#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    
    vector<pair<int, int>> vec(n);
    int cost;
    for(int i = 0; i < n; i++) {
        scanf("%d", &cost);
        vec[i].second = cost;
    }
    int increase;
    for(int i = 0; i < n; i++) {
        scanf("%d", &increase);
        vec[i].first = increase;
    }
    multimap<int, int> mp(vec.begin(), vec.end());
    int total = 0;
    int c = 0;
    for(auto p = mp.rbegin(); p != mp.rend(); p++) {
        total += p->first * c + p->second;
        c += 1;
    }
    printf("%d", total);
    
    return 0;
}
