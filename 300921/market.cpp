// C++ Template Code is tested for compability with: C++11 or above
// Repo: https://github.com/KozerG17/ST4-Snippets/blob/main/cpp.cpp

#include <bits/stdc++.h>
#ifndef LBM_LOCAL
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
	using str  = string;            using ll  = long long;
	using chr  = char;              using ld  = long double;
	using pii  = pair<int, int>;    using pll = pair<ll, ll>;
	using uint = unsigned int;      using ull = unsigned long long;
	template<class T> using MaxHeap = priority_queue<T, vector<T>, less<T>>;
	template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;

	// functions
	template<class A, class B> bool Maxz(A &a, B b) { return a < b && (a = b, true); }
	template<class A, class B> bool Minz(A &a, B b) { return b < a && (a = b, true); }
	mt19937_64 Rng(chrono::steady_clock::now().time_since_epoch().count());
	ll Rand(ll a, ll b) { return uniform_int_distribution<ll>(a, b)(Rng); }

	// constants
	constexpr ld  pi  = acos(-1),   eps = 1e-7;
	constexpr ll  e30 = 1ll << 30,  e60 = 1ll << 60;
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
	freopen("market.INP", "r", stdin);
	freopen("market.OUT", "w", stdout);
	
	int n, m; Read n, m;

	vector<ll> a(n + 1), b(m + 1);
	For (i, 1, n + 1) Read a[i];
	For (i, 1, m + 1) Read b[i];

	Rof (i, m, 1)
		Minz(b[i], b[i + 1]);
	sort(all(a));

	vector<ll> dp(n + 1, e30); dp[0] = 0;
	For (i, 1, n + 1)
		For (k, 1, i + 1) {
			int len = a[i] - a[i - k + 1] + 1;
			Minz(dp[i], dp[i - k] + b[len]);
		}
	cout << dp[n];
}
















// ------------------------------------------                    |\__/,|   (`\
// | author: dlbm1302 | created: 30.09.2021 |                  _.|o o  |_   ) )
// -----------------------------------------------------------(((---(((------------