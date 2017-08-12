#include "stdafx.h"
#include "DataStructures.h"
#include <thread>

#define delayamount 5000

std::thread athread;



int Graph::successes;
//optimize - multiple arrays
//use correct datastructures
// will it choose min dist or -1
//will it go to next node if current node has it defined as -1
//make modules built up on prev projects

//if member does not have a linkedlist, initialize it to its own value


//optimize it so that it stops when it finds no path to node 

//make it more varied and more likely tro be connected to a node
// make it doubly linked

//debug calcdist
//optimize checking for minus one by referring to wiki
//linkedlistempty problem

// if linkedlist empty go to next node

//remove keep going to nodes dependency
//for graphical implementation, make line colored, after the function call (if success)
//music

//add one side, and add anothertoo for list

//read from file and proces

//if current node already visited
//add connection between final node and prev node

// make it respond to gui 
// if minnode.belongs to != currentnode, remove pink 

//add color attribute o edge node
//add nods with which pink color 
//show that it has been visited
//reset if moving to another node 

 Graph::Graph()
{
	
	 

}

 void Graph::startshorestpath(VerticeNode &A, VerticeNode&B)
 {
	 athread=std::thread(&Graph::shortestpath, this, A, B);

 }

 void Graph::setup()
 {
	 SDL_SetRenderDrawColor(renderer, black.r, black.g, black.b, 255);
	 SDL_RenderClear(renderer);
	 for (int i = 0; i < NodeArray.size(); i++)
	 {

		 SDL_RenderCopy(renderer, texture, NULL, &NodeArray[i].circrect);
		 for (list<EdgeNode>::iterator j = NodeArray[i].linkedlist.begin(); j != NodeArray[i].linkedlist.end(); j++)
		 {
			 j->color = ww;
			 RenderLine(white, NodeArray[i], *(j->connectedto));

		 }
	 }
 }

void Graph::AddEdge(VerticeNode &A, VerticeNode &B, int dist)
{
	EdgeNode TempNode;
	TempNode.distance = dist;
	TempNode.connectedto = &B;
	TempNode.belongsto = &A;
	A.linkedlist.push_front(TempNode);
	TempNode.connectedto = &A;
	TempNode.belongsto = &B;
	B.linkedlist.push_front(TempNode);  //beta test 
	//ENodeArray.push_back(TempNode);

}



void Graph::AddVertice(int x, int y)
{
	static int vnodedata = 0;
	VerticeNode tempvnode;
	tempvnode.data = vnodedata;
	tempvnode.circrect.w = width;
	tempvnode.circrect.h = height;
	tempvnode.circrect.x = x;
	tempvnode.circrect.y = y;
	NodeArray.push_back(tempvnode);
	UnvisitedNodes.push_back(tempvnode);
	NodeQueue.push(tempvnode);
	vnodedata++;

}

void Graph::ConnectedTo()

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

void Graph::shortestpath(VerticeNode &A, VerticeNode &B)

