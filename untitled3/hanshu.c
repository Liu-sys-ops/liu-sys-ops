//
// Created by honghuang on 2026/10/26.
//
#include<stdio.h>
#include<string.h>
#include "touwenjian.h"

struct Student stu[MAX_STU];
int count=0;
void menu()
{
    printf("\n========学生成绩管理系统========\n");
    printf("1. 录入学生信息\n");
    printf("2. 显示所有学生信息\n");
    printf("3. 统计：总分、平均分、最高分、最低分\n");
    printf("4. 按成绩降序排序\n");
    printf("5. 按姓名查找学生\n");
    printf("6. 修改学生成绩\n");
    printf("7. 删除学生信息\n");
    printf("0. 退出系统\n");
    printf("================================\n");
    printf("请输入你的选择：");
}
void inputscore() {
    int i;
    printf("请输入要录入的人数：");
    scanf("%d",&count);
    if (count >= MAX_STU)
    {
        printf("人数已满，无法继续录入！\n");
        return;
    }
    printf("%d",count);
for ( i=0;i<count;)
    {
    printf("请输入第%d个学生姓名和成绩：", i + 1);
    scanf("%s %d", stu[i].name, &stu[i].score);
    if(stu[i].score > 150||stu[i].score<0) {
        printf("成绩超出有效值，请重新输入！！\n");
        continue;}
    i++;
    }
printf("录入成功！\n");

}

void showscore()
{
    int i;
    if (count == 0)
    {
        printf("暂无学生数据！\n");
        return;
    }
    printf("\n序号\t姓名\t成绩\n");
    for (i = 0; i < count; i++)
    {
        printf("%d\t%s\t%d\n", i + 1, stu[i].name, stu[i].score);
    }
}
void loadFile()
{
    FILE *fp = fopen("stu.dat", "rb");
    if(fp == NULL)
    {
        printf("没有找到历史数据文件，新建系统\n");
        count = 0;
        return;
    }
    fread(&count, sizeof(int), 1, fp);
    fread(stu, sizeof(stu[MAX_STU]), count, fp);
    fclose(fp);
    printf(" 读取到 %d 条学生记录\n", count);
}

void savefile()
{
    FILE *fp = fopen("stu.dat", "wb");
    if(fp == NULL)
    {
        printf("打开文件失败，无法保存！\n");
        return;
    }
    fwrite(&count, sizeof(int), 1, fp);
    fwrite(stu, sizeof(stu[MAX_STU]), count, fp);
    fclose(fp);
    printf("数据保存成功！\n");
}
void calcscore()
{
    int i;
    int sum = 0;
    double avg;
    int max, min;
    if (count == 0)
    {
        printf("暂无学生数据！\n");
        return;
    }
    max = stu[0].score;
    min = stu[0].score;
    for (i = 0; i < count; i++)
    {
        sum += stu[i].score;
        if (stu[i].score > max)
            max = stu[i].score;
        if (stu[i].score < min)
            min = stu[i].score;
    }
    avg = (double)sum / count;
    printf("总分：%d\n", sum);
    printf("平均分：%.2f\n", avg);
    printf("最高分：%d\n", max);
    printf("最低分：%d\n", min);
}

void sortscore()
{
    int i, j;
    struct Student temp;
    if (count == 0)
    {
        printf("暂无学生数据！\n");
        return;
    }
    for (i = 0; i < count - 1; i++)
    {
        for (j = 0; j < count - 1 - i; j++)
        {
            if (stu[j].score < stu[j + 1].score)
            {
                temp = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = temp;
            }
        }
    }
    printf("排序完成！\n");
}
void searchscore()
{
    char findname[20];
    int i, flag = 0;
    printf("请输入要查找的姓名：");
    scanf("%s", findname);
    for (i = 0; i < count; i++)
    {
        if (strcmp(stu[i].name, findname) == 0)
        {
            printf("找到：%s，成绩：%d\n", stu[i].name, stu[i].score);
            flag = 1;

        }
    }
    if (flag == 0)
    {
        printf("没有找到该学生！\n");
    }
}
void modifyscore()
{
    char findname[20];
    int i, flag = 0;
    int newscore;
    printf("请输入要修改的学生姓名：");
    scanf("%s", findname);
    for (i = 0; i < count; i++)
    {
        if (strcmp(stu[i].name, findname) == 0)
        {
            printf("找到学生【%s】，原成绩：%d，序号%d\n", stu[i].name, stu[i].score,i+1);

            flag = 1;

        }
    }
    if (flag == 0)
    {
        printf("没有找到该学生！\n");
    }
    out:printf("请输入要修改的序号");
    scanf("%d",&i);
    if (i>=1&&i<count){
        i--;
    printf("请输入新成绩：");
            scanf("%d", &newscore);
            stu[i].score = newscore;
            printf("修改成功！\n");}
    else goto out;

}
void delscore()
{
    char findname[20];
    int i, j, flag = 0;
    printf("请输入要删除的学生姓名：");
    scanf("%s", findname);
    for (i = 0; i < count; i++)
    {
        if (strcmp(stu[i].name, findname) == 0)

        {
            printf("序号：%d 姓名：%s 成绩：%d",i+1,stu[i].name,stu[i].score);
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("没有找到该学生！\n");

    }
    if (flag==1) {
        printf("请输入要修改的序号");

        scanf("%d",&i);
        if (i>=1&&i<count){ i--;
        for (j = i; j < count - 1; j++)
        {
            stu[j] = stu[j + 1];
        }
        count--;
        printf("删除成功！\n");}

    }
}



