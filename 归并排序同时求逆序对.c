#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define min2(a,b) ((a)<(b)?(a):(b))
#define N 100010
typedef long long int ll;

int q[N];
ll result = 0;

void merge_sort(int l, int r){
    //�ݹ��������
    if(l >= r) return;
    //�ֳ�������
    int mid = l + r >> 1;
    //�ݹ鴦��������
    merge_sort(l, mid); merge_sort(mid + 1, r);
    //�ϲ�������
    int k = 0, i = l, j = mid + 1, temp[r - l + 1];
    while(i <= mid && j <= r){
        if(q[i] <= q[j]) temp[k++] = q[i++];
        else {
            temp[k++] = q[j++];
            result += mid - i + 1;
        }
    }
    while(i <= mid) temp[k++] = q[i++];
    while(j <= r) temp[k++] = q[j++];
    //���ԭ��
    for(int i = l, k = 0; i <= r; i++, k++) q[i] = temp[k];
}

int main(void){
    int n = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)scanf("%d", &q[i]);

    merge_sort(0, n - 1);

    printf("%lld\n", result);

    return 0;
}
