#ifndef MAZE_H
#define MAZE_H

#include <windows.h> // For the "console" functions
#include <iostream> // So we can use "cout"
#include <fstream> // For the ifstream class
using namespace std;

#define MAX_MONSTERS 4
#define WALL '#' // The ASCII char representing a "solid object" (ie piece of a wall)

// The directions any ENTITY can move
#define NORTH 0
#define SOUTH 1
#define WEST 2
#define EAST 3
#define MAX_DIR 4 // Maximum number of directions an ENTITY can move

// How far from the upper left corner of the window (0,0) we want to
// "indent" in for when we draw to the screen
#define INDENT_X 5
#define INDENT_Y 5

#define MAP_NAME "Map.txt"  // The name of our "maze map" text file
						   // **NOTE** Maze.txt is laid out as follows:
						  // a '0' represents an open space
						 // a '1' represents a "wall" (solid object)

#define SCREEN_WIDTH 197
#define SCREEN_HEIGHT 51

// First thing will do is define our struct for an "entity" -- An entity will be
// any living thing in our game (the player and monsters)
struct ENTITY
{
	int xPos; // X position of ENTITY
	int yPos; // Y position of ENTITY

	unsigned char dispChar; // The ASCII representation of the ENTITY
	unsigned char color; // The color (background and foreground) of the ENTITY "dispChar"
};

// This struct will hold ALL of our game data
struct GAMEDATA
{
	CHAR_INFO screenBuff[SCREEN_HEIGHT][SCREEN_WIDTH]; // This is buffer (array) we will allocate that will hold
					      // all of "maze data" that we want to display to the screen

	HANDLE outputHandle; // This is the handle of where we want to draw our screen buffer
	HANDLE inputHandle; // This is the handle of where we want to receive user input
					   // (ie the keyboard)

	SMALL_RECT rect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT }; // This defines a rectangular area ON THE SCREEN where we want
					// to draw

	// The width and height of our maze
	int width;
	int height;

	// The (x,y) of the "ending position" of the maze -- When the player touches
	// this space they have "won"
	int xEndPos;
	int yEndPos;

	bool gameover; // This gets set to true when the game is over OR a player
				  // hits the "Esc" key
};

// Initializes all the variables we'll need for our game -- Returns true on success, false
// on failure
bool InitGame();
bool InitHandles(); // Initializes the handles
void InitPlayer(); // Initializes the "player"
void InitMonsters(); // Initializes the "Monsters"

// Loads the map (specified by MAP_NAME) into GAMEDATA
// Returns true on success, false on failure
bool LoadMap();

// This takes an ENTITY (a player of monster) and a direction that THEY WANT TO MOVE in.
// If they can move in that direction (ie there's NOT a WALL in that direction) the function
// returns FALSE, otherwise it returns TRUE (the CAN NOT move in the
// specified direction, they've collided) -- Did you get that? %)
bool Collide(ENTITY entity, char dir);

void UpdatePlayer(); // If the player has moved, updates his position
void UpdateMonsters(); // Updates the monsters positions as they move around

void moveUp(ENTITY &entity); // Move an entity (player or monster) up one square
void moveDown(ENTITY &entity); // Move an entity (player or monster) down one square
void moveLeft(ENTITY &entity);// Move an entity (player or monster) left one square
void moveRight(ENTITY &entity); // Move an entity (player or monster) right one square

void DrawScreen(); // This draws the maze and "entities in it" to the screen

void CheckGameState(); // This evaluates the state of the game -- If the player has
					 // died OR the player has one, it sets the game over flag and
					// prints out an appropriate message

bool isGameOver(); // Returns true if game is over (or the player has quit)
				  // Otherwise it returns false

void FreeMem(); // This frees up any memory our "game" has allocated when the game is over

#endif
