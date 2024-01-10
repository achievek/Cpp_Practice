//4.4类的组合
#include<iostream>
using namespace std;
class Point {
public:
	Point(int xx=0, int yy=0) {
		x = xx;
		y = yy;
	}
	Point(Point& p);
	int getX() { return x; }
	int getY() { return y; }
private:int x, y;
};

Point::Point(Point& p) {
	x = p.x;
	y = p.y;
	cout << "calling the copy constructor of Point" << endl;
}

class Line {
public:
	Line(Point p1, Point p2);
	Line(Line& l);
	double getLen() { return len; }
private:
	Point p1, p2;//Point对象是Line类的成员变量
	double len;
};

Line::Line(Point pa, Point pb):p1(pa),p2(pb) {//可以通过初始化列表的方式对外部类进行构造
	//若通过初始化列表的方式，内部类对象将通过复制构造函数进行初始化
	cout << "calling the constructor of Line" << endl;
	double x = static_cast<double>(p1.getX() - p2.getX());
	double y = static_cast<double>(p1.getY() - p2.getY());
	len = sqrt(x * x + y * y);
}

Line::Line(Line& l) {
	//若不通过初始化列表的方式进行构造，那么将执行该内嵌对象的默认构造函数
	//p1 = l.p1; 错误，内嵌对象要么初始化列表构造，要么调用默认构造函数
	//如果内嵌类没有默认构造函数将会报错，或者构造函数的参数均有默认参数
	len = l.len;
}

int main() {
	Point mp1(1, 1), mp2(2, 2);
	Line mLine(mp1, mp2);//会先调用两次复制构造函数,复制实参的副本
	//在构造函数内部，又会通过初始化列表调用两次复制构造函数
	Line mline2(mLine);
	return 0;
}