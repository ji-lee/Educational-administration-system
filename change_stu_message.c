#include"change_stu_message.h"

/****************************************************
*	实现功能：更改学生信息登录选项					*
*	输入参数：学生链表								*
*	返回值  ：	无									*
****************************************************/
void change_stu_message(STU_PNODE stu_head)
{
	if(NULL == stu_head->next)
	{
		system("clear");
		printf("\n学生信息为空，没有数据可以更改．\n");
		press_any_one();
		return;
	}

	while(ONE)
	{
		switch(get_change_stu_command(SHOW_CHANGE_STU_MENU))
		{
			case 0:change_stu_id(stu_head);        press_any_one(); break;
			case 1:change_stu_name(stu_head);      press_any_one(); break;
			case 2:change_stu_sex(stu_head);       press_any_one(); break;
			case 3:change_stu_age(stu_head);       press_any_one(); break;
			case 4:change_stu_class_num(stu_head); press_any_one(); break;
			case 5:change_score(stu_head);         press_any_one(); break;
			case 6:init_stu_passwd(stu_head);      press_any_one(); break;
			case 7:return;
		}
	}
}

/****************************************************
*	实现功能：更改学生id							*
*	输入参数：学生链表								*
*	返回值  ：	无									*
****************************************************/
void change_stu_id(STU_PNODE stu_head)
{
	system("clear");
	output_stu_node(stu_head);
	
	printf("\n请输入要更改的学生id:");
	int stu_id;
	scanf("%d",&stu_id);
	while(getchar() != '\n');

	STU_PNODE find = find_stu_pre_node(stu_head, stu_id);
	if(NULL == find)
	{
		system("clear");
		printf("\n该学生id不存在．\n");
		return;
	}
	
	int new_id = 0;
	printf("请输入新的学生id(6位数字):");
	scanf("%d", &new_id);
	while(getchar() != '\n');

	if(new_id < 100000 || new_id > 999999)
	{
		system("clear");
		printf("\n输入错误，更改学生id失败．\n");
		return;
	}
	
	if(find->next->stu_data.id == new_id)
	{
		system("clear");
		printf("\n您输入的新id与之前的id一样，无需更改．\n");
		return;
	}
	
	STU_PNODE find_1 = find_stu_pre_node(stu_head, new_id);
	if(find_1 != NULL)
	{
		system("clear");
		printf("\nid已存在．更改学生id失败．\n");
		return;
	}
	
	find->next->stu_data.id = new_id;
	system("clear");
	printf("\n学生id更改完成．\n");
}

/****************************************************
*	实现功能：更改学生姓名							*
*	输入参数：学生链表								*
*	返回值  ：	无									*
****************************************************/
void change_stu_name(STU_PNODE stu_head)
{
	system("clear");

	output_stu_node(stu_head);
	
	printf("\n请输入要更改的学生id:");
	int stu_id;
	scanf("%d",&stu_id);
	while(getchar() != '\n');
	
	STU_PNODE find = find_stu_pre_node(stu_head, stu_id);
	if(NULL == find)
	{
		system("clear");
		printf("\n该学生id不存在．\n");
		return;
	}
	
	char str[NAME_MAX];
	printf("请输入新的学生name(不多于20个字符):");
	mygets(str, NAME_MAX);
	strcpy(find->next->stu_data.name, str);
	system("clear");
	printf("\n学生name更改完成．\n");
}

