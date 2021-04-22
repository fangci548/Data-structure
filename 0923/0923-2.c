#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct Student{
    char name[15];
    char sex;
    int number;
    int score_com;
    int score_math;
    float score_ave;
}stu;

FILE *openfile( int mode ){
    if( mode == 0 ){
        return fopen("name.txt","r");
    }
    else{
        return fopen("student.txt","w");
    }
}

void case1(int i , int* num , char* sex , int* com , int* math){
    int tmp;
    *num = i+1;
    tmp = (rand() % 2);
    if( tmp == 0 ){
        *sex = 'F';
    }
    else{
        *sex = 'M';
    }
    *com = (rand() % 31) + 70;
    *math = (rand() % 31) + 70;
}
void case2(FILE *f , char name[15] , int num , char sex){
    int i;
    fprintf(f , "%-14s %-5d %c\n", name , num , sex);
}
void case3(stu Data[50]){
    int i , j;
    stu tmp_stu;
    for(i = 0 ; i < 50 ; i++){
        Data[i].score_ave = ( (float)Data[i].score_com + (float)Data[i].score_math ) / 2;
    }
    for(i = 0 ; i < 50 ; i++){
        for(j = 0 ; j < 50 - i ; j++){
            if(Data[j].score_ave < Data[j+1].score_ave){
                tmp_stu = Data[j];
                Data[j] = Data[j+1];
                Data[j+1] = tmp_stu;
            }
            if(Data[j].score_ave == Data[j+1].score_ave){
                if(Data[j].score_com < Data[j+1].score_com){
                    tmp_stu = Data[j];
                    Data[j] = Data[j+1];
                    Data[j+1] = tmp_stu;
                }
            }
        }
    }
}
void case4(stu Data[50] , float* ave_com , float* ave_math , int* high_com , int* high_math){
    *high_com = 0;
    *high_math = 0;
    int i , total_com = 0 , total_math = 0;
    int high_score_com = Data[0].score_com;
    int high_score_math = Data[0].score_math;
    for(i = 0 ; i < 50 ; i++){
        total_com += Data[i].score_com;
        total_math += Data[i].score_math;
        if(high_score_com < Data[i].score_com){
            high_score_com = Data[i].score_com;
            *high_com = i;
        }
        if(high_score_math < Data[i].score_math){
            high_score_math = Data[i].score_math;
            *high_math = i;
        }
    }
    *ave_com = (float)total_com / 50;
    *ave_math = (float)total_math / 50;
}


int main(){
    FILE* fp_r;
    FILE* fp_w;
    srand( time(NULL) );
    int menu , i , tmp , j;
    stu tmp_stu;
    stu student[50];
    float average_com , average_math;
    int high_com , high_math , flag = 0;
    while(1)
    {
        printf("\n[1]Create [2]Print_Student [3]Print_Rank [4]Print_Avg [0]End : ");
        scanf(" %d", &menu );
        switch( menu )
        {
            case 1:  //原始資料產生
                flag = 1;
                fp_r = openfile( 0 );
                if( fp_r == NULL ){
                    printf("開檔錯誤!");
                    break;
                }
                for(i = 0 ; i < 50 ; i++){
                    fscanf( fp_r , "%s" , student[i].name);
                    case1(i , &student[i].number , &student[i].sex ,
                    &student[i].score_com , &student[i].score_math);
                }
//                for(i = 0;i < 50;i++){
//                    printf("%s %c %d %d\n",student[i].name,student[i].sex,student[i].score_math,student[i].score_com);
//                }
                fclose( fp_r );
                break;
            case 2:  //輸出學生資料
                if( flag == 0 ){
                    printf("Error!\n");
                    break;
                }
                fp_w = openfile( 1 );
                if( fp_w == NULL ){
                    printf("開檔錯誤!");
                    return -1;
                }
                fputs("學生姓名      號碼  性別\n-------------------------\n" , fp_w);
                for(i = 0 ; i < 50 ; i++){
                    case2(fp_w , student[i].name , student[i].number , student[i].sex);
                }
                fclose( fp_w );
                break;
            case 3:  //列印排序成績
                if( flag == 0 ){
                    printf("Error!\n");
                    break;
                }
                case3( student );
                printf("學生姓名  計概成績   微積分成績  平均成績   名次 \n------------------------------------------------\n");
                for(i = 0 ; i < 50 ; i++){
                    printf("%-14s %-10d %-10d %.1f %5d\n"
                    , student[i].name , student[i].score_com , student[i].score_math , student[i].score_ave , i+1);
                }
                break;
            case 4:  //印出各科平均成績和該科目成績最高者
                if( flag == 0 ){
                    printf("Error!\n");
                    break;
                }
                case4( student , &average_com , &average_math , &high_com , &high_math );
                printf(" 科目      平均成績    最高分學生   最高分成績   \n-------------------------------------------\n");
                printf(" 計概      ");
                printf("%-14.1f %-10s %d\n", average_com , student[high_com].name , student[high_com].score_com);
                printf(" 微積分    ");
                printf("%-14.1f %-10s %d", average_math , student[high_math].name , student[high_math].score_math);
                break;
            case 0:  //結束程式執行
                printf("Exit!\n");
                exit( 1 );
                break;
            default:
                printf("Error!\n");
                break;
        }
    }
}
