/**
 * Gabriel Tyler
 * Advent of code 2022 
 * Day 2 part 1
 * Answer: 13565
 */

#include <iostream>
#include <string>

using namespace std;

using ll = long long;

void solve()
{
    // hardcode the scores into a 2d array (dp[opp][me])
    int dp[3][3] = {
        /*       X  Y  Z */
        /* A */ {4, 8, 3},
        /* B */ {1, 5, 9},
        /* C */ {7, 2, 6}
    };

    string s;
    ll total = 0;
    while (getline(cin, s) && s.size() == 3)
    {
        int opp = s[0] - 'A';
        int me  = s[2] - 'X';

        if (opp < 0 || opp > 2 || me < 0 || me > 2)
            // invalid input
            continue; 

        total += dp[opp][me];
    }

    cout << total << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}

