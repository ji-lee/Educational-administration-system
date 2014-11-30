#ifndef LOGIN_H
#define LOGIN_H

#include"link.h"

void login();                                         //总的登录
void student(STU_PNODE stu_head);                     //学生登录
void teacher(STU_PNODE stu_head, TEA_PLINK tea_head); //教师登录
void admin(STU_PNODE stu_head, TEA_PLINK tea_head);   //管理员登录


//加载和保存学生教师信息
STU_PNODE load_stu_data();
TEA_PLINK load_tea_data();
void save_stu_data(STU_PNODE stu_head);
void save_tea_data(TEA_PLINK tea_head);

#endif







