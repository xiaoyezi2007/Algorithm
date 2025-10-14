#include<stdio.h>
#include<math.h>
#include<string.h>
char c[510];
int main()
{
    int len,i;
    printf("#include<stdio.h>\n");
    printf("int main()\n");
    printf("{\n");
    while(gets(c))
    {
        len=strlen(c);
        printf("    puts(\"");
        for(i=0;i<len;i++)
        {
            if(c[i]=='\'')
                printf("\\\'");
            else if(c[i]=='"')
                printf("\\\"");
            else if(c[i]=='\\')
                printf("\\\\");
            else
                printf("%c",c[i]);
        }
        printf("\");\n");
    }
    printf("    return 0;\n");
    printf("}");



}
