#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int tc,n;
    ll d;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++) {
        scanf("%d %lld",&n,&d);
        vector<ll> vals(n);
        for(int i=0;i<n;i++)
            scanf("%lld",&vals[i]);
        for(int i=n-1;i>=0;i--) {
            ll lastX = d/vals[i];
            d = lastX * vals[i];
        }
        printf("Case #%d: %lld\n", t, d);
    }
}
