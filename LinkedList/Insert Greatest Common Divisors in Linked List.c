/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int gcd(int a,int b){
    while(a!=0 && b!=0){
        if(a>b){
            a%=b;
        }
        else{
            b%=a;
        }
    }
    if(a==0){
        return b;
    }
    return a;
}
struct ListNode* insertGreatestCommonDivisors(struct ListNode* head){
struct ListNode* temp=head;
    while(temp->next!=NULL){
    struct ListNode*x=malloc(sizeof(struct ListNode));
    x->val=gcd(temp->val,temp->next->val);
    x->next=temp->next;
    temp->next=x;
    temp=temp->next->next;
}
    return head;
}
