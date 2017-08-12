#include"stdafx.h"
#include "DataStructures.h"
#include "Graphics.h"
#include<time.h>
#include<thread> 
//highlight start node and end node 






//twitter bot// appi 
//make flappy bird better with physics engine

//thread for gui quitting

//refactoring 

//clear on screen after finding 

//draw nodes in proportion to their distance (random*nodedistancfe?)







//threads

//random nodes shouldn't be equal to chosen before 







int main(int argc, char* argv[])
{
	srand(time(0));
	
	//initializeSDL();
	Graph agraph;

	std::thread athread(displaythread);

	
	SDL_Delay(100);
	//SDL_DestroyWindow(window);
	
	if(texture==NULL)
	{
		cout << "NULL";
	}

	

	




	





	for (int i = 0; i < 10; i++)
	{
		int x, y;
		x = rand() % 750;
		y = rand() % 550;
		agraph.AddVertice(x, y);
		

	}





	for (int i = 0; i < 10; i++)
	{
		int randvar = rand() % 11;
		//   cout<<" "<<randvar;
		if (randvar < 10)
		{
			int randomvariable1 = rand() % agraph.NodeArray.size();
			int randomvariable2 = rand() % agraph.NodeArray.size();
			//cout<<"\n "<<randomvariable1<<" "<<randomvariable2;
			int randdist = rand() % 30;

			if ((randomvariable1 != randomvariable2) && randdist != 0)
			{
				agraph.AddEdge(agraph.NodeArray[randomvariable1], agraph.NodeArray[randomvariable2], randdist);
			}

		}

	}


	//SDL_RenderClear;
	agraph.setup();
	


	agraph.ConnectedTo();
	//athread.join();

	for (int i = 0; i < 10; i++)
	{


		int randomvariable1 = rand() % agraph.NodeArray.size();
		int randomvariable2 = rand() % agraph.NodeArray.size();



		if (randomvariable1 != randomvariable2)
		{

			SDL_RenderPresent(renderer);
		//	std::thread anotherthread(&Graph::shortestpath, agraph, agraph.NodeArray[0], agraph.NodeArray[1]);
			//anotherthread.join();
			agraph.shortestpath(agraph.NodeArray[randomvariable1], agraph.NodeArray[randomvariable2]);
			//agraph.startshorestpath(agraph.NodeArray[randomvariable1], agraph.NodeArray[randomvariable2]);
		//	athread=std::thread(&Graph::shortestpath, agraph, agraph.NodeArray[randomvariable1], agraph.NodeArray[randomvariable2]);
			agraph.cleanup();
			
			SDL_RenderPresent(renderer);


		}



	}

	


	cout << "Number of successful outcomes: " << Graph::successes;

//	athread.join();
	


	return 0;
}

