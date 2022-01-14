// 给你一个n代表有n个数字，然后你需要使用选择排序将这些数字从小到大排好。
#include <iostream>
#include <vector>

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

void selectSort(std::vector<int> &arr) {
  int minIndex = 0, len = arr.size();
  for (int i = 0; i < len; ++i) {
     minIndex = i;
     for (int j = i; j < len; ++j) {
       if (arr[j] < arr[minIndex]) {
         minIndex = j;
       }
     }
     swap(arr[i], arr[minIndex]);
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
  selectSort(v);

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