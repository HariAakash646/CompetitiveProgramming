#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define pb push_back
#define f first
#define s second
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long long int lli;

int tot = 0;
vb vis;
vvi graph;

pair<int, bool> dfs(int node, int cyc)
{
    if (vis[node] && node == cyc)
        return {0, true};
    if (vis[node])
        return {0, false};
    vis[node] = true;
    if (graph[node].size() >= 1 && graph[node][0] != node)
        tot++;
    int out = 0;
    for (auto e : graph[node])
    {
        if (e == node)
            continue;
        auto p = dfs(e, cyc);
        if (p.s)
        {
            return {p.f + 1, true};
        }
    }

    return {0, false};
}

int main()
{
    int t;
    cin >> t;
    frange(_, t)
    {
        string str1, str2;
        cin >> str1;
        cin >> str2;

        graph = vvi(52);
        vi outdeg(52);
        bool brk = false;
        frange(i, str1.size())
        {
            char d = ((str1[i] - 'A') < 26) ? 'A' : 'a' - 26;
            char d2 = ((str2[i] - 'A') < 26) ? 'A' : 'a' - 26;
            if (graph[str1[i] - d].size() == 0)
            {
                outdeg[str1[i] - d] = 1;
            }
            else if (graph[str1[i] - d][0] != str2[i] - d2)
            {
                outdeg[str1[i] - d] += 1;
            }

            if (outdeg[str1[i] - d] > 1)
            {

                printf("-1\n", str1[i]);
                brk = true;
                break;
            }
            // if (str1[i] != str2[i])
            {
                graph[str1[i] - d].pb(str2[i] - d2);
            }
        }
        int num0 = 0;
        frange(i, 52)
        {
            if (outdeg[i] == 0)
                num0++;
        }
        if (brk)
            continue;
        tot = 0;
        vis = vb(52, false);
        frange(i, 52)
        {
            if (!vis[i])
            {
                auto out = dfs(i, i);
                if (out.s)
                {
                    tot += 1;
                    // if (out.f - 1 > num0)
                    // {
                    //     printf("-1\n");
                    //     brk = true;
                    //     break;
                    // }
                }
            }
        }
        if (!brk)
            printf("%d\n", tot - 1);
    }
}