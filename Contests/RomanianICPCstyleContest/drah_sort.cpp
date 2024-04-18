#include <bits/stdc++.h>
using namespace std;

#ifdef evenvalue
#include "debug.h"
#define debug(...) print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#endif

using int64 = long long;
using ld = long double;

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using max_heap = priority_queue<T, vector<T>, less<T>>;

const int n;

namespace read
{
    int Int()
    {
        int x;
        cin >> x;
        return x;
    }
    int64 Int64()
    {
        int64 x;
        cin >> x;
        return x;
    }
    char Char()
    {
        char c;
        cin >> c;
        return c;
    }
    string String()
    {
        string s;
        cin >> s;
        return s;
    }
    double Double()
    {
        return stod(String());
    }
    ld LongDouble()
    {
        return stold(String());
    }
    template <typename T1, typename T2>
    pair<T1, T2> Pair()
    {
        pair<T1, T2> p;
        cin >> p.first >> p.second;
        return p;
    }
    template <typename T>
    vector<T> Vec(const int n)
    {
        vector<T> v(n);
        for (T &x : v)
        {
            cin >> x;
        }
        return v;
    }
    template <typename T>
    vector<vector<T>> VecVec(const int n, const int m)
    {
        vector<vector<T>> v(n);
        for (vector<T> &vec : v)
        {
            vec = Vec<T>(m);
        }
        return v;
    }
} // namespace read

constexpr int kInf = 1e9 + 10;
constexpr int64 kInf64 = 1e15 + 10;
constexpr int kMod = 1e9 + 7;
constexpr int kMaxN = 2e5 + 10;

class MergeSortTree
{
    const int n;
    vector<int64> best;
    vector<vector<int>> mst;

    int64 find(const int x, const int64 val)
    {
        const auto it = std::lower_bound(mst[x].begin(), mst[x].end(), val);
        return (it == mst[x].begin() ? 0 : *(it - 1)) * val;
    }

    void build(const int x, const int l, const int r, const vector<int> &a)
    {
        // if (l == r)
        // {
        //     mst[x] = {a[l]};
        //     return;
        // }
        // const int mid = (l + r) / 2;
        // const int y = 2 * (mid - l + 1) + x;
        // build(x + 1, l, mid, a);
        // build(y, mid + 1, r, a);
        // merge(mst[x + 1].begin(), mst[x + 1].end(),
        //       mst[y].begin(), mst[y].end(),
        //       back_inserter(mst[x]));
        // best[x] = max({best[x + 1], best[y], find(y, mst[x + 1].back())});
        for (int i = x)
    }

    pair<int64, int> query(const int x, const int l, const int r, const int ql, const int qr, const int value = 0)
    {
        if (ql <= l and r <= qr)
        {
            return {max(best[x], find(x, value)), mst[x].back()};
        }
        const int mid = (l + r) / 2;
        const int y = 2 * (mid - l + 1) + x;
        if (qr <= mid)
        {
            return query(x + 1, l, mid, ql, qr, value);
        }
        else if (mid < ql)
        {
            return query(y, mid + 1, r, ql, qr, value);
        }
        else
        {
            const auto [ans1, mx1] = query(x + 1, l, mid, ql, qr, value);
            const auto [ans2, mx2] = query(y, mid + 1, r, ql, qr, max(value, mx1));
            return {max(ans1, ans2), max(mx1, mx2)};
        }
    }

public:
    explicit MergeSortTree(const vector<int> &a) : n((int)a.size()), best(2 * n - 1), mst(2 * n - 1)
    {
        build(0, 0, n - 1, a);
    }

    int64 qeury(const int ql, const int qr)
    {
        return query(0, 0, n - 1, ql, qr).first;
    }
};

inline void solution()
{
    n = read::Int();
    vector<int> a = read::Vec<int>(n);
    MergeSortTree mst(a);

    int q = read::Int();
    while (q--)
    {
        const int l = read::Int() - 1;
        const int r = read::Int() - 1;
        cout << mst.qeury(l, r) << '\n';
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    cout << fixed << setprecision(10);

    int testcases = 1;
    // cin >> testcases;
    while (testcases--)
    {
        solution();
    }
}