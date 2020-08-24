#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

const ll INF = 1e15;

int main(){
    fastio
    int tc,n,m,s,r,u,v,c,k;
    cin >> tc;
    for(int t=1;t<=tc;t++) {
        cin >> n >> m >> s >> r;
        vector<vector<ll>> dist(n, vector<ll>(n, INF));
        for(int i=0;i<n;i++) dist[i][i] = 0;
        for(int i=0;i<m;i++) {
            cin >> u >> v; u--; v--;
            dist[u][v] = dist[v][u] = 1;
        }

        vector<vector<int>> stones;
        for(int i=0;i<n;i++) {
            cin >> c;
            vector<int> stone(c);
            for(int j=0;j<c;j++) {
                cin >> stone[j];
                stone[j]--;
            }
            stones.push_back(stone);
        }

        vector<vector<int>> recipes;
        for(int i=0;i<r;i++) {
            cin >> k;
            vector<int> recipe(k+1);
            for(int j=0;j<=k;j++) {cin >> recipe[j]; recipe[j]--;}
            recipes.push_back(recipe);
        }


        // floyd warshall to find minute dist between cities
        for(int k=0;k<n;k++)
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        // find mincost to get stone
        vector<vector<ll>> stoneCost(n, vector<ll>(s, INF)); // cost to get stone x into city
        for(int i=0;i<n;i++) {
            for(int x : stones[i]) {
                stoneCost[i][x] = 0;
                for(int v=0;v<n;v++) stoneCost[v][x] = min(stoneCost[v][x], dist[i][v]); // update all other cities
            }
        }

        bool improved = true;
        int test = 0;
        // bellman ford variant with relaxation
        while(improved) {
            improved = false;
            // for each possible recipe and target junction
            // check if it relaxes any other cities
            for(auto& recipe : recipes) {
                int len = recipe.size();
                int output = recipe.back();
                for(int i=0;i<n;i++) {
                    ll rcost = 0; // cost to do this recipe
                    for(int j=0;j<len-1;j++) rcost += stoneCost[i][recipe[j]];
                    if(rcost < stoneCost[i][output]) {
                        improved = true;
                        stoneCost[i][output] = rcost;
                        for(int u=0;u<n;u++)
                            stoneCost[u][output] = min(stoneCost[u][output], dist[i][u] + rcost);
                    }
                }
            }
        }
        ll res = INF;
        for(int i=0;i<n;i++) res = min(res, stoneCost[i][0]);

        cout << "Case #"<< t << ": " << (res>=1e12 ? -1 : res) << "\n";
    }
}

