#include <bits/stdc++.h>

using namespace std;

#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)


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
    int t;
    cin >> t;

    frange(_, t) {
        int n;
        cin >> n;
        string str;
        cin >> str;
        char pre = '0';
        bool done = true;
        for(auto e : str) {
            if('0' <= pre && pre <= '9' && 'a' <= e && e <= 'z') {pre=e;continue;}
            if('a' <= pre && pre <= 'z' && '0' <= e && e <= '9') {
                done = false;
                break;
            }
            if(pre > e) {
                done = false;
                break;
            }
            pre = e;
        }
        if(done) cout << "YES\n";
        else cout << "NO\n";
    }
}