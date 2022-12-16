/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

pair<long long int, long long int> max_adj(vector<long long int> vec) {
    long long int m = 0;
    long long int m2 = 0;
    for(int i = 1; i < vec.size(); i++) {
        if (min(vec[i], vec[i-1]) > m) {
            m = min(vec[i], vec[i-1]);
            m2 = max(vec[i], vec[i-1]);
        }
    }
    return pair<long long int, long long int>(m, m2);
}

int main()
{
    int t;
    scanf("%d", &t);
    long long int prod = 0;
    for(int i = 0; i<t; i++) {
        long long int n;
        scanf("%lld", &n);
        vector<long long int> v(n);
        for(int j = 0; j<n; j++) {
            scanf("%lld", &v[j]);
        }
        pair<long long int, long long int> p = max_adj(v);
        prod = *max_element(v.begin(), v.end()) * p.first;
        printf("%lld\n", prod);
    }
    return 0;
}
