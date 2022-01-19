// 输入整型数组和排序标识，对其元素按照升序或降序进行排序
// 第一行输入数组元素个数
// 第二行输入待排序的数组，每个数用空格隔开
// 第三行输入一个整数0或1。0代表升序排序，1代表降序排序
#include <ctime>
#include <iostream>
#include <vector>

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

std::vector<int> partition(std::vector<int> &arr, int L, int R, int key,
                           int flag) {
  int left = L - 1;  // 左边界
  int right = R;     // 有边界
  int index = L;

  if (!flag) {  // 升序
    while (index < right) {
      if (arr[index] < key) {
        swap(arr[++left], arr[index++]);
      } else if (arr[index] > key) {
        swap(arr[--right], arr[index]);
      } else {
        ++index;
      }
    }

  } else {  // 降序
    while (index < right) {
      if (arr[index] < key) {
        swap(arr[--right], arr[index]);
      } else if (arr[index] >key) {
        swap(arr[++left], arr[index++]);
      } else {
        ++index;
      }
    }
  }
  swap(arr[right], arr[R]);
  std::vector<int> res;
  res.push_back(left + 1);
  res.push_back(right);
  return res;
}

void quickSort(std::vector<int> &arr, int L, int R, int flag) {
  if (L >= R) {
    return;
  }
  if (arr.size() < 2) {
    return;
  }

  int randomIndex = rand() % (R - L + 1) + L;
  swap(arr[randomIndex], arr[R]);
  std::vector<int> res = partition(arr, L, R, arr[R], flag);
  quickSort(arr, L, res[0] - 1, flag);
  quickSort(arr, res[1] + 1, R, flag);
}

int main(int argc, char *argv[]) {
  // 处理输入
  int n = 0, number = 0, flag = 0;
  std::cin >> n;
  std::vector<int> vInt;
  while (n--) {
    std::cin >> number;
    vInt.push_back(number);
  }
  std::cin >> flag;

  // 快速排序
  quickSort(vInt, 0, vInt.size() - 1, flag);

  // 处理输出
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