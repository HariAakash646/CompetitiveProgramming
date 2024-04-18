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
    int t;
    // usaco();
    scd(t);

    frange(_, t) {
        int n;
        scd(n);

        string st1;
        cin >> st1;
        vi str;
        frange(i, n) str.pb(st1[i]-'0');
        vi out;
        int st = 0;
        int en = n;
        int se = 0;
        int ee = n;
        bool done = false;
        frange(i, 301) {
            if(str.size() ==0) {done = true;break;}
            if(str.size() == 1) break;
            if(i == 300) break;
            if(str[st] == str[en-1]) {
                vi tmp;
                if(str[st] == 0) {
                    out.pb(ee);
                    se++;
                    ee++;
                    forr(i, 1, en) {
                        tmp.pb(str[i]);
                    }
                    tmp.pb(0);
                }
                else {
                    out.pb(se);
                    se++;
                    ee+=1;
                    tmp.pb(1);
                    frange(i, en-1) tmp.pb(str[i]);
                }
                str = tmp;
                st = 0;
                en = str.size();
                
            }
            else {
                vi tmp;
                forr(i, 1, en-1) tmp.pb(str[i]);
                str = tmp;
                st = 0;
                en = str.size();
                se++;
                ee-=1;
            }
            // if(str == "1")
            // cout << str;
            // for(auto e : str) printf("%d ", e);
            // printf("\n");
        }
        if(done) {
            printf("%d\n", (int)out.size());
            for(auto e : out) printf("%d\n", e);
        }
        else printf("-1\n");
    }
}