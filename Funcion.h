#ifndef Funcion_h_
#define Funcion_h_
#include "Hour.h"

class Funcion
{
  public:
  Funcion();
  Funcion(string, int, int, Hour);
  void setFuncion(string);
  string getFuncion();
  void setNumPeli(int);
  int getNumPeli();
  void setSala(int);
  int getSala();
  void setHour(Hour);
  Hour getHour();
  void muestra();

  private:
  string cveFuncion;
  int numPeli, sala;
  Hour hour;
};
Funcion::Funcion()
{
  Hour h(0,0);
  cveFuncion = "";
  numPeli = 0;
  sala = 0;
  hour = h;
}
Funcion::Funcion(string Funcion1, int numPelicula, int salaF, Hour h)
{
  cveFuncion = Funcion1;
  numPeli = numPelicula;
  sala = salaF;
  hour = h;
}
void Funcion::setFuncion(string funcion1)
{
  cveFuncion = funcion1;
}
string Funcion::getFuncion()
{
  return cveFuncion;
}
void Funcion::setNumPeli(int numPelicula)
{
  numPeli = numPelicula;
}
int Funcion::getNumPeli()
{
  return numPeli;
}
void Funcion::setSala(int salaF)
{
  sala = salaF;
}
int Funcion::getSala()
{
  return sala;
}
void Funcion::setHour(Hour h)
{
  hour = h;
}
Hour Funcion::getHour()
{
  return hour;
}
void Funcion::muestra()
{
  cout << "Function: " << cveFuncion << endl;
  cout << "Movie number: " << numPeli << endl;
  cout << "Room: " << sala << endl;
}
#endif