#include <stdio.h>
#pragma warning(disable:4996)

//func������ʱ���
//typedef struct Mytime
//{
//	int hour;
//	int min;
//	int sec;
//}T;
//int main(int argc, char* argv[])
//{
//	T t1, t2, t3;
//	int sec1, sec2, sec3;
//	printf("��������ʱ��ֵ����XX:XX:XX�ĸ�ʽ\n");
//	scanf("%d:%d:%d", &t1.hour, &t1.min, &t1.sec);
//	scanf("%d:%d:%d", &t2.hour, &t2.min, &t2.sec);
//	sec1 = t1.hour * 3600 + t1.min * 60 + t1.sec;
//	sec2 = t2.hour * 3600 + t2.min * 60 + t2.sec;
//	if (sec1 >= sec2)
//		sec3 = sec1 - sec2;
//	else
//		sec3 = sec2 - sec1;
//	t3.hour = sec3 / 3600;
//	sec3 %= 3600;
//	t3.min = sec3 / 60;
//	t3.sec = sec3 % 60;
//	printf("ʱ�����%dСʱ%d��%d��\n", t3.hour, t3.min, t3.sec);
//	return 0;
//}


//ʱ��Ľṹ�����
//ʱ��Ľṹ��ͺ�����Ʊ�������Ҫ��һЩ����Ϊ���ÿ���ÿ���·ݲ�ͬ������Ĺ�ϵ��ͳһÿ�춼��24Сʱ��ÿСʱ60���ӣ�ÿ����60�룬����д����Ҫ���ɵö࣬���ֶ����ֵ������Ծͺá�
struct time    //�ṹ��
{
	int hour;
	int minute;
	int second;
};
int main()
{
	int hours, minutes, seconds, day = 1;
	struct time formal, change, end;
	printf("�����뿪ʼʱ��\nʱ��");    //��ȡСʱ
	scanf("%d", &formal.hour);
	printf("�֣�");                   //����
	scanf("%d", &formal.minute);
	printf("�룺");                   //��
	scanf("%d", &formal.second);
	//�ж�ʱ��������Ƿ���ϳ�ʶ
	if (formal.second > 59 || formal.minute > 59 || formal.hour > 23)
	{
		printf("����ʱ�����\n");
		return 1;
	}
	printf("�����뾭��ʱ��\nʱ: ");    //����ʱ��
	scanf("%d", &change.hour);
	printf("�֣�");
	scanf("%d", &change.minute);
	printf("�룺");
	scanf("%d", &change.second);
	if (formal.second > 59 || formal.minute > 59)
	{
		printf("����ʱ�����\n");
		return 1;
	}

	seconds = formal.second + change.second;      //������
	while (seconds >= 60)         //����д��1������Ҫ��ᾭ��ʱ��ķ�Χ   2�������%��Ҫ����0 �����
	{
		seconds = seconds - 60;
		change.minute++;        //��60s����һ����
	}
	end.second = seconds;
	minutes = formal.minute + change.minute;      //�������
	while (minutes >= 60)
	{
		minutes = minutes - 60;
		change.hour++;            //��60min����һСʱ
	}
	end.minute = minutes;
	hours = formal.hour + change.hour;            //�������
	while (hours >= 24)
	{
		hours = hours - 24;                   //��24h�����¼���
		day++;

	}
	end.hour = hours;
	printf("�仯���ʱ���ǵ�%d���%d:%d:%d\n", day, end.hour, end.minute, end.second);           //�������ʱ��
	return 0;
}


//���ڵĽṹ�����
//���������ʱ����Ҫע�����ÿ���·ݵ������ǲ�ͬ�ģ��������������ԭ�򣬲�ͬ��ݵ�����Ҳ�ǲ�ͬ�ģ���Ҳ����ƺ������ѵ����ڡ�
//
//#include<stdio.h>
//struct date   //�ṹ��
//{
//	int year;
//	int month;
//	int day;
//};
//
//int daysofmonth(int month, int year);     //������ÿ���µ��������Լ��ж��Ƿ�Ϊ����
//
//int main()
//{
//	int changedays;
//	int yearss, monthss, dayss;
//	struct date formal, end;
//	printf("�����뿪ʼʱ��\n�꣺");                 //���뿪ʼ��
//	scanf("%d", &formal.year);
//	printf("�£�");                                  //��
//	scanf("%d", &formal.month);
//	printf("�գ�");                                 //��
//	scanf("%d", &formal.day);
//	if (formal.month > 12 || formal.day > daysofmonth(formal.month, formal.year))
//	{
//		printf("�����������\n");
//		return 1;
//	}
//	printf("�����뾭��������: ");                   //��������
//	scanf("%d", &changedays);
//
//	yearss = formal.year;                          //��������
//	monthss = formal.month;
//	dayss = changedays + formal.day;
//	while (dayss > daysofmonth(monthss, yearss))          //��������������������
//	{
//		dayss = dayss - daysofmonth(monthss, yearss);    //�����ؼƣ��·ݼ�һ
//		monthss++;
//		if (monthss > 12)                                 //���·ݳ���12���£�
//		{
//			monthss = monthss - 12;                       //�·��ؼƣ���ݼ�һ
//			yearss++;
//		}
//	}
//	end.year = yearss;
//	end.month = monthss;
//	end.day = dayss;
//	printf("%d--%d--%d\n", end.year, end.month, end.day);    //�����������
//	return 0;
//}
//
//
//int daysofmonth(int month, int year)         //������ÿ���µ��������Լ��ж��Ƿ�Ϊ����
//{
//	int days;
//	switch (month)
//	{
//	case 1:               //1��3��5��7��8��10��12����31��
//	case 3:
//	case 5:
//	case 7:
//	case 8:
//	case 10:
//	case 12:
//		days = 31;
//		break;
//	case 4:            //4��6��9��11����30��
//	case 6:
//	case 9:
//	case 11:
//		days = 30;
//		break;
//	case 2:             //2������29�죬������28��
//		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//			days = 29;
//		else
//			days = 28;
//	}
//	return days;
//}
//��������������������������������
//��Ȩ����������ΪCSDN������Lurejahor����ԭ�����£���ѭCC 4.0 BY-SA��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
//ԭ�����ӣ�https://blog.csdn.net/qq_43644205/article/details/94736264