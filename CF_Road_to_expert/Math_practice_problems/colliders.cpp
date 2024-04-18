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
typedef vector<char> vc;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

vi tmp;

void primefac(int n)
{
    int k = 0;
    while (n % 2 == 0)
    {
        if (k == 0)
        {
            tmp.pb(2);
        }
        n = n / 2;
        k++;
    }

    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        k = 0;
        while (n % i == 0)
        {
            if (k == 0)
            {
                tmp.pb(i);
            }
            n = n / i;
            k++;
        }
    }
    if (n > 2)
        tmp.pb(n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vb vec(n + 1);
    vector<pair<bool, int>> prim(n + 1);
    frange(_, m)
    {
        tmp = {};
        int a;
        char c;
        cin >> c >> a;
        if (c == '-')
        {
            if (!vec[a])
            {
                cout << "Already off\n";
            }
            else
            {
                primefac(a);
                for (auto e : tmp)
                    prim[e] = {false, 0};
                vec[a] = false;
                cout << "Success\n";
            }
        }
        else if (c == '+')
        {
            if (vec[a])
            {
                cout << "Already on\n";
            }
            else
            {
                primefac(a);
                bool fail = false;
                for (auto e : tmp)
                {
                    if (prim[e].f)
                    {
                        cout << "Conflict with " << prim[e].s << "\n";
                        fail = true;
                        break;
                    }
                }
                if (fail)
                    continue;
                for (auto e : tmp)
                {
                    prim[e] = {true, a};
                }
                vec[a] = true;
                cout << "Success\n";
            }
        }
    }
}