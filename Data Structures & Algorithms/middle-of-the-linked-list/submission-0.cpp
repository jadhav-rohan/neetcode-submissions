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
    ListNode* middleNode(ListNode* head) {
        int n = 0;
        ListNode* dup = head;
        while(dup != nullptr){
            n++;
            dup = dup->next;
        }
        int mid = 0;
        mid = (n / 2);

        while(mid > 0){
            head = head->next;
            mid--;
        }


        return head;
    }
};