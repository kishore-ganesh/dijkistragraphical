// ConsoleApplication5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include<iostream>
#include<vector>
#include<list>
#include<stdlib.h>
#include<time.h>

using namespace std;
int a = 0;


struct EdgeNode
{
	EdgeNode* next = NULL;
	struct VerticeNode* connectedto = NULL;
	int distance = -1;
};

struct VerticeNode
{
	int data;
	list<EdgeNode> linkedlist;
	//   EdgeNode* head=NULL;
	int currentdistance = -1;
	int hasbeenvisited = 0;

};



class Graph
{
private: int iterator;
		 int anotheriterator;

public:
	vector<VerticeNode> NodeArray;
	vector<EdgeNode>ENodeArray;

	Graph()
	{
		
		iterator = 0;
		anotheriterator = 0;
	}



	void AddEdge(VerticeNode &A, VerticeNode &B, int dist)
	{
		EdgeNode TempNode;
		TempNode.distance = dist;
		TempNode.connectedto = &B;

		//    ENodeArray.push_back(TempNode);;
		A.linkedlist.push_front(TempNode);

		if (anotheriterator < ENodeArray.size()
			)
		{
			ENodeArray[anotheriterator].connectedto = &B;
		}
		
		else
		{

			EdgeNode tempnode;
			tempnode.connectedto = &B;
			ENodeArray.push_back(tempnode);

		}

		
		anotheriterator++;

		//  cout<<" Edge: "<<anotheriterator;




	}

	void AddVertice()
	{
		static int vnodedata = 0;
		VerticeNode tempvnode;
		tempvnode.data = vnodedata;
		NodeArray.push_back(tempvnode);
		// std::cout<<vnodedata<<"\n";
		vnodedata++;
	}

	/*void displayverticelist()
	{
	for(int i=0; i<NodeArray.)
	}*/

	void ConnectedTo()
	{
		for (int i = 0; i<NodeArray.size(); i++)
		{
			list<EdgeNode> linkedlist = NodeArray[i].linkedlist;

			for (list<EdgeNode>::iterator j = linkedlist.begin(); j != linkedlist.end(); j++)
			{


				std::cout << "\n Node " << NodeArray[i].data << " " << "is connected to:";

				std::cout << " " << j->connectedto->data << " " << "with a distance of: " << j->distance;
			}

		}





	}

	void shortestpath(VerticeNode &A, VerticeNode &B)
	{

		//    A.currentdistance=0;

		//cout<<" "<<A.data;

		iterator = 0;
		static bool flag = true;
		//cout<<flag;

		for (int i = 0; i<ENodeArray.size(); i++)
		{
			if (ENodeArray[i].connectedto->hasbeenvisited == 0)
			{
				flag = true;
			}
		}



		if (flag == false)
		{
			//     cout<<"   "<<flag;
			cout << "\n \n The Node is not reachable, ending search";
			return;

		}
		//ENodeArray.erase(ENodeArray.begin(), ENodeArray.end());
		for (int i = 0; i<ENodeArray.size(); i++)
		{
			ENodeArray[i].distance = -1;
		}

		A.hasbeenvisited = 1;
		VerticeNode* currentnode;
		currentnode = &A;
		// EdgeNode* temp=A.head;
		EdgeNode minnode;

		//here insert mechanism for checking if any visited ndoes are lett

		if (currentnode->data == B.data)
		{
			std::cout << "\n The node has been reached and distance is: " << currentnode->currentdistance;

		}
		else {
			for (list<EdgeNode>::iterator temp = A.linkedlist.begin(); temp != A.linkedlist.end(); temp++)

			{
				calcdist(temp->distance, temp->connectedto, currentnode->currentdistance);
				// temp->connectedto->hasbeenvisited
				// temp=temp->next;
			}

			// cout<<" "<<A.currentdistance;
			int mindist;
			int varforfindingi = 0;
			//cout<<" E N SIZE" << ENodeArray.size();
		

			mindist = ENodeArray[0].distance;




			// cout<<ENodeArray[0].connectedto->currentdistance;

			// cout<<ENodeArray[0].distance
			for (int i = 0; i<5; i++)
			{
				//cout<<ENodeArray[i].connectedto->data;
				// std::cout<<"Y";
				if (ENodeArray[i].connectedto != NULL)

				{//std::cout<<"Y";
				 // std::cout<<" "<<ENodeArray[i].distance;
					if ((ENodeArray[i].distance<mindist) && ENodeArray[i].distance != -1)
					{

						// std::cout<<"Y";

						{

							if (ENodeArray[i].connectedto->hasbeenvisited == 0)
							{

								mindist = ENodeArray[i].distance;
								varforfindingi = i;


							}
						}


					}




				}


			}

			for (int i = 0; i<5; i++)
			{
				// cout<<ENodeArray[i].distance<<" ";
				if (ENodeArray[i].connectedto)
				{
					if (ENodeArray[i].connectedto->currentdistance == mindist)
					{
						// cout<<mindist;
						varforfindingi = i;
					}
				}

			}

			// cout<<mindist;


			//cout<<mindist;
			//cout<<" "<<varforfindingi;

			//after finding minimum distance
			minnode = ENodeArray[varforfindingi];

			//cout<<varforfindingi;
			
			currentnode = minnode.connectedto;

			if(!currentnode)
			{
				//cout << "it does not exist";
			}
			
			VerticeNode tmp = *currentnode;

		

			//cout<<currentnode->data;
			//std::cout<<tmp.currentdistance;
			//cout<<NodeArray[3].currentdistance;
			flag = false;

			shortestpath(tmp, B);

			//    cout<<"   "<<flag;
		}

		//clause for not going through node is has been visited

	}

