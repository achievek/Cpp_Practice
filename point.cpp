//4-3构造函数和析构函数
#include<iostream>
using namespace std;

class Point {
public:
	Point(int xx,int yy) {//构造函数通常声明为public
		x = xx;
		y = yy;
	}
	~Point(){}
	Point(Point& p);//复制构造函数
	int getX(){
		return x;
	}
	int getY() {
		return y;
	}
private:
	int x, y;
};

Point::Point(Point& p) {
	x = p.x;
	y = p.y;
	cout << "calling the copy constructor" << endl;
}

void fun1(Point p) {//当函数的型参为该类的对象时，就会调用类的复制构造函数
	cout<< p.getX()<<endl;
}

Point fun2() {
	Point a(1, 2);
	return a;//当函数的返回值为类的对象时，就会调用类的复制构造函数
}

int main() {
	Point p1(4,5);//构造函数有两个参数，就必须传入
	Point p2 = p1;//此处会调用复制构造函数
	cout << p2.getX() << endl;
	fun1(p1);//此处会调用复制构造函数
	p2 = fun2();
	cout << p2.getX() << endl;//此处会调用复制构造函数

}