#pragma once
#include "dependencies.h"
class NumMatrix {
public:
    vector<vector<int>> memory;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(),n = matrix.front().size();
        memory.resize(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                memory[i + 1][j + 1] = memory[i + 1][j] + memory[i][j + 1] - memory[i][j] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 == 0 && col1 == 0) return memory[row2 + 1][col2 + 1];
        else {
            return memory[row2 + 1][col2 + 1] - memory[row2 + 1][col1] - memory[row1][col2 + 1] + memory[row1][col1];
        }
    }
};