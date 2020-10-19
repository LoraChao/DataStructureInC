#include <stdio.h>
#include <stdlib.h>

#ifndef _DataStruct_H
#define _DataStruct_H
#endif

#define INIT_SIZE 30
#define LISTINCREMENT 10

typedef int ElemType;
typedef int Status;

typedef struct
{
	ElemType *Base;
	int Length;
	int WholeSize;
}list;

ElemType compare( ElemType a, ElemType b )
{
    if( a == b )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

Status SQlist_init(list *L)
{
	
	L->Base = (ElemType*)malloc(INIT_SIZE *sizeof(ElemType));  //malloc返回值为void*
	if(!L->Base) 
		exit(0);
	L->Length = 0;
	L->WholeSize = INIT_SIZE;
	return 0;
}

void SQlist_show(list *L)
{
	ElemType *LEnd = L->Base + (L->Length)-1;
	ElemType *p = L->Base;
	while(p <= LEnd)
	{
		printf("%d ", *p++);
	}
	printf("\n");
}


Status SQlist_insert(list *L, int i, ElemType value)
{
	ElemType *NewBase, *InsertLocation, *EndLocation;
	if(i<1 || i > L->Length+1)
		exit(0);
	if(i > L->WholeSize)
	{
		NewBase = (ElemType*)realloc(L->Base, sizeof(ElemType) * (INIT_SIZE + LISTINCREMENT));
		L->WholeSize += LISTINCREMENT;		
		L->Base = NewBase;
		if(!NewBase) return 1;
	}
	else
	{
		InsertLocation = &(L->Base[i-1]);
		EndLocation = &(L->Base[L->Length-1]);
		for(EndLocation; EndLocation >= InsertLocation; EndLocation--)
		{
			*(EndLocation+1) = *EndLocation;
		}
	}
	*InsertLocation = value;
	L->Length += 1;	
}

Status SQlist_insert2(list *L, int i, ElemType value)
{
	if(i<1 || i> L->Length+1)
	{
		return 1;  
	}
	if(i > L->WholeSize)
	{
		ElemType* NewBase = (ElemType*)realloc(L->Base, sizeof(ElemType)*(INIT_SIZE+ LISTINCREMENT));
		L->Base = NewBase;
		L->WholeSize += LISTINCREMENT;
	}
	else
	{
		int end = L->Length;
		for(end; end>=i-1; end--)
		{
			L->Base[end] = L->Base[end-1];
		}
	}
	L->Base[i-1] = value;
	L->Length++;
}

Status SQlist_delete(list *L, ElemType i)
{
	if(i<1 || i> L->Length+1)
	{
		return 1;
	}
	else
	{
		int insert = i;
		for(insert; insert <= L->Length; insert++)
		{
			L->Base[insert-1] = L->Base[insert];
		}
	L->Length--;
	}
}
	
Status SQlist_locate( list *L, ElemType value, ElemType(*compare)(ElemType, ElemType)) //函数指针
{
    int i;
    i = 0;
    while( i<=L->Length && !(*compare)(L->Base[i], value))
    {
        i++;
    }
    if( i <= L->Length)
    {
        return i+1;
    }
    else
    {
        return 0;
    }
}
	
Status SQlist_locate2(list *L, int value, ElemType (*compare)(int, int))
{
	int i = 1;
	int* p = L->Base;
	
	while(!(*compare)(value, *p++) && i <= L->Length)
		i++;
	if(i <= L->Length)
		return i;
	else
		return 0;
}

void SQlist_merge(list *La, list *Lb, list *Lc)
//已知顺序线性表La和Lb的元素按值非递减排列
//归并La和Lb得到新的顺序线性表Lc，Lc的元素也按非递减排列
{
	ElemType *pa = La->Base;
	ElemType *pb = Lb->Base;
	ElemType *LaEnd = pa + (La->Length)-1;
	ElemType *LbEnd = pb + (Lb->Length)-1;
	
	Lc->Base = (ElemType*)malloc(sizeof(ElemType) * (La->Length+ Lb->Length));
	Lc-> Length = La->Length + Lb->Length; 
	
	ElemType *pc = Lc->Base;
	
	if(!Lc->Base) exit(0);
	
	while(pa <= LaEnd && pb <= LbEnd)
	{
		if(*pa > *pb)
			{
				*pc = *pb;
				pc++; pb++;
			}
			else
			{
				*pc = *pa;
				pc++; pa++;
			}
	}
	while(pa <= LaEnd)
	{
		*pc = *pa; pc++; pa++;
	}
	
	while(pb <= LbEnd)
	{
		*pc =  *pb;  pc++; pb++;
	}
}



		
		
			
		
		
		






/*void union(*L1, *L2)
{
	ElemType* end = &(L2->Base[Length-1]);
	ElemType* start = L2->Base;
	for(start; start <= end ; start++)
	{
		if(SQlist_locate(*L1, *start, (ElemType*)compare(*start, )));


/*
void SQlist_destory(list *L)
{
	free(L);
	printf("1111destory successfully\n");
}*/