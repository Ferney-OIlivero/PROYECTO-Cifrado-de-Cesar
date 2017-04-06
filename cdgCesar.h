#ifndef CDGCESAR_H
#define CDGCESAR_H


using namespace std;
class cdgCesar{
	
	public:
		void setTexto(string v);
		void setCodificado(string v, int numero, int tam);
		void setDecodificado(string v, int numero, int tam);
		string getTexto();
		// class constructor
		cdgCesar();
		// class destructor
		~cdgCesar();
	private:
		string texto;
};


#endif
