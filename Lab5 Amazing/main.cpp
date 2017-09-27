// Done by TheTutor -- 10/26/01

/*	This takes the idea behind the "maze" tutorial and expands it a little bit.  You can
	actually call this tutorial a GAME!  It's a long way from anything like NetHack, but
	it's a start in the right direction.

	Okay so what does this tutorial do that the original "Maze" tutorial did not?  Well
	here's the list:

	1)  The ability to load "mazes" from a file has been added.
	2)  The maze can be solved.  Simply touch the 'E' and you've won the game.
	3)  There are now monsters randomly moving about the maze.  Touch one of these
		and it's game over

	This tutorial is different from others, in that it's structured in a way
	that "is a good structure to follow for a game" -- Now that's not to say
	it's perfect or even really good, but it's definitely better than average.
	I mention some of the problems at the bottom of this file.  However, if you find
	yourself thinking, "Man how the heck should I structure my program for this
	sweet game I'm about to write?"  You can use this tutorial as a guide.

*/

#include "maze.h"
#include <conio.h> // So we can use _kbhit()

int main()
{
	if(InitGame() == false)
		return 1;

	// While the game IS NOT over
	while(isGameOver() == false)
	{
		UpdatePlayer();
		UpdateMonsters();
		DrawScreen();

		CheckGameState();
	}

	FreeMem(); // Free up memory

	// This is just says "while a key HAS NOT been hit" keep looping (doing nothing)
	// We put this here so the game just doesn't close all of sudden when it's over
	// (ie you have to push a key to close the window)
	while(!_kbhit());

	return 0;
}


/*	Game over... almost

	So now that you went through all the code (you have went through the code right?)
	I'll talk about some things that could be improved.

	You'll notice we NEVER pass GAMEDATA into any functions.  Here I took advantage of
	the fact that it was global.  However if you wanted to make a more complex game, you
	more than likely want to starting passing the GAMEDATA into functions.  Do so as a
	reference OR a pointer.  Why you ask two reasons:

	1)  If you want to modify it, you have to pass it in as a reference or pointer.
	2)  When you pass in as a reference or pointer, it's faster.  Remember when you pass
		a variable (ANY VARIABLE) into a function, the function makes a LOCAL copy of
		that variable.  So if we were to pass a GAMEDATA into a function it would have to
		make local copies of ALL the variables that are inside the struct GAMEDATA.  But,
		if we pass in as reference or a pointer to a GAMEDATA, all that gets passed into
		the function is 4 bytes of information (a "pointer" to the GAMEDATA, hence it DOES NOT
		make a local copy of the variable since it "points" to the actual variable).
		Now what if you don't want to change it, but you accidentally do. (This would be bad)
		Is there a way to pass in a pointer AND not have it be changed?  The answer is YES!
		Just put in front of the variable name (in the function declaration) the keyword
		"const".

		To tie it all back in to this tutorial -- If I were to rewrite the LoadMap() function
		this would be it's function declaration (located in maze.h)

		void LoadMap(GAMEDATA &gamedata); // The function would take a reference to a GAMEDATA
										 // so we could change it in the function LoadMap()
										// and have those changes stay intact when
									   // we return from the function LoadMap()

	Okay now another thing that could be made better in the game is the following:
	If you look closely, you'll notice when your character moves, the monsters move at the
	same speed.  But if you stand still, the monsters slow down a little bit.  Now this isn't
	necessarily a bad thing (perhaps you like it that way) -- But regardless it would
	not be too tough to fix, so I'll leave this as an exercise for you :)

	Like Aristotle said:

	"What we learn to do, we learn by doing."

	If there's anything that's unclear, be sure to ask at www.GameTutorials.com

*/

