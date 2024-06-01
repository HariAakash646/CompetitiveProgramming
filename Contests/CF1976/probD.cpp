#include <bits/stdc++.h>

using namespace std;

#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define pb push_back
typedef long long int lli;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef map<int, int> mpii;

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}


vvi minv;
vi vec;

void init(int n) {
    minv = vvi(20, vi(n));
    frange(i, n) minv[0][i] = vec[i];

    forr(i, 1, 20) {
        frange(j, n) {
            minv[i][j] = max(minv[i-1][j], minv[i-1][min(n-1, j+(1<<(i-1)))]);
        }
    }
}

int query(int l, int r) {
    int ln = r - l +1;
    int msb = 31 - __builtin_clz(ln);

    return max(minv[msb][l], minv[msb][r-(1<<msb)+1]);
}


int main() {
    fastio();
    int t;
    cin >> t;
    frange(_, t) {
        string str;
        cin >> str;
        int n = str.size();

        vi pref(n+1);
        map<int, vi> mv;
        mv[0].pb(0);
        forr(i, 1, n+1) {
            pref[i] = pref[i-1];
            if(str[i-1] == '(') pref[i]++;
            else pref[i]--;
            mv[pref[i]].pb(i);
        }
        lli tot = 0;
        vec = pref;
        init(n+1);

        forr(l, 1, n+1) {
            int lo = l-1;
            int hi = n;

            while(lo != hi) {
                int mid = (lo+hi+1)/2;
                if(query(l, mid) - pref[l-1] > pref[l-1]) hi = mid-1;
                else lo = mid;
            }
            int i1 = lower_bound(all(mv[pref[l-1]]), l) - mv[pref[l-1]].begin();
            int i2 = upper_bound(all(mv[pref[l-1]]), lo) - mv[pref[l-1]].begin() - 1;
            tot += i2 - i1 + 1;
        }
        cout << tot << "\n";

    }
}