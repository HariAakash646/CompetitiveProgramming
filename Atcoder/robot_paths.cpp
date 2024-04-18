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

int main() {
    // usaco();
    int n, x, y;
    scd(n);
    scd(x);
    scd(y);

    vi v1, v2;
    frange(i, n) {
        int a;
        scd(a);
        if(i % 2) v2.pb(a);
        else v1.pb(a);
    }

    int k1 = (n+1)/2;
    int k2 = n/2;

    vi dir1(k1), dir2(k2);
    mpii mv;
    int done = 0;
    frange(i, 1<<((k1+1)/2)) {
        int tot = 0;
        frange(j, ((k1+1)/2)) {
            if(i & (1<<j)) {
                tot += v1[j];
            }
            else {
                tot -= v1[j];
            }
        }
        mv[tot] = i;
    }

    frange(i, 1<<(k1/2)) {
        int tot = 0;
        frange(j, (k1/2)) {
            if(i & (1<<j)) {
                tot += v1[(k1+1)/2+j];
            }
            else {
                tot -= v1[(k1+1)/2+j];
            }
        }
        if(mv.find(y - tot) != mv.end()) {
            done++;
            int v = mv[y - tot];
            frange(j, (k1+1)/2) {
                if(v & (1<<j)) dir1[j] = 1;
                else dir1[j] = -1;
            }
            frange(j, (k1)/2) {
                if(i & (1<<j)) dir1[j + (k1+1)/2] = 1;
                else dir1[j + (k1+1)/2] = -1;
            }
            break;
        }
    }

    mv = {};
    frange(i, 1<<((k2+1)/2)) {
        int tot = 0;
        frange(j, ((k2+1)/2)) {
            if(i & (1<<j)) {
                tot += v2[j];
            }
            else {
                tot -= v2[j];
            }
        }
        mv[tot] = i;
    }

    frange(i, 1<<(k2/2)) {
        int tot = 0;
        frange(j, (k2/2)) {
            if(i & (1<<j)) {
                tot += v2[(k2+1)/2+j];
            }
            else {
                tot -= v2[(k2+1)/2+j];
            }
        }
        if(mv.find(x - tot) != mv.end()) {
            done++;
            int v = mv[x - tot];
            frange(j, (k2+1)/2) {
                if(v & (1<<j)) dir2[j] = 1;
                else dir2[j] = -1;
            }
            frange(j, (k2)/2) {
                if(i & (1<<j)) dir2[j + (k2+1)/2] = 1;
                else dir2[j + (k2+1)/2] = -1;
            }
            break;
        }
    }

    if(done != 2) {
        printf("No");
        return 0;
    }
    else {
        printf("Yes\n");
        if(dir1[0] == 1) printf("L");
        else printf("R");
        forr(i, 1, n) {
            if(i % 2) {
                if(dir1[i/2] * dir2[i/2] == 1) printf("R");
                else printf("L");
            }
            else {
                if(dir1[i/2] * dir2[(i-1)/2] == 1) printf("L");
                else printf("R");
            }
        }
    }
}