/*
    Problem: Longest Substring with K Distinct Characters(geeksforgeeks)
    Difficulty: Medium
    Pattern: Sliding Window (Dynamic) + Hash Map
    
    My notes: 
    - We need the LONGEST window that contains exactly 'K' unique characters.
    - We use an unordered_map to keep track of how many times we've seen each character in our current window.
    - 'high' pointer: Expands the window by adding the current character to the map.
    - 'low' pointer: Shrinks the window if our map size (unique characters) gets strictly greater than K.
    - When shrinking, we decrease the character's frequency. If it hits 0, WE MUST ERASE IT from the map, otherwise map.size() stays incorrectly high.
    - If map.size() == k, we calculate the window length and update our max result.
    - Time Complexity: O(N)
    - Space Complexity: O(K) for the map.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
  public:
    int longestKSubstr(string s, int k) {
        int low = 0;
        int res = -1; 
        unordered_map<char, int> f;
        
        for(int high = 0; high < s.size(); high++) {
            
            f[s[high]]++; 
            while(f.size() > k) {
                f[s[low]]--; 
                if(f[s[low]] == 0) {
                    f.erase(s[low]);
                low++;
                }
            
            if(f.size() == k) {
                int len = high - low + 1;
                res = max(len, res);
            }
        }
        
        return res;
    }
};
