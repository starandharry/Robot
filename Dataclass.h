#pragma once
#include<iostream>
#include<string>
#include<vector>

using namespace std;

//����̨
class WorkPlace {
public:
	vector<double> loca;//����̨��λ��(�̶�)
	vector<int> buy;//����̨��ʲôԭ��(�̶�)
	vector<int> sell;//����̨��ʲô��������̨����ʲôԭ��(��������)  (�̶�)
	int produceTime;//�������ڣ�����ԭ������֮����Ҫ����ʱ�������������Ʒ  (�̶�)
	vector<int> materialReady;//ÿ��һ����Ʒ����Ӧ��һ����ȫ����֮��ʼ����
	bool produceDone;//����������������Ĳ�Ʒ�ڹ���̨�ϣ��������ߣ���0
	WorkPlace(vector<double> loca, char cata);
};

//����̨��
class AllWorkPlaces {
public:
	vector<WorkPlace> workers;
	void add_workers(WorkPlace w);
};






//������
class Robot {
public:
	vector<double> loca;//������λ�ã��ɱ仯
	int carry;//Я���Ķ�����ţ�û�о���-1
	double radius;//�����˵İ뾶,��������������ײ
	double weight;//���������������ƶ��� mv
	int whichWorker;//��������̨ ID��û�ڹ���̨��������-1
	double ft;//ʱ���ֵϵ��(����Я����Ʒ��Ϊ��ֵ)
	double fc;//��ײ��ֵϵ��(����Я����Ʒ��Ϊ��ֵ)
	double va;//���ٶȣ�ת���ٶ�(+˳ʱ�룬-��ʱ��)
	double vl;//���ٶȣ�ֱ���ٶ�
	double direction;//����[-pi,pi]�����������껹�Ǳ�׼���ꣿ
	//Ӧ���Ǳ�׼���꣬��ʾ���ڻ��������ģ��ź��ý��ٶȽ���ת��
	int worker_ind;//�������������ڵ�Ŀ�����ߵ��ĸ�����̨(��ţ����ǹ���̨���)


	Robot(vector<double> loca,double direction);//�����˺ܶ඼�ǿɱ�ģ����ֻ��Ҫ��ʼλ�úͶ���ʼ����
	void get_weight();//���»���������
};

//��������
class AllRobots {
public:
	vector<Robot> robots;
	void add_robots(Robot bot);
};






