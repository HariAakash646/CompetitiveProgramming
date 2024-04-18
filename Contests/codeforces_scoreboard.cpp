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

bool cmp(pair<pii, pii>> x, pair<pii, pii>> y) {
    if(x.f.f > y.f.f) return true;
    else if(x.f.f == y.f.s) {

    }
}


int main() {
    int t;
    scd(t);
    frange(_, t) {
        int n;
        scd(n);
        mu<pair<pii, pii>> vec(n);
        frange(i, n) {
            scd(vec[i].f.f);
            scd(vec[i].s.f);
            scd(vec[i].s.s);
            vec[i].f.s = (vec[i].s.f - vec[i].s.s) / vec[i].f.f;
        }
        sort(all(vec), greater<>());

    }
}