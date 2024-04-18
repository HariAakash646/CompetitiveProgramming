#include <bits/stdc++.h>
// #include <grader.h>

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

int besthub(int r, int l, int X[], lli b)
{
    int lo = 0;
    int hi = r;
    vll vec(r);
    frange(i, r) vec[i] = X[i];
    vll pref(r);
    pref[0] = vec[0];
    forr(i, 1, r) pref[i] = pref[i - 1] + vec[i];

    while (lo != hi)
    {
        int mid = (hi + lo + 1) / 2;
        bool check = false;

        forr(i, 0, r)
        {
            if (i - mid / 2 >= 0 && i + (mid - 1) / 2 < r)
            {
                int i1 = mid / 2;
                int i2 = (mid - 1) / 2;
                lli v = pref[i];
                if (i - i1 > 0)
                    v -= pref[i - i1 - 1];
                v = -v;
                v += vec[i] * (i1 + 1);
                v += pref[i + i2] - pref[i];
                v -= vec[i] * i2;
                if (v <= b)
                {
                    check = true;
                    break;
                }
            }
            if (i - (mid - 1) / 2 >= 0 && i + (mid) / 2 < r)
            {
                int i1 = (mid - 1) / 2;
                int i2 = (mid) / 2;
                lli v = pref[i];
                if (i - i1 > 0)
                    v -= pref[i - i1 - 1];
                v = -v;
                v += vec[i] * (i1 + 1);
                v += pref[i + i2] - pref[i];
                v -= vec[i] * i2;
                if (v <= b)
                {
                    check = true;
                    break;
                }
            }
        }
        if (check)
        {
            lo = mid;
        }
        else
            hi = mid - 1;
    }
    return lo;
}

// int main()
// {
//     int r;
//     lli l, b;
//     scd(r);
//     sclld(l);
//     sclld(b);
//     int vec[r];

//     frange(i, r) scd(vec[i]);
//     printf("%d", besthub(r, l, vec, b));
// }
