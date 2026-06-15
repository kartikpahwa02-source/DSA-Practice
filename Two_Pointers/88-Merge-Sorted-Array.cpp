/*
    Problem: 88. Merge Sorted Array
    Difficulty: Easy
    Pattern: Two Pointers (Reverse / End-to-Beginning)
    
    My notes: 
    - We need to merge nums2 into nums1. nums1 has extra space (0s) at the end to hold everything.
    - The trap: If we start comparing from the beginning (index 0), we will accidentally overwrite numbers in nums1 that we haven't looked at yet!
    - The secret: Start from the BACK.
    - Set 'p1' to the last real number in nums1 (m - 1).
    - Set 'p2' to the last number in nums2 (n - 1).
    - Set 'p' to the very last open slot in nums1 (m + n - 1).
    - Compare nums1[p1] and nums2[p2]. Put the LARGER one at nums1[p], then move the pointers backward.
    - Time Complexity: O(M + N)
    - Space Complexity: O(1) — We modify nums1 completely in-place without extra memory!
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    void merge(vector<int>& arr1, int m, vector<int>& arr2, int n) {
        vector<int> res(m+n);
        int i=0,j=0,k=0;
        while(i<m && j<n){
            if(arr1[i]<arr2[j])
                res[k++]=arr1[i++];
            else
                res[k++]=arr2[j++];
        }

        while(i<m)
            res[k++]=arr1[i++];
        
        while(j<n)
            res[k++]=arr2[j++];
        
        for(int i=0;i<res.size();i++)
            arr1[i]=res[i];
    }
};
