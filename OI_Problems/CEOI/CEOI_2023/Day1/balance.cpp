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

int main()
{
    int n, v, t;
    scd(n);
    scd(v);
    scd(t);

    vvi cnt(t + 1, vi(v));

    vvi vec(n, vi(v));
    vi cv(t + 1);

    frange(i, n)
    {
        frange(j, v)
        {
            scd(vec[i][j]);
            cv[vec[i][j]]++;
        }
    }
    vvi out(n, vi(v));
    frange(i, 1 << n)
    {
        frange(j, n)
        {
            if (i & (1 << j))
            {
                out[j][0] = vec[j][0];
                out[j][1] = vec[j][1];
            }
            else
            {
                out[j][1] = vec[j][0];
                out[j][0] = vec[j][1];
            }
        }
        vvi cnt(t + 1, vi(2));
        frange(i, n)
        {
            frange(j, 2)
            {
                cnt[out[i][j]][j]++;
            }
        }
        bool done = true;
        forr(j, 1, t + 1)
        {
            if (abs(cnt[j][0] - cnt[j][1]) > 1)
                done = false;
        }
        if (done)
        {
            frange(i, n)
            {
                for (auto e : out[i])
                    printf("%d ", e);
                printf("\n");
            }
            break;
        }
    }

    // forr(i, 1, t + 1)
    // {
    //     forr(j, 0, v)
    //     {
    //         cnt[i][j] = cv[i] / v;
    //     }
    // }

    // frange(i, n)
    // {
    //     seti act;
    //     frange(j, v) act.insert(j);
    //     vi cv1(t + 1);
    //     for (auto e : vec[i])
    //     {
    //         cv1[e]++;
    //     }
    //     vi cv2(t + 1);
    //     forr(j, 1, t + 1)
    //     {
    //         frange(k, v)
    //         {
    //             if (!out[i][k] || cv2[out[i][k]] > cv1[out[i][k]])
    //             {
    //                 if (cnt[j][k])
    //                 {
    //                     cnt[j][k]--;
    //                     cv2[out[i][k]]--;
    //                     cnt[out[i][k]][k]++;
    //                     cv2[j]++;
    //                     out[i][k] = j;
    //                 }
    //             }
    //         }
    //     }
    // }
}