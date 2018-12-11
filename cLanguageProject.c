#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#define LEN sizeof(course)

typedef struct abab
{
    char numb[20];
    char nam[20];
    char zhuan[20];
    char xing[20];
    int time;
    int score;
    char day[20];
    char where[20];
    struct abab *next;
} course;

int power;
course *place_head=NULL;
course *place_last=NULL;

void shuru()
{
    if(place_head!=NULL)
    {
        course *p=place_head;
        while(place_head!=NULL)
        {
            p=place_head->next;
            free(place_head);
            place_head=p;
        }
    }
    printf("输入要创建的课程数（输入0取消）：");
    int t;
    scanf("%d",&t);
    if(t==0)
        return;
    course *p1,*p2;
    printf("          -------------------------------------------------------------------------------------------------\n"
           "         |  课程号  |  课程名  |  所属专业  |  性质  |  学时  |  学分  |    上  课  时  间    |   地  点   |\n"
           "          -------------------------------------------------------------------------------------------------\n");
    place_head=p2=p1=(course *)malloc(LEN);
    scanf("%s%s%s%s%d%d%s%s",p1->numb,p1->nam,p1->zhuan,p1->xing,&p1->time,&p1->score,p1->day,p1->where);
    t--;
    while(t--)
    {
        p2=(course *)malloc(LEN);
        scanf("%s%s%s%s%d%d%s%s",p2->numb,p2->nam,p2->zhuan,p2->xing,&p2->time,&p2->score,p2->day,p2->where);
        p1->next=p2;
        p1=p2;
    }
    place_last=p2;
    place_last->next=NULL;
}

void add()
{
    printf("          -------------------------------------------------------------------------------------------------\n"
           "         |  课程号  |  课程名  |  所属专业  |  性质  |  学时  |  学分  |    上  课  时  间    |   地  点   |\n"
           "          -------------------------------------------------------------------------------------------------\n");
    if(place_head!=NULL)
    {
        course *p1=(course *)malloc(LEN);
        place_last->next=p1;
        scanf("%s%s%s%s%d%d%s%s",p1->numb,p1->nam,p1->zhuan,p1->xing,&p1->time,&p1->score,p1->day,p1->where);
        place_last=p1;
        place_last->next=NULL;
    }
    else
    {
        course *p1=place_head=place_last=(course *)malloc(LEN);
        scanf("%s%s%s%s%d%d%s%s",p1->numb,p1->nam,p1->zhuan,p1->xing,&p1->time,&p1->score,p1->day,p1->where);
        place_last->next=NULL;
    }
}

void chazhao()
{
    printf("输入1、查询课程号；\n输入2、查询课程名；\n输入0、取消:    ");
    char a[20],b[]="1",c[]="2",d[]="0";
    int aa;
    while(~scanf("%s",a))
    {
        if(strcmp(a,b)==0)
        {
            printf("输入课程号：");
            aa=1;
            break;
        }
        else if(strcmp(a,c)==0)
        {
            printf("输入课程名：");
            aa=2;
            break;
        }
        else if(strcmp(a,d)==0)
        {
            return;
        }
        else printf("parden?");
    }
    char what[20];
    scanf("%s",what);
    course *p1;
    p1=place_head;
    printf("          -------------------------------------------------------------------------------------------------\n"
           "         |  课程号  |  课程名  |  所属专业  |  性质  |  学时  |  学分  |    上  课  时  间    |   地  点   |\n"
           "          -------------------------------------------------------------------------------------------------\n");
    if(aa==1)
    {
        aa=0;
        do
        {
            if(strcmp(p1->numb,what)==0)
            {
                printf("         |%8s  |%8s  |%10s  |%6s  |%6d  |%6d  |%20s  |%10s  |\n",p1->numb,p1->nam,p1->zhuan,p1->xing,p1->time,p1->score,p1->day,p1->where);
                printf("          -------------------------------------------------------------------------------------------------\n");
                aa++;
            }
            p1=p1->next;
        }
        while(p1!=NULL);
        if(aa==0)
            printf("查无此课！\n");
    }
    if(aa==2)
    {
        aa=0;
        do
        {
            if(strcmp(p1->nam,what)==0)
            {
                printf("         |%8s  |%8s  |%10s  |%6s  |%6d  |%6d  |%20s  |%10s  |\n",p1->numb,p1->nam,p1->zhuan,p1->xing,p1->time,p1->score,p1->day,p1->where);
                printf("          -------------------------------------------------------------------------------------------------\n");
                aa++;
            }
            p1=p1->next;
        }
        while(p1!=NULL);
        if(aa==0)
            printf("查无此课！\n");
    }
}

