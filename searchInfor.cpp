//4-1.查询电影信息
void Search_movie(Mov* pHead)
{
	system("cls");
	int ret = 1;// 判断电影存在与否    
	Mov* pMove = pHead;

	printf("通过什么途径查找电影:\n");
	printf(" ______________\n");
	printf("|   1.名称     |\n");
	printf("|   2.序号     |\n");
	printf("|______________|\n");
	printf("|   3.返回     |\n");
	printf("|______________|\n");

	int searchWay;
	while(scanf("%d",&searchWay)==0 || searchWay==0 || searchWay>3)
	{
		getchar();
		printf("请输入正确途径:");
	}

	switch (searchWay)
	{
	case 1:
		char name[20];
		printf("名称:");
		scanf("%s", name);
		while (pMove->next)
		{
			pMove = pMove->next;
			if (!strcmp(name, pMove->m_name))
			{
				Show_movieInformation(pMove);
				return ;
			}
		}
		printf(" _____________________\n");
		printf("|  ERROR,未收录该电影  |\n");
		printf("|_____________________|\n");
		getchar();
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
				Show_movieInformation(pMove);
				return ;
			}
		}
		printf(" _____________________\n");
		printf("|  ERROR,未收录该电影  |\n");
		printf("|_____________________|\n");
		getchar();
		break;
	default:
		break;
	}
}
//4-2. 打印电影相关信息
void Show_movieInformation(Mov* movie)
{
	system("cls");

	printf(" _____________________\n");
	printf("|  名称·:%-12s         |\n", movie->m_name);
	printf("|  序号:%-12s          |\n", movie->m_number);
	printf("|  上映年份:%-12d      |\n", movie->m_year);
	printf("|  音乐得分:%-12d      |\n", movie->m_music);
	printf("|  视效得分:%-12d      |\n", movie->m_visual);
	printf("|  剧情得分:%-12d      |\n", movie->m_story);
	printf("|  演出得分:%-12d      |\n", movie->m_display);
	printf("|  总分:%-12d          |\n", movie->m_totalScore);
	printf("|______________________|\n");
	getchar();
}

