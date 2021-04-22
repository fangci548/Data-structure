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

void Postorderchild(treeNode *ptr, treeNode *searchptr){ //back shi print
    if(ptr != NULL){
        Postorderchild(ptr->Left, searchptr);
        Postorderchild(ptr->Right, searchptr);
        if(ptr != searchptr){
            printf("%d ",ptr->data);
        }
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
        *now += 1;
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
            *now += 1;
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

void searchdel(treeNode *ptr, int tmp,int flag, treeNode **delptr){
    if(ptr != NULL && flag == 0){
        if(ptr->data == tmp){
            flag = -1;
            *delptr = ptr;
        }
        searchdel(ptr->Left, tmp, flag, delptr);
        searchdel(ptr->Right, tmp, flag, delptr);
    }
}

int search(treeNode *ptr, int tmp,int flag, treeNode **searchptr){
    if(ptr != NULL && flag == 0){
        if(ptr->data == tmp){
            flag = -1;
            *searchptr = ptr;
        }
        flag = search(ptr->Left, tmp, flag, searchptr);
        flag = search(ptr->Right, tmp, flag, searchptr);
    }
    return flag;
}

treeNode *del(treeNode *root, int tmp, int *nowplace){
    int flag = 0, i;
    treeNode *temp, *last = root, *delptr;
    int tmpp;
    int path[10] = {0};
//    printf("%d  ", *nowplace);
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
            searchdel(root, tmp, 0, &delptr);
            //printf("..%d", delptr->data);
            delptr->data = tmpp;
            if(path[0] == -1){
                last->back->Left = NULL;
            }
            else{
                last->back->Right = NULL;
            }

            if(delptr->back->data < delptr->data){
                tmpp = delptr->data;
                delptr->data = delptr->back->data;
                delptr->back->data = tmpp;
            }
            if(delptr->data < delptr->Left->data || delptr->data < delptr->Right->data){
                if(delptr->Left->data > delptr->Right->data){
                    tmpp = delptr->Left->data;
                    delptr->Left->data = delptr->data;
                    delptr->data = tmpp;
                }
                else{
                    tmpp = delptr->Right->data;
                    delptr->Right->data = delptr->data;
                    delptr->data = tmpp;
                }
            }
            *nowplace -= 1;
        }
    }
    return root;
}

int main(){
    FILE *fp = fopen("input_1.txt","r");
    if(fp == NULL){
        printf("NO~~~~~\n");
    }
    int nowplace = 0;
    int tmp;
    int menu;
    int flag = 0;
    treeNode *root = NULL, *searchptr;
    while(1){
        fscanf(fp, "%d ", &menu);
        if(menu == 0){
            break;
        }
        printf("[1] Insert [2] Delete [3] Show [4] Search ¡G%d\n", menu);

        if(menu == 1){
            fscanf(fp, "%d", &tmp);
            printf("Insert a number : %d\n", tmp);
            root = insertdata(root, tmp, &nowplace);
            //Postorder(root);
            printf("\n\n");
        }
        else if(menu == 2){
            fscanf(fp, "%d", &tmp);
            printf("Insert a number : %d\n", tmp);
            root = del(root, tmp ,&nowplace);
            //Postorder(root);
            printf("\n\n");
        }
        else if(menu == 3){
            printf("PostOrder¡G");
            Postorder(root);
            printf("\n");
            printf("Total¡G%d\n", nowplace);
            printf("Max¡G%d\n",root->data);
            printf("\n");
        }
        else if(menu == 4){
            fscanf(fp, "%d", &tmp);
            printf("Search the number¡G%d\n",tmp);
            flag = search(root, tmp, 0, &searchptr);
            if(flag == 0){
                printf("%d does not exist¡I\n\n", tmp);
            }
            else{
                printf("Child: ");
                Postorderchild(searchptr, searchptr);
                printf("\n\n");
            }

        }
        else{
            printf("Please chose again!!\n\n");
        }
    }
}
