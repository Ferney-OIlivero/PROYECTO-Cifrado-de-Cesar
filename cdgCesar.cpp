#include <iostream>
#include "cdgCesar.h"
using namespace std;

void cdgCesar::setTexto(string v){
	this->texto=v;
}

void cdgCesar::setCodificado(string tex, int numero, int tam){
	this->texto=tex;
	for(int x=0; x<tam; x++){
		if(this->texto[x]>64 && this->texto[x]<91){
			this->texto[x]=this->texto[x]-((numero%26)-1);
			if(this->texto[x]<65){
				this->texto[x]=this->texto[x]+26;
			}
		}	
	}
}

void cdgCesar::setDecodificado(string tex, int numero, int tam){
	this->texto=tex;
	for(int x=0; x<tam; x++){
		if(this->texto[x]>64 && this->texto[x]<91){
			this->texto[x]=this->texto[x]+((numero%26)-1);
			if(this->texto[x]>90){
				this->texto[x]=this->texto[x]-26;
			}
		}
	}
}

string cdgCesar::getTexto(){

	return this->texto;
}


// class constructor
cdgCesar::cdgCesar()
{
	// insert your code here
}

// class destructor
cdgCesar::~cdgCesar()
{
	// insert your code here
}

