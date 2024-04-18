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

bool cmp(pair<lli, lli> &x, pair<lli, lli> &y) {
    return x.s < y.s;
}

int n;
vector<pair<lli, lli>> vec;
vll xvec, yvec;
lli k;

// bool check(lli d) {
//     lli tot = 0;
//     sort(all(vec));

//     int l = 0;
//     int r = -1;

//     lli mix = 1e18;

//     vll pref(n);
//     pref[0] = vec[0].f;

//     forr(i, 1, n) {
//         pref[i] = pref[i-1] + vec[i].f;
//     }

//     while(r < n-1) {
//         r++;
//         if(vec[r].f - vec[l].f <= d) {

//             lli v1 = vec[l].f + d;
//             if(r < n-1) v1 = min(v1, vec[r+1].f);
//             lli v = 0;
//             if(l > 0) {
//                 v += vec[l].f * l - pref[l-1];
//             }
//             if(r < n-1) {
//                 v += pref[n-1] - pref[r] - (n-r-1) * v1;
//             }
//             mix = min(mix, v);

//             v1 = vec[r].f - d;
//             if(l > 0) v1 = max(v1, vec[l-1].f);
//             v = 0;
//             if(l > 0) {
//                 v += v1 * l - pref[l-1];
//             }
//             if(r < n-1) {
//                 v += pref[n-1] - pref[r] - (n-r-1) * vec[r].f;
//             }
//             mix = min(mix, v);
//         }
//         else {
//             l++;
//             r--;
//         }
//     }

//     sort(all(vec), cmp);

//     l = 0;
//     r = -1;

//     lli miy = 1e18;

//     pref = vll(n);
//     pref[0] = vec[0].s;

//     forr(i, 1, n) {
//         pref[i] = pref[i-1] + vec[i].s;
//     }

//     while(r < n-1) {
//         r++;
//         if(vec[r].s - vec[l].s <= d) {
//             lli v1 = vec[l].s + d;
//             if(r < n-1) v1 = min(v1, vec[r+1].s);
//             lli v = 0;
//             if(l > 0) {
//                 v += vec[l].s * l - pref[l-1];
//             }
//             if(r < n-1) {
//                 v += pref[n-1] - pref[r] - (n-r-1) * v1;
//             }
//             miy = min(miy, v);

//             v1 = vec[r].s - d;
//             if(l > 0) v1 = max(v1, vec[l-1].s);
//             v = 0;
//             if(l > 0) {
//                 v += v1 * l - pref[l-1];
//             }
//             if(r < n-1) {
//                 v += pref[n-1] - pref[r] - (n-r-1) * vec[r].s;
//             }
//             miy = min(miy, v);
//         }
//         else {
//             l++;
//             r--;
//         }
//     }
//     tot = mix + miy;
//     return tot <= k;
// }

bool check(lli d) {
    vll pref(n);
    pref[0] = xvec[0];

    forr(i, 1, n) pref[i] = pref[i-1] + xvec[i];

    lli mix = 1e18;

    frange(i, n) {
        lli xi = xvec[i];
        lli x = xvec[i] + d;
        int r = upper_bound(all(xvec), x) - xvec.begin();
        lli v = 0;
        if(i > 0) {
            v += xi * i - pref[i-1];
        }
        if(r <= n-1) {
            v += pref[n-1] - pref[r-1] - (n - r) * x;
        }
        mix = min(mix, v);
    }

    for(int i=n-1; i>=0; i--) {
        lli xi = xvec[i];
        lli x = xvec[i] - d;
        int l = lower_bound(all(xvec), x) - xvec.begin() - 1;
        lli v = 0;
        if(l >= 0) {
            v += x * (l+1) - pref[l];
        }
        if(i < n-1) {
            v += pref[n-1] - pref[i] - (n - i - 1) * xi;
        }
        mix = min(mix, v);
    }

    pref[0] = yvec[0];

    forr(i, 1, n) pref[i] = pref[i-1] + yvec[i];

    lli miy = 1e18;

    frange(i, n) {
        lli yi = yvec[i];
        lli y = yvec[i] + d;
        int r = upper_bound(all(yvec), y) - yvec.begin();
        lli v = 0;
        if(i > 0) {
            v += yi * i - pref[i-1];
        }
        if(r <= n-1) {
            v += pref[n-1] - pref[r-1] - (n - r) * y;
        }
        miy = min(miy, v);
    }

    for(int i=n-1; i>=0; i--) {
        lli yi = yvec[i];
        lli y = yvec[i] - d;
        int l = lower_bound(all(yvec), y) - yvec.begin() - 1;
        lli v = 0;
        if(l >= 0) {
            v += y * (l+1) - pref[l];
        }
        if(i < n-1) {
            v += pref[n-1] - pref[i] - (n - i - 1) * yi;
        }
        miy = min(miy, v);
    }
    return mix + miy <= k;
}

int main() {
    // usaco();
    
    scd(n);
    sclld(k);

    vec = vector<pair<lli, lli>>(n);
    xvec = yvec = vll(n);

    frange(i, n) {
        sclld(vec[i].f);
        sclld(vec[i].s);
        xvec[i] = vec[i].f;
        yvec[i] = vec[i].s;
    }

    sort(all(xvec));
    sort(all(yvec));

    lli lo = 0;
    lli hi = 2e9;

    while(lo != hi) {
        lli mid = (lo + hi)/2;
        bool done = check(mid);
        if(done) hi = mid;
        else lo = mid+1;
    }

    printf("%lld", lo);


}