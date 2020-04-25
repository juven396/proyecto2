 #ifndef Movie_h_
#define Movie_h_

class Movie
{
  private:
  int numPeli, año, duracion, cantidadActores, listaActores[10];
  string titulo, genero; 

  public:
  Movie();
  void setNumPeli(int);
  int getNumPeli();
  void setTitulo(string);
  string getTitulo();
  void setAño(int);
  int getAño();
  void setDuracion(int);
  int getDuracion();
  void setGenero(string);
  string getGenero();
  int getListaActores(int);
  bool agregarActor(int);
  
};
Movie::Movie()
{
  numPeli = 0;
  año = 0;
  duracion = 0;
  cantidadActores = 0;
  listaActores[0] = 0;
  titulo = "";
  genero = ""; 
}
void Movie::setNumPeli(int numeroPeli)
{
  numPeli = numeroPeli;
}
int Movie::getNumPeli()
{
  return numPeli;
}
void Movie::setTitulo(string tituloPeli)
{
  titulo = tituloPeli;
}
string Movie::getTitulo()
{
  return titulo;
}
void Movie::setAño(int añoP)
{
  año =añoP;
}
int Movie::getAño()
{
  return año;
}
void Movie::setDuracion(int duracionPeli)
{
  duracion = duracionPeli;
}
int Movie::getDuracion()
{
  return duracion;
}
void Movie::setGenero(string generoPeli)
{
  genero = generoPeli;
}
string Movie::getGenero()
{
  return genero;
}
int Movie::getListaActores(int i)
{
  return listaActores[i];
}
bool Movie::agregarActor(int i)
{
  bool valido = true;
  if(cantidadActores<10)
  {
    for(int j =0; j<cantidadActores; j++)
    {
      if(listaActores[j] == i)
      {
        valido = false;
      }
    }
  } else
  valido = false;
  
  if (valido == true)
  {
    
    listaActores[cantidadActores] = i;
    cantidadActores++;

  }
  return valido;
}
#endif