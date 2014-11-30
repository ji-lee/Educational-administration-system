#ifndef STUDENT_H
#define STUDENT_H

#include"login.h"

STU_PNODE login_student(STU_PNODE stu_head);  //学生登录判断
void show_stu_message(STU_PNODE stu_head);    //学生个人信息显示
void change_stu_passwd(STU_PNODE stu_head);   //更改学生个人密码

#endif

