//4.2类和对象
//实现时钟类，成员数据（私有）：时，分，秒；成员函数（公有）：设置时间，显示时间
#include<iostream>
using namespace std;
class Clock {
	private://如果不标明private,默认就是private的
		int hour, minute, second;
	public://通常数据是私有的，接口函数是公有的
		//这样既保证了数据的安全性，又能从外部合法访问到数据
		void showTime();//通常在类的定义中，只写成员函数的声明
		void showTime_Inner() {//如果类的内部，就完成了成员的函数定义，则默认为内联函数
			cout << hour << ':' << minute << ':' << second;
		}
		void setTime(int newH=0 , int newM=0, int newS=0);//函数的默认参数值，必须从右往左赋值
};
void Clock::setTime(int newH, int newM, int newS) {
	//在类外实现定义时，就要在成员函数前加上 返回值 类名::
	hour = newH;
	minute = newM;
	second = newS;
	}
inline void Clock:: showTime() {
	//如果要显示的声明内联，就在类外的定义前加上incline
	cout << hour << ':' << minute << ':' << second<<endl;
}

int main() {
	Clock myClock;
	myClock.setTime();
	myClock.showTime();//显示默认时间
	myClock.setTime(22,0,3);
	myClock.showTime();
}