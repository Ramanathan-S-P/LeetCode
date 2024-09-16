#include<stdlib.h>
convert(char *s){
    int h,min;
    sscanf(s,"%d:%d",&h,&min);
    min=h*60+min;
    
return min;
}
int cmp(const void* a, const void *b){
    return *((int*)a)-*((int *)b);
}
int findMinDifference(char** timePoints, int timePointsSize) {
    int arr[timePointsSize];
    for(int i=0;i<timePointsSize;i++){
         arr[i]=convert(timePoints[i]);
        //printf("%d-",arr[i]);
    }
    qsort(arr,timePointsSize,sizeof(int),cmp);
    int ans=abs(arr[0]-arr[timePointsSize-1]);
    int min= (ans>720)?1440-ans:ans;
    for(int i=1;i<timePointsSize;i++){
        ans=abs(arr[i]-arr[i-1]);
        if(ans>720){
            ans=1440-ans;
        }
        if(ans<min){
            min=ans;
        }
    }
    
    return min;
}