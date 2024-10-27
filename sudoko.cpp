#include <iostream>
#include <vector>

using namespace std;

const int N = 9; // Size of the Sudoku grid

// Function to print the Sudoku grid
void printGrid(const vector<vector<int>> &grid)
{
    for (const auto &row : grid)
    {
        for (int num : row)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}

// Function to check if a number can be placed in the given row, column, and box
bool isSafe(const vector<vector<int>> &grid, int row, int col, int num)
{
    // Check the row and column
    for (int x = 0; x < N; x++)
    {
        if (grid[row][x] == num || grid[x][col] == num)
        {
            return false;
        }
    }

    // Check the 3x3 box
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i + startRow][j + startCol] == num)
            {
                return false;
            }
        }
    }
    return true;
}

// Backtracking function to solve the Sudoku
bool solveSudoku(vector<vector<int>> &grid)
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            if (grid[row][col] == 0)
            { // Find an empty cell
                for (int num = 1; num <= 9; num++)
                { // Try numbers 1-9
                    if (isSafe(grid, row, col, num))
                    {
                        grid[row][col] = num; // Place the number
                        if (solveSudoku(grid))
                        { // Recursively try to solve
                            return true;
                        }
                        grid[row][col] = 0; // Backtrack
                    }
                }
                return false; // If no number can be placed, return false
            }
        }
    }
    return true; // Puzzle solved
}

int main()
{
    while (true)
    {
        int Choice;
        cout << "============ Welcome To Sudoku Solver ============" << endl
             << endl;
        cout << "Choice 1 -> Enter to Sudoku Solver" << endl;
        cout << "Choice 2 -> Exit" << endl;
        cout << "Enter your choice -> ";
        cin>>Choice;
        if (Choice == 1)
        {
            vector<vector<int>> grid(N, vector<int>(N));
            cout << "Enter the Sudoku grid (use 0 for empty cells):" << endl;
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    cin >> grid[i][j];
                }
            }

            if (solveSudoku(grid))
            {
                cout << "Solved Sudoku grid:" << endl
                     << endl;
                printGrid(grid);
            }
            else
            {
                cout << "No solution exists for the given Sudoku puzzle." << endl
                     << endl;
            }
        }
        else if (Choice == 2)
        {
            cout << "============ Thank You for using Sudoku Solver ============" << endl;
            break;
        }
        else
        {
            cout << "Please Enter a Valid Input";
        }

        // return 0;
    }
}
