#include"show_all_stu_message.h"

/****************************************************
*	实现功能：显示所有学生信息选择					*
*	输入参数：学生链表								*
*	返回值  ：	无									*
****************************************************/
void show_all_stu_message(STU_PNODE stu_head)
{
	if(NULL == stu_head->next)
	{
		system("clear");
		printf("\n学生信息为空，没有数据可以显示．\n");
		press_any_one();
		return;
	}

	while(ONE)
	{
		switch(get_command(SHOW_ALL_STU_MESSAGE_MENU))
		{
			case 0:show_by_id(stu_head);          press_any_one(); break;
			case 1:show_by_total_score(stu_head); press_any_one(); break;
			case 2:show_by_one_score(stu_head);   press_any_one(); break;
			case 3:show_by_grade(stu_head);       press_any_one(); break;
			case 4:return;
		}
	}
}

/****************************************************
*	实现功能：显示所有学生信息界面					*
*	输入参数：箭头指向的位置						*
*	返回值  ：	无									*
****************************************************/
void show_all_stu_message_menu(int num)
{
	system("clear");
	printf(
		"\n\t       -----------------------------------------\n"
		"\n\t%s    按照学生id顺序显示      "
		"\n\t                              "
		"\n\t%s    按照学生总分顺序显示    "
		"\n\t                              "
		"\n\t%s    按照学生单科成绩顺序显示"
		"\n\t                              "
		"\n\t%s    按照分数段显示          "
		"\n\t       ---------------------- "
		"\n\t                              "
		"\n\t%s    返回上一层              "
		"\n\t       ---------------------- "
		"\n\t                              "
		"\n\n\t       提示：<w> -> 上   <s> -> 下   <j> -> 选择"
		"\n\t       -----------------------------------------\n"
		, num == 0 ? MARK_SELECT : MARK_NO_SELECT
		, num == 1 ? MARK_SELECT : MARK_NO_SELECT
		, num == 2 ? MARK_SELECT : MARK_NO_SELECT
		, num == 3 ? MARK_SELECT : MARK_NO_SELECT
		, num == 4 ? MARK_SELECT : MARK_NO_SELECT
		);
}

/****************************************************
*	实现功能：按id排序显示							*
*	输入参数：学生链表								*
*	返回值  ：无									*
****************************************************/
void show_by_id(STU_PNODE stu_head)
{
	stu_bubble_sort(stu_head, SORT_BY_ID);
	output_stu_node(stu_head);
}

/****************************************************
*	实现功能：按总分排序							*
*	输入参数：学生链表								*
*	返回值  ：无									*
****************************************************/
void show_by_total_score(STU_PNODE stu_head)
{
	stu_bubble_sort(stu_head, SORT_BY_TOTAL_SCORE);
	output_stu_node(stu_head);
}

/****************************************************
*	实现功能：按单科成绩显示						*
*	输入参数：学生链表								*
*	返回值  ：无									*
****************************************************/
void show_by_one_score(STU_PNODE stu_head)
{
	system("clear");
	printf(
		"\n\t    --------------------"
		"\n\t    请选择按哪一科目显示："
		"\n\t                        "
		"\n\t    1)---math"
		"\n\t                        "
		"\n\t    2)---chinese"
		"\n\t                        "
		"\n\t    3)---C program"
		"\n\t                        "
		"\n\t    --------------------"
		"\n\n\t  请选择："
		);
	int select;
	scanf("%d", &select);
	while(getchar() != '\n');

	if((select != 1) && (select != 2) && (select != 3))
	{
		system("clear");
		printf("\n选择输入有误．\n");
		return;
	}

	switch(select)
	{
		case 1:
			stu_bubble_sort(stu_head, SORT_BY_MATH);
			output_stu_node(stu_head);
			break;
		case 2:
			stu_bubble_sort(stu_head, SORT_BY_CHINESE);
			output_stu_node(stu_head);
			break;
		case 3:
			stu_bubble_sort(stu_head, SORT_BY_C_PROGRAM);
			output_stu_node(stu_head);
			break;
	}
}

/****************************************************
*	实现功能：按分数段显示							*
*	输入参数：学生链表								*
*	返回值  ：无									*
****************************************************/
void show_by_grade(STU_PNODE stu_head)
{
	system("clear");

	if(NULL == stu_head->next)
	{
		printf("\n学生信息为空．\n");
		return;
	}
	
	stu_bubble_sort(stu_head, SORT_BY_TOTAL_SCORE);
	
	STU_PNODE p = stu_head->next;
	
	printf("\n总分在1-150分之间的学生：\n");
	printf("\n\t 学号   姓名                   性别     年龄   班级     数学成绩       语文成绩        C语言成绩         总分\n");
	while(p != NULL)
	{
		if(p->stu_data.total_score < 150)
		{
		printf("\n\t%6d\t%-22s\t%2c\t%3d\t%2d\t%6.2f\t\t%6.2f\t\t%6.2f\t\t%6.2f\n"
				,p->stu_data.id
				,p->stu_data.name
				,p->stu_data.sex
				,p->stu_data.age
				,p->stu_data.class_num
				,p->stu_data.math_score
				,p->stu_data.chinese_score
				,p->stu_data.c_program_score
				,p->stu_data.total_score
				);
		}
		p = p->next;
	}
	printf("\n总分在150-300分之间的学生：\n");
	printf("\n\t 学号   姓名                   性别     年龄   班级     数学成绩       语文成绩        C语言成绩         总分\n");
	p = stu_head->next;
	while(p != NULL)
	{
		if(p->stu_data.total_score >= 150)
		{
		printf("\n\t%6d\t%-22s\t%2c\t%3d\t%2d\t%6.2f\t\t%6.2f\t\t%6.2f\t\t%6.2f\n"
				,p->stu_data.id
				,p->stu_data.name
				,p->stu_data.sex
				,p->stu_data.age
				,p->stu_data.class_num
				,p->stu_data.math_score
				,p->stu_data.chinese_score
				,p->stu_data.c_program_score
				,p->stu_data.total_score
				);
		}		
		p = p->next;
	}
}



