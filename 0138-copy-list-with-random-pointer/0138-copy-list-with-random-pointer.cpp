/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        Node* temp = head;
        Node* nex = NULL;

        while(temp){
            nex = temp->next;
            Node* newNode = new Node(temp->val);
            newNode->next = nex;
            temp->next = newNode;
            temp = nex;
        }
        temp = head;
        nex = NULL;
        while(temp){
            nex = temp->next->next;
            if(temp->random != NULL)
                temp->next->random = temp->random->next; 
            temp = nex;
        }
        temp = head;
        nex = NULL;

        Node* pseudoNode = new Node(0);
        Node* copy = pseudoNode;

       while(temp){
            nex = temp->next->next;
            copy->next = temp->next;
           temp->next = nex;
           copy = copy->next;
            
            temp = nex;
        }
        return pseudoNode->next;
    }
};