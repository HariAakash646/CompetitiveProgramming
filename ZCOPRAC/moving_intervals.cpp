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
    int t;
    scd(t);

    frange(_, t) {
        int c, n, k;
        scd(c);
        scd(n);
        scd(k);

        vii rang(n);
        vii vec;
        vii pos(n, mp(-1, -1));

        frange(i, n) {
            scd(rang[i].f);
            scd(rang[i].s);
            vec.pb(mp(rang[i].f, i));
            vec.pb(mp(rang[i].s, i));
        }

        sort(all(vec));

        frange(i, vec.size()) {
            auto p = vec[i];
            if(pos[p.s].f == -1) {
                pos[p.s].f = i;
            }
            else {
                pos[p.s].s = i;
            }
        }

        pair<pii, pii> inter = mp(mp(-1, -1), mp(-1, -1));

        bool done = true;
        frange(i, n) {
            
            seti st;
            if(pos[i].f != pos[i].s-1) {
                forr(j, pos[i].f+1, pos[i].s) {
                    st.insert(vec[j].s);
                }
            }
            for(int j=pos[i].f-1; j>=0; j--) {
                if(vec[j].f == vec[pos[i].f].f) st.insert(vec[j].s);
                else break;
            }
            for(int j=pos[i].s+1; j<vec.size(); j++) {
                if(vec[j].f == vec[pos[i].s].f) st.insert(vec[j].s);
                else break;
            }
            if(st.size() == 0) continue;
            if(inter.f.f != -1) {
                if(inter.f.s > 1) {
                    if(st.size() > 1) {
                        done = false;
                        break;
                    }
                    else {
                        if(*st.begin() == inter.f.f) continue;
                        else {
                            done = false;
                            break;
                        }
                    }
                }
                else {
                    if(st.size() > 1) {
                        if(st.find(inter.f.f) != st.end()) {
                            inter.f.f = i;
                            inter.f.s = st.size();
                        }
                        else {
                            done = false;
                            break;
                        }
                    }
                    else {
                        if(*st.begin() == inter.f.f) {
                            inter.s = mp(i, 1);
                        }
                        else {
                            done = false;
                            break;
                        }
                    }
                }
            }
            else {
                inter.f = mp(i, st.size());
            }
        }
        // printf("%d %d %d %d\n", inter.f.f, inter.f.s, inter.s.f, inter.s.s);
        if(k == 0) {
            if(inter.f.f != -1) {
                printf("Bad\n");
            }
            else printf("Good\n");
        }
        else {
            if(!done) {
                printf("Bad\n");
            }
            else {
                multiset<pii> st;
                for(auto p : rang) st.insert(p);
                bool w = false;
                if(inter.f.f != -1) {
                    auto e = rang[inter.f.f];
                    st.erase(st.find(rang[inter.f.f]));
                    int curr = 1;
                    for(auto p : st) {
                        if(p.f - curr >= e.s - e.f + 1) {
                            w = true;
                            break;
                        }
                        curr = max(curr, p.s+1);
                    }
                    if(c - curr + 1 >= e.s - e.f + 1) w = true;
                    st.insert(e);
                    if(inter.f.s == 1) {
                        
                        int v = vec[pos[inter.f.f].f+1].s;
                        auto e = rang[v];
                        st.erase(st.find(rang[v]));
                        int curr = 1;
                        for(auto p : st) {
                            if(p.f - curr >= e.s - e.f + 1) {
                                w = true;
                                break;
                            }
                            curr = max(curr, p.s+1);
                        }
                        if(c - curr + 1 >= e.s - e.f + 1) w = true;
                        st.insert(e);
                    }
                }
                if(inter.s.f != -1) {
                    auto e = rang[inter.s.f];
                    st.erase(st.find(rang[inter.s.f]));
                    int curr = 1;
                    for(auto p : st) {
                        if(p.f - curr >= e.s - e.f + 1) {
                            w = true;
                            break;
                        }
                        curr = max(curr, p.s+1);
                    }
                    if(c - curr + 1 >= e.s - e.f + 1) w = true;
                }

                if(w) printf("Good\n");
                else printf("Bad\n");
            }
        }

    }
}