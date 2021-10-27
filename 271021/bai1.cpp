/**
 *    author:  Dao Le Bao Minh
 *    created: 27.10.2021 08:48:23  
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
const int N = 21;

ll n, p[N], index;
ll f[N];

namespace task1 {
	void main() {
		ll ans = 1;
		Rof (i, n, 0) {
			For (j, i + 1, n) {
				if (p[i] < p[j]) continue;
				ans += f[n - i - 1];
			}
		}
		cout << ans << '\n';
	}
} // namespace task1

namespace task2 {
	bool visited[N];
	void main() {
		For (i, 0, n) {
			For (j, 1, n + 1) {
				if (visited[j]) continue;
				if (index >= f[n - i - 1])
					index -= f[n - i - 1];
				else { 
					visited[j] = true;
					cout << j << ' '; break;
				}
			}
		}
	}
} // namespace task2

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	
	cin >> n;
	For (i, 0, n) cin >> p[i];
	cin >> index; index--;

	f[0] = f[1] = 1;
	For (i, 1, n + 1)
		f[i] = f[i - 1] * i;

	task1::main();
	task2::main();
}