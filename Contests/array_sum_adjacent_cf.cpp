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
typedef vector<bool> vb;
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
    frange(i, t)
    {
        int n;
        scd(n);
        if (n == 3)
            printf("NO\n");
        else if (n % 2 == 0)
        {
            printf("YES\n");
            frange(j, n / 2)
            {
                printf("5 -5 ");
            }
            printf("\n");
        }
        else
        {
            printf("YES\n");
            frange(j, n / 2)
            {
                printf("%d %d ", -(n / 2 - 1), n / 2);
            }
            printf("%d\n", -(n / 2 - 1));
        }
    }

    return 0;
}

// int n = 7;
// frange(i, 101)
// {
//     forr(j, -100, 101, 1)
//     {
//         int sum = j;
//         int next = j;
//         vi ar{next};
//         frange(_, n - 1)
//         {
//             next = i - next;
//             sum += next;
//             ar.pb(next);
//         }
//         if (sum == i)
//         {
//             cout << sum << "\n";
//             for (auto e : ar)
//             {
//                 cout << e << " ";
//             }
//             cout << "\n";
//         }
//     }
// }
