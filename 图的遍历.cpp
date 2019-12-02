#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 20
#define M_weight 32580

/*typedef char vertexdata;
typedef struct
{
    vertexdata vertex[M];
    char arcs[M][M];
    int n,e;//顶点数和边数
}adjacecy_matrix;*/

typedef int infotype;
typedef struct node//弧结点结构
{
    int adjvex;
    struct node *nextarc;
    infotype info;
}arcnode;

typedef int vextype;
typedef struct vexnode//表头结点结构
{
    vextype vertex;
    arcnode *firstarc;
}vertexnode;

//typedef vertexnode adjlist[M];
typedef struct//图的基本结构
{
    vertexnode adjlist[M];
    int n,e;
}adjlist;

void menu();
//void creategraph1(adjacecy_matrix *G, int adjmatrix[][M]);//邻接矩阵
void creategraph2(adjlist *G);
//void destorygrape(adjacecy_matrix G);
//void locategrape(adjacecy_matrix *G, char v);//寻找顶点v
//void getgrape(adjacecy_matrix G, char i);//寻找第i个顶点
//void firstadjvertex(adjacecy_matrix G, char v);//寻找顶点的第一个邻接顶点
//void nextadjvertex(int G, int v, int w);//寻找下一个邻接点
//void insertvertex(adjacecy_matrix G, char v);//增加顶点v
//void delectvertex(adjacecy_matrix G, char v);//删除顶点v
//void insertarc(adjacecy_matrix G, char v ,char w);//增加v和w之间的弧
//void delectarc(adjacecy_matrix G, char v, char w);//删除弧

void DFSTraveseAL(adjlist *G);
void DFS(adjlist *G, int i); //深度优先遍历
//void BFSTraveseAL(adjlist G);
//void BFS(adjlist G, int i);//广度优先遍历
void traversegraph(adjlist G);//2种遍历访问

int main()
{
    menu();
    system("pause");
    return 0;
}

/*void creategraph1(adjacecy_matrix *G, int adjmatrix[][M])//邻接矩阵有向图
{
    int i,j,k;
    printf("please enter the number of vertices and edges of the graph\n");
    scanf("%d %d",&G->n,&G->e);//输入顶点和边数
    printf("please enter the vertex information\n");
    for(i=0;i<G->n;++i)
        scanf("%s",&G->vertex[i]);
    for(i=0;i<G->n;++i)
    {
        for(j=0;j<G->n;++j)
        adjmatrix[i][j]=M_weight;
    }
    for(k=0;k<G->e;++k)
    {
        int x,y,due;
        printf("please enter the %d  ede's vertices and weight\n",k+1);
        scanf("%d %d %d",&x,&y,&due);//输入权值
        adjmatrix[x][y]=due;//赋权
    }
}*/

void creategraph2(adjlist *G)//邻接表创造图
{
    int i, j, k;
    arcnode *s;
    printf("please enter the number of vertices and edges of the graph\n");
    scanf("%d,%d", &G->n, &G->e); //输入顶点和边数

    printf("please enter the vertex information\n");
    for (i = 0; i < G->n; ++i)
    {
        scanf("\n%s", &G->adjlist[i].vertex);
        G->adjlist[i].firstarc = NULL;
    }
    printf("please enter the ede's information(2 numbers):\n");
    for (k = 0; k < (G->e); k++)
    {
        scanf("%d,%d", &i, &j);
        getchar();
        s = (arcnode *)malloc(sizeof(arcnode));
        s->adjvex = j;
        s->nextarc = G->adjlist[i].firstarc;
        G->adjlist[i].firstarc = s;
    }
    printf("succeff!\n");
}

/*void locategrape(adjacecy_matrix *G, char v) //寻找顶点v
{
    int j,k;
    for(k=0;k<G->n;++k)
        if(G->vertex[k]==v)
        {
            j=k;
            printf("the vertex you want to find is %d",j);
            break;
        }
}*/

/*void getgrape(adjacecy_matrix *G, char i) //寻找第i个顶点
{    
    for(int j;j<G->n;++j)
    {
        if(i==j)
            printf("the vertex you want to find is %s", G->vertex[j]);
    }
          
}*/

bool visited[M];//访问过的数组

void DFSTraveseAL(adjlist *G)
{
    int i;
    for (i = 0; i < G->n; i++)
        visited[i] = 0; /* 给每个顶点一个未访问过标记 */
    for (i = 0; i < G->n; i++)
        if (!visited[i])
            DFS(G, i); /*若顶点vi未访问过,从vi开始深度优先遍历图*/
} /* 要特别注意非连通图的遍历 */

void DFS(adjlist *G, int i)
{
    arcnode *p;
    printf("%c", G->adjlist[i].vertex); /*访问顶点vi*/
    visited[i] = 1;                      /* 标记顶点vi已被访问过 */
    p = G->adjlist[i].firstarc;         /*取vi边表头指针*/
    while (p)
    {                            /* 若p存在 */
        if (!visited[p->adjvex]) /* 若v p->adjvex未被访问过 */
            DFS(G, p->adjvex); /* 从v p->adjvexi出发开始深度优先遍历图 */
            p = p->nextarc;             /*找和vi 相邻的下一邻接顶点*/
    }
}
/*
void BFSTraveseAL(adjlist *G)
{
    int i;
    for (i = 0; i < G->n; i++)
        visited[i] = 0; /* 给每个顶点一个未访问过标记 */
  //  for (i = 0; i < G->n; i++)
  //      if (!visited[i])
   //         BFS(G, i); /*若顶点vi未访问过,从vi开始广度优先遍历图*/
//}

/*
void BFS(adjlist *G, int i) //广度优先遍历
{

}*/

void menu()
{
    int num;
    int adjmatrix[M][M];
    adjlist G;
    while(1)
    {
        printf("\n====================================================\n");
        printf("|            please select an opertain         \n");
        printf("|1.creategragh2         2.locategrape enter vertex  \n");
        printf("|3.getgrape enter ith   4.DFS        \n");
        printf("|5.BFS       \n");
        printf("====================================================\n");
        scanf("%d",&num);
        switch (num)
        {
            case 1 /* constant-expression */:
            creategraph2(&G);
                /* code */
                break;
            case 2:
                printf("please enter the vertex you want to find\n");
                char v;
                scanf("%s",&v);
                //locategrape(&G,v);
                break;
            case 3:
                printf("please enter the vertex you want to find\n");
                int i;
                scanf("%d", &i);
                //getgrape(&G, i);
                break;
            case 4:
                DFSTraveseAL(&G);
                break;
            case 5:
                //BFSTraveseAL(&G);
                break;
            default : break;
        }
    }

}
