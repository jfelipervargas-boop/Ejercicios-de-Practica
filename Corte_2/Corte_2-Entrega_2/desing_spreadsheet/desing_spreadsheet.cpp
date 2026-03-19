#include <vector>
#include <string>

class Spreadsheet {
private:
    std::vector<std::vector<int>> grid;

    int colIndex(char c) {
        return c - 'A';
    }

public:
    Spreadsheet(int rows) {
        grid.assign(rows, std::vector<int>(26, 0));
    }

    void setCell(std::string cell, int value) {
        int col = colIndex(cell[0]);
        int row = std::stoi(cell.substr(1)) - 1;
        grid[row][col] = value;
    }

    void resetCell(std::string cell) {
        int col = colIndex(cell[0]);
        int row = std::stoi(cell.substr(1)) - 1;
        grid[row][col] = 0;
    }

    int getValue(std::string formula) {
        if(formula[0] != '=') return 0;

        std::string a = formula.substr(1,2);
        std::string b = formula.substr(4,2);

        int col1 = colIndex(a[0]);
        int row1 = a[1] - '1';

        int col2 = colIndex(b[0]);
        int row2 = b[1] - '1';

        return grid[row1][col1] + grid[row2][col2];
    }
};