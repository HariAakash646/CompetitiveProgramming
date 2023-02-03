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

string bin(int n, int sz)
{
    string out = "";
    int c = 0;
    while (n > 0)
    {
        out += to_string(n % 2);
        n /= 2;
        c++;
    }
    while (c < sz)
    {
        out += "0";
        c++;
    }
    reverse(all(out));
    return out;
}

int main()
{
    int n, r;
    scd(n);
    scd(r);

    {
        bool one = false, zero = false;
        vi out;
        vector<pair<pii, vector<int>>> req(r);
        frange(i, r)
        {
            int t, k;
            scd(t);
            scd(k);
            req[i].f = {t, k};
            int a;
            frange(__, k)
            {
                scd(a);
                req[i].s.pb(a);
            }
        }
        frange(i, 1 << n)
        {
            string bina = bin(i, n);
            if (bina.size() != n)
                printf("Not working");
            bool done = true;
            for (auto e : req)
            {
                int t = e.f.f;
                int k = e.f.s;
                int co = 0;
                for (auto l : e.s)
                {
                    if (bina[l - 1] == '1')
                        co++;
                }
                if (t && co % 2)
                    continue;
                else if (t && co % 2 == 0)
                {
                    done = false;
                    break;
                }
                else if (t == 0 && co % 2 == 0)
                    continue;
                else if (t == 0 && co % 2 == 1)
                {
                    done = false;
                    break;
                }
            }
            if (done)
            {
                printf("Yes\n");
                int tot = 0;
                frange(i, n)
                {
                    if (bina[i] == '1')
                        tot++;
                }
                printf("%d\n", tot);
                frange(i, n)
                {
                    if (bina[i] == '1')
                    {
                        printf("%d ", i + 1);
                                        }
                }
                return 0;
            }
        }
        printf("No");
    }
}