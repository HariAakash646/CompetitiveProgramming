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
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

int main()
{
    int n, q;
    scd(n);
    scd(q);
    vii act(n);
    int a, b;
    int idx = 0;
    map<int, pii> range;
    stack<int> stk;
    frange(i, n)
    {
        scd(a);
        if (a == 1)
        {
            scd(b);
            range[b] = {idx, n};
            stk.push(b);
            idx++;
        }
        else
        {
            b = stk.top();
            stk.pop();
            range[b] = {range[b].f, idx};
        }
    }
    vii books(q);
    frange(i, q)
    {
        scd(a);
        scd(b);
        int st = max(range[a].f, range[b].f);
        int en = min(min(range[a].s, idx), min(range[b].s, idx));
        printf("%d\n", max(0, en - st));
    }
}