#include "matriztetris.h"

MatrizTetris::MatrizTetris(unsigned alto, unsigned ancho, char ch) : 
	m1( Matriz<char>(alto,ancho,' ') ),
	m2( Matriz<char>(YM2,XM2) ),
	c(ch)
{
	inicializaM1();
	inicializaM2();
}

void MatrizTetris::inicializaM1(){
	m1.rellenaFila(0,c);
	m1.rellenaFila(m1.dimensionY()-1,c);
	m1.rellenaColumna(0,c);
	m1.rellenaColumna(m1.dimensionX()-1,c);
}

void MatrizTetris::inicializaM2(){
	for(unsigned i=0 ; i<m2.dimensionY() ; i++)
		for(unsigned j=0 ; j<m2.dimensionX() ; j++)
			m2[i][j] = ' ';
	m2.rellenaColumna(m2.dimensionX()-1,c);
	m2.rellenaFila(0,c);
	m2.rellenaFila(7,c);
	m2.rellenaFila(12,c);
	m2.rellenaFila(16,c);
	m2[8][0] = 'S'; m2[8][1] = 'c'; m2[8][2] = 'o'; m2[8][3] = 'r'; m2[8][4] = 'e';
	m2[10][0] = 'L'; m2[10][1] = 'n'; m2[10][2] = 'a'; m2[10][3] = 's';
	m2[13][0] = 'L'; m2[13][1] = 'e'; m2[13][2] = 'v'; m2[13][3] = 'e'; m2[13][4] = 'l';
}

bool MatrizTetris::pintaPiezaEn(const Pieza& p, unsigned y, unsigned x){
	if(!v.empty()) borraPieza();
	if(!detectaColision(p.vectorEstado(),y,x)){
		posX = x;
		posY = y;
		v = p.vectorEstado();
		for(unsigned i=0 ; i<v.size() ; i++)
			m1[y + v[i].first][x + v[i].second] = '#';
		return true;
	}
	else return false;
}

bool MatrizTetris::detectaColision(const vEstado& v, unsigned y, unsigned x){
	for(unsigned i=0 ; i<v.size() ; i++)
		if(m1[y + v[i].first][x + v[i].second] != ' ')
			return true;
	
	return false;
}

bool MatrizTetris::detectaLinea(short int& fila){
	unsigned cont = 1;
	fila = m1.dimensionY()-2;
	while(fila > 0){
		while(m1[fila][cont] != ' ')
			if(cont == m1.dimensionX()-2) 
				return true;
			else 
				cont++;
		cont = 1;
		fila--;
	}
	return false;
}

void MatrizTetris::borraPieza(){
	for(unsigned i=0 ; i<v.size() ; i++)
		m1[posY + v[i].first][posX + v[i].second] = ' ';
}

void MatrizTetris::pintaPiezaSig(const Pieza& p){
	if(!vSig.empty()) borraPiezaSig();
	vSig = p.vectorEstado();
	for(unsigned i=0 ; i<vSig.size() ; i++)
		m2[2 + vSig[i].first][1 + vSig[i].second] = '#';
}

void MatrizTetris::borraPiezaSig(){
	for(unsigned i=0 ; i<vSig.size() ; i++)
		m2[2 + vSig[i].first][1 + vSig[i].second] = ' ';
}

void MatrizTetris::pintaPuntos(const Contador& c){
	const vector<int>& v = c.vectorPuntos();
	for(unsigned j=0 ; j<v.size() ; j++)
		m2[9][j] = v[j] + 48;
}

void MatrizTetris::pintaLineas(const Contador& c){
	const vector<int>& v = c.vectorPuntos();
	for(unsigned j=0 ; j<v.size() ; j++)
		m2[11][j+1] = v[j] + 48;
}

void MatrizTetris::pintaGameOver(){
	unsigned dim = m1.dimensionX() / 2;
	for(unsigned i=1 ; i<7 ; i++)
		for(unsigned j=dim-3 ; j< dim+3 ; j++)
			m1[i][j] = ' ';
			
	m1[2][dim-2] = 'G';
	m1[2][dim-1] = 'A';
	m1[2][dim]	 = 'M';
	m1[2][dim+1] = 'E';
	m1[5][dim-2] = 'O';
	m1[5][dim-1] = 'V';
	m1[5][dim]	 = 'E';
	m1[5][dim+1] = 'R';
}

void MatrizTetris::borraLinea(unsigned linea){
	for(unsigned j=1 ; j<m1.dimensionX()-1 ; j++)
		m1[linea][j] = ' ';
	
	bajarTodo(linea-1);
}

void MatrizTetris::bajarTodo(unsigned linea){
	for(unsigned i=linea ; i>0 ; i--)
		for(unsigned j=1 ; j<m1.dimensionX()-1 ; j++)
			m1[i+1][j] = m1[i][j];
	
	for(unsigned j=1 ; j<m1.dimensionX()-1 ; j++)
		m1[1][j] = ' ';
}

void MatrizTetris::imprimeMatriz(){
	unsigned dim1 = m1.dimensionX();
	unsigned dim2 = m2.dimensionX();
	for(unsigned i=0 ; i<m1.dimensionY() ; i++){
		for(unsigned j=0 ; j<dim1 ; j++)
			addch(m1[i][j]);
		for(unsigned j=0 ; j<dim2 ; j++)
			addch(m2[i][j]);
		addch('\n');
	}
	refresh();
}

ostream& operator <<(ostream& os, const MatrizTetris& mt){
	unsigned dim1 = mt.m1.dimensionX();
	unsigned dim2 = mt.m2.dimensionX();
	for(unsigned i=0 ; i<mt.m1.dimensionY() ; i++){
		for(unsigned j=0 ; j<dim1 ; j++)
			os<<mt.m1[i][j];
		for(unsigned j=0 ; j<dim2 ; j++)
			os<<mt.m2[i][j];
		os<<endl;
	}
	return os;
}