void xiugai()
{
    printf("输入需修改的查询课程号、查询课程名；\n输入“我最帅 666”取消:    ");
    char a[20],b[20],q[]="我最帅",w[]="666";
    scanf("%s%s",a,b);
    if(strcmp(a,q)==0 && strcmp(b,w)==0)
        return;
    printf("修改：1、专业 2、性质");
    int aa;
    scanf("%d",&aa);
    course *p1;
    p1=place_head;
    if(aa==1)
    {
        printf("输入修改的【专业】：");
        char ss[20];
        scanf("%s",ss);
        aa=0;
        do
        {
            if(strcmp(p1->numb,a)==0 && strcmp(p1->nam,b)==0)
            {
                strcpy(p1->zhuan,ss);
                aa++;
            }
            p1=p1->next;
        }
        while(p1!=NULL);
        if(aa==0)
            printf("查无此课！\n");
    }
    if(aa==2)
    {
        printf("输入修改的【性质】：");
        char ss[20];
        scanf("%s",ss);
        aa=0;
        do
        {
            if(strcmp(p1->numb,a)==0 && strcmp(p1->nam,b)==0)
            {
                strcpy(p1->xing,ss);
                aa++;
            }
            p1=p1->next;
        }
        while(p1!=NULL);
        if(aa==0)
            printf("查无此课！\n");
    }
}

void shanchu()
{
    printf("输入需删除的课程号、课程名；\n输入“我最帅 666”取消:    ");
    char a[20],b[20],q[]="我最帅",w[]="666";
    scanf("%s%s",a,b);
    if(strcmp(a,q)==0 && strcmp(b,w)==0)
        return;
    course *p1,*p2;
    p1=p2=place_head;
    while(p2==place_head && p2->next!=NULL && strcmp(p2->numb,a)==0 && strcmp(p2->nam,b)==0)
    {
        place_head=p2->next;
        p1=p2->next;
        free(p2);
        p2=p1;
    }
    while(p2->next!=NULL)
    {
        if(strcmp(p2->numb,a)==0 && strcmp(p2->nam,b)==0)
        {
            p1->next=p2->next;
            free(p2);
            p2=p1->next;
        }
        else
        {
            p1=p2;
            p2=p2->next;
        }
    }
    if(strcmp(p2->numb,a)==0 && strcmp(p2->nam,b)==0)
    {
        if(place_head==place_last)
        {
            place_head=place_last=NULL;
            free(p2);
        }
        else
        {
            place_last=p1;
            p1->next=NULL;
            free(p2);
        }
    }
    printf("删除成功！\n");
}

void xianshi()
{
    printf("          -------------------------------------------------------------------------------------------------\n"
           "         |  课程号  |  课程名  |  所属专业  |  性质  |  学时  |  学分  |    上  课  时  间    |   地  点   |\n"
           "          -------------------------------------------------------------------------------------------------\n");
    course *p1;
    p1=place_head;
    do
    {
        printf("         |%8s  |%8s  |%10s  |%6s  |%6d  |%6d  |%20s  |%10s  |\n",p1->numb,p1->nam,p1->zhuan,p1->xing,p1->time,p1->score,p1->day,p1->where);
        printf("          -------------------------------------------------------------------------------------------------\n");
        p1=p1->next;
    }
    while(p1!=NULL);
}

void frempt()
{
    course *p=place_head;
    while(place_head!=NULL)
    {
        p=place_head->next;
        free(place_head);
        place_head=p;
    }
    printf("清空成功！");
}

void ap()
{
    system("cls");
    system("color 2e");
    printf("请以【管理员】、【教师】、【学生】身份登陆\n输入密匙证明身份：");
    char a[21],b[]="123",c[]="111";
    //scanf("%s",a);
    int i=0;
    do
    {
        a[i]=getch();
        if(a[i]=='\r')///回车
            break;
        if(a[i]=='\b')///退格
        {
            if(i==0)
            {
                printf("\a");///响铃
                continue;
            }
            i=i-1;
            printf("\b \b");
        }
        else
        {
            i=i+1;
            printf("*");
        }
    }
    while(a[i]!='\n' && i<20);
    a[i]='\0';
    if(strcmp(a,b)==0) power=3;
    else if(strcmp(a,c)==0) power=2;
    else power =1;
    system("color f5");
}

