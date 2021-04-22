#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tree {
    int data;
    struct tree *Left;
    struct tree *back;
    struct tree *Right;
}treeNode;

int searchnum(treeNode *ptr, int tmp, int flag){ //exist or not?
    //printf("%d ",flag);
    if(ptr != NULL && flag == 0){
        flag = searchnum(ptr->Left, tmp, flag);
        if(ptr->data == tmp){
            flag = -1;
            //printf("123");
        }
        flag = searchnum(ptr->Right, tmp, flag);
    }
    return flag;
}

treeNode *newNode(int key, treeNode *back){
    treeNode *node;
    node = malloc(sizeof(treeNode));
    node->data = key;
    node->back = back;
    node->Left = NULL;
    node->Right = NULL;
    return node;
}

void Postorder(treeNode *ptr){ //back shi print
    if(ptr != NULL){
        Postorder(ptr->Left);
        Postorder(ptr->Right);
        printf("%d ",ptr->data);
    }
}

treeNode *insertsort(treeNode *insert, treeNode *root){
//printf("%p", insert);
    int num = insert->data;
    int tmp;

    while(1){
        if(insert == root){
            break;
        }
        if(num > insert->back->data){
            tmp = insert->back->data;
            insert->back->data = insert->data;
            insert->data = tmp;
            insert = insert->back;
        }
        else{
            break;
        }

    }
    return root;
}

int searchplace(int now, int path[10]){ //-1 Left  1 Right search last place
    int i = 0;
    while(now > 1){
        if(now % 2 == 0){
            path[i] = -1;
        }
        else{
            path[i] = 1;
        }
        now = now / 2;
        i += 1;
        //printf("!!! = %d\n",path[0]);
    }
    return i;
}

treeNode *insertdata(treeNode *root, int tmp, int *now){
    int path[10] = {0};
    int tmpp, i;
    treeNode *insert = root;
    //printf("!!");
    if(root == NULL){
        root = malloc(sizeof(treeNode));
        root->data = tmp;
        root->Left = NULL;
        root->Right = NULL;
        root->back = NULL;
    }
    else{
        if(searchnum(root, tmp, 0) == -1){
            printf("%d already exist¡I\n", tmp);
        }
        else{
            tmpp = searchplace(*now, path);
            //printf("??%d",tmpp);
            for(i = tmpp - 1; i > 0; i--){
                if(path[i] == -1){
                    insert = insert->Left;
                }
                else{
                    insert = insert->Right;
                }
            }
            //printf("qq");

            if(path[0] == -1){
                insert->Left = newNode(tmp, insert);
                insert = insert->Left;
            }
            else{
                insert->Right = newNode(tmp, insert);
                insert = insert->Right;
            }
            root = insertsort(insert, root);
        }

    }
    return root;
}

treeNode *searchdel(treeNode *ptr, int tmp,int flag, treeNode *delptr){
    if(ptr != NULL && flag == 0){
        searchdel(ptr->Left, tmp, flag, delptr);
        printf("^%d ",ptr->data);
        if(ptr->data == tmp){
            flag = -1;
            delptr = ptr;

        }
        searchdel(ptr->Right, tmp, flag, delptr);
    }
    printf("%d", delptr->data);
}

treeNode *del(treeNode *root, int tmp, int *nowplace){
    int flag = 0, i;
    treeNode *temp, *last = root, *delptr;
    int tmpp;
    int path[10] = {0};
    //printf("%d  ", *nowplace);
    if(root == NULL){
        printf("The tree is empty!\n");
    }
    else{
        if(searchnum(root, tmp, 0) == 0){
            printf("%d does not exist¡I\n", tmp);
        }
        else{
            tmpp = searchplace(*nowplace, path);
            for(i = tmpp - 1; i >= 0; i--){
                if(path[i] == -1){
                    last = last->Left;
                }
                else{
                    last = last->Right;
                }
            }
            tmpp = last->data; //copy last data
            //printf("!!%d",tmpp);
            searchdel(root, tmp, 0, delptr);
            printf("!!%d",delptr->data);
            delptr->data = tmpp;
            Postorder(root);printf("\n");
            printf("..%d", delptr->data);
        }
    }
    return root;
}

int main(){
    FILE *fp = fopen("input.txt","r");
    if(fp == NULL){
        printf("NO~~~~~\n");
    }
    int nowplace = 0;
    int tmp;
    int menu;
    treeNode *root = NULL, *now;
    while(1){
        fscanf(fp, "%d ", &menu);
        if(menu == 0){
            break;
        }
        printf("[1] Insert [2] Delete [3] Show [4] Search ¡G%d\n", menu);

        if(menu == 1){
            fscanf(fp, "%d", &tmp);
            nowplace += 1;
            printf("Insert a number : %d\n", tmp);
            root = insertdata(root, tmp, &nowplace);
            Postorder(root);
            printf("\n\n");
        }
        else if(menu == 2){
            fscanf(fp, "%d", &tmp);
            printf("Insert a number : %d\n", tmp);
            root = del(root, tmp ,&nowplace);
            Postorder(root);
        }
        else if(menu == 3){

        }
        else if(menu == 4){
            fscanf(fp, "%d", &tmp);
            //printf("%d",tmp);
            Postorder(root);
            printf("\n\n");
        }
        else{
            printf("Please chose again!!\n\n");
        }
    }
}
