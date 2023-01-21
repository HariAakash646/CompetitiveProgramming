#include <bits/stdc++.h>
#include <iostream>

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
#define MP make_pair
#define pb push_back
#define f first
#define s second
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

int main()
{
    int n;
    scd(n);
    vi vec(n);
    set<pii> st;
    frange(i, n)
    {
        int a;
        scd(a);
        vec[i] = a + i + 1;
        st.insert({a + i + 1, i});
    }
    int inc = 1;
    auto itr = max_element(all(vec));
    int beg = itr - vec.begin();
    int ma = *itr;
    printf("%d ", ma);
    for (int i = n - 1; i > 0; i--)
    {
        st.erase({vec[i], i});
        st.insert({vec[i] - n, i});
        if (beg == i)
        {
            int sec;
            int idx;
            tie(sec, idx) = *prev(st.end());
            ma -= n;
            if (sec > ma)
            {
                ma = sec;
                beg = idx;
            }
        }
        printf("%d ", ma + inc);
        inc++;
    }
}