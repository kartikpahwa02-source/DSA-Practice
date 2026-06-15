/*
    Problem: 26. Remove Duplicates from Sorted Array
    Difficulty: Easy
    Pattern: Two Pointers (Slow & Fast Pointers)
    
    My notes: 
    - The array is already sorted, which guarantees that all duplicates are sitting right next to each other.
    - We need to modify the array "in-place" (O(1) space), so we use two pointers starting at the same end.
    - 'slow' pointer: Keeps track of where the last unique number was placed.
    - 'fast' pointer: Scans ahead looking for new, different numbers.
    - If nums[fast] != nums[slow], it means we found a new unique number! We move 'slow' forward by one, and overwrite it with the 'fast' value.
    - Since 'slow' is an index, the total number of unique elements is 'slow + 1'.
    - Time Complexity: O(N)
    - Space Complexity: O(1)
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i =0; //slow pointer
        for(int j=1;j<nums.size();j++){ //fast pointer
            if(nums[i]!=nums[j]){
                i++;
                nums[i]=nums[j];
            }
        }
        return i+1;
    }
};
