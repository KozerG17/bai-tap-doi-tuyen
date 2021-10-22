/**
 *    author:  dlbm1302
 *    created: 15.10.2021 07:42:42       
**/

#include <bits/stdc++.h>
#ifndef LBM_LOCAL
#define debug(x...) 17
#endif

using namespace std;

int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);

    string s; cin >> s; s = ' ' + s;
    for (int i = 1; s[i]; i++)
        if (!isdigit(s[i]) || (s[i] == '0' && s[i - 1] == ' '))
            s[i] = ' ';
    stringstream t(s);
    set<string> st;
    for (string x; t >> x; )
        st.insert(x);
    cout << st.size();
}