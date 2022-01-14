// 你需要输入一个n，一个数k，然后输入一个长度为n个大小的数组arr，然后你需要在arr上找满足>=K的最左位置，
// 并且输出这个位置，如果不存在这个位置就输出-1。
#include <iostream>
#include <vector>

int findLocation(std::vector<int> v, int k);

int main(int argc, char *argv[]) {
  int ans = 0, n = 0, number = 0, k = 0;
  std::vector<int> v;
  std::cin >> n;
  std::cin >> k;

  while (n--) {
    std::cin >> number;
    v.push_back(number);
  }

  ans = findLocation(v, k);
  std::cout << ans << std::endl;
  return 0;
}

int findLocation(std::vector<int> v, int k) {
  int mid = 0, left = 0, right = v.size() - 1;
  int flag = -1, index = 0;

  while (left <= right) {
    mid = (left + right) / 2;
    if (v[mid] >= k) {
      right = mid - 1;
      flag = 1;
      index = mid;
    } else {
      left = mid + 1;
    }
  }

  if (flag == -1) {
    return -1;
  } else {
    return index;
  }
}