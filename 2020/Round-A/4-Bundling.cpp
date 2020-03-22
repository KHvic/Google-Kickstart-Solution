#include <bits/stdc++.h>
using namespace std;

// Idea: Trie post order traversal (go as deep as we can to maximize prefix)

int t, n, k;
string s;
int res = 0;

struct Node
{
    struct Node *child[26];
    int cntEnd = 0;
};

int traverse(Node *n, int depth = 0)
{
    if (!n)
        return 0;
    int cnt = n->cntEnd;
    for (int i = 0; i < 26; i++)
    {
        cnt += traverse(n->child[i], depth + 1);
    }
    int add = cnt / k;
    int rem = cnt % k;
    res += (add * depth);
    return rem;
}

int main()
{
    scanf("%d", &t);
    for (int tc = 1; tc <= t; tc++)
    {
        scanf("%d %d", &n, &k);
        Node *root = new Node();
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            Node *cur = root;
            for (char c : s)
            {
                if (cur->child[c - 'A'] == NULL)
                    cur->child[c - 'A'] = new Node();
                cur = cur->child[c - 'A'];
            }
            cur->cntEnd += 1;
        }
        res = 0;
        traverse(root);
        printf("Case #%d: %d\n", tc, res);
    }
}
