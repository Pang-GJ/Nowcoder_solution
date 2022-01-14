#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void aescSort(std::vector<std::string> &vName, std::vector<int> &vGrade);
void descSort(std::vector<std::string> &vName, std::vector<int> &vGrade);
void printAnswer(std::vector<std::string> &vName, std::vector<int> &vGrade);

int main(int argc, char *argv[]) {
  int n = 0, tag = 0, number = 1;
  std::string name;
  std::vector<int> vGrade;
  std::vector<std::string> vName;

  while (std::cin >> n) {
    std::cin >> tag;
    while (n--) {
      std::cin >> name >> number;
      vName.push_back(name);
      vGrade.push_back(number);
    }

    if (tag) {
      aescSort(vName, vGrade);
    } else {
      descSort(vName, vGrade);
    }

    printAnswer(vName, vGrade);

    std::vector<int>().swap(vGrade);  // 清空 vGrade
    std::vector<std::string>().swap(vName); // 清空 vName
  }

  return 0;
}

void swap(int &a, int &b) {
  int temp = b;
  b = a;
  a = temp;
}

void swap(std::string &a, std::string &b) {
  std::string temp = b;
  b = a;
  a = temp;
}

void aescSort(std::vector<std::string> &vName, std::vector<int> &vGrade) {
  for (int i = 0; i < vGrade.size(); ++i) {
    for (int j = i - 1; j >=0 && vGrade[j] > vGrade[j+1]; --j) {
      swap(vGrade[j], vGrade[j+1]);
      swap(vName[j], vName[j+1]);
    }
  }
}

void descSort(std::vector<std::string> &vName, std::vector<int> &vGrade) {
  for (int i = 0; i < vGrade.size(); ++i) {
    for (int j = i - 1; j >=0 && vGrade[j] < vGrade[j+1]; --j) {
      swap(vGrade[j], vGrade[j+1]);
      swap(vName[j], vName[j+1]);
    }
  }
}

void printAnswer(std::vector<std::string> &vName, std::vector<int> &vGrade) {
  for (int i = 0; i < vName.size(); ++i) {
    std::cout << vName[i] << " " << vGrade[i] << std::endl;
  }
}