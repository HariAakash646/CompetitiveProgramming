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

int main()
{
    int n;
    scd(n);
    vi vec(n);
    frange(i, n) scd(vec[i]);
    vi indeg(n, -1);
    queue<pii> q;
    frange(i, n)
    {
        if (vec[i] == 2)
            q.push({i, 2});
    }
    while (q.size())
    {
        auto p = q.front();
        q.pop();
        if (p.s == 2)
        {
            if (p.f - 1 >= 0 && indeg[p.f] != p.f - 1)
            {
                indeg[p.f - 1] = p.f;
                q.push({p.f - 1, vec[p.f - 1]});
            }
            if (p.f + 1 < n && indeg[p.f] != p.f + 1)
            {
                indeg[p.f + 1] = p.f;
                q.push({p.f + 1, vec[p.f + 1]});
            }
            vec[p.s] = 0;
        }
        else if (p.s == 1)
        {
            if (p.f - 1 >= 0 && indeg[p.f] != p.f - 1)
            {
                indeg[p.f - 1] = p.f;
                q.push({p.f - 1, vec[p.f - 1]});
            }
            else if (p.f + 1 < n && indeg[p.f] != p.f + 1)
            {
                indeg[p.f + 1] = p.f;
                q.push({p.f + 1, vec[p.f + 1]});
            }
            vec[p.s] = 0;
        }
    }
    int c = 0;
    frange(i, n)
    {
        if (indeg[i] == -1)
            c++;
    }
    int c1 = 0;
    pii p = {0 - 1, -1};
    frange(i, n)
    {
        if (vec[i] == 1)
        {
            if (p.f == -1)
                p.f = i;
            p.s = i;
            c--;
        }
        else
        {
            if (p.f == -1)
                continue;
            if ((p.f - 1 < 0 || indeg[p.f - 1] != -1) && (p.s + 1 >= n || indeg[p.s + 1] != -1))
                c++;
            p.f = -1;
            p.s = -1;
        }
    }
    printf("%d", c);
}