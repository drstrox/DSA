#include <bits/stdc++.h>
using namespace std;

// recursion
void printNos(int n)
{
    if (n == 0)
    {
        return;
    }
    // called before to avoid printing in reverse order
    printNos(n - 1);
    cout << n << " ";
}
void printGfg(int N)
{
    int count = N;
    cout << "GFG ";
    count--;
    if (count == 0)
    {
        return;
    }
    printGfg(N - 1);
}
int sumOfSeries(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n * n * n + sumOfSeries(n - 1);
}
int factorialofn(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * factorial(n - 1);
}
vector<long long> factorialNumberswithoutRecusion(long long n)
{
    vector<long long> result;
    long long fact = 1; // present number's factorial
    long long i = 1;    // present number which is being updated

    while (fact <= n)
    {
        result.push_back(fact);
        i++;
        fact = fact * i;
    }

    return result;

    //  vector <long long> result;
    //      if(n<=0){
    //          return result;
    //      }

    //      long long fact=1;
    //      for(long long i=1;i<n;i++){
    //          fact=fact*i;
    //          result.push_back(fact);
    //      }

    //      return result;
}
void reverseArray(vector<int> arr, int i)
{
    int n = arr.size();
    if (i >= n / 2)
        return;
    swap(arr[i], arr[n - i - 1]);
    reverseArray(arr, i + 1);
}
void reverseArray(vector<int> &arr)
{
    reverse(arr.begin(), arr.end());
}
bool isPalindrome(string s)
{
    int left = 0, right = s.length() - 1;
    while (left < right)
    {
        while (left < right && !isalnum(s[left]))
        {
            left++;
        }
        while (left < right && !isalnum(s[right]))
        {
            right--;
        }

        if (tolower(s[left]) != tolower(s[right]))
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}
int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

// hashing
// Function to count the frequency of all elements from 1 to N in the array.
vector<int> frequencyCount(vector<int> &arr)
{
    int n = arr.size();
    vector<int> hash(n, 0);

    for (int i = 0; i < n; i++)
    {
        hash[arr[i] - 1]++;
    }
    return hash;
}
// maximum possible frequency of an element after performing at most k operations.
int maxFrequency(vector<int> &nums, int k)
{
    //using sliding window 
    sort(nums.begin(), nums.end());
    long long total = 0;               //cumulative sum of the elements in the current window
    int left = 0, maxFreq = 0;

    for (int right = 0; right < nums.size(); ++right)
    {
        total += nums[right];
        while (static_cast<long long>(nums[right]) * (right - left + 1) > total + k)
        {
            total -= nums[left];
            ++left;
        }

        maxFreq = max(maxFreq, right - left + 1);
    }

    return maxFreq;
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