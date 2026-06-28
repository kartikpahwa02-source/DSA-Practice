/*
    Problem: 53. Maximum Subarray
    Difficulty: Medium
    Pattern: Kadane's Algorithm (Dynamic Programming / Greedy)
    
    My notes: 
    - We need to find the contiguous subarray with the largest sum.
    - At every index, we make a choice: 
        1. Add the current element to our running total (`best_ending + a[i]`).
        2. OR, start a brand new subarray starting at the current element (`a[i]`).
    - We take whichever option is bigger! If our running total became negative, starting fresh is better.
    - We keep track of the highest `best_ending` we've ever seen in the `result` variable.
    - Note: The if/else block can also be written in one line as: `best_ending = max(a[i], a[i] + best_ending);`
    - Time Complexity: O(N) — We only loop through the array once.
    - Space Complexity: O(1) — We only use two variables to track our sums!
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& a) {
            int best_ending=a[0];
        int result=a[0];
        for(int i=1;i<a.size();i++){
           int v1=a[i]+best_ending;
           int v2=a[i];
           best_ending=max(v1,v2);
           result=max(result,best_ending);
           
        }
        return result;
};
