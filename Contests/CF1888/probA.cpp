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

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    // fastion();
    // usaco();
    int t;
    cin >> t;
    frange(_, t) {
        int n, k;
        scd(n);
        scd(k);
        int v = n - k;

        vi cnt(26);
        string str;
        cin >> str;
        frange(i, n) cnt[str[i] - 'a']++;
        int odd = 0;
        frange(i, 26) {
            if(cnt[i] % 2) odd++;
        }
        if(odd == k) {
            printf("YES\n");
        }
        else if(abs(odd - k) == 1) {
            if(v % 2) printf("YES\n");
            else printf("NO\n");
        }
        else if(odd > k) {
            printf("NO\n");
        }
        else if((k - odd) % 2 == 0) {
            printf("YES\n");
        }
        else {
            if(v % 2) printf("YES\n");
            else printf("NO\n");
        }
    }
}