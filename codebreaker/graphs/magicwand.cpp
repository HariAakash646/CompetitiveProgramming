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
    int h, w, x, y, t;
    scd(h);
    scd(w);
    scd(x);
    scd(y);
    scd(t);
    x--;
    y--;
    vvi pix(h, vi(w));
    vector<vb> vis(h, vb(w));

    frange(i, h)
    {
        frange(j, w)
        {
            scd(pix[i][j]);
        }
    }

    queue<pii> q;
    q.push({x, y});
    int v = pix[x][y];
    while (q.size())
    {
        auto p = q.front();
        q.pop();
        int x = p.f;
        int y = p.s;
        if (x >= h || x < 0 || y >= w || y < 0 || vis[x][y] || abs(v - pix[x][y]) > t)
            continue;
        vis[x][y] = true;

        q.push(mp(x + 1, y));
        q.push(mp(x, y + 1));
        q.push(mp(x - 1, y));
        q.push(mp(x, y - 1));
    }

    frange(i, h)
    {
        frange(j, w)
        {
            if (vis[i][j])
                printf("1");
            else
                printf("0");
        }
        printf("\n");
    }
}