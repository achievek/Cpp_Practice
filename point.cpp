//4-3���캯������������
#include<iostream>
using namespace std;

class Point {
public:
	Point(int xx,int yy) {//���캯��ͨ������Ϊpublic
		x = xx;
		y = yy;
	}
	~Point(){}
	Point(Point& p);//���ƹ��캯��
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

void fun1(Point p) {//���������Ͳ�Ϊ����Ķ���ʱ���ͻ������ĸ��ƹ��캯��
	cout<< p.getX()<<endl;
}

Point fun2() {
	Point a(1, 2);
	return a;//�������ķ���ֵΪ��Ķ���ʱ���ͻ������ĸ��ƹ��캯��
}

int main() {
	Point p1(4,5);//���캯���������������ͱ��봫��
	Point p2 = p1;//�˴�����ø��ƹ��캯��
	cout << p2.getX() << endl;
	fun1(p1);//�˴�����ø��ƹ��캯��
	p2 = fun2();
	cout << p2.getX() << endl;//�˴�����ø��ƹ��캯��

}