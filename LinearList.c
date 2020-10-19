#include "DataStruct.h"

int main()
{
	list sqlistA, sqlistB, sqlistC  ;
	list *La = &sqlistA;
	list *Lb = &sqlistB;
	list *Lc = &sqlistC;
	
	SQlist_init(La);		
	SQlist_init(Lb);

	
	int i=1;
	
	for(i; i<10; i++)
	{
		SQlist_insert(La, i, 2*i );
		SQlist_insert(Lb, i, i);
	}

	SQlist_merge(La, Lb, Lc);
	
	SQlist_show(La);
	SQlist_show(Lb);
	SQlist_show(Lc);


	
	//printf("%d \n", SQlist_locate( L, 3, compare)); //compare是个地址
	
}