// 给你一个n代表有n个数字，然后你需要使用堆排序将这些数字从小到大排好。
#include <iostream>
#include <vector>

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

class Heap {
  friend void swap(int &a, int &b);

 public:
  explicit Heap(std::vector<int> &v) : arr(v) { heapSize = arr.size(); }
  Heap(std::vector<int> &v, int sz) : arr(v), heapSize(sz) {}

  void heapInsert(int index);
  void heapify(int index);
  int popMax();
  void heapSort();

 private:
  int heapSize;
  std::vector<int> &arr;
};

// 让 arr[0...index] 都是大根堆
void Heap::heapInsert(int index) {
  while (arr[index] > arr[(index - 1) / 2]) {
    swap(arr[index], arr[(index - 1) / 2]);
    index = (index - 1) / 2;
  }
}

void Heap::heapify(int index) {
  int left = 2 * index + 1;  // 左孩子的下标
  while (left < heapSize) {
    // 左右孩子中谁的值大，谁是 largest
    int largest =
        left + 1 < heapSize && arr[left + 1] > arr[left] ? left + 1 : left;
    // 父和较大孩子之间，谁是 largest
    largest = arr[largest] > arr[index] ? largest : index;
    if (largest == index) {
      break;
    } else {
      swap(arr[index], arr[largest]);
      index = largest;
      left = 2 * index + 1;
    }
  }
}

int Heap::popMax() {
  int max = arr[0];

  arr[0] = arr[heapSize - 1];
  heapSize--;
  heapify(0);

  return max;
}

void Heap::heapSort() {
  if (arr.empty() || arr.size() < 2) {
    return;
  }

  for (int i = 0; i < heapSize; ++i) {
    heapInsert(i);
  }
  swap(arr[0], arr[heapSize - 1]);
  --heapSize;
  while (heapSize > 0) {
    heapify(0);
    swap(arr[0], arr[heapSize - 1]);
    --heapSize;
  }
}

int main(int argc, char *argv[]) {
  int n = 0, number = 0;
  std::cin >> n;
  std::vector<int> vInt;
  while (n--) {
    std::cin >> number;
    vInt.push_back(number);
  }

  Heap solution(vInt);
  solution.heapSort();

  for (int i = 0; i < vInt.size(); ++i) {
    if (i == 0) {
      std::cout << vInt[i];
    } else {
      std::cout << " " << vInt[i];
    }
  }
  return 0;
}