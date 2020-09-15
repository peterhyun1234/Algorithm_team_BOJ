#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void qsort(vector<int> &arr, int low, int high)
{
    int pivot = arr[low - 1];
    int cur_low = low;
    int cur_high = high;

    while (cur_low < cur_high)
    {
        while ((cur_low <= cur_high) && (arr[cur_low] < pivot))
        {
            cur_low++;
        }

        while ((cur_low <= cur_high) && (arr[cur_high] > pivot))
        {
            cur_high--;
        }

        if (cur_low < cur_high)
        {
            int temp = arr[cur_low];
            arr[cur_low] = arr[cur_high];
            arr[cur_high] = temp;
        }
    }

    int temp = arr[cur_low];
    arr[cur_low] = arr[low - 1];
    arr[low - 1] = temp;

    pivot = cur_low;

    qsort(arr, low, pivot - 1);
    qsort(arr, pivot + 1, high);

    return;
}

void print_arr(vector<int> arr)
{
    for (int i = 0; i < arr.length(); i++)
    {
        cout << arr[i] << "\n";
    }
    return;
}

int main()
{
    vector<int> sample_arr = {6, 4, 2, 1, 5, 8, 7, 9, 3};

    qsort(sample_arr);

    print_arr(sample_arr);

    return 0;
}