void app()
{
    printf("\n");
    printf("\t\t\t***************************************\n");
    printf("\t\t\t*           输入1  显示课程           *\n");
    printf("\t\t\t***                                 ***\n");
    printf("\t\t\t*           输入2  查找课程           *\n");
    printf("\t\t\t***                                 ***\n");
    if(power==2||power==3)
    {
        printf("\t\t\t*           输入3  增加课程           *\n");
        printf("\t\t\t***                                 ***\n");
        printf("\t\t\t*           输入4  修改课程           *\n");
        printf("\t\t\t***                                 ***\n");
    }
    if(power==3)
    {
        printf("\t\t\t*           输入5  输入课程           *\n");
        printf("\t\t\t***                                 ***\n");
        printf("\t\t\t*           输入6  删除课程           *\n");
        printf("\t\t\t***                                 ***\n");
        printf("\t\t\t*           输入7  清除所有           *\n");
        printf("\t\t\t***                                 ***\n");
    }
    printf("\t\t\t*           输入byebye  退出          *\n");
    printf("\t\t\t***************************************\n\n");
}

int main()
{
    system("color f5");
    shuru();
    power=0;
    ap();
    app();
    getchar();
    char number[20],n1[]="1",n2[]="2",n3[]="3",n4[]="4",n5[]="5",n6[]="6",n7[]="7",n8[]="byebye";
    while(~scanf("%s",number))
    {
        system("cls");
        app();
        getchar();
        if(strcmp(number,n1)==0)
        {
            if(place_head!=NULL)
                xianshi();
            else printf("数据库为空！\n");
        }
        else if(strcmp(number,n2)==0)
        {
            if(place_head!=NULL)
                chazhao();
            else printf("数据库为空！\n");
        }
        else if(strcmp(number,n3)==0 && power>1)
        {
            add();
        }
        else if(strcmp(number,n4)==0 && power>1)
        {
            if(place_head!=NULL)
                xiugai();
            else printf("数据库为空！\n");
        }
        else if(strcmp(number,n5)==0 && power>2)
        {
            shuru();
        }
        else if(strcmp(number,n6)==0 && power>2)
        {
            if(place_head!=NULL)
                shanchu();
            else printf("数据库为空！\n");
        }
        else if(strcmp(number,n7)==0)
        {
            frempt();
        }
        else if(strcmp(number,n8)==0)
        {
            system("cls");
            printf("\t\t\t\t\tgoodby!(灬0ω0灬)\n");
            printf("\t\t\t\t\tgoodby!(灬0ω0灬)\n");
            printf("\t\t\t\t\tgoodby!(灬0ω0灬)\n");
            printf("\t\t\t\t\tgoodby!(灬0ω0灬)\n");
            printf("\t\t\t\t\tgoodby!(灬0ω0灬)\n");
            printf("\t\t\t\t\tgoodby!(灬0ω0灬)\n");
            printf("\t\t\t\t\tgoodby!(灬0ω0灬)\n");
            printf("\t\t\t\t\tgoodby!(灬0ω0灬)\n");
            printf("\t\t\t\t\tgoodby!(灬0ω0灬)\n");
            printf("\t\t\t\t\tgoodby!(灬0ω0灬)\n");
            printf("\t\t\t\t\tgoodby!(灬0ω0灬)\n");
            printf("\t\t\t\t\tgoodby!(灬0ω0灬)\n");
            printf("\t\t\t\t\tgoodby!(灬0ω0灬)\n");
            printf("\t\t\t\t\tgoodby!(灬0ω0灬)\n");
            printf("\t\t\t\t\tgoodby!(灬0ω0灬)\n");
            printf("\t\t\t\t\tgoodby!(灬0ω0灬)\n");
            printf("\t\t\t\t\tgoodby!(灬0ω0灬)\n");
            for(int i=0; i<9; i++)
            {
                system("color f4");
                system("color f5");
                system("color f1");
                system("color f2");
                system("color f3");
                system("color f6");
            }
            return 0;
        }
        printf("输入：");
    }
}
