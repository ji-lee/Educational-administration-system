#ifndef CHANGE_STU_MESSAGE_H
#define CHANGE_STU_MESSAGE_H

#include"link.h"

//更改学生信息相关函数
void change_stu_id(STU_PNODE stu_head);
void change_stu_name(STU_PNODE stu_head);
void change_stu_sex(STU_PNODE stu_head);
void change_stu_age(STU_PNODE stu_head);
void change_stu_class_num(STU_PNODE stu_head);
void change_score(STU_PNODE stu_head);
void init_stu_passwd(STU_PNODE stu_head);

//显示更改菜单和箭头移动函数
void show_change_stu_menu(int num);
int get_change_stu_command(int xuan_xiang_ge_shu);

#endif
