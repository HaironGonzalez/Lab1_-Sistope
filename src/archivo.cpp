#include "archivo.h"

/*void concatenar(char * nombre1, char * nombre2)
{           // concatena ambos ficheros de texto

	ofstream archivo1;
	ifstream archivo2;
	string cadena;

	archivo1.open(nombre1 , ios::app);
	archivo2.open(nombre2);

	if(archivo1.fail() || archivo1.fail()){

		cout << "Error parametros";
	}
		
	while (!archivo2.eof()){

		
		 getline(archivo2 , cadena);
		 archivo1 << cadena<<"\n"; 
	}

	archivo1.close();
	archivo2.close();

} */

void buscarrepetidas (char * nombre,vector<string> &repetidas)
{   // busca las palabras repetidas en un texto y las ingresa a un vector
	ifstream archivo;
	ifstream aux;
	string s1;
	string s2;
	int cont = 0;
	int validacion = 1;

	archivo.open(nombre);

	if(archivo.fail()){
		cout << "Error parámetros\n";
		exit(0);
	}


	while (!archivo.eof())
	{

		archivo >> s1; 
		for (vector<string>::iterator it = repetidas.begin() ; it != repetidas.end(); ++it)
		{
            if (s1.compare(*it)==0)
            {
            	validacion=0;
            	break;
         	}
        }

		if(validacion)
		{                        // si la palabra no está en el vector
			aux.open(nombre);
	
			while(!aux.eof())
			{
				aux >> s2;
				
				if( s1.compare(s2)==0)
				{
					cont ++;
				}
				
				if (cont > 1)
				{
					repetidas.push_back(s2);
					break;
				}
				s2.clear();
			}	
			cont = 0;
			aux.close();
		}
		validacion=1;
		s1.clear();
	}	
	archivo.close();
}

void guardarrepetidas(vector<string> &repetidas,ofstream &salida)
{
	for(vector<string>::iterator it = repetidas.begin(); it != repetidas.end(); it++)
	{
		salida << *it << "\n";
	}
	salida <<"\n";
}

void mostrarrepetidas(vector<string> &repetidas)
{
	for(vector<string>::iterator it = repetidas.begin(); it != repetidas.end(); it++)
	{
		cout << *it << "\n";
	}
	cout <<"\n";
}

void interseccion(vector<string> &repetidasf,vector<string> &repetidasg,vector<string> &repetidasinter)
{
	string s;

	for(vector<string>::iterator i = repetidasf.begin(); i != repetidasf.end(); i++)
	{
		
		for(vector<string>::iterator j = repetidasg.begin(); j != repetidasg.end(); j++)
		{
			s = *i;
			if(s.compare(*j)==0)repetidasinter.push_back(s);	
		}
	}
}

void buscarrepetidasinter (char * nombref,char * nombreg,vector<string> &repetidas)
{
	ifstream archivof;
	ifstream archivog;
	string s1;
	string s2;
	int cont = 0;
	int validacion = 1;
	int cont2 = 0;

	archivof.open(nombref);
	if(archivof.fail())	{
		cout << "Error parámetros\n";
		exit(0);
	}

	while (!archivof.eof())
	{
		archivof >> s1;
		for (vector<string>::iterator it = repetidas.begin() ; it != repetidas.end(); ++it)
		{
            if (s1.compare(*it)==0)
            {
            	validacion=0;
            	break;
            }
        }

		if(validacion)
		{                        // si la palabra no está en el vector
			archivog.open(nombreg);
			if(archivog.fail()){
				
				cout << "Error parámetros\n";
				exit(0);
			}
			while(!archivog.eof())
			{
				archivog >> s2;
				
				if( s1.compare(s2)==0)
				{
					repetidas.push_back(s2);
					break;
				}
				s2.clear();
			}	

			archivog.close();
			s1.clear();
			
		}
		validacion = 1;
	}	
	archivof.close();
}

void mostraro(char * oflag)
{
	stringstream comando;
	comando << "file -i " << oflag;
	system( comando.str().c_str() );
}


void guardaro(char * oflag,ofstream &salida)
{
	FILE *sal;
	char buff[512];
	stringstream comando;
	ifstream archivo;

	archivo.open(oflag);
	if(archivo.fail())	{
		cout << "Error parámetros\n";
		exit(0);
	}
	archivo.close();


	comando << "file -i " << oflag;
	sal = popen(comando.str().c_str(), "r");
	while(fgets(buff, sizeof(buff), sal)!=NULL) salida << buff;
	pclose(sal);
}


void mostrarO(char * Oflag)
{
	FILE *in;
	char buff[512];
	stringstream comando;
	comando << "file -i " << Oflag;

	in = popen(comando.str().c_str(), "r");
	fgets(buff, sizeof(buff), in);  

	pclose(in);
	int check = 0;
	for (int i=0;i<508;i++)
	{
	  if (buff[i]== 't' && buff[i+1]== 'e' && buff[i+2]== 'x' && buff[i+3]== 't' && buff[i+4]== '/' && buff[i+5]== 'p' && buff[i+6]== 'l' && buff[i+7]== 'a'&&buff[i+8]== 'i'&&buff[i+9]== 'n')
	  {
	    check = 1;
	    break;
	  }
	}
	if (check)
	{
	  stringstream comando2;
	  comando2 << "cat " << Oflag;
	  system( comando2.str().c_str() );   
	}
}

void guardarO(char * Oflag,ofstream &salida)
{
	FILE *in;
	char buff[512];
	stringstream comando;
	ifstream archivo;

	archivo.open(Oflag);
	if(archivo.fail())	{
		cout << "Error parámetros\n";
		exit(0);
	}
	archivo.close();
	comando << "file " << Oflag;
	
	in = popen(comando.str().c_str(), "r");

	fgets(buff, sizeof(buff), in);  
	pclose(in);
	int check =0;
	for (int i=0;i<508;i++)
	{
	  if (buff[i]== 't' && buff[i+1]== 'e' && buff[i+2]== 'x' && buff[i+3]== 't')
	  {
	    check = 1;
	    break;
	  }
	}

	if (check)
	{ 
	  FILE *in;
	  char buff2[512];
	  stringstream comando2;
	  comando2 << "cat " << Oflag;
	  in = popen(comando2.str().c_str(), "r");
	  while(fgets(buff2, sizeof(buff2), in)!=NULL) salida << buff2;
	  pclose(in);  
	}
}

