#include <iostream>
#include <vector>
using namespace std;
;

class Solution {
 public:
  bool Find(int target, vector<vector<int> > array) {
    if (!array.size() || !array[0].size()) {
      return false;
    }
    int j = 0, i = array.size() - 1;
    while (i >= 0 && j < array[0].size()) {
      if (array[i][j] == target)
        return true;
      else if (array[i][j] > target)
        i--;
      else
        j++;
    }
    return false;
  }
};

int main(int argc, char *argv[]) { return 0; }