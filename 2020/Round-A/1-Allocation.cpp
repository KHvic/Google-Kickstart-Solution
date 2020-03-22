#include <bits/stdc++.h>
using namespace std;

// Idea: bucket to count frequency

int main()
{
    int t, n, b, v;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; tc++)
    {
        scanf("%d %d", &n, &b);
        vector<int> cnt(1001, 0);
        while (n--)
        {
            scanf("%d", &v);
            cnt[v]++;
        }
        int res = 0;
        for (int i = 1; i <= 1000; i++)
        {
            int buyable = b / i;
            int buy = min(buyable, cnt[i]);
            res += buy;
            b -= (buy * i);
        }
        printf("Case #%d: %d\n", tc, res);
    }
}
