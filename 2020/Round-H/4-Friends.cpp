#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

// condense graph to 26 nodes and do bfs on each query in O(1)
int main(){
    fastio
    int t, n, q, a, b;
    cin >> t;
    for(int tc=1;tc<=t;tc++) {
        // solve
        cin >> n >> q;
        vector<string> ppl(n);
        vector<vector<bool>> has(n, vector<bool>(26));
        vector<set<int>> node(26), node2(26);
        for(int i=0;i<n;i++) {
            cin >> ppl[i];
            set<int> u;
            for(char c : ppl[i]) {
                int idx = c-'A';
                has[i][idx] = true;
                node[idx].insert(i);
                u.insert(idx);
            }
            vector<int> chs(u.begin(), u.end());
            for(int j=0;j<chs.size();j++)
            for(int k=j+1;k<chs.size();k++) {
                node2[chs[k]].insert(chs[j]);
                node2[chs[j]].insert(chs[k]);
            }
        }

        auto bfs = [&](int s, int t) {
            if(s==t) return 1;
            vector<bool> vis(26);
            queue<int> q;
            for(int i=0;i<26;i++) {
                if(has[s][i]) {
                    vis[i] = true;
                    q.push(i);
                    if(node[i].count(t)) return 2;
                }
            }
            int steps = 2;
            while(!q.empty()) {
                int len = q.size();
                while(len--) {
                    int top = q.front(); q.pop();
                    for(int v : node2[top]) {
                        if(vis[v]) continue;
                        if(node[v].count(t)) return steps+1;
                        vis[v] = true;
                        q.push(v);
                    }
                }
                steps++;
            }

            return -1;
        };

        vector<int> res;
        for(int i=0;i<q;i++) {
            cin >> a >> b; a--; b--;
            res.push_back(bfs(a, b));
        }

        cout << "Case #" << tc << ":";
        for(int x : res) cout << " " << x;
        cout << "\n";
    }
}
