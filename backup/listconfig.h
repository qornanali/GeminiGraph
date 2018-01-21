#ifndef  __LISTConfig_H__
#define  __LISTConfig_H__

typedef struct Config * P_Config;
typedef struct Config{
 	char name[15];
 	char value[50];
	P_Config next;
} Config;
typedef struct LConfigs{
	P_Config first;
	P_Config last;
} LConfigs;

P_Config allocConfig();
P_Config getConfig(LConfigs L, char name[]);
void deAllocConfig (P_Config P);
void addConfigtToList(LConfigs * L, P_Config P);
void removeConfigFromList(LConfigs * L, char name[]);
void initListConfigs(LConfigs * L);
void printListItemConfigs(LConfigs L);
P_Config createInstanceConfig(char name[], char value[]);

#endif
