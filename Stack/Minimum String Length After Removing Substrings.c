int top;
void push(char *arr,char c){
if(top==-1){
    printf("top-1\n");
    arr[++top]=c;
    return ;
}
if((arr[top]=='A' && c=='B')||(arr[top]=='C' && c=='D')){
    printf("if\n");
    arr[top]='\0';
    top--;
}
else{
    printf("else\n");
    arr[++top]=c;
}
}

int minLength(char * s){
char arr[100];
 top=-1;
for(int i=0;i<strlen(s);i++){
    push(arr,s[i]);
}
    printf("%s",arr);
    return top+1;
}
