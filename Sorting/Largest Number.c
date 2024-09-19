int cmp(const void *a,const void *b) {
    int *x=((int*)a);
    int *y=((int*)b);
   //  char *s1=malloc(sizeof(char)*(int)pow(10,11));
    //char *s2=malloc(sizeof(char)*(int)pow(10,11));
    char s1[22];
    char s2[22];
    
    sprintf(s1,"%d%d",*x,*y);
   
    sprintf(s2,"%d%d",*y,*x);
   //  printf("%s\n",s1);
    //printf("%s\n",s2);
  //printf("%d",strcmp(s2,s1));
    return strcmp(s2,s1);
}




char* largestNumber(int* a, int n) {
  qsort(a,n,sizeof(int ),cmp);
    /*for(int i=0; i<n; i++) {
        printf("%d-\n",a[i]);
    }*/
    int pos=0;
    char *s=malloc(sizeof(char)*1100);
    for(int i=0;i<n;i++){
        pos+=sprintf(s+pos,"%d",a[i]);
    }
   // printf("\n%s",s);
    int num;
    sscanf(s,"%d",&num);
    if(num==0){
        sprintf(s,"%d",0);
    }
    return s;
        
}
