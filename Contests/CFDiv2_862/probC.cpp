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
typedef long double ld;

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        int n, m;
        scd(n);
        scd(m);
        vector<ld> vec(n);
        frange(i, n)
        {
            lli a;
            sclld(a);
            vec[i] = a;
        }
        sort(all(vec));
        vector<pair<ld, ld>> quad(m);
        frange(i, m)
        {
            lli a1, b1, c1;
            sclld(a1);
            sclld(b1);
            sclld(c1);
            ld a = a1;
            ld b = b1;
            ld c = c1;
            ld x = -b / 2 * a;
            ld y = ((b * b) / (4 * a)) - ((b * b) / (2 * a)) + c;
            quad[i] = {x, y};
            // cout << x << " " << y << "\n";
            // if (x > 0)
            // {
            //     auto it = lower_bound(all(vec), (y / x));
            //     if (it != vec.begin())
            //     {
            //         it--;
            //         printf("YES\n%d\n", int(*vec.begin()));
            //     }
            //     else
            //     {
            //         printf("NO\n");
            //     }
            // }
            // else if (x < 0)
            // {
            //     auto it = upper_bound(all(vec), (y / x));
            //     if (it != vec.end())
            //     {
            //         printf("YES\n%d\n", int(*prev(vec.end())));
            //     }
            //     else
            //     {
            //         printf("NO\n");
            //     }
            // }
            // else if (y > 0)
            // {
            //     printf("YES\n");
            //     printf("%d\n", int(*vec.begin()));
            // }
            // else
            // {
            //     printf("NO\n");
            // }
            if (c < 0)
            {
                printf("NO\n");
                continue;
            }
            ld v = b + 2 * sqrt(a * c);
            auto it = lower_bound(all(vec), v);
            if (it != vec.begin())
            {
                it--;
                printf("YES\n");
                printf("%d\n", int(*it));

                // if (*prev(vec.end()) > v)
                // {

                // }
                // else
                // {
                //     printf("NO\n");
                // }
            }
            else
            {
                v = b - 2 * sqrt(a * c);
                auto it = upper_bound(all(vec), v);
                if (it == vec.end())
                {
                    printf("NO\n");
                }
                else if (*it <= b)
                {
                    printf("YES\n");
                    printf("%d\n", int(*it));
                }
                else
                {
                    printf("NO\n");
                }
            }
            // else
            // {
            //     printf("NO\n");
            // }
        }
        printf("\n");
    }
}