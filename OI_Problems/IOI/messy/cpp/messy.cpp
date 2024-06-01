#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long long int lli;
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
#include "messy.h"

int n;

void build(int l, int r) {
    if(l >= r) return;
    int mid = (l+r)/2;
    string str="";
    frange(i, n) str += "1";
    forr(i, l, r+1) str[i] = '0';
    forr(i, l, mid+1) {
        str[i] = '1';
        // cout << l << " " << r << " " << i << " "<< str << "\n";
        add_element(str);
        str[i] = '0';
    }
    build(l, mid);
    build(mid+1, r);
}

vi out;

void query(int l, int r, vi vec) {
    if(l == r) {
        // if(vec.size())
        out[vec[0]] = l;
        return;
    }
    int mid = (l+r)/2;
    string str="";
    frange(i, n) str += "1";
    for(auto i : vec) str[i] = '0';
    vi lv, rv;
    for(auto e : vec) {
        str[e] = '1';
        if(check_element(str)) lv.pb(e);
        else rv.pb(e);
        str[e] = '0';
    }
    query(l, mid, lv);
    query(mid+1, r, rv);
}

std::vector<int> restore_permutation(int N, int w, int r) {
    n = N;
    build(0, n-1);
    compile_set();
    vi vec;
    frange(i, n) vec.pb(i);
    out = vi(n);
    query(0, n-1, vec);
    return out;
}
