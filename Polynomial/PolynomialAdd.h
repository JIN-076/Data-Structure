#ifndef _POLYNOMIALADD_H_
# define _POLYNOMIALADD_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# define	TRUE	1
# define	FALSE	0
# define	ERROR	-1

typedef struct PolyNodeType
{
	int					coef;		// 계수
	int					degree;		// 차수
	struct PolyNodeType	*pNext;
} PolyNode;

typedef struct PolyListType
{
	int			currentElementCount;	// 현재 저장된 원소의 개수
	PolyNode	headerNode;				// 헤더 노드(Header Node)
} PolyList;

PolyList	*createPolyList(void);
int			insertPolyNode(PolyList *pList, PolyNode element);
PolyList	*addPolyList(PolyList *pList1, PolyList *pList2);

void		displayPolyList(PolyList *pList);
void		deletePolyList(PolyList *pList);
int			getPolyListLength(PolyList *pList);

#endif
