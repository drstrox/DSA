#include <bits/stdc++.h>
using namespace std;

// easy
// largest element in an array
int largest(vector<int> &arr)
{
    int maxelement = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > maxelement)
        {
            maxelement = arr[i];
        }
    }

    return maxelement;
}
// second largest element
int getSecondLargest(vector<int> &arr)
{
    int maxelement = arr[0];
    int slargest = -1;

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > maxelement)
        {
            slargest = maxelement;
            maxelement = arr[i];
        }
        else if (arr[i] < maxelement && arr[i] > slargest)
        {
            slargest = arr[i];
        }
    }

    return slargest;
}
// array is sorted or rotatedly sorted
bool check(vector<int> &nums)
{
    int count = 0; // Count of decreasing pairs
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (nums[i] > nums[(i + 1) % n])
        { // Compare current element with the next (wrap-around using modulo)
            count++;
            if (count > 1)
            { // More than one decreasing pair means invalid
                return false;
            }
        }
    }

    return true;
}
// removing duplicates from sorted array
int removeDuplicates(vector<int> &nums)
{
    int i = 0;
    for (int j = 1; j < nums.size(); j++)
    {
        if (nums[j] != nums[i])
        {
            nums[i + 1] = nums[j];
            i++;
        }
    }
    return i + 1;
}
// left rotate an array by one place


int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        cout << function(n);
    }
}