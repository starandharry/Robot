#include<iostream>
#include<string>
#include"Dataclass.h"
#include"utils.h"
#include "math.h"
using namespace std;


//���ļ���ҪдһЩ��������
//�����������֮��ľ���

//double cal_distance_robot2worker(Robot bot, WorkPlace worker) {
//	vector<double> loca_b = bot.loca;
//	vector<double> loca_w = worker.loca;
//	double distance = sqrt((loca_b[0] - loca_w[0]) * (loca_b[0] - loca_w[0]) + (loca_b[1] - loca_w[1]) * (loca_b[1] - loca_w[1]));
//	double angle;
//	if (loca_b[0] - loca_w[0] == 0) angle = loca_b[1] < loca_w[1] ? -bot.direction : (3.1415 - bot.direction);
//	else if (loca_b[1] - loca_w[1] == 0) angle = loca_b[0] < loca_w[0] ? (3.1415/2.0+bot.direction) : (3.1415 / 2.0 - bot.direction);
//	else angle = atan2((loca_b[0] - loca_w[0]), (loca_w[1] - loca_b[1]));//����
//	//��һ֡ת���������߼�֡ת������ֱ��������angle����
//	//ע�������ǻ���ÿ�룬���ǻ���ÿ֡
//	//��ʵ�Ϳ�������Ϊһ��ת����ȷ���򣬵��ǿ�����Ҫÿһ֡ÿһ֡�����¼����ȷ��
//	if (bot.direction - angle < 1e-3) {//���������˳�����ȷ������ת����
//		
//	}
//	else {
//		double va = angle;
//		bot.va = va;//Ŀǰֻ����ת�����ٶȵ�������
//	}
//	
//
//
//}


double cal_distance_2points(vector<double> p1,vector<double>p2) {

}


double cal_angle_2points(vector<double> p1, vector<double>p2) {

}




//�ٶ��Ѿ�ȷ��robot1Ҫȥ����̨1��
//���ٶ�[-2,6]m/s�����ٶ�[0,3]rad/s
//���辡���������ٶ�ȥ��ɶ���
//�����������
double eval_profit(Robot r, WorkPlace w,int frame) {//���¹��ƴӻ�����1������̨1����Ҫ��ʱ�����ʧ
	double d = cal_distance_2points(r.loca,w.loca);//����
	double a = cal_angle_2points(r.loca, w.loca);//�Ƕ�
	//�ٶ�ȫ�������ߣ���6m/s
	double time;
	if (abs(r.direction - a) <  3.1415926) {
		time = (abs(r.direction - a)) / 3 + d / 6;
	}
	else {
		time = (2*3.1415926-abs(r.direction - a)) / 3 + d / 6;
	}
	time = time / 20 + frame;
	double mv = r.weight * 6;
	double price_weight = 1 - 0.2 * sqrt(mv / 500) + 0.2 * sqrt(time / 4500);

	return price_weight;
}












