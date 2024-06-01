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

struct Data {
    int id;
    lli tot, k;
    vll val;

    bool operator<(Data &other) const {
        return tot * other.k < other.tot * k;
    }

    bool operator>(Data &other) const {
        return tot * other.k > other.tot * k;
    }

    ld avg() {
        return ld(tot)/ld(k);
    }
};

int bin1(Data val, vector<Data> &vec) {
    int lo = 0;
    int hi = (int)vec.size()-1;

    while(lo != hi) {
        int mid = (lo+hi)/2;
        if(val > vec[mid]) hi = mid;
        else lo = mid+1;
    }
    return lo;
}

int bin2(Data val, vector<Data> &vec) {
    int lo = 0;
    int hi = (int)vec.size()-1;
    while(lo != hi) {
        int mid = (lo+hi+1)/2;
        if(!(vec[mid]<val)) lo = mid;
        else hi = mid-1;
    }
    return lo;
}

int main() {
    // usaco();
    int t;
    scd(t);

    frange(_, t) {
        int n, m;
        scd(n);
        scd(m);
        vi vec(n);
        frange(i, n) scd(vec[i]);
        sort(all(vec), greater<>());

        vector<Data> stud(m);
        int id = 0;
        frange(i, m) {
            sclld(stud[i].k);
            stud[i].id = id;
            id+=stud[i].k;
            frange(j, stud[i].k) {
                lli v;
                sclld(v);
                stud[i].val.pb(v);
                stud[i].tot += v;
            }
        }

        sort(all(stud), greater<>());
        vi pref(m+1), prefb(m+1), prefa(m+1);
        forr(i, 1, m+1) {
            pref[i] = pref[i-1] + (stud[i-1].avg() <= vec[i-1]);
            if(i>1) prefb[i] = prefb[i-1] + (stud[i-1].avg() <= vec[i-2]);
            if(i<m) prefa[i] = prefa[i-1] + (stud[i-1].avg() <= vec[i]); 
        }

        string ans;
        frange(i, id) ans += '0';

        frange(i, m) {
            auto p = stud[i];
            int id = p.id;
            for(auto e : p.val) {
                Data tmp;
                tmp.tot = p.tot - e;
                tmp.k = p.k-1;
                int out = 1;
                if(tmp > p) {
                    int id = bin1(tmp, stud);
                    // printf("g: %d\n", id);
                    
                    if(tmp.avg() > vec[id]) out = 0;
                    if(pref[id]!=id) out = 0;
                    if(pref[m]-pref[i+1]!=m-i-1) out = 0;
                    if(prefa[i]-prefa[id] != i-id) out = 0;
                }
                else {
                    int id = bin2(tmp, stud);
                    // printf("l: %d\n", id);
                    if(tmp.avg() > vec[id]) out = 0;
                    if(pref[i]!=i) out = 0;
                    if(pref[m]-pref[id+1]!=m-id-1) out = 0;
                    if(prefb[id+1]-prefb[i+1] != id-i) out = 0;
                }
                ans[id] = char('0'+out);
                id++;
            }
        }
        cout<<ans;
        printf("\n");


    }
}