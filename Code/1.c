#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

#define stuNum 40

//管理员
struct administrator{
    char account[12];
    char password[12];
}admin = {"admin","123456"};

//教师
struct teachers{
    char id[12];
    char name[10];
    char password[12];
}teacher1 = {"cy001","吴亦凡","123456"},
 teacher2 = {"cy002","蔡徐坤","123456"},
 teacher3 = {"cy003","张学友","123456"},
 teacher4 = {"cy004","刘德华","123456"};

//学生
typedef struct students{
    char id[13];
    char name[10];
    int score[4];};

/**
 * n:当前记录的学生总人数
 * process:记录系统进程       1:管理员   2：教师    3：学生
 * userID:记录用户输入的学号
 * test:用户输入的功能菜单编号
 * user:用户输入的管理员id或教师id
 */
int n = 0,process = 0,test = 0;
char userID[12];
char user[12];
struct students student1[stuNum],*sp = student1;
struct students student2[stuNum],*sp2 = student2;

//函数声明
void mainProcess();     //控制系统流程
void user_menu();       //登录函数
void Admin_menu();      //管理员功能菜单
void Teacher_menu();    //教师功能菜单
void Student_menu ();   //学生功能菜单
void student_print();   //信息输出
void student_add();     //添加信息
void student_delete();  //删除账户及信息
void student_search();  //查询
void student_sort();    //按学号升序排序
void student_sort1 ();  //姓名排序
void student_sort2();   //平均成绩排序
void student_sort3();   //总成绩排序
void score_analyze(); //成绩分析
void fileWrite ();      //数据写出
void fileRead ();       //数据读入
void system_before ();  //返回上一层调用
void system_out ();     //退出系统
void display();         //学生信息展示
void modify();          //修改
void student_input();   //信息输入函数
void saveAll();         //保存所有数据

int main(){
    SetConsoleTitle("诚毅学院学生成绩管理系统");        //设置窗口标题
    fileRead ();
    user_menu();
    mainProcess();
    return 0;
}

void user_menu(){
    char password[12];
    int i = 0, item = 0;
    printf("\n\n\n\n\n");
    printf("\t\t|---------------------USER-----------------------|\n\n");
    printf("\t\t|\t\t 0.管理员                       |\n\n");
    printf("\t\t|\t\t 1.学生                          |\n\n");
    printf("\t\t|\t\t 2.教师                          |\n\n");
    printf("\t\t|------------------------------------------------|\n\n");
    printf("\t\t\t\t请输入功能编号：");
    scanf("%d",&test);
    system("cls");
    switch(test){
    case 0:
        printf("\n\n\n\n\n");
        printf("\t\t|---------------------登录-------------------|\n\n");
        printf("\t\t    账号:");
        scanf("%s",user);
        printf("\n");
        printf("\t\t    密码:");
        scanf("%s",password);
        printf("\n");
        printf("\t\t|--------------------------------------------|\n");
        while(i < 3){
if (strcmp(user,admin.account) == 0 && strcmp(password,admin.password) == 0){
                printf("\n\n\t\t登录成功\n");
                break;
            } else {
                i++;
                if(i!=3){
                   printf("\n\n\t\t账号或密码输入错误，请重新输入\n");
               Sleep(2000);
                 system("cls");
      printf("\n\n\n\n\n");
      printf("\t\t|---------------------登录-------------------|\n\n");
                    printf("\t\t    账号:");
                    scanf("%s",user);
                    printf("\n");
                    printf("\t\t    密码:");
                    scanf("%s",password);
                    printf("\n");
         printf("\t\t|--------------------------------------------|\n");
         printf("\n");}}
            if(i == 3){
                printf("\t\t\t\t密码输入错误3次，程序退出\n");
                system("pause");}}
        break;
    case 1:
        Student_menu();
        while(1){
            student_menu2();
            printf("\n\n\t\t选择您的下一步操作");
            printf("\n\t\t0、退出");
            printf("\n\t\t1、返回");
            printf("\n\t\t请输入选项：");
            scanf("%d",&item);
            if(item==0){
                system_out();}}
        break;
    case 2:
        printf("\n\n\n\n\n");
        printf("\t\t|---------------------登录-------------------|\n\n");
        printf("\t\t    账号:");
        scanf("%s",user);
        printf("\n");
        printf("\t\t    密码:");
        scanf("%s",password);
        printf("\n");
        printf("\t\t|--------------------------------------------|\n");
        while(i < 3){
            if(strcmp(user,teacher1.id)==0 || strcmp(user,teacher2.id)==0 ||strcmp(user,teacher3.id)==0 || strcmp(user,teacher4.id)==0){
                printf("\n\n\t\t登录成功\n");
                strcpy(userID,user);
                break;
           }else {
                i++;
     	if(i!=3){
      	printf("\n\n\t\t账号或密码输入错误，请重新输入\n");
       Sleep(2000);
       system("cls");
       printf("\n\n\n\n\n");
       printf("\t\t|---------------------登录-------------------|\n\n");
                    printf("\t\t    账号:");
                    scanf("%s",user);
                    printf("\n");
                    printf("\t\t    密码:");
                    scanf("%s",password);
                    printf("\n");          printf("\t\t|--------------------------------------------|\n");
            printf("\n");}}
            if(i == 3){
                printf("\t\t\t\t密码输入错误3次，程序退出\n");
                system("pause");}}
        break;}}

