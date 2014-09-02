
#ifndef __Laboratorio1__
#define __Laboratorio1__

#include <iostream>
#include <sstream>
#include <vector>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <fstream>


using namespace std;

//void concatenar(char * nombre1, char * nombre2);
void buscarrepetidas (char * nombre,vector<string> &repetidas);
void mostrarrepetidas(vector<string> &repetidas);
void interseccion(vector<string> &repetidasf,vector<string> &repetidasg,vector<string> &repetidasinter);
void buscarrepetidasinter (char * nombref,char * nombreg,vector<string> &repetidas);
void guardarrepetidas(vector<string> &repetidas,ofstream &salida);
void mostraro(char * oflag);
void mostrarO(char * Oflag);
void guardaro(char * oflag,ofstream &salida);
void guardarO(char * Oflag,ofstream &salida);
int validartexto(char * Oflag);

#endif /* defined(__Laboratorio1__) */