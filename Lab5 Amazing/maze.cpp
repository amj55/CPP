#include "maze.h"

// Here will make a global (global to this .cpp file) instance of
// our GAEMDATA
GAMEDATA gamedata;
ENTITY player;
ENTITY monster[MAX_MONSTERS];

// This loads/creates all necessary data to play the "game" -- If an error
// occurs, the function returns false, otherwise we return true
bool InitGame() {
    system("mode 650");
    // Seed the random timer
    srand(GetTickCount());

    // Init input and output handles
    if(InitHandles() == false)
        return false;

    // Load and initialize our map
    if(LoadMap() == false)
        return false;

    InitPlayer(); // Init the player
    InitMonsters(); // Init the monsters

    // Initialize the "rectangle" defining where we want to draw to in our window
    gamedata.rect.Left = INDENT_X;
    gamedata.rect.Top = INDENT_Y;
    gamedata.rect.Right = INDENT_X + (gamedata.width - 1);
    gamedata.rect.Bottom = INDENT_Y + (gamedata.height - 1);

    while(1) {
        // Randomly pick an ending position
        gamedata.xEndPos = rand() % gamedata.width;
        gamedata.yEndPos = rand() % gamedata.height;

        // If the square was open (ie not a WALL)
        // we can break from the while loop
        if(gamedata.screenBuff[gamedata.yEndPos][gamedata.xEndPos].Char.AsciiChar == ' ')
            break;
    }

    DrawScreen(); // Draw the whole screen (once)

    return true; // We got loaded :)
}

// Init our standard input and output handles
bool InitHandles() {
    // Get the standard output handle
    gamedata.outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    // Error Check -- If we couldn't get the standard output handle, we won't
    // be able to draw to the screen, thus we'll quit
    if(gamedata.outputHandle == NULL)
        return false;

    // Get the standard input handle
    gamedata.inputHandle = GetStdHandle(STD_INPUT_HANDLE);

    // Error Check -- If we couldn't get the standard input handle, we won't
    // be able receive keyboard input, thus we'll quit
    if(gamedata.inputHandle == NULL)
        return false;

    return true; // Handles are loaded
}

// Initialize the "player"
void InitPlayer() {

    player.dispChar = (char)1; // This is the ASCII code for the "smiley face"
    player.color = BACKGROUND_BLUE | FOREGROUND_RED; // Player will be "red" with background
    // color being blue (like the floor)

    while(1) {
        // Give the player a random position in the maze
        player.xPos = rand() % gamedata.width;
        player.yPos = rand() % gamedata.height;

        // Calculate index (ie position in "screenBuff" where player would be
        // presuming it is not a wall)

        // If the spot that was randomly generated is open (ie not a wall)
        if(gamedata.screenBuff[player.yPos][player.xPos].Char.AsciiChar == ' ') {
            // Fill it with the "player"
            gamedata.screenBuff[player.yPos][player.xPos].Char.AsciiChar = player.dispChar;
            gamedata.screenBuff[player.yPos][player.xPos].Attributes = player.color;
            break; // And we're done
        }

    } // end of while(1)

}

// Initialize the "monsters"
void InitMonsters() {
    int index = 0; // Index into the array of "monsters"

    int scrBufIndex = 0; // Index into the "screenBuff"

    // While we haven't filled in all the monsters starting positions
    while(index != MAX_MONSTERS) {
        // Set the monster character to a "snake like character"
        // Set the color to be light green (background color blue, like the floor)
        monster[index].dispChar = (char)235;
        monster[index].color = BACKGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY;

        // Give the monster a random position in the maze
        monster[index].xPos = rand() % gamedata.width;
        monster[index].yPos = rand() % gamedata.height;

        // Calculate the index into the screen buffer

        // If the spot that was randomly generated is open (ie not a wall), we're
        // ready to set the next monster
        if(gamedata.screenBuff[monster[index].yPos][monster[index].xPos].Char.AsciiChar == ' ') {
            // Fill in the screen buffer with the monster
            gamedata.screenBuff[monster[index].yPos][monster[index].xPos].Char.AsciiChar =
                monster[index].dispChar;
            gamedata.screenBuff[monster[index].yPos][monster[index].xPos].Attributes = monster[index].color;

            index++; // Increment to next monster
        }

    } // end of while(index != MAX_MONSTERS)

} // end of InitMonsters()

