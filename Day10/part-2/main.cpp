// Answer: EZFPRAKL

#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    int m, n;
    vector<char> picture;

public:
    void DrawPixel(int cycle, int x)
    {
        if (cycle > m*n)
        {
            cout << "DrawPixel: cycle = " << cycle << " is out of bounds\n";
        }

        int pos = (cycle % n) - 1;

        if (pos == x-1 || pos == x || pos == x+1)
        {
            picture[cycle-1] = '#';
        }
        else
        {
            picture[cycle-1] = '.';
        }
    }

    void PrintPicture() const
    {
        if (picture.empty())
        {
            cout << "Empty picture\n";
            return;
        }

        for (int i = 0; i < m*n; ++i)
        {
            cout << picture[i];
            if ((i+1) % n == 0)
                cout << '\n';
        }
    }

    void Solve()
    {
        m = 6;
        n = 40;
        picture = vector<char>(m*n, '-');
        int x = 1;
        int cycle = 1;

        string line;
        while (getline(cin, line) && !line.empty())
        {
            if (cycle > 240)
                continue;

            istringstream iss(line);
            string cmd;
            int rhs;
            iss >> cmd;

            if (cmd == "noop")
            {
                DrawPixel(cycle, x);
                ++cycle;
            }
            else if (cmd == "addx")
            {
                DrawPixel(cycle, x);
                ++cycle;

                DrawPixel(cycle, x);
                ++cycle;

                iss >> rhs;
                x += rhs;
            }
        }

        PrintPicture();
    }
};

int main()
{
    Solution s; 
    s.Solve();
}

