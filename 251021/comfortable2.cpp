/**
 *    author:  Dao Le Bao Minh
 *    created: 25.10.2021 08:38:14  
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
int n, ans = 0;
char grid[3015][3015];
const int OFFSET = 1005;

int hx[] = {-1, +1, 0, 0};
int hy[] = {0, 0, -1, +1};
int count(int x, int y) {
	int res = 0;
	For (h, 0, 4) {
		int nx = x + hx[h], ny = y + hy[h];
		res += grid[nx][ny] != '.';
	}
	return res;
}
pii next(int x, int y) {
	For (h, 0, 4) {
		int nx = x + hx[h], ny = y + hy[h];
		if (grid[nx][ny] != '.') continue;
		return pair(nx, ny);
	}
	return pair(-1, -1);
}
void dfs(int x, int y) {
	if (count(x, y) == 3) {
		auto [nx, ny] = next(x, y);
		grid[nx][ny] = 'O';
		ans++; dfs(nx, ny);
		debug(nx - OFFSET, ny - OFFSET);
	}
	For (h, 0, 4) {
		int nx = x + hx[h], ny = y + hy[h];
		if (grid[nx][ny] == '.') continue;
		if (count(nx, ny) == 3) dfs(nx, ny);
	}
}

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	freopen("comfortable2.INP", "r", stdin);
	freopen("comfortable2.OUT", "w", stdout);
	
	cin >> n;
	memset(grid, '.', sizeof(grid));
	For (i, 0, n) {
		int x, y; cin >> x >> y;
		x += OFFSET, y += OFFSET;

		if (grid[x][y] == 'O') {
			grid[x][y] = 'X'; ans--;
		} else {
			grid[x][y] = 'X'; dfs(x, y);
		}
		cout << ans << '\n';
	}
}