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

bool isEdge(int i, int j);

// DO NOT CHANGE ANYTHING ABOVE THIS LINE

// You are free to add variables and functions at global scope here
// If you use global variables, remember to initialize them in the getNode() function.

int rec(vi vec) {

    vi lv;
    int x = vec[0];
    forr(i, 1, vec.size()) {
        if(!isEdge(x, vec[i])) {
            forr(j, i, vec.size()) lv.pb(vec[j]);
            break;
        }
    }
    if(lv.size()) return rec(lv);
    else return x;
}

int getNode(int n){
    vi vec;
    frange(i, n) vec.pb(i);
    return rec(vec);
}