// This function loads the map data specified by MAP_NAME (#define in maze.h)
// into our "gamedata" struct
bool LoadMap() {
    // Create a "ifstream" (way to read from a file) for the map text file
    ifstream file_in(MAP_NAME);

    // Error Check -- If we couldn't open the file, we can't load the map
    if(!file_in)
        return false;

    // Error check -- Make sure we could allocate the memory
    if(gamedata.screenBuff == NULL) {
        file_in.close(); // Close the file we opened
        return false;
    }

    // These will be used to index into our screenBuff
    // *Remember* even though "screenBuff" is a one dimensional array, we're going to
    // treat it as a two dimensional array
    int y = 0;

    string temp; // Create temo variable to read in line by line
    while(file_in) {  // Keep going until we reach the end of the file
        file_in >> temp; // Read in the next line
        for(int x = 0; x < temp.length(); x++) { // Loop through line
            switch(temp[x]) {
                case '0': // Char is an open space
                    gamedata.screenBuff[y][x].Char.AsciiChar = ' ';
                    gamedata.screenBuff[y][x].Attributes = BACKGROUND_BLUE;
                    break;

                case '1':  // Char is a wall
                    gamedata.screenBuff[y][x].Char.AsciiChar = WALL;
                    gamedata.screenBuff[y][x].Attributes = BACKGROUND_BLUE | FOREGROUND_GREEN;
                    break;

                default: // Die if anything else
                    file_in.close();
                    return false;
            } // End switch
        } // End for
        y++; // Increment y
    }
     // While
     gamedata.width = SCREEN_WIDTH;
     gamedata.height = SCREEN_HEIGHT;
    // Okay if we get here the map has been loaded successfully --
    // Now all we have to do is close the file we opened and then return true
    file_in.close();
    return true; // Success :)

} // end of bool LoadMap()

// Returns true if the "entity" CAN NOT move in the direction specified by "dir"
// otherwise returns false ("entity" can move in direction "dir")
bool Collide(ENTITY entity, char dir) {
    int tempX = entity.xPos; // Get the "xPos" of the entity
    int tempY = entity.yPos; // Get the "yPos" of the entity

    switch(dir) {
        case NORTH:

            tempY--; // Move tempY up by one so we are checking the spot to the
            // north of "entity"

            // If the spot north of entity is a wall
            if(gamedata.screenBuff[tempY][tempX].Char.AsciiChar == WALL)
                return true; // CAN NOT move north
            else
                return false; // ARE ABLE to move north

        case SOUTH:

            tempY++; // Move tempY down by one so we are checking the spot to the
            // south of "entity"

            // If the spot south of entity is a wall
            if(gamedata.screenBuff[tempY][tempX].Char.AsciiChar == WALL)
                return true; // CAN NOT move south
            else
                return false; // ARE ABLE to move south

        case WEST:

            tempX--; // Move tempX left by one so we are checking the spot to the
            // west of "entity"

            // If the spot west of entity is a wall
            if(gamedata.screenBuff[tempY][tempX].Char.AsciiChar == WALL)
                return true; // CAN NOT move west
            else
                return false; // ARE ABLE to move west

        case EAST:

            tempX++; // Move tempX right by one so we are checking spot to the
            // east of "entity"

            // If the spot east of entity is a wall
            if(gamedata.screenBuff[tempY][tempX].Char.AsciiChar == WALL)
                return true; // CAN NOT move east
            else
                return false; // ARE ABLE to move east

        // We are ONLY able to move north, south, east and west so any other
        // direction passed in, just return false
        default:
            return false;

    } // end of switch(dir)

} // end of bool Collide(ENTITY entity, char dir)


