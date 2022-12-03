/**
 * Gabriel Tyler
 * Advent of Code 2022
 * Day 1 part 1
 * Answer: 64929
 */

#include <iostream>
#include <string>
#include <climits> // LLONG_MAX, LLONG_MIN

using namespace std;

using ll = long long;

// check that the addition won't overflow, return LLONG_MAX/LLONG_MIN if overflow/underflow
ll add(ll lhs, ll rhs)
{
    if (lhs >= 0)
    {
        if (LLONG_MAX - lhs < rhs) 
            // OVERflow
            return LLONG_MAX;
    }
    else
    {
        if (rhs < LLONG_MIN - lhs)
            // UNDERflow
            return LLONG_MIN;
    }
    return lhs + rhs;

    // see: https://stackoverflow.com/a/3947943
}

void solve()
{
    ll curr = 0;
    ll total = 0;
    ll max = 0;

    string s;
    int num_empty_lines = 0;
    while (num_empty_lines < 2 && getline(cin, s))
    {
        // blank line if s is empty
        if (s.empty()) 
        {
            if (total > max) 
                max = total;
            total = 0;
            ++num_empty_lines;
            continue;
        }
        num_empty_lines = 0;

        try
        {
            curr = stoll(s);
        }
        catch (const exception& e)
        {
            // invalid argument and out of range exceptions can be thrown by ll stoll(string)
            cout << e.what() << '\n';
            continue;
        }

        // handle negative calories
        if (curr < 0)
            curr = 0;
        
        // add(ll, ll) checks for overflow
        total = add(total, curr);
    }
    
    // last check because the input may not end with a blank line
    if (total > max)
        max = total;

    cout << max << '\n';    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
}

