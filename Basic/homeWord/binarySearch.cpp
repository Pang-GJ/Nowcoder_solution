// 请实现有重复数字的有序数组的二分查找。
// 输出在数组中第一个大于等于查找值的位置，如果数组中不存在这样的数，则输出数组长度加1。
#include <iostream>
#include <vector>

int binarySearch(std::vector<int> &vInt, int key);

int main(int argc, char *argv[]) {
  int n = 0, v = 0, number = 0;
  std::vector<int> vInt;
  std::cin >> n >> v;
  while (n--) {
    std::cin >> number;
    vInt.push_back(number);
  } 
  
  int ans = binarySearch(vInt, v);
  std::cout << ans << std::endl;
  return 0;
}

int binarySearch(std::vector<int> &vInt, int key) {
  int left = 0, right = vInt.size() - 1;
  int index = 0, flag = 0;
  while (left <= right) {
    int mid = left + ((right - left) >> 1);
    if (vInt[mid] >= key) {
      right = mid - 1;
      index = mid;
      flag = 1;
    } else {
      left = mid + 1;
    }
  }

  if (flag) {
    return index;
  } else {
    return vInt.size() + 1;
  }
}