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

vector<vector<int>> dirs = {{1,0}, {0,1}, {-1,0}, {0,-1}};

int main(){
    int t;
    cin >> t;
    for(int tc=1;tc<=t;tc++) {
        int r,c;
        cin >> r >> c;
        vector<vector<int>> grid(r, vector<int>(c));
        vector<vector<bool>> vis(r, vector<bool>(c));
        priority_queue<vector<ll>> pq;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++) {
                cin >> grid[i][j];
                pq.push({grid[i][j], i, j});
            }

        ll res = 0;
        while(!pq.empty()) {
            auto top = pq.top(); pq.pop();
            int cost = top[0], x = top[1], y = top[2];
            if(vis[x][y]) continue;
            vis[x][y] = true;
            res += cost - grid[x][y];

            for(auto& d : dirs) {
                int nx = d[0]+x, ny = d[1]+y;
                if(nx<0||ny<0||nx>=r||ny>=c) continue;
                if(vis[nx][ny]) continue;
                pq.push({cost-1, nx, ny});
            }
        }

        cout << "Case #" << tc << ": ";
        cout << res;
        cout << "\n";
    }
}
