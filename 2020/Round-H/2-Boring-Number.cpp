#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long


ll l, r;
string s;
int n;
vector<vector<ll>> dp;
// digit dp
ll solve(int idx, int upper) {
    if(idx>=n) return 1;
    else if(dp[idx][upper] != -1) return dp[idx][upper];
    int v = s[idx] - '0';
    ll res = idx > 0 && (idx&1) ? solve(idx+1, upper&(v==0)) : 0;
    for(int i=((idx&1) ? 2 : 1);i<=9;i+=2) {
        if(i > v && upper) continue;
        res += solve(idx+1, upper & (i==v));
    }
    return dp[idx][upper] = res;
}

ll go(ll x) {
    if(x==0) return 0;
    s = to_string(x);
    n = s.size();
    dp = vector<vector<ll>>(n, vector<ll>(2, -1));
    ll res = solve(0, 1);
    while(--n>0) {
        dp = vector<vector<ll>>(n, vector<ll>(2, -1));
        res += solve(0, 0);
    }
    return res;
}

int main(){
    fastio
    int t;
    cin >> t;
    for(int tc=1;tc<=t;tc++) {
        // solve
        cin >> l >> r;
        ll res = go(r) - go(l-1);
        cout << "Case #" << tc << ": ";
        cout << res;
        cout << "\n";
    }
}
