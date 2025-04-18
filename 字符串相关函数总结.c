//字符串相关函数
#include <string.h>
char *strchr(char *s, int c);//返回c在s中第一次出现的位置，这里c可以输入字符，若不存在c返回NULL
char *strrchr(char *s,int c);//返回c在s中最后一次出现的位置，这里c可以输入字符，若不存在c返回NULL
char *strstr(const char *str1, const char *str2);//返回str1中第一次出现str2的位置，不存在返回NULL
int strcmp(const char *str1,const char *str2);//比较两个字符串字典序，s1==s2返回0，s1>s2返回正，反之为负
char *strcpy(char *to,char *from);//将from串复制到to，返回to的位置
char *strncpy(char *to,char *from,int n);//将from开始的n个字符复制到to并返回to的位置
char *strcat(char *d,char *s);//将s串拼接到d的末尾，注意d要有足够的空间，返回指向d的指针
char *strncat(char *d,char *s,int n);//同理
int strlen(char *str);//返回str的长度






