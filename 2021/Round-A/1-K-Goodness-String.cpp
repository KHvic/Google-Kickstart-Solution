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

int main(){
    int t;
    cin >> t;
    for(int tc=1;tc<=t;tc++) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        int score = 0;
        for(int i=0;i<n/2;i++) score += s[i] != s[n-1-i];
        int chg = abs(k-score);
        cout << "Case #" << tc << ": ";
        cout << chg;
        cout << "\n";
    }
}
