#include "archivo.h"

int main (int argc, char **argv)
{
  int pflag = 0;
  int hflag = 0;
  char *oflag = NULL;
  char *Oflag = NULL;
  char *fflag = NULL;
  char *gflag = NULL;
  char *sflag = NULL;
  char *Sflag = NULL;
  char *aux = NULL;
  int cont=0;
  int c;
  string s;
  vector <string> repetidasf;
  vector <string> repetidasg;
  vector <string> repetidasinter;
  int *flags = new int [8];
  opterr = 0;

  while ((c = getopt (argc, argv, "o:O:h:p:s:S:f:g:")) != -1)
  {
    switch (c)
    {
      case 'o':
        oflag = optarg;
        flags[0]= 1;
        break; 
      case 'O':
        Oflag = optarg;
        flags[1]= 1;
        break;
      case 'h':
        flags[2]= 1;
        aux=optarg;
        hflag=atoi(aux);
        if (hflag==0)
        {
          cout<<"Error parámetros \n";
          return 0;
        }
        break;
      case 'p':
        flags[3]= 1;
        aux=optarg;
        pflag=atoi(aux);
        if (pflag==0)
        {
          cout<<"Error parámetros \n";
          return 0;
        }
        break;

      case 'f':
        flags[4]= 1;
        fflag = optarg;
        break;
      case 'g':
        flags[5]= 1;
        gflag = optarg;
        break;
      case 's':
        flags[6]= 1; 
        sflag = optarg;
        break;
      case 'S':
        flags[7]= 1;
        Sflag = optarg;
        break;
      case '?':
        if (optopt == 'c') cout << "Error de parámetros";
        else if (isprint (optopt)) cout << "Error banderas";
        else cout << "Error banderas";
          return 1;
      default:
        abort ();
    }
  }

  if (flags[2] == 1 && flags[3]== 1)             // si estan las banderas obligatorias h  y p  
 {
    if (flags[7]==1)
    {     // si esta la bandera S (solo imprimir en el texto)

      //cout << "bandera S\n";  
      ofstream salida;
      salida.open(Sflag); 

      salida << "nHebras:"<<hflag<<"\n";
      salida << "nProcesos:"<<pflag<<"\n";

      if (flags[0]==1) guardaro(oflag,salida);  // bandera o 
      
      if (flags[1]==1) guardarO(Oflag,salida);   //bandera O 
      
      if (flags[4]==1 && flags[5]==1)
      { //   buscar en ambos ficheros
        //cout << "-f y -g \n";
        buscarrepetidasinter(fflag,gflag,repetidasinter);
        guardarrepetidas(repetidasinter,salida);
      }
      else if(flags[4]==1)
      {                       // solo bandera f
        //cout << "solo -f\n";
        buscarrepetidas(fflag,repetidasf);
        guardarrepetidas(repetidasf,salida);
      }
      else if (flags[5]==1)
      {                             // solo bandera g 
        //cout << "solo -g\n";
        //buscarrepetidas(gflag,repetidasg);
        //guardarrepetidas(repetidasg,salida);
        cout << "Error banderas";
        exit(0);
      }
    }
    else if (flags[6]==1)
    {       // imprimir por pantalla y guardar en fichero (bandera s)
      //cout << "bandera s \n";
      ofstream salida;
      salida.open(sflag);

      cout << "nHebras:"<<hflag<<"\n";
      cout << "nProcesos:"<<pflag<<"\n";
      salida << "nHebras:"<<hflag<<"\n";
      salida << "nProcesos:"<<pflag<<"\n";

      if (flags[0]==1)
      {             // bandera o 
        guardaro(oflag,salida);
        mostraro(oflag);
      }
      if(flags[1]==1)
      {        // bandera O
        guardarO(Oflag,salida);
        mostrarO(Oflag);
      }
      if (flags[4]==1 && flags[5]==1){ //   buscar en ambos ficheros
        //cout << "-f y -g \n";
        buscarrepetidasinter(fflag,gflag,repetidasinter);
        mostrarrepetidas(repetidasinter);
        guardarrepetidas(repetidasinter,salida);
      }
      else if(flags[4]==1){                       // solo bandera f
        //cout << "solo -f\n";
        buscarrepetidas(fflag,repetidasf);
        mostrarrepetidas(repetidasf);
        guardarrepetidas(repetidasf,salida);
      }
      else if (flags[5]==1){                             // solo bandera g 
        //cout << "solo -g\n";
        //buscarrepetidas(gflag,repetidasg);
        //mostrarrepetidas(repetidasg);
        //guardarrepetidas(repetidasg,salida);
        cout << "Error banderas";
        exit(0);
      }      
    }
    else{                         // solo mostrar por pantalla
      cout << "nHebras:"<<hflag<<"\n";
      cout << "nProcesos:"<<pflag<<"\n";

      if (flags[0]==1) mostraro(oflag);   // bandera o 

      if(flags[1]==1) mostrarO(Oflag);   // bandera O
      
      if (flags[4]==1 && flags[5]==1){ //   buscar en ambos ficheros
        //cout << "-f y -g \n";
        // concatenar(fflag,gflag);
        buscarrepetidasinter(fflag,gflag,repetidasinter);
        //buscarrepetidas(fflag,repetidasf);
        //buscarrepetidas(gflag,repetidasg);
        //interseccion(repetidasf,repetidasg,repetidasinter);
        //cout <<"salio aqui\n";
        mostrarrepetidas(repetidasinter);
      }
      else if(flags[4]==1){                       // solo bandera f
        //cout << "solo -f\n";
        buscarrepetidas(fflag,repetidasf);
        mostrarrepetidas(repetidasf);
      }
      else if (flags[5]==1){                             // solo bandera g 
        //cout << "solo -g\n";
        //buscarrepetidas(gflag,repetidasg);
        //mostrarrepetidas(repetidasg);
        cout << "Error banderas";
        exit(0);
      }
    }
  }
  else
  {                              // falta alguna de las banderas obligatorias
    cout<< "error de banderas\n";
  }
 return 0;
}