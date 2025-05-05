#include<stdio.h>
#include<conio.h>
#include<limits.h>
#include<stdbool.h>

#define V 5

int min(int key[],bool mst[]){
        int min=INT_MAX,min_index;

        for(int i=0;i<V; i++){
            if(mst[i]==false && key[i]<min){
                min=key[i];
                min_index=i;
            }
        }
        return min_index;
}

void display(int parent[],int graph[V][V]){
    printf("Edge \t Weight");
    for(int i =1;i<V;i++){
        printf("\n%d -%d->\t %d",parent[i],i,graph[parent[i]][i]);
    }
}

void primMST(int graph[V][V]){
    int key[V];
    int parent[V];
    bool mst[V];

    for(int v=0;v<V;v++){
        key[v]=INT_MAX;
        mst[v]=false;
    }

    key[0]=0;
    parent[0]=-1;

    for(int count =0 ;count < V-1; count ++){

        int u = min(key,mst);

        mst[u]=true;
        
        for(int v=0;v<V;v++){

            if(graph[u][v] && mst[v]== false && graph[u][v]<key[v])
                {
                    parent[v]=u;
                    key[v]=graph[u][v];
                }
        }
    }
    display(parent,graph);
  
   
}

int main()
{
    int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };

   
    primMST(graph);
    return 0;
}
