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
const int N = 2e5 + 5;

ll n, a[N], dp[N][2];
vector<int> adj[N];

void dfs(int u) {
	dp[u][1] = a[u];
	for (int v : adj[u]) {
		dfs(v); dp[u][1] += dp[v][0];
		dp[u][0] += max(dp[v][0], dp[v][1]);
	}
}

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	
	cin >> n;
	For (i, 1, n + 1) cin >> a[i];
	For (i, 1, n + 1) {
		int p = Gint;
		if (p) adj[p].push_back(i);
	}

	dfs(1);
	cout << max(dp[1][0], dp[1][1]);
}

// ------------------------------------------                    |\__/,|   (`\
// | author: dlbm1302 | created: 19.01.2022 |                  _.|o o  |_   ) )
// -----------------------------------------------------------(((---(((------------