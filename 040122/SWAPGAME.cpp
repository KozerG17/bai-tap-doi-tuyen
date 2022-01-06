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
const int N = 1e5 + 5;

int n, a[N][2];

pii prv[N], nxt[N][2];
void add(int i, int k, int v) {
	a[i][k] = v;
	if (prv[v].first == 0)
		prv[v] = pii(i, k);
	else {
		auto [f, s] = prv[v];
		nxt[i][k] = prv[v];
		nxt[f][s] = pii(i, k);
	}
}

bool mark[N];

int main() {
	cin >> n;
	For (i, 1, n + 1) add(i, 0, Gint);
	For (i, 1, n + 1) add(i, 1, Gint);
 
	ll ans = 1, _min = 0;
	fill(mark, mark + n + 1, 0);

	For (i, 1, n + 1) {
		if (mark[i]) continue;

		int j = i, k = 0, ex = 0;
		int cnt = 0, err = 0;

		while (!mark[j]) {
			err += k == 1;
			mark[j] = true;
			tie(j, k) = nxt[j][k];
			cnt++; k ^= 1;
		}

		ans *= 2;
		_min += min(err, cnt - err);
	}

	cout << ans << ' ' << _min << '\n';
}

// ------------------------------------------                    |\__/,|   (`\
// | author: dlbm1302 | created: 04.01.2022 |                  _.|o o  |_   ) )
// -----------------------------------------------------------(((---(((------------