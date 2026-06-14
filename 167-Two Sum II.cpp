/*
    Problem: 167. Two Sum II - Input Array Is Sorted
    Difficulty: Medium
    Pattern: Two Pointers
    
    My notes: 
    - The array is ALREADY sorted, which is the massive clue to use Two Pointers instead of a Hash Map.
    - Put left pointer at index 0, right pointer at the last index.
    - If sum < target: we need a bigger number -> move left pointer right (left++).
    - If sum > target: we need a smaller number -> move right pointer left (right--).
    - Note: The problem asks for 1-indexed answers, so return {left + 1, right + 1}.
    - Time Complexity: O(N)
    - Space Complexity: O(1)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        while(i<j){
            if(nums[i]+nums[j]==target)
                return {i+1,j+1};
            else if(nums[i]+nums[j]>target)
                j--;
            else
                i++;

        }
        return {};
    }
};
