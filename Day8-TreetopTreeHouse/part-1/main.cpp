// Gabriel Tyler
// Answer: 1776

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

    int CountVisible(const vector<vector<bool>>& visible) const
    {
        int count = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (visible[i][j])
                    ++count;
            }
        }
        return count;
    }

    void Solve() const
    {
        if (IsGridEmpty())
        {
            cout << "0\n";
            return;
        }

        vector<vector<bool>> visible(m, vector<bool>(n, false));

        // left
        for (int i = 0; i < m; ++i)
        {
            int max_h = -1;
            for (int j = 0; j < n; ++j)
            {
                int h = grid[i][j]-'0';
                if (h > max_h)
                {
                    max_h = max(max_h, h);
                    visible[i][j] = true;
                }
            }
        }

        // right
        for (int i = 0; i < m; ++i)
        {
            int max_h = -1;
            for (int j = n-1; j >= 0; --j)
            {
                int h = grid[i][j]-'0';
                if (h > max_h)
                {
                    max_h = max(max_h, h);
                    visible[i][j] = true;
                }
            }
        }

        // top
        for (int j = 0; j < n; ++j)
        {
            int max_h = -1;
            for (int i = 0; i < m; ++i)
            {
                int h = grid[i][j]-'0';
                if (h > max_h)
                {
                    max_h = max(max_h, h);
                    visible[i][j] = true;
                }
            }
        }

        // bottom
        for (int j = 0; j < n; ++j)
        {
            int max_h = -1;
            for (int i = m-1; i >= 0; --i)
            {
                int h = grid[i][j]-'0';
                if (h > max_h)
                {
                    max_h = max(max_h, h);
                    visible[i][j] = true;
                }
            }
        }

        cout << CountVisible(visible) << '\n';
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
    /**
     * -------- Explanation --------
     *  For each of these steps, when looping throught a row/column:
     *      - If a height is greater than the prev. max height: 
     *          - Set new max height
     *          - Set the element as visible is 2d is-visible grid
     *  1. Loop through each row from left to right
     *  2. Loop through each row from right to left
     *  3. Loop through each column from up to down
     *  4. Loop through each column from down to up
     */
    Solution s;
    s.FillGrid(); // get input
    s.Solve(); // algorithm
}


