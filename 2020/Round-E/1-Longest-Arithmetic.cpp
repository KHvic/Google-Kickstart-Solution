#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    int tc,n;
    cin >> tc;
    for(int t=1;t<=tc;t++) {
        cin >> n;
        int res = 2;
        vector<ll> vals(n);
        for(int i=0;i<n;i++) cin >> vals[i];

        vector<ll> diff;
        for(int i=1;i<n;i++) {
            ll d = vals[i] - vals[i-1];
            diff.push_back(d);
        }
        // groupby
        int idx = 0;
        while(idx<diff.size()) {
            int j=idx;
            while(j+1<diff.size() && diff[j+1] == diff[idx]) j++;
            res = max(res, j-idx+2);
            idx = j+1;
        }

        cout << "Case #"<<t << ": " << res << "\n";
    }
}
