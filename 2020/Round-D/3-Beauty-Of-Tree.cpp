#include<bits/stdc++.h>
using namespace std;
#define ll long long

int mod = 1e9+7;

// number of descendant for A and B
vector<int> descA, descB;
vector<int> pars, st;
vector<vector<int>> graph;

void dfs(int x, int a, int b) {
    st.push_back(x);
    for(int child : graph[x]) {
        dfs(child, a, b);
    }
    st.pop_back();
    descA[x]++;
    descB[x]++;

    int n = st.size();
    if(n>=a) {
        int parA = st[n-a];
        descA[parA] += descA[x];
    }
    if(n>=b) {
        int parB = st[n-b];
        descB[parB] += descB[x];
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t,n,a,b,v;
    cin >> t;
    for(int tc=1;tc<=t;tc++) {
        cin >> n >> a >> b;
        pars.assign(n,0);
        descA.assign(n,0);
        descB.assign(n,0);
        graph.assign(n,vector<int>());
        for(int i=1;i<n;i++) {
            cin >> pars[i];
            pars[i]--;
            graph[pars[i]].push_back(i);
        }
        // dfs to find number of child for each node
        st.clear();
        dfs(0, a, b);
        double res = 0;
        for(int i=0;i<n;i++) {
            double totalReach = (double)(descA[i] + descB[i]) * n;
            double doubleReach = (double)descA[i] * descB[i];
            res += (totalReach-doubleReach)/n/n;
        }
        cout << fixed << setprecision(12);
        cout << "Case #"<<tc<<": " << res << "\n";
    }
}
