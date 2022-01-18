/**
牛牛今天带来了一排气球，气球有n个，然后每一个气球里面都包含一个数字，牛牛是一个善于思考的人,于是他就想到了一个问题，
牛牛随便给你一个值K，这个值在这些气球中不一定存在，聪明的你需要把气球中包含的数字是小于K的放到这排气球的左边，大于K的放到气球的右边，
等于K的放到这排气球的中间，最终返回一个整数数组，其中只有两个值，分别是气球中包含的数字等于K的部分的左右两个下标值,如果气球中没有K这个数字就输出-1，-1。
**/

#include <iostream>
#include <vector>

std::vector<int> partition(std::vector<int> &arr, int key);
void swap(int &, int &);

int main(int argc, char *argv[]) {
  int n = 0, number = 0, k = 0;
  std::vector<int> vInput;
  std::cin >> n >> k;
  while (n--) {
    std::cin >> number;
    vInput.push_back(number);
  }

  std::vector<int> ans = partition(vInput, k);
  std::cout << ans[0] << " " << ans[1] << std::endl;
  return 0;
}

std::vector<int> partition(std::vector<int> &arr, int key) {
  int less = 0 - 1;
  int more = arr.size();

  int index = 0;
  while (index < more) {
    if (arr[index] < key) {
      swap(arr[++less], arr[index++]);
    } else if (arr[index] > key) {
      swap(arr[--more], arr[index]);
    } else {
      index++;
    }
  }

  std::vector<int> ans;
  if (less + 1 == more) {
    ans.push_back(-1);
    ans.push_back(-1);
  } else {
    ans.push_back(less + 1);
    ans.push_back(more - 1);
  }
  return ans;
}

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}