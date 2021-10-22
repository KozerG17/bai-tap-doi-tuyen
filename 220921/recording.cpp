#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> a;

int main() {
	freopen("recording.inp", "r", stdin);
	freopen("recording.out", "w", stdout);
	cin.tie(nullptr) -> sync_with_stdio(false);

	// do something
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		int s, t; cin >> s >> t;
		a.push_back({t, s});
	}
	sort(a.begin(), a.end());

	int ans = 0;
	int tu = 0, tv = 0;
	for (int j = 0; j < n; j++) {
		pair<int, int> i = a[j];
		if (++ans && i.second >= tv) {
			tv = i.first;
		} else if (i.second >= tu) {
			swap(tu = i.first, tv);
		} else ans--;
	}
	cout << ans;
}