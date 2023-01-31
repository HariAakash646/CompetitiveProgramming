#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define pb push_back
#define f first
#define s second
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long long int lli;

int main()
{
    int n;
    cin >> n;
    vi vec(2 * n + 15, 0);
    forr(i, 1, n + 1)
    {
        cin >> vec[2 * i + 1];
    }
    // for (auto e : vec)
    // {
    //     cout << e << " ";
    // }
    // cout << "\n";
    int idx = 2;
    char prev = 'R';
    while (vec[3] > 0)
    {

        if (prev == 'R')
        {
            if (vec[idx + 1] >= vec[idx - 1])
            {

                cout << 'R';
                vec[idx + 1]--;
                idx += 2;
                prev = 'R';
            }
            else
            {
                vec[idx - 1]--;
                idx -= 2;
                cout << 'L';
                prev = 'L';
            }
        }
        else
        {
            if (vec[idx - 1] >= vec[idx + 1])
            {

                cout << 'L';
                vec[idx - 1]--;
                idx -= 2;
                prev = 'L';
            }
            else
            {
                vec[idx + 1]--;
                idx += 2;
                cout << 'R';
                prev = 'R';
            }
        }
    }
}