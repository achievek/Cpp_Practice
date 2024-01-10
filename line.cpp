//4.4������
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
	Point p1, p2;//Point������Line��ĳ�Ա����
	double len;
};

Line::Line(Point pa, Point pb):p1(pa),p2(pb) {//����ͨ����ʼ���б�ķ�ʽ���ⲿ����й���
	//��ͨ����ʼ���б�ķ�ʽ���ڲ������ͨ�����ƹ��캯�����г�ʼ��
	cout << "calling the constructor of Line" << endl;
	double x = static_cast<double>(p1.getX() - p2.getX());
	double y = static_cast<double>(p1.getY() - p2.getY());
	len = sqrt(x * x + y * y);
}

Line::Line(Line& l) {
	//����ͨ����ʼ���б�ķ�ʽ���й��죬��ô��ִ�и���Ƕ�����Ĭ�Ϲ��캯��
	//p1 = l.p1; ������Ƕ����Ҫô��ʼ���б��죬Ҫô����Ĭ�Ϲ��캯��
	//�����Ƕ��û��Ĭ�Ϲ��캯�����ᱨ�����߹��캯���Ĳ�������Ĭ�ϲ���
	len = l.len;
}

int main() {
	Point mp1(1, 1), mp2(2, 2);
	Line mLine(mp1, mp2);//���ȵ������θ��ƹ��캯��,����ʵ�εĸ���
	//�ڹ��캯���ڲ����ֻ�ͨ����ʼ���б�������θ��ƹ��캯��
	Line mline2(mLine);
	return 0;
}