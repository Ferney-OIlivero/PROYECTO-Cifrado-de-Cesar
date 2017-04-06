#include <iostream>
#include <fstream>
#include "cdgCesar.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
bool validar(string valor);
	
int main(int argc, char** argv) {
	
	cdgCesar cesar;
	string auxiliar,otra,texto;
	int numero,tam,opc,cont=0;
	ofstream myfile;
	ifstream archivo;
	
	do{
	
		cout<<"\tSELECIONES UNA OPCION"<<endl;
		cout<<"1.- CODIFICAR"<<endl;
		cout<<"2.- DECODIFICAR"<<endl;
		cout<<"3.- SALIR"<<endl;
		cin>>opc;
		switch(opc){
			case 1:
				cout<<"INGRESE EL TEXTO QUE DESEA CODIFICAR"<<endl;
				do{
					fflush(stdin);
					getline(cin,otra);
					if(otra!=":SACAME"){
						auxiliar=otra;
					}
					else{
						auxiliar="";
					}
					texto=texto+auxiliar+'\n';
				}while(otra!=":SACAME");
				tam=(texto.size());		
				cout<<"ESCRITO:\n"<<texto<<endl;
				cout<<"INGRESE El NUMERO DE LA CODIFICACION"<<endl;
				cin>>numero;
				
				cesar.setCodificado(texto, numero, tam);
			
				cout<<"TEXTO CODIFICADO:\n"<<cesar.getTexto();

				myfile.open ("codificado.txt",ios::trunc);
				if(myfile.is_open()){
					myfile<<cesar.getTexto();
				}
				else{
					cout<<"NO SE COPIO LA PALABRA"<<endl;
				}
				myfile.close();
			break;
		
			case 2:
				cout<<"";
				cout<<"INGRESE El NUMERO DE LA DECODIFICACION"<<endl;
				cin>>numero;
				
				
				archivo.open("codificado.txt");
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
		if((valor[i]<48 || valor[i]>57) && (valor[i]!=46)){
			valido=false;
			break;
		}
	}
	return valido;
}
