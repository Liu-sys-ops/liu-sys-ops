#include<stdio.h>
#include<string.h>
#include"touwenjian.h"




int main()
{
    loadFile();
    int choose;
    menu();
    while (1)
    {
        loadFile();
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            inputscore();
                savefile();
            break;
        case 2:
            showscore();
            break;
        case 3:
            calcscore();
            break;
        case 4:
            sortscore();
            break;
        case 5:
            searchscore();
            break;
        case 6:
            modifyscore();
            break;
        case 7:
            delscore();
            break;
        case 0:
            printf("系统已安全退出\n");
                savefile();
            return 0;
        default:
            printf("输入错误，请重新输入\n");
        }
    }
    return 0;
}







