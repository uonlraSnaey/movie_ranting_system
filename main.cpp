#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fuctionState.h"
#include "dealInfor.cpp"
#include "searchInfor.cpp"
//#include "authentication.cpp"

int main()
{

	Mov* pHead = (Mov*)malloc(sizeof(Mov));
	memset(pHead, 0, sizeof(Mov));
	//log_in();
	pHead->next = NULL;
	Load_data(pHead);// 
	
	Select_fuction(pHead);

	free(pHead);
	return 0;
}
