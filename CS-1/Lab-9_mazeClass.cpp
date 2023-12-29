//Maze with classes
//Khushi Patel
//22nd december 2023

#include <iostream>
#include <cstdlib>
#include <ctime>
using std::cout; using std::cin; using std::endl;

// room coordinates
class Room {
public:
    Room(): x_(-1), y_('*'){}; // void constructor, assigns -1 to X coord, and * to Y coord
            // use initializer list for implementation

    void pick(){ // selects a random room within the maze
        x_ = 1 + rand() % mazeSize_ ;
        y_ = rand() % mazeSize_ + 'a';
    }
    // selects a random adjacent room
    // uses goodDirection() and createAdjacent()
    const Room pickAdjacent(){
        Room adjacent;
        char dm;
        do{
            const char direction[] = {'u', 'd', 'l', 'r'};
            int random = rand() % 4;
            dm = direction[random];
            if(goodDirection(dm)){
                adjacent = createAdjacent(dm);
            }
        }while(!goodDirection(dm));
        return adjacent;
    }

    // asks the user for the room to move adjacent to this room
    // returns {-1,*} if the user wants to quit
    // uses goodDirection() and createAdjacent()
    const Room nextMove() const{
        Room nextRoom;

        cout << "Enter your next move [u, d, l, r, q]: ";
        char dr; cin >> dr;
        if(dr != 'q'){
            if(goodDirection(dr)){
                nextRoom = createAdjacent(dr);
            }
            else {
                nextRoom = *this;
            }
        }
        return nextRoom;
    } 

    void print() const{   // prints room coordinates in format "a1"
        cout << y_ << x_;
    }

    // make this room the start room
    void makeStartRoom() { x_ = 1; y_ = 'a'; }

    // make this room - the cheese room
    void makeCheeseRoom() { x_ = mazeSize_, y_ = 'a' + mazeSize_ - 1; };

    // predicate returns true if the coordinates of the two rooms match
    friend bool matchRoom(const Room& one, const Room& two){
        if(one.x_ == two.x_ && one.y_ == two.y_) return true;
        return false;
    }
private:
    // checks if this direction keeps the mouse inside the maze
    bool goodDirection(const char dir) const{
        if(dir == 'u' && y_ > 'a') return true;
        if(dir == 'd' && y_ < 'a' + mazeSize_-1) return true;
        if(dir == 'l' && x_ > 1) return true;
        if(dir == 'r' && x_ < mazeSize_) return true;
        return false;
    }
 
    // returns the room adjacent to this room in the specified direction
    // assumes the direction is inside the maze
    const Room createAdjacent(const char dir) const{
        Room adjacent = *this;
        switch(dir){
            case 'u':
                adjacent.y_ = y_ - 1;
                break;
            case 'd':
                adjacent.y_ = y_+ 1;
                break;
            case 'l':
                adjacent.x_ = x_ - 1;
                break;
            case 'r':
                adjacent.x_ = x_ + 1;
                break;
        }
        return adjacent;
    }

    static const int mazeSize_ = 4; // maze is mazeSize * mazeSize
    int x_;  // 1 through mazeSize
    char y_; // 'a' through mazeSize
};


// internal wall or next move
class RoomPair {
public:
    RoomPair() {} // void constructor implicitly invokes void constructors on member variables
    // makes a roomPair out of two rooms
    RoomPair(const Room& one, const Room& two):one_(one), two_(two) {}

    void pick(){ //selects a random wall, uses Room::pickAdjacent()
        one_.pick();
        two_ = one_.pickAdjacent();
    }

    void print() const{ // prints the locations of the two rooms in format a1|b1
        one_.print();   // uses Room::print()
        cout << "|";
        two_.print();      
    }

    // returns true if two pairs of adjacent rooms are the same,
    // returns false otherwise, uses matchRoom() note that r1|r2 matches r2|r1
    friend bool matchPair(const RoomPair& first, const RoomPair& second){
        bool RoomPair_1 = matchRoom(first.one_, second.one_) && matchRoom(first.two_, second.two_); 
        bool RoomPair_2 = matchRoom(first.one_, second.two_) && matchRoom(first.two_, second.one_); 
        return (RoomPair_1 || RoomPair_2);
    }

private:
    Room one_;
    Room two_;
};

class Maze {
public:
    // places every wall between two rooms where x-coordinate is -1
    // and y-coordinate is '*' (a star) to signify that
    // the wall is not built yet
    Maze() {}; 

    // prints the locations of all the internal walls of the maze
    // and current mouse location
    void print() const{
        for(int i=0; i<numWalls_; ++i){
            walls_[i].print();
            cout << ", ";
        }
    }

    // places internal walls in random locations of the maze
    // all walls are different
    void build(){
        int walls = 0;

        while(walls < numWalls_){
            RoomPair first;
            first.pick();
            if(!checkMaze(first)){
                walls_[walls] = first;
                ++walls;
            }
        }
    }

