#include "sculptor.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <math.h>
#include <iomanip>

/*TESTE
void Sculptor::showcolor(){
  std::cout<<r<<"\n";
  std::cout<<g<<"\n";
  std::cout<<b<<"\n";
  std::cout<<a<<"\n";
};
void Sculptor::showvoxel(int x,int y,int z){
  std::cout<< v[x][y][z].isOn << std::endl;
  std::cout<< v[x][y][z].r << std::endl;
  std::cout<< v[x][y][z].g << std::endl;
  std::cout<< v[x][y][z].b << std::endl;
  std::cout<< v[x][y][z].a << std::endl;
};
//mostra quais celulas no plano x estão ativadas
void Sculptor::showplano(int x){//
  for(int i=0; i<ny; i++){
    for(int j=0; j<nz;j++){
        std::cout<<v[x][i][j].isOn<<" ";
    }
    std::cout<<"\n";
  }
}
FIM*/


//Construtor da classe
Sculptor::Sculptor(int _nx, int _ny, int _nz){
  //passando as dimensões da matriz para as variáveis da classe
  nx=_nx;
  ny=_ny;
  nz=_nz;
  //Alocação dinâmica da matriz
  v = new Voxel**[nx];//Alocando os x planos

  for (int i = 0; i < nx; i++){
        v[i] = new Voxel*[ny];//Alocando as y linhas
        for (int j = 0; j < ny; j++) {
            v[i][j] = new Voxel[nz];//Alocando as z linhas
        }
    }
  //mudando parametro is0n:false em todas as células
   for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                v[i][j][k].isOn = false;
            }
          }
     }
}
//destrutor da classe
Sculptor::~Sculptor(){
  //desalocando a memoria
  for(int i = 0; i<nx;i++){
    for(int j = 0; j<ny;j++){
      delete[] v[i][j];//desaloca as z linhas
    }
    delete[] v[i];//desaloca as y linhas
  }
  delete[] v;//desaloca os x planos
}
//Define a cor atual para o desenho
void Sculptor::setColor(float r, float g, float b, float alpha){
  //Atribui os argumentos às variáveis da classe
  this->r=r;
  r=(float)r;
  this->g=g;
  g=(float)g;
  this->b=b;
  b=(float)b;
  a=(float)alpha;
  //std::cout<< std::fixed << std::setprecision(1)<< r << g<<b<<a<<"\n";
}
//Ativa o voxel na posicao (x,y,z) (isOn = true) e atribui ao mesmo a cor atual de desenho(atribuido por setColor)
void Sculptor::putVoxel(int x, int y, int z){
  v[x][y][z].isOn = true;
  v[x][y][z].r = r;
  v[x][y][z].g=g;
  v[x][y][z].b=b;
  v[x][y][z].a=a;
}
//Desativa o voxel na posicao (x,y,z) (isOn = false)
void Sculptor::cutVoxel(int x, int y, int z){
  v[x][y][z].isOn = false;
}
//Ativa todos os voxels no intervalo x∈[x0,x1], y∈[y0,y1], z∈[z0,z1] e atribui aos mesmos a cor atual de desenho (isOn = true)
void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
  for(int i=x0; i<=x1; i++){
    for(int j=y0; j<=y1;j++){
      for(int k=z0;k<=z1;k++){
        v[i][j][k].isOn = true;
        v[i][j][k].r = r;
        v[i][j][k].g=g;
        v[i][j][k].b=b;
        v[i][j][k].a=a;
      }
    }
  }
}
//Desativa todos os voxels no intervalo x∈[x0,x1], y∈[y0,y1], z∈[z0,z1] e atribui aos mesmos a cor atual de desenho (isOn = false)
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
  for(int i=x0; i<=x1; i++){
    for(int j=y0; j<=y1;j++){
      for(int k=z0;k<=z1;k++){
        v[i][j][k].isOn = false;
        v[i][j][k].r = r;
        v[i][j][k].g=g;
        v[i][j][k].b=b;
        v[i][j][k].a=a;
      }
    }
  }
}

//Ativa todos os voxels que satisfazem a equacao da esfera e atribui aos mesmos a cor atual de desenho
void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
  for(int i=0;i<nx;i++){
      for(int j=0;j<ny;j++){
          for(int k=0;k<nz;k++)
            if((pow((i-xcenter),2)+pow((j-ycenter),2)+pow((k-zcenter),2))<pow(radius,2)){
              v[i][j][k].isOn = true;
              v[i][j][k].r = r;
              v[i][j][k].g=g;
              v[i][j][k].b=b;
              v[i][j][k].a=a;
            }
      }
  }
}

//Desativa todos os voxels que satisfazem a equacao da esfera
void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
  for(int i=0;i<nx;i++){
      for(int j=0;j<ny;j++){
          for(int k=0;k<nz;k++){
            if((pow((i-xcenter),2)+pow((j-ycenter),2)+pow((k-zcenter),2))<pow(radius,2)){
              v[i][j][k].isOn = false;
              v[i][j][k].r = r;
              v[i][j][k].g=g;
              v[i][j][k].b=b;
              v[i][j][k].a=a;
            }
          }
      }
  }
}
//Ativa todos os voxels que satisfazem à equação do elipsóide e atribui aos mesmos a cor atual de desenho
void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
  for(int i=0;i<=nx;i++){
    for(int j=0;j<=ny;j++){
      for(int k=0;k<=nz;k++){
        if(pow(((i-xcenter)/(float)rx),2.0)+pow(((j-ycenter)/(float)ry),2.0)+pow(((k-zcenter)/(float)rz),2.0)<1.0){
              v[i][j][k].isOn = true;
              v[i][j][k].r = r;
              v[i][j][k].g=g;
              v[i][j][k].b=b;
              v[i][j][k].a=a;
        }
      }
    }
  }
}

