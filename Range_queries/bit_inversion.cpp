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
typedef vector<vii> vvii;
typedef vector<vvi> vvvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

struct dat
{
    int curr = 1;
    int pref = 1;
    int suf = 1;
};

vector<dat> segtree;
vi vec;

void recalculate(int x, int mid, int l, int r)
{
    segtree[x].curr = max(segtree[2 * x + 1].curr, segtree[2 * x + 2].curr);
    if (vec[mid] == vec[mid + 1])
    {
        segtree[x].curr = max(segtree[x].curr, segtree[2 * x + 1].suf + segtree[2 * x + 2].pref);
    }
    if (segtree[2 * x + 1].pref == mid - l + 1 && vec[mid] == vec[mid + 1])
    {
        segtree[x].pref = segtree[2 * x + 1].pref + segtree[2 * x + 2].pref;
    }
    else
    {
        segtree[x].pref = segtree[2 * x + 1].pref;
    }
    if (segtree[2 * x + 2].suf == r - mid && vec[mid] == vec[mid + 1])
    {
        segtree[x].suf = segtree[2 * x + 1].suf + segtree[2 * x + 2].suf;
    }
    else
    {
        segtree[x].suf = segtree[2 * x + 2].suf;
    }
}

void build(int x, int l, int r)
{
    if (l == r)
    {
        return;
    }
    int mid = (l + r) / 2;
    build(2 * x + 1, l, mid);
    build(2 * x + 2, mid + 1, r);
    recalculate(x, mid, l, r);
}

void update(int x, int l, int r, int id)
{
    if (l == r)
    {
        return;
    }
    int mid = (l + r) / 2;
    if (id <= mid)
    {
        update(2 * x + 1, l, mid, id);
    }
    else
    {
        update(2 * x + 2, mid + 1, r, id);
    }
    recalculate(x, mid, l, r);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string bit;
    cin >> bit;
    int n = bit.size();
    int sze = 1;
    while (sze < n)
        sze *= 2;
    vec = vi(sze);
    frange(i, n)
    {
        if (bit[i] == '1')
            vec[i] = 1;
    }
    segtree = vector<dat>(2 * sze);
    build(0, 0, n - 1);
    int m;
    cin >> m;
    frange(i, m)
    {
        int id;
        cin >> id;
        vec[id - 1] = !vec[id - 1];
        update(0, 0, n - 1, id - 1);
        cout << segtree[0].curr << "\n";
    }
}