#include <windows.h>
//0-0

//0-1.加载数据
void Load_data(Mov* pHead)
{
	int loading = 4;
	
	while (loading--)  //你猜猜这是在干啥 nvn
	{
		system("cls");
		for (int i = 0; i < loading; i++)
		{	
			printf("---加载中---");
			printf(" >>>>>>");Sleep(1000);
		}
		printf("\n");
		
	}
	int number = 0;//记录当前需要评分的电影总数
	Mov* pMove = pHead;
	FILE* fp = fopen("movie.txt", "r");

	if (fp == NULL)
	{
		printf("==	 ==               =                       = = = = = =        ==            = \n");
		printf("==	==              == ==                     =                  =  =          = \n");
		printf("=== ==             ==   ==                    =                  =    =        = \n");
		printf("====              ==     ==                   =                  =     =       = \n");
		printf("====             ==  ==   ==         S        = = = = = =        =      =      = \n");
		printf("==  ==          ==         ==                 =                  =       =     = \n");
		printf("==   ==        ==           ==                =                  =         =   = \n");
		printf("==    ==      ==             ==               = = = = = =        =           = = \n");

		                                //https://github.com/uonlraSnaey

		printf(" _______________________________\n");
		printf("|  当前暂时没有电影信息.         |\n");
		printf("|  按 enter 开始  ...           |\n");
		printf("|_______________________________|\n");
		getchar();
		return;
	}
	while (1)
	{
		Mov* newMovie = (Mov*)malloc(sizeof(Mov));
		if (fscanf(fp, "%s\t %s\t %d\t %d\t %d\t %d\t %d\t %d\n",
			newMovie->m_name, newMovie->m_number,
			& newMovie->m_year, &newMovie->m_music,
			& newMovie->m_visual, &newMovie->m_story,
			& newMovie->m_display, &newMovie->m_totalScore,
			& newMovie->m_totalScore) == EOF)
		{

			free(newMovie);
			break;
		}
		number++;
		Judge_score(newMovie);
		newMovie->next = NULL;
		pMove->next = newMovie;
		pMove = pMove->next;
	}

	printf(" _______________________________________\n");
	printf("|              -加载完成-                |\n");
	printf("|  当前系统已经录入 %3d  部电影信息      |\n", number);
	printf("|        按 enter 进入系统               |\n");
	printf("|________________________________________|\n");
	getchar();
}

//0-3 选择操作
void Select_fuction(Mov* pHead)
{
	int select = 0;
	while (1)
	{
		int N = 0;
		Home_page();

		while(scanf("%d",&select)==0 || select==0 || select>8)
		{
			getchar();
			printf("请输入正确的系统功能序号（1 - 8）:");
		}

		switch (select)
		{
		case 1://录入电影信息
			Input_new_movie(pHead);
			break;
		case 2://删除电影
			Search_movie_toChange(pHead);
			getchar();
			break;
		case 3: //查询某部电影信息
			Delete_movie(pHead);
			break;
		case 4://打印电影的所有信息
			Search_movie(pHead);
			getchar();
			break;
		case 5://查询电影排名
			Rank_kindSelect(pHead);
			getchar();
			break;
		case 6://显示系统所有信息
			Show_all_selection(pHead);
			getchar();
			break;
		case 7://保存
			Save_data(pHead);//！！！！！！！！！！！！！！！
			getchar();
			break;
		case 8://退出系统
			Save_data(pHead);//真保存了
			exit(0);
			break;
		default:
			break;
		}
	}
}
//1-1. 存入电影信息
void Input_new_movie(Mov* pHead)
{
	int N;
	printf("本次评分的电影总数:\n");
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++)
	{
		system("cls");

		Mov* newMovie = (Mov*)malloc(sizeof(Mov));
		memset(newMovie, 0, sizeof(Mov));
		newMovie->next = NULL;

		printf("电影名称:");
		scanf("%s", newMovie->m_name);
		printf("序号:");
		while(scanf("%s",&newMovie->m_number)==0 || strlen(newMovie->m_number)>10)
		{
			getchar();
			printf("ERROR，请重新输入!\n");
			printf("电影序号:");
		}
		printf("年份:");
		scanf("%d", &newMovie->m_year);
		printf("音乐得分:");
		while(scanf("%d",&newMovie->m_music)==0 || newMovie->m_music>100)
		{
			getchar();
			printf("ERROR，请重新输入!\n");
			printf("音乐得分:");
		}
		printf("视效得分:");
		while(scanf("%d",&newMovie->m_visual)==0 || newMovie->m_visual>100)
		{
			getchar();
			printf("ERROR，请重新输入!\n");
			printf("视效得分:");
		}
		printf("剧情得分:");
		while(scanf("%d",&newMovie->m_story)==0 || newMovie->m_story>100)
		{
			getchar();
			printf("ERROR，请重新输入!\n");
			printf("剧情得分:");
		}
		printf("演出得分:");
		while(scanf("%d",&newMovie->m_display)==0 || newMovie->m_display>100)
		{
			getchar();
			printf("ERROR，请重新输入!\n");
			printf("演出得分:");
		}
		newMovie->m_totalScore = newMovie->m_music + newMovie->m_visual + newMovie->m_story + newMovie->m_display;
		newMovie->m_rankScore = 0;
		Judge_score(newMovie);//判断口碑
		getchar();

		Tail_add_node(pHead, newMovie);
		printf("成功录入评分信息!\n");
		getchar();
	}
}
//1-2.判断口碑好坏
void Judge_score(Mov* movie)
{
	int cnt = 0;// 评分 < 60 的项目
	cnt = (movie->m_music < 60) + (movie->m_visual < 60)\
		+ (movie->m_story < 60) + (movie->m_display < 60);
	if (cnt >= 2)
		movie->m_qualifiedScore = false;
	else
		movie->m_qualifiedScore = true;
}
//1-3.结尾连接数据
void Tail_add_node(Mov* pHead, Mov* new1)
{
	Mov* pMove = pHead;
	while (pMove->next)
	{
		pMove = pMove->next;
	}
	pMove->next = new1;
}

