#include "supertrees.h"
#include <vector>

int construct(std::vector<std::vector<int>> p) {
	int n = p.size();
	std::vector<std::vector<int>> answer;
	for (int i = 0; i < n; i++) {
		std::vector<int> row;
		row.resize(n);
		answer.push_back(row);
	}
	frange(i, n) {
		if(p[i][i] != 1) return 0;
		frange(j, n) {
			if(p[i][j] != p[j][i]) return 0;
		}
	}
	vvi cyc;
	vi pos(n, -1);
	frange(i, n) {
		int id = -1;
		frange(j, i) {
			if(p[i][j] == 2) id = pos[j];
		}
	}
	build(answer);
	return 1;
}