	void calcdist(int distance, VerticeNode* connectedto, int orgcurrentdist)
	{
		//verticenode dist
		int dist = distance;
		//add?
		int currentdist = connectedto->currentdistance;

		//  cout<<orgcurrentdist;

		if (currentdist = -1)
		{

			if (orgcurrentdist == -1)
			{
				currentdist = dist;
			}
			else
			{
				currentdist = dist + orgcurrentdist;
			}
		}

		else if (dist<currentdist)
		{
			std::cout << "Y";

			if (orgcurrentdist == -1)
			{
				currentdist = dist;
			}
			else
			{
				currentdist = dist + orgcurrentdist;
			}

		}

		//std::cout<<currentdist<<" "<<dist;
		// std::cout<<" The Node"<<" "<<connectedto->data;


		ENodeArray[iterator].distance = currentdist;
		ENodeArray[iterator].connectedto = connectedto;
		connectedto->currentdistance = currentdist;
		iterator++;

		// cout<<connectedto->data;
		//cout<<iterator;

	}
	//verify if visited
	//recursive
	//if same nodes on both sides, end functon
};

int main()
{
	srand(time(0));
	Graph agraph;
	for (int i = 0; i<10; i++)
	{

		agraph.AddVertice();
		// cout<<" "<<agraph.NodeArray.size();



	}


	for (int i = 0; i<10; i++)
	{
		int randvar = rand() % 11;
		//   cout<<" "<<randvar;
		if (randvar<10)
		{
			int randomvariable1 = rand() % agraph.NodeArray.size();
			int randomvariable2 = rand() % agraph.NodeArray.size();
			//cout<<"\n "<<randomvariable1<<" "<<randomvariable2;
			int randdist = rand() % 11;

			if (randomvariable1 != randomvariable2)
			{
				agraph.AddEdge(agraph.NodeArray[randomvariable1], agraph.NodeArray[randomvariable2], randdist);
			}

		}

	}








	/*agraph.AddEdge(agraph.NodeArray[0], agraph.NodeArray[2], 4);
	agraph.AddEdge(agraph.NodeArray[1],agraph.NodeArray[3],4);
	agraph.AddEdge(agraph.NodeArray[2],agraph.NodeArray[3],2);
	agraph.AddEdge(agraph.NodeArray[0],agraph.NodeArray[1],1);
	agraph.AddEdge(agraph.NodeArray[0],agraph.NodeArray[3],8);
	agraph.AddVertice();*/
	//for(int i=0)


//	agraph.ConnectedTo();

	for (int i = 0; i<10; i++)
	{


		int randomvariable1 = rand() % agraph.NodeArray.size();
		int randomvariable2 = rand() % agraph.NodeArray.size();
		//cout<<"\n "<<randomvariable1<<" "<<randomvariable2;


		if (randomvariable1 != randomvariable2)
		{

			agraph.shortestpath(agraph.NodeArray[randomvariable1], agraph.NodeArray[randomvariable2]);

		}



	}
	//std::cout<<"\n";
	//
	//agraph.shortestpath(agraph.NodeArray[0], agraph.NodeArray[4]);
	//std::cout<<agraph.NodeArray[4].data;

	//for(int i=0; i<5; i++)
	//{
	//  cout<<" Current "<<agraph.NodeArray[i].currentdistance;
	//}

}

//current node find, then start visiting

//start from A, find distance to nodes it is connected to. Then choose node of minimum distance, and find distance of its nearest nodes. At the same time check if any node is B.
//ENodeArray fix
//disconnect between ENodeArray and Data

//find EdgeNodePosition problem


//flexible addition of nodes and edges
//on screen

//random generation of graph
//clean up of code

//add vertice function


// separate container for visited nodes
// use search function instead
// use library function for min dist
//remove the loop for vertice addition
//refactor into separate files

//if starting from same node
//write logs
// if no more nodes available in edge node, choose  next applicable min distance. 