//Desativa todos os voxels que satisfazem à equação do elipsóide
void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
  for(int i=0;i<=nx;i++){
    for(int j=0;j<=ny;j++){
      for(int k=0;k<=nz;k++){
        if(pow(((i-xcenter)/(float)rx),2.0)+pow(((j-ycenter)/(float)ry),2.0)+pow(((k-zcenter)/(float)rz),2.0)<1.0){
              v[i][j][k].isOn = false;
              v[i][j][k].r = r;
              v[i][j][k].g=g;
              v[i][j][k].b=b;
              v[i][j][k].a=a;
        }
      }
    }
  }
}

void Sculptor::writeOFF(char* filename){
  std::ofstream fout;//cria objeto fout da classe ofstream
  int nvertices, nfaces;//variável para número de vertice e faces
  fout.open(filename);//método da fout para abrir o arquivo(e criar)
  if(!fout.is_open()){//contingência
    std::cout << "deu errado\n";
    exit(1);
  }
  //contar a quantidade de isOn==true
  int cont=0;
  for(int i=0;i<nx;i++){
    for(int j=0;j<ny;j++){
      for(int k=0;k<nz;k++){
        if(v[i][j][k].isOn==true)
          cont++;
      }
    }
  }

  nvertices = 8;//atribui 8
  nfaces = 6;//atribui 6
  fout << "OFF\n";//escreve OFF
  fout << nvertices*cont << " " << nfaces*cont << " 0\n";//escreve a quantidade total de vertices e faces*/


  for(int _i=0;_i<nx;_i++){
     for(int _j=0;_j<ny;_j++){
       for(int _k=0;_k<nz;_k++){
         if(v[_i][_j][_k].isOn==true){
           fout << _i+(-0.5) <<" "<< _j+(0.5)<<" "<<  _k+(-0.5)<<"\n";
           fout << _i+(-0.5) <<" "<< _j+(-0.5)<<" "<< _k+(-0.5)<<"\n";
           fout << _i+(0.5) <<" "<<  _j+(-0.5)<<" "<< _k+(-0.5)<<"\n";
           fout << _i+(0.5) <<" "<<  _j+(0.5) <<" "<< _k+(-0.5)<<"\n";
           fout << _i+(-0.5) <<" "<< _j+(0.5)<<" "<<  _k+(0.5)<<"\n";
           fout << _i+(-0.5) <<" "<< _j+(-0.5)<<" "<< _k+(0.5)<<"\n";
           fout << _i+(0.5) <<" "<<  _j+(-0.5)<<" "<< _k+(0.5)<<"\n";
           fout << _i+(0.5) <<" "<<  _j+(0.5)<<" "<<  _k+(0.5)<<"\n";
         }
       }
     }
  }

  int voxel =0;
  for(int _i=0;_i<nx;_i++){
     for(int _j=0;_j<ny;_j++){
       for(int _k=0;_k<nz;_k++){
         if(v[_i][_j][_k].isOn==true){
           fout<< std::fixed << std::setprecision(1) <<"4 "<<(int)(0+voxel)<<" "<<(3+voxel)<<" "<<(2+voxel)<<" "<<(1+voxel)<<" "<<(float)(v[_i][_j][_k].r)<<" "<<v[_i][_j][_k].g<<" "<<v[_i][_j][_k].b<<" "<<v[_i][_j][_k].a<<"\n";
           fout <<"4 "<<(int)(4+voxel)<<" "<<(5+voxel)<<" "<<(6+voxel)<<" "<<(7+voxel)<<" "<<v[_i][_j][_k].r<<" "<<v[_i][_j][_k].g<<" "<<v[_i][_j][_k].b<<" "<<v[_i][_j][_k].a<<"\n";
           fout <<"4 "<<(int)(0+voxel)<<" "<<(1+voxel)<<" "<<(5+voxel)<<" "<<(4+voxel)<<" "<<v[_i][_j][_k].r<<" "<<v[_i][_j][_k].g<<" "<<v[_i][_j][_k].b<<" "<<v[_i][_j][_k].a<<"\n";
           fout <<"4 "<<(int)(0+voxel)<<" "<<(4+voxel)<<" "<<(7+voxel)<<" "<<(3+voxel)<<" "<<v[_i][_j][_k].r<<" "<<v[_i][_j][_k].g<<" "<<v[_i][_j][_k].b<<" "<<v[_i][_j][_k].a<<"\n";
           fout <<"4 "<<(int)(3+voxel)<<" "<<(7+voxel)<<" "<<(6+voxel)<<" "<<(2+voxel)<<" "<<v[_i][_j][_k].r<<" "<<v[_i][_j][_k].g<<" "<<v[_i][_j][_k].b<<" "<<v[_i][_j][_k].a<<"\n";
           fout <<"4 "<<(int)(1+voxel)<<" "<<(2+voxel)<<" "<<(6+voxel)<<" "<<(5+voxel)<<" "<<v[_i][_j][_k].r<<" "<<v[_i][_j][_k].g<<" "<<v[_i][_j][_k].b<<" "<<v[_i][_j][_k].a<<"\n";
           voxel=voxel+8;
         }
       }
     }
  }

  fout.close();//fecha o arquivo

}
