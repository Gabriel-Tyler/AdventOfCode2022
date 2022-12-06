/*
 * Answer: 2823
 */
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    unsigned int bit_set = 0;
    int count = 0;
    int l = 0, r = 0;
    while (count < 14 && r < n)
    {
        unsigned int r_mask = 1u << (s[r]-'a');

        if (bit_set & r_mask)
        {
            while (l < r && (bit_set & r_mask))
            {
                unsigned int l_mask = 1u << (s[l]-'a');
                bit_set &= ~l_mask;
                ++l;
                --count;
            }
        }

        bit_set |= r_mask;
        ++count;
        ++r;
    }
    cout << r << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}

