#include <bits/stdc++.h>
using namespace std;

// Cada orden es una transposicion fija de posiciones (a,b) que cada cuadrilla
// aplica o no segun la senale la batuta. Es decir: buscamos una secuencia
// corta de "interruptores" comun a todas las cuadrillas tal que cada una,
// activando los suyos, realice su propia permutacion. Eso es exactamente una
// red de Benes (en su version de Waksman para tamanos arbitrarios): una red
// de intercambiadores opcionales con posiciones fijas capaz de encaminar
// CUALQUIER permutacion eligiendo que interruptores se cruzan.
//
// La red sobre m cables se construye recursivamente: una columna de entrada
// con interruptores en las parejas (1,2), (3,4), ...; dos subredes, la
// "superior" con los cables de indice par y la "inferior" con los de indice
// impar; y una columna de salida con las mismas parejas. Para encaminar una
// permutacion se decide a que subred va cada elemento con un 2-coloreado:
// los dos elementos de una pareja de entrada deben ir a subredes distintas,
// y los dos elementos que desembocan en una misma pareja de salida tambien.
// El grafo de esas restricciones tiene grado <= 2 y sus ciclos son pares
// (alternan restriccion de entrada y de salida), asi que el coloreado
// siempre existe; con m impar, el cable sin pareja fuerza su color.
//
// Numero de interruptores: S(m) = 2*floor(m/2) + S(ceil(m/2)) + S(floor(m/2))
// con S(2) = 1, lo que da S(200) = 1392 <= 2500. Cada interruptor se emite
// como una orden con el subconjunto de cuadrillas que se cruzan en el (y se
// omite si ninguna lo hace), asi que la cota se respeta siempre.

int k;

struct Orden {
	int a, b;
	vector<int> cuadrillas;
};
vector<Orden> ordenes;

// w: posiciones reales (1..n) de los cables de esta subred. dest[q][i]: cable
// de salida al que debe llegar el valor que entra por el cable i en la
// cuadrilla q. Emite las ordenes que encaminan todas las cuadrillas a la vez.
void rutea(const vector<int>& w, vector<vector<int>>& dest)
{
	int m = w.size();
	if (m <= 1)
		return;
	if (m == 2) {
		vector<int> qs;
		for (int q = 0; q < k; ++q)
			if (dest[q][0] == 1)
				qs.push_back(q);
		if (!qs.empty())
			ordenes.push_back({w[0], w[1], qs});
		return;
	}

	int pares = m / 2, tamSup = m - pares;
	vector<vector<int>> destSup(k, vector<int>(tamSup));
	vector<vector<int>> destInf(k, vector<int>(pares));
	vector<vector<int>> cruzaEntrada(pares), cruzaSalida(pares);
	vector<int> color(m), idest(m);

	for (int q = 0; q < k; ++q) {
		auto& d = dest[q];
		for (int i = 0; i < m; ++i)
			idest[d[i]] = i;
		fill(color.begin(), color.end(), -1);

		// Colorea la componente de v0 alternando (0 = superior, 1 = inferior).
		// Vecinos de v: su pareja de entrada (v^1) y el elemento que sale por
		// la pareja de salida de d[v]; el cable impar de una red impar no
		// tiene pareja.
		auto pinta = [&](int v0) {
			color[v0] = 0; // los cables forzados siempre van a la superior
			deque<int> porVisitar{v0};
			while (!porVisitar.empty()) {
				int v = porVisitar.front();
				porVisitar.pop_front();
				int vecinos[2];
				vecinos[0] = (m % 2 && v == m - 1) ? -1 : (v ^ 1);
				int t = d[v];
				vecinos[1] = (m % 2 && t == m - 1) ? -1 : idest[t ^ 1];
				for (int u : vecinos)
					if (u >= 0 && color[u] == -1) {
						color[u] = color[v] ^ 1;
						porVisitar.push_back(u);
					}
			}
		};

		if (m % 2) {
			// Con m impar, el ultimo cable de entrada y el de salida estan
			// cableados directamente a la subred superior: color forzado.
			pinta(m - 1);
			if (color[idest[m - 1]] == -1)
				pinta(idest[m - 1]);
		}
		for (int i = 0; i < m; ++i)
			if (color[i] == -1)
				pinta(i);

		// Interruptor de entrada i: cruzado si el valor del cable par debe
		// ir a la subred inferior. De salida j: cruzado si el valor que debe
		// salir por el cable par viene de la subred inferior.
		for (int i = 0; i < pares; ++i)
			if (color[2 * i] == 1)
				cruzaEntrada[i].push_back(q);
		for (int j = 0; j < pares; ++j)
			if (color[idest[2 * j]] == 1)
				cruzaSalida[j].push_back(q);

		// Destinos dentro de cada subred: la pareja i de fuera es el cable i
		// de dentro, tanto a la entrada como a la salida.
		for (int i = 0; i < m; ++i) {
			if (color[i] == 0)
				destSup[q][i / 2] = d[i] / 2;
			else
				destInf[q][i / 2] = d[i] / 2;
		}
	}

	for (int i = 0; i < pares; ++i)
		if (!cruzaEntrada[i].empty())
			ordenes.push_back({w[2 * i], w[2 * i + 1], cruzaEntrada[i]});

	vector<int> wSup(tamSup), wInf(pares);
	for (int j = 0; j < tamSup; ++j)
		wSup[j] = w[2 * j];
	for (int j = 0; j < pares; ++j)
		wInf[j] = w[2 * j + 1];
	rutea(wSup, destSup);
	rutea(wInf, destInf);

	for (int j = 0; j < pares; ++j)
		if (!cruzaSalida[j].empty())
			ordenes.push_back({w[2 * j], w[2 * j + 1], cruzaSalida[j]});
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n >> k;
		vector<vector<int>> dest(k, vector<int>(n));
		for (int q = 0; q < k; ++q)
			for (int j = 0; j < n; ++j) {
				int altura;
				cin >> altura;
				dest[q][j] = altura - 1; // debe acabar en la posicion "altura"
			}

		ordenes.clear();
		vector<int> w(n);
		iota(w.begin(), w.end(), 1);
		rutea(w, dest);

		cout << ordenes.size() << '\n';
		for (const auto& o : ordenes) {
			cout << o.a << ' ' << o.b << ' ' << o.cuadrillas.size();
			for (int q : o.cuadrillas)
				cout << ' ' << q + 1;
			cout << '\n';
		}
	}
	return 0;
}
