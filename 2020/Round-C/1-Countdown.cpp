#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int tc,n, k, v;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++) {
        scanf("%d %d",&n,&k);
        vector<int> vs;
        int res = 0;
        for(int i=0;i<n;i++) {
            scanf("%d",&v);
            vs.push_back(v);
        }
        int i=0;
        while(i<n) {
            // countdown from k
            if(vs[i] == k) {
                int j = i;
                while(j+1<n && vs[j+1] == vs[j]-1) j++;
                if(vs[j] == 1) res++;
                i = j+1;
            } else i++;
        }
        printf("Case #%d: %d\n", t, res);
    }
}
