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

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int t, c;
string str;
const int sz = 2e4 + 2;

vi pos, vec;
vector<bitset<sz>> frw;

void fun(vector<bitset<sz>> &fr1, int x) {
    vi tmp = vec;
    for(int i=c; i>=1; i--) {
        fr1[i] = fr1[i+1];
        if(str[i-1] == 'F' && pos[i]+x <= 2*c && pos[i]+x >= 0) {
            if(tmp[pos[i]+x]) {
                fr1[i][pos[i]+x] = 1;
                tmp[pos[i]+x] = 0;
            }
        }
    }
}

int main() {
    fastio();
    // usaco();
    
    cin >> t >> c;    
    
    vec = vi(2*c+1);

    frange(i, t) {
        int v;
        cin >> v;
        vec[c+v] = 1;
    }
    cin >> str;

    frw =vector<bitset<sz>>(c+1);
    pos=vi(c+1);

    pos[0] = c;
    frw[0] = 0;
    vi tmp = vec;
    forr(i, 1, c+1) {

        if(str[i-1] == 'L') {
            pos[i] = pos[i-1] - 1;
            frw[i] = frw[i-1];
        }
        else if(str[i-1] == 'R') {
            pos[i] = pos[i-1] + 1;
            frw[i] = frw[i-1];
        }
        else {
            pos[i] = pos[i-1];
            frw[i] = frw[i-1];
            if(tmp[pos[i]]) frw[i][pos[i]] = 1;
            tmp[pos[i]] = 0;
        }
    }
    int ma = frw[c].count();

    vector<bitset<sz>> fr1(c+2), fr2(c+2), zer(c+2), bk1(c+2), bk2(c+2);
    fun(fr1, 1);
    fun(fr2, 2);
    fun(bk1, -1);
    fun(bk2, -2);

    forr(i, 1, c+1) {
        if(str[i-1] == 'L') {
            bitset<sz> v = frw[i-1] | fr1[i+1];
            if(pos[i] + 1 <= 2*c) 
                v[pos[i]+1] = vec[pos[i]+1];
            ma = max(ma, (int)v.count());
            v = frw[i-1] | fr2[i+1];
            ma = max(ma, (int)v.count());
        }
        else if(str[i-1] == 'R') {
            bitset<sz> v = frw[i-1] | bk1[i+1];
            if(pos[i] -1 >= 0) 
                v[pos[i]-1] = vec[pos[i]-1];
            ma = max(ma, (int)v.count());
            v = frw[i-1] | bk2[i+1];
            ma = max(ma, (int)v.count());
        }
        else {
            bitset<sz> v = frw[i-1] | bk1[i+1];
            ma = max(ma, (int)v.count());
            v = frw[i-1] | fr1[i+1];
            ma = max(ma, (int)v.count());
        }
    }

    

    cout << ma;
}