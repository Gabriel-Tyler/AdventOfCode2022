// Gabriel Tyler
// Answer: 234416

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
private:
    vector<string> grid {};
    int m=0, n=0;

    bool IsGridEmpty() const 
    {
        return grid.empty() || m == 0 || n == 0;
    }

public:
    void Clear()
    {
        grid.clear();
        m = 0;
        n = 0;
    }

    void FillGrid()
    {
        Clear();

        int max_line_size = 0;
        string line_input;
        while (getline(cin, line_input) && !line_input.empty())
        {
            grid.push_back(line_input);
            max_line_size = max(max_line_size, (int)line_input.size());
        }

        m = grid.size();
        n = max_line_size;

        for (string& row : grid)
        {
            int row_size = row.size();
            if (row_size != n)
            {
                int num_cols_missing = n - row_size;
                row.append(num_cols_missing, '0');
            }
        }

        if (IsGridEmpty())
        {
            Clear();
            return;
        }
    }

    long long GetScenicScore(int r, int c) const
    {
        long long right=0, left=0, down=0, up=0;

        // look right
        for (int j = c+1; j < n; ++j)
        {
            ++right;
            if (grid[r][c] <= grid[r][j])
                break;
        }
        // look left
        for (int j = c-1; j >= 0; --j)
        {
            ++left;
            if (grid[r][c] <= grid[r][j])
                break;
        }
        // look down
        for (int i = r+1; i < m; ++i)
        {
            ++down;
            if (grid[r][c] <= grid[i][c])
                break;
        }
        // look up
        for (int i = r-1; i >= 0; --i)
        {
            ++up;
            if (grid[r][c] <= grid[i][c])
                break;
        }

        return right * left * down * up;
    }

    void Solve() const
    {
        if (IsGridEmpty())
        {
            cout << "0\n";
            return;
        }
        
        long long max_scenic_score = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                max_scenic_score = max(max_scenic_score, GetScenicScore(i, j));
            }
        }
        cout << max_scenic_score << '\n';
    }

    void PrintGrid() const
    {
        cout << m << " x " << n << '\n';
        for (const auto& line : grid)
        {
            cout << line << '\n';
        }
        cout << '\n';
    }
};

int main()
{
    Solution s;
    s.FillGrid(); // get input
    s.Solve(); // algorithm
}


