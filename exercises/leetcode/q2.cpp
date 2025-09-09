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

#include <cmath>
#include <memory>

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        auto carry = 0;
        auto sum = 0;
        auto l1val = 0;
        auto l2val = 0;

        while (l1 || l2 || carry)
        {
            sum = carry;

            if (l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = std::floor(sum / 10);

            auto n = new ListNode(sum % 10);

            if (!head)
            {
                head = n;
                tail = n;
            }
            else
            {
                tail->next = n;
                tail = tail->next;
            }
        }

        return head;
    }
};
