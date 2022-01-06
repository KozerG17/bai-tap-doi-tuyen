#include <bits/stdc++.h>
#ifndef LBM_LOCAL
#define debug(x...) 17
#endif

using namespace std;
namespace {
	// macros definitions
	#define Gint Read<ll>()
	#define Gstr Read<str>()
	#define all(a)  (a).begin(),  (a).end()
	#define rall(a) (a).rbegin(), (a).rend()
	#define For(i, u, v) for (int i = (u), _n_ = (v); i < _n_; i++)
	#define Rof(i, u, v) for (int i = (u), _n_ = (v); --i >= _n_; )

	// typedefs & constants
	using chr = char;     using ll = long long;     using pll = pair<ll, ll>;
	using str = string;   using ld = long double;   using pii = pair<int, int>;
	template<class T> using MaxHeap = priority_queue<T, vector<T>,    less<T>>;
	template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;
	const ld eps = 1000000 * 0.0000000000001, pi = 3.1415926535897932384626433;
	const ll mod = 1e9 + 7, lim = 1e6 + 1411, e30 = 1ll << 30, e60 = 1ll << 60;

	// useful functions
	template<class A, class B>
	bool Maxz(A &a, B b) { return a < b && (a = b, true); }
	template<class A, class B>
	bool Minz(A &a, B b) { return b < a && (a = b, true); }
	template<class T> T Read() { T x; return cin >> x, x; }
	int hextoint(char c) { return 9 * (c >> 6) + c & 017; }
	int isvowel(char c) { return 2130466 >> (c & 31) & 1; }
} // main template



/* -----------------[ MAIN CODE GOES HERE ]----------------- */
const short luv = 17 * 83;
const int N = 1005;

int n;
vector<pii> adj[N];

int fin[N], fout[N];
void dfsIn(int u, int p) {
	for (auto [v, d] : adj[u]) {
		if (v == p) continue;
		dfsIn(v, u);
		Maxz(fin[u], fin[v] + d);
	}
}
void dfsOut(int u, int p) {
	int first = -1, second = -1;
	for (auto [v, d] : adj[u]) {
		if (v == p) continue;
		if (fin[v] + d > first)
			second = first, first = fin[v] + d;
		else Maxz(second, fin[v] + d);
	}
	for (auto [v, d] : adj[u]) {
		fout[v] = fout[u] + d;
		if (fin[v] + d != first)
			Maxz(fout[v], first + d);
		else
			Maxz(fout[v], second + d);
		dfsOut(v, u);
	}
}

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> n;
	For (i, 0, n - 1) {
		int u, v, p, q;
		cin >> u >> v >> p >> q;
		adj[u].emplace_back(v, q-p);
		adj[v].emplace_back(u, q-p);
	}

	dfsIn(1, 1); dfsOut(1, 1);
	For (i, 1, n + 1) debug(i, fin[i], fout[i]);
}

// ------------------------------------------                    |\__/,|   (`\
// | author: dlbm1302 | created: 05.01.2022 |                  _.|o o  |_   ) )
// -----------------------------------------------------------(((---(((------------