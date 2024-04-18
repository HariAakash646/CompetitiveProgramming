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
#define MP make_pair
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

bool cmp(const pii &x, const pii &y)
{
    if (x.s > y.s)
        return true;
    else if (x.s == y.s)
        return x.s < y.s;
    else
        return false;
}

int main()
{
    int q;
    scd(q);
    set<pii, bool (*)(const pii &, const pii &)> st1(cmp);
    set<pii> st2;
    int num = 0;
    frange(_, q)
    {
        int t;
        scd(t);
        if (t == 1)
        {
            num++;
            int m;
            scd(m);
            st1.insert({num, m});
            st2.insert({num, m});
        }
        else if (t == 2)
        {
            pii p = *st2.begin();
            st2.erase(st2.begin());
            st1.erase(p);
            printf("%d ", p.f);
        }
        else if (t == 3)
        {
            pii p = *st1.begin();
            st1.erase(st1.begin());
            st2.erase(p);
            printf("%d ", p.f);
        }
    }
}