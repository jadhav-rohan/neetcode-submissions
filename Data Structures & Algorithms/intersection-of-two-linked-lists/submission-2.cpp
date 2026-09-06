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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int n = 0, m = 0;

        ListNode *t1 = headA, *t2 = headB;

        while(t1 != t2){
            if(t1) t1 = t1->next;
            if(t2) t2 = t2->next;

            if(t1 == t2) return t1;

            if(t1 == nullptr) t1 = headB;
            if(t2 == nullptr) t2 = headA;
        }
        
        return t1;
    }
};