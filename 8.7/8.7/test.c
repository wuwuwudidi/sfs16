#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h >
struct S
{
	int age;
};
//Init(struct S tmp)
//{
//	tmp.age;//s1 不变 形参不改变实参，是一份临时拷贝 把tmp 内容改了 不影响 s1
//}
void Init(struct S*  tmp)
{
	tmp->age=10;
}

//int main()
//{
//	struct S s1;
//	Init(&s1);//函数内部想改变函数外部的变量值的话 传地址  结构体传递参数尽量传地址
//	enum Day s = mon;
//	return 0;
//}
//位段 位端的成员类型是相同的 有int unsigned int signed int  short int  char
struct a
{
	int a : 2;//意思是占两个比特位  a就是一个位段类型  节省空间
	int b : 8;// 10 在32 内部
	
	//char c ：10 就越界了 char 是8
	//在vs 下  开辟字节 是从右向左放的 
}s;//sizeof（s）大小是 4个字节 

//枚举 可以一一列举的类型创建的变量  enum  
//枚举类型 的定义
enum Day
{// 枚举的 可能取值是常量 赋初始值 再改不了了
	mon,//0
	tues=2,//1 赋初始值 再改不了了
	sun = 4,//4
	fire//5
};
//枚举的优点	我们可以使用#define 定义常量，为什么非要使用枚举
//优点
//1 增加代码的可读性和可维护性
//2 和#define定义的标识符比较枚举有类型检查，更加严谨 
//3 为了防止命名污染（封装）
//4 便于调试
//5 使用方便 可以一次性定义多个常量

//联合（共用体） 这些成员共用同一块空间 
union un
{
	char a;	//&(un.a)取地址
	int c;
};//a 和 c是一块空间  un占 4个字节  
//a 和 c 不能同时 使用 

//判断当前计算机的大小端 
int  if_daixaoduan()
{
	//int a = 1;
	////返回1小端
	////返回0大端
 // return *(char*)&a;
	union un
	{
		int a;
		char c;
	}u;
	u.a = 1;
	return u.c;
}
int main()
{


	int ret = if_daixaoduan();
	if (ret == 1)
	{
		printf("xiaoduan\n");
	}
	else
		printf("daduan\n");


	return 0;

}
//enum 的大小 都是一些0 1 是整形 占4个字节