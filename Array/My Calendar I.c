


typedef struct {
    int book[1001][2];
    int len;
} MyCalendar;


MyCalendar* myCalendarCreate() {
    MyCalendar* obj=malloc(sizeof(MyCalendar));
    obj->len=-1;
    return obj;
}

bool myCalendarBook(MyCalendar* obj, int start, int end) {
    int len=obj->len;
    for(int i=0;i<=len;i++){
       // printf("[%d %d]\n",obj->book[i][0],obj->book[i][1]);
        if(!((start>=obj->book[i][1])|| (start<obj->book[i][0]&&end<=obj->book[i][0]))){
            
            return false;
        }
    }
    //printf("added: [%d %d]\n",start,end);
    obj->book[++len][0]=start;
    obj->book[len][1]=end;
    obj->len+=1;
    return true;
    
}

void myCalendarFree(MyCalendar* obj) {
    free (obj);
}

/**
 * Your MyCalendar struct will be instantiated and called as such:
 * MyCalendar* obj = myCalendarCreate();
 * bool param_1 = myCalendarBook(obj, start, end);
 
 * myCalendarFree(obj);
*/
