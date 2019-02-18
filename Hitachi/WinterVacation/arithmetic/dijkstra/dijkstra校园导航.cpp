#include "pch.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stack>
#define SIZE 14
#define INTMAX 10000
#define SCALE 30
using namespace std;

class Dijkstra
{
public:
	//设置当前地点
	void SetV(int v)
	{
		this->vn = v;
		for (int i = 0; i < dis[vn].size(); i++)
		{
			vector<int> temp;
			temp.push_back(dis[vn][i]);
			vinfo.push_back(temp);
		}
		s.push_back(vn);
		for (int i = 0; i < SIZE; i++)
		{
			if (i != vn)
			{
				u.push_back(i);
			}
		}
		update(vn);
	}
	void GoV(int gv)
	{
		this->gv = gv;

	}
	//输出路径信息
	void OutMinVia()
	{
		int total = 0;
		//查找路径信息时，例如到点8，vinfo里看到点7离点8最近，那么再看里点8最近的点......直到最近的点是0(即起点)
		//由于上述过程，是逆向查看的，所以使用栈，将数据存到一起，然后再读取出来输出
		stack<int> sta;
		int n = gv;
		sta.push(gv);
		while (1)
		{
			if (vinfo[n].size() - 1 == 0)
			{
				sta.push(0);
				break;
			}
			sta.push(vinfo[n][vinfo[n].size()-1]);
			n = vinfo[n][vinfo[n].size() - 1];
		}
		int pre = 0; sta.pop();
		while (!sta.empty())
		{
			int a = sta.top();
			sta.pop();
			cout << vs[pre] << "=======》" << vs[a] << '(' << dis[pre][a]/SCALE << "米" <<')' << endl;
			total += (dis[pre][a] / SCALE);
			pre = a;
		}
		cout << "从" << vs[vn] << "到" << vs[gv] << "最短距离为" << total << "米" << endl;
	}
	//构造函数
	Dijkstra(const char **v,int vnum ,int dist[][3], int dnum)
	{
		//通过键值对储存点的信息,使编码和地点名称一一对应
		map<int, string> vs;
		for (int i = 0; i < vnum; i++)
		{
			vs[i] = v[i];
		}
		//将所有点之间距离初始化(地点到达自己的距离为0，到达其它点的距离为特别大的值，方便比较)
		int dis[SIZE][SIZE];
		for (int i = 0; i < SIZE; i++)
			for (int j = 0; j < SIZE; j++)
				if (i == j)
					dis[i][j] = 0;
				else
					dis[i][j] = INTMAX;
		//将距离信息写到邻接矩阵中
		for (int i = 0; i < 16; i++)
		{
			dis[dist[i][0]][dist[i][1]] = dist[i][2];
			dis[dist[i][1]][dist[i][0]] = dist[i][2];
		}
		//把二维数组写进vector里，方便赋值(懒得new一个新的二维数组，还得手动释放真不舒服)
		vector<vector<int>> di;
		for (int i = 0; i < SIZE; i++)
		{
			vector<int> d(dis[i], dis[i] + SIZE);
			di.push_back(d);
		}
		this->vs = vs;
		this->dis = di;
	}
private:
	//在dis里选择点vn对应的那一行，对应的是起点到各个地点的距离,最后一个维度：[0]用来储存到其他点的最小距离然后，最后一个元素是到这个点最近的点(有瑕疵，可优化，懒得弄了)
	vector<vector<int>> vinfo;
	map<int, string> vs;
	vector<vector<int>> dis;
	//已经确定的点集合
	vector<int> s;
	//还没确定的点的集合
	vector<int> u;
	//起点
	int vn;
	//终点
	int gv;
	//对vinfo更新，递归寻找最小距离
	void update(int v)
	{
		if (u.size() > 0)
		{
			for (int i = 0; i < SIZE; i++)
			{
				//如果有中转点比vn到i更近，那么久将dis[vn][i更新]，顺便带上vinfo(可以优化)
				//然后把中转点添加到vinfo最后
				if (dis[vn][i] > dis[vn][v] + dis[v][i])
				{
					dis[vn][i] = dis[vn][v] + dis[v][i];
					vinfo[i][0] = dis[vn][i]; 
					vinfo[i].push_back(v);
				}
			}
			int min = FindMin(v);
			update(min);
		}
	}
	//寻找离v最近的点
	int FindMin(int v)
	{
		int min = 0;
		for (int i = 0; i < u.size(); i++)
		{
			if (dis[v][u[i]] < dis[v][u[min]])
			{
				min = i;
			}
				
		}
		//怕一会删除了访问不到
		int bak = u[min];
		//将点加到s里，从u里删除
		s.push_back(u[min]);
		u.erase(u.begin()+min,u.begin() + min+1);
		return bak;
	}
};
int main()
{	//地点名
	const char *v[SIZE] = { "学生公寓二舍","学生公寓三舍","新楼","南研楼","食堂",
		"空草地","篮球场","体育馆","学生公寓一舍","科技大厦","华苑宾馆","二舍去往南研楼方向的路口","篮球场旁十字路口","南研楼对面的小桥" };
	//点之间的距离，[点1，点2，距离]
	int dist[16][3] = { {0,11,450},{1,11,782},{2,11,923},{3,11,520},{11,13,600},
	{3,4,791},{4,13,820},{11,6,517},{6,12,378}, {4,5,554},{5,8,977},{13,9,720},
	{7,12,370},{12,10,637},{12,9,536},{1,9,1110} };
	
	//第一个参数，char **类型，是一个c串的数组，用来储存地点的名字，第二个参数是字符串的数量(第二维数)
	//第三个参数，int[][]类型，用来表示两个点之间的距离的数组，例如{1,11,200}表示从1到11的距离是200，第四个参数是边数(第二维数)
	Dijkstra dij(v,SIZE,dist,16);
	//设置起点
	dij.SetV(0);
	//设置终点
	dij.GoV(8);
	//输出最短路径信息
	dij.OutMinVia();
}
