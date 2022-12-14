/**
 * Gabriel Tyler
 * Advent of code 2022 
 * Day 2 part 2
 * Answer: 12424
 */

#include <iostream>
#include <string>

using namespace std;

using ll = long long;

void solve()
{
    // hardcode the scores into a 2d array (dp[opp][outcome])
    int dp[3][3] = {
        /*       X  Y  Z */
        /* A */ {3, 4, 8},
        /* B */ {1, 5, 9},
        /* C */ {2, 6, 7}
    };

    string s;
    ll total = 0;
    while (getline(cin, s) && s.size() == 3)
    {
        int opp     = s[0] - 'A';
        int outcome = s[2] - 'X';

        if (opp < 0 || opp > 2 || outcome < 0 || outcome > 2)
            // invalid input
            continue; 

        total += dp[opp][outcome];
    }

    cout << total << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}

