#include <bits/stdc++.h>
using namespace std;

// Idea: binary search + greedy, whether we can achieve some difficulty d

int t, n, k, m;
vector<int> session;

bool can(int d)
{
    int need = 0;
    for (int i = 1; i < n; i++)
    {
        int diff = session[i] - session[i - 1];
        int cost = ceil((double)diff / d) - 1;
        need += cost;
        if (need > k)
            break;
    }
    return need <= k;
}

int main()
{
    scanf("%d", &t);
    for (int tc = 1; tc <= t; tc++)
    {
        scanf("%d %d", &n, &k);
        session.clear();
        int diff = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &m);
            if (i > 0)
                diff = max(diff, m - session.back());
            session.push_back(m);
        }
        int low = 1, high = diff;
        while (low < high)
        {
            int mid = low + (high - low) / 2;

            if (!can(mid))
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        printf("Case #%d: %d\n", tc, low);
    }
}