//2-1.找到要修改数据的电影
void Search_movie_toChange(Mov* pHead)
{
	system("cls");

	int ifSelect=1;
	while(ifSelect)
	{
		system("cls");
		printf("选择修改电影信息的途径:\n");
		printf(" ______________\n");
		printf("|   1.名称     |\n");
		printf("|   2.序号     |\n");
		printf("|______________|\n");
		printf("|3.查看全部信息 |\n");
		printf("|   4.返回     |\n");
		printf("|______________|\n");

		Mov* pMove = pHead;
		int selectWay;//选择查找方式
		while(scanf("%d",&selectWay)==0 || selectWay==0 || selectWay>4)
		{
			getchar();
			printf("请输入正确的查找途径:");
		}

		switch (selectWay)
		{
		case 1://ͨ名字
			char name[20];
			printf("名称:");
			scanf("%s", name);
			while (pMove->next)
			{
				pMove = pMove->next;
				if (!strcmp(name, pMove->m_name))
				{
					Change_information_selection(pMove);
					return;
				}
			}
			break;
		case 2://ͨ序号
			char number[20];
			printf("序号:");
			scanf("%s", number);
			while (pMove->next)
			{
				pMove = pMove->next;
				if (!strcmp(number, pMove->m_number))
				{
					Change_information_selection(pMove);
					return;
				}
			}
			break;
		case 3://全部信息
			Show_all_movie(pHead);
			break;
		case 4:
			return ;
			break;
		default:
			break;
		}
		if(selectWay != 3)
		{
			getchar();
			printf("未找到该学生,修改操作无效\n");
			getchar();
		}
		printf("是否还要继续修改操作?[1-是  0-否]");
		scanf("%d",&ifSelect);
	}
}
//2-2.修改信息选项
void Change_information_selection(Mov* movie)
{
	system("cls");
	printf("修改电影%s的哪一项信息:\n", movie->m_name);
	printf(" __________\n");
	printf("|1.名称    |\n");
	printf("|2.序号    |\n");
	printf("|3.年份    |\n");
	printf("|4.成绩    |\n");
	printf("|__________|\n");
	printf("|5.返回    |\n");
	printf("|__________|\n");

	int select;
	while(scanf("%d",&select)==0 || select==0 || select>5)
	{
		getchar();
		printf("ERROR!,请输入正确的选择序号:");
	}
	switch (select)
	{
	case 1:
		printf("原名 %s,改为:", movie->m_name);
		char newName[20];
		scanf("%s", newName);
		strcpy(movie->m_name, newName);
		break;
	case 2:
		printf("原序号%s,改为:", movie->m_number);
		char newNumber[20];
		while(scanf("%s",newNumber)==0 || strlen(newNumber)>10)
		{
			getchar();
			printf("ERROR! ,请重新输入！!\n");
			printf("序号:");
		}
		strcpy(movie->m_number, newNumber);
		break;
	case 3:
		printf("原上映年份 %d,改为:", movie->m_year);
		scanf("%d", &movie->m_year);
		break;
	case 4:
		Change_score(movie);
		break;
	default:
		break;
	}
	if(select != 5)
	{
		printf("修改成功.\n");
		getchar();
	}
}
//2-3.修改成绩 
void Change_score(Mov* movie)
{
	system("cls");
	int ret;
	printf("%s", movie->m_name);
	printf("音乐得分:%d ,是否要修改?\n[0-否;1-是]", movie->m_music);
	scanf("%d", &ret);
	while (ret)
	{
		printf("改为:");
		scanf("%d", &movie->m_music);
		if(movie->m_music > 100)
		{
			ret=1;
			printf("评分数据异常,请重新输入!\n");
		}else{
			ret=0;
		}
	}
	printf("视效得分:%d ,是否要修改?\n[0-否;1-是]", movie->m_visual);
	scanf("%d", &ret);
	while (ret)
	{
		printf("改为:");
		scanf("%d", &movie->m_visual);
		if(movie->m_visual > 100)
		{
			ret=1;
			printf("评分数据异常,请重新输入!\n");
		}else{
			ret=0;
		}
	}
	printf("剧情得分:%d ,是否要修改?\n[0-否;1-是]", movie->m_story);
	scanf("%d", &ret);
	while (ret)
	{
		printf("改为:");
		scanf("%d", &movie->m_story);
		if(movie->m_story > 100)
		{
			ret=1;
			printf("评分数据异常,请重新输入!\n");
		}else{
			ret=0;
		}
	}
	printf("演出得分:%d ,是否要修改?\n[0-否;1-是]", movie->m_display);
	scanf("%d", &ret);
	while (ret)
	{
		printf("改为:");
		scanf("%d", &movie->m_display);
		if(movie->m_display > 100)
		{
			ret=1;
			printf("评分数据异常,请重新输入!\n");
		}else{
			ret=0;
		}
	}
	movie->m_totalScore = movie->m_music + movie->m_visual + movie->m_story + movie->m_display;
	Judge_score(movie);
	return;
}

