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
    int n;
    lli k;
    scd(n);
    sclld(k);
    map<lli, lli> num;
    vll vec(n);
    frange(i, n)
    {
        lli a;
        sclld(a);
        num[a]++;
        vec[i] = a;
    }

    lli tot = 0;
    // if (k == 1)
    // {
    //     map<lli, bool> vis;
    //     for (auto e : vec)
    //     {
    //         if (!vis[e])
    //         {
    //             vis[e] = true;
    //             tot += num[e] * (num[e] - 1) * (num[e] - 2) / 6;
    //         }
    //     }
    // }
    // else
    {
        map<lli, lli> cnt;
        vll cvec(n);
        frange(i, n)
        {
            if (k * vec[i] != vec[i])
            {
                cnt[vec[i]] += num[k * vec[i]];
                cvec[i] = num[k * vec[i]];
            }
            else
            {
                cnt[vec[i]] += num[k * vec[i]] - 1;
                cvec[i] = num[k * vec[i]] - 1;
            }

            cvec[i] = num[k * vec[i]];
            num[vec[i]]--;
        }
        frange(i, n)
        {
            auto e = vec[i];
            tot += cnt[k * e];
            cnt[e] -= cvec[i];
        }
    }
    printf("%lld", tot);
}