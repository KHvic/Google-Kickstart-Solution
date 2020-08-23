#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

vector<ll> fenwick;
int n;
void adjust(int idx, int val) {
    idx++;
    while(idx<=n) {
        fenwick[idx] += val;
        idx += (idx&-idx);
    }
}

ll query(int idx) {
    idx++;
    ll res = 0;
    while(idx>0) {
        res += fenwick[idx];
        idx -= (idx&-idx);
    }
    return res;
}

int main(){
    fastio
    ll tc;
    cin >> tc;
    for(int t=1;t<=tc;t++) {
        cin >> n;
        fenwick.assign(n+1, 0);
        vector<ll> enjoy(n), rem(n);
        ll sumEnjoy = 0;
        for(int i=0;i<n;i++) {
            cin >> enjoy[i] >> rem[i];
            sumEnjoy += enjoy[i];
            adjust(i, enjoy[i]);
        }

        priority_queue<int,vector<int>,greater<int>> pq;
        vector<int> others;
        for(int i=0;i<n;i++) {
            if(rem[i] > sumEnjoy-enjoy[i]) pq.push(i); // candidates that will cry
            else others.push_back(i);
        }
        // largest rem + enjoy first, candidate that will cry first
        auto cmp = [&](int a, int b) {
            ll valA = rem[a] + enjoy[a], valB = rem[b] + enjoy[b];
            return valA > valB;
        };
        sort(others.begin(), others.end(), cmp);
        ll removal = 0, best = 0;
        int bestremoval = 0;
        int j = 0;
        while(!pq.empty()) {
            int top = pq.top(); pq.pop();
            ll earn = query(n-1) + query(top-1);
            if(earn > best) {
                bestremoval = removal;
                best = earn;
            }
            removal++;
            sumEnjoy -= enjoy[top];
            adjust(top, -enjoy[top]);
            while(j<others.size() && rem[others[j]] > sumEnjoy-enjoy[others[j]]) {
                pq.push(others[j++]);
            }
        }
        cout << "Case #" << t << ": ";
        if(removal != n) cout << removal << " INDEFINITELY";
        else cout << bestremoval << " " << best;
        cout << "\n";
    }
}
