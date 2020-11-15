#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

int main(){
    fastio
    int t, n;
    cin >> t;
    for(int tc=1;tc<=t;tc++) {
        // solve
        cin >> n;
        vector<ll> valX(n), valY(n);
        for(int i=0;i<n;i++) cin >> valX[i] >> valY[i];
        sort(valY.begin(), valY.end());
        sort(valX.begin(), valX.end());
        int mean = valY[n/2];
        ll resY = 0, resX = 0;
        for(ll y : valY) resY += abs(y-mean);
        for(int i=0;i<n;i++) valX[i] -= i;
        sort(valX.begin(), valX.end());
        mean = valX[n/2];
        for(ll x : valX) resX += abs(x-mean);
        ll res = resX + resY;

        cout << "Case #" << tc << ": ";
        cout << res;
        cout << "\n";
    }
}
