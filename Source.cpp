#include <vector>
#include <iostream>
#include <math.h>

 using namespace std;

/// Оформление кода
/// Cmake проект
/// Реализация в cpp, прототипы в заголовках
int Sign(int q, int w) {
    if ((q + w) % 2 == 0) {
      return 1;
    } 
        else
    { 
        return -1;
    }
}
/// вы чтобы скипнуть и выкусить из массива число, просто берете и копируете
/// все целиком), была бы образно у вас длинна nums 10000000
/// Вы вместого, чтобы скипнуть i элемент, копируете 10000000 - 1 
vector<int> FiltByIndex(const vector<int>& nums, int index) {
    vector<int> filter;
    for (int y = 0; y < nums.size(); ++y) {
      if (y != index) {
        filter.push_back(nums[y]);
      }
    }
  return filter;
}
vector<vector<int>> MakeMinor(const vector<vector<int>>& mat, int skip_q, int skip_w) {
    vector<vector<int>> minor;
    
    for (int q = 0; q < mat.size(); ++q) {
      if (q != skip_q) {
        auto filter = FiltByIndex(mat[q], skip_w);
            minor.push_back(filter);
      }
    }
    return minor;
}
int Det(const vector<vector<int>>& mat) {
    if (mat.size() == 1 && mat[0].size() == 1) {
        return mat[0][0];
    }
 int det = 0;
 for (int w = 0; w < mat[0].size(); ++w) {
        auto minor = MakeMinor(mat, 0, w);
            det += Sign(0, w) * mat[0][w] * Det(minor);
}
    return det;
}
int main() {   
    int str, stl;
        cin >> str >> stl;
            vector<vector<int>> mat(str, vector<int>(stl));
    for (auto& line : mat) {
        for (auto& e : line) {
            cin >> e;
        }
    }
cout << Det(mat) << '\n';
}
