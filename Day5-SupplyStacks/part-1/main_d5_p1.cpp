/**
 * Gabriel Tyler
 * Advent of Code 2022
 * Day 5 part 1
 * Answer: "VPCDMSLWJ"
 */

#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

using ll = long long;

struct Operation
{
    int num, src, dst;
};

void solve()
{
    // get the stacks
    vector<string> lines;
    string line;
    while (getline(cin, line) && line[1] != '1')
    {
        lines.push_back(line);
    }

    int num_stacks = (line.size()-1)/4+1;
    vector<stack<char>> stacks(num_stacks);
    for (int i = lines.size()-1; i >= 0; --i)
    {
        forn (j, num_stacks)
        {
            char c = lines[i][4*j+1];
            if (c != ' ')
                stacks[j].push(lines[i][4*j+1]);
        }
    }

    // get the ops
    getline(cin, line);
    while (getline(cin, line) && !line.empty())
    {
        Operation op;
        string s;
        istringstream iss(line);
        iss >> s >> op.num >> s >> op.src >> s >> op.dst;
        for (int i = 0; i < op.num; ++i)
        {
            char c = stacks[op.src-1].top();
            stacks[op.src-1].pop();
            stacks[op.dst-1].push(c);
        }
    }

    // get the top of each stack
    forn (i, num_stacks)
    {
        cout << stacks[i].top();
    }
    cout << '\n';
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);

    solve();
}

