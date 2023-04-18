/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode *newList = new ListNode();
        ListNode *head = newList;


        while(list1 && list2){
            if(list1->val > list2->val){
                ListNode *temp = new ListNode(list2->val);
                head->next = temp;
                head = temp;
                list2 = list2->next;
            }
            else if(list1->val < list2->val){
                ListNode *temp = new ListNode(list1->val);
                head->next = temp;
                head = temp;
                list1 = list1->next;
            }
            else{
                ListNode *temp = new ListNode(list2->val);
                head->next = temp;
                head = temp;
                list2 = list2->next;
            }
        }
        if(list2){
            head ->next = list2;
        }
        if(list1){
            head->next = list1;
        }
        newList = newList->next;

        return newList;
    }
};