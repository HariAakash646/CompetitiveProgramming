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

int main()
{
    int t;
    cin >> t;
    frange(i, t)
    {
        int n;
        cin >> n;
        int x = 0, y = 0;
        bool done = false;
        frange(j, n)
        {
            char a;
            cin >> a;
            if (a == 'U')
                y++;
            else if (a == 'D')
                y--;
            else if (a == 'L')
                x--;
            else if (a == 'R')
                x++;
            if (y == 1 && x == 1)
            {
                done = true;
            }
        }
        if (done)
        {
            printf("YES\n");
        }
        else
            printf("NO\n");
    }
}