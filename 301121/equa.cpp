/**
 *    author:  Dao Le Bao Minh
 *    created: 30.11.2021 08:55:48  
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
const ld eps = 1e-7;
vector<ld> no;
vector<bool> mark;

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	
	int tc; cin >> tc;
	while (tc--) {
		ld a, b, c; cin >> a >> b >> c;
		if (abs(a) > eps) {
			ld delta = b*b - 4*a*c;
			if (delta < -eps) continue;
			no.push_back((-b-sqrt(delta))/2/a);
			no.push_back((-b+sqrt(delta))/2/a);
		} else if (abs(b) > eps) {
			no.push_back(-c/b);
		} else if (abs(c) > eps) {
			continue;
		} else return cout << -1, 0;
	}

	int n = no.size();
	mark.resize(n, true);
	For (i, 0, n) {
		if (!mark[i]) continue;
		For (j, i+1, n)
			if (abs(no[i] - no[j]) < eps) {
				mark[j] = false;
			}
	}

	cout << count(all(mark), true);
}