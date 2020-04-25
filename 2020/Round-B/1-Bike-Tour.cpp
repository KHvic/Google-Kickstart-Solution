#include <bits/stdc++.h>
using namespace std;

int main(){
    int tc,n;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++) {
        scanf("%d",&n);
        vector<int> vals(n);
        for(int i=0;i<n;i++)
            scanf("%d", &vals[i]);
        int res = 0;
        for(int i=1;i<n-1;i++)
            if(vals[i]> vals[i-1] && vals[i]>vals[i+1])
                res++;
        printf("Case #%d: %d\n", t, res);
    }
}
