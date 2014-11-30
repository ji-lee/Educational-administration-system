#include"student.h"

/****************************************************
*	实现功能：学生登录选择							*
*	输入参数：学生链表								*
*	返回值  ：无									*
****************************************************/
void student(STU_PNODE stu_head)
{
	STU_PNODE find = login_student(stu_head);
	if(NULL == find)
	{
		return;
	}
	while(ONE)
	{
		switch(get_command(SHOW_STU_LOGIN_MENU))
		{
			case 0: show_stu_message(find);  press_any_one(); break;
			case 1: change_stu_passwd(find); press_any_one(); break;
			case 2: return;
		}
	}
}

/****************************************************
*	实现功能：学生登录界面显示						*
*	输入参数：登录参数								*
*	返回值  ：无									*
****************************************************/
void show_stu_login_menu(int num)
{
	system("clear");
	printf(
		"\n\t     -----------------------------------------\n"
		"\n\t%s  查看个人信息 "
		"\n\t                 "
		"\n\t%s  修改密码     "
		"\n\t     ------------"
		"\n\t                 "
		"\n\t%s  返回上一层   "
		"\n\t     ------------"
		"\n\t                 "
		"\n\n\t     提示：<w> -> 上   <s> -> 下   <j> -> 选择"
		"\n\t     -----------------------------------------\n"
		, num == 0 ? MARK_SELECT : MARK_NO_SELECT
		, num == 1 ? MARK_SELECT : MARK_NO_SELECT
		, num == 2 ? MARK_SELECT : MARK_NO_SELECT
		);
	
}

/****************************************************
*	实现功能：学生个人信息输出显示					*
*	输入参数：学生节点数据							*
*	返回值  ：无									*
****************************************************/
void show_stu_message(STU_PNODE stu_head)
{
	system("clear");
	printf(
		"\n\t学生个人信息：\n"
		"\n\t 学号   姓名                   性别     年龄   班级     数学成绩       语文成绩        C语言成绩         总分\n"
		"\n\t%6d\t%-22s\t%2c\t%3d\t%2d\t%6.2f\t\t%6.2f\t\t%6.2f\t\t%6.2f\n"
		,stu_head->stu_data.id
		,stu_head->stu_data.name
		,stu_head->stu_data.sex
		,stu_head->stu_data.age
		,stu_head->stu_data.class_num
		,stu_head->stu_data.math_score
		,stu_head->stu_data.chinese_score
		,stu_head->stu_data.c_program_score
		,stu_head->stu_data.total_score
		);
}

/****************************************************
*	实现功能：更改学生密码							*
*	输入参数：学生节点数据							*
*	返回值  ：无									*
****************************************************/
void change_stu_passwd(STU_PNODE stu_head)
{
	system("clear");
	
	char new_passwd[PASSWD_MAX];
	
	strcpy(new_passwd, getpass("请输入原密码："));

	if(0 != strcmp(new_passwd, stu_head->stu_data.passwd))
	{
		system("clear");
		printf("\n原密码输入错误．不能更改密码．\n");
		return;
	}
	
	strcpy(new_passwd, getpass("请输入新密码（不大于16位）："));

	char new_passwd1[PASSWD_MAX];
	strcpy(new_passwd1, getpass("请再输入一次新密码："));

	if(strcmp(new_passwd, new_passwd1) == 0)
	{
		system("clear");
		
		printf("\n是否保存新密码(y/n)：");
		char yes_or_no = tolower(getchar());	
		while(getchar() != '\n');
		
		if(yes_or_no != 'y' && yes_or_no != 'n')
		{
			system("clear");
			printf("\n输入错误，密码更改失败．\n");
			return;
		}
		
		if(yes_or_no == 'y')
		{
			system("clear");
			strcpy(stu_head->stu_data.passwd, new_passwd);
			printf("\n密码更改并保存成功．\n");
		}
		if(yes_or_no == 'n')
		{
			system("clear");
			printf("\n已放弃密码更改．\n");
			return;
		}
	}
	else
	{
		system("clear");
		printf("\n两次输入不一致，密码更改失败．\n");
		return;
	}
}

/****************************************************
*	实现功能：学生登录								*
*	输入参数：学生节点								*
*	返回值  ：学生节点判断							*
****************************************************/
STU_PNODE login_student(STU_PNODE stu_head)
{
	system("clear");
	int stu_id;
	printf("\n请输入学生id:");
	scanf("%d", &stu_id);
	while(getchar() != '\n');
	
	STU_PNODE find = find_stu_pre_node(stu_head, stu_id);
	if(NULL == find)
	{
		system("clear");
		printf("\n该学生id不存在，请重新输入或联系管理员．\n");
		press_any_one();
		return NULL;
	}//登录失败

	char stu_passwd[PASSWD_MAX];

	strcpy(stu_passwd, getpass("请输入密码："));

	int i = 2;
	while(0 != strcmp(stu_passwd, find->next->stu_data.passwd) && i != 0)
	{
		system("clear");
		printf("\n密码输入不对，你还有%d次机会重新输入：", i);
		strcpy(stu_passwd, getpass(""));
		i--;
	}
	if((0 == i) && strcmp(stu_passwd, find->next->stu_data.passwd) != 0)
	{
		system("clear");
		printf("\n三次密码输入错误．登录不成功．\n");
		press_any_one();
		return NULL;
	}
	return find->next;
}

