#include"fun.h"

/****************************************************
*	函数介绍：缓冲函数								*
*	实现功能：按下任意键继续						*
*	输入参数：无									*	
*	返回值  ：无									*
****************************************************/
void press_any_one()
{
	printf("\n\n回车继续");
	getchar();
}

/****************************************************
*	实现功能：从屏幕中获取至多len-1字符串保存到str	*
*	输入参数：str --- 字符串首地址					*
*			  len --- 字符串大小					*
*	返回值  ：无									*	
****************************************************/
void mygets(char * str, int len)
{
	int i = 0;
	for(i = 0; i<len-1; i++ ) 
	{
		str[i] = getchar();
		if( str[i] == '\n' )
		{
			break;
		}
	}
	if( str[i] != '\n' )              //不是break就有多余字符
	{
		while( getchar() != '\n' );   //吸收缓存
	}
	str[i] = '\0';	                  //把字符数组，转换成字符串
}

/****************************************************
*	实现功能：实现单个字符缓冲输入输出				*
*	输入参数：无									*
*	返回值  ：返回按键信息							*
****************************************************/
int getch()
{
	CHAR_MODE_START
	char ch = getchar();
	putchar('\b');
	CHAR_MODE_STOP
	return ch;
}

/****************************************************
*	实现功能：界面显示箭头移动控制					*
*	输入参数：选项个数								*
*	返回值  ：箭头指示位置							*
****************************************************/
int get_command(int number_of_menu)
{
	int num = 0; 
	while( 1 ) {
		switch(number_of_menu)
		{
			case SHOW_AD_LOGIN_MENU:        show_ad_login_menu(num);        break;
			case SHOW_LOGIN_MENU:           show_login_menu(num);           break;
			case SHOW_STU_LOGIN_MENU:	    show_stu_login_menu( num );     break;	
			case SHOW_TEA_LOGIN_MENU:       show_tea_login_menu(num);       break;
			case SHOW_CHANGE_TEA_MENU:      show_change_tea_menu(num);      break;
			case SHOW_ALL_STU_MESSAGE_MENU: show_all_stu_message_menu(num); break;
		}
		int select = getch();	                 //获取按键
		if( select == 'w' && num > 0 )           //上
		{	
			num = (num-1) % number_of_menu;
		} 
		else if( select == 's' )                 //下 
		{	
			num = (num+1) % number_of_menu;
		}
		else if( select == 'j' )                 //选项 
		{	
			return num;
		}
	}
	return num;
}