// Update the player's position -- Draw to the "screenBuff" in the new position
void UpdatePlayer() {
    // Flush the "input buffer" (ie effectively wipe out and key strokes that are
    // queued up for execution)
    FlushConsoleInputBuffer(gamedata.inputHandle);

    INPUT_RECORD inputRecord; // We will fill this struct with information
    // regarding user input (ie what key did the player press)

    DWORD eventsReadIn; // This will hold the number of events read in
    // (we don't really care but we have to pass it in to the function)

    // Whoa!  What does this do?
    // Well the function a few lines below, ReadConsoleInput() WAITS for keyboard input
    // when it's called so if we were to just call that function, our game WOULD ONLY do
    // something (ie monsters would only move) when we pressed a key on the keyboard
    // So what this function does is it "monitors" the "inputHandle" for 200 milliseconds,
    // if ANY input is registered if will return some value OTHER than WAIT_TIMEOUT
    // If the 200 milliseconds go by and there IS NO input (ie the player doesn't move),
    // WaitForSingleObject() returns the flag WAIT_TIMEOUT, hence we'll just return from
    // this function and move on :)
    if(WAIT_TIMEOUT == WaitForSingleObject(gamedata.inputHandle, 200))
        return;

    // This is the function that will fill "inputRecord" -- So by parameter
    // gamedata.inputHandle -- A handle to a console input buffer (ie the keyboard)
    // &inputRecord -- Address of an INPUT_RECORD struct to fill with "data"
    // 1 -- Number of INPUT_RECORD's to read
    // &eventsReadIn -- Address of a DWORD, it will hold the number of INPUT_RECORD's that
    //                  were read in successfully
    ReadConsoleInput(gamedata.inputHandle, &inputRecord, 1, &eventsReadIn);

    // If a key was pressed down (bKeyDown makes sure NT Os's don't do double steps)
    if(inputRecord.EventType == KEY_EVENT && inputRecord.Event.KeyEvent.bKeyDown) {
        // We'll switch on the "key code" that was read in
        switch(inputRecord.Event.KeyEvent.wVirtualKeyCode) {
            case VK_UP: // If the up arrow key was pressed

                // If the player WILL NOT COLLIDE into a wall by moving north
                if(Collide(player, NORTH) == false)
                    moveUp(player); // Move the player north

                break;

            case VK_DOWN: // If the down arrow key was pressed

                // If the player WILL NOT COLLIDE into a wall by moving south
                if(Collide(player, SOUTH) == false)
                    moveDown(player); // Move the player south

                break;

            case VK_LEFT: // If the left arrow key was pressed

                // If the player WILL NOT COLLIDE into a wall by moving west
                if(Collide(player, WEST) == false)
                    moveLeft(player); // Move the player west

                break;

            case VK_RIGHT: // If the right arrow key was pressed

                // If the player WILL NOT COLLIDE into a wall by moving east
                if(Collide(player, EAST) == false)
                    moveRight(player); // Move the player east

                break;

            case VK_ESCAPE:

                gamedata.gameover = true;
                break;

        } // end of switch(inputRecord.Event.KeyEvent.wVirtualKeyCode)

    } // end of if(inputRecord.EventType == KEY_EVENT)

} // end of UpdatePlayer()

// Here we're going to move the monsters in a purely RANDOM direction
void UpdateMonsters() {
    char dir; // This will hold a random direction to move in

    for(int i = 0; i < MAX_MONSTERS; i++) {
        dir = rand() % MAX_DIR;

        // If we CAN MOVE in the specified direction
        if(Collide(monster[i], dir) == false) {
            switch(dir) {
                case NORTH:
                    moveUp(monster[i]);
                    break;

                case SOUTH:
                    moveDown(monster[i]);
                    break;

                case EAST:
                    moveRight(monster[i]);
                    break;

                case WEST:
                    moveLeft(monster[i]);
                    break;

            } // end of switch(dir)

        } // end of if(Collide(monster[i],dir) == false)

    } // end of for(int i = 0; i < MAX_MONSTERS; i++)

} // end of void UpdateMonsters()

// Move an ENTITY (player of monster) north one square
void moveUp(ENTITY &entity) {

    // Make the spot where the entity is currently standing
    // a "floor tile" again
    gamedata.screenBuff[entity.yPos][entity.xPos].Char.AsciiChar = ' ';
    gamedata.screenBuff[entity.yPos][entity.xPos].Attributes = BACKGROUND_BLUE;

    // Move the entity up one position
    entity.yPos--;

    // Draw the entity where he is standing
    gamedata.screenBuff[entity.yPos][entity.xPos].Char.AsciiChar = entity.dispChar;
    gamedata.screenBuff[entity.yPos][entity.xPos].Attributes = entity.color;
}

// Move an ENTITY (player of monster) south one square
void moveDown(ENTITY &entity) {
    // Make the spot where the entity is currently standing
    // a "floor tile" again
    gamedata.screenBuff[entity.yPos][entity.xPos].Char.AsciiChar = ' ';
    gamedata.screenBuff[entity.yPos][entity.xPos].Attributes = BACKGROUND_BLUE;

    // Move the entity south one position
    entity.yPos++;

    // Draw the entity where he is standing
    gamedata.screenBuff[entity.yPos][entity.xPos].Char.AsciiChar = entity.dispChar;
    gamedata.screenBuff[entity.yPos][entity.xPos].Attributes = entity.color;
}

