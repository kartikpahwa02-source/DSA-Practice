/*
    Problem: 904. Fruit Into Baskets
    Difficulty: Medium
    Pattern: Sliding Window (Dynamic) + Hash Map
    
    My notes: 
    - Don't let the story confuse you. This is literally just "Find the longest subarray with at most 2 distinct elements."
    - We use a sliding window with 'low' and 'high' pointers.
    - An unordered_map keeps track of the types of fruit and their frequencies in our current window.
    - If map.size() > 2 (we picked a 3rd type of fruit), our baskets are full! We must shrink the window from the left.
    - We decrement the frequency of the fruit at the 'low' pointer. If it hits 0, we ERASE it from the map so the size drops back to 2.
    - We update our max length at every valid step.
    - Time Complexity: O(N) — Each element is processed by 'high' and 'low' at most once.
    - Space Complexity: O(1) — The map never holds more than 3 elements at a time!
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int low = 0;
        int res = -1; // -1 is a safe baseline, or 0 works too here since fruit arrays are rarely empty
        unordered_map<int, int> tree;
        
        for(int high = 0; high < fruits.size(); high++) {
            tree[fruits[high]]++;
            
            // If we have more than 2 types of fruit, shrink the window
            while(tree.size() > 2) {
                tree[fruits[low]]--;
                
                if(tree[fruits[low]] == 0) {
                    tree.erase(fruits[low]);
                }
                low++;
            }
           
            // Calculate the valid window length
            int len = high - low + 1;
            res = max(len, res);
        }
        
        // Edge case handling if the array was totally empty
        if(res == -1) return 0;
        return res;
    }
};
