/**
 * Gabriel Tyler
 * Advent of code 2022 
 * Day 3 part 2
 * Answer: 2838
 */

#include <iostream>
#include <string>

#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

using ll = long long;

void solve()
{
    bool flags[3][52];
    forn(i, 3)
    {
        forn(j, 52)
        {
            flags[i][j] = false;
        }
    }

    ll sum = 0;
    string line;
    while (true)
    {
        // loop through three lines and flag the chars 
        forn(i, 3)
        {
            getline(cin, line);
            if (line.empty())
                break;
            for (char c : line)
            {
                int j = -1;
                if (islower(c))
                    j = c-'a';
                if (isupper(c))
                    j = c-'A'+26;
                if (j >= 0 && j < 52)
                    flags[i][j] = true;
            }
        }

        if (line.empty())
            break;

        // check which char is in all three lines
        forn(i, 52)
        {
            if (flags[0][i] && flags[1][i] && flags[2][i])
            {
                sum += i+1;
                break;
            }
        }

        // clear
        forn(i, 3)
        {
            forn(j, 52)
            {
                flags[i][j] = false;
            }
        }
    }
    cout << sum << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}

