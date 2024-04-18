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

int main() {
    // usaco();
    int n, k;
    scd(n);
    scd(k);

    vi pos1(n+1, -1), pos2(n+1, -1);
    seti st;
    forr(i, 0, k) {
        int a;
        scd(a);
        pos1[a] = i;
        st.insert(a);
    }
    forr(i, 0, k) {
        int a;
        scd(a);
        pos2[a] = i;
        st.insert(a);
    }

    vi diff(n+1, -1);

    forr(i, 1, n+1) {
        if(pos1[i] != -1 && pos2[i] != -1) {
            if(pos1[i] < pos2[i]) {
                diff[i] = pos2[i] - pos1[i];
            }
            else {
                diff[i] = k - pos1[i] + pos2[i];
            }
        }
    }

    // forr(i, 1, k+1) printf("%d ", diff[i]);

    vi cnt(n+1);

    forr(i, 1, n+1) {
        if(diff[i] != -1)
        cnt[diff[i]]++;
    }

    int ma = *max_element(all(cnt));

    forr(i, 1, n+1) {
        if(pos1[i] != -1) pos1[i] = k-1 - pos1[i];
    }

    diff = vi(n+1, -1);

    forr(i, 1, n+1) {
        if(pos1[i] != -1 && pos2[i] != -1) {
            if(pos1[i] < pos2[i]) {
                diff[i] = pos2[i] - pos1[i];
            }
            else {
                diff[i] = k - pos1[i] + pos2[i];
            }
        }
    }

    // forr(i, 1, k+1) printf("%d ", diff[i]);

    cnt = vi(n+1);

    forr(i, 1, n+1) {
        if(diff[i] != -1)
        cnt[diff[i]]++;
    }

    ma = max(ma, *max_element(all(cnt)));

    ma += n-st.size();

    printf("%d", ma);


}