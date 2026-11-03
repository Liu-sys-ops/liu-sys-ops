//
// Created by honghuang on 2026/10/26.
//

#ifndef UNTITLED3_TOUWENJIAN_H
#define UNTITLED3_TOUWENJIAN_H

#endif //UNTITLED3_TOUWENJIAN_H



struct Student
{
    char name[20];
    int score;
};
#define MAX_STU 30
extern struct Student stu[MAX_STU];
extern int count;

void menu();
void inputscore();
void showscore();
void calcscore();
void sortscore();
void searchscore();
void modifyscore();
void delscore();
void loadFile();
void savefile();


