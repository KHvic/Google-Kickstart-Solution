#include <bits/stdc++.h>
using namespace std;
#define ll long long

// idea: use 2 segment tree or fenwick tree
// first tree for storing a normal range sum
// second tree for storing the seq range sum
// we can add first tree X times to get any X starting seq

vector<ll> segment1, segment2;
int n;
void build(vector<ll> arr) {
    n = arr.size();
    segment1.assign(2*n,0);
    segment2.assign(2*n,0);
    for(int i=0;i<n;i++) {
        segment1[i+n] = arr[i]; 
        segment2[i+n] = arr[i]*(i+1);
        if(i%2) {
            segment2[i+n]*=-1;
            segment1[i+n] *=-1;
        }
    }
    for(int i=n-1;i>0;i--) {
        segment1[i] = segment1[i*2]+segment1[i*2+1];
        segment2[i] = segment2[i*2]+segment2[i*2+1];
    }
}

void update(int p, ll val){

    segment1[n+p] = val;
    segment2[n+p] = val*(p+1);
    if(p%2) {segment2[n+p]*=-1;segment1[n+p]*=-1;}
    for(p=(n+p)>>1;p>0;p>>=1) {
        segment1[p] = segment1[p*2]+segment1[p*2+1];
        segment2[p] = segment2[p*2]+segment2[p*2+1];
    }
}

vector<ll> query2(int l, int r){
    ll res = 0;
    ll res2 = 0;
    for(l+=n, r+=n; l<=r; l >>= 1, r >>= 1){
      if((l&1) == 1) {
            res2 += segment2[l];
            res += segment1[l++];
      }
      if((r&1) == 0) {
            res2 += segment2[r];
            res += segment1[r--];
      }
    }
    return {res,res2};
}

ll solve(int l, int r) {
    vector<ll> p = query2(l,r);
    if(l%2) {
        p[0] *= -1;
        p[1] *= -1;
    }
    ll times = l;
    ll r2 = p[1] - (times*p[0]);
    return r2;
}

int main() {
    int tc,n,q,l,r;
    ll v;
    char c;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++) {
        scanf("%d %d",&n,&q);
        vector<ll> arr;
        ll res = 0;
        for(int i=0;i<n;i++) {
            scanf("%lld",&v);
            arr.push_back(v);
        }
        build(arr);
        for(int i=0;i<q;i++) {
           cin >> c >> l >> r;
           if(c=='Q') {
            res += solve(l-1,r-1);
           } else {
            update(l-1,r);
           }
        }
        printf("Case #%d: %lld\n",t,res);
    }
}
