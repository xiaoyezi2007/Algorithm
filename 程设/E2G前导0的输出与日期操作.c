#include<stdio.h>
#include<math.h>

int main()
{
    int y,m,d,h,min,s;
    char a,b,c;
    scanf("%d/%d/%d%d:%d:%d %c%c%c",&y,&m,&d,&h,&min,&s,&a,&b,&c);
    if(a!='S'&&((h>=9&&h<=14)||(h==15&&min==0&&s==0)))
        printf("%04d/%02d/%02d",y,m,d);
    else
    {
        if((a=='M'||a=='T'||a=='W')||(a=='F'&&h<=8)||(a=='S'&&b=='u'))
        {
            if(h<=8&&a!='S')
                printf("%04d/%02d/%02d",y,m,d);
            else
            {
                if(m==2&&d==28)//加一天的通法
                {
                    if((y%4==0&&y%100!=0)||y%400==0)
                        printf("%04d/%02d/%02d",y,m,d+1);
                    else
                        printf("%04d/%02d/01",y,m+1);
                }
                else if(((m==1||m==3||m==5||m==7||m==8||m==10)&&d==31)||((m==4||m==6||m==9||m==11)&&d==30)||(m==2&&d==29))
                    printf("%04d/%02d/01",y,m+1);
                else if(m==12||d==31)
                    printf("%04d/01/01",y+1);
                else
                    printf("%04d/%02d/%02d",y,m,d+1);
            }
        }
        else
        {
            if(a=='F')
            {
                if(m==2&&d>=26)
                {
                    if(((y%4==0&&y%100!=0)||y%400==0)&&d==26)
                        printf("%04d/%02d/%02d",y,m,d+3);
                    else if(((y%4==0&&y%100!=0)||y%400==0)&&d!=26)
                        printf("%04d/%02d/%02d",y,m+1,d-26);
                    else
                        printf("%04d/%02d/%02d",y,m+1,d-25);
                }
                else if((m==1||m==3||m==5||m==7||m==8||m==10)&&d>=29)
                    printf("%04d/%02d/%02d",y,m+1,d-28);
                else if((m==4||m==6||m==9||m==11)&&d>=28)
                    printf("%04d/%02d/%02d",y,m+1,d-27);

                else if(m==12||d>=29)
                    printf("%04d/01/%02d",y+1,d-28);
                else
                    printf("%04d/%02d/%02d",y,m,d+3);
            }
            if(a=='S'&&b=='a')
            {
                if(m==2&&d>=27)
                {
                    if(((y%4==0&&y%100!=0)||y%400==0)&&d==27)
                        printf("%04d/%02d/%02d",y,m,d+2);
                    else if(((y%4==0&&y%100!=0)||y%400==0)&&d!=27)
                        printf("%04d/%02d/%02d",y,m+1,d-27);
                    else
                        printf("%04d/%02d/%02d",y,m+1,d-26);
                }
                else if((m==1||m==3||m==5||m==7||m==8||m==10)&&d>=30)
                    printf("%04d/%02d/%02d",y,m+1,d-29);
                else if((m==4||m==6||m==9||m==11)&&d>=29)
                    printf("%04d/%02d/%02d",y,m+1,d-28);

                else if(m==12||d>=30)
                    printf("%04d/01/%02d",y+1,d-29);
                else
                    printf("%04d/%02d/%02d",y,m,d+2);
            }
        }

    }
}
