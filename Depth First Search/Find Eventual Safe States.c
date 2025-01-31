/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* terminal;
//int* safe;
void explore(int** graph, int graphSize, int* graphColSize, int* unreachable,
             int* visited, int node) {
    if (!terminal[node]) {
        visited[node] = 1;

        for (int i = 0; i < graphColSize[node]; i++) {
            if (!unreachable[graph[node][i]] && !visited[graph[node][i]]) {
                if (!terminal[graph[node][i]]) {

                    explore(graph, graphSize, graphColSize, unreachable,
                            visited, graph[node][i]);
                  
                }
            } else {
                
                for (int i = 0; i < graphSize; i++) {
                    if (visited[i] && !unreachable[i]) {
                        unreachable[i] = 1;
                    }
                }
                break;
            }
            visited[graph[node][i]]=0;
        }
        if (!unreachable[node]) {
        
           
            terminal[node] = 1;
            
        }
    }
    
}
int* eventualSafeNodes(int** graph, int graphSize, int* graphColSize,
                       int* returnSize) {
    terminal = calloc(graphSize, sizeof(int));
   // safe = calloc(graphSize, sizeof(int));
    for (int i = 0; i < graphSize; i++) {
        if (!graphColSize[i]) {
            terminal[i] = 1;
            //safe[i] = 1;
        }
    }
    int* unreachable = calloc(graphSize, sizeof(int));
    for (int i = 0; i < graphSize; i++) {
        if (!unreachable[i]) {
            int* visited = calloc(graphSize, sizeof(int));
            explore(graph, graphSize, graphColSize, unreachable, visited, i);
            free(visited);
        }
    }
int *ans=calloc(graphSize,sizeof(int));
int no=0;
    for (int i = 0; i < graphSize; i++) {
        if (terminal[i])
        ans[no++]=i;
    }
    
    *returnSize=no;
    return ans;
}