void mainProcess(){
    int item;       //接收键盘输入的值，判断下一步操作，输入0（退出），1（返回上一步）
    fileRead();
            //判断是否为管理员账号
    if(strcmp(user,admin.account) == 0){
        while(1){       //输入0（退出），1（返回上一步）
            Admin_menu();
            printf("\n\n\t\t选择您的下一步操作");
            printf("\n\t\t0、退出");
            printf("\n\t\t1、返回");
            printf("\n\t\t请输入选项：");
            scanf("%d",&item);
            if(item==0){
                system_out();}}}
            //判断是否为教师账号
    else if(strcmp(userID,teacher1.id)==0 || strcmp(userID,teacher2.id)==0 || strcmp(userID,teacher3.id)==0 || strcmp(userID,teacher4.id)==0){
        while(1){       //输入0（退出），1（返回上一步）
            Teacher_menu();
            printf("\n\n\t\t选择您的下一步操作");
            printf("\n\t\t0、退出");
            printf("\n\t\t1、返回");
            printf("\n\t\t请输入选项：");
            scanf("%d",&item);
            if(item==0){system_out();}}}}

void fileRead(){
    FILE *fp;
    fp = fopen("test.txt","rw+");
    int i=0;
    int num=0;
    while(!feof(fp))                     //读取一组数据后指针指向下一组数据，并且判断是否指向最后一行
	{fscanf(fp,"%s%s%d%d%d%d",student1[i].id,student1[i].name,&student1[i].score[0],&student1[i].score[1],&student1[i].score[2],&student1[i].score[3]);
	i++;}
    fclose(fp);}

void fileWrite () {     //学生单个信息保存
    FILE *fp;
    char fileName[13];
    printf("\n\t\t\t请输入要保存该信息的文件名：");
    scanf("%s",fileName);
    fp = fopen(fileName,"w+");
    int flag = 0;
    for(int i=0;i<40;i++)
        if(strcmp(student1[i].id,userID)==0)
        {   flag=1;
          fprintf(fp,"%s %s %d %d %d %d",student1[i].name,student1[i].id,student1[i].score[0],student1[i].score[1],student1[i].score[2],student1[i].score[3]);
            printf("\n\t\t\t保存成功！\n");
            break;}
    if(0==flag)
    printf("\n\n\t\t\t保存失败！\n");
    fclose(fp);}

