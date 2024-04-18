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

int bsze = 1e3;

struct Point
{
    int x, y, id;

    bool operator<(Point k)
    {
        int v1 = x / bsze;
        int v2 = k.x / bsze;
        if (v1 < v2)
        {
            return true;
        }
        else if (v1 == v2)
        {
            if (v1 % 2)
            {
                return y < k.y;
            }
            else
                return y > k.y;
        }
        else
            return false;
    }
};

int main()
{
    int n;
    scd(n);
    vector<Point> vec(n);
    frange(i, n)
    {
        scd(vec[i].x);
        scd(vec[i].y);
        vec[i].id = i + 1;
    }
    sort(all(vec));
    for (auto p : vec)
        printf("%d ", p.id);
}