/**
 * Exercies: Given an m x n 2D binary grid grid which represents a map of '1's
 * (land) and '0's (water), return the number of islands.
 * 
 * An island is surrounded by water and is formed by connecting adjacent lands
 * horizontally or vertically. You may assume all four edges of the grid are all
 * surrounded by water.
 */

class NumberOfIslands {
    public int numIslands(char[][] grid) {
        int countIslands = 0;
        for (int m = 0; m < grid.length; m++) {
            for (int n = 0; n < grid[m].length; n++) {
                if (grid[m][n] == '1') {
                    countIslands++;
                    dfs(grid, m, n);
                }
            }
        }
        return countIslands;

    }

    public void dfs(char[][] grid, int m, int n) {
        if (m < 0 || m >= grid.length || n < 0 || n >= grid[m].length || grid[m][n] == '0') {
            return;

        }
        grid[m][n] = '0';
        dfs(grid, m - 1, n); // up
        dfs(grid, m + 1, n); // down
        dfs(grid, m, n - 1); // left
        dfs(grid, m, n + 1); // right

    }
}

