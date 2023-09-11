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
    //Merge 2 sorted lists
    ListNode* mergeTwoLists(ListNode* head1,ListNode* head2){
        if(head1==NULL){
            return head2;
        }
        if(head2==NULL){
            return head1;
        }
        ListNode* head=NULL;
        if(head1->val<=head2->val){
            head=head1;
            head->next=mergeTwoLists(head1->next,head2);
        }
        else{
            head=head2;
            head->next=mergeTwoLists(head1,head2->next);
        }
        return head;
    }
    ListNode* merge(vector<ListNode*>& lists,int s,int e){
        if(s==e){
            return lists[s];
        }
        if(e-s==1){
            ListNode* dummy=mergeTwoLists(lists[s],lists[e]);
            return dummy;
        }
        int m=s+(e-s)/2;
        ListNode* left=merge(lists,s,m);
        ListNode* right=merge(lists,m+1,e);
        return mergeTwoLists(left,right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int l=lists.size();
        if(l==0){
            return NULL;
        }
        return merge(lists,0,l-1);
    }
};