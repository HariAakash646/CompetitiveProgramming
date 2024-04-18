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
#define PB push_back
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

int main()
{

    int n;
    scd(n);
    vi seq1(n);
    frange(i, n) scd(seq1[i]);
    int m;
    scd(m);
    vi seq2(m);
    frange(i, m) scd(seq2[i]);
    vvi lcs_dp(n, vi(m, 0));
    lcs_dp[0][0] = (seq1[0] == seq2[0]) ? 1 : 0;
    forr(i, 1, n, 1)
    {
        lcs_dp[i][0] = (seq1[i] == seq2[0]) ? 1 : lcs_dp[i - 1][0];
    }
    forr(i, 1, m, 1)
    {
        lcs_dp[0][i] = (seq1[0] == seq2[i]) ? 1 : lcs_dp[0][i - 1];
    }
    forr(i, 1, n, 1)
    {
        forr(j, 1, m, 1)
        {
            lcs_dp[i][j] = (seq1[i] == seq2[j]) ? lcs_dp[i - 1][j - 1] + 1 : max(lcs_dp[i - 1][j], lcs_dp[i][j - 1]);
        }
    }
    int i = n - 1;
    int j = m - 1;
    vi seq;
    while (i > 0 && j > 0)
    {
        if (seq1[i] == seq2[j])
        {
            seq.push_back(seq1[i]);
            i--;
            j--;
        }
        else
        {
            if (lcs_dp[i - 1][j] > lcs_dp[i][j - 1])
                i--;
            else
                j--;
        }
    }
    while (i != 0)
    {
        if (lcs_dp[i][0] == 0)
            i = 0;
        else
        {
            if (seq1[i] == seq2[0])
            {
                seq.push_back(seq1[i]);
                break;
            }
            i--;
        }
    }
    while (j != 0)
    {
        if (lcs_dp[0][j] == 0)
            j = 0;
        else
        {
            if (seq1[0] == seq2[j])
            {
                seq.push_back(seq2[j]);
                break;
            }
            j--;
        }
    }
    if (seq1[0] == seq2[0])
        seq.push_back(seq1[0]);

    reverse(seq.begin(), seq.end());
    int s = seq.size();
    if (s == 0)
    {
        printf("0\n\n");
        return 0;
    }
    vi dp(s);
    dp[0] = 1;
    vi prev(s);
    prev[0] = -1;
    forr(i, 1, s, 1)
    {
        int k = 0;
        int k_idx = -1;
        frange(j, i)
        {
            if (seq[i] > seq[j])
            {

                if (dp[j] > k)
                {
                    k = dp[j];
                    k_idx = j;
                }
            }
        }
        dp[i] = k + 1;
        prev[i] = k_idx;
    }
    auto max_ptr = max_element(dp.begin(), dp.end());
    int idx = max_ptr - dp.begin();
    vi com_seq(*max_ptr);
    int c = *max_ptr - 1;
    while (idx != -1)
    {
        com_seq[c] = seq[idx];
        idx = prev[idx];
        c--;
    }

    printf("%d\n", *max_ptr);
    for (int i : com_seq)
    {
        printf("%d ", i);
    }
    return 0;
}
