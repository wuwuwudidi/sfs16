#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h >
struct S
{
	int age;
};
//Init(struct S tmp)
//{
//	tmp.age;//s1 ���� �ββ��ı�ʵ�Σ���һ����ʱ���� ��tmp ���ݸ��� ��Ӱ�� s1
//}
void Init(struct S*  tmp)
{
	tmp->age=10;
}

//int main()
//{
//	struct S s1;
//	Init(&s1);//�����ڲ���ı亯���ⲿ�ı���ֵ�Ļ� ����ַ  �ṹ�崫�ݲ�����������ַ
//	enum Day s = mon;
//	return 0;
//}
//λ�� λ�˵ĳ�Ա��������ͬ�� ��int unsigned int signed int  short int  char
struct a
{
	int a : 2;//��˼��ռ��������λ  a����һ��λ������  ��ʡ�ռ�
	int b : 8;// 10 ��32 �ڲ�
	
	//char c ��10 ��Խ���� char ��8
	//��vs ��  �����ֽ� �Ǵ�������ŵ� 
}s;//sizeof��s����С�� 4���ֽ� 

//ö�� ����һһ�оٵ����ʹ����ı���  enum  
//ö������ �Ķ���
enum Day
{// ö�ٵ� ����ȡֵ�ǳ��� ����ʼֵ �ٸĲ�����
	mon,//0
	tues=2,//1 ����ʼֵ �ٸĲ�����
	sun = 4,//4
	fire//5
};
//ö�ٵ��ŵ�	���ǿ���ʹ��#define ���峣����Ϊʲô��Ҫʹ��ö��
//�ŵ�
//1 ���Ӵ���Ŀɶ��ԺͿ�ά����
//2 ��#define����ı�ʶ���Ƚ�ö�������ͼ�飬�����Ͻ� 
//3 Ϊ�˷�ֹ������Ⱦ����װ��
//4 ���ڵ���
//5 ʹ�÷��� ����һ���Զ���������

//���ϣ������壩 ��Щ��Ա����ͬһ��ռ� 
union un
{
	char a;	//&(un.a)ȡ��ַ
	int c;
};//a �� c��һ��ռ�  unռ 4���ֽ�  
//a �� c ����ͬʱ ʹ�� 

//�жϵ�ǰ������Ĵ�С�� 
int  if_daixaoduan()
{
	//int a = 1;
	////����1С��
	////����0���
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
//enum �Ĵ�С ����һЩ0 1 ������ ռ4���ֽ