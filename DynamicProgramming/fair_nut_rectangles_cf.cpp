// Not working
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

struct rect
{
    lli x, y, a;
    bool operator<(rect k)
    {
        return x < k.x;
    }
};

vector<rect> vec;
vector<rect> rec;

struct Line
{
    lli m;
    lli c;
    lli operator()(lli x)
    {
        return m * x + c;
    }
};

vector<Line> cht;

bool bad(Line x, Line a, Line b)
{
    return (b.c - x.c) * (x.m - a.m) < (a.c - x.c) * (x.m - b.m);
}

void add(Line x)
{
    while (cht.size() >= 2 && bad(x, *prev(cht.end()), *prev(prev(cht.end()))))
    {
        cht.erase(prev(cht.end()));
    }
    cht.pb(x);
}

int ptr = 0;

lli query(lli x)
{
    int n = cht.size();
    if (n == 0)
        return 0;
    if (ptr >= n)
    {
        ptr = n - 1;
    }
    while (ptr < n - 1 && cht[ptr + 1](x) < cht[ptr](x))
    {
        ptr++;
    }
    return cht[ptr](x);
}

int main()
{
    int n;
    scd(n);
    vec = vector<rect>(n);
    frange(i, n)
    {
        sclld(vec[i].x);
        sclld(vec[i].y);
        sclld(vec[i].a);
    }
    sort(all(vec));
    // frange(i, n)
    // {
    //     while (rec.size() && rec[rec.size() - 1].y <= vec[i].y)
    //     {
    //         rec.erase(prev(rec.end()));
    //     }
    //     rec.pb(vec[i]);
    // }
    rec = vec;
    n = rec.size();
    vll dp(n);
    frange(i, n)
    {
        lli v = query(rec[i].y);
        dp[i] = v - rec[i].x * rec[i].y + rec[i].a;
        Line ele;
        ele.m = rec[i].x;
        ele.c = dp[i];
        add(ele);
    }
    printf("%lld", -(*min_element(all(dp))));
}