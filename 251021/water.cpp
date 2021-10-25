/**
 *    author:  Dao Le Bao Minh
 *    created: 25.10.2021 07:45:01  
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
const int N = 1e6 + 5;

ll n, a[N], pf[N], sf[N];

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);

	cin >> n;
	For (i, 1, n + 1) {
		cin >> a[i];
		pf[i] = max(pf[i - 1], a[i]);
	}

	ll ans = 0;
	Rof (i, n + 1, 1) {
		ll h = min(pf[i - 1], sf[i + 1]);
		ans += max(0ll, h - a[i]);
		sf[i] = max(sf[i + 1], a[i]);
	}

	ll res = 0;
	stack<int> st;
	For (i, 1, n + 1) {
		if (a[i] != sf[i]) continue;
		while (!st.empty() && a[st.top()] <= a[i])
			st.pop();
		if (!st.empty()) res = max(res, 0ll + i - st.top() - 1);
		st.push(i);
	}

	while (!st.empty()) st.pop();
	Rof (i, n + 1, 1) {
		if (a[i] != pf[i]) continue;
		while (!st.empty() && a[i] >= a[st.top()])
			st.pop();
		if (!st.empty()) res = max(res, 0ll + st.top() - i - 1);
		st.push(i);
	}

	cout << ans + res;
}