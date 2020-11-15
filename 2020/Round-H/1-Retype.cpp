#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    int t;
    ll n, k, s;
    cin >> t;
    for(int tc=1;tc<=t;tc++) {
        // solve
        cin >> n >> k >> s;
        ll cur = k-1;
        ll res = min(n+1, n-s+1+k-s) + cur;

        cout << "Case #" << tc << ": ";
        cout << res;
        cout << "\n";
    }
}
