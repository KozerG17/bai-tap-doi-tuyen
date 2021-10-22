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
	freopen("stock.INP", "r", stdin);
	freopen("stock.OUT", "w", stdout);
	
	For (nTest, 0, Gint) {
		int n = Gint;

		vector<ll> a(n);
		for (ll &x : a) Read x;

		ll ans = 0, mx = 0;
		Rof (i, n, 0) {
			Maxz(mx, a[i]);
			ans += mx - a[i];
		}

		cout << ans << '\n';
	}
}

















// ------------------------------------------                    |\__/,|   (`\
// | author: dlbm1302 | created: 22.09.2021 |                  _.|o o  |_   ) )
// -----------------------------------------------------------(((---(((------------