/**
 *    author:  Dao Le Bao Minh
 *    created: 26.10.2021 07:44:13  
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

const ll mod = 1e9 + 7,        luv = 18 * 13;
const ll e30 = 1ll << 30,      e60 = 1ll << 60;



/* -----------------[ MAIN CODE GOES HERE ]----------------- */
const int N = 1e3 + 5;

ll n, x[N], y[N];

bool visited[N];
bool check(ll maxDist) {
	memset(visited, 0, sizeof(visited));
	queue<int> q; q.push(0); visited[0] = true;
	while (!q.empty()) {
		int i = q.front(); q.pop();
		For (j, 0, n) {
			if (visited[j]) continue;
			ll dx = abs(x[i] - x[j]);
			ll dy = abs(y[i] - y[j]);
			if (dx*dx + dy*dy <= maxDist) {
				q.push(j); visited[j] = true;
			}
		}
	}
	For (i, 0, n) if (!visited[i]) return false;
	return true;
}

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	freopen("angten.INP", "r", stdin);
	freopen("angten.OUT", "w", stdout);
	
	cin >> n;
	For (i, 0, n) cin >> x[i] >> y[i];

	ll low = 0, high = 2*e60;
	while (low <= high) {
		ll mid = (low + high)/2;
		if (check(mid))
			high = mid - 1;
		else
			low = mid + 1;
	}
	cout << sqrt(low) / 2;
}