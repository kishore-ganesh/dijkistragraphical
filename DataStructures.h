#pragma once



#include<iostream>
#include<vector>
#include<list>
#include<stdlib.h>
#include<queue>
#include<limits>
#include "Graphics.h"

#define ww 0
#define bb 1
#define pp 2


using namespace std;




//use map

struct EdgeNode
{
	EdgeNode* next = NULL;
	struct VerticeNode* connectedto = NULL;
	struct VerticeNode* belongsto = NULL;
	int distance = -1;
	int color = 0;
};

struct VerticeNode
{
	int data;
	list<EdgeNode> linkedlist;
	//   EdgeNode* head=NULL;
	int currentdistance = -1;
	int hasbeenvisited = 0;
	SDL_Rect circrect;
	int flag = 0;
	
	


};

class greaternode
{
public: 
	bool operator()(VerticeNode A, VerticeNode B)
	{
		return A.currentdistance > B.currentdistance;
	}
};


class Graph
{


public:
	vector<VerticeNode> NodeArray;  // used for holding all the vertices
	list<VerticeNode>UnvisitedNodes;  // used for holding unvisited nodes;
	vector<EdgeNode>ENodeArray;    //used for holding distances with the vertice nodes they are connected to 
	priority_queue<VerticeNode, vector<VerticeNode>, greaternode> NodeQueue;
	static int successes;   // used for finding the number of times it has found a path 

	Graph();
	void setup();
	void AddEdge(VerticeNode &A, VerticeNode &B, int dist);
	void AddVertice(int x, int y);
	void ConnectedTo();
	void shortestpath(VerticeNode &A, VerticeNode &B);
	void alternateshortestpath(VerticeNode &A, VerticeNode &B);
	void calcdist(EdgeNode anedgenode, int orgcurrentdist);
	void startshorestpath(VerticeNode &A, VerticeNode &B);
	void cleanup();

	
};







