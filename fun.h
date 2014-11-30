#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

//箭头显示
#define MARK_SELECT      "-->"
#define MARK_NO_SELECT   "   "

//常量
#define ONE              1
#define NOT_FOUND        -1
#define FOUND            1

//相关字符数组最大长度
#define NAME_MAX         20
#define PASSWD_MAX       16
#define SUBJECT_MAX      20
#define HEAD_TEACHER_MAX 4

//界面显示所需的参数
#define SHOW_LOGIN_MENU            4
#define SHOW_AD_LOGIN_MENU         13
#define SHOW_STU_LOGIN_MENU        3
#define SHOW_TEA_LOGIN_MENU        8
#define SHOW_ALL_STU_MESSAGE_MENU  5
#define SHOW_CHANGE_TEA_MENU       7
#define SHOW_CHANGE_STU_MENU       8


#define CHAR_MODE_START system("stty raw");		//缓冲按单个字符接受，像windows的getch()
#define CHAR_MODE_STOP system("stty cooked");	//取消缓冲单个接受


void press_any_one();                    //确认继续
void mygets(char *str, int len);         //输入字符串
int getch();                             //菜单箭头移动 
int get_command(int xuan_xiang_ge_shu);  //确认继续


//界面显示函数
void show_stu_login_menu(int num);
void show_login_menu(int num);
void show_all_stu_message_menu(int num);
void show_change_tea_menu(int num);
void show_change_stu_menu(int num);
void show_tea_login_menu(int num);
void show_ad_login_menu(int num);



