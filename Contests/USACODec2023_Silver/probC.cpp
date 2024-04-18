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

vi vec;
vi pos, frw, vfrw;
int t, c;
string str;

void fun(vi &fr1, vi &vfr1, int x) {
    vi tmp = vec;
    for(int i=c; i>=1; i--) {
        fr1[i] += fr1[i+1];
        if(str[i-1] == 'F' && pos[i]+x <= 2*c && pos[i]+x >= 0) {
            if(tmp[pos[i]+x] && (!vfrw[pos[i]+x] || vfrw[pos[i]+x] > i-2)) {
                fr1[i] += tmp[pos[i]+x];
                vfr1[pos[i]+x] = i;
                tmp[pos[i]+x] = 0;
            }
        }
    }
}

int main() {
    // usaco();
    fastio();
    
    cin >> t >> c;
    
        
    if(t > 1000 || c > 1000)
    {    
        vec = vi(2*c+1);
    
        frange(i, t) {
            int v;
            cin >> v;
            vec[c+v] = 1;
        }
        cin >> str;
        
        frw =vi(c+1);
        pos=vi(c+1);
        vfrw=vi(2*c+1);
    
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
                frw[i] = frw[i-1] + tmp[pos[i]];
                if(tmp[pos[i]]) vfrw[pos[i]] = i;
                tmp[pos[i]] = 0;
            }
        }
    
        vi fr1(c+2), fr2(c+2), zer(c+2), bk1(c+2), bk2(c+2);
        vi vfr1(2*c+1), vfr2(2*c+1), vzer(2*c+1), vbk1(2*c+1), vbk2(2*c+1);
        fun(fr1, vfr1, 1);
        fun(fr2, vfr2, 2);
        fun(bk1, vbk1, -1);
        fun(bk2, vbk2, -2);
    
    
        int ma = frw[c];
    
        forr(i, 1, c+1) {
            if(str[i-1] == 'L') {
                int v = frw[i-1] + fr1[i+1];
                if(pos[i] + 1 <= 2*c && (!vfrw[pos[i]+1] || (vfrw[pos[i]+1] >= i)) && (!vfr1[pos[i]+1] || (vfr1[pos[i]+1] <= i))) 
                    v += vec[pos[i]+1];
                ma = max(ma, v);
                v = frw[i-1] + fr2[i+1];
                ma = max(ma, v);
            }
            else if(str[i-1] == 'R') {
                int v = frw[i-1] + bk1[i+1];
                if(pos[i] -1 >= 0 && (!vfrw[pos[i]-1] || (vfrw[pos[i]-1] >= i)) && (!vbk1[pos[i]-1] || (vbk1[pos[i]-1] <= i))) 
                    v += vec[pos[i]-1];
                ma = max(ma, v);
                v = frw[i-1] + bk2[i+1];
                ma = max(ma, v);
            }
            else {
                int v = frw[i-1] + bk1[i+1];
                ma = max(ma, v);
                v = frw[i-1] +fr1[i+1];
                ma = max(ma, v);
            }
        }
    
        // forr(i, 1, c+1) {
        //     cout << pos[i] << " " << frw[i] << " " << fr1[i] << " " << fr2[i] << " " << bk1[i] << " " << bk2[i] << "\n";
        // }
    
        cout << ma;
    }
    else {
        vec = vi(2*c+1);

    frange(i, t) {
        int v;
        cin >> v;
        vec[c+v] = 1;
    }
    cin >> str;

    frw =vi(c+1);
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
            frw[i] = frw[i-1] + tmp[pos[i]];
            tmp[pos[i]] = 0;
        }
    }
    int ma = frw[c];

    frange(i, c) {
        char og = str[i];
        str[i] = 'L';
        frw =vi(c+1);
        pos=vi(c+1);

        pos[0] = c;
        frw[0] = 0;
        tmp = vec;
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
                frw[i] = frw[i-1] + tmp[pos[i]];
                tmp[pos[i]] = 0;
            }
        }
        ma = max(ma, frw[c]);
        str[i] = 'R';
        frw =vi(c+1);
        pos=vi(c+1);

        pos[0] = c;
        frw[0] = 0;
        tmp = vec;
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
                frw[i] = frw[i-1] + tmp[pos[i]];
                tmp[pos[i]] = 0;
            }
        }
        ma = max(ma, frw[c]);
        str[i] = 'F';
        frw =vi(c+1);
        pos=vi(c+1);

        pos[0] = c;
        frw[0] = 0;
        tmp = vec;
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
                frw[i] = frw[i-1] + tmp[pos[i]];
                tmp[pos[i]] = 0;
            }
        }
        ma = max(ma, frw[c]);
        str[i] = og;
    }

    cout << ma;
    }
}