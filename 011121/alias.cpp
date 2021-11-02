/**
 *    author:  Dao Le Bao Minh
 *    created: 01.11.2021 09:03:09  
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
ll Hash(str s) {
	ll ans = 0;
	for (char &c : s) {
		ans = ans*10 + c - 'a' + 1;
		while (ans > mod) ans -= mod;
	}
	return ans;
}

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	
	int n, m; cin >> n >> m;
	map<ll, vector<pll>> adj;
	while (m--) {
		str a, b; int t; cin >> a >> b >> t;
		adj[Hash(a)].emplace_back(t, Hash(b));
	}

	int tc; cin >> tc;
	while (tc--) {
		str s, t; cin >> s >> t;

		map<ll, ll> d;
		priority_queue<pll,
		vector<pll>, greater<pll>> pq;
		pq.emplace(d[Hash(s)] = 0, Hash(s));
		while (!pq.empty()) {
			auto [du, u] = pq.top();
			if (pq.pop(); du != d[u]) break;
			for (auto [dv, v] : adj[u])
				if (d.count(v) == 0 || d[v] > du + dv) {
					pq.emplace(d[v] = du + dv, v);
				}
		}
		if (!d.count(Hash(t))) cout << "Roger\n";
		else cout << d[Hash(t)] << '\n';
	}
}