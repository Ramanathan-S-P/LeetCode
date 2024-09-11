struct dir {
    char ch;
    struct dir *left;
    struct dir *right;
};
struct list {
    int key;
    int val;
    struct list * next;
    
};
struct list ** ar;
int find(int t1){
    return (t1%30001+30001)%30001;
}
int dist(int x1, int y1) {
    
    return  (int) (pow(x1,2)+pow(y1,2));
    
}
int check(int t1,int t2){
    int index=find(t1);
   // printf("%d::%d\n",index,t1);
    struct list *temp=ar[index];
    while(temp!=NULL){
      //  printf("%d--%d::%d--%d\n",t1,temp->key,t2,temp->val);
        if(temp->key==t1&&temp->val==t2){
        
            return 1;
        }
        else{
            temp=temp->next;
        }
        
    }
    return 0;
}
    
void pos(int *x,int *y,int ch,int mov) {
    //printf("before:%d-%d\n",*x,*y);
    int t1=*x;
    int t2=*y;
    if(ch=='n') {
        for(int i=0;i<mov;i++){
            t2+=1;
                if(!check(t1,t2)){
                    *x=t1;
                    *y=t2;
                    //printf("after:%d-%d\n",*x,*y);
                }
            else{
                break;
            }
            
    }
    }
    else if(ch=='e') {
         for(int i=0;i<mov;i++){
            t1+=1;
                if(!check(t1,t2)){
                    *x=t1;
                    *y=t2;
                    //printf("after:%d-%d\n",*x,*y);
                }
            else{
                break;
            }
            
    }
    }
    else if(ch=='s') {
         for(int i=0;i<mov;i++){
            t2-=1;
                 if(!check(t1,t2)){
                    *x=t1;
                    *y=t2;
                   // printf("after:%d-%d\n",*x,*y);
                }
            else{
                break;
            }
    }
    }
    else {
         for(int i=0;i<mov;i++){
            t1-=1;
             if(!check(t1,t2)){
                    *x=t1;
                    *y=t2;
                    //printf("after:%d-%d\n",*x,*y);
                }
            else{
                break;
            }
    }
    }

}


int robotSim(int* arr, int len, int** hud, int on, int* obstaclesColSize) {
int max=0;
ar=malloc(sizeof(struct list *)*30001);
    for(int i=0;i<30001;i++){
        ar[i]=NULL;
    }
    for(int i=0;i<on;i++){
        int index =find(hud[i][0]);
        struct list * tem=malloc(sizeof(struct list));
        tem->key=hud[i][0];
        tem->val=hud[i][1];
        tem->next=NULL;
        if(ar[index]!=NULL){
            struct list * temp=ar[index];
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=tem;
            
        }
        else{
            ar[index]=tem;
        }
    }
    struct dir *a=malloc(sizeof(struct dir));
    struct dir *b=malloc(sizeof(struct dir));
    struct dir *c=malloc(sizeof(struct dir));
    struct dir *d=malloc(sizeof(struct dir));

    a->ch='n';
    b->ch='e';
    c->ch='w';
    d->ch='s';
    a->right=b;
    a->left=c;
    b->right=d;
    b->left=a;
    c->left=d;
    c->right=a;
    d->left=b;
    d->right=c;
    struct dir *temp=a;
        int x=0,y=0;
    int u,v;
    u=x;
    v=y;
    for(int i=0; i<len; i++) {
       // scanf("%d",&arr[i]);
        if(arr[i]==-1) {
            temp=temp->right;
        }
        else if(arr[i]==-2) {
            temp=temp->left;
        }
        else {
            pos(&x,&y,temp->ch,arr[i]);
            int dq= dist(x,y);
            if(dq>max) {
                max=dq;
                u=x;
                v=y;

            }
        }

    }
   // printf("maxdist=%d\n(x,y)=(%d,%d)",max,u,v);
    return max;
}
