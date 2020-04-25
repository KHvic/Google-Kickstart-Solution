#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll w,h,l,u,r,d;

vector<double> logfac;
void genFactorial() {
    logfac.assign(1,0);
    for(int i=1; i<=w+h+5; i++) {
        logfac.push_back(logfac[i-1] + log(i));
    }
}

// probability from x1,y1 to x2,y2
double probability(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1, dy = y2 - y1;
    int n = dx + dy;
    double nCr = logfac[n] - logfac[dx] - logfac[dy];
    return exp(nCr - (n+1) * log(2)); // 0.5 probability in each cell, plus one probability to 'exit'
}

/*
find probability to reach x
these x spots guarantee to reach e
s...x.
....x.
..hh..
..hh..
xx....
.....e
*/

double solve() {
    genFactorial();
    double res = 0;
    // probability to reach bottom left of hole
    if (d < h) // don't add if hole is on last row
        for(int i=1;i<l;i++)
            res += probability(1, 1, i, d);
    // probability to reach top right of hole
    if (r < w) // don't add if hole is on last column
        for(int i=1;i<u;i++)
            res += probability(1, 1, r, i);
    return res;
}

int main(){
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++) {
        scanf("%lld %lld %lld %lld %lld %lld",&w,&h,&l,&u,&r,&d);
         printf("Case #%d: %f\n", t, solve());
    }
}
