// 给你一个n代表有n个数字，然后你需要使用快速排序将这些数字从小到大排好
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

inline int random(int L, int R) { return rand() % (R - L + 1) + L; }

void swap(int &numA, int &numB) {
  int temp = numA;
  numA = numB;
  numB = temp;
}

std::vector<int> partition(std::vector<int> &arr, int L, int R, int key) {
  int less = L - 1;
  int more = R;

  int index = L;
  while (index < more) {
    if (arr[index] < key) {
      swap(arr[++less], arr[index++]);
    } else if (arr[index] > key) {
      swap(arr[--more], arr[index]);
    } else {
      ++index;
    }
  }

  std::vector<int> result;
  result.push_back(less + 1);
  swap(arr[more], arr[R]);
  result.push_back(more);
  return result;
}

void quickSort(std::vector<int> &arr, int L, int R) {
  if (L >= R) {
    return;
  }

  if (arr.size() < 2) {
    return;
  }

  int randomIndex = random(L, R);
  swap(arr[randomIndex], arr[R]);
  std::vector<int> res = partition(arr, L, R, arr[R]);
  quickSort(arr, L, res[0] - 1);
  quickSort(arr, res[1] + 1, R);
}

int main(int argc, char *argv[]) {
  srand((unsigned)time(NULL));

  int n = 0, number = 0;
  std::cin >> n;
  std::vector<int> vInt;
  while (n--) {
    std::cin >> number;
    vInt.push_back(number);
  }

  quickSort(vInt, 0, vInt.size() - 1);
  // 排好序，输出
  for (int i = 0; i < vInt.size(); ++i) {
    if (i == 0) {
      std::cout << vInt[i];
    } else {
      std::cout << " " << vInt[i];
    }
  }
  std::cout << std::endl;
  return 0;
}