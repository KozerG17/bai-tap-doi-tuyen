/**
 *    author:  Dao Le Bao Minh
 *    created: 01.12.2021 07:50:16  
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
const int N = 2e5 + 5;

int n, a[N], b[N];
set<pii> sa, sb;

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	// freopen("team.INP", "r", stdin);
	// freopen("team.OUT", "w", stdout);
	
	cin >> n;
	For (i, 0, n) {
		cin >> a[i] >> b[i];
		sa.emplace(a[i], i);
		sb.emplace(b[i], i);
	}

	cout << sa.begin()->fi << '\n';

	ll sum = 0;
	while (--n) {
		auto i = sa.begin(), _i = i; _i++;
		auto j = sb.begin(), _j = j; _j++;
		if (i->se != j->se || _i->fi + j->fi <= i->fi + _j->fi) {
			sa.erase(pii(a[j->se], j->se));
			sum += j->fi; sb.erase(j);
		} else {
			sa.erase(pii(a[_j->se], _j->se));
			sum += _j->fi; sb.erase(_j);
		} cout << sum + sa.begin()->fi << '\n';
	}
}