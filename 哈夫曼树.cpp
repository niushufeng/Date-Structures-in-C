/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXVALUE 1000
#define MAXLEAF 30

typedef struct//哈夫曼树结构
{
    int weight;
    int parent;
    int lchild;
    int rchild;
}htnode, *Huffmantree;

void menu();//菜单
void createHuffmantree(Huffmantree *ht);//创建哈夫曼树
void printHuffmantree(int ht );//打印哈夫曼树
void Huffmancode();//哈夫曼编码

int main()
{
    menu();
    system("please!");
}

//-------------------------创建哈夫曼树--------------------
void createHuffmantree(Huffmantree *ht)//创建哈夫曼树
{
    int i,j,m1,m2,x1,x2,n;
    printf("please enter leaf code numbers:\n");
    scanf("%d",&n);
    for(i=0;i<(2*n-1);++i)
    {
        (*ht)[i].weight=0;
        (*ht)[i].parent=-1;
        (*ht)[i].lchild=-1;
        (*ht)[i].rchild=-1;
    }
    printf("please enter weight:\n");
    for(i=0;i<n;++i)
    scanf("%d",&(*ht)[i].weight);
    for (i = 0; i < n - 1; i++)
    {
        m1 = m2 = MAXVALUE;
        x1 = x2 = 0;
        for (j = 0; j < n + i; j++)
        {
            if ((*ht)[j].parent == -1 &&
                (*ht)[j].weight < m1)
            {
                m2 = m1;
                x2 = x1;
                m1 = (*ht)[j].weight;
                x1 = j;
            }
            else if ((*ht)[j].parent == -1 &&
                     (*ht)[j].weight < m2)
            {
                m2 = (*ht)[j].weight;
                x2 = j;
            }
        }
        (*ht)[x1].parent = n + i;
        (*ht)[x2].parent = n + i;
        (*ht)[n + i].weight =
            (*ht)[x1].weight + (*ht)[x2].weight;
        (*ht)[n + i].lchild = x1;
        (*ht)[n + i].rchild = x2;
    }
}

void menu()
{
    int i,n;
    Huffmantree ht[MAXVALUE];
    int num;
    while(1)
    {
        printf("\n====================================\n");
        printf("|        please select you want        \n");
        printf("| 1.createHuffmantree    \n");
        scanf("%d",&num);
        switch(num)
        {
            case 1:
                createHuffmantree(ht);
                break;
            default :
                break;
        }
    }
}*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ELEMTYPE;

// 哈夫曼树结点结构体
typedef struct HuffmanTree
{
    ELEMTYPE weight;
    ELEMTYPE id; // id用来主要用以区分权值相同的结点，这里代表了下标
    struct HuffmanTree *lchild;
    struct HuffmanTree *rchild;
} HuffmanNode;

// 构建哈夫曼树
HuffmanNode *createHuffmanTree(int *a, int n)
{
    int i, j;
    HuffmanNode **temp, *hufmTree;
    *temp = (HuffmanNode *)malloc(sizeof(HuffmanNode));
    for (i = 0; i < n; ++i) // 将数组a中的权值赋给结点中的weight
    {
        temp[i] = (HuffmanNode *)malloc(sizeof(HuffmanNode));
        temp[i]->weight = a[i];
        temp[i]->id = i;
        temp[i]->lchild = temp[i]->rchild = NULL;
    }

    for (i = 0; i < n - 1; ++i) // 构建哈夫曼树需要n-1合并
    {
        int small1 = -1, small2; // small1、small2分别作为最小和次小权值的下标
        for (j = 0; j < n; ++j)  // 先将最小的两个下标赋给small1、small2（注意：对应权值未必最小）
        {
            if (temp[j] != NULL && small1 == -1)
            {
                small1 = j;
                continue;
            }
            else if (temp[j] != NULL)
            {
                small2 = j;
                break;
            }
        }

        for (j = small2; j < n; ++j) // 比较权值，挪动small1和small2使之分别成为最小和次小权值的下标
        {
            if (temp[j] != NULL)
            {
                if (temp[j]->weight < temp[small1]->weight)
                {
                    small2 = small1;
                    small1 = j;
                }
                else if (temp[j]->weight < temp[small2]->weight)
                {
                    small2 = j;
                }
            }
        }
        hufmTree = (HuffmanNode *)malloc(sizeof(HuffmanNode));
        hufmTree->weight = temp[small1]->weight + temp[small2]->weight;
        hufmTree->lchild = temp[small1];
        hufmTree->rchild = temp[small2];

        temp[small1] = hufmTree;
        temp[small2] = NULL;
    }
    free(temp);
    return hufmTree;
}

