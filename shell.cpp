
using namespace std;

void shellSort(int *a, int arraySize)
{
	int i, j, k, temp;
	int gap = arraySize;
	for (gap = arraySize / 2; gap > 0; gap /= 2)
	{
		for (i = 0; i < gap; i++)
		{
			for (j = i ; j < arraySize-gap; j += gap)
			{
				if (a[j] > a[j + gap])
				{
					temp = a[j + gap];
					k = j ;
					while (k >= 0 && a[k] > temp)
					{
						a[k +gap] = a[k];
						k -= gap;
					}
					a[k + gap] = temp;
				}
			}
		}
	}
}	
/*
�����ԣ������shellsort1������Ȼ��ֱ�۵����ϣ�������а�����
��������̫���ˣ����������������˽����¸Ľ����Ż����Եڶ�������Ϊ����
ԭ����ÿ�δ�1A��1E����2A��2E�����Ըĳɴ�1B��ʼ���Ⱥ�1A�Ƚϣ�Ȼ��ȡ2B��2A�Ƚϣ�
��ȡ1C��ǰ���Լ����ڵ����ݱȽϡ���.������ÿ�δ������gap��Ԫ�ؿ�ʼ��
ÿ��Ԫ�����Լ����ڵ����ݽ���ֱ�Ӳ���������ȻҲ����ȷ�ġ�*/
void shellSort1(int *a, int n)
{
	int j, gap;

	for (gap = n / 2; gap > 0; gap /= 2)
		for (j = gap; j < n; j++)//�������gap��Ԫ�ؿ�ʼ
			if (a[j] < a[j - gap])//ÿ��Ԫ�����Լ����ڵ����ݽ���ֱ�Ӳ�������
			{
				int temp = a[j];
				int k = j - gap;
				while (k >= 0 && a[k] > temp)
				{
					a[k + gap] = a[k];
					k -= gap;
				}
				a[k + gap] = temp;
			}
}

//shellSort2��shellSort1��ͬ��ǰ���Ǻ��ߵ���д
void shellSort2(int *a, int arraySize)
{
	int i, k, gap, temp;
	for (gap = arraySize / 2; gap > 0; gap /= 2)
	{
		for (i = 0; i < arraySize-gap ; i++)
		{
			if (a[i] > a[i + gap])
			{
				temp = a[i + gap];
				k = i;
				while (k >= 0 && a[k]>temp)
				{
					a[k + gap] = a[k];
					k -= gap;
				}
				a[k + gap] = temp;
			}
			
		}
	}
}
	



