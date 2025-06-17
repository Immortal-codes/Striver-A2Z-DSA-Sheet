// Linked List Advanced Problems
// All problems are solved using Tortoise-Hare (Floyd), two pointers, recursion, and pointer manipulation.
// Each function assumes the basic structure of singly linked list:

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//--------------------------------------------------------
// 1. Find Middle of Linked List (Tortoise-Hare Method)
ListNode* findMiddle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

//--------------------------------------------------------
// 2. Reverse Linked List (Iterative)
ListNode* reverseListIterative(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr) {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

//--------------------------------------------------------
// 3. Reverse Linked List (Recursive)
ListNode* reverseListRecursive(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* newHead = reverseListRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}

//--------------------------------------------------------
// 4. Detect Loop in Linked List (Floyd's Cycle Detection)
bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

//--------------------------------------------------------
// 5. Find Starting Point of Loop
ListNode* detectCycleStart(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    bool cycle = false;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            cycle = true;
            break;
        }
    }
    if (!cycle) return nullptr;
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

//--------------------------------------------------------
// 6. Length of Loop in LL
int lengthOfCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            int count = 1;
            fast = fast->next;
            while (slow != fast) {
                count++;
                fast = fast->next;
            }
            return count;
        }
    }
    return 0;
}

//--------------------------------------------------------
// 7. Check if LL is Palindrome
ListNode* reverse(ListNode* head) {
    ListNode* prev = nullptr;
    while (head) {
        ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* second = reverse(slow->next);
    ListNode* first = head;
    while (second) {
        if (first->val != second->val) return false;
        first = first->next;
        second = second->next;
    }
    return true;
}

//--------------------------------------------------------
// 8. Segregate Odd and Even Nodes
ListNode* oddEvenList(ListNode* head) {
    if (!head) return nullptr;
    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* evenHead = even;

    while (even && even->next) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}

//--------------------------------------------------------
// 9. Remove Nth Node from End
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* first = &dummy;
    ListNode* second = &dummy;
    for (int i = 0; i <= n; ++i) first = first->next;
    while (first) {
        first = first->next;
        second = second->next;
    }
    second->next = second->next->next;
    return dummy.next;
}

//--------------------------------------------------------
// 10. Delete Middle Node of LL
ListNode* deleteMiddle(ListNode* head) {
    if (!head || !head->next) return nullptr;
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = slow->next;
    delete slow;
    return head;
}

//--------------------------------------------------------
// 11. Sort LL using Merge Sort
ListNode* merge(ListNode* l1, ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    if (l1->val < l2->val) {
        l1->next = merge(l1->next, l2);
        return l1;
    } else {
        l2->next = merge(l1, l2->next);
        return l2;
    }
}

ListNode* sortList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* mid = slow->next;
    slow->next = nullptr;
    ListNode* left = sortList(head);
    ListNode* right = sortList(mid);
    return merge(left, right);
}

//--------------------------------------------------------
// 12. Sort 0s, 1s, 2s by changing links
ListNode* sortColors(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* zeroDummy = new ListNode(0);
    ListNode* oneDummy = new ListNode(0);
    ListNode* twoDummy = new ListNode(0);
    ListNode* zero = zeroDummy, *one = oneDummy, *two = twoDummy;

    while (head) {
        if (head->val == 0) zero->next = head, zero = zero->next;
        else if (head->val == 1) one->next = head, one = one->next;
        else two->next = head, two = two->next;
        head = head->next;
    }
    zero->next = oneDummy->next ? oneDummy->next : twoDummy->next;
    one->next = twoDummy->next;
    two->next = nullptr;

    head = zeroDummy->next;
    delete zeroDummy, oneDummy, twoDummy;
    return head;
}

//--------------------------------------------------------
// 13. Find intersection point of Y-shaped LL
int getLength(ListNode* head) {
    int len = 0;
    while (head) len++, head = head->next;
    return len;
}

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    int lenA = getLength(headA);
    int lenB = getLength(headB);
    while (lenA > lenB) lenA--, headA = headA->next;
    while (lenB > lenA) lenB--, headB = headB->next;
    while (headA && headB) {
        if (headA == headB) return headA;
        headA = headA->next;
        headB = headB->next;
    }
    return nullptr;
}

//--------------------------------------------------------
// 14. Add 1 to Number in LL
ListNode* addOne(ListNode* head) {
    head = reverse(head);
    ListNode* curr = head;
    int carry = 1;
    while (curr) {
        int sum = curr->val + carry;
        curr->val = sum % 10;
        carry = sum / 10;
        if (!curr->next && carry) {
            curr->next = new ListNode(carry);
            carry = 0;
        }
        curr = curr->next;
    }
    return reverse(head);
}

//--------------------------------------------------------
// 15. Add Two Numbers in LL
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    int carry = 0;
    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) sum += l1->val, l1 = l1->next;
        if (l2) sum += l2->val, l2 = l2->next;
        curr->next = new ListNode(sum % 10);
        carry = sum / 10;
        curr = curr->next;
    }
    return dummy->next;
}
