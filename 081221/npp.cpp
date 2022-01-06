#include <bits/stdc++.h>
#ifndef LBM_LOCAL
#define debug(x...) 17
#endif

// libraries
using namespace std;
namespace {
	// macros
	#define Gint getData<ll>()
	#define Gstr getData<str>()
	#define all(a)  (a).begin(),  (a).end()
	#define rall(a) (a).rbegin(), (a).rend()
	#define For(i, u, v) for (int i = (u), _n_ = (v); i < _n_; i++)
	#define Rof(i, u, v) for (int i = (u), _n_ = (v); --i >= _n_; )

	// typedefs
	using str  = string;            using ll  = long long;
	using chr  = char;              using ld  = long double;
	using pii  = pair<int, int>;    using pll = pair<ll, ll>;
	template<class T> using MaxHeap = priority_queue<T, vector<T>, less<T>>;
	template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;
	
	// constants
	constexpr ld  pi  = acos(-1),      eps = 1e-7;
	constexpr ll  md  = 1e9 + 1617,    mod = 1e9 + 7;
	constexpr ll  e30 = 1ll << 30,     e60 = 1ll << 60;

	// functions
	int hextoint(char c) { return 9 * (c >> 6) + c & 017; }
	int isvowel(char c) { return 2130466 >> (c & 31) & 1; }
	template<class A, class B> bool Maxz(A &a, B b) { return a < b && (a = b, true); }
	template<class A, class B> bool Minz(A &a, B b) { return b < a && (a = b, true); }
	template<class T> static T getData() { T x; return cin >> x, x; }
} // main template



/* -----------------[ MAIN CODE GOES HERE ]----------------- */
const short luv = 17 * 83;
const int N = 1e5 + 5;
const int LOG = 19;

#define fi first
#define se second

int n, m, k, d[N];
vector<pii> adj[N];

struct Edge {
	int u, v, w;
	Edge(int u, int v, int w)
	: u(u), v(v), w(w) {}
};
vector<Edge> edge;

int root[N];
int getRoot(int u) {
	if (u != root[u])
		root[u] = getRoot(root[u]);
	return root[u];
}
bool join(int u, int v) {
	u = getRoot(u); v = getRoot(v);
	if (u == v) return false;
	return root[v] = u, true;
}

int t_count = 0;
int t_in[N], t_out[N];
pii par[N][LOG];
void dfs(int u) {
	t_in[u] = ++t_count;
	for (auto [v, dv] : adj[u]) {
		if (v == par[u][0].fi) continue;
		par[v][0] = pair(u, dv); dfs(v);
	}
	t_out[u] = ++t_count;
}

bool isAncestor(int u, int v) {
	return t_in[u] <= t_in[v] && t_out[v] <= t_out[u];
}
int query(int u, int v) {
	int ans = e30;

	if (!isAncestor(u, v)) {
		Rof (k, LOG, 1) {
			auto x = par[u][k];
			if (x.fi == 0) continue;
			if (isAncestor(x.fi, v)) continue;
			ans = min(ans, x.se); u = x.fi;
		}
		ans = min(ans, par[u][0].se);
		u = par[u][0].fi;
	}

	if (v != u) {
		Rof (k, LOG, 1) {
			auto x = par[v][k];
			if (x.fi == 0) continue;
			if (isAncestor(x.fi, u)) continue;
			ans = min(ans, x.se); v = x.fi;
		}
		ans = min(ans, par[v][0].se);
	}

	return ans;
}

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);

	for (cin >> n >> m; m--; ) {
		int u, v, c; cin >> u >> v >> c;
		adj[u].emplace_back(v, c);
		adj[v].emplace_back(u, c);
	}

	MinHeap<pii> pq;
	fill(d + 1, d + n + 1, e30);
	for (cin >> k; k--; ) {
		int x; cin >> x;
		pq.emplace(d[x] = 0, x);
	}
	while (!pq.empty()) {
		auto [du, u] = pq.top(); pq.pop();
		if (du != d[u]) continue;
		for (auto [v, dv] : adj[u]) {
			if (du + dv >= d[v]) continue;
			pq.emplace(d[v] = du + dv, v);
		}
	}

	For (u, 1, n + 1) {
		for (auto [v, dv] : adj[u]) {
			Edge now(u, v, min(d[u], d[v]));
			edge.emplace_back(now);
		} adj[u].clear();
	}
	sort(all(edge), [](Edge u, Edge v) {
		return u.w > v.w;
	});

	iota(root + 1, root + n + 1, 1);
	for (auto &[u, v, w] : edge) {
		if (!join(u, v)) continue;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}

	dfs(1); // root = 1
	For (k, 1, LOG) For (i, 1, n + 1) {
		auto j = par[i][k - 1];
		par[i][k].fi = par[j.fi][k - 1].fi;
		par[i][k].se = par[i][k - 1].se;
		Minz(par[i][k].se, par[j.fi][k - 1].se);
	}

	int q; cin >> q;
	while (q--) {
		int l, r; cin >> l >> r;
		if (d[l] != 0 && d[r] != 0)
		cout << query(l, r) << '\n';
		else cout << 0 << '\n';
	}
}

















// ------------------------------------------                    |\__/,|   (`\
// | author: dlbm1302 | created: 08.12.2021 |                  _.|o o  |_   ) )
// -----------------------------------------------------------(((---(((------------