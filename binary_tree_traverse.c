#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 200

/*二叉树节点类型*/
typedef struct node{
    char data;
    struct node *lchild,*rchild;
}BTNode;

/*函数声明*/
BTNode * createBiTree();
void preOrder(BTNode *);
void inOrder(BTNode *);
void postOrder(BTNode *);

/*主函数*/
int main(){
    BTNode * root = NULL;
    root = createBiTree();
    preOrder(root);
    inOrder(root);
    postOrder(root);
    return 0;
}
/*递归前序简历二叉树*/
BTNode * createBiTree(){
    char ch;
    BTNode *b;
    scanf("%c",&ch);
    /*遇到空节点停止递归*/
    if(ch == '#'){
        b=NULL;
    }else{
        b = (BTNode *) malloc(sizeof(BTNode));
        /*建立根节点*/
        b -> data = ch;
        /*递归先序建立左子树*/
        b -> lchild = createBiTree();
        /*递归先序建立右子树*/
        b -> rchild = createBiTree();
    }
    return b;
}


/*非递归前序遍历二叉树*/
void preOrder(BTNode *b){
    BTNode * stack[MAXSIZE],*p;
    int top = -1;
    if(b != NULL){
        /*根节点入栈*/
        top++;
        stack[top] = b;
        /*栈不空时循环*/
        while(top > -1){
            /*出栈并访问该节点*/
            p = stack[top];
            top--;
            printf("%c ",p->data);
            /*右孩子入栈*/
            if(p->rchild!=NULL){
                top++;
                stack[top] = p->rchild;
            }
            if(p->lchild!=NULL){
                top++;
                stack[top] = p -> lchild;
            }
        }
        printf("\n");
    }
}

/*非递归中序遍历二叉树*/
void inOrder(BTNode *b){
    BTNode * stack[MAXSIZE],*p;
    int top = -1;
    if(b!=NULL){
        p=b;
        while(top >-1||p!=NULL){
            /*扫描p的所有左节点并入栈*/
            while(p!=NULL){
                top++;
                stack[top] = p;
                p = p->lchild;
            }
            if(top>-1){
                /*出栈并访问该节点*/
                p = stack[top];
                top--;
                printf("%c ",p->data);
                /*扫描p的右节点*/
                p = p->rchild;
            }
        }
        printf("\n");
    }
}

/*飞递归后续遍历二叉树*/
void postOrder(BTNode * b){
    BTNode * stack[MAXSIZE],*p;
    int sign,top = -1;
    if(b != NULL){
        do{
            /*b所有左节点入栈*/
            while(b!=NULL){
                top++;
                stack[top] = b;
                b = b ->lchild;
            }
            /*p指向栈顶前一个已访问节点*/
            p = NULL;
            /*设置b为已经访问*/
            sign = 1;
            while(top!=-1&&sign){
                /*取出栈顶节点*/
                b = stack[top];
                /*右孩子不存在或者右孩子已经被访问*/
                if(b->rchild == p){
                    printf("%c ",b->data);
                    top--;
                    /*p指向被访问的节点*/
                    p = b;
                }else{
                    /*b指向右孩子节点*/
                    b = b -> rchild;
                    /*设置未访问标记*/
                    sign = 0;
                }
            }
        }while(top!=-1);
    }
    printf("\n");
}





