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
        for(int i=0;i<n;i++) {
            cin >> vals[i];
        }
        int res = 0;
        int mx = -1;
        for(int i=0;i<n;i++) {
            if(vals[i] > mx) { // highest so far
                // last day or larger than next day
                if(i==n-1 || vals[i] > vals[i+1]) res++;
            }
            mx = max(vals[i], mx);
        }

        cout << "Case #" << tc << ": ";
        cout << res;
        cout << "\n";
    }
}
