// ----- LITERALS -----
// Directions
#define NORTH	1
#define EAST	3
#define SOUTH	7
#define WEST	9

#define TNORTH	"North"
#define TEAST	"East"
#define TSOUTH	"South"
#define TWEST	"West"

// Hints
#define MAXHINT	4
#define HINT1	""
#define HINT2	""
#define HINT3	""
#define HINT4	""

// Others
#define MAXSIZE		3
#define MAZESHAPE1	3,2,1
#define MAZESHAPE2	1,3,2

// Instructions
#define BACK	0
#define FORWARD	1
#define TURN	2

// Room Propmpts |																														|
#define ROOM_0	"Before you is a door. A sign above it reads 'If you get lost, backtrack'. You enter into a hallway with another door at the end, and the entrance closes when the second door is opened.\n"
#define DESCRIPTION "The room is square, having a door on each wall. On the ceiling there is a large number '1' oriented to be read properly when facing North.\n"
#define ROOM_N	"You enter Room %i, facing North.\n"
#define ROOM_E	"You enter Room %i, facing South.\n"
#define ROOM_S	"You enter Room %i, facing East.\n"
#define ROOM_W	"You enter Room %i, facing West.\n"
#define GOAL	"Congratulations, you beat the maze!\nl \n"
#define PROMPT	"Which path do you take? ('n'orth, 's'outh, 'e'ast, 'w'est) "

struct mazedata
{
	int shape[MAXSIZE];
	int room;			// Room number
	int direction;		// What side the player is facing
};