#ifndef ADMIN_H
#define ADMIN_H

#include"login.h"

//保存管理员帐号密码的结构体
typedef struct
{
	char name[NAME_MAX];
	char passwd[PASSWD_MAX];
}ADMIN;


//管理员操作
ADMIN load_admin_data();
int login_admin();
void save_admin_data(ADMIN admin);
void change_ad_name(ADMIN admin);
void change_ad_passwd(ADMIN admin);

//针对学生操作
void change_stu_message(STU_PNODE stu_head);

//针对教师操作
void add_tea_message(TEA_PLINK tea_head);
void delete_tea_message(TEA_PLINK tea_head);
void change_tea_message(TEA_PLINK tea_head);
void find_tea_message(TEA_PLINK tea_head);
void show_all_tea_message(TEA_PLINK tea_head);
#endif
