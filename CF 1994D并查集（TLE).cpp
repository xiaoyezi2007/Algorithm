#include <bits/stdc++.h>
using namespace std;
vector<int> r[2005][2005];
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

// 定义并查集结构体
typedef struct
{
    int *parent;  // 父节点数组
    int *rank1;    // 秩（用于优化合并操作）
    int size1;     // 并查集的大小
} DisjointSet;
int sumr[2005][2005];
int ans12[2005][2];
int in[2005];
// 初始化并查集
void initDisjointSet(DisjointSet *set1, int size1)
{
    set1->size1 = size1;
    set1->parent = (int *)malloc(sizeof(int) * size1);
    set1->rank1 = (int *)malloc(sizeof(int) * size1);

    // 初始化每个元素的父节点为自身，秩为0
    for (int i = 0; i < size1; i++)
    {
        set1->parent[i] = i;
        set1->rank1[i] = 0;
    }
}

// 查找操作（找到元素所在的集合的代表元素）
int find1(DisjointSet *set1, int x)
{
    if (set1->parent[x] != x)
    {
        // 路径压缩：将节点的父节点直接设为根节点，减小查找路径长度
        set1->parent[x] = find1(set1, set1->parent[x]);
    }
    return set1->parent[x];
}

// 合并操作
void unionSets(DisjointSet *set1, int x, int y)
{
    int rootX = find1(set1, x);
    int rootY = find1(set1, y);

    // 按秩合并：将秩较小的集合合并到秩较大的集合上
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

// 释放并查集占用的内存
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

