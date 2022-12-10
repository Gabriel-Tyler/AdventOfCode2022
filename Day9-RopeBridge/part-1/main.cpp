// Gabriel Tyler
// Answer: 6522

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void Solve()
    {
        unordered_set<string> visited; // entry format: "tx ty"
        visited.insert("0 0"); // count the tail starting pos
        int hx=0, hy=0, tx=0, ty=0;
        string line;
        while (getline(cin, line) && !line.empty())
        {
            istringstream iss(line);
            char direction;
            int num_steps;
            iss >> direction >> num_steps;
            
            for (int i = 0; i < num_steps; ++i)
            {
                // move the head one step
                if      (direction == 'R') ++hx;
                else if (direction == 'L') --hx;
                else if (direction == 'U') ++hy;
                else if (direction == 'D') --hy;

                // if the tail is more than one step away from the head from any direction:
                //     - move the tail one or two steps to catch up
                //     - add to the visited set
                int head_tail_dist = max(abs(hx-tx), abs(hy-ty));
                if (head_tail_dist > 1)
                {
                    if      (hx-tx > 0) ++tx;
                    else if (hx-tx < 0) --tx;
                    if      (hy-ty > 0) ++ty;
                    else if (hy-ty < 0) --ty;
                    visited.insert(to_string(tx) + " " + to_string(ty));
                }
            }


        }
        cout << visited.size() << '\n';
    }
};

int main()
{
    Solution s; 
    s.Solve();
}

