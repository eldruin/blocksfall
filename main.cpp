#include <iostream>
#include <unistd.h>
#include <curses.h>
#include "matriztetris.h"
#include "contador.h"
#include "controlTetris.h"

using namespace std;

void clearScreen()                  //Limpia la pantalla
{
	//fprintf(stdout, "\33[2J");
	//fprintf(stdout, "\33[1;1H");
	clear();
}

void iniciaCurses(){
	initscr();
	noecho();
	cbreak();
	nodelay(stdscr, TRUE);
}

void mostrarControles();
void finDelJuego(const ControlTetris&);

int main(){
	clearScreen();			//LIMPIA PANTALLA
	iniciaCurses();
	mostrarControles();
	//cout<<"Cargando..."<<endl;
	printw("Cargando...");
	refresh();
	vector<unsigned> delay(9,0);
	unsigned rest = 200000;
	const char* continuar;
	for(unsigned i=0 ; i<delay.size() ; i++){
		delay[i] = rest;
		rest -= 20000;
	}
	do{
		MatrizTetris mt;
		ControlTetris ct(mt);
		bool LETSPLAYBABY = true;
		unsigned cont = 0;
		try{
			clearScreen();				//LIMPIA PANTALLA
			while(LETSPLAYBABY){
				//iniciaCurses();							//CURSEEEEESZ
				if(ControlTetris::kbhit()){		//KBHIT
					switch(getch()){
						case 's':
							ct.bajarPieza();
							break;
						case 'w':
							ct.rotarPieza();
							break;
						case 'a':
							ct.moverIzqda();
							break;
						case 'd':
							ct.moverDrcha();
							break;
						case ' ':
							ct.caerPieza();
							break;
						case 'p':
							ct.pause();
							break;
						case '0':
							LETSPLAYBABY = false;
							break;
					}
					clearScreen();		//LIMPIAR PANTALLA
					//cout<<mt<<endl;
					mt.imprimeMatriz();
				}
				if(cont<5){
					cont++;
					usleep(delay[ ct.getNivel() ]);
				}
				else{
					ct.bajarPieza();
					cont = 0;
					clearScreen();		//LIMPIA PANTALLA
					//cout<<mt<<endl;
					mt.imprimeMatriz();
				}
			}
		}catch(ControlTetris::GameOver){
			clearScreen();				//LIMPIA PANTALLA
			//cout<<mt<<endl;
			mt.imprimeMatriz();
		}
		finDelJuego(ct);
		scanw(continuar);
		endwin();
		clearScreen();				//LIMPIA PANTALLA
		if(continuar[0] == 's' || continuar[0] == 'S'){
			printw("Cargando nueva partida...\n");
			refresh();
		}
	}while(continuar[0] == 's' || continuar[0] == 'S');
	clearScreen();
	return 0;
}

void finDelJuego(const ControlTetris& ct){
	usleep(4000000);
	clearScreen();					//LIMPIA PANTALLA
	
	/*printw("\n\t¿Tan solo ");
	printw((char)ct.getPuntos().numero());
	printw(" puntos y ");
	printw((char)ct.getLineas().numero());
	printw(" lineas?\n");
	printw("\t\nNo creo que lo vayas a superar pero aun asi...\n");*/
	printw("Otra partida? [s/n]: ");
	refresh();
}

void mostrarControles(){
	printw("\t# CONTROLES #");
	printw("\n-Izquierda: a\n-Derecha: d\n-Rotar: w\n-Bajar: s\n-Soltar pieza: Espacio\n\n");
	refresh();
	nodelay(stdscr, FALSE);
	getch();
	nodelay(stdscr, TRUE);
}
