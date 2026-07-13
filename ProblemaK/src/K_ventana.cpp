// Problema K - Turismo de musicales
//
// Buscamos la sublista de dias consecutivos mas corta que contenga al menos
// una representacion de cada uno de los tres musicales (C, R y H).
//
// La recorremos con una ventana deslizante [l, r] sobre la que llevamos la
// cuenta de cuantas veces aparece cada musical dentro de ella. Partimos de una
// ventana de un solo dia y la hacemos crecer por la derecha de uno en uno.
// Tras cada avance, mientras expulsar el dia del extremo izquierdo deje la
// ventana todavia valida (mientras ese musical aparezca repetido dentro de la
// ventana), lo expulsamos. Asi, para cada extremo derecho r, la ventana queda
// ajustada a la sublista valida mas corta que termina en r, y su longitud es
// candidata a solucion.

#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(nullptr); ios_base::sync_with_stdio(false);

	int n;
	while (cin >> n && n){
		vector<char> dias(n);
		for (auto &d : dias) cin >> d;

		// cuenta[m] = apariciones del musical m dentro de la ventana actual.
		map<char,int> cuenta;
		int distintos = 0;   // musicales distintos presentes en la ventana
		int l = 0;
		int res = n + 1;

		for (int r = 0; r < n; r++){
			if (cuenta[dias[r]]++ == 0) distintos++;

			// Con la ventana ya valida, expulsamos por la izquierda cada dia
			// repetido: quitarlo la mantiene valida y mas corta.
			while (distintos == 3 && cuenta[dias[l]] > 1){
				cuenta[dias[l]]--;
				l++;
			}

			if (distintos == 3) res = min(res, r - l + 1);
		}

		if (res != n + 1) cout << res << '\n';
		else cout << "NO SE PUEDE\n";
	}
	return 0;
}
