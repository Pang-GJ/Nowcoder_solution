// 给定一个数字arr，其中只有两个数字出现了奇数次，其它数字都出现了偶数次，按照从小到大顺序输出这两个数。
#include <algorithm>
#include <iostream>
#include <vector>

void findTwoOdd(std::vector<int> &arr, std::vector<int> &ans) {
  int eor = 0;
  for (auto i : arr) {
    eor = eor ^ i;
  }
  // eor = a ^ b
  // eor != 0
  // 所以 eor 的二进制上肯定有位置是1

  // 找到 eor 二进制上最右位置的1
  int rightOne = eor & (~eor + 1);  // rightOne 只有一个位置是1，其他是0
  int eor_ = 0;
  for (auto i : arr) {
    if ((i & rightOne) != 0) {
      eor_ = i ^ eor_;
    }
  }
  ans.push_back(eor_);
  ans.push_back(eor_ ^ eor);
}

int main(int argc, char *argv[]) {
  int n = 0, number = 0;
  std::vector<int> vInt;
  std::cin >> n;
  while (n--) {
    std::cin >> number;
    vInt.push_back(number);
  }

  std::vector<int> ans;
  findTwoOdd(vInt, ans);

  std::cout << std::min(ans[0], ans[1]) << " " << std::max(ans[0], ans[1])
            << std::endl;

  return 0;
}