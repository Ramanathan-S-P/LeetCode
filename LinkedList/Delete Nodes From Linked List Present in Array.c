/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//int hash[100001]= {0};
struct ListNode* modifiedList(int* arr, int cnt, struct ListNode* head) {
int hash[100001]={0};
    for(int i=0; i<cnt; i++) {
       // scanf("%d",&arr[i]);
        hash[arr[i]]=1;
    }
    struct ListNode* x=head;
    struct ListNode *y=head;
    struct ListNode *l=head;
    while(y!=NULL) {
        if(hash[y->val]) {
            if(y==x) {
                x=y->next;
                l=x;
            }
            else {
                l->next=y->next;
            }
        }
        else{
            
        l=y;
        }
        y=y->next;
    }
    head=x;

    return head;
}
