#include <stdio.h>
#include <stdlib.h>

typedef char datatype;
typedef struct bitnode//二叉树的存储结点
{
    datatype data;
    struct bitnode *lchild;
    struct bitnode *rchild;
}bitnode, *bitree;

void menu();
void visit(bitree bt);//打印
void initiate(int bt);//初始化
void create(bitree *bt);//创建二叉树
void destory(int bt);//销毁二叉树
void root(int bt);///求二叉树的根结点
void parents(int bt, int x);//求双亲函数
void leftchild(int bt, int x);//求左孩子
void rightchild(int bt, int x); //求右孩子
void traverse(int bt);//遍历操作
void preorder(bitree bt);//前序遍历
void inorder(bitree bt);//中序遍历
void postorder(bitree bt);//后序遍历

int main()
{
    menu();
    system("please");
}

//--------------------------打印-----------------------
void visit(bitree bt) //打印
{
    printf("%c",bt->data);
}

void create(bitree *bt) //前序创建二叉树
{
    
    printf("please enter a binary tree\n");
    char c;
    //scanf("%s",&c);
    c=getchar();
    getchar();
    if(c =='.')
    {
         *bt=NULL;
    }
    else 
    {
        *bt=(bitnode *)malloc(sizeof(bitnode));
        (*bt)->data=c;
        create(&((*bt)->lchild));
        create(&((*bt)->rchild));//右子树
    }
}

//------------------------前序遍历二叉树-------------------
void preorder(bitree bt) //前序遍历
{
    if(bt)//递归返回条件
    {
        visit(bt);
        preorder(bt->lchild);
        preorder(bt->rchild);
    }
}

//------------------------中序遍历二叉树-------------------
void inorder(bitree bt) //中序遍历
{
    if (bt != NULL) //递归返回条件
    {
        inorder(bt->lchild);
        visit(bt);
        inorder(bt->rchild);
    }
}

//------------------------后序遍历二叉树-------------------
void postorder(bitree bt) //后序遍历
{
    if (bt != NULL) //递归返回条件
    {
        postorder(bt->lchild);
        postorder(bt->rchild);
        visit(bt);
    }
}

void menu()
{ 
    bitree bt=NULL;
    int num;
    while(1)
    {
        printf("\n======================================\n");
        printf("|   please select you want to       \n");
        printf("|1.crearte               2.preorder \n");
        printf("|3.inorder               4.postorder\n");
        printf("======================================\n");
        scanf("%d", &num);
        switch (num)
        {
        case 1/* constant-expression */:
            /* code */
            create(&bt);
            break;
        case 2:
            preorder(bt);
            break;
        case 3:
            inorder(bt);
            break;
        case 4:
            postorder(bt);
            break;
        default : break;
        }
    }
}
