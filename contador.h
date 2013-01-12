#ifndef CONTADOR_H_
#define CONTADOR_H_

#include <iostream>
#include <vector>

using std::vector;
using std::ostream;

class Contador{
	public:
		Contador(unsigned cifras) : puntos( vector<int>(cifras,0)), vueltas(0){}
		Contador(const Contador& c) : puntos(c.puntos), vueltas(0) {}
		void incrementar(int);
		const vector<int>& vectorPuntos() const{ return puntos; }
		int numero() const;
	private:
		vector<int> puntos;
		unsigned vueltas;
		void sumarCelda(int, int);
		void vuelta();
};

#endif