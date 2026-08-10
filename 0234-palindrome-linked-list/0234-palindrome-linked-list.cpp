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
    bool isPalindrome(ListNode* head) {
        //mandatory for all slow fast ques
        ListNode* slow = head;
        ListNode* fast = head;

        // finding the middle
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;  //slow= 1 move
            fast = fast->next->next;  //fast= 2 moves
        }

        // reversing the second half
        //we need prev,next and here 'curr' used in reversing is 'slow'
        ListNode* prev = NULL;
        ListNode* nextNode = NULL;

        while (slow != NULL) {
            //mtlb jbtk slow null ho jaye tbtk ye chlao
            nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }

        // compare now both halves
        ListNode* first = head;
        ListNode* second = prev;
        while (second != NULL) {
            if (first->val != second->val) {
                return false;
            }
            first = first->next;
            second = second->next;
        }
        return true;
    }
};