/**
 * Gabriel Tyler
 * Advent of code 2022 
 * Day 3 part 1
 * Answer: 7908
 */

#include <iostream>
#include <string>

#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

using ll = long long;

void solve()
{
    bool left[52];
    forn(i, 52)
        left[i] = false;
    ll sum = 0;
    string line;
    while (getline(cin, line) && !line.empty())
    {
        int n = line.size();
        // add left side of line to array
        for (int i = 0; i < n/2; ++i)
        {
            char c = line[i];
            int j = -1;
            if (islower(c))
                j = c-'a';
            else if (isupper(c))
                j = c-'A'+26;
            if (j >= 0 && j < 52)
                left[j] = true;
        }
        // if a char is present in the right side, add priority to sum
        for (int i = n/2; i < n; ++i)
        {
            char c = line[i];
            int j = -1;
            if (islower(c))
                j = c-'a';
            else if (isupper(c))
                j = c-'A'+26;
            if (j >= 0 && j < 52 && left[j])
            {
                sum += j+1;
                break;
            }
        }
        // clear left array
        forn(i, 52)
            left[i] = false;
    }
    cout << sum << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}

