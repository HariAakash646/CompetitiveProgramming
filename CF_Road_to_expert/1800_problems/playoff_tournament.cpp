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

vi tree;
vi vec;

void recalculate(int x)
{
    if (vec[x] == 1)
    {
        tree[x] = tree[2 * x + 1];
    }
    else if (vec[x] == 0)
    {
        tree[x] = tree[2 * x + 2];
    }
    else
    {
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }
}

void build(int x, int l, int r)
{
    if (l == r)
    {
        // cout << x << " ";
        if (vec[x] == 2)
            tree[x] = 2;
        else
            tree[x] = 1;
        return;
    }
    int mid = (l + r) / 2;
    build(2 * x + 1, l, mid);
    build(2 * x + 2, mid + 1, r);
    recalculate(x);
}

void modify(int x)
{
    recalculate(x);
    if (x == 0)
    {
        return;
    }
    else if (x % 2)
    {
        modify((x - 1) / 2);
    }
    else
    {
        modify((x - 2) / 2);
    }
}

// void update(int x, int v)
// {
//     recalculate(x);
// }

int main()
{
    int k;
    cin >> k;
    int n;
    n = pow(2, k);
    // printf("%d\n", n);
    vec = vi(2 * n, -1);
    string str;
    cin >> str;
    frange(i, n - 1)
    {
        if (str[i] == '0')
        {
            vec[n - 2 - i] = 0;
        }
        else if (str[i] == '1')
        {
            vec[n - 2 - i] = 1;
        }
        else
        {
            vec[n - 2 - i] = 2;
        }
    }
    tree = vi(2 * n);
    build(0, 0, n - 1);
    int q;
    // for (auto e : tree)
    // {
    //     cout << e << " ";
    // }
    scd(q);
    // cout << q;
    frange(_, q)
    {
        int i;
        char v;
        cin >> i >> v;
        i--;
        if (v == '0')
        {
            vec[n - 2 - i] = 0;
        }
        else if (v == '1')
        {
            vec[n - 2 - i] = 1;
        }
        else
        {
            vec[n - 2 - i] = 2;
        }
        modify(n - 2 - i);
        cout << tree[0] << "\n";
    }
}