void saveAll(){         //保存所有信息
    FILE *fp;
    char fileName[13];
    printf("\n\t\t\t请输入要保存该信息的文件名：");
    scanf("%s",fileName);
    fp = fopen(fileName,"w+");
    int flag = 0;
    for (int i=0;i<stuNum;i++)
    {   fprintf(fp,"%s %s %d %d %d %d",student1[i].id,student1[i].name,student1[i].score[0],student1[i].score[1],student1[i].score[2],student1[i].score[3]);
        fprintf(fp,"\n");
        if(student2[i].id[0] != 0){
            fprintf(fp,"%s %s %d %d %d %d",student2[i].id,student2[i].name,student2[i].score[0],student2[i].score[1],student2[i].score[2],student2[i].score[3]);
            fprintf(fp,"\n");}}
    printf("\n\t\t\t保存成功！\n");
    fclose(fp);}

void student_print(){
    /**
     * 输出函数
     * 输出学生信息
     */
    for (int i = 0; i < 40; ++i) {
        sp = &student1[i];
        printf("学号：%s\n",student1[i].id);
        printf("姓名：%s\n",student1[i].name);
        printf("C语言:%d\n",student1[i].score[0]);
        printf("高等数学:%d\n",student1[i].score[1]);
        printf("大学英语:%d\n",student1[i].score[2]);
        printf("近代史纲要:%d\n",student1[i].score[3]);
        printf("\n");}}

void student_delete(){
    int n=stuNum,flag=0;       /* flag为0表示查找失败，为1表示查找成功*/
    char s1[12];
    printf("\n\t\t\t请输入要删除学生的学号:\n");
    scanf("%s",s1);
    for(int i=0;i<40;i++)
        if(strcmp(student1[i].id,s1)==0)  /*找到要删除的学生记录*/
        {   flag=1;                   /*查找成功*/
            for(int j=i;j<3-1;j++)
                student1[j]=student1[j+1];
        }else if(strcmp(student2[i].id,s1)==0)
    if(flag==0)                /*查找失败*/
        printf("\n\t\t\t该学号不存在！\n");
    if(flag==1)
    {   printf("\n\t\t\t删除成功,显示结果请选择菜单\n");
        n--;}}

void student_search () {
    int item,flag;
    char s1[13];        /* 以姓名和学号最长长度+1为准*/
    printf("\n\t\t\t\t  ------------------\n");
    printf("\t\t\t\t-----1.按学号查询-----\n");
    printf("\t\t\t\t-----2.按姓名查询-----\n");
    printf("\t\t\t\t-----3.退出本菜单-----\n");
    printf("\t\t\t\t  ------------------\n");
    while(1){
        printf("\t\t\t\t请选择子菜单编号:");
        scanf("%d",&item);
        flag=0;
        switch(item)
        {
            case 1:
                printf("\t\t\t\t请输入要查询的学生的学号:");
                scanf("%s",s1);
                for(int i=0;i < 40;i++)
                    if(strcmp(student2[i].id,s1)==0)
                    {
                        flag=1;
                        printf("学生学号\t学生姓名\tC语言成绩\t高等数学\t大学英语成绩\t近代史纲要\n");                        printf("--------------------------------------------------------------------\n");   printf("%s\t %s\t\t %d\t\t%d\t\t %d\t\t%d\n",student2[i].id,student2[i].name,                          student2[i].score[0],student2[i].score[1],student2[i].score[2],student2[i].score[3]);
                    }else if(strcmp(student1[i].id,s1)==0){
                        flag=1;
                        printf("学生学号\t学生姓名\tC语言成绩\t高等数学\t大学英语成绩\t近代史纲要\n");       printf("--------------------------------------------------------------------\n");      printf("%s\t %s\t\t %d\t\t%d\t\t %d\t\t%d\n",student1[i].id,student1[i].name,         student1[i].score[0],student1[i].score[1],student1[i].score[2],student1[i].score[3]);}
              if(0==flag)
                 printf("\t\t\t\t该学号不存在！\n"); break;
            case 2:
                printf("\t\t\t\t请输入要查询的学生的姓名:");
                scanf("%s",s1);
                for(int i=0;i<3;i++)
                    if(strcmp(student2[i].name,s1)==0)
                    {
                        flag=1;
                        printf("\t学生学号\t学生姓名\tC语言成绩\t高等数学\t大学英语成绩\n");      printf("\t--------------------------------------------------------------------\n");
printf("\t%s\t\t %s\t\t %d\t\t %d\t\t %d\t\t %d\n",student2[i].id,                         student2[i].name,student2[i].score[0],student2[i].score[1],student2[i].score[2],student2[i].score[3]);
                    }else if(strcmp(student1[i].name,s1)==0){
                        flag=1;
                        printf("学生学号\t学生姓名\tC语言成绩\t高等数学\t大学英语成绩\t近代史纲要\n"); printf("--------------------------------------------------------------------\n");             printf("%s\t %s\t\t %d\t\t%d\t\t %d\t\t%d\n",student1[i].id,student1[i].name,                   student1[i].score[0],student1[i].score[1],student1[i].score[2],student1[i].score[3]);}
                if(0==flag)
                    printf("\t\t\t\t该姓名不存在！\n"); break;
            case 3:return;
            default:printf("\t\t\t\t请在1-3之间选择\n");}}}

