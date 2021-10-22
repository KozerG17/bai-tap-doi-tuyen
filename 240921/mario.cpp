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
namespace {
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
const int N = 1e6 + 5;
vector<pll> adj[N];

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	freopen("mario.INP", "r", stdin);
	freopen("mario.OUT", "w", stdout);
	
	int n, m; Read n, m;

	For (i, 0, n)
		For (j, 0, m - 1) {
			int u = i*m + j;
			int v = i*m + j + 1;
			int c = Gint;
			adj[u].emplace_back(v, c);
			adj[v].emplace_back(u, c);
		}
	For (i, 0, n - 1)
		For (j, 0, m) {
			int u = i*m + j;
			int v = (i + 1)*m + j;
			int c = Gint;
			adj[u].emplace_back(v, c);
			adj[v].emplace_back(u, c);
		}

	MinHeap<pll> pq;
	vector<ll> cost(N, e60);
	pq.emplace(cost[0] = 0, 0);
	while (!pq.empty()) {
		int u, uLen;
		tie(uLen, u) = pq.top();
		pq.pop();
		if (uLen != cost[u]) continue;

		for (pll i : adj[u])
			if (uLen + i.se < cost[i.fi]) {
				cost[i.fi] = uLen + i.se;
				pq.emplace(cost[i.fi], i.fi);
			}
	}

	cout << cost[n*m - 1];
}

















// ------------------------------------------                    |\__/,|   (`\
// | author: dlbm1302 | created: 24.09.2021 |                  _.|o o  |_   ) )
// -----------------------------------------------------------(((---(((------------