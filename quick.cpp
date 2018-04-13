
using namespace std;

void qswap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int partition(int *a, int low, int high)
{
	
	int p = a[low];
	while (low < high)
	{
		while (low < high && p < a[high])
		{
			high--;
		}
		if (low<high)
			qswap(a[low], a[high]);
		while (low<high && a[low]<=p)
		{
			low++;
		}
		if(low<high)
			qswap(a[low], a[high]);
	}
	return low;
}

//���滻ȡ�����������Ч�ʡ�
int partition1(int *a, int low, int high)
{
	int p = a[low];

	while (low < high)
	{
		while (low < high && p < a[high])
		{
			high--;
		}
		if (low < high)
			a[low] = a[high];
			//qswap(a[low], a[high]);
		while (low<high && a[low] <= p)
		{
			low++;
		}
		if (low < high)
			a[high] = a[low];
			//qswap(a[low], a[high]);
	}
	a[low] = p;
	return low;
}

//�㷨�����ϵ���һ����ʽ
int partition2(int *a, int low, int high)
{
	int p = a[high];
	int  j, i = low - 1;
	for (j = low; j < high; j++)
	{
		if (a[j] <= p)
		{
			++i;
			qswap(a[i], a[j]);
		}
	}
	qswap(a[i + 1], a[high]);
	return i + 1;


}

void QSort(int *a, int low, int high)
{
	//����ͨ���жϣ����������������һ��ֵ��50��ʱ�Ϳ�������
	//����Ͳ���ֱ�Ӳ�������
	int p;
	if (low < high)
	{
		p = partition2(a, low, high);
		QSort(a, low, p - 1);
		QSort(a, p + 1, high);
	}
}

void quickSort(int *a, int len)
{
	QSort(a, 0, len - 1);
}

