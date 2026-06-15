/*
    Problem: 977. Squares of a Sorted Array
    Difficulty: Easy
    Pattern: Two Pointers 
    
    My notes: 
    - The array is sorted, BUT it contains negative numbers. A large negative number squared becomes a very large positive number.
    - This means the LARGEST squares will always be at either the extreme left (most negative) or extreme right (most positive) of the array.
    - We place 'left' at index 0 and 'right' at the last index.
    - We compare the absolute values. We take the larger one, square it, place it at the VERY END of our new result array, and move that pointer inward.
    - We build the result array backwards!
    - Time Complexity: O(N) — Only one pass through the array.
    - Space Complexity: O(N) — We have to create a new array to store the result.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        int j =n-1;
        vector <int> result(n);
        for(int k=n-1;k>=0;k--){
            int left_sq=nums[i]*nums[i];
            int right_sq=nums[j]*nums[j];
            if(left_sq<right_sq){
                result[k]=right_sq;
                j--;
            }
                else{
                    result[k]=left_sq;
                    i++;
                }
        }
          return result;

    }
  
};
