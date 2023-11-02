#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;
#include <thread>
#include <windows.h>

void CreateGraph_1()
{
	struct Vertex
	{
		vector<Vertex*> edges;
		//int data;
	};
	
	vector<Vertex> v;
	v.resize(6);

	v[0].edges.push_back(&v[1]);
	v[0].edges.push_back(&v[3]);
	v[1].edges.push_back(&v[0]);
	v[1].edges.push_back(&v[2]);
	v[1].edges.push_back(&v[3]);
	v[3].edges.push_back(&v[4]);
	v[5].edges.push_back(&v[4]);

	// Q) 0번 -> 3번 정점이 연결되어 있나요?
	bool connected = false;
	for (Vertex* edge : v[0].edges)
	{
		if (edge == &v[3])
		{
			connected = true;
			break;
		}
	}
}
void CreateGraph_2()
{
	struct Vertex
	{
		//vector<Vertex*> edges;
		//int data;
	};

	vector<Vertex> v;
	v.resize(6);

	// 연결된 목록을 따로 관리
	// adjacent[n] -> n번째 정점과 연결된 정점 목록
	vector<vector<int>> adjacent(6);

	adjacent[0] = { 1, 3 };
	adjacent[1] = { 0, 2, 3 };
	adjacent[3] = { 4 };
	adjacent[5] = { 4 };

	// Q) 0번 -> 3번 정점이 연결되어 있나요?
	bool connected = false;
	for (int vertex : adjacent[0])
	{
		if (vertex == 3)
		{
			connected = true;
			break;
		}
	}

	//STL
	vector<int>& adj = adjacent[0];
	bool connected2 = (std::find(adj.begin(), adj.end(), 3) != adj.end());
}
int main()
{
	CreateGraph_1();
	CreateGraph_2();
}