//5-1. 选择排序方法
void Rank_kindSelect(Mov* pHead)
{
	system("cls");
	int ifSelect = 1;//是否继续   

	printf("按照某个年份或者全部年份排名:\n");
	printf(" ______________\n");
	printf("|   1.年份     |\n");
	printf("|   2.全部时期  |\n");
	printf("|______________|\n");
	printf("|   3.返回     |\n");
	printf("|______________|\n");

	int kindSelect = 0;
	while(scanf("%d",&kindSelect)==0 || kindSelect==0 || kindSelect>3)
	{
		getchar();
		printf("ERROR,输入正确的选择:");
	}
	Mov* p_classHead = NULL;
	while (ifSelect)
	{
		switch (kindSelect)
		{
		case 1:// ༶按年份排序   
			system("cls");
			int rankYear;
			printf("请输入想查看排名的年份:");
			scanf("%d", &rankYear);

			p_classHead = Build_rankYear(pHead, rankYear);
			if (NULL == p_classHead)
			{
				printf("  ___________________________________\n");
				printf(" |  系统内暂未录入该年份电影的信息.     |\n");
				printf(" |___________________________________|\n");
				getchar();
				break;
			}
			Rank_subjectSelect(p_classHead);
			getchar();
			break;
		case 2://全院线排名    
			system("cls");
			Rank_subjectSelect(pHead);
			getchar();
			break;
		default:
			ifSelect = 0;
			break;
		}
		if(kindSelect != 3)
		{
			printf("是否还要继续查看排名?[1-是 0-否]");
			scanf("%d", &ifSelect);
		}
	}
}
//5-2.创建需要排序的年份 （一年很可能包括多部电影）
Mov* Build_rankYear(Mov* pHead, int rankYear)
{
	Mov* pMoveGrade = pHead;//主链表的头指针

	Mov* classHead = (Mov*)malloc(sizeof(Mov));// 年份的首个节点
	memset(classHead, 0, sizeof(Mov));
	classHead->next = NULL;
	Mov* pMoveYear = classHead;// 关于年份的头指针

	int classmateNumber = 0;// 总电影数    
	while (pMoveGrade->next)
	{
		pMoveGrade = pMoveGrade->next;
		if (pMoveGrade->m_year == rankYear)//将该年份的电影信息复制到需要进行排名的链表中              
		{
			classmateNumber++;
			Mov* newMovie = (Mov*)malloc(sizeof(Mov));
			memset(newMovie, 0, sizeof(Mov));
			newMovie->next = NULL;

			strcpy(newMovie->m_name, pMoveGrade->m_name);
			strcpy(newMovie->m_number, pMoveGrade->m_number);
			newMovie->m_year = pMoveGrade->m_year;
			newMovie->m_qualifiedScore = pMoveGrade->m_qualifiedScore;
			newMovie->m_music = pMoveGrade->m_music;
			newMovie->m_visual = pMoveGrade->m_visual;
			newMovie->m_story = pMoveGrade->m_story;
			newMovie->m_display = pMoveGrade->m_display;
			newMovie->m_totalScore = pMoveGrade->m_totalScore;

			pMoveYear->next = newMovie;
			pMoveYear = pMoveYear->next;
		}
	}

	if (classmateNumber)
	{
		return classHead;
	}
	else {
		return NULL;
	}
}
//5-3. 按评分项目排名 
void Rank_subjectSelect(Mov* pHead)
{
	Mov* pMove = pHead;
	system("cls");

	if (NULL == pHead->next )
	{
		printf("无该排名的相关数据录入,排名失败。");
		getchar();
		return;
	}
	printf("按照某一项评分排序:\n");
	printf("1.音乐 2.视效 3.剧情 4.演出 5.总评分 6.退出\n");


	int select_subject = 0;
	while(scanf("%d",&select_subject)==0 || select_subject==0 || select_subject>6)
	{
		getchar();
		printf("ERROR,输入正确的选择:");
	}

	switch (select_subject)
	{
	case 1:// 音乐         
		while (pMove->next)
		{
			pMove = pMove->next;
			pMove->m_rankScore = pMove->m_music;
		}
		printf("------------+------------+------------+----------------------------\n");
		printf("    序号    |    名称     |    时期    |  音乐得分  |  音乐评分名次   |\n");
		printf("------------+------------+------------+------------+---------------\n");

		Rank_byScore(pHead, 1);
		break;
	case 2://视觉效果    
		while (pMove->next)
		{
			pMove = pMove->next;
			pMove->m_rankScore = pMove->m_visual;
		}
		printf("------------+------------+------------+-----------+-----------------\n");
		printf("    序号    |    名称     |    时期    |  音乐得分  |  视效评分名次    |\n");
		printf("------------+------------+------------+-----------+-----------------\n");

		Rank_byScore(pHead, 2);
		break;
	case 3://剧情流程度       
		while (pMove->next)
		{
			pMove = pMove->next;
			pMove->m_rankScore = pMove->m_story;
		}
		printf("------------+------------+------------+-----------+-----------------\n");
		printf("    序号    |    名称     |    时期    |  剧情得分  |  剧情评分名次    |\n");
		printf("------------+------------+------------+-----------+-----------------\n");

		Rank_byScore(pHead, 3);
		break;
	case 4://演员角色的演出效果          
		while (pMove->next)
		{
			pMove = pMove->next;
			pMove->m_rankScore = pMove->m_display;
		}
		printf("------------+------------+------------+-----------+-----------------\n");
		printf("    序号    |    名称     |    时期    |  演出得分  |  演出评分名次    |\n");
		printf("------------+------------+------------+-----------+-----------------\n");

		Rank_byScore(pHead, 4);
		break;
	case 5://总排名   ܷ     
		while (pMove->next)
		{
			pMove = pMove->next;
			pMove->m_rankScore = pMove->m_totalScore;
		}
		printf("------------+------------+------------+-----------+-----------+------------+-------------+--------------+---------------\n");
		printf("    序号    |    名称     |    时期    |     音乐  |    视效    |    剧情    |    演出     |    总得分    |    评分总名次  |\n");
		printf("------------+------------+------------+-----------+-----------+------------+-------------+--------------+---------------\n");

		Rank_byScore(pHead, 5);
		break;
	case 6:
		return ;
		break;
	default:
		break;
	}
}
//5-4. 排名    
void Rank_byScore(Mov* pHead, int subject)
{
	Mov* p = pHead->next->next;
	Mov* q = NULL;
	Mov* pre = NULL;
	pHead->next->next = NULL;
	// 直插法排序    
	while (p)
	{
		q = p->next;
		pre = pHead;
		while (pre->next != NULL && pre->next->m_rankScore > p->m_rankScore)//Ԥ  
		{
			pre = pre->next;
		}
		p->next = pre->next;
		pre->next = p;
		p = q;
	}

	// 遍历链表    
	Mov* pMove = pHead;
	int scoreRank = 1;

	if (subject != 5)
	{
		while (pMove->next)
		{
			pMove = pMove->next;
			printf("------------+------------+------------+------------+-------------\n");
			printf("%11s |%11s |%11d |%11d |%11d |\n", pMove->m_number, \
				pMove->m_name, pMove->m_year, pMove->m_rankScore, scoreRank);
			scoreRank++;
		}
		printf("-----------------------------------------------------------------\n");
	}
	else {
		while (pMove->next)
		{
			pMove = pMove->next;
			printf("------------+------------+------------+------------+------------+------------+------------+------------+-------------\n");
			printf("%11s |%11s |%11d |%11d |%11d |%11d |%11d |%11d |%11d |\n", pMove->m_number, \
				pMove->m_name, pMove->m_year, pMove->m_music, pMove->m_visual, \
				pMove->m_story, pMove->m_display, pMove->m_rankScore, scoreRank);
			scoreRank++;
		}
		    printf("---------------------------------------------------------------------------------------------------------------------\n");
	}
}

