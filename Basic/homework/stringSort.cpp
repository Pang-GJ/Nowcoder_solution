#include <cctype>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

#define MAXLENGTH 1000

void letterQuickSort(std::string &str, int L, int R);
void swap(char &strA, char &strB);
std::vector<int> partition(std::string &str, int L, int R, char key);
void mergeSort(std::string &, int, int);
void merge(std::string &, int, int, int);

int main(int argc, char *argv[]) {
  // 处理输入
  srand((unsigned)time(NULL));
  std::string line, onlyLetter;

  while (getline(std::cin ,line)) {
    // 取出 line 里面的所有字母
    for (std::string::size_type i = 0; i < line.size(); ++i) {
      if ((line[i] - 'a' >= 0 && line[i] - 'a' <= 26) ||
          (line[i] - 'A' >= 0 && line[i] - 'A' <= 26)) {
        onlyLetter.push_back(line[i]);
      }
    }

    // 对字母进行排序
    // letterQuickSort(onlyLetter, 0, onlyLetter.size() - 1);
    // 快速排序会导致不符合规则2
    mergeSort(onlyLetter, 0, onlyLetter.size() - 1);

    int j = 0;
    for (std::string::size_type i = 0; i < line.size(); ++i) {
      if ((line[i] - 'a' >= 0 && line[i] - 'a' <= 26) ||
          (line[i] - 'A' >= 0 && line[i] - 'A' <= 26)) {
        line[i] = onlyLetter[j++];
      }
    }

    std::cout << line << std::endl;
    onlyLetter.erase(0);  // 清空 onlyLetter
  }
  return 0;
}

void letterQuickSort(std::string &str, int L, int R) {
  if (L >= R) {
    return;
  }
  if (str.size() < 2) {
    return;
  }
  int randomIndex = rand() % (R - L + 1) + L;
  swap(str[randomIndex], str[R]);
  std::vector<int> res = partition(str, L, R, str[R]);
  letterQuickSort(str, L, res[0] - 1);
  letterQuickSort(str, res[1] + 1, R);
}

std::vector<int> partition(std::string &str, int L, int R, char key) {
  int left = L - 1;
  int right = R;
  int index = L;

  while (index < right) {
    if (toupper(str[index]) < toupper(key)) {
      swap(str[index++], str[++left]);
    } else if (toupper(str[index]) > toupper(key)) {
      swap(str[index], str[--right]);
    } else {
      ++index;
    }
  }

  swap(str[R], str[right]);
  std::vector<int> res;
  res.push_back(left + 1);
  res.push_back(right);
  return res;
}

void swap(char &strA, char &strB) {
  char temp = strA;
  strA = strB;
  strB = temp;
}

void mergeSort(std::string &str, int L, int R) {
  if (L >= R) {
    return;
  }
  int mid = L + ((R - L) >> 1);
  mergeSort(str, L, mid);
  mergeSort(str, mid + 1, R);
  merge(str, L, mid, R);
}

void merge(std::string &str, int L, int mid, int R) {
  std::string temp(R - L + 1, ' ');
  int p1 = L;
  int p2 = mid + 1;
  int i = 0;
  while (p1 <= mid && p2 <= R) {
    temp[i++] = (toupper(str[p1]) <= toupper(str[p2])) ? str[p1++] : str[p2++];
  }

  while (p1 <= mid) {
    temp[i++] = str[p1++];
  }
  while (p2 <= R) {
    temp[i++] = str[p2++];
  }

  i = 0;
  for (int j = L; j <= R; ++j) {
    str[j] = temp[i++];
  }
}