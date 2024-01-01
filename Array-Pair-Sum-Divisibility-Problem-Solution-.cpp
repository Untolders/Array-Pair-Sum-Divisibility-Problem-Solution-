******************************************************  Question  ************************************************************************


Given an array of integers nums and a number k, write a function that returns true if given array can be divided into pairs such that sum of every pair is divisible by k.

Example 1 :

Input : 
nums = [9, 5, 7, 3]
k = 6
Output: 
True
Explanation: 
{(9, 3), (5, 7)} is a 
possible solution. 9 + 3 = 12 is divisible
by 6 and 7 + 5 = 12 is also divisible by 6.
Example 2:

Input : 
nums = [4, 4, 4]
k = 4
Output: 
False
Explanation: 
You can make 1 pair at max, leaving a single 4 unpaired.
Your Task:
You don't need to read or print anything. Your task is to complete the function canPair() which takes array nums and k as input parameter and returns true if array can be divided into pairs such that sum of every pair is divisible by k otherwise returns false.

Expected Time Complexity: O(n)
Expected Space Complexity : O(n)

Constraints:
1 <= length( nums ) <= 105
1 <= numsi <= 105
1 <= k <= 105




******************************************************  Solution  ************************************************************************

//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;



// } Driver Code Ends

class Solution {

  public:

    bool canPair(vector<int> nums, int k) {

        // Code here.

          int n=nums.size();

        if(n%2==1) return false;

        

        map<int,int>mp;

        int ans=0;

        

        

        for(auto &it:nums)

        {

            it= it%k; //to ensure we have (a+b)%k==0 we convert a to a%k and b to b%k

            //then we will need to check that case1) a==0 && b==0 or other case2) a=(k-b) because after taking the 

            //mod both a and b will become <k ,so for (a+b)%k==0  either of above two cases needs to 

            //be satisfied.

            // note k-b will be positive bcz b<k after taking mod

        }

        

        for(int i=0;i<n;i++)

        {

            int newVal= k-nums[i];

            

             if(nums[i]==0 && mp.find(0)!=mp.end()){ 

                 ans++;

                 mp.erase(0);

                 continue;

             }

           

         if(mp.find(newVal)!= mp.end())

            {

                ans++;

                mp.erase(newVal);

                

            }

            else{

                mp[nums[i]]++;

            }

        }

        return ans==(n/2);

                  

    }

};



//{ Driver Code Starts.

int main() {

    int tc;

    cin >> tc;

    while (tc--) {

        int n, k;

        cin >> n >> k;

        vector<int> nums(n);

        for (int i = 0; i < nums.size(); i++) cin >> nums[i];

        Solution ob;

        bool ans = ob.canPair(nums, k);

        if (ans)

            cout << "True\n";

        else

            cout << "False\n";

    }

    return 0;

}

// } Driver Code Ends
