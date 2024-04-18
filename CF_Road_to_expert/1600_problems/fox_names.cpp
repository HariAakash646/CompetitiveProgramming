// Incorrect for this case:
// 2
// xy
// x
#include <bits/stdc++.h>

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
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;
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

int main()
{
    int n;
    scd(n);
    vs vec(n);
    int ma = 0;
    frange(i, n)
    {
        cin >> vec[i];
        ma = max(ma, int(vec[i].size()));
    }
    vvi graph(26);
    vi indeg(26);
    frange(i, ma)
    {
        int prev = -1;
        int curr;
        frange(j, vec.size())
        {
            auto e = vec[j];
            if (i >= e.size())
            {
                // if (e != "")
                // {
                //     cout << e << "\n";
                //     printf("Impossible");
                //     return 0;
                // }
                // else
                continue;
            }
            curr = e[i] - 'a';
            if (prev != -1 && prev != curr)
            {
                graph[prev].pb(curr);
                indeg[curr]++;
                // vec[j] = "";
                vec[j - 1] = "";
                if (j == vec.size() - 1)
                    vec[j] = "";
            }

            prev = curr;
            // if (i == 0)
            // {
            //     cout << e[i] << " ";
            // }
        }
    }
    vi topo;
    queue<int> q;
    forr(i, 0, 26)
    {
        if (indeg[i] == 0)
            q.push(i);
    }
    int cnt = 0;
    while (q.size())
    {
        if (cnt == 26)
        {
            printf("Impossible");
            return 0;
        }
        int p = q.front();
        q.pop();
        topo.pb(p);
        for (auto e : graph[p])
        {
            indeg[e]--;
            if (indeg[e] <= 0)
            {
                q.push(e);
            }
        }
        cnt++;
    }
    if (topo.size() != 26)
    {
        printf("Impossible\n");
    }
    else
    {
        for (auto e : topo)
        {
            cout << char(e + 'a');
        }
    }
}