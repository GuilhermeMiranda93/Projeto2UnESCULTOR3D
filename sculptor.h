#ifndef SCULPTOR_H
#define SCULPTOR_H

//Destinado a manipulação das cores do objeto, nível opacidade e se o mesmo está ativo ou não.
struct Voxel {
  float r,g,b;
  float a;
  bool isOn;
};

//Classe que contem todas as manipulações da matriz 3d
class Sculptor {
private:
  Voxel ***v;
  // 3D matrix
  int nx,ny,nz; // Dimensions
  float r,g,b,a; // Current drawing color
public:

  //TESTE
  void showcolor();
  void showvoxel(int x,int y,int z);
  void showplano(int x);
  //FIM

  Sculptor(int _nx, int _ny, int _nz);
  //Construtor da classe
  ~Sculptor();
  //Destrutor
  void setColor(float r, float g, float b, float alpha);
  //Define a cor atual de desenho.
  void putVoxel(int x, int y, int z);
  //Ativa o voxel na posição (x,y,z) ( isOn = true) e atribui ao mesmo a cor atual de desenho
  void cutVoxel(int x, int y, int z);
  //Desativa o voxel na posição (x,y,z) (isOn = false)
  void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
  //Ativa todos os voxels no intervalo x∈[x0,x1], y∈[y0,y1], z∈[z0,z1] e atribui aos mesmos a cor atual de desenho
  void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
  //Desativa todos os voxels no intervalo x∈[x0,x1], y∈[y0,y1], z∈[z0,z1] e atribui aos mesmos a cor atual de desenho)
  void putSphere(int xcenter, int ycenter, int zcenter, int radius);
  //Ativa todos os voxels que satisfazem à equação da esfera e atribui aos mesmos a cor atual de desenho (r,g,b,a)
  void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
  //Desativa todos os voxels que satisfazem à equação da esfera
  void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  //Ativa todos os voxels que satisfazem à equação do elipsóide e atribui aos mesmos a cor atual de desenho
  void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  //Desativa todos os voxels que satisfazem à equação do elipsóide
  void writeOFF(char* filename);
  //grava a escultura no formato OFF no arquivo filename
};

#endif
