    #include <bits/stdc++.h>
     
    using namespace std;
    using ll = long long;
    const int mxN = 3e5+3;
    vector<int> a[mxN];
    array<int, 3> e[mxN];
    ll bit[mxN], p[mxN], ans[mxN], c = -1;
    void upd(int idx, int x) {
        while (idx < mxN) {
            bit[idx] += x;
            idx |= (idx + 1);
        }
    }
    ll sum(ll idx) {
        ll s = 0;
        while (idx >= 0) {
            s += bit[idx];
            idx &= (idx + 1);
            --idx;
        }
        return s;
    }
    void supd(int l, int r, int x) {
        upd(l, x);
        upd(r+1, -x);
    }
    int n, m;
    void solve(int l, int r, vector<int> &b) {
        int mid = (l + r)/2;
        while (c < mid) {
            ++c;
            if (e[c][0] <= e[c][1]) {
                supd(e[c][0], e[c][1], e[c][2]);
            }
            else {
                supd(e[c][0], m-1, e[c][2]);
                supd(0, e[c][1], e[c][2]);
            }
        }
        while (c > mid) {
            if (e[c][0] <= e[c][1]) {
                supd(e[c][0], e[c][1], -e[c][2]);
            }
            else {
                supd(e[c][0], m-1, -e[c][2]);
                supd(0, e[c][1], -e[c][2]);
            }
            --c;
        }
        vector<int> L, R;
        for (auto x : b) {
            ll s = 0;
            for (auto i : a[x]) {
                s += sum(i);
                if (s >= p[x])  break;
            }
            if (s >= p[x]) {
                ans[x] = mid;
                L.push_back(x);
            }
            else {
                R.push_back(x);
            }
        }
        b.clear();
        if (l < r) {
            solve(l, mid-1, L);
            solve(mid+1, r, R);
        }
    }
    int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cin >> n >> m;
        fill(ans, ans+n, -1);
        for (int i = 0; i < m; ++i) {
            int x;
            cin >> x;
            --x;
            a[x].push_back(i);
        }
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
        }
        int k;
        cin >> k;
        for (int i = 0; i < k; ++i) {
            cin >> e[i][0] >> e[i][1] >> e[i][2];
            --e[i][0], --e[i][1];
        }
        vector<int> b(n);
        iota(b.begin(), b.end(), 0);
        solve(0, k-1, b);
        for (int i = 0; i < n; ++i) {
            cout << (ans[i] == -1 ? "NIE" : to_string(ans[i] + 1)) << '\n';
        }
    }