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
    vii vec(n);
    frange(i, n)
    {
        scd(vec[i].f);
        scd(vec[i].s);
    }
    if (n <= 16)
    {
        frange(i, 1 << n)
        {
            map<int, seti> x, y;
            set<pii> pos;
            frange(j, n)
            {
                if (i & (1 << j))
                {
                    x[vec[j].f].insert(vec[j].s);
                    y[vec[j].s].insert(vec[j].f);
                }
                else
                    pos.insert(vec[j]);
            }
            bool done = true;
            for (auto p : x)
            {
                if (p.s.size() > 2)
                {
                    done = false;
                    break;
                }
            }
            for (auto p : y)
            {
                if (p.s.size() > 2)
                {
                    done = false;
                    break;
                }
            }
            if (!done)
                continue;
            for (auto p : pos)
            {
                if ((x[p.f].size() && *(x[p.f].begin()) <= p.s && p.s <= *prev(x[p.f].end())) || (y[p.s].size() && *(y[p.s].begin()) <= p.f && p.f <= *prev(y[p.s].end())))
                    continue;
                else
                {
                    done = false;
                    break;
                }
            }
            if (!done)
                continue;
            frange(j, n)
            {
                if (i & (1 << j))
                    printf("1");
                else
                    printf("0");
            }
            return 0;
        }
    }
    else
    {

        int xma = 1;
        int yma = 1;
        unordered_map<int, pii> may;
        unordered_map<int, pii> miy;
        frange(i, n)
        {
            xma = max(vec[i].f, xma);
            yma = max(vec[i].s, yma);
            if (may.find(vec[i].s) == may.end() || vec[i].f > may[vec[i].s].s)
            {
                may[vec[i].s].s = vec[i].f;
                may[vec[i].s].f = i;
            }
            if (miy.find(vec[i].s) == miy.end() || vec[i].f < miy[vec[i].s].s)
            {
                miy[vec[i].s].s = vec[i].f;
                miy[vec[i].s].f = i;
            }
        }

        if (lli(xma) * yma == lli(n))
        {
            vvi grid(xma + 1, vi(yma + 1));
            frange(i, n)
            {
                grid[vec[i].f][vec[i].s] = i;
            }
            vi out(n);

            // if (vec[i].f == 1 || vec[i].s == 1)
            //     out[i] = 1;
            // else if (vec[i].f == xma || vec[i].s == 1)
            //     out[i] = 1;
            // else if (vec[i].f == 1 || vec[i].s == yma)
            //     out[i] = 1;
            // else if (vec[i].f == xma || vec[i].s == yma)
            //     out[i] = 1;
            int mi = min(xma, yma);
            frange(j, (mi + 1) / 2)
            {
                out[grid[1 + j][1 + j]] = 1;
                out[grid[1 + j][yma - j]] = 1;
                out[grid[xma - j][1 + j]] = 1;
                out[grid[xma - j][yma - j]] = 1;
            }

            for (auto e : out)
                printf("%d", e);
        }
        else
        {
            vi out(n);
            for (auto p : may)
            {
                // printf("%d %d\n", p.f, p.s);
                out[p.s.f] = 1;
            }
            for (auto p : miy)
            {
                // printf("%d %d\n", p.f, p.s);
                out[p.s.f] = 1;
            }
            for (auto e : out)
                printf("%d", e);
        }
    }
}