/*
    Problem: 1. Two Sum 
    Pattern: Hash Map
    My notes: 
    - We need to return INDICES, not values. If we sort the array to use Two Pointers, 
      we lose the original indices.
    - Solution: Use an unordered_map<number, index>. 
    - As we loop through, we calculate the "complement" (target - current_number).
    - If the complement is already in our map, we found our pair!
    - Time Complexity: O(N) because we only loop through the array once.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        int first,sec;
        for(int i=0;i<nums.size();i++){
            first=nums[i];
            sec=target-first;
            if(m.find(sec)!=m.end())
                return {i,m[sec]};
            m[first]=i;
        }
    return{};
    }
};
