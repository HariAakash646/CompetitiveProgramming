#include "cave.h"
#include <bits/stdc++.h>

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
#define f first
#define s second
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

void exploreCave(int n) {
    int out[n];
    frange(i, n) out[i] = -1;
    int pos[n];
    forr(j, 1, n+1) {

        int vec[n];
        frange(i, n)
            vec[i] = out[i];
        int k = 0;
        frange(i, n) {
            if(out[i] == -1) {vec[i] = 0;k++;}
            else vec[i] = out[i];
        }
        int v = tryCombination(vec);
        int c;
        if(v == -1 || v >= j) c = 0;
        else c = 1;
        int st = 0;
        int en = n;
        while(k > 1) {
            int x = 0;
            int m;
            forr(i, st, en) {
                if(out[i] == -1) {
                    vec[i] = c;
                    x++;
                }
                else vec[i] = out[i];
                if(x >= k/2) {
                    m = i;
                    break;
                }
            }
            forr(i, m+1, en) {
                if(out[i] == -1) {
                    vec[i] = !c;
                }
            }
            int v = tryCombination(vec);
            if(v == -1 || v >= j) {
                k = x;
                en = m+1;
            }
            else {
                k = k - x;
                st = m+1;
            }
        }
        
        forr(i, st, en) {
            if(out[i] == -1) {
                out[i] = c;
                pos[i] = j-1; 
                break;
            }
        }
    }
    
    answer(out, pos);
}

// int main() {
//     usaco();
//   int N;
//   N = init();
//   exploreCave(N);
//   printf("INCORRECT\nYour solution did not call answer().\n");
//   return 0;
// }