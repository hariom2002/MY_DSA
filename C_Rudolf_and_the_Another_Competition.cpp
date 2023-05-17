#include "bits/stdc++.h"
using namespace std;

bool cmp(vector<int> a, vector<int> b)
{
    if (a[0] > b[0])
        return true;
    if (a[0] == b[0])
        return (a[1] < b[1]) ? true : false;
    else
        return false;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m, t;
        cin >> n >> m >> t;

        vector<vector<int>> result;
        for (int i = 0; i < n; i++)
        {
            vector<int> temp;
            for (int j = 0; j < m; j++)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            sort(temp.begin(), temp.end());

            int pnlt = 0;
            int prev = 0;
            int pnts = 0;

            int time_0 = 0;

            for (int j = 0; j < m; j++)
            {
                if (temp[j] <= (t - time_0))
                {
                    pnlt += temp[j] + prev;
                    prev = pnlt;
                    pnts++;
                    time_0 += temp[j];
                }
            }
            vector<int> temp2;
            temp2.push_back(pnts);
            temp2.push_back(pnlt);
            temp2.push_back(i);
            result.push_back(temp2);
        }

        sort(result.begin(), result.end(), cmp);
        cout << "result.size " << result.size() << endl;

        for (int j = 0; j < result.size(); j++)
        {
            if (result[j][2] == 1)
            {
                cout << j + 1 << endl;
                break;
            }
        }

        // for (int j = 0; j < result.size(); j++)
        // {
        //     cout << result[j][2] << endl;
        // }
        // return 0;
    }
    return 0;
}