/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        if(head == NULL)return false;
        ListNode* ptr = head;

   
        while(ptr->next && ptr->next->next){
        ptr = ptr->next->next;
        head = head->next;
        if(ptr == head)return true;

        }
        return false;


    }
};