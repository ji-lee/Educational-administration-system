#include"teacher.h"
#include"student.h"  //for show_stu_message();

/****************************************************
*	实现功能：教师登录选择							*
*	输入参数：学生链表，教师链表					*
*	返回值  ：无									*
****************************************************/
void teacher(STU_PNODE stu_head, TEA_PLINK tea_head)
{
	
	TEA_PLINK find = login_teacher(tea_head);
	if(NULL == find)
	{
		return;
	}
	while(ONE)
	{
		switch(get_command(SHOW_TEA_LOGIN_MENU))
		{
			case 0:show_tea_message(find);             press_any_one(); break;
			case 1:change_tea_passwd(find);            press_any_one(); break;
			case 2:add_stu_message(find, stu_head);    press_any_one(); break;
			case 3:find_stu_message(stu_head);         press_any_one(); break;
			case 4:delete_student(find, stu_head);     press_any_one(); break;
			case 5:change_stu_score(find, stu_head);   press_any_one(); break;
			case 6:show_all_stu_message(stu_head);     break;
			case 7:return;
		}
	}
}

/****************************************************
*	实现功能：教师界面显示菜单						*
*	输入参数：登录参数								*
*	返回值  ：无									*
****************************************************/
void show_tea_login_menu(int num)
{
	system("clear");
	printf(
		"\n\t    -----------------------------------------\n"
		"\n\t     个人信息管理"
		"\n\t     ------------"
		"\n\t%s  查看个人信息 "
		"\n\t%s　修改个人密码 "
		"\n\t     ------------"
		"\n\t                 "
		"\n\t     学生管理    "
		"\n\t     ------------"
		"\n\t%s　增加学生信息 "
		"\n\t%s　查找学生信息 "
		"\n\t%s　删除学生信息 "
		"\n\t%s　修改学生成绩 "
		"\n\t%s　查看学生信息 "
		"\n\t     ------------"
		"\n\t                 "
		"\n\t%s  返回上一层   "
		"\n\t     ------------"
		"\n\t                 "
		"\n\n\t    提示：<w> -> 上   <s> -> 下   <j> -> 选择"
		"\n\t    -----------------------------------------\n"
		, num == 0 ? MARK_SELECT : MARK_NO_SELECT
		, num == 1 ? MARK_SELECT : MARK_NO_SELECT
		, num == 2 ? MARK_SELECT : MARK_NO_SELECT
		, num == 3 ? MARK_SELECT : MARK_NO_SELECT
		, num == 4 ? MARK_SELECT : MARK_NO_SELECT
		, num == 5 ? MARK_SELECT : MARK_NO_SELECT
		, num == 6 ? MARK_SELECT : MARK_NO_SELECT
		, num == 7 ? MARK_SELECT : MARK_NO_SELECT
		);
}

/****************************************************
*	实现功能：教师个人输出显示						*
*	输入参数：教师节点数据							*
*	返回值  ：无									*
****************************************************/
void show_tea_message(TEA_PLINK tea_head)
{
	system("clear");
	printf(
		"\n\t教师个人信息：\n"
		"\n\t工号    姓名                 性别       年龄              学科                辅导员\n"
		"\n\t%4d\t%-22s%-c\t\t%3d\t\t%-9s\t\t%-4s\n"
		,tea_head->tea_data.id
		,tea_head->tea_data.name
		,tea_head->tea_data.sex
		,tea_head->tea_data.age
		,tea_head->tea_data.subject
		,tea_head->tea_data.head_teacher
		);
}

