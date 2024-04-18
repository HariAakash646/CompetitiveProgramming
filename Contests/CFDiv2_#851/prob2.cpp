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
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

int checkzero(int num)
{
    string str = to_string(num);
    reverse(all(str));
    int tot = 0;
    int out = 0;
    int i = 0;
    for (auto e : str)
    {
        if (e == '0')
            tot++;
        else
            break;
    }
    for (auto e : str)
    {
        if (e == '0')
        {
            if (i % 2 == 0)
            {
                out += 4 * pow(10, (tot - i - 1));
            }
            else
            {
                out += 5 * pow(10, (tot - i - 1));
            }
            i++;
        }
        else
            return out;
    }
    return out;
}

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        int n;
        scd(n);
        int v = n / 2;
        if (n % 2 == 1)
        {
            int out = checkzero(v + 1);
            printf("%d %d\n", v - out, v + out + 1);
        }
        else
        {
            printf("%d %d\n", v, v);
        }
    }
}