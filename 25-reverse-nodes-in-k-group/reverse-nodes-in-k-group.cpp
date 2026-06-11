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
    ListNode* reverse(ListNode* first, ListNode* last){
        ListNode* cur=first;
        ListNode* front=NULL;
        while(cur!=NULL){
            ListNode* temp=cur->next;
            cur->next=front;
            front=cur;
            cur=temp;
        }
        return last;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1)return head;
        ListNode* first=head;
        ListNode* prev=NULL;
        ListNode* last=head;
        ListNode* next=NULL;
        ListNode* ans=head;
        int cnt=k-1;
        bool inBetween=false;
        while(last!=NULL){
            last=last->next;
            cnt--;
            inBetween=true;
            if(cnt==0 && last!=NULL){
                next=last->next;
                last->next=NULL;
                reverse(first,last);
                if(prev!=NULL){
                    prev->next=last;
                }
                else{
                    ans=last;
                }
                prev=first;
                last=next;
                first=next;
                cnt=k-1;
                inBetween=false;
            }
        }
        if(inBetween){
            prev->next=next;
        }
        return ans;

    }
};