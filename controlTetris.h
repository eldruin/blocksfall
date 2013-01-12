#ifndef CONTROL_TETRIS_H_
#define CONTROL_TETRIS_H_

#include <ctime>
#include <cstdlib>
#include <curses.h>
#include "matriztetris.h"
#include "pieza.h"

class ControlTetris{
	public:
		ControlTetris(MatrizTetris&);
		void caerPieza();
		inline void bajarPieza();
		inline void moverDrcha();
		inline void moverIzqda();
		inline void rotarPieza();
		void pause();
		
		const Contador& getPuntos() const{ return puntos; }
		const Contador& getLineas() const{ return lineas; }
		unsigned getNivel() const{ return nivel; }
		
		static bool kbhit(){
			int ch = getch();
    		if (ch != ERR) {
    		    ungetch(ch);
    		    return true;
    		}
    		else
    		    return false;
    	}
		
		class RandomException;
		class GameOver;
		
		~ControlTetris(){
			if(p != NULL) delete p;
			if(pSig != NULL) delete pSig;
		}
		
	private:
		MatrizTetris* mt;
		Contador puntos, lineas;
		unsigned nivel, posX, posY;
		Pieza *p, *pSig;
		
		Pieza* piezaAleatoria();
		void siguientePieza();
		void limpiaLineas(short int);
		
		inline void subirNivel();
		inline void incrementarPuntos(int);
		inline void incrementarLineas(unsigned);
		inline void cambiarNivel(unsigned);
		
};

class ControlTetris::RandomException{
	public:
		RandomException(const char* cad) : str(cad){}
		const char* why() const{ return str; }
	private:
		const char* str;
};

class ControlTetris::GameOver{
	public:
		GameOver(MatrizTetris& m) : mt(m) {
			mt.pintaGameOver();
		}
	private:
		MatrizTetris& mt;
};

void ControlTetris::bajarPieza(){
	if(mt->pintaPiezaEn(*p,posY+1,posX)){
		posY++;
	}
	else{
		mt->pintaPiezaEn(*p,posY,posX);
		mt->vaciaVector();
		incrementarPuntos(50);
		limpiaLineas(posY + (p->dimension() - 1));
		siguientePieza();
	}
}

void ControlTetris::moverDrcha(){
	if(mt->pintaPiezaEn(*p,posY,posX+1))
		posX++;
	else
		mt->pintaPiezaEn(*p,posY,posX);
}

void ControlTetris::moverIzqda(){
	if(mt->pintaPiezaEn(*p,posY,posX-1))
		posX--;
	else
		mt->pintaPiezaEn(*p,posY,posX);
}

void ControlTetris::rotarPieza(){
	p->rotar();
	if(!mt->pintaPiezaEn(*p,posY,posX)){
		p->rotar();
		p->rotar();
		p->rotar();
		mt->pintaPiezaEn(*p,posY,posX);
	}
}

void ControlTetris::incrementarPuntos(int n){
	puntos.incrementar(n);
	mt->pintaPuntos(puntos);
	if(unsigned(puntos.numero()) >= 10000*nivel)
		subirNivel();
}

void ControlTetris::incrementarLineas(unsigned n){
	lineas.incrementar(n);
	mt->pintaLineas(lineas);
}

void ControlTetris::cambiarNivel(unsigned n){
	nivel = n;
	mt->pintaNivel(nivel);
}

void ControlTetris::subirNivel(){
	nivel++;
	mt->pintaNivel(nivel);
}

#endif
