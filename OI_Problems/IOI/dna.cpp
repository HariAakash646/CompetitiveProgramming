#include <bits/stdc++.h>
#include "dna.h"

using namespace std;

#define scd(t) scanf("%d", &t)
#define scld(t) scanf("%ld", &t)
#define sclld(t) scanf("%lld", &t)
#define scc(t) scanf("%c", &t)
#define scs(t) scanf("%s", t)
#define scf(t) scanf("%f", &t)
#define sclf(t) scanf("%lf", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
// #define f first
// #define s second
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;
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


// static std::string s;
// static int tests;

// bool make_test(std::string p) {
//     tests++;
//     for (int i = 0; i < p.size(); i++) {
//         if (p[i] != '0' && p[i] != '1') {
//             return false;
//         }
//     }
//     std::string ss = p + "#" + s;
//     std::vector<int> pr(ss.size() + 1);
//     pr[0] = -1;
//     bool answer = false;
//     for (int i = 1; i <= ss.size(); i++) {
//         int k = pr[i - 1];
//         while (k >= 0 && ss[k] != ss[i - 1])
//             k = pr[k];
//         pr[i] = k + 1;
//         if (pr[i] == p.size()) {
//             answer = true;
//             break;
//         }
//     } 
//     return answer;
// }

string analyse(int n, int t) {
    srand(time(NULL));
    string out = "";
    int ls = -1;
    int nc = 0;

    frange(i, n) {
        int r = rand() % 2;
        out += char('0' + r);
        bool ans = make_test(out);
        if(ans) {
            ls = i;
            nc = 0;
        }
        else {
            nc++;
            out[out.size()-1] = char('0' + !r);
        }
        if(nc >= 64 || (i ==n-1 && nc)) {
            if(make_test(out)) {
                nc = 0;
                ls = i;
            }
            else {
                int lo = 0;
                int hi = nc-1;
                while(lo != hi) {
                    string curr="";
                    int mid = (lo + hi+1)/2;
                    frange(i, ls+mid+1) {
                        curr += out[i];
                    } 
                    if(make_test(curr)) {
                        lo = mid;
                    }
                    else {
                        hi = mid-1;
                    }
                }
                string tmp = "";
                frange(i, ls+lo+1) tmp += out[i];
                out = tmp;
                break;
            }
        }
    }
    int x = out.length();
    // cout << out << " " << n-x << "\n";
    frange(i, n-x) {
        out = '1' + out;
        if(!make_test(out)) {
            out[0] = '0';
        }
        // cout <<i <<":" << out << "\n";
    }
    // cout << out << "\n";
    return out;
}

// int main() {
//     // usaco();
//     int t;
//     // std::cin >> s >> t;
//     frange(i, 32) {
//         t = 10;
//         s = "00000";
//         frange(j, 5) {
//             if(i & (1<<j)) s[5-j-1] = '1';
//         }
//         std::string ans = analyse(s.size(), t);
//         if(ans != s) cout << s << " " << ans << "\n"; 
//     }
    
//     // std::cout << tests << std::endl << ans << std::endl;
//     return 0;
// }
