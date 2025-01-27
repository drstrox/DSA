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
// left rotate an array by k places (optimizing only the space complexity) (TIME:O(2n) SPACE:O(1) as an extra array of k elements is created)
void rotate(vector<int> arr, int d)
{
    if (d > arr.size())
    {
        d = d % arr.size();
    }

    reverse(arr, arr + d);
    reverse(arr + d, arr + n);
    reverse(arr, arr + n);
}
// right rotate an array by k places (brute force approach but optimized for time complexity) (IME:O(n+k) SPACE:O(k) as an extra array of k elements is created)
vector<int> rotateRight(vector<int> &arr, int k)
{
    int n = nums.size();
    k = k % n;
    vector<int> temp(k);

    // storing in temp
    for (int i = n - k; i < n; i++)
    {
        temp[i - (n - k)] = nums[i];
    }

    // shifting elements to right
    for (int i = n - k - 1; i >= 0; i--)
    {
        nums[i + k] = nums[i];
    }

    // storing back from temp
    for (int i = 0; i < k; i++)
    {
        nums[i] = temp[i];
    }

    return nums;
}
// moving zeroes to the end (brute force)  (TIME:O(2n) SPACE:O(n)))
vector<int> moveZeros(int n, vector<int> a)
{
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 0)
        {
            temp.push_back(a[i]);
        }
    }

    int nz = temp.size();
    for (int i = 0; i < nz; i++)
    {
        a[i] = temp[i];
    }

    for (int i = nz; i < n; i++)
    {
        a[i] = 0;
    }

    return a;
}
// moving zeroes to end (optimal solution) (TIME:O(n) SPACE:O(1))
void moveZeroes(vector<int> &nums)
{
    int j = -1;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            j = i;
            break;
        }
    }

    if (j == -1)
    {
        return;
    }

    for (int i = j + 1; i < n; i++)
    {
        if (nums[i] != 0)
        {
            swap(nums[i], nums[j]);
            j++;
        }
    }
}
OR void moveZeroes(vector<int> &nums)
{
    int j = 0; // Start from the beginning of the array
    int n = nums.size();

    // Move non-zero elements to the front
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
        {
            swap(nums[i], nums[j]);
            j++;
        }
    }
}
// union of two arrays (brute force) TIME=o((a.size()+b.size()) * (log st.size()+1))
vector<int> findUnion(vector<int> &a, vector<int> &b)
{
    set<int> st;
    for (int i = 0; i < a.size(); i++)
    {
        st.insert(a[i]);
    }
    for (int i = 0; i < b.size(); i++)
    {
        st.insert(b[i]);
    }
    vector<int> union_vec;
    for (auto i : st)
    {
        union_vec.push_back(i);
    }
}
// union of two arrays (optimal force)
vector<int> findUnion(vector<int> &a, vector<int> &b)
{

    int n1 = a.size();
    int n2 = b.size();
    int i = 0;
    int j = 0;
    vector<int> union_vec;

    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
        {
            if (union_vec.size() == 0 || union_vec.back() != a[i])
            {
                union_vec.push_back(a[i]);
            }
            i++;
        }
        else
        {
            if (union_vec.size() == 0 || union_vec.back() != b[j])
            {
                union_vec.push_back(b[j]);
            }
            j++;
        }
    }

    while (i < n1)
    {
        if (union_vec.size() == 0 || union_vec.back() != a[i])
        {
            union_vec.push_back(a[i]);
        }
        i++;
    }

    while (j < n2)
    {
        if (union_vec.size() == 0 || union_vec.back() != b[j])
        {
            union_vec.push_back(b[j]);
        }
        j++;
    }

    return union_vec;
}
// intersection of two sorted arrays (brute)
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    vector<int> ans;
    vector<int> vis(m, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr1[i] == arr2[j] && vis[j] == 0)
            {
                ans.push_back(arr1[i]);
                vis[j] = 1;
                break;
            }

            if (arr2[j] > arr1[i])
            {
                break;
            }
        }
    }

    return ans;
}
// intersection of two sorted arrays (optimal)
vector<int> findArrayIntersection(vector<int> &A, int n, vector<int> &B, int m)
{
    vector<int> ans;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (A[i] == B[j])
        {
            if (ans.empty() || ans.back() != A[i])
            {
                ans.push_back(A[i]);
            }
            i++;
            j++;
        }
        else if (A[i] < B[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return ans;
}
// intersection of two arrays (optimal)
vector<int> intersection(vector<int> &A, vector<int> &B)
{
    int n = A.size();
    int m = B.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    vector<int> ans;
    int i = 0, j = 0;

    while (i < n && j < m)
    {
        if (A[i] == B[j])
        {
            if (ans.empty() || ans.back() != A[i])
            {
                ans.push_back(A[i]);
            }
            i++;
            j++;
        }
        else if (A[i] < B[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    return ans;
}
// finding missing element in array (brute force) time=O(n^2)
int missingNumber(vector<int> &nums)
{
    int n = nums.size();

    for (int i = 0; i <= n; i++)
    {
        bool found = false;

        for (int j = 0; j < n; j++)
        {
            if (nums[j] == i)
            {
                found = true;
                break;
            }
        }

        if (!found)
        {
            return i;
        }
    }
    return -1;
}
// finding missing element in array (better approach) time=O(2n)
int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    vector<int> hash(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        hash[nums[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (hash[i] == 0)
        {
            return i;
        }
    }
    return -1;
}
// finding missing element in array (optimal) time=O(n)  //sum method  // not better as n can be huge then long long datatype must be required which is not feasible
int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    int sum = n * (n + 1) / 2;
    int sum2 = 0;

    for (int i = 0; i < n; i++)
    {
        sum2 = sum2 + nums[i];
    }

    return (sum - sum2);
}
// finding missing element in array (optimal) time=O(n)  //XOR method
int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    int xor1 = 0;
    int xor2 = 0;

    for (int i = 0; i < n; i++)
    {
        xor2 = xor2 ^ nums[i];
        xor1 = xor1 ^ (i + 1);
    }

    return xor1 ^ xor2;
}
// maximum consecutive ones (optimal)
int findMaxConsecutiveOnes(vector<int> &nums)
{
    int n = nums.size();
    int maxcons = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 1)
        {
            count++;
            maxcons = max(maxcons, count);
        }
        else
        {
            count = 0;
        }
    }
    return maxcons;
}
// Find the number that appears once, and other numbers twice. (brute force)
int singleNumber(vector<int> &nums)
{
    int n = nums.size();
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(nums[i]==nums[j]){
                count++;
            }
        }
        if(count==1){
            return nums[i];
        }
    }
    return -1;
}
// Find the number that appears once, and other numbers twice. (better) //hashing used
int singleNumber(vector<int> &nums)
{
    int n = nums.size();
    int maxi=nums[0];
    for (int i = 0; i < n; i++)
    {
        maxi=max(maxi,nums[i]);
    }

    vector<int> hash=(maxi+1,0);
    for(int i=0;i<n;i++){
        hash[nums[i]]++;
    }

    for(int i=0;i<maxi;i++){
        if(hash[i]==1){
            return i;
        }
    }
    return -1;
}
// Find the number that appears once, and other numbers twice. (better) //mapping used
int singleNumber(vector<int> &nums)
{
    int n = nums.size();
    map<long long, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[nums[i]]++;
    }

    for (auto i : mp)
    {
        if (i.second == 1)
        {
            return i.first;
        }
    }
    return -1;
}
// Find the number that appears once, and other numbers twice. (optimal)
int singleNumber(vector<int> &nums)
{
    int n = nums.size();
    int xor = 0;
    for (int i = 0; i < n; i++)
    {
        xor = xor ^ nums[i];
    }
    return xor;
}
// Longest subarray with given sum K(positives)




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