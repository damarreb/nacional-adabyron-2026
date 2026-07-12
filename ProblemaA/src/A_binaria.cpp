#include <bits/stdc++.h>
using namespace std;

// Busqueda binaria sobre la longitud de la ventana.
//
// Sea P(L) = "existe algun tramo de exactamente L puntos con desnivel <= D".
// P es monotona: si un tramo de longitud L cumple, cualquier subtramo suyo
// (longitud L-1) tambien, luego P(L) => P(L-1). Podemos por tanto buscar
// binariamente la mayor L con P(L) cierta.
//
// Para evaluar P(L) recorremos todas las ventanas de tamano fijo L calculando
// su maximo y su minimo con dos colas monotonas (deques), en O(N).
// Coste total: O(N log N).

static vector<int> a;

// Comprueba si hay alguna ventana de longitud L con max - min <= D.
static bool cabe(int N, int L, int D)
{
	deque<int> maxq, minq; // guardan indices; maxq decreciente, minq creciente
	for (int r = 0; r < N; ++r) {
		while (!maxq.empty() && a[maxq.back()] <= a[r])
			maxq.pop_back();
		maxq.push_back(r);
		while (!minq.empty() && a[minq.back()] >= a[r])
			minq.pop_back();
		minq.push_back(r);

		int l = r - L + 1;
		if (l < 0)
			continue;
		while (maxq.front() < l)
			maxq.pop_front();
		while (minq.front() < l)
			minq.pop_front();
		if (a[maxq.front()] - a[minq.front()] <= D)
			return true;
	}
	return false;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--) {
		int N, D;
		cin >> N >> D;
		a.assign(N, 0);
		for (int& x : a)
			cin >> x;

		int lo = 1, hi = N; // siempre existe una ventana valida de longitud 1
		while (lo < hi) {
			int mid = (lo + hi + 1) / 2;
			if (cabe(N, mid, D))
				lo = mid;
			else
				hi = mid - 1;
		}
		cout << lo << '\n';
	}
	return 0;
}
