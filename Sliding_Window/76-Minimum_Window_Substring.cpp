/*
    Problem: 76. Minimum Window Substring
    Difficulty: HARD
    Pattern: Sliding Window (Dynamic) + Hash Map
    
    My notes: 
    - This is the ultimate test of the Sliding Window pattern.
    - We use a map to track what characters we 'need'.
    - Instead of constantly comparing two maps (which is slow), we use a 'matched' counter.
    - Expand phase ('high'): Add characters to our window. If it's a character we need, and we haven't exceeded the required amount, increment 'matched'.
    - Shrink phase ('low'): Once 'matched' equals the total characters in 't', our window is valid! 
      We record the minimum length, then shrink from the left to see if we can make it even smaller.
    - If we remove a character from the left that causes our window to become invalid, we decrement 'matched' and stop shrinking.
    - Time Complexity: O(N) — Both pointers only move forward.
    - Space Complexity: O(1) — The hash maps store at most 128 ASCII characters.
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool same(unordered_map<char,int> &freq, unordered_map<char,int> &need) {
        for (auto it : need) {
            char required_char = it.first;
            int required_count = it.second;
            
            if (freq[required_char] < required_count) {
                return false;
            }
        }
        return true;       
    }
    
    string minWindow(string s, string t) {
        int low = 0;
        int high = 0;
        int res = INT_MAX;
        int start = 0;
        
        unordered_map<char,int> freq, need;
        
        for(int i = 0; i < t.size(); i++){
            need[t[i]]++;
        }
     
        for(high = 0; high < s.size(); high++){
            freq[s[high]]++;
            
            while(same(freq, need)){
                int len = high - low + 1;
                
                if(res > len){
                    res = len;
                    start = low;
                }
                
                freq[s[low]]--;
                low++;
            }
        }
        
        if(res == INT_MAX) return "";
        return s.substr(start, res);
    }
};
