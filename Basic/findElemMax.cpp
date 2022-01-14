// 用递归方法找一个数组中的最大值
#include <iostream>
#include <vector>

int getMax(std::vector<int> &arr);
int process(std::vector<int>::const_iterator beg,
            std::vector<int>::const_iterator end);

int main(int argc, char *argv[]) {
  int n = 0, number = 0;
  std::cin >> n;
  std::vector<int> vInt;
  while (n--) {
    std::cin >> number;
    vInt.push_back(number);
  }

  int max = getMax(vInt);
  std::cout << max << std::endl;

  return 0;
}

int getMax(std::vector<int> &arr) {
  int Max = 0;
  int sz = arr.size();

  if (sz == 0) {
    return -1;
  }
  Max = process(arr.cbegin(), arr.cend());
  return Max;
}

int process(std::vector<int>::const_iterator beg,
            std::vector<int>::const_iterator end) {
  if (beg == end) {
    return *beg;
  }

  // mid = (beg + end) / 2 这样可能会溢出
  // mid = beg + (end - beg) / 2 这样可以避免溢出
  // 使用等价位运算可以加快
  std::vector<int>::const_iterator mid = beg + ((end - beg) >> 1);
  int lMax = process(beg, mid);
  int rMax = process(mid + 1, end);
  return (lMax > rMax ? lMax : rMax);
}