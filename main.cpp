#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include "cdgCesar.h"
#include "definicion.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int validacion(string vartemp);
void newPantalla();
string transf_A_Mayuscula(string tex, int tam);
	
int main(int argc, char** argv) {
	
	cdgCesar cesar;
	string auxiliar,otra,texto,vartemp;
	int numero,tam,opc,cont=0,bandera=0;
	char nArchivo[100];
	ofstream myfile;
	ifstream archivo;
	FILE *ft;
	do{
		do{
			system("cls");
			fflush(stdin);
			cout<<"\tSELECIONE UNA OPCION"<<endl;
			cout<<"1.- CODIFICAR"<<endl;
			cout<<"2.- DECODIFICAR"<<endl;
			cout<<"3.- SALIR"<<endl;		
			cout<<"\nOpcion: ";
			getline(cin,vartemp);
			
			if(validacion(vartemp)==0){
				cout<<"\n"<<ERROR<<endl<<endl;
				system("pause");
			}else{
				istringstream(vartemp)>>opc;
				bandera=1;
				if(opc<1 || opc>3){
					cout<<"\n"<<ERROR<<endl<<endl;
					system("pause");
					bandera=0;
				}
            }   	
		}while(bandera!=1);
		bandera=0;	
		system("cls");
		switch(opc){
			case 1:
				cout<<"\tBUSCAR ARCHIVO:\n\n";
				cout<<"INGRESE EL NOMBRE DEL ARCHIVO CON SU RESPECTIVA EXTENSION\n";
				cin>>nArchivo;
				ft= fopen(nArchivo,"r");
				if(ft){
					cout<<"EXISTE\n\n";
				}
				else{
					cout<<"NO EXISTE\n\n";
				}
				cout<<"INGRESE EL TEXTO QUE DESEA CODIFICAR"<<endl;
				do{
					fflush(stdin);
					getline(cin,otra);
					tam=(otra.size());
					otra=transf_A_Mayuscula(otra, tam);
					if(otra!=":SACAME"){
						auxiliar=otra;
					}else{
						auxiliar="";
					}
					texto=texto+auxiliar+'\n';
				}while(otra!=":SACAME");
				
				tam=(texto.size());
				texto=transf_A_Mayuscula(texto, tam);
				newPantalla();	
				cout<<"\t TEXTO ESCRITO:\n\n"<<texto<<endl;
				cout<<"INGRESE El NUMERO DE LA CODIFICACION"<<endl;
				cin>>numero;
				cesar.setCodificado(texto, numero, tam);
				system("cls");
				
				cout<<"\tTEXTO CODIFICADO:\n\n\n"<<cesar.getTexto();
				myfile.open ("codificado.txt",ios::trunc);
				if(myfile.is_open()){
					myfile<<cesar.getTexto();
				}else{
					cout<<"NO SE COPIO LA PALABRA"<<endl;
					newPantalla();
				}
				myfile.close();
				newPantalla();
			break;
		
			case 2:
				archivo.open("codificado 2.txt");
				cout<<"\tTEXTO CODIFICADO:\n\n\n";
				if(archivo.is_open()){
					while(getline(archivo,texto)){
						cesar.setTexto(texto);
						cout<<cesar.getTexto()<<endl;
					}
				}
				archivo.clear();
				archivo.seekg(0,ios::beg);
				cout<<"INGRESE El NUMERO DE LA DECODIFICACION"<<endl;
				cin>>numero;
				system("cls");
				cout<<"\tTEXTO DECODIFICADO:\n\n\n";
				if(archivo.is_open()){
					while(getline(archivo,texto)){
						tam=texto.size();
						cesar.setDecodificado(texto, numero, tam);
						cout<<cesar.getTexto()<<endl;
					}
				}
				
				else{
					cout<<"no se leyo el archivo";
				}
				archivo.close();
				newPantalla();
			break;
			
			case 3:
				return 0;
			break;
			
		}
	}while(opc!=3);
	return 0;
}

int validacion(string vartemp){
	int bandera=1;
    int tam=vartemp.size();
	for(int a=0;a<tam;a++){
		if(vartemp[a]<48 || vartemp[a]>57){
			bandera=0;
		}
	}
	return bandera;
}

void newPantalla(){
	system("PAUSE");
	system("cls");
}

string transf_A_Mayuscula(string texto, int tam){
	string nTexto;
	for (int x=0; x<tam; x++){
		if (texto[x]>96 && texto[x]<123){
			texto[x]=texto[x]-32;
		}
	}
	nTexto=texto;
	return nTexto;	
}
