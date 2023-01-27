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
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define MP make_pair
#define pb push_back
#define f first
#define s second
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

vector<seti> graph;
vb vis;

string dfs(int node, string st)
{
    if (vis[node])
        return st;
    vis[node] = true;
    st += ('a' + node);
    for (auto e : graph[node])
    {
        st = dfs(e, st);
    }
    return st;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    frange(_, t)
    {
        string str;
        cin >> str;
        graph = vector<seti>(26);
        forr(i, 1, str.size())
        {
            graph[str[i] - 'a'].insert(str[i - 1] - 'a');
            graph[str[i - 1] - 'a'].insert(str[i] - 'a');
        }
        int root = -2;
        frange(i, 26)
        {
            if (graph[i].size() == 1)
            {
                root = i;
            }
            if (graph[i].size() >= 3)
            {
                root = -1;
                break;
            }
        }
        if (str.size() == 1)
        {
            string st = "";
            frange(i, 26)
            {

                st += ('a' + i);
            }
            cout << "YES"
                 << "\n";
            cout << st << "\n";
            continue;
        }
        if (root < 0)
        {
            cout << "NO\n";
            continue;
        }
        vis = vb(26, false);
        string st = dfs(root, "");
        vb prs(26, true);
        for (auto e : st)
        {
            prs[e - 'a'] = false;
        }
        frange(i, 26)
        {
            if (prs[i])
                st += ('a' + i);
        }
        cout << "YES"
             << "\n";
        cout << st << "\n";
    }
}