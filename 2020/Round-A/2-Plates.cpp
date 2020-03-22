#include <bits/stdc++.h>
using namespace std;

// Idea: Dynamic programming with state = {stackIdx, remainingPlate}

int t, n, k, p, v;
vector<vector<int>> plates;
vector<vector<int>> dp;

int solve(int idx, int p)
{
    if (p <= 0 || idx >= n)
        return 0;
    else if (dp[idx][p] != -1)
        return dp[idx][p];
    int best = solve(idx + 1, p);
    int sum = 0;
    int plateTaken = 0;
    for (int i = 0; i < k && plateTaken + 1 <= p; i++)
    {
        plateTaken++;
        sum += plates[idx][i];
        best = max(best, solve(idx + 1, p - plateTaken) + sum);
    }
    dp[idx][p] = best;
    return best;
}

int main()
{
    scanf("%d", &t);
    for (int tc = 1; tc <= t; tc++)
    {
        scanf("%d %d %d", &n, &k, &p);
        plates.clear();
        dp.assign(n + 1, vector<int>(p + 1, -1));
        for (int i = 0; i < n; i++)
        {
            vector<int> s;
            for (int j = 0; j < k; j++)
            {
                scanf("%d", &v);
                s.push_back(v);
            }
            plates.push_back(s);
        }
        printf("Case #%d: %d\n", tc, solve(0, p));
    }
}
