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
    int n, q;
    scd(n);
    scd(q);

    vi vec(n+1);
    forr(i, 1, n+1) scd(vec[i]);

    frange(_, q) {
        int l, r;
        scd(l);
        scd(r);
        vi cnt(n+1);
        forr(i, l, r+1) cnt[vec[i]]++;
        int c = 0, c2 = 0;
        int ma = 0;
        forr(i, 1, n+1) {
            if(cnt[i]) {
                c++;
                if(cnt[i] >= 2) c2++;
                ma = max(ma, cnt[i]);
            }
        }       
        int len = r - l + 1;
        if(ma > len/2) {
            printf("1\n");
        }
        else if(len % 2 == 0 && ma == len / 2) {
            if(c == 2)
                printf("0\n");
            else printf("1\n");
        }
        else if(len % 2 == 0) {
            printf("%d\n", c2);
        }
        else {
            printf("%d\n", c);
        }
    }
}