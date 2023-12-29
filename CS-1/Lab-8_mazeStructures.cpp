//maze with structures
//Khushi Patel
//19th december 2023

#include <iostream>
#include <ctime>
#include <cstdlib>
using std::cout; using std::cin; using std::endl;


const int mazeSize = 4; // maze is mazeSize * mazeSize
const int numWalls = 8;  // number of internal walls

//
// data structures definitions
//

struct Room {
    int x;  // 1 through mazeSize
    char y; // 'a' through mazeSize
};

const Room startRoom = { 1, 'a' };
const Room cheeseRoom = { mazeSize, 'a' + mazeSize-1 };

// internal maze wall
struct RoomPair{
    Room one;
    Room two;
};


//
// initialization functions
//

// initializes the array of walls by placing every RoomPair to connect
// two non-existant rooms where x-coordinate is -1 and y-coordinate is '*' (a star)
// to signify that the walls are not built yet
void clearWalls(RoomPair room[]){
    for(int i=0; i<numWalls; ++i){
        room[i].one.x = -1;
        room[i].one.y = '*';
        room[i].two.x = -1;
        room[i].two.y = '*';
    }
}

// checks if direction dr ('u', 'd', 'l', or 'r')
// applied to Room rm keeps the mouse inside the maze
bool goodDirection(const Room &rm, const char dr){
    if(dr == 'u' && rm.y > 'a') return true;
    if(dr == 'd' && rm.y < 'a' + mazeSize-1) return true;
    if(dr == 'l' && rm.x > 1) return true;
    if(dr == 'r' && rm.x < mazeSize) return true;
    return false;
}
 
// returns the room adjacent to room rm
// in the specified direction dr 
// assumes the direction is inside the maze
Room createAdjacent(const Room &rm, const char dr){
    Room adjacent = rm;
    switch(dr){
        case 'u':
            adjacent.y = rm.y - 1;
            break;
        case 'd':
            adjacent.y = rm.y + 1;
            break;
        case 'l':
            adjacent.x = rm.x - 1;
            break;
        case 'r':
            adjacent.x = rm.x + 1;
            break;
    }
    return adjacent;
}


// selects a random room adjacent to Room rm
// uses goodDirection() and createAdjacent()
const Room pickAdjacent(const Room &rm){
    Room adjacent = rm; 
    char dm;
    do{
        const char direction[] = {'u', 'd', 'l', 'r'};
        int random = rand() % 4;
        dm = direction[random];
        if(goodDirection(rm,dm)){
            adjacent = createAdjacent(rm, dm);
        }
    }while(!goodDirection(rm,dm));
    return adjacent;
}


// selects a random wall, uses pickAdjacent()
const RoomPair pickPair(){
    Room one;
    Room two;
    int x = 1 + rand() % mazeSize;
    char y = 'a' + rand() % mazeSize;
    one.x = x; one.y = y;
    two = pickAdjacent(one);

    RoomPair rp;
    rp.one = one;
    rp.two = two;

    return rp;
}


// predicate returns true if the coordinates of the two rooms match
bool matchRoom(const Room& one, const Room& two){
    if(one.x == two.x && one.y == two.y) return true;
    return false;
} 

// returns true if two pairs of adjacent rooms are the same, 
// returns false otherwise, uses matchRoom()
// note that r1|r2 matches r2|r1
bool matchPair(const RoomPair& first, const RoomPair& second){
    bool RoomPair_1 = matchRoom(first.one, second.one) && matchRoom(first.two, second.two); 
    bool RoomPair_2 = matchRoom(first.one, second.two) && matchRoom(first.two, second.one); 
    return (RoomPair_1 || RoomPair_2);
} 

// returns true if rp matches one of the wall in the array
// false otherwise
// uses matchPair()
bool checkMaze(const RoomPair one[], const RoomPair &rp){
    for(int i=0; i<numWalls; ++i){
        if(matchPair(one[i], rp))
            return true;
    }
    return false;
}


// places internal walls in random locations of the maze
void build(RoomPair rp[]){
    int walls = 0;

    while(walls < numWalls){
        RoomPair first;
        first = pickPair();
        if(!checkMaze(rp,first)){
            rp[walls] = first;
            ++walls;
        }
    }
}