    // places current mouse location in startRoom_;
    void start() { currentRoom_.makeStartRoom(); }

    // takes the room to move the mouse to
    // moves the mouse there and returns true if no walls (move is possible)
    // does not move the mouse and returns false if wall
    bool move(const Room& rm){
        RoomPair newRoom(currentRoom_, rm);
        if(matchRoom(currentRoom_, rm)) return false;

        for(int i=0; i<numWalls_; ++i){
            if(matchPair(walls_[i], newRoom))
                return false;
        }
        currentRoom_ = rm;
        return true;
    }
     
    // returns current mouse location
    const Room getCurrentRoom() { return currentRoom_; }

private:
    // returns true if RoomPair matches one of the walls in the maze
    bool checkMaze(const RoomPair& one) const{
        for(int i=0; i<numWalls_; ++i){
            if(matchPair(walls_[i], one)) 
                return true;
        }
        return false;
    }

    Room currentRoom_; // current mouse Location

    static const int numWalls_ = 8;  // number of internal walls
    RoomPair walls_[numWalls_]; // array of internal maze walls
};

/*
int main() {
    // 
    // checking room functions
    // 
    srand(time(nullptr)); // random seed
    //srand(1); // fixed seed

    
    //
    // first part: checking Room functions
    //

    Room myRoom; // create a room
    cout << "myRoom, default location: "; myRoom.print(); cout << endl;

    myRoom.pick();
    cout << "myRoom, random location: "; myRoom.print(); cout << endl;

    Room startRoom; startRoom.makeStartRoom();
    cout << "start room: "; startRoom.print(); cout << endl;

    Room cheeseRoom; cheeseRoom.makeCheeseRoom();
    cout << "cheese room: "; cheeseRoom.print(); cout << endl;

    // make sure to implement goodDirection() and createAdjacent() first
    Room newMoveRoom = myRoom.nextMove(); // asks user for new adjacent room
    cout << "user selected adjacent room: "; newMoveRoom.print(); cout << endl; 

    if (matchRoom(myRoom, newMoveRoom))
        cout << "myRoom is the same as newMoveRoom" << endl;
    else
        cout << "myRoom is not the same as newMoveRoom" << endl;
    

    //
    // second part: RoomPair functions
    //
    
    RoomPair myPair; 
    cout << "myPair, default location: "; myPair.print(); cout << endl;

    RoomPair otherPair(myRoom, newMoveRoom); // testing a constructor
    cout << "pair of myRoom, newMoveRoom: "; otherPair.print(); cout << endl;

    myPair.pick();
    cout << "random room pair: "; myPair.print(); cout << endl;

    if(matchPair(myPair,otherPair))
        cout << "myPair is the same as otherPair" << endl;
    else
        cout << "myPair is not the same as otherPair" << endl;
     
    //
    // third part: Maze functions
    //
    
    Maze myMaze;
    cout << "maze with no walls: "; myMaze.print();

    myMaze.start();
    cout << endl;

    // make sure to implemnt Maze::checkMaze() before build()
    myMaze.build();
    cout << "maze with walls:"; myMaze.print();
    cout << endl;

    myRoom = myMaze.getCurrentRoom();
    cout << "maze current room: "; myRoom.print(); cout << endl;

    
    newMoveRoom = myRoom.nextMove(); 

    if (myMaze.move(newMoveRoom))
        cout << "move to newMoveRoom is successful" << endl;
    else
        cout << "move to newMoveRoom failed" << endl;

    myRoom = myMaze.getCurrentRoom();
    cout << "maze current room: "; myRoom.print(); cout << endl;
    
}
*/


int main(){
    srand(time(nullptr));

    Maze myMaze;
    myMaze.build();
    myMaze.start();

    Room finishRoom;
    finishRoom.makeCheeseRoom();

    Room currentRoom;
    currentRoom = myMaze.getCurrentRoom();

    Room nextRoom = currentRoom;
    
    cout << "Do you want to see the walls in the maze [y/n]: ";
    char ans; cin >> ans;
    if(ans == 'y'){
        myMaze.print();
    }
    cout << endl;

    while(!matchRoom(finishRoom, currentRoom) && !matchRoom(nextRoom, Room())){
        cout << "Current Room: ";
        currentRoom.print();
        cout << endl;

        nextRoom = currentRoom.nextMove();

        RoomPair first(currentRoom, nextRoom);
        
        if(!matchRoom(nextRoom, Room())){
            if(myMaze.move(nextRoom)){
                cout << "Your move was successful." << endl;
            }
            else {
                cout << "You encountered a wall." << endl;
            }
        }
        currentRoom = myMaze.getCurrentRoom();
    }
    
    if(matchRoom(currentRoom, finishRoom)){
        cout << "Congratulations!! You found the way." << endl;
    }
    else{
        cout << "You quit the game." << endl;
    }


}


