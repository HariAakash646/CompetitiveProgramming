#include <bits/stdc++.h>
 
using namespace std;
 
#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, l, r) for(int i=l; i<r; i++)
#define frange(i, l) forr(i, 0, l)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
 
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef long long lli;
typedef vector<vi> vvi;
typedef vector<lli> vll;
typedef vector<bool> vb;
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

lli suml(int l, int r, vll &vec) {
    if(r < l) return 0;
    lli val = vec[r];
    if(l > 0) val -= vec[l-1];
    return val;
}

lli sumr(int l, int r, vll &vec) {
    if(r < l) return 0;
    lli val = vec[l];
    if(l < (int)vec.size()-1) val -= vec[r+1];
    return val;
}


int main() {
    // usaco();
    fastio();
    int t;
    cin >> t;
    
    frange(_, t) {
        int n;
        cin >> n;
        string str;
        cin >> str;

        vll lv(n), rv(n);
        vll lc(n), rc(n);
        lv[0] = str[0] == '<';
        lc[0] = lv[0];

        forr(i, 1, n) {
            lc[i] = lc[i-1] + (str[i] == '<');
            lv[i] = lv[i-1] + (str[i] == '<') * i;
        }

        rc[n-1] = str[n-1] == '>';
        rv[n-1] = rc[n-1];

        for(int i=n-2; i>=0; i--) {
            rc[i] = rc[i+1] + (str[i] == '>');
            rv[i] = rv[i+1] + (str[i] == '>') * (n-1-i);
        }

        frange(i, n) {
            if(str[i] == '<') {
                lli c1 = sumr(0, i-1, rc);
                lli c2 = suml(i+1, n-1, lc);
                lli tot = 0;
                if(c1 <= c2) {
                    tot += 2*(sumr(0, i-1, rv) - c1 * (n-1-i));
                    int l = i;
                    int r = n-1;
                    while(l < r) {
                        int mid = (l+r)/2;
                        if(lc[mid] - lc[i] >= c1) {
                            r = mid;
                        }
                        else l = mid+1;

                    }
                    tot += 2*(suml(i+1, l, lv) - c1 * i);
                    tot += i+1;
                }
                else {
                    tot += 2*(suml(i+1, n-1, lv) - c2 * i);
                    
                    int l = 0;
                    int r = i;
                    while(l < r) {
                        int mid = (l+r+1)/2;
                        if(rc[mid] - rc[i] >= c2+1) {
                            l = mid;
                        }
                        else r = mid-1;
                    }

                    tot += 2*(sumr(l, i-1, rv) - (c2+1) * (n-1-i));
                    
                    tot += n-i;
                }
                cout << tot << " ";
            }
            else {
                lli c1 = sumr(0, i-1, rc);
                lli c2 = suml(i+1, n-1, lc);
                lli tot = 0;
                if(c1 < c2) {
                    tot += 2*(sumr(0, i-1, rv) - c1 * (n-1-i));
                    int l = i;
                    int r = n-1;
                    while(l < r) {
                        int mid = (l+r)/2;
                        if(lc[mid] - lc[i] >= c1+1) {
                            r = mid;
                        }
                        else l = mid+1;
                    }
                    tot += 2*(suml(i+1, l, lv) - (c1+1) * i);
                    tot += i+1;
                }
                else {
                    tot += 2*(suml(i+1, n-1, lv) - c2 * i);
                    // cout << tot << " ";
                    
                    int l = 0;
                    int r = i;
                    while(l < r) {
                        int mid = (l+r+1)/2;
                        if(rc[mid] - rc[i] >= c2) {
                            l = mid;
                        }
                        else r = mid-1;
                        // cout << l << " " << r << "\n";
                    }

                    tot += 2*(sumr(l, i-1, rv) - c2 * (n-1-i));
                    // cout << tot << " ";
                    
                    tot += n-i;
                }
                cout << tot << " ";
            }
        }
        cout << "\n";
    }


}