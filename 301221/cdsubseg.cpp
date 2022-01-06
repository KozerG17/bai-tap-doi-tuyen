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
const int N = 1e6 + 5;

int n, tree[2*N];

int getgcd(int l, int r) {
	int ans = 0;
	for (l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
		if (l&1) ans = __gcd(ans, tree[l++]);
		if (r&1) ans = __gcd(ans, tree[--r]);
	}
	return ans;
}

int main() {
	freopen("cdsubseg.INP", "r", stdin);
	freopen("cdsubseg.OUT", "w", stdout);
	cin.tie(nullptr) -> sync_with_stdio(false);
	
	For (nTest, 0, Gint) {
		cin >> n;
		For (i, 0, n) tree[i+n] = abs(Gint);
		Rof (i, n, 1) tree[i] = __gcd(tree[i << 1], tree[i << 1 | 1]);

		ll ans = 0;
		For (i, 0, n) {
			if (tree[i+n] == 1) continue;

			int lo = i, hi = n - 1;
			while (lo <= hi) {
				int mid = (lo + hi)/2;
				if (getgcd(i, mid) != 1)
					lo = mid + 1;
				else
					hi = mid - 1;
			}

			Maxz(ans, hi - i + 1);
		}

		cout << ans << '\n';
	}
}

// ------------------------------------------                    |\__/,|   (`\
// | author: dlbm1302 | created: 30.12.2021 |                  _.|o o  |_   ) )
// -----------------------------------------------------------(((---(((------------