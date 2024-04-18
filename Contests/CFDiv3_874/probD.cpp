#include <bits/stdc++.h>

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
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<lli> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long double ld;

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        int n;
        scd(n);
        vi vec(n);
        frange(i, n)
        {
            scd(vec[i]);
        }
        auto it = max_element(all(vec));
        int mid = it - vec.begin();
        if (mid == 0)
        {
            int a = vec[0];
            vec[0] = 0;
            it = max_element(all(vec));
            mid = it - vec.begin();
            vec[0] = a;
        }
        vi v2(n);
        int curr = 0;
        forr(i, mid, n)
        {
            v2[curr] = vec[i];
            curr++;
        }
        int l = curr;
        vvi out(mid);
        frange(i, mid)
        {
            l = curr;
            for (int j = mid - 1; j >= i; j--)
            {
                v2[l] = vec[j];
                l++;
            }
            frange(j, i)
            {
                v2[l] = vec[j];
                l++;
            }
            out[i] = v2;
        }
        // reverse(vec.begin(), it + 1);
        if (mid == n - 1)
        {

            frange(i, n)
            {
                vi v3(n);
                v2 = vec;
                reverse(v2.begin() + i, v2.end());
                int k = 0;
                forr(j, i, n)
                {
                    v3[k] = v2[j];
                    k++;
                }
                frange(j, i)
                {
                    v3[k] = v2[j];
                    k++;
                }
                out.pb(v3);
            }
        }
        vi ans(n);
        for (auto v : out)
        {
            frange(i, n)
            {
                if (v[i] > ans[i])
                {
                    ans = v;
                    break;
                }
                else if (v[i] < ans[i])
                {
                    break;
                }
            }
        }
        // vi ans = *max_element(all(out));
        for (auto e : ans)
            printf("%d ", e);
        printf("\n");
    }
}