// Move an ENTITY (player of monster) west one square
void moveLeft(ENTITY &entity) {

    // Make the spot where the entity is currently standing
    // a "floor tile" again
    gamedata.screenBuff[entity.yPos][entity.xPos].Char.AsciiChar = ' ';
    gamedata.screenBuff[entity.yPos][entity.xPos].Attributes = BACKGROUND_BLUE;

    // Move the entity left one position
    entity.xPos--;

    // Draw the entity where he is standing
    gamedata.screenBuff[entity.yPos][entity.xPos].Char.AsciiChar = entity.dispChar;
    gamedata.screenBuff[entity.yPos][entity.xPos].Attributes = entity.color;
}

// Move an ENTITY (player of monster) right one square
void moveRight(ENTITY &entity) {

    // Make the spot where the entity is currently standing
    // a "floor tile" again
    gamedata.screenBuff[entity.yPos][entity.xPos].Char.AsciiChar = ' ';
    gamedata.screenBuff[entity.yPos][entity.xPos].Attributes = BACKGROUND_BLUE;

    // Move the entity up one position
    entity.xPos++;

    // Draw the entity where he is standing
    gamedata.screenBuff[entity.yPos][entity.xPos].Char.AsciiChar = entity.dispChar;
    gamedata.screenBuff[entity.yPos][entity.xPos].Attributes = entity.color;
}



// Draw the maze to the screen
void DrawScreen() {
    COORD buffSize = {SCREEN_WIDTH, SCREEN_HEIGHT}; // This holds the width then
    // height of the "screenBuff"
    // (order IS important)

    COORD buffCoord = {0, 0}; // The upper left hand corner of where we want to
    // begin drawing our "screenBuff" from

    gamedata.screenBuff[gamedata.yEndPos][gamedata.xEndPos].Char.AsciiChar = 'E';
    gamedata.screenBuff[gamedata.yEndPos][gamedata.xEndPos].Attributes = BACKGROUND_BLUE |
            FOREGROUND_RED;

    // All right, this is the function that will blit (draw to the screen) our
    // screenBuff -- So by parameter:
    // gamedata.outputHandle -- A handle to a console screen buffer
    // gamedata.screenBuff -- Pointer to a buffer with that contains the data to write
    //                        (array of CHAR_INFO's to write to the screen)
    // buffSize -- This is the size of the buffer stored as (column,row)
    //             so column * row should equal the number of elements in the array
    //             (in screenBuff)
    // buffCoord -- This defines the upper-left cell (corner) of where to start
    //              drawing from in "screenBuff"
    // &(gamedata.rect) -- Address (pointer to) of SMALL_RECT variable that defines a
    //                     rectangle area that we want to write (draw) to in our window
    WriteConsoleOutput(gamedata.outputHandle, (CHAR_INFO *)gamedata.screenBuff, buffSize, buffCoord,
                       &(gamedata.rect));

}

// This checks the state of the game -- If a you've come in contact with a monster OR
// you've touched the 'E' (gotten to the exit, won the game), we'll change the
// "game state" to be "over" and print out a message (either you won, or you died)
void CheckGameState() {
    // First check to see if you've collided with ANY of the monsters
    for(int i = 0; i < MAX_MONSTERS; i++) {
        // If they're on the same spot -- You have lost the game
        if((monster[i].xPos == player.xPos) && (monster[i].yPos == player.yPos)) {
            cout << "You Lose!!!!!!!" << endl;
            gamedata.gameover = true;
            return;
        }

    }

    // Otherwise if you're on the "exit spot" (the letter 'E')
    if((gamedata.xEndPos == player.xPos) && (gamedata.yEndPos == player.yPos)) {
        // You've won -- YEAH :)
        cout << "Winner and still champion!" << endl;
        gamedata.gameover = true;
    }

} // end of void CheckGameState()


// Returns true when game is over, false otherwise
bool isGameOver() {
    return gamedata.gameover;
}

// Free up the memory the game allocated
void FreeMem() {
    // If we allocated a screen buffer, free it
    if(gamedata.screenBuff)
        delete[] gamedata.screenBuff;
    for(int r = SCREEN_HEIGHT - 1; r >= 0; r--)
        for(int c = 0; c < SCREEN_WIDTH; c++) {
            gamedata.screenBuff[r][c].Char.AsciiChar = 32;
            gamedata.screenBuff[r][c].Attributes = 15;
        }

    FlushConsoleInputBuffer(gamedata.inputHandle); // Remove any "keystrokes" that may
    // be queued up
}




