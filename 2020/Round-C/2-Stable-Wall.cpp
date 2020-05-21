#include <bits/stdc++.h>
using namespace std;
#define ll long long

// idea: topological sorting

int main() {
    int tc,r,c;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++) {
        scanf("%d %d",&r,&c);
        vector<string> sq;
        string in;
        for(int i=0;i<r;i++) {
            cin >> in;
            sq.push_back(in);
        }
        map<char, set<char>> graph;
        map<char, int> indegree;
        set<char> allchars;
        
        // build graph
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++) allchars.insert(sq[i][j]);
        for(int i=0;i<r-1;i++) {
            for(int j=0;j<c;j++) {
                char here = sq[i+1][j];
                char below = sq[i][j];
                if(below == here) continue;
                if(graph[here].count(below)) continue;
                graph[here].insert(below);
                indegree[below]++;
            }
        }
        // topo sort
        queue<char> q;
        int len = allchars.size();
        for(char c : allchars) if(indegree[c] == 0) q.push(c);
        string res = "";
        while(!q.empty()) {
            auto cur = q.front(); q.pop();
            res += cur;
            for(char next : graph[cur]) {
                if(--indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        if(res.size() != len) res = "-1";
        printf("Case #%d: ", t);
        cout << res << endl;
    }
}
