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

        while (t1) {
            n++;
            t1 = t1->next;
        }
        while (t2) {
            m++;
            t2 = t2->next;
        }
        t1 = headA;
        t2 = headB;
        int diff = 0;
        if (n > m) {
            diff = n - m;
            while (diff) {
                t1 = t1->next;
                diff--;
            }
        } else {
            diff = m - n;
            while (diff) {
                t2 = t2->next;
                diff--;
            }
        }

        while (t1 && t2) {
            if (t1 == t2) {
                return t1;
            }
            t1 = t1->next;
            t2 = t2->next;
        }

        return nullptr;
    }
};