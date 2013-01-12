#include "pieza.h"

//Definicion PiezaL
vEstado PiezaL::v1;
vEstado PiezaL::v2;
vEstado PiezaL::v3;
vEstado PiezaL::v4;

//Definicion PiezaL2
vEstado PiezaL2::v1;
vEstado PiezaL2::v2;
vEstado PiezaL2::v3;
vEstado PiezaL2::v4;

//Definicion PiezaS
vEstado PiezaS::v1;
vEstado PiezaS::v2;

//Definicion PiezaS2
vEstado PiezaS2::v1;
vEstado PiezaS2::v2;

//Definicion PiezaT
vEstado PiezaT::v1;
vEstado PiezaT::v2;
vEstado PiezaT::v3;
vEstado PiezaT::v4;

//Definicion PiezaC
vEstado PiezaC::v1;

//Definicion PiezaP
vEstado PiezaP::v1;
vEstado PiezaP::v2;

PiezaL::PiezaL() : estado(0), Pieza(3)
{
	if(v1.empty()){
		v1.push_back(make_pair(0,1));
		v1.push_back(make_pair(1,1));
		v1.push_back(make_pair(2,1));
		v1.push_back(make_pair(2,2));
	}
	if(v2.empty()){
		v2.push_back(make_pair(1,0));
		v2.push_back(make_pair(1,1));
		v2.push_back(make_pair(1,2));
		v2.push_back(make_pair(2,0));
	}
	if(v3.empty()){
		v3.push_back(make_pair(0,0));
		v3.push_back(make_pair(0,1));
		v3.push_back(make_pair(1,1));
		v3.push_back(make_pair(2,1));
	}
	if(v4.empty()){
		v4.push_back(make_pair(1,2));
		v4.push_back(make_pair(2,2));
		v4.push_back(make_pair(2,1));
		v4.push_back(make_pair(2,0));
	}
}

PiezaL2::PiezaL2() : estado(0), Pieza(3)
{
	if(v1.empty()){
		v1.push_back(make_pair(0,1));
		v1.push_back(make_pair(1,1));
		v1.push_back(make_pair(2,1));
		v1.push_back(make_pair(2,0));
	}
	if(v2.empty()){
		v2.push_back(make_pair(1,0));
		v2.push_back(make_pair(2,0));
		v2.push_back(make_pair(2,1));
		v2.push_back(make_pair(2,2));
	}
	if(v3.empty()){
		v3.push_back(make_pair(0,1));
		v3.push_back(make_pair(0,2));
		v3.push_back(make_pair(1,1));
		v3.push_back(make_pair(2,1));
	}
	if(v4.empty()){
		v4.push_back(make_pair(1,0));
		v4.push_back(make_pair(1,1));
		v4.push_back(make_pair(1,2));
		v4.push_back(make_pair(2,2));
	}
}

PiezaS::PiezaS() : estado(0), Pieza(3)
{
	if(v1.empty()){
		v1.push_back(make_pair(0,2));
		v1.push_back(make_pair(1,1));
		v1.push_back(make_pair(1,2));
		v1.push_back(make_pair(2,1));
	}
	if(v2.empty()){
		v2.push_back(make_pair(1,0));
		v2.push_back(make_pair(1,1));
		v2.push_back(make_pair(2,1));
		v2.push_back(make_pair(2,2));
	}
}

PiezaS2::PiezaS2() : estado(0), Pieza(3)
{
	if(v1.empty()){
		v1.push_back(make_pair(0,0));
		v1.push_back(make_pair(1,0));
		v1.push_back(make_pair(1,1));
		v1.push_back(make_pair(2,1));
	}
	if(v2.empty()){
		v2.push_back(make_pair(1,1));
		v2.push_back(make_pair(1,2));
		v2.push_back(make_pair(2,0));
		v2.push_back(make_pair(2,1));
	}
}

PiezaT::PiezaT() : estado(0), Pieza(3)
{
	if(v1.empty()){
		v1.push_back(make_pair(0,1));
		v1.push_back(make_pair(1,0));
		v1.push_back(make_pair(1,1));
		v1.push_back(make_pair(1,2));
	}
	if(v2.empty()){
		v2.push_back(make_pair(0,1));
		v2.push_back(make_pair(1,1));
		v2.push_back(make_pair(1,2));
		v2.push_back(make_pair(2,1));
	}
	if(v3.empty()){
		v3.push_back(make_pair(1,0));
		v3.push_back(make_pair(1,1));
		v3.push_back(make_pair(1,2));
		v3.push_back(make_pair(2,1));
	}
	if(v4.empty()){
		v4.push_back(make_pair(0,1));
		v4.push_back(make_pair(1,0));
		v4.push_back(make_pair(1,1));
		v4.push_back(make_pair(2,1));
	}
}

PiezaC::PiezaC() : Pieza(2)
{
	if(v1.empty()){
		v1.push_back(make_pair(0,0));
		v1.push_back(make_pair(0,1));
		v1.push_back(make_pair(1,0));
		v1.push_back(make_pair(1,1));
	}
}

PiezaP::PiezaP() : estado(0), Pieza(4)
{
	if(v1.empty()){
		v1.push_back(make_pair(0,1));
		v1.push_back(make_pair(1,1));
		v1.push_back(make_pair(2,1));
		v1.push_back(make_pair(3,1));
	}
	if(v2.empty()){
		v2.push_back(make_pair(1,0));
		v2.push_back(make_pair(1,1));
		v2.push_back(make_pair(1,2));
		v2.push_back(make_pair(1,3));
	}
}
