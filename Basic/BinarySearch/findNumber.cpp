// 给你一个n代表有一个长度为n的有序数组，然后给你一个k，你需要判断这个k是否在数组里面，
// 如果存在就返回这个数从左往右第一次出现位置的下标，如果不存在输出-1
#include <iostream>
#include <vector>

int findNumber(std::vector<int> v, int k);

int main(int argc, char *argv[]) {
  int ans = 0, n = 0, number = 0, k = 0;
  std::vector<int> v;
  std::cin >> n;
  std::cin >> k;

  while (n--) {
    std::cin >> number;
    v.push_back(number);
  }

  ans = findNumber(v, k);
  std::cout << ans << std::endl;
  return 0;
}

int findNumber(std::vector<int> v, int k) {
  int mid = 0, left = 0, right = v.size() - 1;
  int flag = -1, index = 0;

  while (left <= right) {
    mid = (left + right) / 2;
    if (v[mid] == k) {
      index = mid;
      flag = 1;
      break;
    } else if (v[mid] < k) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  // 需要找到从左往右第一个出现 k 的位置，
  // 确认 ans 左边是否还有 k
  int j = index;
  while (v[j] == k && j >= 0) {
    index = j;
    j--;
  }

  if (flag == -1) {
    return -1;
  } else {
    return index;
  }
}