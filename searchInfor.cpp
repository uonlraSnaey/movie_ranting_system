//4-1.��ѯ��Ӱ��Ϣ
void Search_movie(Mov* pHead)
{
	system("cls");
	int ret = 1;// �жϵ�Ӱ�������    
	Mov* pMove = pHead;

	printf("ͨ��ʲô;�����ҵ�Ӱ:\n");
	printf(" ______________\n");
	printf("|   1.����     |\n");
	printf("|   2.���     |\n");
	printf("|______________|\n");
	printf("|   3.����     |\n");
	printf("|______________|\n");

	int searchWay;
	while(scanf("%d",&searchWay)==0 || searchWay==0 || searchWay>3)
	{
		getchar();
		printf("��������ȷ;��:");
	}

	switch (searchWay)
	{
	case 1:
		char name[20];
		printf("����:");
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
		printf("|  ERROR,δ��¼�õ�Ӱ  |\n");
		printf("|_____________________|\n");
		getchar();
		break;
	case 2:
		char number[20];
		printf("���:");
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
		printf("|  ERROR,δ��¼�õ�Ӱ  |\n");
		printf("|_____________________|\n");
		getchar();
		break;
	default:
		break;
	}
}
//4-2. ��ӡ��Ӱ�����Ϣ
void Show_movieInformation(Mov* movie)
{
	system("cls");

	printf(" _____________________\n");
	printf("|  ���ơ�:%-12s         |\n", movie->m_name);
	printf("|  ���:%-12s          |\n", movie->m_number);
	printf("|  ��ӳ���:%-12d      |\n", movie->m_year);
	printf("|  ���ֵ÷�:%-12d      |\n", movie->m_music);
	printf("|  ��Ч�÷�:%-12d      |\n", movie->m_visual);
	printf("|  ����÷�:%-12d      |\n", movie->m_story);
	printf("|  �ݳ��÷�:%-12d      |\n", movie->m_display);
	printf("|  �ܷ�:%-12d          |\n", movie->m_totalScore);
	printf("|______________________|\n");
	getchar();
}

