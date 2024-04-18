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
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long double ld;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    scd(n);
    scd(k);
    vi vec(n);
    cout << "and 1 2" << endl;
    int a;
    cin >> a;
    cout << "or 1 2" << endl;
    int b;
    cin >> b;
    int s1 = a + b;
    cout << "and 3 2" << endl;
    cin >> a;
    cout << "or 3 2" << endl;
    cin >> b;
    int s2 = a + b;
    cout << "and 3 1" << endl;
    cin >> a;
    cout << "or 3 1" << endl;
    cin >> b;
    int s3 = a + b;
    vec[1] = (s1 + s2 - s3) / 2;
    vec[0] = s1 - vec[1];
    vec[2] = s2 - vec[1];

    forr(i, 4, n + 1)
    {
        cout << "and 2 " << i << endl;
        cin >> a;
        cout << "or 2 " << i << endl;
        cin >> b;
        int v = a + b;
        vec[i - 1] = v - vec[1];
    }
    sort(all(vec));
    cout << "finish " << vec[k - 1];
}