{
	
	A.hasbeenvisited = 1;
	VerticeNode* currentnode;
	
	
	currentnode = &A;
	static bool flag = true;
	static int firstnodedata=0;
	static int secondnodedata=0;
	EdgeNode minnode;
	int varforfindingi = 0;
	int mindist;
	VerticeNode* currentnodecopy = currentnode;


	//cout << " "<<firstnodedata;
	
	//cout <<" "<< NodeArray[3].currentdistance;
	if (flag == true)
	{
		 firstnodedata = currentnode->data;
		 secondnodedata = B.data;
		 flag = false;
		 

		  
	}
	//flag = false;
	
	//cout << firstnodedata << " " << secondnodedata;
	
	//cout << A.hasbeenvisited;
	

	//who updates in unvisitednodes

	if(currentnode->currentdistance==-1)
	{
		currentnode->currentdistance = 0;
	}


	for (list<VerticeNode>::iterator i = UnvisitedNodes.begin(); i != UnvisitedNodes.end(); i++)
	{
		if (i->data == A.data)
		{
			i->hasbeenvisited = 1;
			
			UnvisitedNodes.erase(i);
			
			break;
		}
			
	}

	

	/*for (int i = 0; i < NodeArray.size(); i++)
	{
		if (NodeArray[i].data == A.data)
		{
			NodeArray[i].hasbeenvisited = 1;
			break;
		}
	}*/

	
	
	//cout << flag;

	
	//cout <<" "<< UnvisitedNodes.size();
	//cout << currentnode->data;

	
	

	if (UnvisitedNodes.size() == 0)

	{
		cout << "\n \n The Node"<<" "<<secondnodedata<<" is not reachable from Node"<<" "<<firstnodedata<<", ending search";
		cout << "\n ";
	//	cout << "flag value: " << flag;
		flag = true;
		//SDL_Delay(delayamount);
		return;
	}
	

	//initialize variables to avoid error
	//add function to detect if no nodes are left to evaluate;
	//redundant nodes in ENodeArray


	if (currentnode->data == B.data&&currentnode->currentdistance!=-1&&currentnode->currentdistance!=0)
	{
		std::cout << "\n The node"<<" "<<currentnode->data<< " has been reached from node"<<" "<<firstnodedata<<" and distance is: \n " << currentnode->currentdistance;
		flag = true;
		successes++;
		SDL_Delay(delayamount);
		
	
		return;

	}

	/*else if (currentnode->data == B.data &&currentnode->currentdistance == -1)
	{
		cout << "\n \n The Node"<<currentnode->data<<" is not reachable from node"<<firstnodedata<<", ending search";
		cout << "\n ";
		return;
	}*/
	else
	{
		if (A.linkedlist.size() != 0)
		{
			for (list<EdgeNode>::iterator anedgenode = A.linkedlist.begin(); anedgenode != A.linkedlist.end(); anedgenode++)

			{
				calcdist(*anedgenode, currentnode->currentdistance);
			//	SDL_SetRenderDrawColor(renderer, 100, 255, 255, 255);
				int sourcex, sourcey;
				sourcex = A.circrect.x;
				sourcey = A.circrect.y;
				
				if ( anedgenode->color != pp)
				{
				//	cout << "FLAG:" << A.flag << " " << anedgenode->connectedto->flag;
					SDL_Delay(delayamount / 2);
					anedgenode->color = bb;

					RenderLine(blue, A, *(anedgenode->connectedto));
				}
					

			}

		}

		
	}

	mindist = -1;

	for (int i = 0; i < ENodeArray.size(); i++)
	{ 
		if ((ENodeArray[i].distance < mindist || mindist==-1) )
		{
			if (ENodeArray[i].connectedto->hasbeenvisited == 0)
			{
				//cout << "Y";
				mindist = ENodeArray[i].distance;
				varforfindingi = i;
				//cout << mindist;


			}
		}

		
	}

	//cout << varforfindingi;
	
	

	if (mindist != -1)

	{
		minnode = ENodeArray[varforfindingi];
		currentnode = minnode.connectedto;
	}

	else
	{


		cout << "\n \n The Node" << " " << secondnodedata << " is not reachable from Node" << " " << firstnodedata << ", ending search";
		cout << "\n ";
		flag = true;
		//SDL_Delay(delayamount);
		return;
		
		/*for (list<VerticeNode>::iterator i = UnvisitedNodes.begin(); i != UnvisitedNodes.end(); i++)
		{
			
			if (i->hasbeenvisited == 0)
			{
				
				currentnode = &(*i);
				
				break;
			}
		}*/
	}

	for (int i = 0; i < NodeArray.size(); i++)
	{
		if (NodeArray[i].data == currentnode->data)
		{
			currentnode = &(NodeArray[i]);
		}
	}
	
	currentnode->flag = 1;
	
		//currentnodecopy->flag = 1;
	currentnode->hasbeenvisited = 1;
	SDL_Delay(delayamount/2);
	if (minnode.belongsto->data != currentnode->data)
	{
		//recursively go through prev path and make lines blue 
		//RenderLine(blue, )
	}
	RenderLine(pink, *minnode.belongsto, *currentnode);
	minnode.belongsto->flag = 1;
	minnode.color = pp;
	for (list<EdgeNode>::iterator i = minnode.connectedto->linkedlist.begin(); i != minnode.connectedto->linkedlist.end(); i++)
	{
		if (i->connectedto == minnode.belongsto)
		{
			cout << i->connectedto->data << " " << minnode.connectedto->data;
			i->color = pp;
			break;
		}
	}
	


	//recursivenode = *currentnode;
	//cout << currentnode->data;
	

	
	shortestpath(*currentnode, B);
	


}

void Graph::calcdist(EdgeNode anedgenode, int currentnodedistance)
{
	//insert code for graphical here  
	
	
	int distancetonode = anedgenode.distance;
	VerticeNode* connectedto = anedgenode.connectedto;
	if (connectedto->currentdistance == -1)
	{
		connectedto->currentdistance= distancetonode+currentnodedistance;
	}

	else
	{
		if (currentnodedistance + distancetonode < connectedto->currentdistance)
		{
			connectedto->currentdistance = currentnodedistance + distancetonode;
		}

	}

	EdgeNode tempnode;
	tempnode.connectedto = connectedto;
	tempnode.distance = connectedto->currentdistance;
	tempnode.belongsto = anedgenode.belongsto;
	//cout << connectedto->currentdistance;
	ENodeArray.push_back(tempnode);





}

void Graph::cleanup()
{
	for (int i = 0; i < NodeArray.size(); i++)
	{
        NodeArray[i].hasbeenvisited = 0;
		NodeArray[i].currentdistance = -1;
		NodeArray[i].flag = 0;

	}

    UnvisitedNodes.erase(UnvisitedNodes.begin(), UnvisitedNodes.end());
	ENodeArray.erase(ENodeArray.begin(), ENodeArray.end());

	for (vector<VerticeNode>::iterator i = NodeArray.begin(); i != NodeArray.end(); i++)
	{
		UnvisitedNodes.push_back(*i);
	}

	//SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	setup();
	SDL_RenderPresent;
	/*for (int i = 0; i < NodeArray.size(); i++)
	{
		//SDL_BlitScaled(circle, NULL, screensurface, &agraph.NodeArray[i].circrect);
		
		for (list<EdgeNode>::iterator j = NodeArray[i].linkedlist.begin(); j != NodeArray[i].linkedlist.end(); j++)
		{
			//cout << "I";
			//SDL_RenderClear(renderer);
			RenderLine(white, NodeArray[i], *(j->connectedto));
			
			//SDL_RenderPresent(renderer);
		}
	}*/
}

void Graph::alternateshortestpath(VerticeNode &A, VerticeNode &B)
{
	
	while (NodeQueue.size() != 0)
	{
		if (NodeQueue.top().hasbeenvisited==1)
		{
			continue;
		}

		else
		{
           
		}
		NodeQueue.pop();
	}

	if (B.currentdistance == numeric_limits<int>::infinity())
	{
		cout << "Node not reachable";
	}
}


//namespaces?

//why isn't reference working

//pop nodes once done 

//if you can go to no more nodes, but nodes are stil univisited, what will happen

//sort by distance, pick first node