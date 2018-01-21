#ifndef  __LISTDouble_H__
#define  __LISTDouble_H__

typedef struct Double * P_Double;
typedef struct Double{
 	char name[15];
 	double value;
	P_Double next;
} Double;
typedef struct LDoubles{
	P_Double first;
	P_Double last;
} LDoubles;

P_Double allocDouble();
P_Double getDouble(LDoubles L, char name[]);
void deAllocDouble (P_Double P);
void addDoubleToList(LDoubles * L, P_Double P);
void removeDoubleFromList(LDoubles * L, char name[]);
void initListDoubles(LDoubles * L);
void printListItemDoubles(LDoubles L);
P_Double createInstanceDouble(char name[10], double value);

#endif
