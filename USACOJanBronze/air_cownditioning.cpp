#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define pb push_back
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long long int lli;

#define f first
#define s second

string bin(int n, int m)
{
    string out = "";
    frange(i, m) out += "0";
    int idx = 0;
    while (n > 0)
    {
        out[idx] = '0' + (n % 2);
        n /= 2;
        idx++;
    }
    reverse(all(out));
    return out;
}

int main()
{
    int n, m;
    scd(n);
    scd(m);
    vector<pair<pii, int>> vec(n);
    frange(i, n)
    {
        int l, r, c;
        scd(l);
        scd(r);
        scd(c);
        vec[i].f.f = l;
        vec[i].f.s = r;
        vec[i].s = c;
    }

    vector<pair<pii, pii>> ac(m);
    frange(i, m)
    {
        int a, b, p, co;
        scd(a);
        scd(b);
        scd(p);
        scd(co);
        ac[i].f.f = a;
        ac[i].f.s = b;
        ac[i].s.f = p;
        ac[i].s.s = co;
    }
    int minc = 1e9;
    frange(i, pow(2, m) + 1)
    {
        string bit = bin(i, m);
        vi cool(101, 0);
        int currc = 0;
        frange(k, m)
        {
            if (bit[k] == '1')
            {
                pair<pii, pii> p = ac[k];
                forr(j, p.f.f, p.f.s + 1)
                {
                    cool[j] += p.s.f;
                }
                currc += p.s.s;
            }
        }
        bool yes = true;
        frange(k, n)
        {
            pair<pii, int> p = vec[k];
            forr(j, p.f.f, p.f.s + 1)
            {
                if (cool[j] < p.s)
                {
                    yes = false;
                    break;
                }
            }
        }
        if (!yes)
            continue;
        minc = min(minc, currc);
    }
    printf("%d", minc);
}