#include "stdafx.h"
#include "Graphics.h"
#include <mutex>



//x, y coords, nodes- circles, edge nodes-lines, with dist written, node overlay data
//use images for circles, white background 

//derive rect class and modify it 

const colorstruct white = colorstruct(255, 255, 255);
const colorstruct blue = colorstruct(100, 255, 255);
const colorstruct pink = colorstruct(255, 100, 255);
const colorstruct black = colorstruct(0, 0, 0);
SDL_Window* window = NULL;
SDL_Surface* screensurface = NULL;
SDL_Surface* circle = NULL;
SDL_Renderer* renderer = NULL;

SDL_Texture* texture = NULL;
mutex mu;


void initializeSDL()
{
	
	
	//mu.lock();
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_INIT_PNG;
	window = SDL_CreateWindow("Djikistra's Algorithm", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
	screensurface = SDL_GetWindowSurface(window);
	circle = IMG_Load("circle1.png");
	renderer = SDL_CreateRenderer(window, -1, 0);
	texture = SDL_CreateTextureFromSurface(renderer, circle);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
//	mu.unlock();

	

	
}




void displaythread()
{
	initializeSDL();
//	SDL_Init(SDL_INIT_EVERYTHING);

 
	while (true)
	{
		SDL_Event event;
		
		while (SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_QUIT)
			{
				//cout << "Running";
				SDL_Quit();
			}

			//SDL_Delay(5000);
			
		}
		//SDL_RenderPresent(renderer);
	}
}

void RenderLine(struct colorstruct a, VerticeNode sourcenode, VerticeNode destnode)
{
	int r, g, b;
	r = a.r;
	g = a.g;
	b = a.b;
	int sourcex = sourcenode.circrect.x;
	int sourcey = sourcenode.circrect.y;
	int destx = destnode.circrect.x;
	int desty = destnode.circrect.y;
	SDL_SetRenderDrawColor(renderer, r, g, b, 255);
	SDL_RenderDrawLine(renderer, (sourcex)+25, (sourcey)+25, (destx) + 25, (desty) + 25);
	SDL_RenderPresent(renderer);
}



/*void display()
{
	SDLWindow* window;
	window=SDL_CreateWindow("Djikstra's Algorithm", SDL_WINDOWPOS_ISUNDEFINED, SDL_W)
}

void rendernode(VerticeNode a)
{
	int x = a.x;
	int y = a.y;
	// insert code for rendering circle
	for (list < EdgeNode::iterator i = a.list.begin(); i++)
	{
		//render line from a.x to i->connectedto->x;
	}
}*/
