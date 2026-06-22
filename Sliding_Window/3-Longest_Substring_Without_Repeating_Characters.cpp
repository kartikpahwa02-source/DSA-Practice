/*
    Problem: 3. Longest Substring Without Repeating Characters
    Difficulty: Medium
    Pattern: Sliding Window (Dynamic) + Hash Map
    
    My notes: 
    - We need the longest window with NO duplicate characters.
    - We use an unordered_map<char, int> to track character frequencies.
    - The golden rule: In a valid window, the number of unique characters (map.size()) MUST equal the window size (high - low + 1).
    - If map.size() < window_size, it means a character is repeating! 
    - When a repeat happens, we shrink the window from the 'low' pointer until the duplicate is completely removed from the map.
    - Time Complexity: O(N) — Left and right pointers only move forward.
    - Space Complexity: O(1) — The map will hold at most 26 letters (or 256 ASCII characters), which is constant space.
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low = 0;
        int res = 0;
        unordered_map<char, int> f;
        
        for (int high = 0; high < s.size(); high++) {
            f[s[high]]++;
            
            
            int k = high - low + 1;
            
            
            while (f.size() < k) {
                f[s[low]]--;
                
                if (f[s[low]] == 0) {
                    f.erase(s[low]);
                }
                low++;
                
            
                k = high - low + 1; 
            }
            
            if (f.size() == k) {
                res = max(res, k);
            }
        }
        
        return res;
    }
};
