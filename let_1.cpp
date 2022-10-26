#include "Header.h"

int main()
{
    int matrix_size;
    vector<vector<int>> matrix;

    cout << "Enter the size of matrix: ";
    cin >> matrix_size;
    if (matrix_size < 1)
    {
        cout << "Size of matrix is 0 or smaller!" << endl;
        return 0;
    }

    cout << "Enter elements of matrix size of " << matrix_size << "x" << matrix_size << endl;

    for (int y = 0; y < matrix_size; ++y)
    {
        vector<int> row;

        cout << y + 1 << " row --> ";

        for (int x = 0; x < matrix_size; ++x)
        {
            int element;
            cin >> element;
            row.push_back(element);
        }

        matrix.push_back(row);
    }

    if (matrix_size == 1)
    {
        cout << "Det: " << matrix[0][0] << endl;
        return 0;
    }

    vector<int> skipping_rows, skipping_cols;
    int det = getDet(matrix, skipping_rows, skipping_cols);

    cout << "Det: " << det << endl;

    return 0;
}

