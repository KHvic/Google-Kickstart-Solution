#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }
int __fastio = fastio();

typedef long long ll;
typedef pair<ll, ll> ii;
#define fi first
#define se second
#define sz(x) (int((x).size()))
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

ll compute(int A, int B) {
    ll p1 = A-1, p2 = B/2 - 1;
    return max(min(p1, p2), 0LL);
}


int main(){
    int t;
    cin >> t;
    for(int tc=1;tc<=t;tc++) {
        // solve
        int r,c;
        cin >> r >> c;
        vector<vector<int>> grid(r, vector<int>(c));
        vector<vector<int>> left, right, up, down;
        left = right = up = down = vector<vector<int>>(r, vector<int>(c));
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                cin >> grid[i][j];
        // left + right
        for(int i=0;i<r;i++) {
            for(int j=0,z=0;j<c;j++) {
                if(grid[i][j] == 1) {
                    z++;
                } else z = 0;
                left[i][j] = z;
            }
            for(int j=c-1,z=0;j>=0;j--) {
                if(grid[i][j] == 1) {
                    z++;
                } else z = 0;
                right[i][j] = z;
            }
        }

        // up + down
        for(int j=0;j<c;j++) {
            for(int i=0,z=0;i<r;i++) {
                if(grid[i][j] == 1) {
                    z++;
                } else z = 0;
                up[i][j] = z;
            }
            for(int i=r-1,z=0;i>=0;i--) {
                if(grid[i][j] == 1) {
                    z++;
                } else z = 0;
                down[i][j] = z;
            }
        }
        ll res = 0;
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                int u = up[i][j], d = down[i][j], l = left[i][j], r = right[i][j];
                ll e = 0;
                e+= compute(u, r) + compute(r, u);
                e+= compute(r,d) + compute(d,r);
                e+= compute(d,l) + compute(l,d);
                e+= compute(l,u) + compute(u,l);
                res += e;
            }
        }

        cout << "Case #" << tc << ": ";
        cout << res;
        cout << "\n";
    }
}
