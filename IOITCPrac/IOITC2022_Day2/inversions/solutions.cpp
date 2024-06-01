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

int add(int i, int j);

int subtract(int i, int j);

int multiply(int i, int j);

int exclusive_or(int i, int j);

int compare(int i, int j);

int put(int i);

int compose(int i);

// DO NOT CHANGE ANYTHING ABOVE THIS LINE
// DO NOT PRINT ANYTHING TO STDOUT

vi tree(1e5);

void build(int x, int id, int pos) {
    
}

void add(int x, int id, int pos) {
    if(id == -1) {
        tree[pos]++;
        return;
    }
    add(x, id-1, 2*pos+1);
    add(x|(1<<id))
}

void solve(int n) {
    vi out;
    int id;
    int z = put(0);
    frange(i, n) {
        vi curr;
        if(i < n/2) {
            frange(j, i) {
                id = compare(j, i);
                curr.pb(id);
            }
            if(!curr.size()) {
                id = add(i, z);
                out.pb(id);
            }
            else {
                id = curr[0];
                forr(i, 1, curr.size()) {
                    id = add(id, curr[i]);
                }
                int i1 = id;
                id = add(i, z);
                id = subtract(id, i1);
                out.pb(id);
            }

        }
        else {
            forr(j, i+1, n) {
                id = compare(j, i);
                curr.pb(id);
            }
            if(curr.size()) {
                id = curr[0];
                forr(i, 1, curr.size()) {
                    id = add(id, curr[i]);
                }
                out.pb(id);
            }
        }

    }   
    id = out[0];
    forr(i, 1, out.size()) {
        id = add(id, out[i]);
    }
    // id = put(2);
    // id = multiply(id, id-1);
    // int i1 = id;
    // id = put(0);
    // id = compare(id, i1);
    // id = subtract(i1, id);
}