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
// removing duplicates from {sorted array} (brute force approach)
int removeDuplicates(vector<int> &nums)
{
    set<int> st;
    for (int j = 0; j < nums.size(); j++)
    {
        st.insert(nums[j]);
    }

    int value = 0;
    for (auto i : st)
    {
        nums[value] = i;
        value++;
    }
    return value;
}
// removing duplicates from {sorted array}  (optimized approach)
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
// removing duplicates from {sorted array}  (optimized approach) (unique element appears at most twice)
int removeDuplicates(vector<int> &nums)
{
    if (nums.size() <= 2)
        return nums.size();

    int i = 1;
    int count = 1;

    for (int j = 1; j < nums.size(); j++)
    {
        if (nums[j] == nums[j - 1])
        {
            count++;
        }
        else
        {
            count = 1;
        }

        if (count <= 2)
        {
            nums[i] = nums[j];
            i++;
        }
    }
    return i;
}
// left rotate an array by one place (brute force approach) (TIME:O(n) SPACE:O(n) as an extra array is created to solve the prob.)
vector<int> rotateArray(vector<int> &arr, int n)
{
    vector<int> temp[n];
    for (int i = 1; i < n; i++)
    {
        temp[i - 1] = arr[i];
    }
    temp[n - 1] = arr[0];
    return temp;
}
// left rotate an array by one place (optimal approach) (in place algorithm) (TIME:O(n) SPACE:O(1) as no extra array is created to solve the prob.)
vector<int> rotateArray(vector<int> &arr, int n)
{
    int temp = arr[0];
    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
    return arr;
}
// left rotate an array by k places (brute force approach) (TIME:O(n+k) SPACE:O(k) as an extra array of k elements is created)
vector<int> rotateArray(vector<int> arr, int k)
{
    int n = arr.size();
    k = k % n;
    
    vector<int> temp(k);
    for (int i = 0; i < k; i++)
    {
        temp[i] = arr[i];
    }

    for (int j = k; j < n; j++)
    {
        arr[j - k] = arr[j];
    }

    for (int j = n - k; j < n; j++)
    {
        arr[j] = temp[j - (n - k)];
    }

    return arr;
}

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