/**
 *    author:  dlbm1302
 *    created: 14.10.2021 07:21:51       
**/

#include <bits/stdc++.h>
#ifndef LBM_LOCAL
#define debug(x...) 17
#endif

using namespace std;

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
    freopen("catbanh.INP", "r", stdin);
    freopen("catbanh.OUT", "w", stdout);

    int n, k; cin >> n >> k;

    const int N = 505;
    static int64_t a[N][N];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    static int64_t pv[N][N], pd[N][N];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            pv[i][j] = pv[i-1][j] + a[i][j];
            pd[i][j] = pd[i-1][j-1] + a[i][j];
        }

    int64_t ans = 0;
    for (int i = 1; i <= n - k; i++) {
        int64_t res = 0;
        for (int u = 0; u <= k; u++)
            for (int v = 0; v <= u; v++)
                res += a[i + u][v + 1];
        ans = max(ans, res);
        for (int j = 2; j <= n - k; j++) {
            res += pd[i+k][j+k] - pd[i-1][j-1];
            res -= pv[i+k][j-1] - pv[i-1][j-1];
            ans = max(ans, res);
        }
    }

    cout << ans;
}