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
    ListNode* merge(ListNode* head1, ListNode* head2) {

	if(head1 == NULL) {
		return head2;
	} 

	if(head2 == NULL) {
		return head1;
	}

	ListNode* head = NULL;
	if(head1->val < head2->val) {
		head = head1;
		head->next = merge(head1->next, head2);
	} else {
		head = head2;
		head->next = merge(head1, head2->next);
	}
	return head;

}

ListNode* getMidPoint(ListNode* head) {
	if(head == NULL) {
		return head;
	}

	ListNode* slow = head;
	ListNode* fast = head->next;

	while(fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;
	}

	return slow;
}

ListNode* mergeSort(ListNode* head) {
	if(head == NULL || head->next == NULL) {
		return head;
	}

	ListNode* mid = getMidPoint(head);
	ListNode* head1 = head;
	ListNode* head2 = mid->next;
	mid->next = NULL;

	head1 = mergeSort(head1);
	head2 = mergeSort(head2);

	head = merge(head1, head2);
	return head;
}

    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};