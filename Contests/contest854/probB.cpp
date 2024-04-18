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

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        int n;
        scd(n);
        vi vec(n);
        int mi = 1e9 + 10;
        int one = false;
        int j = 0;
        int sec = 0;
        int secj = 0;
        frange(i, n)
        {
            scd(vec[i]);
            if (vec[i] < mi && vec[i] != 1)
            {
                sec = mi;
                secj = j;
                mi = vec[i];
                j = i;
            }
            else if (vec[i] < sec)
            {
                sec = vec[i];
                secj = i;
            }
            if (vec[i] == 1)
                one = true;
        }
        bool eq = true;
        forr(i, 1, n)
        {
            if (vec[i] != vec[i - 1])
                eq = false;
        }
        if (n == 1 || eq)
        {
            printf("0\n");
            continue;
        }
        if (n == 2 && one && vec[0] != vec[1])
        {
            printf("-1\n");
            continue;
        }
        vii oper;
        eq = false;
        int c = 0;
        bool over = false;
        while (!eq)
        {
            c++;
            frange(i, n)
            {
                int e = vec[i];
                bool done = true;
                while (e != 2)
                {
                    if (vec[i] > vec[j])
                    {
                        e = (e + mi - 1) / mi;
                        oper.pb({i + 1, j + 1});
                        vec[i] = e;
                        if (c > 30 * n || vec.size() > 30 * n)
                        {
                            over = true;
                            break;
                        }
                    }
                    else
                    {
                        // e = (e + sec - 1) / sec;
                        // oper.pb({i + 1, secj + 1});
                        mi = vec[i];
                        j = i;
                        done = false;
                        break;
                    }
                }
                if (done)
                {
                    j = i;
                    mi = 2;
                }
            }
            eq = true;
            forr(i, 1, n)
            {
                if (vec[i] != vec[i - 1])
                    eq = false;
            }
            // if (!eq)
            // {
            //     frange(i, n)
            //     {
            //         int e = vec[i];
            //         while (e != 2)
            //         {
            //             e = (e + mi - 1) / mi;
            //             oper.pb({i + 1, j + 1});
            //         }
            //         mi = min(mi, e);
            //     }
            // }
            if (c > 30 * n || vec.size() > 30 * n)
            {
                printf("-1\n");
                over = true;
                break;
            }
        }
        if (over)
            continue;
        printf("%d\n", oper.size());
        for (auto e : oper)
        {
            printf("%d %d\n", e.f, e.s);
        }
    }
}