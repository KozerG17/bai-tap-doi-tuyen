/**
 *    author:  Dao Le Bao Minh
 *    created: 29.10.2021 08:45:51  
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
int n, index;
string s;

string t, ans;
void quaylui1(int pos, int sum) {
	if (sum < 0) return;
	int rem = n - pos;
	if (sum - rem > 0) return;
	if (pos == n && !--index)
		ans = t;
	if (index == 0) return;
	t[pos] = '('; quaylui1(pos + 1, sum + 1);
	t[pos] = ')'; quaylui1(pos + 1, sum - 1);
}

int cnt = 0, found = -1;
void quaylui2(int pos, int sum) {
	if (sum < 0) return;
	int rem = n - pos;
	if (sum - rem > 0) return;
	if (pos == n) {
		if (cnt++; t == s)
			found = cnt;
	}
	if (found != -1) return;
	t[pos] = '('; quaylui2(pos + 1, sum + 1);
	t[pos] = ')'; quaylui2(pos + 1, sum - 1);
}

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	
	cin >> n; t.resize(n);
	for (int typ; cin >> typ; ) {
		if (typ == 1) {
			cin >> index;
			quaylui1(0, 0);
			cout << ans << '\n';
		} else {
			cin >> s;
			cnt = 0; found = -1;
			quaylui2(0, 0);
			cout << found << '\n';
		}
	}
}