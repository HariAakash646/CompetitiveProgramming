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

double euclid_dist(pair<double, double> c1, pair<double, double> c2)
{
    return sqrt((c1.f - c2.f) * (c1.f - c2.f) + (c1.s - c2.s) * (c1.s - c2.s));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    double d;
    cin >> n >> d;

    vector<pair<double, double>> vec(n);
    frange(i, n)
    {
        cin >> vec[i].f >> vec[i].s;
    }

    queue<int> q;
    q.push(0);
    vb inf(n);

    while (q.size())
    {
        int e = q.front();
        q.pop();
        if (inf[e])
            continue;
        inf[e] = true;
        frange(i, n)
        {
            if (euclid_dist(vec[i], vec[e]) <= d)
            {
                q.push(i);
            }
        }
    }
    frange(i, n)
    {
        if (inf[i])
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}