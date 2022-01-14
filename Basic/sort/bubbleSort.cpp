// 给你一个n代表有n个数字，然后你需要使用冒泡排序将这些数字从小到大排好。
#include <iostream>
#include <vector>

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

void bubbleSort(std::vector<int> &arr) {
  for (int i = arr.size() - 1; i != 0; --i) {
    for (int j = 0; j < i; ++j) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}

int main(int argc, char *argv[]) {
  std::vector<int> v;
  int n = 0, number = 0;
  std::cin >> n;
  while (n--) {
    std::cin >> number;
    v.push_back(number);
  }
  bubbleSort(v);

  for (int i = 0; i < v.size(); ++i) {
    if (i == 0) {
      std::cout << v[0];
    } else {
      std::cout << " " << v[i];
    }
  }
  std::cout << std::endl;
  return 0;
}