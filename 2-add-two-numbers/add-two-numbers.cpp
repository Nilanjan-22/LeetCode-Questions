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
    ListNode* removelast(ListNode* head){
        if(head==NULL || head->next==NULL)return NULL;

        ListNode* move=head;
        while(move->next->next!=NULL)move=move->next;
        move->next=NULL;
        return head;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int hand=0,sum=0;
        ListNode* m1=l1;
        ListNode* m2=l2;

        ListNode* ans= new ListNode(0);
        ListNode* m3=ans;
        while(m1!=NULL && m2!=NULL){
            sum= hand+ m1->val+m2->val;
            hand = sum/10;
            m3->val=sum%10;
            m3->next= new ListNode(0);
            m3=m3->next;
            m2=m2->next;
            m1=m1->next;
        }
        while(m1!=NULL){
            sum= hand+ m1->val;
            hand = sum/10;
            m3->val=sum%10;
            m3->next= new ListNode(0);
            m3=m3->next;
            m1=m1->next;
        }
        while(m2!=NULL){
            sum= hand+ m2->val;
            hand = sum/10;
            m3->val=sum%10;
            m3->next= new ListNode(0);
            m3=m3->next;
            m2=m2->next;
        }

        if(hand!=0){
            m3->val=hand;
            m3->next= new ListNode(0);
        }
        
        ans=removelast(ans);
        return ans;


    
    }
};