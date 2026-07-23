#include<iostream>
#include<vector>

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        int islandCount = 0;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1') {
                    islandCount++;
                    dfsUtil(grid, i, j);
                }
            }
        }

        return islandCount;
    }

    void dfsUtil(vector<vector<char>>& grid, int i, int j) {
        int rows = grid.size();
        int cols = grid[0].size();
        if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] != '1') {
            return;
        }
        grid[i][j] = '0';
        dfsUtil(grid, i + 1, j);
        dfsUtil(grid, i - 1, j);
        dfsUtil(grid, i, j + 1);
        dfsUtil(grid, i, j - 1);
    }
};
