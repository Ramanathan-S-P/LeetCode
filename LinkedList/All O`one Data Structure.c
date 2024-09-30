

struct node{
    char *s;
    int count;
    struct node *next;
};
typedef struct {
  struct node * h[SIZE];  
} AllOne;


AllOne* allOneCreate() {
    AllOne* list = malloc(sizeof(AllOne));
    for(int i=0;i<SIZE;i++){
        list->h[i]=NULL;
        
    }
    return list;
    
}

void allOneInc(AllOne* obj, char* key) {
printf("INC:");
    int len =strlen(key);
    struct node *temp=obj->h[len];
    while(temp&&strcmp(temp->s,key)){
     temp=temp->next;
  };
    if(temp){
        temp->count+=1;
    }
    else{
    temp=malloc(sizeof(struct node));
    temp->s=strdup(key);
    temp->count=1;
    temp->next=obj->h[len];
    obj->h[len]=temp;
    }
    printf("%s-%d\n",obj->h[len]->s,obj->h[len]->count);
}

void allOneDec(AllOne* obj, char* key) {
   printf("DEC:");
   int len =strlen(key);
    struct node *temp=obj->h[len];
    struct node* prev=temp;
    while(temp&&strcmp(temp->s,key)){
        prev=temp;
        temp=temp->next;
      
  };
    printf("%s-%d\n",obj->h[len]->s,obj->h[len]->count);
        if(!(temp->count-=1)){
            printf("%d\n",temp->count);
            prev->next=temp->next;
            if(temp==obj->h[len]){
                if(obj->h[len]->next){
                obj->h[len]=obj->h[len]->next;
                
            }
                else{
                    obj->h[len]=NULL;
                }
        }
        }

        
    
}

char* allOneGetMaxKey(AllOne* obj) {
    printf("max:");
int max=INT_MIN;
char *max_s="";
    for(int i=1;i<SIZE;i++){
        struct node * temp=obj->h[i];
        while(temp){
            if(temp->count>max){
                max=temp->count;
                max_s=strdup(temp->s);
            }
            temp=temp->next;
            
        }
    }
    printf("%s\n",max_s);
    return max_s;
}

char* allOneGetMinKey(AllOne* obj) {
    printf("min:");
    int min=INT_MAX;
char *min_s="";
    for(int i=1;i<SIZE;i++){
        struct node * temp=obj->h[i];
        while(temp){
            if(temp->count<min){
                min=temp->count;
                min_s=strdup(temp->s);
            }
            temp=temp->next;
            
        }
    }
      printf("%s\n",min_s);
    return min_s;
    
}

void allOneFree(AllOne* obj) {
    free(obj);
}

/**
 * Your AllOne struct will be instantiated and called as such:
 * AllOne* obj = allOneCreate();
 * allOneInc(obj, key);
 
 * allOneDec(obj, key);
 
 * char* param_3 = allOneGetMaxKey(obj);
 
 * char* param_4 = allOneGetMinKey(obj);
 
 * allOneFree(obj);
*/
