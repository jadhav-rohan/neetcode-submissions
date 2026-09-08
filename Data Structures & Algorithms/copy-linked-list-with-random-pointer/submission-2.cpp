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
        if (head == nullptr)
            return nullptr;

        Node* temp = head;
        
        while(temp){
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode->next;
        }

        temp = head;
        while(temp){
            Node* copyNode = temp->next;

            if(temp->random == nullptr){
                copyNode->random = nullptr;
            }
            else{
                copyNode->random = temp->random->next;
            }
            temp = copyNode->next;
        }

        temp = head;
        Node* dummyNode = new Node(-1);
        Node* res = dummyNode;
        while(temp){
            res->next = temp->next;
            res = res->next;
            
            temp->next = temp->next->next;
            temp = temp->next;
        }

        return dummyNode->next;
    }
};
