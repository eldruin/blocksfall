#ifndef MATRIZ_H_
#define MATRIZ_H_

#include <vector>
#include <iostream>

using std::vector;
using std::ostream;
using std::endl;

template <typename T> class Matriz{
	public:
		Matriz(){}
		Matriz(unsigned, unsigned, const T& e = T());
		Matriz(const Matriz<T>&);
		unsigned dimensionX() const;
		unsigned dimensionY() const;
		vector<T> operator[](unsigned) const;
		vector<T>& operator[](unsigned);
		unsigned at(unsigned, unsigned) const;
		unsigned& at(unsigned, unsigned);
		void rellenaFila(unsigned, const T&);
		void rellenaColumna(unsigned, const T&);
		
		class OutOfRange{
			public:
				OutOfRange(const char* c){ cad = c; }
				const char* why() const{ return cad; }
			private:
				const char* cad;
		};
		
	protected:
		vector< vector<T> > m;
};

template <typename T>
ostream& operator <<(ostream&, const Matriz<T>&);

template <typename T>
Matriz<T>::Matriz(unsigned alto, unsigned ancho, const T& e) : m(alto,vector<T>(ancho,e)) {}

template <typename T>
Matriz<T>::Matriz(const Matriz<T>& mat){
	if(&mat != this){
		m.clear();
		for(int i=0 ; i<mat.m.size() ; i++)
			m.push_back(mat.m[i]);
	}
}

template <typename T>
inline unsigned Matriz<T>::dimensionX() const{ return m[0].size(); }
template <typename T>
inline unsigned Matriz<T>::dimensionY() const{ return m.size(); }

template <typename T>
inline vector<T> Matriz<T>::operator [](unsigned i) const{ return m[i]; }
template <typename T>
inline vector<T>& Matriz<T>::operator [](unsigned i){ return m[i]; }
template <typename T>
inline unsigned Matriz<T>::at(unsigned i, unsigned j) const{
	if(dimensionY() > i) throw OutOfRange("El indice i sobrepasa el eje Y");
	if(dimensionX() > j) throw OutOfRange("El indice j sobrepasa el eje X");
	return m[i][j];
}
template <typename T>
inline unsigned& Matriz<T>::at(unsigned i, unsigned j){
	if(dimensionY() > i) throw OutOfRange("El indice i sobrepasa el eje Y");
	if(dimensionX() > i) throw OutOfRange("El indice j sobrepasa el eje X");
	return m[i][j];
}

template <typename T>
void Matriz<T>::rellenaFila(unsigned i, const T& x){
	for(unsigned j=0 ; j<dimensionX() ; j++)
		m[i][j] = x;
}

template <typename T>
void Matriz<T>::rellenaColumna(unsigned j, const T& x){
	for(unsigned i=0 ; i<dimensionY() ; i++)
		m[i][j] = x;
}

template <typename T>
ostream& operator <<(ostream& os, const Matriz<T>& m){
	for(unsigned i=0 ; i<m.dimensionY() ; i++){
		for(unsigned j=0 ; j<m.dimensionX() ; j++)
			os<<m[i][j];
		os<<endl;
	}
	return os;
}

#endif
