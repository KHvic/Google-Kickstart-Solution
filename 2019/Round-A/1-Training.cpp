#include <bits/stdc++.h>
using namespace std;

int t, n, p, s;

int main()
{
    scanf("%d", &t);
    for (int tc = 1; tc <= t; tc++)
    {
        scanf("%d %d", &n, &p);
        vector<int> skills;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &s);
            skills.push_back(s);
        }
        sort(skills.begin(), skills.end());
        int best = INT_MAX;
        int sum = 0;
        for (int i = 0; i < skills.size(); i++)
        {
            sum += skills[i];
            if (i + 1 >= p)
            {
                int cost = skills[i] * p - sum;
                best = min(best, cost);
                sum -= skills[i - p + 1];
            }
        }
        printf("Case #%d: %d\n", tc, best);
    }
}