//3.删除电影 
void Delete_movie(Mov* pHead)
{
	Mov* prev = NULL;//等待遍历的时候,保留指针pMove的前一位

	Mov* pMove = pHead;
	system("cls");

	printf("通过什么途径删除电影:\n");
	printf(" ______________\n");
	printf("|   1.名称     |\n");
	printf("|   2.序号     |\n");
	printf("|______________|\n");
	printf("|3.查看全部资料 |\n");
	printf("|   4.返回     |\n");
	printf("|______________|\n");

	int searchWay;//选择排序方法
	while(scanf("%d",&searchWay)==0 || searchWay==0 || searchWay>4)
	{
		getchar();
		printf("请输入正确的查找途径:");
	}

	switch (searchWay)
	{
	case 1:
		char name[20];
		printf("名称:");
		scanf("%s", name);
		while (pMove->next)
		{
			prev = pMove;
			pMove = pMove->next;
			if (!strcmp(name, pMove->m_name))
			{
				prev->next = pMove->next;
				printf("成功删除电影!");
				getchar();
				return;
			}
		}
		break;
	case 2:
		char number[20];
		printf("序号:");
		scanf("%s", number);
		while (pMove->next)
		{
			pMove = pMove->next;
			if (!strcmp(number, pMove->m_number))
			{
				prev->next = pMove->next;
				printf("成功删除电影!");
				getchar();
				return;
			}
		}
		break;
	case 3:
		Show_all_movie(pHead);
		getchar();
		Delete_movie(pHead);
		break;
	default:
		break;
	}
	if(searchWay==1 || searchWay==2)
	{
		getchar();
		printf(" __________________________________\n");
		printf("|  ERROR,未收录该电影信息，删除失败  |\n");
		printf("|__________________________________|\n");
		getchar();
	}
}
//7. 保存
void Save_data(Mov* pHead)
{
	FILE* fp;
	Mov* pMove = pHead;
	if ((fp = fopen("movie.txt", "w")) == NULL)
	{
		printf("存档失败");
	}
	else
	{
		while (pMove->next)
		{
			pMove = pMove->next;
			fprintf(fp, "%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\n", pMove->m_name, \
				pMove->m_number, pMove->m_year, pMove->m_music, \
				pMove->m_visual, pMove->m_story, pMove->m_display, \
				pMove->m_totalScore);
		}
	}

	printf("存档成功!nwn");
	getchar();
	fclose(fp);
}
