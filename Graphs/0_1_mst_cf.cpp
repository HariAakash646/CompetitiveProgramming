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
    int n, m;
    scd(n);
    scd(m);
    vector<set<int>> graph(n + 1);
    frange(i, m)
    {
        int a, b;
        scd(a);
        scd(b);
        graph[a].insert(b);
        graph[b].insert(a);
    }
    set<int> todel;
    forr(i, 1, n + 1) todel.insert(i);
    queue<int> q;
    int c = 0;
    vi cnt(n);
    forr(i, 1, n + 1)
    {
        if (todel.find(i) != todel.end())
        {
            q.push(i);
            c++;
            todel.erase(i);
            while (q.size())
            {
                vi todo;
                int x = q.front();
                cnt[c - 1]++;
                q.pop();
                for (auto e : todel)
                {
                    if (graph[x].find(e) == graph[x].end())
                    {
                        todo.pb(e);
                    }
                }
                for (auto e : todo)
                {
                    todel.erase(e);
                    q.push(e);
                }
            }
        }
    }
    printf("%d\n", c);
    forr(i, 1, n + 1) todel.insert(i);
    c = 0;
    forr(i, 1, n + 1)
    {
        if (todel.find(i) != todel.end())
        {
            q.push(i);
            c++;
            todel.erase(i);
            printf("%d ", cnt[c - 1]);
            while (q.size())
            {
                vi todo;
                int x = q.front();
                printf("%d ", x);
                q.pop();
                for (auto e : todel)
                {
                    if (graph[x].find(e) == graph[x].end())
                    {
                        todo.pb(e);
                    }
                }
                for (auto e : todo)
                {
                    todel.erase(e);
                    q.push(e);
                }
            }
            printf("\n");
        }
    }
}