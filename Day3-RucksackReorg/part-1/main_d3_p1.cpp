#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve()
{
    ll sum = 0;
    bool left[52], right[52];
    forn(i, 52)
    {
        left[i] = false;
        right[i] = false;
    }
    string line;
    while (getline(cin, line) && !line.empty())
    {
    }
    cout << sum << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}

