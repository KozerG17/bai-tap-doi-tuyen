// C++ Template Code is tested for compability with: C++11 or above
// Repo: https://github.com/KozerG17/ST4-Snippets/blob/main/cpp.cpp

#ifdef LBM_LOCAL
#include <local.h>
#else
#include <bits/stdc++.h>
#define debug(x...) 17
#endif

// libraries
using namespace std;
namespace std {
	// macros
	#define fi first
	#define se second
	#define all(a)  (a).begin(),  (a).end()
	#define rall(a) (a).rbegin(), (a).rend()
	#define For(i, u, v) for (int i = (u), _n_ = (v); i < _n_; i++)
	#define Rof(i, u, v) for (int i = (u), _n_ = (v); --i >= _n_; )

	// typedefs
	using ll   = long long;         using chr = char;
	using dbl  = long double;       using str = string;
	using pint = pair<int, int>;    using pll = pair<ll, ll>;
	using uint = unsigned int;      using ull = unsigned long long;
	template<class T> using MaxHeap = priority_queue<T, vector<T>, less<T>>;
	template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;

	// functions
	template<class A, class B> bool Maxz(A &a, B b) { return a < b && (a = b, true); }
	template<class A, class B> bool Minz(A &a, B b) { return b < a && (a = b, true); }
	mt19937_64 Rng(chrono::steady_clock::now().time_since_epoch().count());
	ll Rand(ll a, ll b) { return uniform_int_distribution<ll>(a, b)(Rng); }

	// constants
	constexpr ll  e30 = 1ll << 30,  e60 = 1ll << 60;
	constexpr dbl pi  = acos(-1),   eps = 1e-7;
	constexpr ll  md  = 1e9 + 7,    _md = 1e9 + 1617;

	// devices
	class Reader {
	public:
		template<class T> static T getData() {
			T x; return cin >> x, x;
		} template<class T> Reader &operator,(T &x) {
			return ok &= !!(cin >> x), *this;
		} bool ok = true; operator bool() { return ok; }
	private:
		#define Read Reader(),
		#define Gint Reader::getData<ll>()
		#define Gstr Reader::getData<str>()
	};
} // custom standard namespace



/* -----------------[ MAIN CODE GOES HERE ]----------------- */
const short luv = 17 * 83;

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	freopen("cowroute2.INP", "r", stdin);
	freopen("cowroute2.OUT", "w", stdout);
	
	int a, b; Read a, b;

	const int N = 1e3 + 5;
	static pll edge[N][N];
	For (i, 0, N)
		For (j, 0, N) {
			edge[i][j] = pair(e60, e60);
		}

	For (nTest, 0, Gint) {
		ll c = Gint;
		vector<int> p;
		For (i, 0, Gint) {
			ll x = Gint;
			For (j, 0, i)
				Minz(edge[p[j]][x], pair(c, ll(i - j)));
			p.push_back(x);
		}
	}

	MinHeap<tuple<int, int, int>> pq;
	vector<ll> d(N, e60), c(N, 0);
	pq.emplace(d[a] = 0, c[a] = 0, a);
	while (!pq.empty()) {
		ll u, uc, ud;
		tie(ud, uc, u) = pq.top();
		pq.pop();
		debug(u, uc, ud, d[u], c[u]);
		if (ud != d[u] || uc != c[u]) continue;

		For (v, 1, N) {
			if (v <= 10) debug(v, ud + edge[u][v].fi, uc + edge[u][v].se, d[v], c[v]);
			if (pair(ud + edge[u][v].fi, uc + edge[u][v].se) < pair(d[v], c[v]))
				pq.emplace(d[v] = ud + edge[u][v].fi, c[v] = uc + edge[u][v].se, u);
		}
	}

	if (d[b] == e60) cout << -1;
	else cout << d[b] << ' ' << c[b];
}

















// ------------------------------------------                    |\__/,|   (`\
// | author: dlbm1302 | created: 22.09.2021 |                  _.|o o  |_   ) )
// -----------------------------------------------------------(((---(((------------