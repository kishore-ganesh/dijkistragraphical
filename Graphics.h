#pragma once

#include "stdafx.h"
#include "SDL.h"
#include "DataStructures.h"
#include "SDL_image.h"

#define height 50;
#define width 50;

extern SDL_Window* window;
extern SDL_Surface*  screensurface;
extern SDL_Surface* circle;
extern SDL_Renderer* renderer;
extern SDL_Texture* texture;

struct colorstruct
{
	int r, g, b;
	colorstruct(int r, int g, int b) :r(r), g(g), b(b)
	{}
};

void initializeSDL();
void displaythread();

void rendernode(struct VerticeNode a);
void RenderLine(colorstruct a, struct VerticeNode sourcenode, struct VerticeNode destnode);

extern const colorstruct white;
extern const colorstruct blue;
extern const colorstruct pink;
extern const colorstruct black;
