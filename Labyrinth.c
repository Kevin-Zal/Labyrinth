#include <stdio.h>
#include "Labyrinth.h"
/*	~~~~~~~~~~ Current problems ~~~~~~~~~~
	Navigation of the maze looses track when turning.
	Orientation changes to the opposite direction when TURNED.
*/
// Function list.
int QueryInput (void);
int Movement (int m_enter, int m_exit);
void Navigation(struct mazedata *playloc);
void RoomText(struct mazedata *roomdata);

int main()
{
	int choice,			// Returned variable from the QueryInput function.
		stage = 0,		// Keep track of what tumbler in the maze we are working on.
		mazeshape[3] = {MAZESHAPE1};
	struct mazedata maze;
	for (int i = 0; i < 3; i++)
	{
		maze.shape[i] = mazeshape[i];
	}
	maze.room = 0;

	do
	{
		switch (maze.room)		// Keep track of where in the maze we are.
		{
		case 0:
			printf(ROOM_0);
			maze.room = 1;
			maze.direction = NORTH;
			break;
		case 1:
			RoomText(&maze);
			Navigation(&maze);
			break;
		case 2:
			RoomText(&maze);
			Navigation(&maze);

			break;
		case 3:
			RoomText(&maze);
			Navigation(&maze);

			break;
		case 4:
			RoomText(&maze);
			Navigation(&maze);

			break;
		case 5:
			RoomText(&maze);
			Navigation(&maze);

			break;
		case 6:
			printf(GOAL);
			maze.room = 0;
			break;
		default:
			break;
		}
		
	} while (1);

	return 0;
}

// Collects the input instruction from the user and translates it for the code to process.
int QueryInput (void)
{
	int qi_choice = 0;
	static int hint = 0;
	while (qi_choice == 0)
	{
		printf(PROMPT);		// Prompts the player to choose a direction.
		switch (getchar())
		{
		case 'n':
			qi_choice = NORTH;
			break;
		case 'e':
			qi_choice = EAST;
			break;
		case 's':
			qi_choice = SOUTH;
			break;
		case 'w':
			qi_choice = WEST;
			break;
		case 'h':			// Get the next hint.
			//hint <= MAXHINT ? hint++ : hint = 4;
			break;
		default:
			break;
		}
		getchar();			// Clear the character buffer.
		// This is calling twice for no reason ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	}
	return qi_choice;
}

// Processes the players input and converts it into a move.
int Movement (int m_enter, int m_exit)
{
	int destination = m_enter + m_exit,
		m_move;
	if (m_enter == m_exit)
	{m_move = FORWARD;}
	else if ((destination == 8) || (destination == 12))
	{m_move = BACK;}
	else
	{m_move = TURN;}

	return m_move;
}

// Navigates through the maze
void Navigation(struct mazedata *playloc)
{
	//static int stage = 0;			// Keep track of what tumbler in the maze we are working on.
	int choice = QueryInput();		// Returned variable from the QueryInput function.
	/*if (playloc->room == 1)
	{
		stage = 0;
	}*/
	switch (Movement(playloc->direction, choice))
	{
	case FORWARD:
		if (playloc->room < playloc->shape[playloc->room])	// If the player hasn't made it to the first tumbler ...
		{
			playloc->room++;					// Advance to the next room
		}
		else
		{
			playloc->room = 1;					// Send them back to room 1
		}
		break;
	case TURN:
		if (playloc->room == playloc->shape[playloc->room])
		{
			playloc->room++;
			playloc->direction = choice;
		}
		break;
	case BACK:
		playloc->room = 0;
		break;
	default:
		break;
	}
}

// Prints the room information.
void RoomText(struct mazedata* roomdata)
{
	switch (roomdata->direction)
	{
	case NORTH:
		printf(ROOM_N, roomdata->room);
		break;
	case EAST:
		printf(ROOM_E, roomdata->room);
		break;
	case SOUTH:
		printf(ROOM_S, roomdata->room);
		break;
	case WEST:
		printf(ROOM_W, roomdata->room);
		break;
	default:
		break;
	}
}
