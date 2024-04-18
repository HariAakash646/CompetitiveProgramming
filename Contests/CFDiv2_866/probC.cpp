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

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        int n;
        scd(n);
        vi vec(n);
        frange(i, n) scd(vec[i]);
        vvi pos(n + 2);
        vi cnt(n + 2);
        frange(i, n)
        {
            if (vec[i] <= n + 1)
            {
                pos[vec[i]].pb(i);
                cnt[vec[i]]++;
            }
        }
        int mex;
        frange(i, n + 1)
        {
            if (cnt[i] == 0)
            {
                mex = i;
                break;
            }
        }
        // printf("%d\n", mex);
        int st = -1;
        int en = -2;
        bool done = false;
        if (pos[mex + 1].size())
        {
            st = pos[mex + 1][0];
            en = *prev(pos[mex + 1].end());
        }
        // printf("%d %d\n", st, en);
        if (st < 0)
        {
            bool grt = false;
            for (auto e : vec)
            {
                if (e > mex + 1)
                {
                    grt = true;
                    break;
                }
            }
            bool cn = false;
            forr(i, 0, mex + 1)
            {
                if (cnt[i] > 1)
                {
                    cn = true;
                    break;
                }
            }
            if (cn || grt)
            {
                printf("Yes\n");
                done = true;
            }
            else
            {
                printf("No\n");
                done = true;
            }
        }
        else
        {
            forr(i, st, en + 1)
            {
                if (vec[i] < mex)
                {
                    cnt[vec[i]]--;
                    if (cnt[vec[i]] == 0)
                    {
                        printf("No\n");
                        done = true;
                        break;
                    }
                }
            }
            if (!done)
            {
                printf("Yes\n");
            }
        }
    }
}