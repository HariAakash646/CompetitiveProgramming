#include "Bruno.h"

namespace {

int N;
int variable_example = 0;

}  // namespace

void init(int N, int l) {
  ::N = N;
  variable_example++;
}

int bruno(std::string u) {
  variable_example--;
  if(u.size() < 130) return 1;
  else {
    if(u[0] == u[1]) return 1;
    else return 2;
  }
}
