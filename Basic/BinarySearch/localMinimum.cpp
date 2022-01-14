/* 定义局部最小的概念。arr长度为1时，arr[0]是局部最小。arr的长度为N(N>1)时，
如果arr[0]< arr[1]，那么arr[0]是局部最小；
如果arr[N-1]<arr[N-2],那么arr[N-1]是局部最小；
如果0<i<N-1，既有arr[i] <arr[i-1]，又有arr[i] < arr[i +
1]，那么arr[i]是局部最小。
给定无序数组arr,已知arr中任意两个相邻的数都不相等，只需要返回arr中任意一个局部最小出现的位置即可，如果不存在这个位置就输出-1。
 */
#include <iostream>
#include <vector>

int findLocalMinimum(std::vector<int> v);

int main(int argc, char *argv[]) {
  int ans = 0, n = 0, number = 0;
  std::vector<int> v;
  std::cin >> n;

  while (n--) {
    std::cin >> number;
    v.push_back(number);
  }

  ans = findLocalMinimum(v);
  std::cout << ans << std::endl;
  return 0;
}

int findLocalMinimum(std::vector<int> v) {
  int len = v.size();
  int mid = 0, left = 0, right = len - 1;
  int flag = -1, index = 0;

  if (len == 1 || v[0] < v[1])
    return 0;
  else if (v[len - 1] < v[len - 2])
    return len - 1;

  while (left <= right) {
    mid = (left + right) / 2;

    if (v[mid] < v[mid + 1] && v[mid] < v[mid - 1]) {
      index = mid;
      flag = 1;
      break;
    } else if (v[mid - 1] < v[mid]) {
      right = mid;
    } else if (v[mid] > v[mid + 1]) {
      left = mid + 1;
    }
  }

  if (flag == -1) {
    return -1;
  } else {
    return index;
  }
}