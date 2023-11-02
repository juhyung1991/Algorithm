#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;
#include <thread>
#include <windows.h>

// [ ][ ][ ][ ][ ][ ][ ][ ]

// DFS (Depth First Search) 깊이 우선 탐색
// BFS (Breadth First Search) 너비 우선 탐색

struct Vertex
{
	//int data;

};

vector<Vertex> vertices;
vector<vector<int>> adjacent;
vector<bool> visited;

void CreateGraph()
{
	vertices.resize(6);
	adjacent = vector<vector<int>>(6);

	//adjacent[0].push_back(1);
	//adjacent[0].push_back(3);
	//adjacent[1].push_back(0);
	//adjacent[1].push_back(2);
	//adjacent[1].push_back(3);
	//adjacent[3].push_back(4);
	//adjacent[5].push_back(4);

	adjacent = vector<vector<int>>
	{
		{0, 1, 0, 1, 0, 0},
		{1, 0, 1, 1, 0, 0},
		{0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 1, 0},
	};

}

//DFS

//DFS(0)
//- DFS(1)
//-- DFS(2)
//-- DFS(3)
//--- DFS(4)
//- DFS(3)
void DFS(int here)
{
	//방문체크
	visited[here] = true;
	cout << "visited : " << here << endl;
	//인접 리스트 ver.
	//모든 인접 정점을 순회한다.

	//for(int i = 0; i < adjacent[here].size(); i++)
	//{
	//	int there = adjacent[here][i];

	//	if(visited[there] == false)
	//		DFS(there);
	//}
	//인접 행령 ver.
	//모든 정점을 순회한다.
	for (int there = 0; there < 6; there++)
	{
		if(adjacent[here][there] == 0)
			continue;

		//아직 방문하지 않은 곳이 있으면 방문한다.
		if(visited[there] = false)
			DFS(there);
	}

} 

void DFSAll()
{
	visited = vector<bool>(6, false);

	for (int i = 0; i < 6; i++)
	{
		if(visited[i] == false)
			DFS(i);
	}
}

int main()
{
	CreateGraph();

	//DFS(0);
	DFSAll();
}