// 以广义表的形式打印哈夫曼树
void PrintHuffmanTree(HuffmanNode *hufmTree)
{
    if (hufmTree)
    {
        printf("%d", hufmTree->weight);
        if (hufmTree->lchild != NULL || hufmTree->rchild != NULL)
        {
            printf("(");
            PrintHuffmanTree(hufmTree->lchild);
            printf(",");
            PrintHuffmanTree(hufmTree->rchild);
            printf(")");
        }
    }
}

// 递归进行哈夫曼编码
void HuffmanCode(HuffmanNode *hufmTree, int depth) // depth是哈夫曼树的深度
{
    static int code[10];
    if (hufmTree)
    {
        if (hufmTree->lchild == NULL && hufmTree->rchild == NULL)
        {
            printf("id is %d weight is %d leaf nodes :", hufmTree->id, hufmTree->weight); //id为%d权值为%d的叶子结点的哈夫曼编码为
            int i;
            for (i = 0; i < depth; ++i)
            {
                printf("%d", code[i]);
            }
            printf("\n");
        }
        else
        {
            code[depth] = 0;
            HuffmanCode(hufmTree->lchild, depth + 1);
            code[depth] = 1;
            HuffmanCode(hufmTree->rchild, depth + 1);
        }
    }
}

// 哈夫曼解码
void HuffmanDecode(char ch[], HuffmanNode *hufmTree, char string[]) // ch是要解码的01串，string是结点对应的字符
{
    int i;
    int num[100];
    HuffmanNode *tempTree = NULL;
    for (i = 0; i < strlen(ch); ++i)
    {
        if (ch[i] == '0')
            num[i] = 0;
        else
            num[i] = 1;
    }
    if (hufmTree)
    {
        i = 0; // 计数已解码01串的长度
        while (i < strlen(ch))
        {
            tempTree = hufmTree;
            while (tempTree->lchild != NULL && tempTree->rchild != NULL)
            {
                if (num[i] == 0)
                {
                    tempTree = tempTree->lchild;
                }
                else
                {
                    tempTree = tempTree->rchild;
                }
                ++i;
            }
            printf("%c", string[tempTree->id]); // 输出解码后对应结点的字符
        }
    }
}

int main()
{
    int i, n;
    printf("please enter leaf nodes number:\n");
    while (1)
    {
        scanf("%d", &n);
        if (n > 1)
            break;
        else
            printf("Error! please again！");
    }

    int *arr;
    arr = (int *)malloc(n * sizeof(ELEMTYPE));
    printf("please enter the weight of %d leaf nodes:\n", n);
    for (i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }

    char ch[100], string[100];
    printf("please enter the charters of %d leaf nodes in a row:\n", n);
    fflush(stdin); // 强行清除缓存中的数据，也就是上面输入权值结束时的回车符
    gets(string);

    HuffmanNode *hufmTree = NULL;
    hufmTree = createHuffmanTree(arr, n);

    printf("showing this Huffman tree:\n"); //此哈夫曼树的广义表形式为：
    PrintHuffmanTree(hufmTree);
    printf("\nleaf nodes Huffman coding：\n"); //各叶子结点的哈夫曼编码为
    HuffmanCode(hufmTree, 0);

    printf("please enter coding :\n");//要解码吗,请输入编码
    gets(ch);
    printf("Decode result\n"); //解码结果为:
        HuffmanDecode(ch, hufmTree, string);
    printf("\n");

    free(arr);
    free(hufmTree);

    return 0;
}