void student_sort () {      //默认按学号升序排序
    struct students test;
    for (int i = 0; i < 40; ++i) {
        for (int j = 39; j > i; j--) {
            if (strcmp(student1[j].id,student1[j-1].id)<0) {
                test = student1[j];
                student1[j] = student1[j-1];
                student1[j-1] = test;}}}}

void student_sort1 () {     //按姓名升序排序
    struct students test;
    for (int i = 0; i < 40; ++i) {
        for (int j = 39; j > i; j--) {
            if (strcmp(student1[j].name,student1[j-1].name)<0) {
                test = student1[j];
                student1[j] = student1[j-1];
                student1[j-1] = test;}}}}

void student_sort2 () {     //按平均成绩升序
    struct students test;
    int avg1 = 0,avg2 = 0;
    for (int i = 0; i < 40; ++i) {
        for (int j = 39; j > i; j--) {
            avg1 = (student1[j-1].score[0]+student1[j-1].score[1]+student1[j-1].score[2]+student1[j-1].score[3])/4;
            avg2 = (student1[j].score[0]+student1[j].score[1]+student1[j].score[2]+student1[j].score[3])/4;
            if (avg1 > avg2) {
                test = student1[j];
                student1[j] = student1[j-1];
                student1[j-1] = test;}}}}

void student_sort3(){       //按总成绩升序排序
    struct students stuTest;
    int sum1 = 0,sum2 = 0;
    for (int i = 0; i < 40; ++i) {
        for (int j = 39; j > i; j--) {
sum1=student1[j-1].score[0]+student1[j-1].score[1]+student1[j-1].score[2]+student1[j-1].score[3];
sum2=student1[j].score[0]+student1[j].score[1]+student1[j].score[2]+student1[j].score[3];
            if (sum1 < sum2) {
                stuTest = student1[j];
                student1[j] = student1[j-1];
                student1[j-1] = stuTest;}}}}

