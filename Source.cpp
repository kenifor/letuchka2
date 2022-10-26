#include "Header.h"

int getDet(const vector<vector<int>>& matrix, vector<int>& skip_row_index, vector<int>& skip_col_index)
{
    int det = 0;
    int matrix_size = sizeWithoutSkippedRowsAndCols(matrix, skip_row_index);
    if (matrix_size > 2)
    {
        int row_index = skip_row_index.size();
        skip_row_index.push_back(row_index);
        int local_col_index = 0;

        for (int col_index = 0; col_index < matrix.size(); col_index++)
        {
            if (!isValidIndex(col_index, skip_col_index))
                continue;
            skip_col_index.push_back(col_index);
            det +=
                matrix[row_index][col_index] *                  // берем элемент на пересечении строки и столбца
                pow(-1, local_col_index++) *                    // вы€вл€ем знак определител€
                getDet(matrix, skip_row_index, skip_col_index); // считаем определитель подматрицы/матрицы
            skip_col_index.pop_back();
        }

        skip_row_index.pop_back(); 
    }
    else if (matrix_size == 2)
    {
        vector<int> M2x2;
        for (int y = 0; y < matrix.size(); y++)
        {
            if (isValidIndex(y, skip_row_index))
            {
                for (int x = 0; x < matrix.size(); x++)
                {
                    if (isValidIndex(x, skip_col_index))
                    {
                        M2x2.push_back(matrix[y][x]);
                        if (M2x2.size() == 4)
                        {
                            det = M2x2[0] * M2x2[3] - M2x2[1] * M2x2[2];
                            return det;
                        }
                    }
                }
            }
        }
    }
    return det;
}

int sizeWithoutSkippedRowsAndCols(const vector<vector<int>>& matrix, const vector<int>& skip_row_index)
{
    if (skip_row_index.empty())
        return matrix.size();
    return matrix.size() - skip_row_index.size();
}

bool isValidIndex(int index, const vector<int>& skip_indexes)
{
    for (auto skip_index : skip_indexes)
    {
        if (index == skip_index)
            return false;
    }

    return true;
}