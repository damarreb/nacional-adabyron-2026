#include <bits/stdc++.h>
using namespace std;

// Problema interactivo. Reconstruimos el diccionario a base de consultas
// "? pre", a las que el juez responde con las hasta K palabras
// lexicograficamente menores que empiezan por "pre".
//
// collect(p) recopila TODAS las palabras con prefijo p:
//   - Consultamos p. Si el juez devuelve menos de K palabras, esas son todas
//     las que empiezan por p (no hay mas ocultas) y terminamos.
//   - Si devuelve exactamente K, tenemos las K menores; sea last la mayor.
//     Todas las palabras <= last con prefijo p son justo esas K. Las que
//     faltan son las > last, y se parten en dos grupos disjuntos:
//       (1) continuaciones de last  -> collect(last)
//       (2) palabras que se desvian de last en alguna posicion j >= |p| con
//           una letra mayor -> collect(last[0..j-1] + c) para cada c > last[j]
//
// Como cada llamada recursiva usa un prefijo estrictamente mas largo, la
// recursion termina (profundidad acotada por L).

int K, L;
set<string> dic;

vector<string> consulta(const string& pre)
{
	if (pre.empty())
		cout << "?\n";
	else
		cout << "? " << pre << '\n';
	cout.flush();

	int m;
	if (!(cin >> m) || m == -1)
		exit(0); // el juez aborto (demasiadas consultas): salimos limpiamente
	vector<string> res(m);
	for (int i = 0; i < m; ++i)
		cin >> res[i];
	return res;
}

void collect(const string& p)
{
	vector<string> s = consulta(p);
	for (const string& w : s)
		dic.insert(w);
	if ((int)s.size() < K)
		return;

	const string last = s.back();
	collect(last); // (1) continuaciones de last
	// (2) desvios: en cada posicion j de last, letras mayores que last[j]
	for (int j = (int)last.size() - 1; j >= (int)p.size(); --j)
		for (char c = last[j] + 1; c <= 'z'; ++c)
			collect(last.substr(0, j) + c);
}

int main()
{
	int T;
	if (!(cin >> T))
		return 0;
	while (T--) {
		cin >> K >> L;
		dic.clear();
		collect("");
		cout << "! " << dic.size() << '\n';
		for (const string& w : dic)
			cout << w << '\n';
		cout.flush();
	}
	return 0;
}
