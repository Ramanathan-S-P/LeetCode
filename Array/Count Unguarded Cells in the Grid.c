
int count;
void traverse(int i, int j,char d,int m,int n,char map[m][n]){
    int add;
    char x;
    if(d=='r'||d=='b'){
        add=1;
    }
    else{
        add=-1;
    }
    if(d=='t'||d=='b'){
        x='i';
    }
    else{
        x='j';
    }
    if(x=='i'){
        i+=add;
        while(i>-1&&i<m&&(map[i][j]!='w'&&map[i][j]!='g')){
            if(map[i][j]!='s'){
            count+=1;
            map[i][j]='s';
            }
            i+=add;
        }
    }
    else{
        j+=add;
        while(j>-1&&j<n&&(map[i][j]!='w'&&map[i][j]!='g')){
        if(map[i][j]!='s'){
            count+=1;
            map[i][j]='s';
        }
            j+=add;
        }
    }
}


int countUnguarded(int m, int n, int** guards, int guardsSize, int* guardsColSize, int** walls, int wallsSize, int* wallsColSize) {
    char map[m][n];
    count=0;
    int answer;
    memset(map,'o',sizeof(char)*m*n);
    for(int i=0;i<guardsSize;i++){
        map[guards[i][0]][guards[i][1]]='g';
    }
    
    for(int i=0;i<wallsSize;i++){
        map[walls[i][0]][walls[i][1]]='w';
    }
    /*for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%c ",map[i][j]);
        }
        printf("\n");
    }*/
    for(int h=0;h<guardsSize;h++){
        int i=guards[h][0];
        int j=guards[h][1];
        traverse(i,j,'t',m,n,map);
        traverse(i,j,'r',m,n,map);
        traverse(i,j,'b',m,n,map);
        traverse(i,j,'l',m,n,map);
    }
    /*printf("\n\n");
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%c ",map[i][j]);
        }
        printf("\n");
    }*/
    answer=m*n-(count+guardsSize+wallsSize);
    
    printf("%d*%d=%d,%d=final= %d-(%d+%d+%d)=%d",m,n,m*n,count,m*n,count,guardsSize,wallsSize,answer);
    
    return answer;
    
}
