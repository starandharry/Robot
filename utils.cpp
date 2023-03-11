#include<iostream>
#include<string>
#include"Dataclass.h"
#include"utils.h"
#include "math.h"
using namespace std;


//此文件主要写一些辅助函数
//例如计算两点之间的距离

//double cal_distance_robot2worker(Robot bot, WorkPlace worker) {
//	vector<double> loca_b = bot.loca;
//	vector<double> loca_w = worker.loca;
//	double distance = sqrt((loca_b[0] - loca_w[0]) * (loca_b[0] - loca_w[0]) + (loca_b[1] - loca_w[1]) * (loca_b[1] - loca_w[1]));
//	double angle;
//	if (loca_b[0] - loca_w[0] == 0) angle = loca_b[1] < loca_w[1] ? -bot.direction : (3.1415 - bot.direction);
//	else if (loca_b[1] - loca_w[1] == 0) angle = loca_b[0] < loca_w[0] ? (3.1415/2.0+bot.direction) : (3.1415 / 2.0 - bot.direction);
//	else angle = atan2((loca_b[0] - loca_w[0]), (loca_w[1] - loca_b[1]));//弧度
//	//是一帧转过来，或者几帧转过来，直到朝向与angle对齐
//	//注意这里是弧度每秒，不是弧度每帧
//	//其实就可以设置为一秒转到正确朝向，但是可能需要每一帧每一帧的重新计算和确认
//	if (bot.direction - angle < 1e-3) {//表明机器人朝向正确，不用转向了
//		
//	}
//	else {
//		double va = angle;
//		bot.va = va;//目前只考虑转向，线速度当作匀速
//	}
//	
//
//
//}


double cal_distance_2points(vector<double> p1,vector<double>p2) {

}


double cal_angle_2points(vector<double> p1, vector<double>p2) {

}




//假定已经确定robot1要去工作台1，
//线速度[-2,6]m/s，角速度[0,3]rad/s
//假设尽量以最大的速度去完成动作
//计算最大收益
double eval_profit(Robot r, WorkPlace w,int frame) {//大致估计从机器人1到工作台1所需要的时间和损失
	double d = cal_distance_2points(r.loca,w.loca);//距离
	double a = cal_angle_2points(r.loca, w.loca);//角度
	//假定全都正着走，以6m/s
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












