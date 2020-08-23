#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t,n,v;
    cin >> t;
    for(int tc=1;tc<=t;tc++) {
        cin >> n;
        vector<int> vals(n);
        int res = 0;
        int mn = 0, mx = 0;
        int cur = 0;
        for(int i=0;i<n;i++) {
            cin >> vals[i];
            if(i>0) {
                if(vals[i]==vals[i-1]) continue;
                else if(vals[i]>vals[i-1]) {
                    cur++;
                } else cur--;
                mn = min(mn, cur);
                mx = max(mx, cur);
                if(mx-mn > 3) {
                    res++;
                    cur=mn=mx=0;
                }
            }
        }

        cout << "Case #" << tc << ": ";
        cout << res;
        cout << "\n";
    }
}