//
// display functions
//
void printRoom(const Room& rm){ // prints the location of the room
    cout << rm.x << rm.y; 
}
void printPair(const RoomPair& rp){ // prints the locations of the adjacent rooms
    cout << rp.one.x << rp.one.y << "| " << rp.two.x << rp.two.y;
}
void printMaze(const RoomPair rp[]){ // prints the locations of all the internal //walls of the maze // uses printPair
    for(int i=0; i<numWalls; ++ i){
        printPair(rp[i]);
        cout << endl;
    }
}

//
// game functions
//

// asks the user for the direction and generates the next room
// to move to
// uses goodDirection() to valid (does not go outside external walls) and
//      createAdjacent() to generate the room for the next move
// returns {-1,*} if the user wants to quit
const Room nextMove(const Room& currentRoom){
    Room nextRoom = currentRoom;
    Room base = {-1,'*'};
    cout << "Enter your next move [u, d, l, r, q]: ";
    char dr; cin >> dr;
    if(goodDirection(currentRoom,dr)){
        nextRoom = createAdjacent(currentRoom,dr);
    }
    else if(dr == 'q') {nextRoom = base;}

    return nextRoom;
}

// note that checkMaze() is also used in the game





//Test-file
/*
int main() {

    // srand(time(nullptr)); // random seed
    srand(1); // fixed seed

    //
    // first part: checking Room functions
    //

    Room myRoom; // create a room
    myRoom.x = 2;
    myRoom.y = 'b';

    // print Room
    cout << "myRoom, fixed location: "; printRoom(myRoom); cout << endl;

    // make sure to implement goodDirection() and createAdjacent() first
    Room newMoveRoom = nextMove(myRoom); // asks user for new adjacent room
    cout << "user selected adjacent room: "; printRoom(newMoveRoom); cout << endl;
   
    Room randomRoom = pickAdjacent(myRoom);
    cout << "randomly selected adjacent room: "; printRoom(randomRoom); cout << endl;

    
    if(matchRoom(randomRoom, newMoveRoom))
        cout << "randomRoom is the same as newMoveRoom" << endl;

    //
    // second part: checking wall functions
    //
    
    // select a fixed wall
    RoomPair myWall = { {2,'b'}, {2,'c'} };

    // print wall 
    cout << "myWall, fixed location: "; printPair(myWall); cout << endl;

    // select and print a random wall
    myWall = pickPair();
    cout << "myWall, random location: "; printPair(myWall); cout << endl;

    RoomPair myMove; myMove.one = myRoom; myMove.two = newMoveRoom;

    if (matchPair(myWall, myMove))
        cout << "there is a wall between these two rooms" << endl;
    else
       cout << "there is no wall between these two rooms" << endl;
     
    //
    // third part: check maze functions
    //
    
    RoomPair myMaze[numWalls]; // array of walls in the maze

    clearWalls(myMaze); //assigning -1 and '*' to all rooms of the walls 

    // printing walls of the maze
    cout << "uninitialized maze walls: ";  printMaze(myMaze); cout << endl;

    if (checkMaze(myMaze, myMove))
       cout << "checkMaze returned true" << endl;
    else
       cout << "checkMaze returned false" << endl;

    build(myMaze); // placing walls at random locations in the maze
    cout << "built maze: ";  printMaze(myMaze); cout << endl;
    
}
*/

int main(){
    srand(time(nullptr));
    
    RoomPair rp[numWalls];
    clearWalls(rp);
    cout << endl;
    build(rp);
    //printMaze(rp);
    cout << endl;

    Room initialLoc = startRoom;
    Room endLoc = cheeseRoom;
    Room nextLoc = initialLoc;
    Room base = {-1,'*'};

    cout << "Would you want to see the walls [y/n]: ";
    char viewMaze; cin >> viewMaze;
    if (viewMaze == 'y') {
        printMaze(rp);
    }


    while(!matchRoom(initialLoc, endLoc) ){
        cout << "Current room: ";
        printRoom(initialLoc);
        cout << endl;

        nextLoc = nextMove(initialLoc);
        RoomPair first = {nextLoc,initialLoc};
 
        if(!matchRoom(nextLoc, base)){
            if(!checkMaze(rp,first)){
                initialLoc = nextLoc;
                //cout << "Next room: ";
                //printRoom(initialLoc);
                //cout << endl;
            }
            else {
                cout << "You encountered a wall" << endl;
            }
        }
    }
    if(matchRoom(initialLoc, endLoc)){
        cout << "You cleared the maze!" << endl; 
    }
    else{
        cout << "You quit the game." << endl;
    }

}