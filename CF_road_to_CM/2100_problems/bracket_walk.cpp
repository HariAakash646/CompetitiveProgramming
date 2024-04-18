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


void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

int main() {
    // usaco();
    int n, q;
    scd(n);
    scd(q);
    if(n % 2) {
        frange(_, q) printf("NO\n");
        return 0;
    }
    string str;
    cin >> str;

    seti st;
    frange(i, n) {
        if(i % 2 == 1 && str[i] == '(') st.insert(i);
        if(i % 2 == 0 && str[i] == ')') st.insert(i);
    }

    frange(_, q) {
        int id;
        scd(id);
        id--;
        if(st.find(id) != st.end()) st.erase(id);
        else st.insert(id);
        if(st.size() && (*st.begin() % 2 == 0 || *prev(st.end()) % 2 == 1)) printf("NO\n");
        else printf("YES\n");
    }

}