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

ll a[2], b[2], c[2];
pll fix(ll a, ll b) { return make_pair(min(a, b), max(a, b)); }

int main() {
	freopen("rectpapers.INP", "r", stdin);
	freopen("rectpapers.OUT", "w", stdout);
	cin.tie(nullptr) -> sync_with_stdio(false);
	
	For (nTest, 0, Gint) {
		cin >> a[0] >> a[1];
		cin >> b[0] >> b[1];
		cin >> c[0] >> c[1];

		set<pll> ans;
		For (i, 0, 2) For (j, 0, 2) For (k, 0, 2) {
			if (a[i] == b[j] && a[i] == c[k])
				ans.insert(fix(a[i], a[!i] + b[!j] + c[!k]));
			if (a[i] == b[j] && a[!i] + b[!j] == c[k])
				ans.insert(fix(a[i] + c[!k], c[k]));
			if (b[j] == c[k] && b[!j] + c[!k] == a[i])
				ans.insert(fix(b[j] + a[!i], a[i]));
			if (a[i] == c[k] && a[!i] + c[!k] == b[j])
				ans.insert(fix(a[i] + b[!j], b[j]));
		}

		cout << ans.size() << '\n';
	}
}

// ------------------------------------------                    |\__/,|   (`\
// | author: dlbm1302 | created: 30.12.2021 |                  _.|o o  |_   ) )
// -----------------------------------------------------------(((---(((------------