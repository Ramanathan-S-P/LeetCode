struct node{
    int val;
    struct node* next;
    struct node* prev;
    
};

typedef struct {
int size;
   //struct node *head;
   struct node *front;
    struct node *rear;
} MyCircularDeque;


MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque *q=malloc(sizeof(MyCircularDeque));
    q->size=k;
   // q->head=NULL;
    q->rear=NULL;
    q->front=NULL;
    return q;
    
    
}

bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
   // printf("\n");
    
   
  if(obj->front==NULL){
      obj->size-=1;
      struct node* temp=malloc(sizeof(struct node));
      temp->val=value;
      temp->next=NULL;
      temp->prev=NULL;
      
      obj->front=obj->rear=temp;
  }
    else if(obj->size!=0){
      obj->size-=1;
      struct node *temp=malloc(sizeof(struct node));
      temp->val=value;
      temp->prev=NULL;
      temp->next=obj->front;
      obj->front->prev=temp;
      obj->front=temp;
   
      
    }
    else{
    // struct node *t=obj->rear;
    // struct node *t2=obj->front;
    //      while(t2!=t){
    //     printf("%d->",t2->val);
    //     t2=t2->next;
    // }
    // printf("%d->",t2->val);
        return false;
    }
    // struct node *t=obj->rear;
    // struct node *t2=obj->front;
    //      while(t2!=t){
    //     printf("%d->",t2->val);
    //     t2=t2->next;
    // }
    // printf("%d->",t2->val);

    return  true;
    
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    //printf("\n");
     
   
   if(obj->front==NULL){
      obj->size-=1;
      struct node *temp=malloc(sizeof(struct node));
      temp->val=value;
      temp->next=NULL;
      temp->prev=NULL;
      
      obj->front=obj->rear=temp;
  }
    else if(obj->size!=0){
      obj->size-=1;
      struct node *temp=malloc(sizeof(struct node));
      temp->val=value;
      temp->prev=obj->rear;
      temp->next=NULL;
      obj->rear->next=temp;
      obj->rear=temp;
        
    }
    else{
   // struct node *t=obj->rear;
   //  struct node *t2=obj->front;
   //       while(t2!=t){
   //      printf("%d->",t2->val);
   //      t2=t2->next;
   //  }
   //  printf("%d->",t2->val);
        return false;
    }
    //  struct node *t=obj->rear;
    // struct node *t2=obj->front;
    //      while(t2!=t){
    //     printf("%d->",t2->val);
    //     t2=t2->next;
    // }
    // printf("%d->",t2->val);
    return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    // printf("\n");
     
    if(obj->front==NULL){
    //   struct node *t=obj->rear;
    // struct node *t2=obj->front;
    //      while(t2!=t){
    //     printf("%d->",t2->val);
    //     t2=t2->next;
    //}
   // printf("%d->",t2->val);
        return false;
    }
    else if(obj->front==obj->rear){
        obj->size+=1;
        obj->front=obj->rear=NULL;
    }
    else{
        obj->size+=1;
        obj->front=obj->front->next;
    }
    
    // struct node *t=obj->rear;
    // struct node *t2=obj->front;
    //      while(t2!=t){
    //     printf("%d->",t2->val);
    //     t2=t2->next;
    // }
    // printf("%d->",t2->val);
    return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
   // printf("\n");
     
    if(obj->front==NULL){
    //  struct node *t=obj->rear;
    // struct node *t2=obj->front;
    //      while(t2!=t){
    //     printf("%d->",t2->val);
    //     t2=t2->next;
    //}
   // printf("%d->",t2->val);
        return false;
    }
    else if(obj->front==obj->rear){
        obj->size+=1;
        obj->front=obj->rear=NULL;
    }
    else{
       
        obj->size+=1;
        obj->rear=obj->rear->prev;
    //   struct node *t=obj->rear;
    // struct node *t2=obj->front;
    //      while(t2!=t){
    //     printf("%d->",t2->val);
    //     t2=t2->next;
    // }
    // printf("%d->",t2->val);
    }
    return true;
    
}

int myCircularDequeGetFront(MyCircularDeque* obj) {
    if(obj->front==NULL){
        return -1;
    }
    
        return obj->front->val;

}

int myCircularDequeGetRear(MyCircularDeque* obj) {
    if(obj->front==NULL){
        return -1;
    }
    
        return obj->rear->val;
    return 0;
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    if(obj->front==NULL){
        return true;
    }
    return 0;
}

bool myCircularDequeIsFull(MyCircularDeque* obj) {
if(obj->size==0){
    return true;
}
    return 0;
}

void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj);
    
}

/**
 * Your MyCircularDeque struct will be instantiated and called as such:
 * MyCircularDeque* obj = myCircularDequeCreate(k);
 * bool param_1 = myCircularDequeInsertFront(obj, value);
 
 * bool param_2 = myCircularDequeInsertLast(obj, value);
 
 * bool param_3 = myCircularDequeDeleteFront(obj);
 
 * bool param_4 = myCircularDequeDeleteLast(obj);
 
 * int param_5 = myCircularDequeGetFront(obj);
 
 * int param_6 = myCircularDequeGetRear(obj);
 
 * bool param_7 = myCircularDequeIsEmpty(obj);
 
 * bool param_8 = myCircularDequeIsFull(obj);
 
 * myCircularDequeFree(obj);
*/
