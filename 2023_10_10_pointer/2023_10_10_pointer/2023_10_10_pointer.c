#define _CRT_SECURE_NO_WARNINGS 1

//typedef int(*ptr_t)(int);
//typedef int(*arr_p)[5];

# include <stdio.h>
# include <stdlib.h>
# include <string.h>





int main()
{
	int x = 0, y = 0, z = 0;
	printf("��������������x, y, z��ֵ���ÿո������");
	scanf("%d %d %d", &x, &y, &z);
	if (x < y && x < z)
	{
		printf("��С������x��ֵΪx = %d\n", x);
		//�������д������
		//.......
	}
	else if (y < x && y < z)
		printf("��С������y��ֵΪy = %d\n", y);
	else
		printf("��С������z��ֵΪz = %d\n", z);

	return 0;
}






int main()
{
	void(* signal(int, void(*)(int)))(int);
	//void(*)(int)signal(int, void(*)(int));   err
	int a = 0;
	int* p1 = &a;
	int* p2 = &a;

	return 0;
}





//����ָ������
int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int main()
{
	int* arr[10];//����ָ�������
	int(*p1)(int, int) = Add;
	int(*p2)(int, int) = Sub;

	//����ָ������-��ź���ָ��
	int(* pArr[4] )(int, int) = { Add, Sub };

	return 0;
}





//����ָ����;��ת�Ʊ�
//ʵ�ּӼ��˳�������
void Menu()
{
	printf("******************************");
	printf("******  1.Add  2.Sub   *******");
	printf("******  3.Mul  4,Div   *******");
	printf("******     0.Exit      *******");
	printf("******************************");
}
int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}
int main()
{
	int input = 0;
	int a = 0;
	int b = 0;
	int ret = 0;
	do
	{
		Menu();
		printf("\n��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("����������������");
			scanf("%d %d", &a, &b);
			ret = Add(a, b);
			printf("%d\n", ret);
			break;
		case 2:
			printf("����������������");
			scanf("%d %d", &a, &b);
			ret = Sub(a, b);
			printf("%d\n", ret);
			break;
		case 3:
			printf("����������������");
			scanf("%d %d", &a, &b);
			ret = Mul(a, b);
			printf("%d\n", ret);
			break;
		case 4:
			printf("����������������");
			scanf("%d %d", &a, &b);
			ret = Div(a, b);
			printf("%d\n", ret);
			break;
		case 0:
		default:
			printf("\nѡ�����������ѡ��");
			break;
		}
	} while (input);
	return 0;
}










//����д���������

void Menu()
{
	printf("******************************\n");
	printf("******  1.Add  2.Sub   *******\n");
	printf("******  3.Mul  4,Div   *******\n");
	printf("******     0.Exit      *******\n");
	printf("******************************\n");
}
int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}
int main()
{
	//����ָ�������
	//��ת�Ʊ�
	int(*pfArr[])(int, int) = { 0, Add, Sub, Mul, Div };  //ʹ�±��ѡ���Ӧ

	int input = 0;
	int a = 0;
	int b = 0;
	int ret = 0;
	do
	{
		Menu();
		printf("\n��ѡ��");
		scanf("%d", &input);
		if (input >= 1 && input <= 4)
		{
			printf("������2����������");
			scanf("%d %d", &a, &b);
			ret = pfArr[input](a, b);
			printf("%d\n", ret);
		}
		else if (input == 0)
		{
			printf("�˳�������\n");
			break;
		}
		else
		{
			printf("ѡ�����������ѡ��\n");
		}
	} while (input);
	return 0;
}
//���⣻��������ֵ���ͱ���һ��










//��һ�ּ������У���ͬcase��������ƣ������ú�����ͬ����Щ����

void Menu()
{
	printf("******************************");
	printf("******  1.Add  2.Sub   *******");
	printf("******  3.Mul  4,Div   *******");
	printf("******     0.Exit      *******");
	printf("******************************");
}
int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}

////�Ѻ�����ַ���Σ��ú���ָ�봫��
////һ����������ʵ�ֶ������ʹ��
void calc(int(*pf)(int, int))
{
	int a = 0;
	int b = 0;
	int ret = 0;

	printf("������2����������");
	scanf("%d %d", &a, &b);
	ret = pf(a, b);
	printf("%d\n", ret);
}

int main()
{
	int input = 0;
	int a = 0;
	int b = 0;
	int ret = 0;
	do
	{
		Menu();
		printf("\n��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			calc(Add);
			break;
		case 2:
			calc(Sub);
			break;
		case 3:
			calc(Mul);
			break;
		case 4:
			calc(Div);
			break;
		case 0:
		default:
			printf("\nѡ�����������ѡ��");
			break;
		}
	} while (input);
	return 0;
}







