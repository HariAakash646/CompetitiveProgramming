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
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<lli> vll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
int cp;
string bin(int n, int sz)
{
    string out = "";
    while (n > 0)
    {
        out += to_string(n % 2);
        if (n % 2)
        {
            cp++;
        }
        n /= 2;
    }
    while (out.size() < sz)
        out += "0";
    reverse(all(out));
    return out;
}

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        int n, k;
        cin >> n >> k;
        string str, str1;
        cin >> str;
        cin >> str1;
        seti let;
        frange(i, n)
        {
            let.insert(str[i]);
        }
        vi sv(all(let));
        // for (auto e : sv)
        //     printf("%d ", e);
        vi vec(26, -1);
        int sz = sv.size();

        frange(i, sz)
        {
            vec[sv[i] - 'a'] = i;
        }
        // for (auto e : vec)
        //     printf("%d ", e);
        lli tot = 0;
        frange(i, 1 << sz)
        {
            cp = 0;
            string bina = bin(i, sz);
            if (cp > k)
                continue;
            lli curr = 0;
            lli len = 0;
            frange(j, n)
            {
                bool eq = false;
                if (vec[str[j] - 'a'] != -1 && bina[vec[str[j] - 'a']] == '1')
                {
                    eq = true;
                    len++;
                }
                else if (str[j] == str1[j])
                {
                    eq = true;
                    len++;
                }
                else
                {
                    if (len > 0)
                        curr += (len * (len - 1)) / 2 + len;
                    len = 0;
                }
            }
            if (len > 0)
            {
                curr += (len * (len - 1)) / 2 + len;
            }
            tot = max(tot, curr);
        }
        printf("%lld\n", tot);
    }
}