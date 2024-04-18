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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    cin >> str;
    str = str + "$";
    vi vec(str.size()), out(str.size());
    vii tmp(str.size());
    forr(i, 0, str.size())
    {
        tmp[i] = {str[i], i};
    }
    sort(all(tmp));

    frange(i, str.size()) out[i] = tmp[i].s;
    vec[out[0]] = 0;
    forr(i, 1, tmp.size())
    {
        if (tmp[i].f == tmp[i - 1].f)
        {
            vec[out[i]] = vec[out[i - 1]];
        }
        else
        {
            vec[out[i]] = vec[out[i - 1]] + 1;
        }
    }
    int k = 0;
    while ((1 << k) < str.size())
    {

        vector<pair<pii, int>> tmp(str.size());
        forr(i, 0, str.size())
        {
            tmp[i] = mp(mp(vec[i], vec[(i + (1 << k)) % str.size()]), i);
        }
        sort(all(tmp));

        frange(i, str.size()) out[i] = tmp[i].s;
        vec[out[0]] = 0;
        forr(i, 1, tmp.size())
        {
            if (tmp[i].f == tmp[i - 1].f)
            {
                vec[out[i]] = vec[out[i - 1]];
            }
            else
            {
                vec[out[i]] = vec[out[i - 1]] + 1;
            }
        }
        k++;
    }

    int t;
    cin >> t;
    vector<string> st_tmp(str.size() + 1);
    frange(_, t)
    {
        string str1;
        cin >> str1;
        int x = str1.size();

        int l = 0;
        int h = out.size() - 1;
        bool done = false;
        int idx = -1;
        while (l < h)
        {
            int mid = (l + h + 1) / 2;
            string st = str.substr(out[mid], x);
            // cout << st << " ";
            if (str1 < st)
            {
                h = mid - 1;
            }
            else
            {
                l = mid;
            }
            if (st == str1)
            {
                idx = mid;
                done = true;
                break;
            }
        }
        int c = 0;
        if (done)
        {
            c++;
            int l = idx;
            int h = out.size() - 1;
            int rm = idx + 1;
            while (l < h)
            {
                int mid = (l + h) / 2;
                string st = str.substr(out[mid], x);
                // cout << st << " ";
                if (str1 == st)
                {
                    l = mid + 1;
                }
                else
                {
                    h = mid;
                }
            }
            rm = h;
            int lm = idx;
            l = 0;
            h = idx;
            while (l < h)
            {
                int mid = (l + h + 1) / 2;
                string st = str.substr(out[mid], x);
                // cout << st << " ";
                if (str1 == st)
                {
                    h = mid - 1;
                }
                else
                {
                    l = mid;
                }
            }
            if (str.substr(out[0], x) == str1)
            {
                lm = -1;
            }
            if (str.substr(out[out.size() - 1], x) == str1)
            {
                rm = out.size();
            }
            lm = l;
            c = rm - lm - 1;
        }
        cout << c << "\n";
    }
}