void system_out () {
    printf("退出系统……");
    exit(0);            //程序正常退出}

void display(){
    int flag = 0;
    for(int i=0;i<40;i++)
        if(strcmp(student1[i].id,userID)==0)
        {   flag=1;
            printf("学生学号\t学生姓名\tC语言成绩\t高等数学\t大学英语成绩\t近代史纲要\n");    printf("--------------------------------------------------------------------\n");
printf("%s\t %s\t\t %d\t\t %d\t\t %d\t\t %d\n",student1[i].id,student1[i].name,          student1[i].score[0],student1[i].score[1],student1[i].score[2],student1[i].score[3]);}
    if(0==flag)
    printf("\n\n\t\t\t该学号不存在！\n");}

void score_analyze(){
    system("cls");
    int sum = 0, scoreAvg = 0;
    student_sort3();
    for(int i=0;i<40;i++)
        if(strcmp(student1[i].id,userID)==0){
sum=student1[i].score[0]+student1[i].score[1]+student1[i].score[2]+student1[i].score[3];
          scoreAvg = sum / 4;
          printf("\n\n\t\t学生学号\t学生姓名\tC语言成绩\t高等数学\t大学英语成绩\t近代史纲要\n");
printf("\n\n\t\t--------------------------------------------------------------------\n");  printf("\n\n\t\t%s\t %s\t\t %d\t\t %d\t\t %d\t\t %d\n",student1[i].id,student1[i].name,student1[i].score[0],student1[i].score[1],student1[i].score[2],student1[i].score[3]);
printf("\n\n\t\t--------------------------------------------------------------------\n");
printf("\n\n\t\t总成绩\t平均成绩\t排名\n");  printf("\n\n\t\t--------------------------------------------------------------------\n");
 printf("\n\n\t\t%d\t %d\t\t %d\t\t\n",sum,scoreAvg,i+1);
        }else if(strcmp(student2[i].id,userID)==0){   
sum=student2[i].score[0]+student2[i].score[1]+student2[i].score[2]+student2[i].score[3];
scoreAvg = sum / 4;
printf("\n\n\t\t学生学号\t学生姓名\tC语言成绩\t高等数学\t大学英语成绩\t近代史纲要\n");  printf("\n\n\t\t--------------------------------------------------------------------\n");
printf("\n\n\t\t%s\t %s\t\t %d\t\t %d\t\t %d\t\t %d\n",student2[i].id,student2[i].name,student2[i].score[0],student2[i].score[1],student2[i].score[2],student2[i].score[3]);
printf("\n\n\t\t--------------------------------------------------------------------\n");
printf("\n\n\t\t总成绩\t平均成绩\t排名\n");  printf("\n\n\t\t--------------------------------------------------------------------\n");
printf("\n\n\t\t%d\t %d\t\t %d\t\t\n",sum,scoreAvg,i+1);}}

void analyze(){
    system("cls");//a:100-90,b:80-89,c:70-79,d:60-69,e:60以下
    int j= 0,a1 = 0, b1 = 0, c1 = 0, d1 = 0, e1 = 0,  //C语言
             a2 = 0, b2 = 0, c2 = 0, d2 = 0, e2 = 0,    //高等数学
             a3 = 0, b3 = 0, c3 = 0, d3 = 0, e3 = 0,   //大学英语
             a4 = 0, b4 = 0, c4 = 0, d4 = 0, e4 = 0,  //近代史纲要
             a5 = 0, b5 = 0, c5 = 0, d5 = 0;    //及格率
    int sum = 0, scoreAvg = 0;
    student_sort3();
    for(j = 0; j < 40; j++){
        switch(student1[j].score[0]/10){
        case 10:a1++;break;
        case 9:a1++;break;
        case 8:b1++;break;
        case 7:c1++;break;
        case 6:d1++;break;
        default:e1++;break;}
        switch(student1[j].score[1]/10){
        case 10:a2++;break;
        case 9:a2++;break;
        case 8:b2++;break;
        case 7:c2++;break;
        case 6:d2++;break;
        default:e2++;break;}
        switch(student1[j].score[2]/10){
        case 10:a3++;break;
        case 9:a3++;break;
        case 8:b3++;break;
        case 7:c3++;break;
        case 6:d3++;break;
        default:e3++;break;}
        switch(student1[j].score[3]/10){
        case 10:a4++;break;
        case 9:a4++;break;
        case 8:b4++;break;
        case 7:c4++;break;
        case 6:d4++;break;
        default:e4++;break;}       sum=student1[j].score[0]+student1[j].score[1]+student1[j].score[2]+student1[j].score[3];
        scoreAvg = sum / 4;
        printf("\n\n\t\t学生学号\t学生姓名\tC语言成绩\t高等数学\t大学英语成绩\t近代史纲要\n");
printf("\n\n\t\t--------------------------------------------------------------------\n");
printf("\n\n\t\t%s\t %s\t\t %d\t\t %d\t\t %d\t\t %d\n",student1[j].id,student1[j].name,      student1[j].score[0],student1[j].score[1],student1[j].score[2],student1[j].score[3]);   printf("\n\n\t\t--------------------------------------------------------------------\n");
printf("\n\n\t\t总成绩\t平均成绩\t排名\n");
printf("\n\n\t\t--------------------------------------------------------------------\n");
        printf("\n\n\t\t%d\t %d\t\t %d\t\t\n",sum,scoreAvg,j+1);
        if(student2[j].id[0] != 0){
            switch(student2[j].score[0]/10){
            case 10:a1++;break;
            case 9:a1++;break;
            case 8:b1++;break;
            case 7:c1++;break;
            case 6:d1++;break;
            default:e1++;break;}
            switch(student2[j].score[1]/10){
            case 10:a2++;break;
            case 9:a2++;break;
            case 8:b2++;break;
            case 7:c2++;break;
            case 6:d2++;break;
            default:e2++;break;}
            switch(student2[j].score[2]/10){
            case 10:a3++;break;
            case 9:a3++;break;
            case 8:b3++;break;
            case 7:c3++;break;
            case 6:d3++;break;
            default:e3++;break;}
            switch(student2[j].score[3]/10){
            case 10:a4++;break;
            case 9:a4++;break;
            case 8:b4++;break;
            case 7:c4++;break;
            case 6:d4++;break;
            default:e4++;break;}
            sum = student2[j].score[0]+student2[j].score[1]+student2[j].score[2]+student2[j].score[3];
            scoreAvg = sum / 4;
            printf("\n\n\t\t学生学号\t学生姓名\tC语言成绩\t高等数学\t大学英语成绩\t近代史纲要\n");
printf("\n\n\t\t--------------------------------------------------------------------\n");     printf("\n\n\t\t%s\t %s\t\t %d\t\t %d\t\t %d\t\t %d\n",student2[j].id,student2[j].name,  student2[j].score[0],student2[j].score[1],student2[j].score[2],student2[j].score[3]);
printf("\n\n\t\t--------------------------------------------------------------------\n");
printf("\n\n\t\t总成绩\t平均成绩\t排名\n");   printf("\n\n\t\t--------------------------------------------------------------------\n");
        printf("\n\n\t\t%d\t %d\t\t %d\t\t\n",sum,scoreAvg,j+1);}}
        printf("\n\n\t\tC语言：     不及格人数：%d\t60-69分段人数：%d\t70-79分段人数：%d\t80-89分段人数：%d\t90-100分段人数：%d\n",e1,d1,c1,b1,a1);
        printf("\n\t\t高等数学：  不及格人数：%d\t60-69分段人数：%d\t70-79分段人数：%d\t80-89分段人数：%d\t90-100分段人数：%d\n",e2,d2,c2,b2,a2);
        printf("\n\t\t大学英语：  不及格人数：%d\t60-69分段人数：%d\t70-79分段人数：%d\t80-89分段人数：%d\t90-100分段人数：%d\n",e3,d3,c3,b3,a3);
        printf("\n\t\t近代史纲要：不及格人数：%d\t60-69分段人数：%d\t70-79分段人数：%d\t80-89分段人数：%d\t90-100分段人数：%d\n",e4,d4,c4,b4,a4);
        a5 = (d1+c1+b1+a1)*1.0/(a1+d1+c1+b1+e1)*100;//C语言及格率
        b5 = (d2+c2+b2+a2)*1.0/(a2+d2+c2+b2+e2)*100;//高等数学
        c5 = (d3+c3+b3+a3)*1.0/(a3+d3+c3+b3+e3)*100;//大学英语
        d5 = (d4+c4+b4+a4)*1.0/(a4+d4+c4+b4+e4)*100;//近代史
        printf("\n\t\tC语言及格率：%d%%\t\t高等数学及格率：%d%%\t大学英语及格率：%d%%\t近代史纲要及格率：%d%%\n",a5,b5,c5,d5);}

void Admin_menu(){
    system("cls");
    printf("\n\n\n\n\n");
    printf("\t\t|---------------------ADMIN---------------------|\n");
    printf("\t\t|\t 0.退出                                 |\n");
    printf("\t\t|\t 1.查询                                 |\n");
    printf("\t\t|\t 2.成绩分析                             |\n");
    printf("\t\t|\t 3.数据保存                             |\n");
    printf("\t\t|\t 4.修改                                 |\n");
    printf("\t\t|\t 5.信息输入                             |\n");
    printf("\t\t|\t 6.成绩排序                             |\n");
    printf("\t\t|\t 7.删除用户                             |\n");
    printf("\t\t|\t 输入(0-7):                             |\n");
    printf("\t\t|-----------------------------------------------|\n");
    printf("\t\t\t\t请输入功能编号：");
    scanf("%d",&test);
    switch(test){
    case 0:
        system_out();
        break;
    case 1:
        student_search();
        break;
    case 2:
        analyze();
        break;
    case 3:
        saveAll();
        break;
    case 4:
        //修改
        break;
    case 5:
        system("cls");
        student_input();
        break;
    case 6:
        Sort_menu();
        break;
    case 7:
        student_delete();
        break;
    default:
        printf("\n\n\t\t输入错误！\n");
        break;}}

void Teacher_menu(){
    system("cls");
    if (strcmp(userID,teacher1.id)==0)
            printf("\n\n\t\t\t\t欢迎%s老师登录系统！",teacher1.name);
    if (strcmp(userID,teacher2.id)==0)
            printf("\n\n\t\t\t\t欢迎%s老师登录系统！",teacher2.name);
    if (strcmp(userID,teacher3.id)==0)
            printf("\n\n\t\t\t\t欢迎%s老师登录系统！",teacher3.name);
    if (strcmp(userID,teacher4.id)==0)
            printf("\n\n\t\t\t\t欢迎%s老师登录系统！",teacher4.name);
    printf("\n\n\n\n\n");
    printf("\t\t|---------------------TEACHER------------------|\n");
    printf("\t\t\t 0.退出                                  \n");
    printf("\t\t\t 1.查询                                  \n");
    printf("\t\t\t 2.成绩分析                              \n");
    printf("\t\t\t 3.数据保存                              \n");
    printf("\t\t\t 4.修改信息                              \n");
    printf("\t\t\t 输入(0-4):                              \n");
    printf("\t\t|-----------------------------------------------|\n");
    printf("\t\t\t\t请输入功能编号：");
    scanf("%d",&test);
    switch(test){
    case 0:
        system_out();
        break;
    case 1:
        student_search();
        break;
    case 2:
        analyze();      //分析所有学生的数据
        break;
    case 3:
        saveAll();      //保存所有成员数据
        break;
    case 4:
        modify();       //修改单个学生的所有成绩
        break;
    default:
        printf("\n\n\t\t输入错误！\n");
        break;}}

void Student_menu(){
    char stuId[12];
    int i = 0;
    system("cls");
    printf("\n\n\t\t\t请输入学号：");
    scanf("%s",stuId);
    while(i < 3){
        if(strlen(stuId)==12){
            printf("\n\n\t\t\t输入成功！\n\n");
            strcpy(userID,stuId);
            Sleep(2000);
            break;
        }else{
            	i++;
                if(i!=3){
                    printf("\n\n\t\t输入错误!\n\n\t\t\t请重新输入:");
                    scanf("%s",stuId);}}
        if(i == 3){
                printf("\t\t\t\t输入错误3次，程序退出\n");
                system("pause");}}}

void student_menu2(){
    system("cls");
    printf("\n\n\n\n\n");
    printf("\t\t|---------------------STUDENT-------------------|\n");
    printf("\t\t\t 0.退出                                  \n");
    printf("\t\t\t 1.查询信息                              \n");
    printf("\t\t\t 2.成绩分析                              \n");
    printf("\t\t\t 3.数据保存                              \n");
    printf("\t\t\t 输入(0-3):                              \n");
    printf("\t\t|-----------------------------------------------|\n");
    printf("\t\t\t\t请输入功能编号：");
    scanf("%d",&test);
    switch(test){
    case 0:
        system_out();
        break;
    case 1:
        display();
        break;
    case 2:
        score_analyze();
        break;
    case 3:
        fileWrite();
        break;
    default:
        printf("\n\n\t\t输入错误！\n");
        break;}}

void modify(){      //修改、保存(写出到文件)
   printf("\n\n\t\t请输入需要修改信息的学生学号:");
   scanf("%s",&userID);
   for (int i = 0; i< 40; i++){
        if(strcmp(userID,student1[i].id)==0){
            printf("\n\n\t\t已找到该学生，请修改");
            printf("\n\t\t学号：%s",student1[i].id);
            printf("\n\t\t姓名：%s",student1[i].name);
            printf("\n\t\tC语言：");
            scanf("%d",&student1[i].score[0]);
            printf("\n\t\t高等数学：");
            scanf("%d",&student1[i].score[1]);
            printf("\n\t\t大学英语：");
            scanf("%d",&student1[i].score[2]);
            printf("\n\t\t近代史纲要：");
            scanf("%d",&student1[i].score[3]);
            break;}}}

void student_input() /*输入函数*/{
    int j=0,i,flag;
    int item=1;
    while(item){
        flag=1;
        while(flag)
        {   flag=0;
            printf("\n\n\t\t请输入第%d位学生的学号:",j+1);
            scanf("%s",student2[j].id);
            for(i=0;i<j;i++)  /*与之前的学号比较，如果重复，则重新输入*/
                if(strcmp(student2[j].id,student2[i].id)==0)
                {printf("已有该学号，请重新录入");
                    flag=1;
                    break;/*如有重复，退出循环*/}}
        printf("\n\t\t请输入第%d个学生的姓名:",j+1);
        scanf("%s",student2[j].name);
        printf("\n\t\t请输入第%d个学生的C语言成绩:",j+1);
        scanf("%d",&student2[j].score[0]);
        printf("\n\t\t请输入第%d个学生的高等数学成绩:",j+1);
        scanf("%d",&student2[j].score[1]);
        printf("\n\t\t请输入第%d个学生的大学英语成绩:",j+1);
        scanf("%d",&student2[j].score[2]);
        printf("\n\t\t请输入第%d个学生的近代史纲要成绩:",j+1);
        scanf("%d",&student2[j].score[3]);
        j++;
        printf("\n\t\t是否继续输入(1/0):");
        scanf("%d",&item);
        printf("\n\t\t输入成功\n");}}

void Sort_menu(){
    int choice;
    system("cls");
    printf("\n\n\n\n\n");
    printf("\t\t|---------------------Sort----------------------|\n");
    printf("\t\t\t 0.退出                                  \n");
    printf("\t\t\t 1.姓名排序                              \n");
    printf("\t\t\t 2.平均成绩                              \n");
    printf("\t\t\t 3.总成绩                                \n");
    printf("\t\t|-----------------------------------------------|\n");
    printf("\t\t\t\t请输入功能编号：");
    scanf("%d",&choice);
    switch(choice){
    case 0:
        system_out();
        break;
    case 1:
        student_sort1();
        student_print();
        break;
    case 2:
        student_sort2();
        student_print();
        break;
    case 3:
        student_sort3();
        student_print();
        break;}}
