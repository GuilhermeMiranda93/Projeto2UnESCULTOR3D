#include <iostream>
#include "sculptor.h"
#include <math.h>
#include <cstdlib>


int main(void){

    int i=0,j=0,k=0,cont;

    Sculptor desenho(201,201,201);
    desenho.setColor(0.019, 0.184, 0.658,1.0);//azul
    desenho.putBox(0,200,0,0,0,0);//eixo x
    desenho.setColor(0.839, 0.066, 0.039,1.0);//vermelho
    desenho.putBox(0,0,0,200,0,0);//eixo y
    desenho.setColor(0, 0.541, 0.047,1.0);//verde
    desenho.putBox(0,0,0,0,0,200);//eixo z
    //apagando os eixos
    for(i=0;i<201;i++){
        desenho.cutVoxel(i,0,0);
    }
    for(i=0;i<201;i++){
        desenho.cutVoxel(0,i,0);
    }
    for(i=0;i<201;i++){
        desenho.cutVoxel(0,0,i);
    }
    //cabeça
     desenho.setColor(0,0,0,1.0);//preto
     desenho.putSphere(54,48,74,25);//esfera cabeça
     desenho.cutSphere(54,48,74,24);
     desenho.cutBox(23,88,17,87,46,74);
    //base do corpo
    desenho.setColor(0,0,0,1.0);//preto
    desenho.putEllipsoid(54,48,27,25,25,1);//base corpo
    //pata direita
    desenho.setColor(0.898, 0.5, 0.219,1.0);//amarelo
    desenho.putEllipsoid(62,26,28,4,9,6);//interna
    desenho.putEllipsoid(69,22,29,5,9,6);//meio
    desenho.putEllipsoid(74,30,27,4,8,6);//extrema
    desenho.putEllipsoid(66,38,25,10,17,5);//patameio
    desenho.putEllipsoid(65,46,25,8,15,5);//patemameiotras
    //desenho.cutBox(56,79,11,61,30,36);//plano na parte superior
    desenho.cutBox(56,79,11,61,19,26);//plano na parte infeiror
    //pata esquerda
    desenho.putEllipsoid(46,24,28,4,9,6);//interna
    desenho.putEllipsoid(40,22,28,5,9,6);//meio
    desenho.putEllipsoid(35,30,27,4,8,6);//externa
    desenho.putEllipsoid(42,36,25,9,17,5);//patameio
    desenho.putEllipsoid(43,45,25,8,15,5);//patameiotras
    //desenho.cutBox(30,53,10,60,30,36);//plano na parte superior
    desenho.cutBox(30,52,11,67,19,26);//plano na parte infeiror
    //braço direito
    desenho.setColor(0,0,0,1.0);//preto
    desenho.putEllipsoid(87,46,74,18,4,6);
    //desenho.cutBox(72,105,34,59,63,72);
    //braço esquerdo
    desenho.putEllipsoid(29,46,61,4,6,18);
    //barriga
    desenho.setColor(1,1,1,1.0);//branco
    desenho.putEllipsoid(54,27,51,20,11,23);
    //olho esquerdo
    desenho.putSphere(48,27,86,4);
    //olho direito
    desenho.putSphere(61,27,86,4);
    //bola preta olho
    desenho.setColor(0,0,0,1.0);//preto
    desenho.putSphere(61,25,86,2);//esquerdo
    desenho.putSphere(48,25,86,2);//direito
    //corpo
    desenho.setColor(0,0,0,1.0);//preto
    for(i=28;i<=74;i++){
            desenho.putEllipsoid(54,48,i,25,25,1);
            desenho.cutEllipsoid(54,48,i,24,24,1);
    }
    //nariz
    desenho.setColor(0.898, 0.5, 0.219,1.0);//amarelo
    desenho.putBox(52,57,21,25,80,84);
    desenho.putBox(53,56,19,21,81,84);
    desenho.putBox(53,56,17,19,82,84);
    desenho.putBox(53,56,15,17,83,84);
    //chão
    desenho.setColor(1,1,1,1.0);//branco
    desenho.putBox(0,114,0,100,25,25);
//gerando neve c1
    for(cont=0;cont<=50;cont++){
        while(i<81){
            i=rand()%115;
        }
        while(j<54){
            j=rand()%101;
        }
        while(k<26){
            k=rand()%151;
        }
       desenho.putVoxel(i,j,k);
       i=0;
       j=0;
       k=0;
    }
    //gerando neve c2
   for(cont=0;cont<=50;cont++){
        while(i<33){
            i=rand()%81;
        }
        while(j<74){
            j=rand()%101;
        }
        while(k<26){
            k=rand()%151;
        }
       desenho.putVoxel(i,j,k);
       i=0;
       j=0;
       k=0;
    }
//gerando neve c3
   for(cont=0;cont<=50;cont++){
        while(i==0){
            i=rand()%33;
        }
        while(j<62){
            j=rand()%101;
        }
        while(k<26){
            k=rand()%151;
        }
       desenho.putVoxel(i,j,k);
       i=0;
       j=0;
       k=0;
    }
    //gerando neve c4
   for(cont=0;cont<=50;cont++){
        while(i==0){
            i=rand()%29;
        }
        while(j<39){
            j=rand()%62;
        }
        while(k<26){
            k=rand()%151;
        }
       desenho.putVoxel(i,j,k);
       i=0;
       j=0;
       k=0;
    }
//gerando neve c5
   for(cont=0;cont<=50;cont++){
        while(i==0){
            i=rand()%28;
        }
        while(j==0){
            j=rand()%39;
        }
        while(k<26){
            k=rand()%151;
        }
       desenho.putVoxel(i,j,k);
       i=0;
       j=0;
       k=0;
    }

    //gerando neve c6
   for(cont=0;cont<=50;cont++){
        while(i<27){
            i=rand()%80;
        }
        while(j==0){
            j=rand()%14;
        }
        while(k<26){
            k=rand()%151;
        }
       desenho.putVoxel(i,j,k);
       i=0;
       j=0;
       k=0;
    }
//gerando neve c7
   for(cont=0;cont<=50;cont++){
        while(i<79){
            i=rand()%115;
        }
        while(j==0){
            j=rand()%39;
        }
        while(k<26){
            k=rand()%151;
        }
       desenho.putVoxel(i,j,k);
       i=0;
       j=0;
       k=0;
    }

    //gerando neve c8
   for(cont=0;cont<=50;cont++){
        while(i<78){
            i=rand()%115;
        }
        while(j<39){
            j=rand()%54;
        }
        while(k<86){
            k=rand()%151;
        }
       desenho.putVoxel(i,j,k);
       i=0;
       j=0;
       k=0;
    }
        //gerando neve ccentro
   for(cont=0;cont<=50;cont++){
        while(i<32){
            i=rand()%81;
        }
        while(j<12){
            j=rand()%74;
        }
        while(k<98){
            k=rand()%151;
        }
       desenho.putVoxel(i,j,k);
       i=0;
       j=0;
       k=0;
    }

  desenho.writeOFF((char*)"pinguim.off");
  //FIM
}

































