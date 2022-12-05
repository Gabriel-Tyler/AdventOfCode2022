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
    // store the stack input into an array of strings
    vector<string> lines;
    string line;
    while (getline(cin, line))
    {
        // break if one of the following:
        //  -> we reach an empty line
        //  -> the line isn't at least size 3 (length of a single entry, e.g., "[A]")
        //  -> we reach the line that lists the numbers of the stack (" 1  2  ...")
        if (line.size() < 3 || line[1] == '1')
            break;

        lines.push_back(line);
    }

    // can calculate the number of stacks based on how long the line is 
    //  -> (n = (sz-1) / 4 + 1)
    int num_stacks = (line.size()-1)/4+1;

    vector<stack<char>> stacks(num_stacks);

    // starting from the bottom (end) of the strings array, 
    // add each entry into the corresponding stack
    for (int i = lines.size()-1; i >= 0; --i)
    {
        forn (j, num_stacks)
        {
            // can calculate the index of an element of the stack from the strings array
            //  -> pos = 4*j + 1
            char c = lines[i][4*j+1];

            if (c != ' ')
                stacks[j].push(c);
        }
    }


    // ignore the empty line separating the stacks from the operations
    getline(cin, line);

    // perform the operations one by one until an empty line
    while (getline(cin, line) && !line.empty())
    {
        // extract the integers from the operation string using istringstream
        Operation op;
        string s;
        istringstream iss(line); 
        iss >> s >> op.num >> s >> op.src >> s >> op.dst;

        // perform the operation
        //  -> move the tops one-by-one from src stack dst stack op.num times
        forn (i, op.num)
        {
            char c = stacks[op.src-1].top();
            stacks[op.src-1].pop();
            stacks[op.dst-1].push(c);
        }
    }

    // print the top of each stack
    forn (i, num_stacks)
    {
        cout << stacks[i].top();
    }
    cout << '\n';
}

int main()
{
    // vroom vroom
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}

