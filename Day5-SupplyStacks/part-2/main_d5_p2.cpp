/**
 * Gabriel Tyler
 * Advent of Code 2022
 * Day 5 part 2
 * Answer: "TPWCGNCCG"
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

    // because the stack input is a number of elements of size 3 each separated by a space
    // and because the line has no leading or trailing whitespace: e.g., "[1] [2]", not "  [1] [2] "
    // and because we can assume that stacks only contain chars and the stack number is a single digit
    //
    //     we can calculate the number of stacks based on how long the line is 
    //      -> n = (size+1) / 4
    //
    // example:
    //     "[1] [2] [3]" (size = 11)
    //
    //     (11+1)/4 = 3 stacks
    //
    //     imagine adding a space at the beginning then dividing by 4:
    //         " [1] [2] [3]" (size=12)
    //          1   1   1 
    //           234 234 234
    //
    int num_stacks = (line.size()+1)/4;

    vector<stack<char>> stacks(num_stacks);

    // starting from the bottom (end) of the strings array, 
    // add each entry into the corresponding stack
    for (int i = lines.size()-1; i >= 0; --i)
    {
        forn (j, num_stacks)
        {
            // see the above explanation of this calculation
            //
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

        // input is 1-indexed, convert to 0-indexed
        --op.src;
        --op.dst;

        // perform the operation
        //  -> move op.num elements from top of src stack to top of dst stack
        //  -> use a temp stack to maintain orderings
        stack<char> top_of_stack;
        // to temp
        forn (i, op.num)
        {
            top_of_stack.push(stacks[op.src].top());
            stacks[op.src].pop();
        }
        // to dst
        while (!top_of_stack.empty())
        {
            stacks[op.dst].push(top_of_stack.top());
            top_of_stack.pop();
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

