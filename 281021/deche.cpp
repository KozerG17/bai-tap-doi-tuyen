/**
 *    author:  Dao Le Bao Minh
 *    created: 28.10.2021 08:09:19  
**/

#include <bits/stdc++.h>
#ifndef LBM_LOCAL
#define debug(x...) 17
#endif

// /* 
#define fi first
#define se second
// */

#define all(a)  (a).begin(),  (a).end()
#define For(i, a, b) for (int i = a; i < b; i++)
#define Rof(i, a, b) for (int i = a; --i >= b; )

using namespace std;           using ll  = long long;
using str = string;            using ld  = long double;
using pii = pair<int, int>;    using pll = pair<ll, ll>;

const ll mod = 1e9 + 7,        luv = 18 * 13;
const ll e30 = 1ll << 30,      e60 = 1ll << 60;



/* -----------------[ MAIN CODE GOES HERE ]----------------- */
const int N = 1e5 + 5;

int n;
pii x[N], y[N], z[N];

struct Edge {
	int u, v, w;
	Edge(int u, int v, int w)
	: u(u), v(v), w(w) {}
};
vector<Edge> edge;

int par[N];
int getPar(int u) {
	if (par[u] != u)
		par[u] = getPar(par[u]);
	return par[u];
}
bool join(int u, int v) {
	u = getPar(u), v = getPar(v);
	if (u == v) return false;
	return par[v] = u, true;
}

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	// freopen("deche.INP", "r", stdin);
	// freopen("deche.OUT", "w", stdout);
	
	cin >> n;
	For (i, 0, n) {
		cin >> x[i].fi >> y[i].fi >> z[i].fi;
		x[i].se = y[i].se = z[i].se = i;
	}

	sort(x, x + n); sort(y, y + n); sort(z, z + n);
	For (i, 1, n) {
		edge.emplace_back(x[i-1].se, x[i].se, x[i].fi - x[i-1].fi);
		edge.emplace_back(y[i-1].se, y[i].se, y[i].fi - y[i-1].fi);
		edge.emplace_back(z[i-1].se, z[i].se, z[i].fi - z[i-1].fi);
	}
	sort(all(edge), [](Edge &u, Edge &v) { return u.w < v.w; });

	ll ans = 0;
	iota(par, par + n, 0);
	for (Edge &x : edge) {
		if (join(x.u, x.v))
			ans += x.w;
	}
	cout << ans;
}