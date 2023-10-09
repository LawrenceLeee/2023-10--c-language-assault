#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


int main()
{
	int a = 10;
	int* p = &a;
	//a时整型变量，p是一级指针变量
	int** pp = &p;
	//pp也是指针变量，是二级指针变量,存放一级指针变量p的地址
	int*** ppp = &pp;

	printf("%d\n", **pp);
	return 0;
}


//指针数组模拟二维数组
int main()
{
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 2,3,4,5,6 };
	int arr3[] = { 3,4,5,6,7 };
	int* parr[3] = { arr1, arr2, arr3 };
	//数组名是数组首元素的地址
	//使用i遍历指针数组数组名，使用j遍历数组下标
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		int j = 0;
		for (j = 0; j < 5; j++)
		{
			printf("%d ", *(parr[i] + j));
			//printf("%d ", parr[i][j]);
			//parr[i]即为数组名后接下标访问操作符，继续访问一维数组下标
			//[]相当于解引用了，parr[i] == *(parr + i)
			//相当于*(*(parr+i)+j)
		}
		printf("\n");
	}

	return 0;
}


//字符指针变量
int main()
{
	char ch = 'a';
	const char* pc = &ch;//pc就是字符指针变量

	//字符指针变量是用来存放地址的
	char* p = "abcdefghi";//这个代码不是将"abcdefghi\0"存放到p中
	//表达式都有两个属性，一个是值属性，一个是类型属性
	//e.g. b=2+3  值属性：5  类型属性：int
	//上面代码中字符串的值属性是首字符a的地址，和数组非常相似
	printf("%c\n", *p);//验证可知，解引用打印a，上述代码将首字符a的地址存在p中
	//"abcdefghi\0"是一个常量字符串，是不能被修改的

	//p本质指向a，但字符串是连续的，所以可指向整个字符串，如下面代码
	printf("%s\n", p);  //abcdefghi

	return 0;
}


int main()
{
	char strl[] = "hello bit.";
	char str2[] = "hello bit.";
	const char* str3 = "hello bit.";
	const char* str4 = "hello bit.";
	if (strl == str2)
		printf("strl and str2 are same\n");
	else
		printf("strl and str2 are not same\n");
	if (str3 == str4)
		printf("str3 and str4 are same\n");
	else
		printf("str3 and str4 are not same\n");
	return 0;
}
//strl and str2 are not same
//str3 and str4 are same
//数组名是首元素地址，str1与str2是两个不同的数组，尽管存入的字符串内容相同，但首元素地址肯定不等
//而常量字符串不能被修改，一样的内容没必要保存两份，指针str3和str4指向一样的字符串，地址相同



//数组指针变量
//指针数组是数组，是存放指针的数组
//数组指针是指向数组的指针，存放的是数组的地址 
//int arr[10]; int(*p)[10] = &arr;  
//int* p[10] 是指针数组不正确
int main()
{
	int arr[6];
	int* p = arr;

	int(*ptr)[6] = &arr;

	char* ch[8];
	char* (*p2)[8] = &ch;   //数组指针p2指向数组ch，ch中有8个元素，元素类型为char*     去掉指针名为指针类型

	int arr[10];
	arr;//数组首元素地址,类型为  int*
	&arr;//数组的地址，类型为   int(*)[10]

	return 0;
}


int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int(*p)[10] = &arr;
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		//(*p)
		//(*&arr)
		//arr
		//上面三者相等
		printf("%d ", (*p)[i]);
	}
	//这么写很怪，不建议这么写

	return 0;
}


//二维数组传参的本质（数组指针的应用）
// 
//原来二维数组传参，实参写数组名，形参写二维数组
//传递过去的数组名表示首元素地址，形参部分可以写成指针接收
//二维数组每一行（一个一维数组）是一个元素
//那么二维数组的数组名表示数组首元素的地址，也就是第一行的地址，即一个一维数组的地址


//函数指针变量
//函数指针是指针，是指向函数的指针，是存放函数地址的指针

//函数地址？
int Add(int x, int y)
{
	return x + y;
}
int main()
{
	//数组名 - 数组首元素的地址
	//&数组名 - 数组的地址
	printf("%p\n", &Add);
	printf("%p\n", Add);
	//对于函数，&函数名和函数名都是函数的地址
	int (*pf)(int,int) = &Add;//第一个int是返回类型，pf是指针名，*表示是指针，括号内两个int表示两个参数名，括号内两参数int的名字可以不写，返回类型是void最开始写void
	int ret = (*pf)(3, 5);//后面()是函数调用操作符，内部传参，前面括号内解引用函数指针，调用函数
	//int ret = pf(3,5)
	ret = Add(3, 6);

	//调用函数，使用的函数名就是地址
	//而指针变量存储的就是函数的地址本身
	//因此是否解引用都可使用，直接写pf也可以，*可以省略
	//加*便于理解，但要写*一定要在括号内，否则pf直接作为函数地址进行调用操作，之后再解引用，err

	//int (*pf)(int, int)去掉指针名字int (*)(int,int)是函数指针类型

	printf("ret = %d\n", ret);//8

	return 0;
}



int main()
{
	//调用0地址处的函数，调用的函数无参，返回类型void	
	(*(void(*)()) 0)();
	//把0转换为函数指针变量，函数指针变量存的是函数的地址，所以地址0处此时存了一个无参的void函数
	//*对该地址（即指针，因为指针存的就是地址）进行解引用，调用这个void函数，无参所以跟一对空括号

	return 0;
}