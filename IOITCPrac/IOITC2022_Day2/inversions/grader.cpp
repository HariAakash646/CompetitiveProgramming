#include <bits/stdc++.h>
using namespace std;

void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

namespace{
    int steps, Q;
    vector<int> F;
    const int MAX = 1000000000;
    // 0-indexed
    template<class T>
    struct BIT{
        int n;
        vector<T> F;
        BIT(){}
        BIT(int n) : n(n), F(n + 1){};
        void init(){
            fill(all(F), 0);
        }
        void add(int i, T w){
            i++;
            for(; i <= n; i += (i & (-i))) F[i] += w;
        }
        T get(int i){
            i++;
            T ret = 0;
            for(; i; i -=(i & (-i))) ret += F[i];
            return ret;
        }
        T get(int i, int j){ return get(j) - get(i - 1);}
        int getKth(T k){
            int p = 0;
            for(int i = __lg(n); i >= 0; i--){
                T v = p + (1 << i) > n ? k + 1 : F[p + (1 << i)];
                if(v < k){
                    k -= v;
                    p += 1 << i;
                }
            }
            return p;
        }
    };
    inline void ensure(bool x, string err = ""){
        if(!x){
            cerr << err << endl;
            exit(0);
        }
    }
}

int put(int i){
    steps++; 
    if(steps > Q) 
        ensure(false, "Query Limit Exceeded!");
    ensure(i >= 0 && i <= MAX, "put: any value appended to F must be in [0, 10^9]!");
    F.push_back(i);
    return F.size() - 1;
}

int add(int i, int j){
    steps++;
    if(steps > Q)
        ensure(false, "Query Limit Exceeded!");
    ensure(min(i, j) >= 0 && max(i, j) < (int)F.size(), "add: index out of bounds!");
    ensure(F[i] + F[j] <= MAX, "add: any value appended to F must be in [0, 10^9]!");
    F.push_back(F[i] + F[j]);
    return F.size() - 1;
}

int subtract(int i, int j){
    steps++;
    if(steps > Q)
        ensure(false, "Query Limit Exceeded!");
    ensure(min(i, j) >= 0 && max(i, j) < (int)F.size(), "subtract: index out of bounds!");
    ensure(F[i] >= F[j], "subtract: any value appended to F must be in [0, 10^9]!");
    F.push_back(F[i] - F[j]);
    printf("%d %d %d\n", F[i], F[j], F.back());
    return F.size() - 1;
}

int multiply(int i, int j){
    steps++; 
    if(steps > Q)
        ensure(false, "Query Limit Exceeded!");
    ensure(min(i, j) >= 0 && max(i, j) < (int)F.size(), "multiply: index out of bounds!");
    ensure(F[i] * (long long) F[j] <= MAX, "multiply: any value appended to F must be in [0, 10^9]!");
    F.push_back(F[i] * F[j]);
    // cout << F[i] * F[j] << "\n";
    return F.size() - 1;
}

int exclusive_or(int i, int j){
    steps++;
    if(steps > Q)
        ensure(false, "Query Limit Exceeded!");
    ensure(min(i, j) >= 0 && max(i, j) < (int)F.size(), "exclusive_or: index out of bounds!");
    ensure((F[i] ^ F[j]) <= MAX, "exclusive_or: any value appended to F must be in [0, 10^9]!");
    F.push_back(F[i] ^ F[j]);
    return F.size() - 1;
}

int compare(int i, int j){
    steps++;
    if(steps > Q)
        ensure(false, "Query Limit Exceeded!");
    ensure(min(i, j) >= 0 && max(i, j) < (int)F.size(), "compare: index out of bounds!");
    F.push_back(F[i] < F[j] ? 1 : 0);
    return F.size() - 1;
}

int compose(int i){
    steps++;
    if(steps > Q) 
        ensure(false, "Query Limit Exceeded!");
    ensure(i >= 0 && i < (int)F.size(), "compose: index out of bounds!");
    ensure(F[i] < (int)F.size(), "compose: index out of bounds!");
    F.push_back(F[F[i]]);
    return F.size() - 1;
}

void solve(int n);

int main(){
    usaco();
    int n; cin >> n >> Q;
    F.resize(n);
    int inversions = 0;
    BIT<int> B(n + 1);
    for(int i = 0; i < n; i++){
        cin >> F[i];
        inversions += i - B.get(F[i]);
        B.add(F[i], 1);
    }
    solve(n);
    if(F.back() != inversions){
        cerr << "Incorrect Output!" << endl;
        cerr << "Expected: " << inversions << endl;
        cerr << "Got: " << F.back() << endl;
        cout << 0 << endl;
        return 0;
    }
    const string password = "#wd#$!K";
    cerr << "Correct output!" << endl;
    cerr << "# of function calls: " << steps << endl;
}