int  cmp(const void *a,const void *b){
    return *((int *)a)-*((int* )b);
}
int check(int *st,int top){
    int num=-1;
    for(int i=0;i<=top;i++){
        if(++num!=st[i]){
            return 0;
        }
    }
    return 1;
}
int maxChunksToSorted(int* arr, int arrSize) {
int st[arrSize];
int top=-1;
    int count=0;
    for(int i=0;i<arrSize;i++){
        st[++top]=arr[i];
        qsort(st,top+1,sizeof(int),cmp);
        int val=check(st,top);
        if(val){
            count++;
        }
    }
    
    return count;
    
}
