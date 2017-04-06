#include <iostream>
#include <fstream>


using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
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
		
				for(int x=0; x<tam; x++){
					if(texto[x]>64 && texto[x]<91){
						texto[x]=texto[x]-((numero%26)-1);
						if(texto[x]<65){
							texto[x]=texto[x]+26;
						}
					}	
				}
			
				cout<<"TEXTO CODIFICADO:\n"<<texto;

				myfile.open ("codificado.txt",ios::trunc);
				if(myfile.is_open()){
					myfile<<texto;
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
						for(int x=0; x<tam; x++){
							if(texto[x]>64 && texto[x]<91){
								texto[x]=texto[x]+((numero%26)-1);
								if(texto[x]>90){
									texto[x]=texto[x]-26;
								}
							}
						}
						cout<<texto<<endl;
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
