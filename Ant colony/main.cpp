#include <iostream>
#include <vector>
using namespace std;
///Ant Colony
int n, Q, fuerza[100002];

void Lectura(){
	cin>>n;
	for(int i= 1; i<=n; i++){
		cin>>fuerza[i];
	}
	cin>>Q;
}

struct tree{
	vector<vector< int> > rama(400002);

	void Mezclar(int iniIzq, int finIzq, int iniDer, int finDer, vector<int> izq, vector<int> der){
		vector<int> eliminarIzq;
		vector<int> eliminarDer;
		for(int i=0; i< izq.size(); i++){
			for(int j= iniDer; j<= finDer; j++){
				if(fuerza[izq[i]]% fuerza[j]!= 0){
					eliminarIzq.push_back(i);
					break;
				}
			}
		}

		for(int i=0; i< der.size(); i++){
			for(int j= iniIzq; j<= finIzq; j++){
				if(fuerza[der[i]]% fuerza[j]!= 0){
					eliminarIzq.push_back(i);
					break;
				}
			}
		}


		for(int i=eliminarIzq.size() +1; i>=0; i--){
			izq.erase(izq.begin()+ eliminarIzq[i]);
		}

		for(int i=eliminarDer.size() +1; i>=0; i--){
			izq.erase(izq.begin()+ eliminarDer[i]);
		}

		for(int i=0; i<= der.size(); i++) izq.push_back(der[i]);

		return izq;
	}

	void Crear(int ini, int fin, int r){
		if(ini== fin){
			rama[r]== ini;
			return;
		}
		Crear(ini, (ini+ fin)/ 2, r*2);
		Crear((ini+ fin) / 2+ 1, fin, r* 2+ 1);
		rama[r]= Mezclar()
	}
};



void Preguntas(){
	int ini, fin;
	for(int q= 1; q<= Q; q++){
		cin>> ini>> fin;
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	Lectura();

	Preguntas();

	return 0;
}
/// xD
/**
5
1 3 2 4 2
4
1 5
2 5
3 5
4 5
**/