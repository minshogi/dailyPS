#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int calc(int *A, int N)
{
    int sum = 0;
    for (int i = 1; i < N; i++)
    {
        sum += abs(A[i - 1] - A[i]);
    }
    return sum;
}

int main()
{
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    int max = -1;
    sort(A, A + N);

    do
    {
        int tmp = calc(A, N);
        if (tmp > max)
            max = tmp;
    } while (next_permutation(A, A + N));

    cout << max << '\n';
}