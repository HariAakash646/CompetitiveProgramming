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
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

int main()
{
    int t;
    cin >> t;
    frange(_, t)
    {
        string seq;
        cin >> seq;
        int n = seq.size();
        vll vec(n);
        if (seq[0] == '1')
            vec[0] = 1;
        else
            vec[0] = 0;
        forr(i, 1, n)
        {
            if (seq[i] == '1')
                vec[i] = vec[i - 1] + 1;
            else
                vec[i] = 0;
        }
        lli c = 0;
        frange(i, n)
        {
            if (seq[i] == '1')
                c++;
            else
                break;
        }
        lli k = *max_element(all(vec));
        if (c + vec[n - 1] <= n)
            k = max(k, c + vec[n - 1]);
        // cout << k << " ";
        if (k == n)
        {
            cout << k * k << "\n";
        }
        else if (k % 2)
        {
            cout << ((k + 1) / 2) * ((k + 1) / 2) << "\n";
        }
        else
        {
            cout << ((k + 2) / 2) * (k / 2) << "\n";
        }
    }
}