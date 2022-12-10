// Gabriel Tyler
// Answer: 2717

#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    struct Coord
    {
        int x, y;
    };
public:
    void Solve()
    {
        int num_knots = 10;
        vector<Coord> knots(num_knots, {0, 0});
        unordered_set<string> visited; // entry format: "tx ty"
        visited.insert("0 0"); // count the tail starting pos

        string line;
        while (getline(cin, line) && !line.empty())
        {
            istringstream iss(line);
            char direction;
            int num_steps;
            iss >> direction >> num_steps;


            // perform a motion between each adjacent knot (starting with the head)
            for (int i = 0; i < num_steps; ++i)
            {
                // move the head one step
                if      (direction == 'R') ++knots[0].x;
                else if (direction == 'L') --knots[0].x;
                else if (direction == 'U') ++knots[0].y;
                else if (direction == 'D') --knots[0].y;

                for (int j = 1; j < num_knots; ++j)
                {
                    // if the tail is more than one step away from the head from any direction:
                    //     - move the tail one or two steps to catch up
                    //     - add to the visited set
                    int adj_dist = max(
                        abs(knots[j].x - knots[j-1].x), 
                        abs(knots[j].y - knots[j-1].y)
                    );
                    if (adj_dist > 1)
                    {
                        if      (knots[j-1].x - knots[j].x > 0) ++knots[j].x;
                        else if (knots[j-1].x - knots[j].x < 0) --knots[j].x;

                        if      (knots[j-1].y - knots[j].y > 0) ++knots[j].y;
                        else if (knots[j-1].y - knots[j].y < 0) --knots[j].y;

                        if (j == 9)
                            visited.insert(to_string(knots[j].x) + " " + to_string(knots[j].y));
                    }
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

