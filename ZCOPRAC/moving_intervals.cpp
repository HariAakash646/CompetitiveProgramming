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
    int t;
    scd(t);
    while (t--)
    {
        int c, n, k;
        scd(c);
        scd(n);
        scd(k);
        int r, l;
        vii vec(n + 2);
        vec[0] = {0, 0};
        vec[n + 1] = {c + 1, c + 1};
        frange(i, n)
        {
            scd(vec[i + 1].s);
            scd(vec[i + 1].f);
        }
        sort(vec.begin(), vec.end());
        pii pr;
        if (k == 1)
        {
            forr(i, 1, n + 1, 1)
            {
                if (vec[i].f >= vec[i + 1].s)
                {
                    int idx;
                    if (vec[i].f - vec[i].s > vec[i + 1].f - vec[i + 1].s)
                    {
                        pr = vec[i + 1];
                        idx = i + 1;
                    }
                    else
                    {
                        pr = vec[i];
                        idx = i;
                    }
                    int dif = pr.f - pr.s + 1;
                    vec.erase(vec.begin() + idx);
                    bool out = true;
                    forr(j, 0, n + 1, 1)
                    {
                        if (vec[j + 1].s - vec[j].f - 1 >= dif)
                        {
                            vec.pb({vec[j].f + dif, vec[j].f + 1});
                            out = false;
                            break;
                        }
                    }
                    if (out)
                    {
                        vec.pb(pr);
                    }
                    break;
                }
            }
            sort(vec.begin(), vec.end());
        }
        bool out = true;
        forr(i, 1, n, 1)
        {
            if (vec[i].f >= vec[i + 1].s)
            {
                cout << "BAD\n";
                out = false;
                break;
            }
        }
        if (out)
            cout << "GOOD\n";
    }
    return 0;
}
