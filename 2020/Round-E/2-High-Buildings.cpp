#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    int tc,n,a,b,c;
    cin >> tc;
    for(int t=1;t<=tc;t++) {
        cin >> n >> a >> b >> c;
        vector<int> res(n, 1);
        int afterA = a-c, afterB = b-c;
        bool can = afterA + afterB + c <= n;
        bool special = false;
        if(afterA==0 && afterB==0 && (n-c)>0) {
            if(n<=2 || c==1) can = false;
            else {
                special = true;
                res.assign(n,n);
                for(int i=0,j=1;i<(n-c);i++,j++) res[j] = 1;
            }
        }
        bool swapped = false;
        if(afterA > afterB) {
            swap(afterA, afterB);
            swapped = true;
        }

        if(can && !special) {
            int val = 1;
            for(int i=0;i<afterA;i++) res[i] = val++;
            int idx = afterA;
            for(int i=0;i<c;i++) res[idx++] = n;
            val = afterB<=1&&n>2 ? 2 : 1;
            for(int i=0;i<afterB;i++) {
                int pos = n-1-i;
                res[pos] = val++;
                if(res[pos] >= n) can = false;
            }
        }
        if(swapped) reverse(res.begin(), res.end());

        cout << "Case #" << t << ":";
        if(!can) cout << " IMPOSSIBLE";
        else {
            for(auto x : res) cout << " " << x;
        }
        cout << "\n";
    }
}
