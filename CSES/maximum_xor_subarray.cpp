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


void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

struct Data {
    int v=0;
    int lc = -1;
    int rc = -1;
};

struct Trie {
    int n;
    vector<Data> tree;

    void init(int l) {
        n = l;
        Data tmp;
        tmp.lc = tmp.rc = -1;
        tree.pb(tmp);
    }

    void insert(int x) {
        int curr = 0;
        for(int i=n-1; i>=0; i--) {
            int v = (x & (1<<i));
            if(!v) {
                if(tree[curr].lc == -1) {
                    tree[curr].lc = tree.size();
                    // printf("%d\n", (int)tree.size());
                    Data tmp;
                    tmp.lc = tmp.rc = -1;
                    tree.pb(tmp);
                } 
                curr = tree[curr].lc;
            }
            else {
                if(tree[curr].rc == -1) {
                    tree[curr].rc = tree.size();
                    // printf("%d\n", (int)tree.size());
                    // printf("%d %d\n", i, curr.rc);
                    Data tmp;
                    tmp.v = 1;
                    tmp.lc = tmp.rc = -1;
                    tree.pb(tmp);
                } 
                // printf("%d %d\n", i, curr.rc);
                curr = tree[curr].rc;

            }
        }
    }

    int search(int x) {
        Data curr = tree[0];

        int out = 0;
        for(int i=n-1; i>=0; i--) {
            // printf("%d %d\n", curr.rc, curr.lc);
            int v = (x & (1<<i));
            if(!v) {
                if(curr.rc != -1 && curr.rc) {
                    // printf("%d %d %d\n", v, i, curr.rc);
                    out = out | (1<<i);
                    curr = tree[curr.rc];
                }
                else curr = tree[curr.lc];
            }
            else {
                if(curr.lc != -1) {
                    // printf("%d %d %d\n", v, i, curr.lc);
                    out = out | (1<<i);
                    curr = tree[curr.lc];
                }
                else curr = tree[curr.rc];
            }
        }
        return out;
    }
};

int main() {
    // usaco();
    int n;
    scd(n);
    Trie trie;
    trie.init(31);

    int v = 0;
    int ma = 0;
    trie.insert(0);

    // for(auto p : trie.tree) printf("%d %d\n", p.lc, p.rc);

    frange(i, n) {
        int a;
        scd(a);
        v = v ^ a;
        // printf("%d\n", a);
        ma = max(ma, trie.search(v));
        // printf("%d %d\n", v, ma);
        trie.insert(v);
    }

    printf("%d", ma);
}