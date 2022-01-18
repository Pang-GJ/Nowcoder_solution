// 给你一个n代表有n个数字，然后你需要使用归并排序将这些数字从小到大排好。

#include <iostream>
#include <vector>

class mergeSort {
 public:
  mergeSort(std::vector<int> &v) : arr(v) {}
  void sort();

 private:
  void process(int L, int R);
  void merge(int L, int M, int R);
  std::vector<int> &arr;
};

void mergeSort::sort() { process(0, arr.size() - 1); }

void mergeSort::process(int L, int R) {
  if (L == R) {
    return;
  }
  int mid = L + ((R - L) >> 1);
  process(L, mid);
  process(mid + 1, R);
  merge(L, mid, R);
}

void mergeSort::merge(int L, int M, int R) {
  std::vector<int> temp(R - L + 1);
  int i = 0;
  int p1 = L;
  int p2 = M + 1;
  while (p1 <= M && p2 <= R) {
    temp[i++] = arr[p1] <= arr[p2] ? arr[p1++] : arr[p2++];
  }
  while (p1 <= M) temp[i++] = arr[p1++];

  while (p2 <= R) {
    temp[i++] = arr[p2++];
  }

  for (int j = L, i = 0; j <= R; ++j) {
    arr[j] = temp[i++];
  }
}

int main(int argc, char *argv[]) {
  int n = 0, number = 0;
  std::vector<int> vInt;
  std::cin >> n;
  while (n--) {
    std::cin >> number;
    vInt.push_back(number);
  }

  mergeSort vSort(vInt);
  vSort.sort();

  for (int i = 0; i < vInt.size(); ++i) {
    if (i == 0) {
      std::cout << vInt[i];
    } else {
      std::cout << " " << vInt[i];
    }
  }

  return 0;
}