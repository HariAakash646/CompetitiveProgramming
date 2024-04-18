#include <bits/stdc++.h>
using namespace std;

#define int long long

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

struct foo
{
    int bit;
    int state;
    int value;

    bool operator<(const foo &other) const
    {
        return (value == other.value ? bit > other.bit : value > other.value);
    }
};

inline void solution()
{
    const int n = read::Int();
    const int k = read::Int();
    int p = read::Int();

    const vector<int> a = read::Vec<int>(n);

    // index[i][state] -> all indices with the parity of the ith bit being state
    vector<vector<vector<int>>> index(k, vector<vector<int>>(2));

    for (int i = 0; i < n; i++)
    {
        for (int bit = 0; bit < k; bit++)
        {
            index[bit][(a[i] & (1 << bit)) ? 1 : 0].push_back(i + 1);
        }
    }

    auto calc_cost = [&](const int i, const int bit)
    {
        const int happy = index[i][bit].size() - 1;
        const int sad = index[i][1 - bit].size();
        const int pow2 = (1 << i);
        return pow2 * (happy - sad);
    };

    multiset<foo> best;

    for (int bit = 0; bit < k; bit++)
    {
        foo off = {bit, 0};
        off.value = calc_cost(bit, 0);
        foo on = {bit, 1};
        on.value = calc_cost(bit, 1);
        best.insert(on);
        best.insert(off);
    }

    while (p--)
    {
        const auto [b, s, x] = *best.begin();

        best.erase(best.begin());
        best.erase(best.find({b, 1 - s, calc_cost(b, 1 - s)}));

        cout << index[b][s].back() << ' ' << b << '\n';

        index[b][1 - s].push_back(index[b][s].back());
        index[b][s].pop_back();

        best.insert({b, s, calc_cost(b, s)});
        best.insert({b, 1 - s, calc_cost(b, 1 - s)});
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