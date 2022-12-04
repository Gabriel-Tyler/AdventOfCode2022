/**
 * Gabriel Tyler
 * Advent of Code 2022
 * Day 4 part 1
 * Answer: 576 
 */

#include <iostream>
#include <string>

#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

using ll = long long;

void solve()
{
    int contained = 0;
    string line;
    while (getline(cin, line))
    {
        if (line.empty())
            break;

        // parse the line into a pair of ranges ([1st/2nd elf][left/right in range])
        ll range_pair[2][2];

        forn (i, 2)
            forn (j, 2)
                range_pair[i][j] = 0;

        size_t curr = 0;
        size_t pos = 0;
        forn (i, 2)
        {
            forn (j, 2)
            {
                try
                {
                    range_pair[i][j] = stoll(line.substr(curr), &pos);
                    curr += pos+1;
                }
                catch(const invalid_argument& e)
                {
                    cout << "invalid_argument::what(): " << e.what() << '\n';
                }
                catch(const out_of_range& e)
                {
                    cout << "out_of_range::what(): " << e.what() << '\n';
                }
            }
        }
        
        // check the boundaries of each range pair to see if one contains the other
        if ((range_pair[0][0] <= range_pair[1][0] && range_pair[1][1] <= range_pair[0][1]) || 
            (range_pair[1][0] <= range_pair[0][0] && range_pair[0][1] <= range_pair[1][1]))
        {
            ++contained;
        }

    }
    cout << contained << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}

