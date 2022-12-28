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
#define forr(i, j, k, in) for (int i = j; i < k; i += in)
#define frange(i, j) forr(i, 0, j, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.rbegin(), cont.rend()
#define MP make_pair
#define PB push_back
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

vector<lli> prefix_sum(vi &vec) {
    int s = vec.size();
    vector<lli> out(s+1);
    out[0] = 0;
    forr(i, 1, s+1, 1) out[i] = out[i-1] + vec[i-1];
    return out;
}

lli max_cost(vector<lli> &vec, int vec_size, int cows) {
    return vec[min(cows, vec_size-1)];
}

vector<lli> max_milk(vii milk, vector<lli> cow_vec, int cows) {
    
    auto itr = milk.begin();
    
    vector<lli> max_milk_vec(cows+1, 0);
    lli gal;
    lli gal_ini = 0;
    forr(i, 1, cows+1, 1) {
        gal = cow_vec[i] - gal_ini;
        gal_ini = cow_vec[i];
        lli total = 0;
        while(gal > 0 && itr!=milk.end()) {
            total += min(gal, (lli)(*itr).second) * (*itr).first;
            gal -= (*itr).second;
            if(gal < 0) {
                (*itr).second -= gal + (*itr).second;
            }
            else itr++;
        }
        max_milk_vec[i] = max_milk_vec[i-1] + total;
        
    }
        
    return max_milk_vec;
}

int main() {
    int n, m, r;
    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);
    scd(n); scd(m); scd(r);
    vi cows(n);
    frange(i, n) scd(cows[i]);
    sort(rall(cows));
    vii milk(m);
    frange(i, m) {
        scd(milk[i].second);
        scd(milk[i].first);
    }
    sort(rall(milk));
    vi cost(r);
    frange(i, r) {
        scd(cost[i]);
    }
    sort(rall(cost));
    vector<lli> cost_vec = prefix_sum(cost);
    vector<lli> cow_vec = prefix_sum(cows);
    lli max_total = 0;
    lli t;
    int cost_size = cost_vec.size();
    int no_cows = cows.size();
    vector<lli> max_milk_vec = max_milk(milk, cow_vec, no_cows);
    frange(i, no_cows+1) {
        t = max_cost(cost_vec, cost_size, i) + max_milk_vec[no_cows-i];
        max_total = max(max_total, t);
    }
    printf("%lld", max_total);
    
    return 0;
}
