int lower_bound(int l, int r, int key) //�½���ֲ��ң��ҳ���һ��ֵ��С��key��λ�ã�������l��������˵㣬r�������Ҷ˵�
{
    while(l < r) //����ΪС�ڶ���С�ڵ���
    {
        int mid = l + (r - l) / 2;
        if(a[mid] >= key) r = mid; //�˴�Ϊ���ڵ���
        else l = mid + 1; //�˴�����Ҫ+1
    }
    return l;
}
int upper_bound(int l, int r, int key) //�Ͻ���ֲ��ң��ҳ���һ��ֵ����key��λ�ã�
{
    while(l < r)
    {
        int mid = l + (r - l) / 2;
        if(a[mid] > key) r = mid; //���½���ֲ��Ҽ�����ȫ��ͬ�����д˴����޸�Ϊ����
        else l = mid + 1;
    }
    return l;
}
//������½���ͬ����ж����ֲ�������������
