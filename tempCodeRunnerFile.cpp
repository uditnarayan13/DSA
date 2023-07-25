#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

struct Cell {
    int row;
    int col;
    Cell(int r, int c) : row(r), col(c) {}
};

std::vector<std::pair<int, int>> findPath(const std::vector<std::vector<int>>& maze) {
    int n = maze.size();
    int m = maze[0].size();

    std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
    visited[0][0] = true;

    std::queue<Cell> q;
    q.push(Cell(0, 0));

    std::vector<std::pair<int, int>> path;
    std::vector<std::pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    while (!q.empty()) {
        Cell current = q.front();
        q.pop();

        int row = current.row;
        int col = current.col;

        if (row == n - 1 && col == m - 1) {
            path.push_back({row, col});
            Cell curr = current;
            while (curr.row != 0 || curr.col != 0) {
                std::pair<int, int> prev = path.back();
                if ((prev.first == curr.row && prev.second == curr.col + 1) || 
                    (prev.first == curr.row + 1 && prev.second == curr.col) ||
                    (prev.first == curr.row && prev.second == curr.col - 1) ||
                    (prev.first == curr.row - 1 && prev.second == curr.col)) {
                    path.push_back({curr.row, curr.col});
                }
                curr = Cell(prev.first, prev.second);
            }
            path.push_back({0, 0});
            std::reverse(path.begin(), path.end());  // Reversing the path
            return path;
        }

        for (const auto& dir : directions) {
            int newRow = row + dir.first;
            int newCol = col + dir.second;

            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && !visited[newRow][newCol] && maze[newRow][newCol] == 0) {
                visited[newRow][newCol] = true;
                q.push(Cell(newRow, newCol));
                path.push_back({row, col});
            }
        }
    }

    return {};
}

int main() {
    std::vector<std::vector<int>> maze = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {1, 0, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };

    std::vector<std::pair<int, int>> path = findPath(maze);

    if (path.empty()) {
        std::cout << "No valid path found." << std::endl;
    } else {
        std::cout << "Path found:" << std::endl;
        for (const auto& p : path) {
            std::cout << "(" << p.first << ", " << p.second << ")" << std::endl;
        }
    }

    return 0;
}
