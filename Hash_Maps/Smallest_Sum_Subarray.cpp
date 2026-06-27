/*
    Problem: Smallest Sum Subarray (GeeksforGeeks)
    Difficulty: Medium
    Pattern: Kadane's Algorithm 
    
    My notes: 
    - This is the exact opposite of the Maximum Subarray problem!
    - Instead of looking for the largest sum, we want the smallest (most negative) sum.
    - At every index, we make a choice: "Does adding my running total to the current element make it SMALLER than just starting fresh at the current element?"
    - If 'best_ending' is positive, adding it makes our sum worse. Start fresh!
    - If 'best_ending' is negative, adding it makes our sum better (smaller). Keep extending the subarray!
    - We track the absolute minimum sum seen so far in 'result'.
    - Time Complexity: O(N) — One single pass through the array.
    - Space Complexity: O(1) — Only two variables used.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int smallestSumSubarray(vector<int>& a) {
        int best_ending = a;
        int result = a;
        
        for (int i = 1; i < a.size(); i++) {
            
            if (a[i] + best_ending < a[i]) {
                best_ending = a[i] + best_ending;
            } else {
                best_ending = a[i]; 
            }
            
            if (result > best_ending) {
                result = best_ending;
            }
        }
        
        return result;
    }
};
