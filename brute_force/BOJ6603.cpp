#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    cin >> K;
    while (K != 0)
    {
        vector<int> nums(K), choose(K, 0);
        for (int i = 0; i < K; i++)
        {
            cin >> nums[i];
        }
        for (int i = 0; i < 6; i++)
            choose[i] = 1;

        sort(nums.begin(), nums.end());

        do
        {
            for (int i = 0; i < K; i++)
            {
                if (choose[i] == 1)
                    cout << nums[i] << ' ';
            }
            cout << '\n';
        } while (prev_permutation(choose.begin(), choose.end()));
        cout << '\n';
        cin >> K;
    }
}