#include <iostream>
using namespace std;
///Sereja and brackets
struct nodo{
	int izq= 0, der= 0, equ= 0;
};
int Q;
string cadena;

struct tree{
	nodo rama[4000002];

	nodo Mezclar(nodo i, nodo d){
		nodo ret;
		ret.equ= min(i.izq, d.der);
		i.izq-= ret.equ;
		d.der-= ret.equ;
		ret.equ*= 2;
		ret.equ+= i.equ+ d.equ;
		ret.izq= i.izq+ d.izq;
		ret.der= i.der+ d.der;
		return ret;
	}

	void Crear(int ini, int fin, int r){
		if(ini== fin){
			if(cadena[ini-1]== '(') rama[r].izq=1;
			else rama[r].der=1;
			return;
		}
		Crear(ini, (ini+ fin)/ 2, r* 2);
		Crear((ini+ fin)/ 2+ 1, fin, r* 2+ 1);
		rama[r]= Mezclar(rama[r* 2], rama[r* 2+ 1]);
	}

	nodo Rango(int &bIni, int &bFin, int ini, int fin, int r){
		if(ini>=bIni and fin<=bFin) return rama[r];
		if(ini> bFin or fin< bIni){
			nodo ret;
			return ret;
		}
		return Mezclar(Rango(bIni, bFin, ini, (ini+ fin)/ 2, r*2), Rango(bIni, bFin, (ini+ fin)/ 2+ 1, fin, r* 2+ 1) );
	}
}arbol;

void Lectura(){
	cin>>cadena;
	cin>>Q;
}

void Preguntas(){
	int ini, fin;
	nodo res;
	for(int i= 1; i<= Q; i++){
		cin>> ini>> fin;
		res= arbol.Rango(ini, fin, 1, cadena.size(), 1);
		cout<<res.equ<<'\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	Lectura();
	arbol.Crear(1, cadena.size(), 1);
	Preguntas();

	return 0;
}
/// xD
/**
())(())(())(
7
1 1
2 3
1 2
1 12
8 12
5 11
2 10

**/