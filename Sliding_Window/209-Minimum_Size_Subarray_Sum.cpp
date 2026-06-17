/*
    Problem: 209. Minimum Size Subarray Sum
    Difficulty: Medium
    Pattern: Sliding Window (Dynamic Size)
    
    My notes: 
    - Unlike finding a fixed size 'K', we need to find the SHORTEST window that adds up to at least 'target'.
    - We use two pointers ('left' and 'right') to create a dynamic window.
    - The "Expand" Phase: Move the 'right' pointer forward, adding numbers to our 'current_sum' until we hit or exceed the target.
    - The "Shrink" Phase: Once 'current_sum >= target', we found a valid window! We record its length. 
      But can we do better? To find out, we try to shrink the window from the left by moving the 'left' pointer forward and subtracting its value from 'current_sum'.
    - We keep shrinking as long as the sum is still >= target.
    - Time Complexity: O(N) — Even though there is a nested while loop, both pointers only move forward. They each visit every element at most once.
    - Space Complexity: O(1)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low =0;
        int high=0;
        int res=INT_MAX;
        int sum=0;
        while(high<nums.size()){
            sum=sum+nums[high];
            while(sum>=target){
                int len=high-low+1;
                res=min(res,len);
                sum-=nums[low];
                low++;
            }
            high++;
        }
        if(res==INT_MAX)
            return 0;
        return res;
    }
};
