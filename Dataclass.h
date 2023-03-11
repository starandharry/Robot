#pragma once
#include<iostream>
#include<string>
#include<vector>

using namespace std;

//工作台
class WorkPlace {
public:
	vector<double> loca;//工作台的位置(固定)
	vector<int> buy;//工作台收什么原料(固定)
	vector<int> sell;//工作台卖什么，即工作台生产什么原料(生产周期)  (固定)
	int produceTime;//工作周期，即当原料收齐之后需要多少时间才能生产出产品  (固定)
	vector<int> materialReady;//每收一样产品，对应加一，当全收齐之后开始生产
	bool produceDone;//完成生产且生产出的产品在工作台上；若被拿走，置0
	WorkPlace(vector<double> loca, char cata);
};

//工作台组
class AllWorkPlaces {
public:
	vector<WorkPlace> workers;
	void add_workers(WorkPlace w);
};






//机器人
class Robot {
public:
	vector<double> loca;//机器人位置，可变化
	int carry;//携带的东西标号，没有就是-1
	double radius;//机器人的半径,与其他机器人碰撞
	double weight;//机器人重量，估计动量 mv
	int whichWorker;//所处工作台 ID，没在工作台附近就是-1
	double ft;//时间价值系数(仅在携带物品是为正值)
	double fc;//碰撞价值系数(仅在携带物品是为正值)
	double va;//角速度，转弯速度(+顺时针，-逆时针)
	double vl;//线速度，直线速度
	double direction;//朝向，[-pi,pi]，是中心坐标还是标准坐标？
	//应该是标准坐标，表示现在机器朝向哪，才好用角速度进行转向
	int worker_ind;//表明机器人现在的目标是走到哪个工作台(序号，不是工作台类号)


	Robot(vector<double> loca,double direction);//机器人很多都是可变的，因此只需要初始位置和而初始朝向
	void get_weight();//更新机器人体重
};

//机器人组
class AllRobots {
public:
	vector<Robot> robots;
	void add_robots(Robot bot);
};






