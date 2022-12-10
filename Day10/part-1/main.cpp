// Answer: 12460

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void Solve()
    {
        int x = 1;
        int cycle_num = 1;
        int total_cycle_strength = 0;
        string line;
        while (getline(cin, line) && !line.empty())
        {
            if (cycle_num > 220)
                continue;
            istringstream iss(line);
            string cmd;
            int rhs;
            iss >> cmd;
            if (cmd == "noop")
            {
                if ((cycle_num+20) % 40 == 0)
                {
                    total_cycle_strength += x * cycle_num;
                }
                ++cycle_num;
            }
            else if (cmd == "addx")
            {
                if ((cycle_num+20) % 40 == 0)
                {
                    total_cycle_strength += x * cycle_num;
                }
                ++cycle_num;
                if ((cycle_num+20) % 40 == 0)
                {
                    total_cycle_strength += x * cycle_num;
                }
                ++cycle_num;
                iss >> rhs;
                x += rhs;
            }
        }
        cout << total_cycle_strength << '\n';
    }
};

int main()
{
    Solution s; 
    s.Solve();
}

