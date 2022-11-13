#include "Header.h"
#include <gtest/gtest.h>
TEST(MatrixDet, calculate_det_of_matrix5x5) {
    std::vector<std::vector<int>> matrix1{
        {0, 7, 9, 2, 5},
        {6, 2, 4, 2, 5},
        {3, 1, 2, 2, 5},
        {3, 2, 8, 2, 5},
        {3, 4, 3, 9, 5}
    };
    // 2 буфера необходимые для подсчёта определителя в подматрице
    std::vector<int> buff_1;
    std::vector<int> buff_2;
    int calc_Det = getDet(matrix1, buff_1, buff_2);
    int fact_Det = -3465;

    ASSERT_EQ(calc_Det,fact_Det);
}
TEST(MatrixDet, calculate_det_of_matrix_4x4) {
    std::vector<std::vector<int>> matrix1{
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };
    // 2 буфера необходимые для подсчёта определителя в подматрице
    std::vector<int> buff_1;
    std::vector<int> buff_2;
    int calc_Det = getDet(matrix1, buff_1, buff_2);
    int fact_Det = 1;

    ASSERT_EQ(calc_Det,fact_Det);
}
TEST(MatrixDet, calculate_det_of_matrix_3x3) {
    std::vector<std::vector<int>> matrix1{
        {0, 7, 9},
        {6, 2, 4},
        {3, 1, 2}
    };
    // 2 буфера необходимые для подсчёта определителя в подматрице
    std::vector<int> buff_1;
    std::vector<int> buff_2;
    int calc_Det = getDet(matrix1, buff_1, buff_2);
    int fact_Det = 0;

    ASSERT_EQ(calc_Det,fact_Det);
}
TEST(MatrixDet, calculate_det_of_matrix_2x2) {
    std::vector<std::vector<int>> matrix1{
        {1, 7,},
        {4, 2,}

    };
    // 2 буфера необходимые для подсчёта определителя в подматрице
    std::vector<int> buff_1;
    std::vector<int> buff_2;
    int calc_Det = getDet(matrix1, buff_1, buff_2);
    int fact_Det = -26;

    ASSERT_EQ(calc_Det,fact_Det);
}
TEST(MatrixDet, calculate_det_of_matrix_1x1) {
    std::vector<std::vector<int>> matrix1{
        {5}

    };
    // 2 буфера необходимые для подсчёта определителя в подматрице
    std::vector<int> buff_1;
    std::vector<int> buff_2;
    int calc_Det = getDet(matrix1, buff_1, buff_2);
    int fact_Det = 5;

    ASSERT_EQ(calc_Det,fact_Det);
}
TEST(MatrixDet, calculate_det_of_emptyMatrix) {
    std::vector<std::vector<int>> matrix1{
        {}
    };
    // 2 буфера необходимые для подсчёта определителя в подматрице
    std::vector<int> buff_1;
    std::vector<int> buff_2;
    int calc_Det = getDet(matrix1, buff_1, buff_2);
    int fact_Det = 0;

    ASSERT_EQ(calc_Det,fact_Det);
}
