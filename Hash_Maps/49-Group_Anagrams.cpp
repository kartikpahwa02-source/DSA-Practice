/*
    Problem: 49. Group Anagrams
    Difficulty: Medium
    Pattern: Hash Map + Sorting
    
    My notes: 
    - The core trick: Anagrams contain the exact same letters. Therefore, if we sort them, they will equal the exact same string (e.g., "eat", "tea", and "ate" all become "aet").
    - We use this sorted string as our "key" or "label" in an unordered_map.
    - The map's value is a vector of strings, where we store the original, unsorted words.
    - After grouping them all by their sorted keys, we just iterate through the map and push the grouped vectors into our final result.
    - Time Complexity: O(N * K log K) — Where N is the number of strings and K is the maximum length of a string (because we sort each string).
    - Space Complexity: O(N * K) — To store all the strings in our hash map.
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        
        for(int i = 0; i < strs.size(); i++) {
            string temp = strs[i];
            string label = temp;
            
            // Sort the string to create the universal key for all its anagrams
            sort(label.begin(), label.end());
            
            // Group the original string under its sorted label
            m[label].push_back(temp);
        }
        
        vector<vector<string>> result;
        
        // Extract the grouped anagrams from the map
        for(auto s = m.begin(); s != m.end(); s++) {
            result.push_back(s->second);
        }
        
        return result;
    }
};
