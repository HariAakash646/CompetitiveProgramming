#include <bits/stdc++.h>
using namespace std;

// Define the number of runs for the test data
// generated
#define RUN 5

// Define the maximum number of vertices of the graph
#define mv 10

// Define the maximum number of edges
#define me 10

#define mq 10

int main()
{
    srand(time(0));
    int n = 2 + rand() % mv;
    int m = n - 1 + rand() % min(me, n * (n - 1) / 2);
    int q = 1 + rand() % min(m, mq);
    printf("%d %d %d\n", n, m, q);
    set<pair<int, int>> edges;
    for (int i = 2; i <= n; i++)
    {
        int par = 1 + rand() % (i - 1);
        edges.insert(make_pair(min(i, par), max(i, par)));
    }
    while (edges.size() < m)
    {
        int x = 1 + rand() % n, y = 1 + rand() % n;
        if (x == y)
            continue;
        edges.insert({min(x, y), max(x, y)});
    }
    // shuffle(edges.begin(), edges.end());
    // for (int i = 0; i < edges.size(); i++)
    // {
    //     int x = rnd.next(1, 2);
    //     if (x == 2)
    //         swap(edges[i][0], edges[i][1]);
    //     // cout << edges[i][0] << " " << edges[i][1] << "\n";
    // }
    for (auto p : edges)
    {
        printf("%d %d\n", p.first, p.second);
    }
    set<int> quer;
    while (quer.size() < q)
    {
        int x = 1 + rand() % m;
        quer.insert(x);
    }
    for (auto e : quer)
        printf("%d\n", e);
    return (0);
}