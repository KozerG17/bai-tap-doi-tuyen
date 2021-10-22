/**
 *    author:  1411
 *    created: 18.10.2021 07:58:20       
**/

#include <bits/stdc++.h>
#ifndef LBM_LOCAL
#define debug(x...) 17
#endif

using namespace std;

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
    freopen("rolling.INP", "r", stdin);
    freopen("rolling.OUT", "w", stdout);

    long long n, k; cin >> n >> k;
    long long a[] = {6, 10, 11, 14};

    long long b = k/4*14;
    if (k % 4 != 0) b += a[k % 4 - 1];
    long long c = n / k * b;

    long long d = n % k, e = d/4*14;
    if (d % 4 != 0) e += a[d % 4 - 1];

    cout << c + e;
}