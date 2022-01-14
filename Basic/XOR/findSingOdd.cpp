// 一个数组中有一种数出现了奇数次，其他数都出现了偶数次，怎么找到这一个数？
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
  int n = 0, number = 0, eor = 0;
  std::cin >> n;
  std::vector<int> vInt;

  while (n--) {
    std::cin >> number;
    vInt.push_back(number);
  }

  for (auto i : vInt) {
    eor = eor^i;
  }
  std::cout << eor << std::endl;
  return 0;
}