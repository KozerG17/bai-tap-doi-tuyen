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
	const ld eps = 0.01 * 0.01 * 0.01 * 0.01, pi = 3.1415926535897932384626433;
	const ll e30 = 1ll << 30; const ll e60 = 1ll << 60; const ll md = 1e9 + 83;

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
const int mod = 1000000007;

bool isPrime(ll m) {
	if (m <= 1) return false;
	for (ll i = 2; i*i <= m; i++)
		if (m % i == 0) return false;

	return true;
}

ostream& submain(int tc) {
	ll a, b; cin >> a >> b;

	bool f1 = b == a - 1;
	bool f2 = isPrime(2*a-1);
	int ok = 3*(f1 && f2);

	str s = "NO\0YES" + ok;
	return cout << s << '\n';
}

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	
	For (tc, 0, Gint) submain(tc);
}

// ------------------------------------------                    |\__/,|   (`\
// | author: dlbm1302 | created: 24.02.2022 |                  _.|o o  |_   ) )
// -----------------------------------------------------------(((---(((------------