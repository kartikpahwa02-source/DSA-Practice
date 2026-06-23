/*
    Problem: 424. Longest Repeating Character Replacement
    Difficulty: Medium
    Pattern: Sliding Window (Dynamic) + Hash Map
    
    My notes: 
    - The core formula: (Window Size) - (Frequency of most common char) = Number of chars we need to replace.
    - If (Chars to replace > k), the window is invalid! We must shrink from the 'low' pointer.
    - We use an unordered_map to track character frequencies.
    - THE SECRET: 'max_count' tracks the historical maximum frequency of any single character in our window. 
      We do NOT need to decrease 'max_count' when we shrink the window. We only care about finding a new, LARGER 'max_count' to expand our max window size.
    - Time Complexity: O(N) — Left and right pointers only move forward.
    - Space Complexity: O(1) — The map only holds uppercase English letters (max 26 keys).
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;
class Solution {
public:
     
    int characterReplacement(string s, int k) {
        int low=0;
        int high=0;
        int res=-1;
        int max_count=0;
        unordered_map<char,int> freq;
       
        for(high=0;high<s.size();high++){
            freq[s[high]]++;
            int len=high-low+1;
            int max_count = max(max_count, freq[s[high]]);
            int diff=abs(len-max_count);
            while(diff>k){
                freq[s[low]]--;
                
                if(freq[s[low]]==0)
                    freq.erase(s[low]);
                low++;
                len=high-low+1;
                max_count=max(max_count, freq[s[high]]);
                diff=(len-max_count);
            }
            len=high-low+1;
            res=max(len,res);
        }
        return res;
    }
};
