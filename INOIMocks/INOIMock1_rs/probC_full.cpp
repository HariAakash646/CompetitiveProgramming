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
    fastio();
    int l, q;
    cin >> l >> q;
    string str;
    cin >> str;

    vi mv(1<<l);

    frange(i, 1<<l) {
        mv[i] = str[i] - '0';
    }

    vi po3(l+1);
    po3[0] = 1;
    forr(i, 1, l+1) po3[i] = po3[i-1] * 3;

    int v1 = min(l, 7);
    vector<string> quer(q);
    // vector<vb> avail(q, vb(1<<v1));

    // frange(i, q) {
    //     cin >> quer[i];
    //     reverse(all(quer[i]));
    //     vi val;
    //     val.pb(0);
    //     frange(j, v1) {
    //         if(quer[i][j] == '1') {
    //             vi v2;
    //             for(auto e : val) {
    //                 v2.pb(e + (1<<j));
    //             }
    //             val = v2;
    //         } 
    //         else if(quer[i][j] == '?') {
    //             vi v2;
    //             for(auto e : val) {
    //                 v2.pb(e + (1<<j));
    //                 v2.pb(e);
    //             }
    //             val = v2;
    //         }
    //     }
    //     for(auto e : val) avail[i][e] = true;
    // }
    

    vi pos(1<<l);
    frange(i, 1<<l) {
        frange(j, v1) {
            pos[i] += (i&(1<<j));
        }
    }

    
    vi out(q);
    frange(i, 1<<v1) {
        vi val;
        // cout << i << "\n";
        frange(j, 1<<l) {
            if(pos[j] == i) {val.pb(mv[j]);}
        }

        
        // for(auto e : val) cout << e << " ";
        // cout << "\n";

        int v = 1;
        frange(i, l-v1) v *= 3;

        vi tot(v);

        frange(i, v) {
            int li=0;
            int r = 0;
            int x = 0;
            int k = i;
            bool done = false;
            frange(j, l-v1) {
                if(k % 3 == 1) {
                    x += po3[j];
                    li += po3[j];
                    r += po3[j];
                }
                else if(k % 3 == 2) {
                    x += po3[j] * 2;
                    if(!done)
                        {r += po3[j]; done = true;}
                    else {
                        li += po3[j] * 2;;
                        r += po3[j] * 2;
                    }
                }
                k /= 3;
            }
            k = i;
            if(!done) {
                int x2 = 0;
                frange(j, l-v1) {
                    if(k % 3 == 1) {
                        x2 += (1<<j);
                    }
                    k /= 3;
                }
                tot[x] = val[x2];
            }
            else {
                // cout << x << " " << li << " " << r << "\n";
                tot[x] = tot[li] + tot[r];
            }
        }

        frange(k, q) {
            auto& st = quer[k];
            bool done = true;
            frange(j, v1) {
                if(st[j] == '?') continue;
                int dig = st[j] - '0';
                if(dig != (bool)(i&(1<<j))) {
                    done = false;
                    break;
                }
            }
            if(done) {

                int num = 0;
                frange(j, l-v1) {
                    if(st[v1+j] == '1') num += po3[j];
                    else if(st[v1+j] == '?') num += 2*po3[j];
                }
                // cout << k << " " << num << "\n";
                out[k] += tot[num];
            }
        }
    }

    frange(i, q) cout << out[i] << "\n";
}