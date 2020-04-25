#include <iostream>
#include "Hour.h"
#include "Actor.h"
#include "Funcion.h"
#include "Movie.h"
#include <fstream>
#include <string.h>
using namespace std;

void menu()
{
cout << "\t MENU" << endl;
cout << "1) Show all the actors in the list" << endl;
cout << "2) Show all the movies in the list" << endl;
cout << "3) Show all the scheduled movies" << endl;
cout << "4) Search scheduled movies by hour" << endl;
cout << "5) Search scheduled movies by ScheduleID" << endl;
cout << "6) Search movies by actorID" << endl;
cout << "7) Finish the program" << endl;
}

int main() 
{
  int opcion, cont, id, cont1, numPeli, añoPeli, durPeli, cantActores, listaId[20], cantFunciones, numFuncionPeli, numSala, Hour, minutos, HourBuscar, minutosBuscar, claveFuncion, pasoClave, HourPaso, idBuscar, pasoId, pasoLista[20], pasoNumPeli, minutosPaso;

  Actor arrActores[20];
  Movie arrPelicula[20];
  Funcion arrFuncion[20];
  class Hour HourMinutos[20], pasoHour, pasoH;
  string nombreActor, generoPeli, tituloPeli, nomFuncion;
  ifstream archActores, archPeliculas;
  bool encontro = false;


  archActores.open("Actores.txt");
  archPeliculas.open("Peliculas.txt");

  cont = 0;
  cont1 = 0;

  while (archActores >> id)
  {
    getline(archActores, nombreActor);

    arrActores[cont].setId(id);
    arrActores[cont].setNombre(nombreActor);
 
    cont ++;
  }

  while (archPeliculas >> numPeli)
  {
    archPeliculas >> añoPeli;
    archPeliculas >> durPeli;
    archPeliculas >> generoPeli;
    archPeliculas >> cantActores;
    for(int j = 0; j<cantActores;j++)
    {
      archPeliculas >> listaId[j];
    }
    getline(archPeliculas, tituloPeli);
    arrPelicula[cont1].setNumPeli(numPeli);
    arrPelicula[cont1].setAño(añoPeli);
    arrPelicula[cont1].setDuracion(durPeli);
    arrPelicula[cont1].setGenero(generoPeli);
    for(int i = 0; i< cantActores; i++)
    {
      arrPelicula[cont1].agregarActor(listaId[i]);
    }
    arrPelicula[cont1].setTitulo(tituloPeli);

    cont1++;
  }

  cout << "Type the number of movies: ";
  cin >> cantFunciones;
  for(int i = 0; i<cantFunciones; i++)
  {
    cout << endl <<"Type the name of the movie " << i+1 << " :" ;
    cin.ignore();
    getline(cin,nomFuncion);

    cout << endl << "Type the movieID " << i+1 << " :";
    cin >> numFuncionPeli;

    cout << endl << "Select the movie's room number " << i+1 << " :";
    cin >> numSala;

    do
    {
      cout << endl << "Type the hours of the movie " << i+1 << " :";
      cin >> Hour;
    } while(Hour<0 || Hour>23);

    do
    {
      cout << endl << "Type the minutes of the movie " << i+1 << " :";
      cin >> minutos;
    } while( minutos<0 || minutos>59);

    HourMinutos[i].setHour(Hour);
    HourMinutos[i].setMinutos(minutos);

    arrFuncion[i].setHour(HourMinutos[i]);
    arrFuncion[i].setNumPeli(numFuncionPeli);
    arrFuncion[i].setFuncion(nomFuncion);
    arrFuncion[i].setSala(numSala);
  }

  
  menu();
  cout << endl;
  cin >> opcion;
  cout << endl << endl;

  while(opcion !=7)
  {
    switch(opcion)
    {
      case 1:
      cout << "1. List of all the actors in the list." << endl;
      for(int j = 0;j<cont;j++)
      {
        arrActores[j].muestra();
        cout << endl;
      }
      break;

      case 2:
      cout << "2. List of all the movies in the list" << 
      endl;
      for(int i = 0; i<cont1 ;i++)
      {
        cout << "Title: " << arrPelicula[i].getTitulo() << endl;
        cout << "Year: " << arrPelicula[i].getAño() << endl;
        cout << "Length: " << arrPelicula[i].getDuracion() << endl;
        cout << "Gender: " << arrPelicula[i].getGenero() << endl;
        for(int j = 0; j<20; j++)
        {
          for(int g = 0; g<3;g++)
          {
            if(arrActores[j].getId() == arrPelicula[i].getListaActores(g))
            {
              cout << "-" << arrActores[j].getNombre() << endl; 
            }
          }
        }
        cout << endl;
      }
      break;

      case 3:
      cout << "3. List of all available movies." << endl;
      for(int i=0;i<cantFunciones; i++)
      {
        arrFuncion[i].muestra();
        pasoH = arrFuncion[i].getHour();
        cout << "Hour: " << pasoH.getHour() << " : " << pasoH.getMinutos() << endl;
      }
      break;

      case 4:
      encontro = false;
      cout << "4. List of movies scheduled by hour." << endl;
      while(encontro == false)
      {
        do
        {
        cout << "Type the hours of the scheduled movie: ";
        cin >> HourBuscar;
        }while(HourBuscar<0 || HourBuscar>24);
        do
        {
          cout << "Type the minutes of the scheduled movie: ";
          cin>>minutosBuscar;
        }while(minutosBuscar<0 || minutosBuscar>59);

        pasoHour.setHour(HourBuscar);
        pasoHour.setMinutos(minutosBuscar);

        for(int i=0;i<cantFunciones;i++)
        {
          pasoHour = arrFuncion[i].getHour();
          HourPaso = pasoHour.getHour();
          minutosPaso = pasoHour.getMinutos();
          if(HourPaso == HourBuscar && minutosPaso == minutosBuscar)
          {
            encontro = true;
            cout << "Title: " << arrFuncion[i].getFuncion() << endl << "Room: " << arrFuncion[i].getSala() << endl;
          } 
        }
        if(encontro == false)
        {
          cout << "The program didn't find that hour in the scheduled movies." << endl;
        }
      } 
      break;
      case 5:
      encontro = false;
      cout <<  "5. List by movie ScheduledID." << endl;
      while(encontro == false)
      {
        cout << "Type the ScheduledID of the movie you want: ";
        cin >> claveFuncion;
        for(int i=0;i<cantFunciones;i++)
        {
          pasoClave = arrPelicula[i].getNumPeli();
          if(pasoClave == claveFuncion)
          {
            encontro = true;
            pasoHour = arrFuncion[i].getHour();
            cout << "Room: " << arrFuncion[i].getSala() << endl << "Title: " << arrFuncion[i].getFuncion() << endl << "Hour: " << pasoHour.getHour() << ":" << pasoHour.getMinutos() <<  endl << "Length: " << arrPelicula[i].getDuracion() << endl << "Gender: " << arrPelicula[i].getGenero() << endl;
            for(int j = 0; j<20; j++)
            {
              for(int g = 0; g<3;g++)
              {
                if(arrActores[j].getId() == arrPelicula[i].getListaActores(g))
                {
                  cout << "-" << arrActores[j].getNombre() << endl; 
                }
              }
            }
          }
        }
        if(encontro == false)
        {
          cout << "The program didn't find that movie." << endl;
        }
      }
      
      break;

      case 6:
      encontro = false;
      cout << "6. List of movies in which an actor participates" <<endl;
      while(encontro == false)
      {
        cout << "Type the ActorID you want: ";
        cin >> idBuscar;
        for(int i=0;i<cont1;i++)
        {
          for(int j=0;j<cantActores;j++)
          {
            pasoId = arrPelicula[i].getListaActores(j);
            if(idBuscar == pasoId)
            {
              cout << endl << "Title: " << arrPelicula[i].getTitulo() << endl << "Year: " << arrPelicula[i].getAño() << endl; 
              encontro =true;
            }
          }
        }
        if(encontro == false)
        {
          cout << "The program didn't find the ActorID." << endl;
        }
      }
      break;
    }
    menu();
    cout << endl;
    cin >> opcion; 
    cout << endl << endl;
  }
  archActores.close();
  archPeliculas.close();
  cout << "The program was finished. " << endl;
  return 0;
}