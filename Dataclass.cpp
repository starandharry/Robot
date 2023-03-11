#include<iostream>
#include<string>
#include<vector>
#include"Dataclass.h"
using namespace std;




//这里用来安放 自创的类
//例如工作台的位置和属性(出什么，收什么)
WorkPlace::WorkPlace(vector<double> loca,char cata) { //有参构造，就不写无参构造了
	this->loca = loca;
	produceDone = false;
	switch (cata) {
	case '1':
		{
			vector<int> buy = {};
			vector<int> sell = {1};
			int produceTime = 50;
			break;
		}
	case '2':
		{
			vector<int> buy = {};
			vector<int> sell = {2};
			int produceTime = 50;
			break;
		}
	case '3':
		{
			vector<int> buy = {};
			vector<int> sell = {3};
			int produceTime = 50;
			break;
		}
	case '4':
		{
			vector<int> buy = {1,2};
			vector<int> sell = {4};
			int produceTime = 500;
			break;
		}
	case '5':
		{
			vector<int> buy = {1,3};
			vector<int> sell = {5};
			int produceTime = 500;
			break;
		}
	case '6':
		{
			vector<int> buy = {2,3};
			vector<int> sell = {6};
			int produceTime = 500;
			break;
		}
	case '7':
		{
			vector<int> buy = {4,5,6};
			vector<int> sell = {7};
			int produceTime = 1000;
			break;
		}
	case '8':
		{
			vector<int> buy = {7};
			vector<int> sell = {};
			int produceTime = 1;
			break;
		}
	case '9':
		{
			vector<int> buy = {1,2,3,4,5,6,7};
			vector<int> sell = {};
			int produceTime = 1;
			break;
		}
	default:
		break;
	}
	this->buy = buy;
	this->sell = sell;
	this->produceTime = produceTime;
	materialReady.resize(buy.size());
}


//工作台组
void AllWorkPlaces::add_workers(WorkPlace w) {
	this->workers.push_back(w);
}




//机器人
Robot::Robot(vector<double> loca, double direction) {
	this->loca = loca;
	this->direction = direction;
	this->radius = 0.45;//没有载重时就是0.4，装了东西就0.53
	this->carry = -1;
	this->whichWorker = 0;
	this->ft = 0;
	this->fc = 0;
	this->va = 0;
	this->vl = 0;
}
void Robot::get_weight() {
	this->weight = 20 * 3.1415 * (this->radius * this->radius);
}

//机器人组
void AllRobots::add_robots(Robot bot) {
	this->robots.push_back(bot);
}

