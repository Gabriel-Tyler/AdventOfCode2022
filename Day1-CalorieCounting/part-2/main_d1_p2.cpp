/**
 * Gabriel Tyler
 * Advent of Code 2022
 * Day 1 part 2
 * Answer: 193697
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
    ll max1 = 0; // first most
    ll max2 = 0; // second most
    ll max3 = 0; // third most

    string s;
    int num_empty_lines = 0;
    while (num_empty_lines < 2 && getline(cin, s))
    {
        // blank line if s is empty
        if (s.empty()) 
        {
            // update the maxes
            if (total >= max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = total;
            }
            else if (total >= max2)
            {
                max3 = max2;
                max2 = total;
            }
            else if (total >= max3)
            {
                max3 = total;
            }

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
    if (total >= max1)
    {
        max3 = max2;
        max2 = max1;
        max1 = total;
    }
    else if (total >= max2)
    {
        max3 = max2;
        max2 = total;
    }
    else if (total >= max3)
    {
        max3 = total;
    }

    cout << add(max1, add(max2, max3)) << '\n';    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
}

