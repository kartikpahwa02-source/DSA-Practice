/*
    Problem: 1186. Maximum Subarray Sum with One Deletion
    Difficulty: Medium (Borderline Hard)
    Pattern: State Machine Dynamic Programming / Advanced Kadane's
    
    My notes: 
    - We have the superpower to delete AT MOST ONE number from our subarray to maximize the sum.
    - We track two parallel states (universes) at every step:
        1. 'no_delete': The max sum ending here if we haven't deleted anything yet (Standard Kadane's).
        2. 'one_delete': The max sum ending here if we HAVE deleted exactly one element.
    - To calculate 'one_delete' at the current step, we take the max of:
        A) We already used our deletion in the past, so we MUST add the current number: (one_delete + a[i])
        B) We choose to use our deletion on the current number RIGHT NOW. So we take the previous 'no_delete' sum and skip a[i].
    - We update our global 'result' by comparing it against both states at every step.
    - Time Complexity: O(N) — One single pass!
    - Space Complexity: O(1) — We compressed an entire 2D DP grid into just two integer variables.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& a) {
        int no_delete = a;
        int one_delete = 0;
        int result = a;
        
        for(int i = 1; i < a.size(); i++){
            one_delete = max(one_delete + a[i], no_delete);
            
            no_delete = max(a[i] + no_delete, a[i]);
        
            result = max(result, max(no_delete, one_delete));
        }
        
        return result;
    }
};
