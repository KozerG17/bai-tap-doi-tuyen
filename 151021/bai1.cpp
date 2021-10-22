/**
 *    author:  dlbm1302
 *    created: 15.10.2021 07:42:00       
**/

#include <bits/stdc++.h>
#ifndef LBM_LOCAL
#define debug(x...) 17
#endif

using namespace std;

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
    freopen("bai1.INP", "r", stdin);
    freopen("bai1.OUT", "w", stdout);

    int n, m; cin >> n >> m;

    vector<int> mark(n);

    int id1, val1 = -1;
    int id2, val2 = -1;
    for (int i = 1; i <= m; i++) {
        int l, r; cin >> l >> r;
        if (r - l > val1)
            id1 = i, val1 = r - l;

        int res = 0; l--, r--;
        for (int i = l; i <= r; i++) {
            if (mark[i]) continue;
            res++; mark[i] = true;
        }
        if (res > val2)
            id2 = i, val2 = res;
    }

    cout << id1 << '\n' << id2;
}