//4.2��Ͷ���
//ʵ��ʱ���࣬��Ա���ݣ�˽�У���ʱ���֣��룻��Ա���������У�������ʱ�䣬��ʾʱ��
#include<iostream>
using namespace std;
class Clock {
	private://���������private,Ĭ�Ͼ���private��
		int hour, minute, second;
	public://ͨ��������˽�еģ��ӿں����ǹ��е�
		//�����ȱ�֤�����ݵİ�ȫ�ԣ����ܴ��ⲿ�Ϸ����ʵ�����
		void showTime();//ͨ������Ķ����У�ֻд��Ա����������
		void showTime_Inner() {//�������ڲ���������˳�Ա�ĺ������壬��Ĭ��Ϊ��������
			cout << hour << ':' << minute << ':' << second;
		}
		void setTime(int newH=0 , int newM=0, int newS=0);//������Ĭ�ϲ���ֵ�������������ֵ
};
void Clock::setTime(int newH, int newM, int newS) {
	//������ʵ�ֶ���ʱ����Ҫ�ڳ�Ա����ǰ���� ����ֵ ����::
	hour = newH;
	minute = newM;
	second = newS;
	}
inline void Clock:: showTime() {
	//���Ҫ��ʾ��������������������Ķ���ǰ����incline
	cout << hour << ':' << minute << ':' << second<<endl;
}

int main() {
	Clock myClock;
	myClock.setTime();
	myClock.showTime();//��ʾĬ��ʱ��
	myClock.setTime(22,0,3);
	myClock.showTime();
}