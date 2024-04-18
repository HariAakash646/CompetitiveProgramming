#include <bits/stdc++.h>
#include "artswap.h"

using namespace std;

void usaco() {
	freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

static int N, S, Q, current_G[50005], initial_G[50005], answer_G[50005], queries = 0;
static long long E;

long long compute_engagement(){
	E = 0;
	for (int i = 1; i < N; ++i){
		for (int j = i+1; j <= N; ++j){
			if (current_G[i] > current_G[j]) E++;
		}
	}
	return E;
}

long long swap_pieces(int X, int Y){
	queries++;
	if (queries > Q){
		cout << "Wrong Answer\nToo many swaps made\n";
		exit(0);
	}
	if (X < 0 || X > N || Y < 0 || Y > N || X == Y){
		cout << "Wrong Answer\nInvalid swap attempted\n";
		exit(0);
	}
	int Xidx, Yidx;
	for (int idx = 1; idx <= N; ++idx){
		if (current_G[idx] == X) Xidx = idx;
		if (current_G[idx] == Y) Yidx = idx;
	}
	swap(current_G[Xidx],current_G[Yidx]);
	return compute_engagement();
}

void answer(int P, int G){
	if (answer_G[P] != 0){
		cout << "Wrong Answer\nInvalid answer attempted\n";
		exit(0);
	}
	printf("%d %d\n", P, G);
	answer_G[P] = G;
}

int main(){
	usaco();
	// ios_base::sync_with_stdio(false);
	// cin.tie(0);
	cin >> N >> S >> Q;

	for (int i = 1; i <= N; ++i){
		cin >> current_G[i];
		initial_G[i] = current_G[i];
	}
	E = compute_engagement();

	artswap(N,E,S,Q);

	for (int i = 1; i <= N; ++i){
		if (answer_G[i] != initial_G[i]){
			cout << "Wrong Answer\nAnswer arrangement not equal to original\n";
			exit(0);
		}
		if (current_G[i] != initial_G[i]){
			cout << "Wrong Answer\nFinal arrangement not equal to origina\n"; 
			exit(0);
		}
	}

	cout << "Accepted\n";
	cout << "Queries Used: " << queries << '\n';
}