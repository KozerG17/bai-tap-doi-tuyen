/**
 *    author:  dlbm1302
 *    created: 21.10.2021 08:11:37       
**/

#include <bits/stdc++.h>
#ifndef LBM_LOCAL
#define debug(x...) 17
#endif

using namespace std;

const int mod = 1e9 + 7;
const int N = 2005;

int n, k;
map<string, int> mp;
vector<int> a(1);
int C[N][N], dp[N][N];

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);

	C[0][0] = 1;
	for (int i = 1; i < N; i++) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++) {
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
			if (C[i][j] > mod) C[i][j] -= mod;
		}
	}
	
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		sort(s.begin(), s.end());
		mp[s]++;
	}

	for (auto &[s, cnt] : mp)
		a.push_back(cnt);

	dp[0][0] = 1; n = a.size();
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= a[i]; j++) {
			int cnt = j*(j - 1)/2;
			for (int c = cnt; c <= k; c++) {
				dp[i][c] += 1ll * C[a[i]][j] * dp[i - 1][c - cnt] % mod;
				if (dp[i][c] > mod) dp[i][c] -= mod;
			}
		}
	}

	cout << dp[n - 1][k];
}