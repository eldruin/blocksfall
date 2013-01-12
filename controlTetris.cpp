#include "controlTetris.h"

#include <unistd.h>

//Constructor
ControlTetris::ControlTetris(MatrizTetris& mat) :
	mt(&mat),
	puntos(5),
	lineas(3),
	nivel(1),
	posX(3),
	posY(1),
	p(NULL),
	pSig(NULL)
{
	p = piezaAleatoria();
	mt->pintaPiezaEn(*p,posY,posX);
	mt->pintaPuntos(puntos);
	mt->pintaLineas(lineas);
	mt->pintaNivel(nivel);
	usleep(1000000);
	pSig = piezaAleatoria();
	mt->pintaPiezaSig(*pSig);
}

void ControlTetris::siguientePieza(){
	posX = 3;
	posY = 1;
	if(p != NULL) delete p;
	p = pSig;
	if(!mt->pintaPiezaEn(*p,posY,posX))	throw(GameOver(*mt));
	pSig = piezaAleatoria();
	mt->pintaPiezaSig(*pSig);
}

void ControlTetris::caerPieza(){
	while(mt->pintaPiezaEn(*p,posY+1,posX))
		posY++;
	mt->pintaPiezaEn(*p,posY,posX);
	mt->vaciaVector();
	incrementarPuntos(50);
	limpiaLineas(posY + (p->dimension() - 1));
	siguientePieza();
}

void ControlTetris::limpiaLineas(short int fila){
	while(mt->detectaLinea(fila)){
		incrementarLineas(1);
		incrementarPuntos(1000);
		mt->borraLinea(fila);
		fila--;
	}
}

Pieza* ControlTetris::piezaAleatoria(){
	srand(time(0));
	switch(rand()%16){
		case 1: case 10: case 15:
			return new PiezaS();
			break;
		case 2: case 11: case 8:
			return new PiezaS2();
			break;
		case 3: case 12: case 7:
			return new PiezaL();
			break;
		case 13: case 14: case 9:
			return new PiezaL2();
			break;
		case 0: case 5:
			return new PiezaT();
			break;
		case 6:
			return new PiezaC();
			break;
		case 4:
			return new PiezaP();
			break;
		default:
			throw RandomException("PIEZA FUERA DE SWITCH");
	}
}

void ControlTetris::pause(){
	while(true)
		if(ControlTetris::kbhit())				//KBHIT
			if(getch() == 'p')
				break;
}
