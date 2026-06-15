/*
    Problem: 75. Sort Colors 
    Pattern: Three pointers
    My notes: 
    - We need to rearrange array without any sort function , in order of 0's then 1's and 2's
    - Solution: Use Three pointers 
    - As we loop from end of array , we check whether element at end is 0,1 or 2.
    - If 0 we know it will be at front so we swap and check which no. is swapped until then no movement of leftward pointer.
    - if 1 we decrement the exploring pointer because it is  at its position.
    - if 2 we know it will be at the end of the array so we swap it at the end and decrement both exploring pointer and rightward pointer.
    - Time Complexity: O(N) because we only loop through the array once.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i =0; //leftward pointer
        int j=nums.size()-1; //exploring pointer 
        int k=nums.size()-1; //rightward pointer
        while(j>=i){
            if(nums[j]==0){
                swap(nums[i],nums[j]);
                i++;
                
            }
            else if(nums[j]==2){
                swap(nums[j],nums[k]);
                j--;
                k--;

            }
            else{
                j--;
            }
        }
            
        }
    
};
