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
    int a, b, c, id;

    bool operator<(Data &other) const {
        return min(b-a, b-c) < min(other.b-other.a, other.b-other.c);
    }
};

int main() {
    usaco();
    int t;
    scd(t);

    frange(_, t) {
        int n;
        scd(n);
        vi vec(n);
        frange(i, n) {
            scd(vec[i]);
        }
        pii ma = mp(0, 0);
        for(int i=0; i<n; i++) {
            ma = max(ma, mp(vec[i], i));
        }

        seti st1, st2;
        forr(i, 1, n/2+1) st1.insert(i);
        forr(i, n/2+1, n+1) st2.insert(i);

        int id = ma.s%2;
        if(id == 0) id =2;
        vector<Data> val;
        for(int i=id; i<n-1; i+=2) {
            Data tmp;
            tmp.a = vec[i-1];
            tmp.b = vec[i];
            tmp.c = vec[i+1];
            tmp.id = i;
            val.pb(tmp);
        }
        sort(all(val));
        vi out(n);
        for(auto p : val) {
            int id = p.id;
            if(out[id-1] && out[id+1]) {
                int v = max(vec[id-1] + out[id-1], vec[id+1]+out[id+1]);
                auto it = st2.upper_bound(v-vec[id]);
                out[p.id] = *it;
                st2.erase(it);
            }
            else  {
                
                
                int lo = *st2.begin();
                int hi = *prev(st2.end());
                while(lo != hi) {
                    int mid = (lo+hi)/2;
                    auto it = st1.begin();
                    if(out[id-1]) {
                        int v = out[id-1] + vec[id-1];
                        if(v >= mid) {lo = mid+1;continue;}
                    }
                    else {
                        int v = vec[id]+mid-vec[id-1];
                        it = st1.lower_bound(v);
                        if(it == st1.begin()) {lo=mid+1; continue;}

                    }


                    if(out[id+1]) {
                        int v = out[id+1] + vec[id+1];
                        if(v >= mid) {lo = mid+1;continue;}
                    }
                    else {
                        int v = vec[id]+mid-vec[id+1];
                        auto it2 = st1.lower_bound(v);
                        if(it2 == st1.begin()) {lo=mid+1; continue;}
                        it2--;
                        it--;
                        if(it2==it && it==st1.begin()) {lo=mid+1; continue;}
                    }
                    hi = mid;

                }
                // if(!out[id-1]) {
                //     it = prev(st1.lower_bound(vec[id]+out[id]-vec[id-1]));
                //     out[id-1] = *it;
                //     st1.erase(it);
                // } 
                // if(!out[id+1]) {
                //     it = prev(st1.lower_bound(vec[id]+out[id]-vec[id+1]));
                //     out[id+1] = *it;
                //     st1.erase(it);
                // }
            }
        }
        for(auto e : st2) st1.insert(e);
        forr(i, 0, n) {
            if(!out[i]) {
                out[i] = *st1.begin();
                st1.erase(st1.begin());
            }
        }
        // st2.erase(st2.begin());

        for(auto e : out) printf("%d ", e);
        printf("\n");


    }
}