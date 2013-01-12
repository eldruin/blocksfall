#ifndef PIEZA_H_
#define PIEZA_H_

#include <vector>
#include <map>
#include <utility>

using std::vector;
using std::map;
using std::pair;
using std::make_pair;

typedef vector< pair<unsigned,unsigned> > vEstado;

class Pieza{
	public:
		Pieza(unsigned d) : dim(d) {}
		virtual void rotar(){}
		virtual const vEstado& vectorEstado() const = 0;
		unsigned dimension() const{ return dim; }
		
		class EstadoImposible{
			public:
				EstadoImposible(const char* str) : cad(str){}
				const char* who() const{ return cad; }
			private:
				const char* cad;
		};
		
		virtual ~Pieza(){}
		
	private:
		unsigned dim;
		
};
	
#endif

	#ifndef PIEZA_L_H_
	#define PIEZA_L_H_
	
	class PiezaL : public Pieza{
		public:
			PiezaL();
			inline void rotar();
			inline const vEstado& vectorEstado() const;
			~PiezaL(){}
		private:
			unsigned estado;
			static vEstado v1,v2,v3,v4;
			
	};
	
	void PiezaL::rotar(){
		if(estado < 3)
			estado++;
		else
			if(estado == 3)
				estado = 0;
			else
				throw EstadoImposible("PiezaL tiene un estado imposible");
	}
	
	const vEstado& PiezaL::vectorEstado() const{
		switch(estado){
			case 0:
				return v1;
				break;
			case 1:
				return v2;
				break;
			case 2:
				return v3;
				break;
			case 3:
				return v4;
				break;
			default:
				throw EstadoImposible("PiezaL tiene un estado imposible");
		}
	}
	
	#endif
	
	#ifndef PIEZA_L2_H_
	#define PIEZA_L2_H_
	
	class PiezaL2 : public Pieza{
		public:
			PiezaL2();
			inline void rotar();
			inline const vEstado& vectorEstado() const;
			~PiezaL2(){}
		private:
			unsigned estado;
			static vEstado v1,v2,v3,v4;
	};
	
	void PiezaL2::rotar(){
		if(estado < 3)
			estado++;
		else
			if(estado == 3)
				estado = 0;
			else
				throw EstadoImposible("PiezaL2 tiene un estado imposible");
	}
	
	const vEstado& PiezaL2::vectorEstado() const{
		switch(estado){
			case 0:
				return v1;
				break;
			case 1:
				return v2;
				break;
			case 2:
				return v3;
				break;
			case 3:
				return v4;
				break;
			default:
				throw EstadoImposible("PiezaL2 tiene un estado imposible");
		}
	}
	
	#endif
	
	#ifndef PIEZA_S_H_
	#define PIEZA_S_H_
	
	class PiezaS : public Pieza{
		public:
			PiezaS();
			inline void rotar();
			inline const vEstado& vectorEstado() const;
			~PiezaS(){}
		private:
			bool estado;
			static vEstado v1,v2;
	};
	
	void PiezaS::rotar(){
		if(estado == 0)
			estado++;
		else
			if(estado == 1)
				estado = 0;
			else
				throw EstadoImposible("PiezaS tiene un estado imposible");
	}
	
	const vEstado& PiezaS::vectorEstado() const{
		if(estado)
			return v2;
		else
			if(estado == 0)
				return v1;
			else
				throw EstadoImposible("PiezaS tiene un estado imposible");
	}
	
	#endif
	
	#ifndef PIEZA_S2_H_
	#define PIEZA_S2_H_
	
	class PiezaS2 : public Pieza{
		public:
			PiezaS2();
			inline void rotar();
			inline const vEstado& vectorEstado() const;
			~PiezaS2(){}
		private:
			bool estado;
			static vEstado v1,v2;
	};
	
	void PiezaS2::rotar(){
		if(estado == 0)
			estado++;
		else
			if(estado == 1)
				estado = 0;
			else
				throw EstadoImposible("PiezaS2 tiene un estado imposible");
	}
	
	const vEstado& PiezaS2::vectorEstado() const{
		if(estado)
			return v2;
		else
			if(estado == 0)
				return v1;
			else
				throw EstadoImposible("PiezaS2 tiene un estado imposible");
	}
	
	#endif
	
	#ifndef PIEZA_T_H_
	#define PIEZA_T_H_
	
	class PiezaT : public Pieza{
		public:
			PiezaT();
			inline void rotar();
			inline const vEstado& vectorEstado() const;
			~PiezaT(){}
		private:
			unsigned estado;
			static vEstado v1,v2,v3,v4;
	};
	
	void PiezaT::rotar(){
		if(estado < 3)
			estado++;
		else
			if(estado == 3)
				estado = 0;
			else
				throw EstadoImposible("PiezaT tiene un estado imposible");
	}
	
	const vEstado& PiezaT::vectorEstado() const{
		switch(estado){
			case 0:
				return v1;
				break;
			case 1:
				return v2;
				break;
			case 2:
				return v3;
				break;
			case 3:
				return v4;
				break;
			default:
				throw EstadoImposible("PiezaT tiene un estado imposible");
		}
	}
	
	#endif
	
	#ifndef PIEZA_C_H_
	#define PIEZA_C_H_
	
	class PiezaC : public Pieza{
		public:
			PiezaC();
			inline void rotar(){}
			inline const vEstado& vectorEstado() const{ return v1; }
			~PiezaC(){}
		private:
			static vEstado v1;
	};
	
	#endif
	
	#ifndef PIEZA_P_H_
	#define PIEZA_P_H_
	
	class PiezaP : public Pieza{
		public:
			PiezaP();
			inline void rotar();
			inline const vEstado& vectorEstado() const;
			~PiezaP(){}
		private:
			bool estado;
			static vEstado v1,v2;
	};
	
	void PiezaP::rotar(){
		if(estado == 0)
			estado++;
		else
			if(estado == 1)
				estado = 0;
			else
				throw EstadoImposible("PiezaP tiene un estado imposible");
	}
	
	const vEstado& PiezaP::vectorEstado() const{
		if(estado)
			return v2;
		else
			if(estado == 0)
				return v1;
			else
				throw EstadoImposible("PiezaP tiene un estado imposible");
	}
	
	#endif


