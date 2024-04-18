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
    int n;

    string str;
    cin >> str;

    n = str.size();

    map<char, int> pq;

    vi cnt(26);
    for(auto e : str) {
        cnt[e-'A']++;
        pq[e]++;
    }
    int ma = *max_element(all(cnt));
    if(ma > (n+1)/2) {
        printf("-1");
        return 0;
    }
    int l = n;
    mseti st;
    for(auto e : cnt) st.insert(e);
    string out = "";
    char pre = ' ';
    while(pq.size() && *prev(st.end()) <= l/2) {
        auto c = (*pq.begin()).f;
        if(c == pre) {
            c = (*next(pq.begin())).f;
        }
        out += c;
        st.erase(st.find(cnt[c-'A']));
        cnt[c-'A']--;
        st.insert(cnt[c-'A']);
        pq[c]--;
        if(pq[c] == 0) pq.erase(c);
        pre = c;
        l--;
    }

    if(pq.size()) {
        priority_queue<char, vector<char>, greater<char>> pq2;
        pii ma = {0, 0};
        frange(i, 26) {
            ma = max(ma, mp(cnt[i], i));
        }
        char ch = ma.s + 'A';
        // while(pq.size()) {
        //     auto c = pq.top();
        //     pq.pop();
        //     if(c != ch) pq2.push(c);

        // }
        for(auto p : pq) {
            if(p.f != ch) {
                frange(i, p.s) pq2.push(p.f);
            }
        }
        while(pq2.size()) {
            out += ch;
            auto c = pq2.top();
            pq2.pop();
            out += c;
        }
        out += ch;
    }
    cout << out;
}