/****************************************************
*	实现功能：更改学生性别							*
*	输入参数：学生链表								*
*	返回值  ：	无								*
****************************************************/
void change_stu_sex(STU_PNODE stu_head)
{
	system("clear");

	output_stu_node(stu_head);
	
	printf("\n请输入要更改的学生id:");
	int stu_id;
	scanf("%d",&stu_id);
	while(getchar() != '\n');

	STU_PNODE find = find_stu_pre_node(stu_head, stu_id);
	if(NULL == find)
	{
		system("clear");
		printf("\n该学生id不存在．\n");
		return;
	}
	
	char yes_or_no;
	if(find->next->stu_data.sex == 'M')
	{
		system("clear");
		printf("\n该学生是男生，您确定要改变他的性别，让他成为女生吗？（ｙ/ｎ）:");
		yes_or_no = tolower(getchar());
		while(getchar() != '\n');

		if(yes_or_no != 'y' && yes_or_no != 'n')
		{
			printf("输入错误．学生性别更改失败．\n");
			return;
		}
		
		if(yes_or_no == 'y')
		{
			find->next->stu_data.sex = 'F';
			system("clear");
			printf("\n操作成功，%s同学现在是女生了．^_^\n", find->next->stu_data.name);
			return;
		}
		else
		{
			system("clear");
			printf("\n您放弃了对%s同学的性别更改．\n", find->next->stu_data.name);
			return;
		}
	}
	else
	{
		system("clear");
		printf("\n该学生是女生，您确定要改变她的性别，让她成为男生吗？(y/n)");
		
		yes_or_no = tolower(getchar());
		while(getchar() != '\n');
		
		if(yes_or_no != 'y' && yes_or_no != 'n')
		{
			printf("输入错误．学生性别更改失败．\n");
			return;
		}
		
		if(yes_or_no == 'y')
		{
			find->next->stu_data.sex = 'F';
			system("clear");
			printf("\n操作成功，%s同学现在是男生了．^_^\n", find->next->stu_data.name);
			return;
		}
		else
		{
			system("clear");
			printf("\n您放弃了对%s同学的性别更改．\n", find->next->stu_data.name);
			return;
		}
	}
}

/****************************************************
*	实现功能：更改学生年龄							*
*	输入参数：学生链表								*
*	返回值  ：无									*
****************************************************/
void change_stu_age(STU_PNODE stu_head)
{
	system("clear");

	output_stu_node(stu_head);
	
	printf("\n请输入要更改的学生id:");
	int stu_id;
	scanf("%d",&stu_id);
	while(getchar() != '\n');

	STU_PNODE find = find_stu_pre_node(stu_head, stu_id);
	if(NULL == find)
	{
		system("clear");
		printf("\n该学生id不存在．\n");
		return;
	}
	
	int new_age;
	printf("请输入新的学生年龄:");
	scanf("%d", &new_age);
	while(getchar() != '\n');
	
	if(new_age < 1 || new_age > 150)
	{
		system("clear");
		printf("\n年龄输入小于1岁或超过150岁．更改失败．\n");
		return;
	}
	
	find->next->stu_data.age = new_age;
	
	system("clear");
	printf("\n学生年龄更改完成．\n");
}

/****************************************************
*	实现功能：更改学生班级							*
*	输入参数：学生链表								*
*	返回值  ：	无									*
****************************************************/
void change_stu_class_num(STU_PNODE stu_head)
{
	system("clear");

	output_stu_node(stu_head);
	
	printf("\n请输入要更改的学生id:");
	int stu_id;
	scanf("%d",&stu_id);
	while(getchar() != '\n');
	
	STU_PNODE find = find_stu_pre_node(stu_head, stu_id);
	if(NULL == find)
	{
		system("clear");
		printf("\n该学生id不存在．\n");
		return;
	}
	
	int new_class;
	printf("请输入新的学生班级:");
	scanf("%d", &new_class);
	while(getchar() != '\n');
	
	find->next->stu_data.class_num = new_class;
	
	system("clear");
	printf("\n学生班级更改完成．\n");

}

