#include "bits/stdc++.h"
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int res = n;

        for (int i = 0; i < n; i++)
        {
            int h, len;
            cin >> h >> len;

            if (len >= h)
                res--;
        }
        cout << res << endl;
    }
    return 0;
}