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
}

vii gr1, gr2;

int main() {
    // usaco();
    int n, k;
    scd(n);
    scd(k);

    seti st;

    gr1 = gr2 = vii(n+1);
    vi vec(k);
    vi v1;
    vb pos1(n+1), pos2(n+1);
    frange(i, k) {
        scd(vec[i]);
        st.insert(vec[i]);
        pos1[vec[i]] = true;
    }
    v1 = vec;

    frange(i, k-1) {
        gr1[vec[i]].f = vec[i+1];
        gr1[vec[i+1]].s = vec[i];
    }
    gr1[vec[k-1]].f = vec[0];
    gr1[vec[0]].s = vec[k-1];

    frange(i, k) {
        scd(vec[i]);
        st.insert(vec[i]);
        pos2[vec[i]] = true;
    }
    // v2 = vec;

    frange(i, k-1) {
        gr2[vec[i]].f = vec[i+1];
        gr2[vec[i+1]].s = vec[i];
    }
    gr2[vec[k-1]].f = vec[0];
    gr2[vec[0]].s = vec[k-1];


    int ma = 0;
    int v = 0;
    int curr = 0;
    int l = 0;

    forr(i, 0, k) {
        if(!pos2[v1[i]]) {
            l = i+1;
            break;
        }
        if(i < k-1 && (gr2[v1[i]].f == v1[i+1] || gr2[v1[i]].s == v1[i+1])) {
            v = i+2;
            l = i+1;
        }
        else {
            v = i+1;
            l = i+1;
            break;
        }
    }
    int r = k-1;
    int v2 = 0;
    for(int i=k; i>=0; i--) {
        if(!pos2[v1[i%k]]) {
            r = i-1;
            break;
        }
        if(i > 0 && (gr2[v1[i%k]].f == v1[i-1] || gr2[v1[i%k]].s == v1[i-1])) {
            v2 = k - i + 1;
            r = i-1;
        }
        else {
            v2 = k-i;
            r = i-1;
            break;
        }
    }

    ma = min(k, v+v2);

    for(int i=l; i<=r;) {
        if(!pos2[v1[i]]) {
            i++;
            continue;
        }
        int og = i;
        while(i < r && (gr2[v1[i]].f == v1[i+1] || gr2[v1[i]].s == v1[i+1])) {
            ma = max(ma, i-og+2);
            i++;
        }
        ma = max(ma, i-og+1);
        i++;
    }

    printf("%d", ma+(n-(int)st.size()));


}