#include <bits/stdc++.h>
using namespace std;

// Ventana deslizante con multiset.
//
// Mantenemos una ventana [l, r] y guardamos sus altitudes en un multiset, que
// nos da en todo momento el maximo (rbegin) y el minimo (begin). Al avanzar r
// insertamos a[r]; mientras el desnivel de la ventana supere D, avanzamos l
// eliminando a[l]. l nunca retrocede, asi que cada elemento entra y sale una
// sola vez del multiset: O(N log N).

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--) {
		int N, D;
		cin >> N >> D;
		vector<int> a(N);
		for (int& x : a)
			cin >> x;

		multiset<int> ventana;
		int l = 0, mejor = 0;
		for (int r = 0; r < N; ++r) {
			ventana.insert(a[r]);
			while (*ventana.rbegin() - *ventana.begin() > D)
				ventana.erase(ventana.find(a[l++]));
			mejor = max(mejor, r - l + 1);
		}
		cout << mejor << '\n';
	}
	return 0;
}
