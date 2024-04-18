#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define scd(t) scanf("%d", &t)
#define scld(t) scanf("%ld", &t)
#define sclld(t) scanf("%lld", &t)
#define scc(t) scanf("%c", &t)
#define scs(t) scanf("%s", t)
#define scf(t) scanf("%f", &t)
#define sclf(t) scanf("%lf", &t)
#define forr(i, j, k, in) for (int i = j; i < k; i += in)
#define frange(i, j) forr(i, 0, j, 1)
#define all(cont) cont.begin(), cont.end()
#define MP make_pair
#define pb push_back
#define f first
#define s second
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

int main()
{
    int n, m;
    scd(n);
    scd(m);
    vvi graph(n + 1);
    int a, b;
    frange(i, m)
    {
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }
    int con = 1e9 + 5;
    forr(i, 1, n + 1, 1)
    {
        int node = i;
        queue<int> q;
        vi data(n + 1, 0);
        vi prev(n + 1, 0);
        q.push(node);
        while (q.size() != 0)
        {
            int e = q.front();
            q.pop();
            bool out = false;
            int mini;
            for (int k : graph[e])
            {
                if (k == prev[e])
                    continue;
                if (k == node)
                {
                    mini = data[e] + 1;
                    out = true;
                    break;
                }
                if (data[k] >= m)
                    continue;
                q.push(k);
                data[k] = data[e] + 1;
                prev[k] = e;
            }
            if (out)
            {
                con = min(con, mini);
                break;
            }
        }
    }
    if (con == 1e9 + 5)
    {
        cout << -1;
    }
    else
        cout << con;
    return 0;
}