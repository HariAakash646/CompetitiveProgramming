#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long long int lli;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<lli> vll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long double ld;

vector<seti> graph;
vb rea;
vvi pos;

bool dfs(int x, int par)
{
    if (rea[x])
        return false;
    rea[x] = true;
    for (auto e : graph[x])
    {
        if (e != par)
        {
            bool out = dfs(e, x);
            if (!out)
                return false;
        }
    }
    return true;
}

bool check(vi &vec, int l, int r)
{
    int ln = r - l + 1;
    // if (ln <= 0)
    //     return true;
    int id = vec[l];
    if (rea[id])
        return false;
    rea[id] = true;
    // if (ln == 0)
    //     return false;
    if (ln <= 1)
        return true;
    if (vec[l] != vec[r])
        return false;
    int c = pos[id][0];
    forr(i, 1, pos[id].size())
    {
        bool out = check(vec, c + 1, pos[id][i] - 1);
        c = pos[id][i];
        if (!out)
            return false;
    }
    return true;
}

int main()
{
    string line;
    getline(cin, line);

    vi vec;
    string curr = "";
    for (auto e : line)
    {
        if (e == ' ')
        {
            vec.pb(stoi(curr));
            curr = "";
        }
        else
            curr += e;
    }
    vec.pb(stoi(curr));
    // for (auto e : vec)
    //     printf("%d ", e);
    int x = vec.size();
    int n = (x + 1) / 2;
    vb vis(n + 1);
    graph = vector<seti>(n + 1);
    vi lid(n + 1);
    // stack<int> stk;
    pos = vvi(n + 1);
    frange(i, x)
    {
        pos[vec[i]].pb(i);
    }
    // stack<int> stk;
    // frange(i, x)
    // {
    //     if (lid[vec[i]] == i)
    //         continue;
    //     if (graph[vec[i + 1]].find(vec[i]) != graph[vec[i + 1]].end())
    //     {
    //         printf("NO");
    //         return 0;
    //     }
    //     graph[vec[i + 1]].insert(vec[i]);
    //     if (graph[vec[i]].find(vec[i + 1]) != graph[vec[i]].end())
    //     {
    //         printf("NO");
    //         return 0;
    //     }
    //     graph[vec[i]].insert(vec[i + 1]);
    // }
    // for (auto e : vec)
    //     cout << e;
    // rea = vb(n + 1);
    // dfs(1, 0);
    // bool done = true;
    // forr(i, 1, n + 1)
    // {
    //     if (!rea[i])
    //         done = false;
    // }
    rea = vb(n + 1);
    bool done = check(vec, 0, x - 1);
    if (done)
        printf("YES");
    else
        printf("NO");
}