
struct node {
    int val;
    struct node * next;
    struct node * prev;
};

typedef struct {
    int size;
    struct node *head;
    struct node *top;
} CustomStack;


CustomStack* customStackCreate(int maxSize) {
  CustomStack *stk = malloc(sizeof(CustomStack));
    stk->size=maxSize;
    stk->head=NULL;
    stk->top=NULL;
    return stk;
}

void customStackPush(CustomStack* obj, int x) {
    if(obj->size>0){
    obj->size-=1;
    struct node * temp=malloc(sizeof(struct node));
    temp->val=x;
    temp->next=NULL;
    temp->prev=NULL;
        if(obj->top==NULL){
    obj->head=obj->top=temp;
        }
        else{
            temp->prev=obj->top;
            obj->top->next=temp;
            obj->top=temp;
        }
    }
    
}

int customStackPop(CustomStack* obj) {
    if(obj->top!=NULL){
        obj->size+=1;
       int item=obj->top->val;
        obj->top=obj->top->prev;
        return item;
    }
    return -1;
    
}

void customStackIncrement(CustomStack* obj, int k, int val) {
    struct node *temp=obj->head;
    for(int i=0;i<k&&temp!=NULL;i++){
        temp->val+=val;
        temp=temp->next;
    }
}

void customStackFree(CustomStack* obj) {
 free (obj);   
}

/**
 * Your CustomStack struct will be instantiated and called as such:
 * CustomStack* obj = customStackCreate(maxSize);
 * customStackPush(obj, x);
 
 * int param_2 = customStackPop(obj);
 
 * customStackIncrement(obj, k, val);
 
 * customStackFree(obj);
*/
