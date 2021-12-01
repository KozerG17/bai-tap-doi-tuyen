/**
 *    author:  Dao Le Bao Minh
 *    created: 01.12.2021 08:21:42  
**/

#include <bits/stdc++.h>
#ifndef LBM_LOCAL
#define debug(x...) 17
#endif

// /* 
#define fi first
#define se second
// */

#define all(a)  (a).begin(),  (a).end()
#define For(i, a, b) for (int i = a; i < b; i++)
#define Rof(i, a, b) for (int i = a; --i >= b; )

using namespace std;           using ll  = long long;
using str = string;            using ld  = long double;
using pii = pair<int, int>;    using pll = pair<ll, ll>;

const ll mod = 1e9 + 7,        luv = 18 * 13;
const ll e30 = 1ll << 30,      e60 = 1ll << 60;



/* -----------------[ MAIN CODE GOES HERE ]----------------- */
const int N = 5e5;

int n, a[N];

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	
	cin >> n;
	For (i, 0, n) cin >> a[i];

	deque<int> dq;
	Rof (i, sqrt(n) + 1, 1)
		if (n % i == 0) {
			dq.push_front(i);
			if (i*i != n)
				dq.push_back(n/i);
		}

	for (int i : dq) {
		cout << i << ' ';

		int ans = n; set<int> st;
		for (int j = 0; j < n; j++) {
			st.insert(a[j]);
			if ((j+1)%i == 0) {
				ans = min(ans, (int)st.size());
				st.clear();
			}
		}
		cout << ans << '\n';
	}
}