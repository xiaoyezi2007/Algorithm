#include <bits/stdc++.h>
using namespace std;
vector<int> r[2005][2005];
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

// ���岢�鼯�ṹ��
typedef struct
{
    int *parent;  // ���ڵ�����
    int *rank1;    // �ȣ������Ż��ϲ�������
    int size1;     // ���鼯�Ĵ�С
} DisjointSet;
int sumr[2005][2005];
int ans12[2005][2];
int in[2005];
// ��ʼ�����鼯
void initDisjointSet(DisjointSet *set1, int size1)
{
    set1->size1 = size1;
    set1->parent = (int *)malloc(sizeof(int) * size1);
    set1->rank1 = (int *)malloc(sizeof(int) * size1);

    // ��ʼ��ÿ��Ԫ�صĸ��ڵ�Ϊ������Ϊ0
    for (int i = 0; i < size1; i++)
    {
        set1->parent[i] = i;
        set1->rank1[i] = 0;
    }
}

// ���Ҳ������ҵ�Ԫ�����ڵļ��ϵĴ���Ԫ�أ�
int find1(DisjointSet *set1, int x)
{
    if (set1->parent[x] != x)
    {
        // ·��ѹ�������ڵ�ĸ��ڵ�ֱ����Ϊ���ڵ㣬��С����·������
        set1->parent[x] = find1(set1, set1->parent[x]);
    }
    return set1->parent[x];
}

// �ϲ�����
void unionSets(DisjointSet *set1, int x, int y)
{
    int rootX = find1(set1, x);
    int rootY = find1(set1, y);

    // ���Ⱥϲ������Ƚ�С�ļ��Ϻϲ����Ƚϴ�ļ�����
    if (rootX != rootY)
    {
        if (set1->rank1[rootX] < set1->rank1[rootY])
        {
            set1->parent[rootX] = rootY;
        }
        else if (set1->rank1[rootX] > set1->rank1[rootY])
        {
            set1->parent[rootY] = rootX;
        }
        else
        {
            set1->parent[rootY] = rootX;
            set1->rank1[rootX]++;
        }
    }
}

// �ͷŲ��鼯ռ�õ��ڴ�
void freeDisjointSet(DisjointSet *set1)
{
    free(set1->parent);
    free(set1->rank1);
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        memset(sumr,0,sizeof(sumr));
        for(int i=0; i<n; i++)
        {
            scanf("%d",&in[i]);
            for(int j=1; j<=n-1; j++)
            {
                r[j][in[i]%j].push_back(i);
                sumr[i][j]++;
            }
        }
        int size1 = n;
        DisjointSet set1;
        initDisjointSet(&set1, size1);
        for(int i=n-1; i>=1; i--)
        {
            int flag=0;
            for(int j=0; j<i; j++)
            {
                for(int x:r[i][j])
                {
                    for(int y:r[i][j])
                    {
                        if(find1(&set1,x)!=find1(&set1,y))
                        {
                            ans12[i][0]=x;
                            ans12[i][1]=y;
                            unionSets(&set1,x,y );
                            flag=1;
                        }
                        if(flag==1) break;
                    }
                    if(flag==1) break;
                }

                if(flag==1) break;
            }
        }
        puts("YES");
        for(int i=1; i<=n-1; i++)
        {
            printf("%d %d\n",ans12[i][0]+1,ans12[i][1]+1);
        }
        for(int i=1;i<=n-1;i++)
        {
            for(int j=0;j<i;j++)
            {
                r[i][j].clear();
            }
        }
        freeDisjointSet(&set1);
    }


    return 0;
}

