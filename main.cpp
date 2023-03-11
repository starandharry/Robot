#include <iostream>
#include<algorithm>
#include<string>
#include"Dataclass.h"
#include"utils.h"
using namespace std;

pair<AllWorkPlaces, AllRobots> readUntilOK_init() {
    char line[1024];
    int x = 1;
    string workers_indexs = "123456789";
    AllWorkPlaces w;
    AllRobots b;
    while (fgets(line, sizeof line, stdin)) {
        if (line[0] == 'O' && line[1] == 'K') {
            return make_pair(w,b);
        }
        //do something
        //这里先初始化，第一次读
        int y = 0;
        while (line[y] != 'EOF') {
            if (workers_indexs.find(line[y]) != -1) {
                WorkPlace w1(vector<double>({ x - 0.5,y + 0.5 }), line[y]);//创建工作台类
                w.add_workers(w1);
            }
            if (line[y] == 'A') {
                Robot r(vector<double>({ x - 0.5,y + 0.5 }), 0);//初始朝向都朝上好了
                b.add_robots(r);
            }
            y++;
        }
    }
    exit(0);
}


bool readUntilOK(pair<AllWorkPlaces, AllRobots>& info) {
    char line[1024];
    int x = 0;
    while (fgets(line, sizeof line, stdin)) {
        if (line[0] == 'O' && line[1] == 'K') {
            return true;
        }
        //do something
        //line是读取到的当前地图上的状态，标准输入格式

        int y = 0;
        while (line[y] != 'EOF') {
            
        }


    }
    return false;
}


int main() {
    pair<AllWorkPlaces, AllRobots> info = readUntilOK_init();//读地图，没接收输入
    puts("OK");
    fflush(stdout);//输出ok
    int frameID;
    while (scanf("%d", &frameID) != EOF) {
        readUntilOK(info);//刷新数据
        printf("%d\n", frameID);
        int lineSpeed = 3;
        double angleSpeed = 1.5;
        for(int robotId = 0; robotId < 4; robotId++){
            printf("forward %d %d\n", robotId, lineSpeed);
            printf("rotate %d %f\n", robotId, angleSpeed);
        }
        printf("OK\n", frameID);
        fflush(stdout);//printf的东西都在缓存区，fflush(stdout)可以把缓冲区的东西输出
    }
    return 0;
}
