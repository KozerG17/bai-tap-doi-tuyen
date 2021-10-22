/**
 *    author:  1411
 *    created: 18.10.2021 07:59:03       
**/

#include <bits/stdc++.h>
#ifndef LBM_LOCAL
#define debug(x...) 17
#endif

using namespace std;

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
    freopen("CAPGAO.INP", "r", stdin);
    freopen("CAPGAO.OUT", "w", stdout);

    int m, n; cin >> m >> n;

    vector<long long> w(m);
    for (auto &x : w) cin >> x;

    set<long long> st;
    for (int mask = 1; mask < (1 << m); mask++) {
        long long sum = 0;
        for (int i = 0; i < m; i++)
            if (mask >> i & 1) sum += w[i];
        st.insert(sum);
    }

    while (n--) {
        long long x; cin >> x;
        cout << (st.count(x) != 0);
    }
}