typedef struct {
      int book[1001][2];
      int count[1001][1001];
      int ind_len[1001];
      int len;
    
} MyCalendarTwo;
bool fun(int start,int end,int c_i,MyCalendarTwo* obj){
    for(int i=0;i<=obj->ind_len[c_i];i++){
          if(!((start>=obj->book[obj->count[c_i][i]][1])|| (start<obj->book[obj->count[c_i][i]][0]&&end<=obj->book[obj->count[c_i][i]][0]))){
              return false;
              
    }
    }
        return true;
}

MyCalendarTwo* myCalendarTwoCreate() {
    MyCalendarTwo* obj=malloc(sizeof(MyCalendarTwo));
    obj->len=-1;
    memset(obj->ind_len,-1,sizeof(int)*1001);
    
    return obj;
}

bool myCalendarTwoBook(MyCalendarTwo* obj, int start, int end) {
     int len=obj->len;
    int count=0;
    int ind[1001]={-1};
    int index=-1;
    for(int i=0;i<=len;i++){
       // printf("[%d %d]\n",obj->book[i][0],obj->book[i][1]);
        if(!((start>=obj->book[i][1])|| (start<obj->book[i][0]&&end<=obj->book[i][0]))){
            ind[++index]=i;
    if(!fun(start,end,i,obj)){
        
   
        return false;
    }        
    
        }
    }
    //printf("added: [%d %d]\n",start,end);
    obj->book[++len][0]=start;
    obj->book[len][1]=end;
    //obj->book_count[len]=1;
    obj->len+=1;
    for(int i=0;i<=index;i++){
        obj->count[ind[i]][++(obj->ind_len[ind[i]])]=len;
    }
    
    return true;
}

void myCalendarTwoFree(MyCalendarTwo* obj) {
   free(obj); 
}

/**
 * Your MyCalendarTwo struct will be instantiated and called as such:
 * MyCalendarTwo* obj = myCalendarTwoCreate();
 * bool param_1 = myCalendarTwoBook(obj, start, end);
 
 * myCalendarTwoFree(obj);
*/
