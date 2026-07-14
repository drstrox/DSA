#include <bits/stdc++.h>
using namespace std;
int countdigits()
{
    int dup = n;
    int count = 0;

    while (n > 0)
    {
        int digit = n % 10;
        n = n / 10;
        // avoiding the use of division by 0
        if (digit != 0 && dup % digit == 0)
        {
            count++;
        }
    }
    return count;
};
int reverse(int x)
{
    int reversed = 0;

    while (x > 0)
    {
        int digit = x % 10;
        x = x / 10;

        // Check for overflow or underflow
        if (reversed > (INT_MAX) / 10 || reversed < (INT_MIN) / 10)
        {
            return 0;
        }

        reversed = reversed * 10 + digit;
    }
    return reversed;
};
bool isPalindrome(int x)
{
    int dup = x;
    int reversed = 0;
    if (x < 0)
    {
        return false;
    }

    while (x != 0)
    {
        int digit = x % 10;
        x = x / 10;

        // Check for overflow or underflow
        if (reversed > (INT_MAX) / 10 || reversed < (INT_MIN) / 10)
        {
            return false;
        }
        reversed = reversed * 10 + digit;
    }

    if (reversed == dup)
    {
        return true;
    }
    else
    {
        return false;
    }
};
bool checkArmstrong(int n)
{
    int dup = n;
    int temp = n;
    int noofdigit = 0;
    int sum = 0;

    while (n > 0)
    {
        n /= 10;
        noofdigit++;
    }
    while (temp > 0)
    {
        int digit = temp % 10;
        temp /= 10;
        sum = sum + pow(digit, noofdigit);
    }

    if (dup == sum)
        return true;
    else
        return false;
}

int sumOfDivisors(int n)
{
    int sum = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                sum = sum + j;
                if ((i / j) != j)
                {
                    sum = sum + (i / j);
                }
            }
        }
    }
    return sum;
};
int minJumps(vector<int> &arr)
{
    int n = arr.size();
    if (n <= 1)
        return 0;

    if (arr[0] == 0)
        return -1; 

    int maxReach = arr[0]; // farthest index we can move towards the end
    int steps = arr[0];    // Steps left in the current range //renewed again
    int jumps = 1;         // total number of jumps //taken to be one initially from start as starting the loop from index=1

    for (int i = 1; i < n; i++)
    {
        // Check if we have reached the last index
        if (i == n - 1)
            return jumps;

        // Update maxReach for the current index
        maxReach = max(maxReach, i + arr[i]);

        // Use a step to move to the current index
        steps--;

        // If no steps are left
        if (steps == 0)
        {
            jumps++; // Increment jump count

            // Check if the current index is beyond maxReach
            if (i >= maxReach)
                return -1;

            // Reinitialize steps for the new range
            steps = maxReach - i;
        }
    }

    return -1;
}
vector<int> lcmAndGcd(int a, int b) {
        vector<int> lg;
        int x=a;
        int y=b;
        int gcd=1;
 
        //using euclidean algorithm for gcd calculation
        while(a>0 && b>0){
            if(a>b){
                a=a%b;
            }
            else{
                b=b%a;
            }
        }
        
        if(a==0){
            gcd=b;
        }
        else{
            gcd=a;
        }
        
        int lcm=(x*y)/gcd;
        lg.push_back(lcm);
        lg.push_back(gcd);
        return lg;
    }

