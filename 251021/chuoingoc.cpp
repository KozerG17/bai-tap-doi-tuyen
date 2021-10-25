/**
 *    author:  Dao Le Bao Minh
 *    created: 25.10.2021 08:04:00  
**/

#include <bits/stdc++.h>
#ifndef LBM_LOCAL
#define debug(x...) 17
#endif

#define all(a)  (a).begin(),  (a).end()
#define For(i, a, b) for (int i = a; i < b; i++)
#define Rof(i, a, b) for (int i = a; --i >= b; )

using namespace std;           using ll  = long long;
using str = string;            using ld  = long double;
using pii = pair<int, int>;    using pll = pair<ll, ll>;

const ll mod = 1e9 + 7;
const ll e30 = 1ll << 30;
const ll e60 = 1ll << 60;



/* -----------------[ MAIN CODE GOES HERE ]----------------- */
const int N = 1e4 + 5;

int n; char s[N];
int Hash[N], base[N];

unordered_set<int> st;
bool check(int k) {
	st.clear();
	For (i, k, n + 1) {
		int crr = (1ll * Hash[i] - 1ll * Hash[i - k] * base[k] % mod + mod) % mod;
		if (st.count(crr) != 0) return true;
		st.insert(crr);
	}
	return false;
}

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	freopen("chuoingoc.INP", "r", stdin);
	freopen("chuoingoc.OUT", "w", stdout);
	
	cin >> n >> s + 1; base[0] = 1;
	For (i, 1, n + 1) {
		base[i] = 37ll * base[i - 1] % mod;
		Hash[i] = (37ll * Hash[i - 1] + s[i] - 'a' + 1) % mod;
	}

	int low = 1, high = n - 1;
	while (low <= high) {
		int mid = (low + high)/2;
		if (check(mid))
			low = mid + 1;
		else
			high = mid - 1;
	}
	cout << low;
}