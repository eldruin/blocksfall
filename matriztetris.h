#ifndef MATRIZ_TETRIS_H_
#define MATRIZ_TETRIS_H_

#define XM2 6
#define YM2 17

#include <iostream>
#include <curses.h>
#include <string>
#include "matriz.h"
#include "pieza.h"
#include "contador.h"

using std::ostream;
using std::endl;
using std::string;

class MatrizTetris{
	public:
		MatrizTetris(unsigned alto=17, unsigned ancho=10, char ch='X');
		bool pintaPiezaEn(const Pieza&, unsigned, unsigned);
		void pintaPiezaSig(const Pieza&);
		void pintaPuntos(const Contador&);
		void pintaLineas(const Contador&);
		void pintaGameOver();
		inline void pintaNivel(unsigned);
		inline void vaciaVector();
		void borraLinea(unsigned);
		bool detectaLinea(short int&);
		
		void imprimeMatriz();
		friend ostream& operator <<(ostream&, const MatrizTetris&);
		
	private:
		Matriz<char> m1,m2;
		char c;
		vEstado v,vSig;
		unsigned posX,posY;
		
		void inicializaM1();
		void inicializaM2();
		void borraPieza();
		void borraPiezaSig();
		void bajarTodo(unsigned);
		bool detectaColision(const vEstado&, unsigned, unsigned);
		
};

void MatrizTetris::pintaNivel(unsigned n){ m2[15][3] = n+48; }

void MatrizTetris::vaciaVector(){ v.clear(); }

#endif
