#include <bits/stdc++.h>
using namespace std;
#define ll long long

int s = 1e9;
vector<ll> solve(string& a) {
    stack<vector<ll>> prev;
    stack<ll> vals;
    vector<ll> res(2);
    int idx = 0;
    while(idx<a.size()) {
        char c = a[idx];
        if(isdigit(c)) {
            idx++;
            ll val = c - '0';
          vals.push(val);
          prev.push(res);
          res = vector<ll>(2);
        } else if(c ==')') {
            ll val = vals.top(); vals.pop();
            vector<ll> prevRes = prev.top(); prev.pop();
            for(int i=0;i<2;i++) res[i] = ((res[i]*val) + prevRes[i]);
        } else if(c=='N') res[0]--;
        else if(c=='S') res[0]++;
        else if(c=='E') res[1]++;
        else if(c=='W') res[1]--;
        idx++;
        for(int i=0;i<2;i++) res[i] = (res[i]+s)%s;
    }
    for(int i=0;i<2;i++) res[i] = (res[i]+s)%s;
    return res;
}

int main(){
    int tc,n;
    string in;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++) {
        cin >> in;
        vector<ll> res = solve(in);

        printf("Case #%d: %lld %lld\n", t, res[1]+1, res[0]+1);
    }
}