/****************************************************
*	实现功能：更改学生成绩							*
*	输入参数：学生链表								*
*	返回值  ：	无									*
****************************************************/
void change_score(STU_PNODE stu_head)
{
	system("clear");

	output_stu_node(stu_head);
	
	printf("\n请输入要更改的学生id:");
	int stu_id;
	scanf("%d",&stu_id);
	while(getchar() != '\n');
	
	STU_PNODE find = find_stu_pre_node(stu_head, stu_id);
	if(NULL == find)
	{
		system("clear");
		printf("\n该学生id不存在．\n");
		return;
	}
	
	system("clear");
	printf(
		"\n\t----------------------\n"
		"\n\t请选择您要更改的科目：\n"
		"\n\t1)---math"
		"\n\t2)---chinese"
		"\n\t3)---C program"
		"\n\n\t请输入选择(1 or 2 or 3):"
		"\n\t----------------------\n"
		);
	int select = 0;
	scanf("%d", &select);
	while(getchar() != '\n');
	
	int new_score;
	switch(select)
	{
		case 1:
			system("clear");
			printf("\n请输入新的数学分数：");
			scanf("%d", &new_score);
			while(getchar() != '\n');
			
			if(new_score > 100 || new_score < 0)
			{
				system("clear");
				printf("\n数学成绩输入错误，添加学生信息失败．\n");
				return;
			}
			
			find->next->stu_data.math_score = new_score;
			
			system("clear");
			printf("\n数学成绩更改成功．\n");
			break;
		case 2:
			system("clear");
			printf("\n请输入新的语文分数：");
			scanf("%d", &new_score);
			while(getchar() != '\n');
			
			if(new_score > 100 || new_score < 0)
			{
				system("clear");
				printf("\n语文成绩输入错误，添加学生信息失败．\n");
				return;
			}
			
			find->next->stu_data.chinese_score = new_score;
			
			system("clear");
			printf("\n语文成绩更改成功．\n");
			break;
		case 3:
			system("clear");
			printf("\n请输入新的C语言分数：");
			scanf("%d", &new_score);
			while(getchar() != '\n');
			
			if(new_score > 100 || new_score < 0)
			{
				system("clear");
				printf("\nC语言成绩输入错误，添加学生信息失败．\n");
				return;
			}
			
			find->next->stu_data.c_program_score = new_score;
			
			system("clear");
			printf("\nC语言成绩更改成功．\n");
			break;
		default:
			system("clear");
			printf("\n输入有误.\n");
			return;
	}
}

/****************************************************
*	实现功能：初始化学生密码						*
*	输入参数：学生链表								*
*	返回值  ：	无									*
****************************************************/
void init_stu_passwd(STU_PNODE stu_head)
{
	system("clear");

	output_stu_node(stu_head);
	
	printf("\n请输入要初始化密码的学生id:");
	int stu_id;
	scanf("%d",&stu_id);
	while(getchar() != '\n');

	STU_PNODE find = find_stu_pre_node(stu_head, stu_id);
	if(NULL == find)
	{
		system("clear");
		printf("\n该学生id不存在．\n");
		return;
	}
	
	strcpy(find->next->stu_data.passwd, "123456");
	
	system("clear");
	printf("\n学生%s的密码初始化成功，密码为：123456\n", find->next->stu_data.name);
}

/****************************************************
*	实现功能：更改学生信息界面箭头移动控制			*
*	输入参数：选项个数								*
*	返回值  ：箭头指示位置							*
****************************************************/
int get_change_stu_command(int xuan_xiang_ge_shu)
{
	int num = 0;  
	while( 1 ) {
		
		show_change_stu_menu(num);
		int select = getch();	                 //获取按键
		if( select == 'w' && num > 0 )           //上
		{	
			num = (num-1) % xuan_xiang_ge_shu;
		} 
		else if( select == 's' )                 //下 
		{	
			num = (num+1) % xuan_xiang_ge_shu;
		}
		else if( select == 'j' )                 //选项 
		{	
			return num;
		}
	}
	return num;
}

/****************************************************
*	实现功能：更改学生信息界面显示					*
*	输入参数：箭头指示位置							*
*	返回值  ：	无									*
****************************************************/
void show_change_stu_menu(int num)
{
	system("clear");
	printf(
		"\n\t     ----------------------------------------\n"
		"\n\t%s  更改学生id"
		"\n\t%s  更改学生姓名"
		"\n\t%s  更改学生性别"
		"\n\t%s  更改学生年龄"
		"\n\t%s  更改学生班级"
		"\n\t%s  更改学生成绩"
		"\n\t%s  初始化学生密码"
		"\n\t     ------------"
		"\n\t                 "
		"\n\t%s  返回上一层"
		"\n\t     ------------"
		"\n\t                "
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
