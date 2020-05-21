#include <bits/stdc++.h>
using namespace std;
#define ll long long

// O(NsqrtSum)
// foreach prefix sum, foreach perfect square, find complement
// tricky case: must use array/vector for fast speed instead of map/unordered_map
// also, use long long as max total sum is 1e7, & number of possible subarray is 1e10

ll cnt[(int)1e8];
int main() {
    int tc,n;
    ll v;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++) {
        scanf("%d",&n);
        memset(cnt, 0, sizeof cnt);
        vector<ll> vs;
        ll pos = 0, neg = 0;
        for(int i=0;i<n;i++) {
            scanf("%lld",&v);
            vs.push_back(v);
            if(v>0) pos+=v;
            else neg-=v;
        }
        ll sum = 0;
        ll res = 0;
        cnt[neg]++; // use neg as 0 offset
        for(int i=0;i<n;i++) {
            sum += vs[i];
            for(ll j=0;j*j<=pos;j++) {
                ll complement = neg + sum - j*j;
                // ensure doesn't go below 0
                if(complement>=0)
                    res += cnt[complement];
            }
            cnt[neg+sum]++;
        }
        printf("Case #%d: %lld\n",t,res);
    }
}
