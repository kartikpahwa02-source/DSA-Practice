/*
    Problem: 141. Linked List Cycle
    Difficulty: Easy
    Pattern: Fast & Slow Pointers (Floyd's Tortoise and Hare)
    
    My notes: 
    - We need to detect if a Linked List loops back on itself (a cycle).
    - We use two pointers starting at the head: 'slow' and 'fast'.
    - 'slow' moves 1 step at a time.
    - 'fast' moves 2 steps at a time.
    - If there is NO cycle, 'fast' will eventually reach the end of the list (NULL).
    - If there IS a cycle, 'fast' will loop around and eventually "lap" 'slow', meaning they will point to the exact same node.
    - Important: Always check 'fast != NULL' AND 'fast->next != NULL' before moving fast twice to avoid Segmentation Faults!
    - Time Complexity: O(N) — In the worst case, 'fast' laps 'slow' in linear time.
    - Space Complexity: O(1) — We only use two pointers, no matter how big the list is.
*/

#include <iostream>

using namespace std;

// Definition for singly-linked list (Provided by LeetCode).
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;          
            fast = fast->next->next;    
            
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};