//�ص�����   һ��ͨ������ָ����õĺ���



//�⺯��qsort,���������ݽ������򣬿���ʵ���κ����ݵ�����
//qsort������4������
void qsort
(
    void* base,  //baseָ�������ĵ�һ��Ԫ��
    size_t num,   //numָ�������Ԫ�ظ���
    size_t size,  //size��ÿ��Ԫ�صĴ�С�м����ֽ�
    int (*compar)(const void*, const void*)   //compar��һ������ָ�룬ָ��ĺ����ܹ��Ƚ�2��Ԫ��,���ȽϷ���
);



//void* ��ʲô��
int main()
{
    int a = 10;
    int* p = &a;
    char* pc = &a;//int* �� char* ������

    void* pv = &a;//����
    //ͨ��ָ�����ͣ����޾������͵�ָ��
    //void*���͵�ָ����������Խ��������������͵ĵ�ַ
    
    //��һ������
    pv + 1;      //err,��֪���Ӽ����ֽ�
    *pv;         //err����֪�������÷��ʼ����ֽ�
    //void*ֻ��������ŵ�ַ��
    return 0;
}









//����qsort������������

//��������ܱȽ�e1��e2ָ�������Ԫ�أ�����������ֵ
int cmp_int(const void* e1, const void* e2)          //ͨ��qsortʹ�ã��ǻص�����
{
    //*e1 *e2        ��void*���޷�ֱ�ӽ�����
    return  *(int*)e1 - *(int*)e2;     //��ǿ������ת������
}
void print_arr(int arr[], int sz)
{
    int i = 0;
    for (i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void test1()
{
    int arr[] = { 1,5,8,9,3,6,7,4,2 };
    int sz = (sizeof(arr) / sizeof(arr[0]));
    print_arr(arr, sz);                              //����ǰ��ӡ
    qsort(arr, sz, sizeof(arr[0]), cmp_int);
    print_arr(arr, sz);                              //������ӡ
}

//test2����qsort��������ṹ������
struct Stu //ѧ��
{
	char name[20];//����
	int age;//����
};
//���谴������Ƚ�
int cmp_stu_by_age(const void* e1, const void* e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}
//strcmp�ǿ⺯����ר�������Ƚ������ַ�����С
int cmp_stu_by_name(const void* e1, const void* e2)
{
    return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e1)->name);
}
 void test2()
 {
	 struct Stu s[] = { {"ZhangSan", 20}, {"LiSi", 30}, {"WangWu", 15} };
	 int sz = sizeof(s) / sizeof(s[0]);
	 qsort(s, sz, sizeof(s[0]), cmp_stu_by_age);
     qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
 }
int main()
{
    test1();
    test2();
    return 0;
}





//ð�������˼��
//�о����ԣ�ֻ��������������
//��չ���ܷ���sort��������������������
void sort(int arr[], int sz)
{
	int i = 0;
	//���Ҫ����
	for (i = 0; i < sz-1; i++)     //sz-1����Ϊ��Ԫ�ظ�����һ�˼���
	{
		//һ��ð������
		int j = 0;
		for (j = 0; j < sz-1-i; j++)
		{
			if (arr[j] > arr[j + 1])             //�˴�Ϊ�ȽϷ���
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
int main()
{
	int arr[] = { 1,5,8,9,3,6,7,4,2 };
	int sz = (sizeof(arr) / sizeof(arr[0]));
	sort(arr, sz); 
	print_arr(arr, sz);

	return 0;
}


//�ṹ������

//�ṹ�崴��
//struct_�ṹ����
//{};
//�ṹ�����ͣ�����int��float...
struct Stu
{
	char name[20];
	int age;
	//...
};
int main()
{
	int a = 0;
	struct Stu s = { {"ZhangSan", 20}, {"LiSi", 30}, {"WangWu", 15} };//�ṹ���ʼ��
	printf("%s %d\n", s.name, s.age);  //�ṹ��Ա���ʲ����� .   ����ǽṹ��������ұ��ǳ�Ա��

	struct Stu* ps = &s;//�ṹ��ָ��
	//���ʷ���2
	printf("%s %d\n", (*ps).name, (*ps).age);

	//���ʷ���2
	printf("%s %d\n", ps->name, ps->age)  //  -> �ṹ��Ա���ʲ�����   ��ʽ���ṹ��ָ��->��Ա��

	return 0;
}

//������㷨�ܶ࣬qsortʹ�õ��ǿ�������˼���������ݵ�
//����ð������ѡ�����򣬲�������ϣ������......