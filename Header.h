#include <iostream>
#include <vector>
#include <math.h>

using std::vector;
using std::cout;
using std::cin;
using std::pow;
using std::endl;

int getDet(const std::vector<std::vector<int>>& matrix, std::vector<int>& skip_row_index, std::vector<int>& skip_col_index);

int sizeWithoutSkippedRowsAndCols(const vector<vector<int>>& matrix, const vector<int>& skip_row_index);

bool isValidIndex(int index, const vector<int>& skip_indexes);