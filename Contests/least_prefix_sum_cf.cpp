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
#define forr(i, j, k, in) for (int i = j; i < k; i += in)
#define frange(i, j) forr(i, 0, j, 1)
#define all(cont) cont.begin(), cont.end()
#define MP make_pair
#define pb push_back
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

vi prefix_sum(vi vec)
{
    vi out(vec.size());
    out[0] = vec[0];
    forr(i, 1, vec.size(), 1)
    {
        out[i] = out[i - 1] + vec[i];
    }
    return out;
}
vi max_ele(vi vec)
{
    vi out(vec.size());
    out[0] = vec[0];
    int least = vec[0];
    forr(i, 1, vec.size(), 1)
    {
        least = max(least, vec[i]);
        out[i] = least;
    }
    return out;
}

int main()
{
    int t;
    scd(t);
    frange(i, t)
    {
        int n, m;
        scd(n);
        scd(m);
        vi vec(n);
        vi neg(m);
        frange(j, n)
        {
            scd(vec[j]);
            if (vec[j] < 0 && j < m)
                neg[j] = vec[j];
        }
        vi out = prefix_sum(vec);
        vi vec_copy(vec.begin(), vec.begin() + m);
        reverse(vec_copy.begin(), vec_copy.end());
        vi maxi = max_ele(vec_copy);
        reverse(all(maxi));
        int curr = out[m - 1];
        int cha = 0;
        frange(j, m)
        {
            if (out[j] < curr)
            {
                int dif = curr - out[j];
                while (dif >= 0)
                {
                    auto itr = max_element(vec_copy.begin() + j + 1, vec_copy.end());
                    dif -= (*itr) * 2;
                    *itr = -(*itr);
                    cha++;
                }
            }
        }
        int sum = 0;
        int l = 1e9;
        int l_prev;
        forr(j, m, n, 1)
        {
            sum += vec[j];
            if (l <= vec[j])
            {
                l_prev = l;
                l = vec[j];
            }
            if (sum < 0)
            {
                sum += 2 * l;
                l = l_prev;
                cha++;
            }
        }
        cout << cha << "\n";
    }
}