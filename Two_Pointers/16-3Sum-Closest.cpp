#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = 0;
        int min_diff = INT_MAX; 
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n; i++){
            int j = i + 1;
            int k = n - 1;
            
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                int diff = abs(sum - target);
                
                if(diff < min_diff){
                    min_diff = diff;
                    res = sum;
                }
                
                if(sum == target){
                    return sum; 
                }
                else if(sum < target){
                    j++; 
                }
                else{
                    k--; 
                }
            }
        }
        return res;
    }
};
