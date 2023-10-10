#define _CRT_SECURE_NO_WARNINGS 1

//typedef int(*ptr_t)(int);
//typedef int(*arr_p)[5];

# include <stdio.h>
# include <stdlib.h>
# include <string.h>





int main()
{
	int x = 0, y = 0, z = 0;
	printf("请依次输入整数x, y, z的值，用空格隔开：");
	scanf("%d %d %d", &x, &y, &z);
	if (x < y && x < z)
	{
		printf("最小整数是x，值为x = %d\n", x);
		//更多语句写在这里
		//.......
	}
	else if (y < x && y < z)
		printf("最小整数是y，值为y = %d\n", y);
	else
		printf("最小整数是z，值为z = %d\n", z);

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





//函数指针数组
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
	int* arr[10];//整形指针的数组
	int(*p1)(int, int) = Add;
	int(*p2)(int, int) = Sub;

	//函数指针数组-存放函数指针
	int(* pArr[4] )(int, int) = { Add, Sub };

	return 0;
}





//函数指针用途，转移表
//实现加减乘除计算器
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
		printf("\n请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("请输入两个操作数");
			scanf("%d %d", &a, &b);
			ret = Add(a, b);
			printf("%d\n", ret);
			break;
		case 2:
			printf("请输入两个操作数");
			scanf("%d %d", &a, &b);
			ret = Sub(a, b);
			printf("%d\n", ret);
			break;
		case 3:
			printf("请输入两个操作数");
			scanf("%d %d", &a, &b);
			ret = Mul(a, b);
			printf("%d\n", ret);
			break;
		case 4:
			printf("请输入两个操作数");
			scanf("%d %d", &a, &b);
			ret = Div(a, b);
			printf("%d\n", ret);
			break;
		case 0:
		default:
			printf("\n选择错误，请重新选择：");
			break;
		}
	} while (input);
	return 0;
}










//上面写法代码过长

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
	//函数指针的数组
	//即转移表
	int(*pfArr[])(int, int) = { 0, Add, Sub, Mul, Div };  //使下标和选择对应

	int input = 0;
	int a = 0;
	int b = 0;
	int ret = 0;
	do
	{
		Menu();
		printf("\n请选择：");
		scanf("%d", &input);
		if (input >= 1 && input <= 4)
		{
			printf("请输入2个操作数：");
			scanf("%d %d", &a, &b);
			ret = pfArr[input](a, b);
			printf("%d\n", ret);
		}
		else if (input == 0)
		{
			printf("退出计算器\n");
			break;
		}
		else
		{
			printf("选择错误，请重新选择！\n");
		}
	} while (input);
	return 0;
}
//问题；参数返回值类型必须一样










//第一种计算器中，不同case后代码相似，仅调用函数不同，有些冗余

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

////把函数地址传参，用函数指针传参
////一个函数可以实现多个函数使用
void calc(int(*pf)(int, int))
{
	int a = 0;
	int b = 0;
	int ret = 0;

	printf("请输入2个操作数：");
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
		printf("\n请选择：");
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
			printf("\n选择错误，请重新选择：");
			break;
		}
	} while (input);
	return 0;
}







//回调函数   一个通过函数指针调用的函数



//库函数qsort,用来对数据进行排序，可以实现任何数据的排序
//qsort函数有4个参数
void qsort
(
    void* base,  //base指向待排序的第一个元素
    size_t num,   //num指待排序的元素个数
    size_t size,  //size是每个元素的大小有几个字节
    int (*compar)(const void*, const void*)   //compar是一个函数指针，指向的函数能够比较2个元素,即比较方法
);



//void* 是什么？
int main()
{
    int a = 10;
    int* p = &a;
    char* pc = &a;//int* 给 char* 不兼容

    void* pv = &a;//可行
    //通用指针类型，是无具体类型的指针
    //void*类型的指针变量，可以接受任意数据类型的地址
    
    //有一定问题
    pv + 1;      //err,不知道加几个字节
    *pv;         //err，不知道解引用访问几个字节
    //void*只是用来存放地址的
    return 0;
}









//测试qsort排序整型数组

//这个函数能比较e1，e2指向的两个元素，并给出返回值
int cmp_int(const void* e1, const void* e2)          //通过qsort使用，是回调函数
{
    //*e1 *e2        是void*，无法直接解引用
    return  *(int*)e1 - *(int*)e2;     //先强制类型转换即可
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
    print_arr(arr, sz);                              //排序前打印
    qsort(arr, sz, sizeof(arr[0]), cmp_int);
    print_arr(arr, sz);                              //排序后打印
}

//test2测试qsort函数排序结构体数据
struct Stu //学生
{
	char name[20];//名字
	int age;//年龄
};
//假设按照年龄比较
int cmp_stu_by_age(const void* e1, const void* e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}
//strcmp是库函数，专门用来比较两个字符串大小
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





//冒泡排序的思想
//有局限性，只能排序整形数组
//拓展：能否让sort函数排序任意类型数据
void sort(int arr[], int sz)
{
	int i = 0;
	//如果要升序
	for (i = 0; i < sz-1; i++)     //sz-1是因为比元素个数少一趟即可
	{
		//一趟冒泡排序
		int j = 0;
		for (j = 0; j < sz-1-i; j++)
		{
			if (arr[j] > arr[j + 1])             //此处为比较方法
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


//结构体类型

//结构体创建
//struct_结构体名
//{};
//结构体类型，类似int，float...
struct Stu
{
	char name[20];
	int age;
	//...
};
int main()
{
	int a = 0;
	struct Stu s = { {"ZhangSan", 20}, {"LiSi", 30}, {"WangWu", 15} };//结构体初始化
	printf("%s %d\n", s.name, s.age);  //结构成员访问操作符 .   左边是结构体变量，右边是成员名

	struct Stu* ps = &s;//结构体指针
	//访问方法2
	printf("%s %d\n", (*ps).name, (*ps).age);

	//访问方法2
	printf("%s %d\n", ps->name, ps->age)  //  -> 结构成员访问操作符   格式：结构体指针->成员名

	return 0;
}

//排序的算法很多，qsort使用的是快速排序思想排序数据的
//还有冒泡排序，选择排序，插入排序，希尔排序......