//5-1. ѡ�����򷽷�
void Rank_kindSelect(Mov* pHead)
{
	system("cls");
	int ifSelect = 1;//�Ƿ����   

	printf("����ĳ����ݻ���ȫ���������:\n");
	printf(" ______________\n");
	printf("|   1.���     |\n");
	printf("|   2.ȫ��ʱ��  |\n");
	printf("|______________|\n");
	printf("|   3.����     |\n");
	printf("|______________|\n");

	int kindSelect = 0;
	while(scanf("%d",&kindSelect)==0 || kindSelect==0 || kindSelect>3)
	{
		getchar();
		printf("ERROR,������ȷ��ѡ��:");
	}
	Mov* p_classHead = NULL;
	while (ifSelect)
	{
		switch (kindSelect)
		{
		case 1:// �2�8���������   
			system("cls");
			int rankYear;
			printf("��������鿴���������:");
			scanf("%d", &rankYear);

			p_classHead = Build_rankYear(pHead, rankYear);
			if (NULL == p_classHead)
			{
				printf("  ___________________________________\n");
				printf(" |  ϵͳ����δ¼�����ݵ�Ӱ����Ϣ.     |\n");
				printf(" |___________________________________|\n");
				getchar();
				break;
			}
			Rank_subjectSelect(p_classHead);
			getchar();
			break;
		case 2://ȫԺ������    
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
			printf("�Ƿ�Ҫ�����鿴����?[1-�� 0-��]");
			scanf("%d", &ifSelect);
		}
	}
}
//5-2.������Ҫ�������� ��һ��ܿ��ܰ����ಿ��Ӱ��
Mov* Build_rankYear(Mov* pHead, int rankYear)
{
	Mov* pMoveGrade = pHead;//�������ͷָ��

	Mov* classHead = (Mov*)malloc(sizeof(Mov));// ��ݵ��׸��ڵ�
	memset(classHead, 0, sizeof(Mov));
	classHead->next = NULL;
	Mov* pMoveYear = classHead;// ������ݵ�ͷָ��

	int classmateNumber = 0;// �ܵ�Ӱ��    
	while (pMoveGrade->next)
	{
		pMoveGrade = pMoveGrade->next;
		if (pMoveGrade->m_year == rankYear)//������ݵĵ�Ӱ��Ϣ���Ƶ���Ҫ����������������              
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
//5-3. ��������Ŀ���� 
void Rank_subjectSelect(Mov* pHead)
{
	Mov* pMove = pHead;
	system("cls");

	if (NULL == pHead->next )
	{
		printf("�޸��������������¼��,����ʧ�ܡ�");
		getchar();
		return;
	}
	printf("����ĳһ����������:\n");
	printf("1.���� 2.��Ч 3.���� 4.�ݳ� 5.������ 6.�˳�\n");


	int select_subject = 0;
	while(scanf("%d",&select_subject)==0 || select_subject==0 || select_subject>6)
	{
		getchar();
		printf("ERROR,������ȷ��ѡ��:");
	}

	switch (select_subject)
	{
	case 1:// ����         
		while (pMove->next)
		{
			pMove = pMove->next;
			pMove->m_rankScore = pMove->m_music;
		}
		printf("------------+------------+------------+----------------------------\n");
		printf("    ���    |    ����     |    ʱ��    |  ���ֵ÷�  |  ������������   |\n");
		printf("------------+------------+------------+------------+---------------\n");

		Rank_byScore(pHead, 1);
		break;
	case 2://�Ӿ�Ч��    
		while (pMove->next)
		{
			pMove = pMove->next;
			pMove->m_rankScore = pMove->m_visual;
		}
		printf("------------+------------+------------+-----------+-----------------\n");
		printf("    ���    |    ����     |    ʱ��    |  ���ֵ÷�  |  ��Ч��������    |\n");
		printf("------------+------------+------------+-----------+-----------------\n");

		Rank_byScore(pHead, 2);
		break;
	case 3://�������̶�       
		while (pMove->next)
		{
			pMove = pMove->next;
			pMove->m_rankScore = pMove->m_story;
		}
		printf("------------+------------+------------+-----------+-----------------\n");
		printf("    ���    |    ����     |    ʱ��    |  ����÷�  |  ������������    |\n");
		printf("------------+------------+------------+-----------+-----------------\n");

		Rank_byScore(pHead, 3);
		break;
	case 4://��Ա��ɫ���ݳ�Ч��          
		while (pMove->next)
		{
			pMove = pMove->next;
			pMove->m_rankScore = pMove->m_display;
		}
		printf("------------+------------+------------+-----------+-----------------\n");
		printf("    ���    |    ����     |    ʱ��    |  �ݳ��÷�  |  �ݳ���������    |\n");
		printf("------------+------------+------------+-----------+-----------------\n");

		Rank_byScore(pHead, 4);
		break;
	case 5://������   �1�1     
		while (pMove->next)
		{
			pMove = pMove->next;
			pMove->m_rankScore = pMove->m_totalScore;
		}
		printf("------------+------------+------------+-----------+-----------+------------+-------------+--------------+---------------\n");
		printf("    ���    |    ����     |    ʱ��    |     ����  |    ��Ч    |    ����    |    �ݳ�     |    �ܵ÷�    |    ����������  |\n");
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
//5-4. ����    
void Rank_byScore(Mov* pHead, int subject)
{
	Mov* p = pHead->next->next;
	Mov* q = NULL;
	Mov* pre = NULL;
	pHead->next->next = NULL;
	// ֱ�巨����    
	while (p)
	{
		q = p->next;
		pre = pHead;
		while (pre->next != NULL && pre->next->m_rankScore > p->m_rankScore)//�0�0  
		{
			pre = pre->next;
		}
		p->next = pre->next;
		pre->next = p;
		p = q;
	}

	// ��������    
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

//6-1. ��ʾȫ����Ӱ��Ϣ
void Show_all_selection(Mov* pHead)
{
	system("cls");

	printf(" _______________________________________\n");
	printf("| 1.���пڱ��ϲ�ĵ�Ӱ                  |\n");
	printf("| 2.ȫ����Ӱ                            |\n");
	printf("| 3.����                                |\n");
	printf(" ---------------------------------------\n");

	int select;
	while(scanf("%d",&select)==0 || select==0 || select>3)
	{
		printf("EROROR!,��������ȷ��ѡ��:");
	}
	//getchar();
	switch (select)
	{
	case 1:// �ڱ��ϲ��Ӱ
		Show_all_unqualified_movie(pHead);
		break;
	case 2://ȫ����Ӱ 
		Show_all_movie(pHead);
		break;
	default:
		break;
	}
}
//6-2.���пڱ������ĵ�Ӱ 
void Show_all_unqualified_movie(Mov* pHead)
{
	system("cls");

	Mov* pMove = pHead;
	printf("--------------------------------------------------------------------------------------------------------------\n");
	printf("     ���      |     ����     |    ʱ��    |    ����     |    ��Ч     |    ����     |    �ݳ�    |       �ܷ�    |\n");
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
//6-3.ȫ����Ӱ  
void Show_all_movie(Mov* pHead)
{
	system("cls");
	Mov* pMove = pHead;

	printf("--------------------------------------------------------------------------------------------------------------\n");
	printf("     ���      |    ����     |    ʱ��    |    ����     |    ��Ч     |    ����     |    �ݳ�    |       �ܷ�    |\n");
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
