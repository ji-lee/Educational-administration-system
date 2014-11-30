#ifndef LINK_H
#define LINK_H

#include"fun.h"


//学生信息排序函数所需参数
#define SORT_BY_ID          1
#define SORT_BY_TOTAL_SCORE 2
#define SORT_BY_MATH        3
#define SORT_BY_CHINESE     4
#define SORT_BY_C_PROGRAM   5




//学生信息结构体
typedef struct 
{
	int id;
	char name[NAME_MAX];
	char passwd[PASSWD_MAX];
	char sex;
	int age;
	
	int class_num;
	float math_score;
	float chinese_score;
	float c_program_score;

	float total_score;
}STU;

//学生信息链表
typedef struct node
{
	STU stu_data;
	struct node *next;
}STU_NODE, *STU_PNODE;


//教师信息结构体
typedef struct
{
	int id;
	char name[NAME_MAX];
	char passwd[PASSWD_MAX];
	int age;
	char sex;
	char subject[SUBJECT_MAX];
	char head_teacher[HEAD_TEACHER_MAX];	
}TEA;

//教师信息链表
typedef struct link
{
	TEA tea_data;
	struct link *next;
}TEA_LINK, *TEA_PLINK;


//学生信息链表操作
STU_PNODE find_stu_pre_node(STU_PNODE stu_head, int stu_id);  
void stu_bubble_sort(STU_PNODE stu_head, int select);         
void output_stu_node(STU_PNODE stu_head);                     
void delete_stu_node(STU_PNODE stu_head);                      
void head_insert_stu_node(STU_PNODE stu_head, STU stu_data);   
STU_PNODE create_stu_node(STU stu_data);                         


//教师信息链表操作
TEA_PLINK find_tea_pre_node(TEA_PLINK tea_head, int tea_id);   
void bubble_sort_tea(TEA_PLINK tea_head);
void output_tea_node(TEA_PLINK tea_head);
void delete_tea_node(TEA_PLINK tea_head); 
void head_insert_tea_node(TEA_PLINK tea_head, TEA tea_data);
TEA_PLINK create_tea_node(TEA tea_data);

#endif
