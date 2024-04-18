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
    lli n;
    sclld(n);

    string str1, str;

    frange(i, 60) {
        if(n % 2) str1 += '1';
        else str1 += '0';
        n /= 2;
    } 

    reverse(all(str1));

    int id = 0;

    frange(i, 60) {
        if(str1[i] == '1') {
            id = i;
            break;
        }
    }

    forr(i, id, str1.size()) str += str1[i];

    vll dp1(str.size()), dp2(str.size());

    // cout << str << "\n";

    dp2[0] = 1;
    vll v1(str.size());
    v1[0] = 1;
    forr(i, 1, str.size()) {
        if(str[i] == '1') {
            dp1[i] = 2*dp1[i-1] + v1[i-1] + dp2[i-1];
            dp2[i] = dp2[i-1] + 1; 
            v1[i] = v1[i-1] * 2 + 1;
        }
        else {
            dp1[i] = 2*dp1[i-1] + v1[i-1];
            dp2[i] = dp2[i-1];
            v1[i] = v1[i-1] * 2;
        }
        // printf("%lld %lld\n", dp1[i], dp2[i]);
    
    }

    printf("%lld\n", dp1[str.size()-1] + dp2[str.size()-1]);

}