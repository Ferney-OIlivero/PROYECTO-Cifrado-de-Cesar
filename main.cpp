#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include "cdgCesar.h"
#include "definicion.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
bool validar(string valor);
void newPantalla();
string transf_A_Mayuscula(string tex, int tam);
	
int main(int argc, char** argv) {
	
	cdgCesar cesar;
	string auxiliar,otra,texto,vartemp;
	int numero,tam,opc,cont=0,bandera=0;;
	ofstream myfile;
	ifstream archivo;
	
	do{

		do{
			system("cls");
			fflush (stdin);
			cout<<"\tSELECIONES UNA OPCION"<<endl;
			cout<<"1.- CODIFICAR"<<endl;
			cout<<"2.- DECODIFICAR"<<endl;
			cout<<"3.- SALIR"<<endl;		
			cout<<"\nOpcion: ";
			cin>>vartemp;
			if(validar(vartemp)==false){
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
				
				cout<<"TEXTO CODIFICADO:\n\n"<<cesar.getTexto();
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
				
				cout<<"INGRESE El NUMERO DE LA DECODIFICACION"<<endl;
				cin>>numero;
				system("cls");
				
				archivo.open("codificado.txt");
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

bool validar(string valor){
    bool valido=true;
    int tam=valor.size();
	for(int i=0;i<tam;i++){
		if((valor[i]<48 || valor[i]>57)){
			valido=false;
			break;
		}
	}
	return valido;
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
