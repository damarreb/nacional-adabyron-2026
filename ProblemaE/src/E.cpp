#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// El estado relevante del pulpo es el PAR de agarres que sujetan los dos
// tentaculos que no se mueven: la zona valida del cuerpo (interseccion de los
// dos discos de radio L) es convexa, asi que el cuerpo puede deslizarse entre
// posiciones validas sin soltar nada y no hace falta rastrearlo. Desde el par
// {B,C} se puede agarrar D si los discos de radio L de B, C y D tienen un
// punto comun; el pulpo pasa a disponer de los pares {B,D} y {C,D}. Un BFS
// sobre pares recorre todo lo alcanzable con movimientos ordinarios.
//
// El estiramiento (una sola vez) parte la busqueda en dos fases: desde
// cualquier par {B,C} de la fase inicial se llega a E si los discos (B,L),
// (C,L) y (E,2L) comparten un punto. Despues el pulpo cuelga de E y se
// reengancha a un F con dist(E,F) <= 2L (necesario y suficiente para acabar
// con ambos tentaculos a longitud <= L), quedando en el par {E,F}, semilla
// de la segunda fase.
//
// La meta se toca al agarrarla en un movimiento ordinario, al ser el destino
// E del estiramiento o al ser el agarre F del reenganche.
//
// Geometria: tres discos cerrados tienen un punto comun si y solo si algun
// centro esta dentro de los otros dos discos, o algun punto de corte de dos
// de las circunferencias cae dentro del tercer disco. Los prechequeos y el
// discriminante son enteros exactos; solo la comprobacion de esos puntos de
// corte usa coma flotante, con error muy por debajo del margen EPS.

int N;
ll L;
vector<ll> X, Y;

ll dist2(int a, int b)
{
	ll dx = X[a] - X[b], dy = Y[a] - Y[b];
	return dx * dx + dy * dy;
}

bool discosSeCortan(int a, ll ra, int b, ll rb)
{
	return dist2(a, b) <= (ra + rb) * (ra + rb);
}

bool agarreEnDisco(int p, int c, ll r)
{
	return dist2(p, c) <= r * r;
}

// ¿Algun punto de corte de las circunferencias (a,ra) y (b,rb) cae dentro
// del disco (c,rc)? Unica comprobacion no exacta de toda la solucion.
bool esquinasEnDisco(int a, ll ra, int b, ll rb, int c, ll rc)
{
	const double EPS = 1e-4;
	ll d2 = dist2(a, b);
	ll ap = d2 + ra * ra - rb * rb;
	ll disc = 4 * ra * ra * d2 - ap * ap; // discriminante, exacto en enteros
	if (disc < 0)
		return false; // las circunferencias no llegan a cortarse
	double inv = 0.5 / d2;
	double vx = X[b] - X[a], vy = Y[b] - Y[a];
	double px = X[a] + ap * inv * vx, py = Y[a] + ap * inv * vy;
	double h = sqrt((double)disc) * inv;
	for (int signo : {-1, 1}) {
		double qx = px - signo * h * vy - X[c];
		double qy = py + signo * h * vx - Y[c];
		if (qx * qx + qy * qy <= (double)(rc * rc) + EPS)
			return true;
	}
	return false;
}

// ¿Existe una posicion del cuerpo compatible con sujetar a la vez los agarres
// a, b y c con tentaculos de alcance ra, rb y rc? Es decir, ¿tienen los tres
// discos algun punto en comun?
bool posicionComun(int a, ll ra, int b, ll rb, int c, ll rc)
{
	if (!discosSeCortan(a, ra, b, rb) || !discosSeCortan(a, ra, c, rc) ||
	    !discosSeCortan(b, rb, c, rc))
		return false;
	if (agarreEnDisco(a, b, rb) && agarreEnDisco(a, c, rc))
		return true;
	if (agarreEnDisco(b, a, ra) && agarreEnDisco(b, c, rc))
		return true;
	if (agarreEnDisco(c, a, ra) && agarreEnDisco(c, b, rb))
		return true;
	return esquinasEnDisco(a, ra, b, rb, c, rc) ||
	       esquinasEnDisco(a, ra, c, rc, b, rb) ||
	       esquinasEnDisco(b, rb, c, rc, a, ra);
}

bool resolver()
{
	cin >> N >> L;
	X.assign(N, 0);
	Y.assign(N, 0);
	for (int i = 0; i < N; ++i)
		cin >> X[i] >> Y[i];
	const int meta = N - 1;

	vector<char> visitado(N * N, 0);
	vector<pair<int, int>> pendientes;
	auto descubre = [&](int a, int b) {
		if (a > b)
			swap(a, b);
		if (!visitado[a * N + b]) {
			visitado[a * N + b] = 1;
			pendientes.push_back({a, b});
		}
	};

	// Expande pares con movimientos ordinarios; true si llega a agarrar la meta.
	auto expandir = [&]() -> bool {
		while (!pendientes.empty()) {
			auto [b, c] = pendientes.back();
			pendientes.pop_back();
			for (int d = 0; d < N; ++d) {
				if (d == b || d == c || !posicionComun(b, L, c, L, d, L))
					continue;
				if (d == meta)
					return true;
				descubre(b, d);
				descubre(c, d);
			}
		}
		return false;
	};

	// Fase inicial: movimientos ordinarios desde los tres pares de partida.
	descubre(0, 1);
	descubre(0, 2);
	descubre(1, 2);
	if (expandir())
		return true;

	// Estiramiento: desde cualquier par visitado, alcanzar E con el disco 2L.
	vector<char> estirable(N, 0);
	for (int b = 0; b < N; ++b)
		for (int c = b + 1; c < N; ++c) {
			if (!visitado[b * N + c])
				continue;
			for (int e = 0; e < N; ++e) {
				if (e == b || e == c || estirable[e])
					continue;
				if (posicionComun(b, L, c, L, e, 2 * L)) {
					if (e == meta)
						return true; // toca la meta durante el estiramiento
					estirable[e] = 1;
				}
			}
		}

	// Reenganche: colgando de E, agarra F y recoge el tentaculo estirado.
	for (int e = 0; e < N; ++e) {
		if (!estirable[e])
			continue;
		if (dist2(e, meta) <= 4 * L * L)
			return true; // se reengancha directamente en la meta
		for (int f = 0; f < N; ++f)
			if (f != e && dist2(e, f) <= 4 * L * L)
				descubre(e, f);
	}

	// Segunda fase: movimientos ordinarios tras el estiramiento. Los pares ya
	// visitados antes no se reexploran: no aportan nada nuevo.
	return expandir();
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int T;
	if (!(cin >> T))
		return 0;
	while (T--)
		cout << (resolver() ? "SI" : "NO") << '\n';
	return 0;
}
