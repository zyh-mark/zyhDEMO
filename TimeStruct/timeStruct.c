#include <stdio.h>
#pragma warning(disable:4996)

//func：计算时间差
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
//	printf("输入两个时间值，以XX:XX:XX的格式\n");
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
//	printf("时间差是%d小时%d分%d秒\n", t3.hour, t3.min, t3.sec);
//	return 0;
//}


//时间的结构体设计
//时间的结构体和函数设计比起日期要简单一些，因为不用考虑每个月份不同和闰年的关系，统一每天都是24小时，每小时60分钟，每分钟60秒，程序写起来要轻松得多，保持对数字的敏感性就好。
struct time    //结构体
{
	int hour;
	int minute;
	int second;
};
int main()
{
	int hours, minutes, seconds, day = 1;
	struct time formal, change, end;
	printf("请输入开始时间\n时：");    //获取小时
	scanf("%d", &formal.hour);
	printf("分：");                   //分钟
	scanf("%d", &formal.minute);
	printf("秒：");                   //秒
	scanf("%d", &formal.second);
	//判断时间的输入是否符合常识
	if (formal.second > 59 || formal.minute > 59 || formal.hour > 23)
	{
		printf("输入时间错误\n");
		return 1;
	}
	printf("请输入经过时间\n时: ");    //经过时间
	scanf("%d", &change.hour);
	printf("分：");
	scanf("%d", &change.minute);
	printf("秒：");
	scanf("%d", &change.second);
	if (formal.second > 59 || formal.minute > 59)
	{
		printf("输入时间错误\n");
		return 1;
	}

	seconds = formal.second + change.second;      //计算秒
	while (seconds >= 60)         //这种写：1、不需要理会经过时间的范围   2、如果用%还要考虑0 的情况
	{
		seconds = seconds - 60;
		change.minute++;        //满60s，加一分钟
	}
	end.second = seconds;
	minutes = formal.minute + change.minute;      //计算分钟
	while (minutes >= 60)
	{
		minutes = minutes - 60;
		change.hour++;            //满60min，加一小时
	}
	end.minute = minutes;
	hours = formal.hour + change.hour;            //计算分钟
	while (hours >= 24)
	{
		hours = hours - 24;                   //满24h，重新计数
		day++;

	}
	end.hour = hours;
	printf("变化后的时间是第%d天的%d:%d:%d\n", day, end.hour, end.minute, end.second);           //输出最终时间
	return 0;
}


//日期的结构体设计
//在设计日期时，需要注意的是每个月份的日期是不同的，而且由于闰年的原因，不同年份的日期也是不同的，这也是设计函数的难点所在。
//
//#include<stdio.h>
//struct date   //结构体
//{
//	int year;
//	int month;
//	int day;
//};
//
//int daysofmonth(int month, int year);     //函数：每个月的天数，以及判断是否为闰年
//
//int main()
//{
//	int changedays;
//	int yearss, monthss, dayss;
//	struct date formal, end;
//	printf("请输入开始时间\n年：");                 //输入开始年
//	scanf("%d", &formal.year);
//	printf("月：");                                  //月
//	scanf("%d", &formal.month);
//	printf("日：");                                 //日
//	scanf("%d", &formal.day);
//	if (formal.month > 12 || formal.day > daysofmonth(formal.month, formal.year))
//	{
//		printf("日期输入错误\n");
//		return 1;
//	}
//	printf("请输入经过的天数: ");                   //经过天数
//	scanf("%d", &changedays);
//
//	yearss = formal.year;                          //计算日期
//	monthss = formal.month;
//	dayss = changedays + formal.day;
//	while (dayss > daysofmonth(monthss, yearss))          //若天数超过该月天数，
//	{
//		dayss = dayss - daysofmonth(monthss, yearss);    //天数重计，月份加一
//		monthss++;
//		if (monthss > 12)                                 //若月份超过12个月，
//		{
//			monthss = monthss - 12;                       //月份重计，年份加一
//			yearss++;
//		}
//	}
//	end.year = yearss;
//	end.month = monthss;
//	end.day = dayss;
//	printf("%d--%d--%d\n", end.year, end.month, end.day);    //输出最终日期
//	return 0;
//}
//
//
//int daysofmonth(int month, int year)         //函数：每个月的天数，以及判断是否为闰年
//{
//	int days;
//	switch (month)
//	{
//	case 1:               //1、3、5、7、8、10、12月是31天
//	case 3:
//	case 5:
//	case 7:
//	case 8:
//	case 10:
//	case 12:
//		days = 31;
//		break;
//	case 4:            //4、6、9、11月是30天
//	case 6:
//	case 9:
//	case 11:
//		days = 30;
//		break;
//	case 2:             //2月闰年29天，非闰年28天
//		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//			days = 29;
//		else
//			days = 28;
//	}
//	return days;
//}
//————————————————
//版权声明：本文为CSDN博主「Lurejahor」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
//原文链接：https://blog.csdn.net/qq_43644205/article/details/94736264