#include <iostream>
#include <fstream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	string palabra;
	int numero,tam,opc;
	ofstream myfile;
	
	cout<<"\tSELECIONES UNA OPCION"<<endl;
	cout<<"1.- CODIFICAR"<<endl;
	cout<<"1.- DECODIFICAR"<<endl;
	cin>>opc;
	switch(opc){
		case 1:
			cout<<"INGRESE LA PALABRA QUE DESEA CODIFICAR"<<endl;
			cin>>palabra;
			cout<<"INGRESE El NUMERO DE LA CODIFICACION"<<endl;
			cin>>numero;
	
			tam=palabra.size();
			for(int x=0; x<tam; x++){
				palabra[x]=palabra[x]-((numero%26)-1);
				
				if(palabra[x]>90){
					palabra[x]=palabra[x]-26;
				}
				if(palabra[x]<65){
					palabra[x]=palabra[x]+26;
				}
			}
			
			cout<<"PALABRA CODIFICADA:    "<<palabra;
	
			
			myfile.open ("codificado.txt",ios::trunc);
			if(myfile.is_open()){
				myfile<<palabra;
			}
			else{
				cout<<"NO SE COPIO LA PALABRA"<<endl;
			}
			myfile.close();
		break;
		
		case 2:
			cout<<"";
		break;
	}
	return 0;
}
