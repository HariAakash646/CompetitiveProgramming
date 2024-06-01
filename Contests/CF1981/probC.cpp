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
    // usaco();
    int t;
    scd(t);
    frange(_, t) {
        int n;
        scd(n);

        vi vec(n);
        frange(i, n) scd(vec[i]);
        vi out(n);
        bool done = true;

        pii pre = mp(-1, -1);

        frange(i, n) {
            if(vec[i] != -1) {
                out[i] = vec[i];
                if(pre.f == -1) {
                    for(int j=i-1; j>=0; j--) {
                        if(out[j+1] > 1) out[j] = out[j+1] / 2;
                        else out[j] = out[j+1] * 2; 
                    }
                }
                else {
                    int a = min(pre.s, vec[i]);
                    int b = max(pre.s, vec[i]);
                    int v = pre.s;
                    int id = pre.f;
                    out[i] = vec[i];
                    out[id] = vec[id];

                    int l = id;
                    int r = i;
                    bool ok = true;
                    while(l+1 < r) {
                        if(out[l] > out[r]) {
                            out[l+1] = out[l]/2;
                            l++;
                        }
                        else if(out[r] > out[l]) {
                            out[r-1] = out[r]/2;
                            r--;
                        }
                        else {
                            if((r-l)%2!=0) {
                                done = false;
                            }
                            else {
                                forr(j, 1, r-l) {
                                    if(j % 2) out[l+j] = out[l+j-1] * 2;
                                    else out[l+j] = out[l+j-1] / 2;
                                }
                            }
                            l = r = -1;
                        }
                    }
                    if(l != -1) {
                        if(out[l] != out[l+1]/2 && out[l+1] != out[l]/2) done = false;
                    }
                    
                }
                pre = mp(i, vec[i]);
            }
        }
        if(!done) printf("-1\n");
        else {
            if(pre.f == -1) {
                frange(i, n) {
                    if(i % 2) out[i] = 1;
                    else out[i] = 2;
                }
            }
            else {
                forr(i, pre.f+1, n) {
                    if(out[i-1] == 1) out[i] = 2 * out[i-1];
                    else out[i] = out[i-1]/2;
                }

            }
            for(auto e : out) printf("%d ", e);
            printf("\n");
        }
    }
}