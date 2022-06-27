#ifndef SCULPTOR_H
#define SCULPTOR_H

//Destinado a manipulação das cores do objeto, nível opacidade e se o mesmo está ativo ou não.
///Voxel.
///
///Destinado a manipulação das cores do objeto, nível opacidade e se o mesmo está ativo ou não.
/// @param r Recebe valores de 0-1 para vermelho.
/// @param g Recebe valores de 0-1 para verde.
/// @param b Recebe valores de 0-1 para azul.
/// @param Relativo a opacidade do voxel(0-1).
/// @param isOn Indica se o Voxel está ou não ativo.
struct Voxel {
  float r,g,b;
  float a;
  bool isOn;
};
///A classe Sculptor é responsável por gerar a escultura 3D.
///
///Classe que contem todas as manipulações da matriz 3D.
class Sculptor {
private:
  Voxel ***v;
  // 3D matrix
  int nx,ny,nz; // Dimensions
  float r,g,b,a; // Current drawing color
public:
    ///Construtor de classe.
    ///
    ///Realiza alocação dinâmica de memória para uma matriz 3D de Voxel e a inicializar.
    ///@param _nx Número de linhas no eixo x.
    ///@param _ny Número de linhas no eixo y.
    ///@param _nz Número de linhas no eixo z.
  Sculptor(int _nx, int _ny, int _nz);
  ///Destrutor de classe.
  ///
  ///Faz a desalocação de memória.
  ~Sculptor();
  //Destrutor
  ///Define a cor atual de desenho.
  /// @param r valor para vermelho @param g valor para verde @param b valor para azul @param alpha valor para a.
  void setColor(float r, float g, float b, float alpha);
  ///Ativa o voxel na posição (x,y,z) ( isOn = true) e atribui ao mesmo a cor atual de desenho.
  ///@param x valor para a coordenada do voxel @param y valor para coordenada do voxel @param z valor para a coordenada do voxel.
  void putVoxel(int x, int y, int z);
  ///Desativa o voxel na posição (x,y,z) (isOn = false).
  ///@param x valor para a coordenada do voxel @param y valor para coordenada do voxel @param z valor para a coordenada do voxel.
  void cutVoxel(int x, int y, int z);
  ///Ativa todos os voxels no intervalo x∈[x0,x1], y∈[y0,y1], z∈[z0,z1] e atribui aos mesmos a cor atual de desenho.
  ///@param x0 Valor inicial do intervalo @param x1 valor final do intervalo.
  ///@param y0 Valor inicial do intervalo @param y1 valor final do intervalo.
  ///@param z0 Valor inicial do intervalo @param z1 valor final do intervalo.
  void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
  ///Desativa todos os voxels no intervalo x∈[x0,x1], y∈[y0,y1], z∈[z0,z1] e atribui aos mesmos a cor atual de desenho).
  ///@param x0 Valor inicial do intervalo @param x1 valor final do intervalo.
  ///@param y0 Valor inicial do intervalo @param y1 valor final do intervalo.
  ///@param z0 Valor inicial do intervalo @param z1 valor final do intervalo.
  void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
  ///Ativa todos os voxels que satisfazem à equação da esfera e atribui aos mesmos a cor atual de desenho (r,g,b,a).
  ///@param xcenter Valor de x para coordenada @param ycenter Valor de y para coordenada @param zcenter Valor de z para coordenada @param radius Raio da Esfera.
  void putSphere(int xcenter, int ycenter, int zcenter, int radius);
  ///Desativa todos os voxels que satisfazem à equação da esfera.
  ///@param xcenter Valor de x para coordenada @param ycenter Valor de y para coordenada @param zcenter Valor de z para coordenada @param radius Raio da Esfera.
  void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
  ///Ativa todos os voxels que satisfazem à equação do elipsóide e atribui aos mesmos a cor atual de desenho.
  ///@param xcenter Valor de x para coordenada @param ycenter Valor de y para coordenada @param zcenter Valor de z para coordenada @param rx Raio no eixo x @param ry Raio do eixo y @param Raio no eixo z.
  void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  ///Desativa todos os voxels que satisfazem à equação do elipsóide.
  ///@param xcenter Valor de x para coordenada @param ycenter Valor de y para coordenada @param zcenter Valor de z para coordenada @param rx Raio no eixo x @param ry Raio do eixo y @param Raio no eixo z.
  void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  ///grava a escultura no formato OFF no arquivo filename
  ///@param filename Nome do arquivo OFF.
  void writeOFF(char* filename);
  //grava a escultura no formato OFF no arquivo filename
};

#endif