//6-1. 显示全部电影信息
void Show_all_selection(Mov* pHead)
{
	system("cls");

	printf(" _______________________________________\n");
	printf("| 1.所有口碑较差的电影                  |\n");
	printf("| 2.全部电影                            |\n");
	printf("| 3.返回                                |\n");
	printf(" ---------------------------------------\n");

	int select;
	while(scanf("%d",&select)==0 || select==0 || select>3)
	{
		printf("EROROR!,请输入正确的选择:");
	}
	//getchar();
	switch (select)
	{
	case 1:// 口碑较差电影
		Show_all_unqualified_movie(pHead);
		break;
	case 2://全部电影 
		Show_all_movie(pHead);
		break;
	default:
		break;
	}
}
//6-2.所有口碑垃圾的电影 
void Show_all_unqualified_movie(Mov* pHead)
{
	system("cls");

	Mov* pMove = pHead;
	printf("--------------------------------------------------------------------------------------------------------------\n");
	printf("     序号      |     名称     |    时期    |    音乐     |    视效     |    剧情     |    演出    |       总分    |\n");
	printf("---------------+-------------+------------+-------------+-------------+-------------+-----------+---------------\n");
	while (pMove->next)
	{
		pMove = pMove->next;
		if (!pMove->m_qualifiedScore)
		{
			printf("---------------+------------+------------+------------+------------+------------+------------+--------------\n");
			printf("%14s |%11s |%11d |%11d |%11d |%11d |%11d |%11d   |\n", pMove->m_number, pMove->m_name, pMove->m_year, pMove->m_music, pMove->m_visual, pMove->m_story, pMove->m_display, pMove->m_totalScore);
		}
	}
			printf("------------------------------------------------------------------------------------------------------------\n");
	getchar();
}
//6-3.全部电影  
void Show_all_movie(Mov* pHead)
{
	system("cls");
	Mov* pMove = pHead;

	printf("--------------------------------------------------------------------------------------------------------------\n");
	printf("     序号      |    名称     |    时期    |    音乐     |    视效     |    剧情     |    演出    |       总分    |\n");
	printf("---------------+------------+------------+------------+-------------+-------------+-----------+---------------\n");
	while (pMove->next)
	{
		pMove = pMove->next;
		printf("---------------+------------+------------+------------+------------+------------+------------+--------------\n");
		printf("%14s |%11s |%11d |%11d |%11d |%11d |%11d |%11d   |\n", pMove->m_number, pMove->m_name, \
			pMove->m_year, pMove->m_music, pMove->m_visual, pMove->m_story, \
			pMove->m_display, pMove->m_totalScore);
	}
		printf("------------------------------------------------------------------------------------------------------------\n");
	getchar();
}
