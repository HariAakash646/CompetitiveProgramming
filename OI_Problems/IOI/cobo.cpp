#include <bits/stdc++.h>
#include "combo.h"

using namespace std;

#define scd(t) scanf("%d", &t)
#define scld(t) scanf("%ld", &t)
#define sclld(t) scanf("%lld", &t)
#define scc(t) scanf("%c", &t)
#define scs(t) scanf("%s", t)
#define scf(t) scanf("%f", &t)
#define sclf(t) scanf("%lf", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;
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

// namespace {

// constexpr int MAX_N = 2000;
// constexpr int MAX_NUM_MOVES = 8000;

// int N;
// std::string S;

// int num_moves;

// void wrong_answer(const char *MSG) {
//   printf("Wrong Answer: %s\n", MSG);
//   exit(0);
// }

// }  // namespace

// int press(std::string p) {
//   if (++num_moves > MAX_NUM_MOVES) {
//     wrong_answer("too many moves");
//   }
//   int len = p.length();
//   if (len > 4 * N) {
//     wrong_answer("invalid press");
//   }
//   for (int i = 0; i < len; ++i) {
//     if (p[i] != 'A' && p[i] != 'B' && p[i] != 'X' && p[i] != 'Y') {
//       wrong_answer("invalid press");
//     }
//   }
//   int coins = 0;
//   for (int i = 0, j = 0; i < len; ++i) {
//     if (j < N && S[j] == p[i]) {
//       ++j;
//     } else if (S[0] == p[i]) {
//       j = 1;
//     } else {
//       j = 0;
//     }
//     coins = std::max(coins, j);
//   }
//   return coins;
// }


string guess_sequence(int n) {
	string conf = "";

	string check = "AB";
	string fi;
	if(press(check)) {
		check = "A";
		if(press(check)) fi = "A";
		else fi = "B";
	} 
	else {
		check = "X";
		if(press(check)) fi = "X";
		else fi = "Y";
	}
	conf += fi;
	string c1, c2, c3;

	if(fi == "A") {
		c1 = "B";
		c2 = "X";
		c3 = "Y";
	}
	else if(fi == "B") {
		c1 = "A";
		c2 = "X";
		c3 = "Y";
	}
	else if(fi == "X") {
		c1 = "A";
		c2 = "B";
		c3 = "Y";
	}
	else if(fi == "Y") {
		c1 = "A";
		c2 = "B";
		c3 = "X";
	}
	if(n == 1) return fi;
	forr(i, 1, n-1) {
		check = conf;
		check += c1;
		check += conf + c2 + c1;
		check += conf + c2 + c2;
		check += conf + c2 + c3;

		int p = press(check);
		if(p == i) {
			conf += c3;
		}
		else if(p == i+1) {
			conf += c1;
		}
		else {
			conf += c2;
		}
	}
	if(press(conf + c1)==n) {
		conf += c1;
	}
	else if(press(conf + c2)==n) {
		conf += c2;
	} 
	else conf += c3;

	return conf;
}

// int main() {
// 	usaco();
//   char buffer[MAX_N + 1];
//   if (scanf("%s", buffer) != 1) {
//     fprintf(stderr, "Error while reading input\n");
//     exit(1);
//   }
//   S = buffer;
//   N = S.length();

//   num_moves = 0;
//   std::string answer = guess_sequence(N);
//   if (answer != S) {
//     wrong_answer("wrong guess");
//     exit(0);
//   }
//   printf("Accepted: %d\n", num_moves);
//   return 0;
// }