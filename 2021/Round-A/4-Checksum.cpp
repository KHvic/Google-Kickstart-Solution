#include <bits/stdc++.h>
using namespace std;
int fastio() { ios_base::sync_with_stdio(false); cout << fixed << setprecision(10); cin.tie(nullptr); return 0; }
int __fastio = fastio();

typedef long long ll;
#define fi first
#define se second
#define sz(x) (int((x).size()))
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

struct UF {
    int cnt;
    vector<int> p, rank, size;
    UF(int N): cnt{N} {
        p = rank = size = vector<int>(N, 1);
        for (int i = 0; i < N; i++) p[i] = i;
    }
    int find(int i) {
        return p[i] == i ? i : p[i] = find(p[i]);
    }
    bool connected(int i, int j) {
        return find(i) == find(j);
    }
    void join(int i, int j) {
        if (connected(i, j)) return;
        cnt--;
        int x = find(i), y = find(j);
        if (rank[x] > rank[y]) {
            p[y] = x;
            size[x] += size[y];
        } else {
            p[x] = y;
            size[y] += size[x];
            if (rank[x] == rank[y]) rank[y]++;
        }
    }
};


int main(){
    int t;
    cin >> t;
    for(int tc=1;tc<=t;tc++) {
        int n;
        cin >> n;
        vector<int> c(n), d(n);
        vector<vector<int>> a ,b;
        ll totalCost = 0;
        a = b = vector<vector<int>>(n, vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin >> a[i][j];

        vector<tuple<int, int, int>> edges;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++) {
                cin >> b[i][j];
                totalCost += b[i][j];
                edges.emplace_back(b[i][j], i, j+n);
            }
        sort(rall(edges));
        for(int i=0;i<n;i++) cin >> c[i]; // ignored
        for(int i=0;i<n;i++) cin >> d[i]; // ignored

        ll mxMST = 0;
        // observation: at most N^2 - (N-1)^2 = 2N-1 cells can be uncovered to restore matrix
        // 2N-1 unknown edges can form a maximum spanning tree for the N columns and N rows (2N nodes)
        UF uf(2*n);
        for(auto&[c,a,b] : edges) {
            if(!uf.connected(a,b)) {
                uf.join(a,b);
                mxMST += c;
            }
        }

        cout << "Case #" << tc << ": ";
        cout << totalCost - mxMST;
        cout << "\n";
    }
}
