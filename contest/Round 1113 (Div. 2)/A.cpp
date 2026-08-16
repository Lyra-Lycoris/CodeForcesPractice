#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        string s;
        cin >> s;

        bool deletedZero = false;
        bool deletedOne = false;

        for (char c : s)
        {
            if (c == '0' && !deletedZero)
            {
                deletedZero = true;
                continue;
            }

            if (c == '1' && !deletedOne)
            {
                deletedOne = true;
                continue;
            }

            cout << c;
        }

        cout << '\n';
    }

    return 0;
}