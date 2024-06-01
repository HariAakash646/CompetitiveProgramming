#include "abc.h"
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

// you may find the definitions useful
const int OP_ZERO    = 0;  // f(OP_ZERO,    x0, x1) = 0
const int OP_NOR     = 1;  // f(OP_NOR,     x0, x1) = !(x0 || x1)
const int OP_GREATER = 2;  // f(OP_GREATER, x0, x1) = (x0 > x1)
const int OP_NOT_X1  = 3;  // f(OP_NOT_X1,  x0, x1) = !x1
const int OP_LESS    = 4;  // f(OP_LESS,    x0, x1) = (x0 < x1)
const int OP_NOT_X0  = 5;  // f(OP_NOT_X0,  x0, x1) = !x0
const int OP_XOR     = 6;  // f(OP_XOR,     x0, x1) = (x0 ^ x1)
const int OP_NAND    = 7;  // f(OP_NAND,    x0, x1) = !(x0 && x1)
const int OP_AND     = 8;  // f(OP_AND,     x0, x1) = (x0 && x1)
const int OP_EQUAL   = 9;  // f(OP_EQUAL,   x0, x1) = (x0 == x1)
const int OP_X0      = 10; // f(OP_X0,      x0, x1) = x0
const int OP_GEQ     = 11; // f(OP_GEQ,     x0, x1) = (x0 >= x1)
const int OP_X1      = 12; // f(OP_X1,      x0, x1) = x1
const int OP_LEQ     = 13; // f(OP_LEQ,     x0, x1) = (x0 <= x1)
const int OP_OR      = 14; // f(OP_OR,      x0, x1) = (x0 || x1)
const int OP_ONE     = 15; // f(OP_ONE,     x0, x1) = 1

const lli mod = 65536;

// Alice
int // returns la
alice(
    /*  in */ const int n,
    /*  in */ const char names[][5],
    /*  in */ const unsigned short numbers[],
    /* out */ bool outputs_alice[]
) {
    frange(i, 16) {
        if(numbers[0] & (1<<i))
            outputs_alice[i] = 1;
        else outputs_alice[i] = 0;
    }
    return 16;
}


// Bob
int // returns lb
bob(
    /*  in */ const int m,
    /*  in */ const char senders[][5],
    /*  in */ const char recipients[][5],
    /* out */ bool outputs_bob[]
) {
    outputs_bob[0] = m;
    return 1;
}

// pii add(int l1, int r1, int l2, int r2, int &operations[], int &operands[][2]) {
//     int id = r2+1;
//     frange(i, 16) {
//         // int p = l1+i;
//         forr(j, 0, 16-i) {
//             operations[id] = 6;
//             operands[id] = {l1+j+i, l2+j};
//             id++;
//         }
//         forr(j, 0, 16-i) {
//             operations[id] = 8;
//             operands[id] = {l1+j+i, l2+j};
//             id++;
//         }
//     }
//     return mp(id-16, id-1);
// }

// Circuit
int // returns l
circuit(
    /*  in */ const int la,
    /*  in */ const int lb,
    /* out */ int operations[],
    /* out */ int operands[][2],
    /* out */ int outputs_circuit[][16]
) {
    operations[la+lb] = 0;
    operands[la+lb][0] = 0; operands[la+lb][1] = 1;
    frange(i, 16) {
        operations[la+lb+i] = 8;
        operands[la+lb+i][0] = i;
        operands[la+lb+i][1] = la;
    }
    for(int j = 0; j < 16; ++j)
        outputs_circuit[0][j] = la+lb+j;
    return la+lb+16;
}