/****************************************************
*	实现功能：更改教师密码							*
*	输入参数：教师节点								*
*	返回值  ：无									*
****************************************************/
void change_tea_passwd(TEA_PLINK tea_head)
{
	system("clear");

	char new_passwd[PASSWD_MAX];

	strcpy(new_passwd, getpass("请输入原密码："));

	if(0 != strcmp(new_passwd, tea_head->tea_data.passwd))
	{
		system("clear");
		printf("\n原密码输入错误，不能更改密码．\n");
		return;
	}

	strcpy(new_passwd, getpass("请输入新密码（不大于16位）："));

	char new_passwd1[PASSWD_MAX];
	strcpy(new_passwd1, getpass("请再输入一次新密码："));

	if(strcmp(new_passwd, new_passwd1) == 0)
	{
		system("clear");
		printf("\n是否保存新密码(y/n)：");
		char yes_or_no = getchar();
		while(getchar() != '\n');

		if(yes_or_no != 'y' && yes_or_no != 'n')
		{
			system("clear");
			printf("\n输入错误．密码更改失败．\n");
			return;
		}
		if(yes_or_no == 'y')
		{
			system("clear");
			strcpy(tea_head->tea_data.passwd, new_passwd);
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
		printf("\n两次输入不一致，密码更改不成功．\n");
		return;
	}
}

/****************************************************
*	实现功能：添加学生信息							*
*	输入参数：教师节点和学生节点					*
*	返回值  ：无									*
****************************************************/
void add_stu_message(TEA_PLINK tea_head, STU_PNODE stu_head)
{
	system("clear");
	
	if(strcmp(tea_head->tea_data.head_teacher, "no") == 0)  //这里不能写成if(strcmp(...,"yes") != 0) 思考一下为什么
	{
		printf("\n抱歉，您的权限不够，不能添加学生．\n");
		return;
	}

	STU stu_data;

	printf("\n请输入学生id(6位数字)：");
	scanf("%d", &stu_data.id);
	while(getchar() != '\n');
	
	if(stu_data.id < 100000 || stu_data.id > 999999)
	{
		system("clear");
		printf("\n学生id输入错误，添加学生信息失败．\n");
		return;
	}
	
	STU_PNODE find = find_stu_pre_node(stu_head, stu_data.id);
	if(find != NULL)
	{
		system("clear");
		printf("id已存在．添加学生信息失败．\n");
		return;
	}
	
	printf("请输入添加的学生姓名(不大于20个字符)：");
	char new_name[NAME_MAX];
	mygets(new_name, NAME_MAX);
	strcpy(stu_data.name, new_name);
	
	printf("请输入添加的学生性别('m'或'f')：");
	stu_data.sex = toupper(getchar());
	if(stu_data.sex != 'M' && stu_data.sex != 'F')
	{
		system("clear");
		printf("\n性别输入错误，添加学生信息失败．\n");
		return;
	}

	printf("请输入添加的学生年龄(1-150)：");
	scanf("%d", &stu_data.age);
	while(getchar() != '\n');
	if(stu_data.age > 150 || stu_data.age < 1)
	{
		system("clear");
		printf("\n年龄输入小于1岁或超过150岁，添加学生信息失败．\n");
		return;
	}
	
	printf("请输入该学生所在班级(1-20)：");
	scanf("%d", &stu_data.class_num);
	while(getchar() != '\n');
	if(stu_data.class_num > 20 || stu_data.class_num < 1)
	{
		system("clear");
		printf("\n班级输入错误，添加学生信息失败．\n");
		return;
	}
	
	printf("请输入该学生的三门成绩：\n");
	printf("数学成绩(0-100)：");
	scanf("%f", &stu_data.math_score);
	while(getchar() != '\n');
	if(stu_data.math_score > 100 || stu_data.math_score < 0)
	{
		system("clear");
		printf("\n数学成绩输入错误，添加学生信息失败．\n");
		return;
	}
	
	printf("语文成绩(0-100)：");
	scanf("%f", &stu_data.chinese_score);
	while(getchar() != '\n');
	if(stu_data.chinese_score > 100 || stu_data.chinese_score < 0)
	{
		system("clear");
		printf("\n语文成绩输入错误，添加学生信息失败．\n");
		return;
	}
	
	printf("C语言成绩(0-100)：");
	scanf("%f", &stu_data.c_program_score);
	while(getchar() != '\n');
	if(stu_data.c_program_score > 100 || stu_data.c_program_score < 0)
	{
		system("clear");
		printf("\nC语言成绩输入错误，添加学生信息失败．\n");
		return;
	}
//计算三科成绩总分
	stu_data.total_score = stu_data.math_score + 
							stu_data.chinese_score + 
							stu_data.c_program_score;

//密码初始化：
	strcpy(stu_data.passwd, "123456");
	
	head_insert_stu_node(stu_head, stu_data);
	
	system("clear");
	printf("\n学生信息增加完成！新添加学生密码初始化为123456.\n");

}

/****************************************************
*	实现功能：查找学生信息							*
*	输入参数：学生节点								*
*	返回值  ：无									*
****************************************************/
void find_stu_message(STU_PNODE stu_head)
{
	system("clear");


	if(stu_head->next == NULL)
	{
		printf("\n学生信息为空．\n");
		return;
	}
	
	int find_id;
	printf("\n请输入要查找的学生id:");
	scanf("%d",&find_id);
	while(getchar() != '\n');

	if(find_id < 100000 || find_id > 999999)
	{
		system("clear");
		printf("\n学生id输入错误，查找学生信息失败．\n");
		return;
	}
	
	STU_PNODE find = find_stu_pre_node(stu_head, find_id);
	if(NULL == find)
	{
		system("clear");
		printf("\n该学生id不存在．\n");
		return;
	}
	show_stu_message(find->next); // 声明在student.h，所以头文件要包含	
}

/****************************************************
*	实现功能：删除学生信息							*
*	输入参数：教师节点和学生节点					*
*	返回值  ：无									*
****************************************************/
void delete_student(TEA_PLINK tea_head, STU_PNODE stu_head)
{
	system("clear");
	
	//判断是不是辅导员	
	if(strcmp(tea_head->tea_data.head_teacher, "no") == 0)  //这里不能写成if(strcmp(...,"yes") != 0) 思考一下为什么
	{
		printf("\n抱歉，您的权限不够，不能删除学生．\n");
		return;
	}

	if(stu_head->next == NULL)
	{
		printf("\n学生信息为空，没有数据删除^_^．\n");
		return;
	}
	
	output_stu_node(stu_head);
	
	int find_id;
	printf("\n请输入要删除的学生id:");
	scanf("%d",&find_id);
	while(getchar() != '\n');

	STU_PNODE find = find_stu_pre_node(stu_head, find_id);
	if(NULL == find)
	{
		system("clear");
		printf("\n该学生id不存在．\n");
		return;
	}
	delete_stu_node(find); // 删除find的下一个节点
	system("clear");
	printf("删除学生数据成功．\n");	
}

/****************************************************
*	实现功能：更改学生成绩							*
*	输入参数：教师节点和学生节点					*
*	返回值  ：无									*
****************************************************/
void change_stu_score(TEA_PLINK tea_head, STU_PNODE stu_head)
{
	system("clear");
	
	if(stu_head->next == NULL)
	{
		printf("\n学生信息为空，没有数据可以更改．\n");
		return;
	}
	
	output_stu_node(stu_head);

	printf("\n请输入要更改的学生id:");
	int stu_id;
	scanf("%d",&stu_id);
	while(getchar() != '\n');

	STU_PNODE find = find_stu_pre_node(stu_head, stu_id);
	if(NULL == find)
	{
		system("clear");
		printf("该学生id不存在，成绩更改失败．\n");
		return;
	}
	
	char change_subject[SUBJECT_MAX];

	printf("请输入您要更改的科目(\"math\" or \"chinese\" or \"c_program\")：");
	mygets(change_subject, SUBJECT_MAX);
	
	if((strcmp(change_subject, "math") != 0) 
			&& (strcmp(change_subject, "chinese") != 0) 
			&& (strcmp(change_subject, "c_program") != 0))
	{
		system("clear");
		printf("\n科目名称输入错误，成绩更改失败．\n");
		return;
	}

	if(0 != strcmp(tea_head->tea_data.subject, change_subject) 
		&& strcmp(tea_head->tea_data.head_teacher, "no") == 0)
	{
		system("clear");
		printf("\n抱歉，您没有权限更改%s科目成绩.\n",change_subject);
		return;
	}

	int new_score;
	
	if(strcmp(change_subject, "math") == 0)
	{
		printf("请输入新的分数：");
		scanf("%d", &new_score);
		while(getchar() != '\n')
		
		if(new_score < 0 || new_score > 100)
		{
			system("clear");
			printf("\n新的分数输入错误，成绩更改失败．\n");
			return;
		}
		
		find->next->stu_data.math_score = new_score;
		find->next->stu_data.total_score = 
				find->next->stu_data.chinese_score + 
				find->next->stu_data.c_program_score + new_score;
	}
	
	if(strcmp(change_subject, "chinese") == 0)
	{
		printf("请输入新的分数(1-100)：");
		scanf("%d", &new_score);
		while(getchar() != '\n')
		
		if(new_score < 0 || new_score > 100)
		{
			system("clear");
			printf("\n新的分数输入错误，成绩更改失败．\n");
			return;
		}
		
		find->next->stu_data.chinese_score = new_score;
		find->next->stu_data.total_score = 
				find->next->stu_data.math_score + 
				find->next->stu_data.c_program_score + new_score;
	}

	if(strcmp(change_subject, "c_program") == 0)
	{
		printf("请输入新的分数：");
		scanf("%d", &new_score);
		while(getchar() != '\n')
		
		if(new_score < 0 || new_score > 100)
		{
			system("clear");
			printf("\n新的分数输入错误，成绩更改失败．\n");
			return;
		}
		
		find->next->stu_data.c_program_score = new_score;
		find->next->stu_data.total_score = 
				find->next->stu_data.math_score + 
				find->next->stu_data.chinese_score + new_score;
	}
	
	system("clear");
	printf("\n学生%s的%s科目成绩更改成功.\n"
			,find->next->stu_data.name 
			,change_subject);
}

/****************************************************
*	实现功能：教师登录								*
*	输入参数：教师节点								*
*	返回值  ：教师节点或NULL						*
****************************************************/
TEA_PLINK login_teacher(TEA_PLINK tea_head)
{
	system("clear");

	int tea_id;
	printf("\n请输入老师id:");
	scanf("%d", &tea_id);
	while(getchar() != '\n');

	TEA_PLINK find = find_tea_pre_node(tea_head, tea_id);
	if(NULL == find)
	{
		system("clear");
		printf("\n该老师id不存在，请重新输入或联系管理员．\n");
		press_any_one();	
		return NULL;
	}//登录失败

	char tea_passwd[PASSWD_MAX];

	strcpy(tea_passwd, getpass("请输入密码："));

	int i = 2;
	while(0 != strcmp(tea_passwd, find->next->tea_data.passwd) && i != 0)
	{
		system("clear");
		printf("\n密码输入不对，你还有%d次机会重新输入：", i);
		strcpy(tea_passwd, getpass(""));
		i--;
	}
	if(0 == i)
	{
		system("clear");
		printf("\n三次密码输入错误，登录不成功．\n");
		press_any_one();	
		return NULL;
	}
	return find->next;
}
