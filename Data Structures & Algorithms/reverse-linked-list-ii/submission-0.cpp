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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || left == right)
            return head;
    
        ListNode* curr = head, *next, *prev = nullptr;

        for(int i = 1; i< left; i++){
            prev = curr;
            curr = curr->next;
        }

        ListNode* before = prev;
        ListNode* start = curr;

        ListNode* revPrev = nullptr;

        for(int i = left; i<= right; i++){
            next = curr->next;
            curr->next = revPrev;

            revPrev = curr;
            curr = next;
        }

        if(before != nullptr){
            before->next = revPrev;
        }else{
            head = revPrev;
        }

        start->next = curr;

        return head;
    }
};