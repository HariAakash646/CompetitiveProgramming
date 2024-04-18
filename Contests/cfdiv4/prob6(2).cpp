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
typedef vector<lli> vll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

bool cmp(pair<lli, lli> x, pair<lli, lli> y)
{
    if (min(x.f, x.s) < min(y.f, y.s))
        return true;
    else
        return false;
}

// bool cmp1(pair<lli, lli> x, pair<lli, lli> y) {
//     if(x.f < x.s) return true;
//     else if()
// }

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        int n;
        lli c;
        scd(n);
        sclld(c);
        vll vec1(n), vec2(n);
        vector<pair<lli, lli>> vec(n);
        forr(i, 1, n + 1)
        {
            sclld(vec1[i - 1]);
            vec2[i - 1] = vec1[i - 1] + (n + 1 - i);
            vec1[i - 1] += i;
            vec[i - 1] = {vec1[i - 1], vec2[i - 1]};
        }

        lli sum = 0;

        // vll vec;
        // vec.insert(vec.end(), vec1.begin(), vec1.end());
        // vec.insert(vec.end(), vec2.begin(), vec2.end());
        sort(all(vec), cmp);
        lli md = 1e12;
        for (auto p : vec)
        {
            lli e = min(p.s, p.f);
            sum += e;
            if (sum > c)
                break;
            md = min(md, max(0LL, p.f - p.s));
        }
        int idx = 0;
        sum = 0;
        for (auto p : vec)
        {
            lli e = min(p.s, p.f);
            sum += e;
            if (sum + md > c)
                break;
            idx++;
        }
        sort(all(vec));
        sum = vec[0].f;
        vec.erase(vec.begin());
        if (sum > c)
        {
            printf("0\n");
            continue;
        }
        int idx1 = 1;
        sort(all(vec), cmp);
        for (auto p : vec)
        {
            lli e = min(p.s, p.f);
            sum += e;
            if (sum > c)
                break;
            idx1++;
        }
        printf("%d\n", max(idx1, idx));
    }
}