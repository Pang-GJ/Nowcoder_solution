// 对于一个无序数组A，请设计一个算法，求出需要排序的最短子数组的长度。
// 给定一个整数数组A及它的大小n，请返回最短子数组的长度。
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class ShortSubsequence {
public:
    int findShortest(vector<int> A, int n) {
        // write code here
      vector<int> temp(n);
      for (int i = 0; i < n; ++i) {
        temp[i] = A[i];
      }
      sort(A.begin(), A.end());
      int l = 0;
      while (l < n && temp[l] == A[l])
         l++;
      int r = n - 1;
      while (r > l && temp[r] == A[r])
         r--;
      return r - l + 1;
    }
};