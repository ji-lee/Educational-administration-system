#ifndef TEACHER_H
#define TEACHER_H

#include"login.h"

TEA_PLINK login_teacher(TEA_PLINK tea_head);  //教师登录判断
void show_tea_message(TEA_PLINK tea_head);    //显示教师个人信息
void change_tea_passwd(TEA_PLINK tea_head);   //更改教师个人密码

//针对学生相关信息操作
void add_stu_message(TEA_PLINK tea_head, STU_PNODE stu_head);
void delete_student(TEA_PLINK tea_head, STU_PNODE stu_head);
void change_stu_score(TEA_PLINK tea_head, STU_PNODE stu_head);
void find_stu_message(STU_PNODE stu_head);
void show_all_stu_message(STU_PNODE stu_head);

#endif
