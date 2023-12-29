// //multi-array
// //Khushi Patel
// //27th december 2023

// #include <iostream>

// using std::cout; using std::endl; using std::cin;


// const int mazeLength = 6;
// const int mazeWidth = 6;

// int main(){
   
//    int mouseX = 0; // current mouse X index
//    int mouseY = 0; // current mouse Y index

//    bool maze[mazeLength][mazeWidth]; // declare mouse maze tracking array
//    maze[mouseX][mouseY]= true;  // place mouse in the top-left corner
   
//    // place your code here
//     cout << "  ";
//       for (char c = 'a'; c < 'a' + mazeWidth; ++c) {
//         cout << c << " ";
//     }
//     cout << endl;

//     // Print maze with row labels
//     for (int i = 0; i < mazeLength; ++i) {
//         cout << i + 1 << " ";
//         for (int j = 0; j < mazeWidth; ++j) {
//             if (maze[i][j]) {
//                 cout << "* ";
//             } else {
//                 cout << "  ";
//             }
//         }
//         cout << endl;

//     }
// }





#include <iostream>

using std::cout; using std::endl; using std::cin;

const int mazeLength = 6;
const int mazeWidth = 6;

void printMaze(bool maze[mazeLength][mazeWidth]) {
    // Print column labels
    cout << "  ";
    for (char c = 'a'; c < 'a' + mazeWidth; ++c) {
        cout << c << " ";
    }
    cout << endl;

    // Print maze with row labels
    for (int i = 0; i < mazeLength; ++i) {
        cout << i + 1 << " ";
        for (int j = 0; j < mazeWidth; ++j) {
            if (maze[i][j]) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

int main() {
    int mouseX = 0; // current mouse X index
    int mouseY = 0; // current mouse Y index

    bool maze[mazeLength][mazeWidth] = {false}; // declare mouse maze tracking array
    maze[mouseX][mouseY] = true; // place mouse in the top-left corner (a1)

    char direction;

    do {
        printMaze(maze);

        cout << "Enter direction (l)eft, (r)ight, (u)p, (d)own or (q)uit: ";
        cin >> direction;

        switch (direction) {
            case 'l':
                if (mouseY > 0) {
                    --mouseY;
                    maze[mouseX][mouseY] = true;
                }
                break;

            case 'r':
                if (mouseY < mazeWidth - 1) {
                    ++mouseY;
                    maze[mouseX][mouseY] = true;
                }
                break;

            case 'u':
                if (mouseX > 0) {
                    --mouseX;
                    maze[mouseX][mouseY] = true;
                }
                break;

            case 'd':
                if (mouseX < mazeLength - 1) {
                    ++mouseX;
                    maze[mouseX][mouseY] = true;
                }
                break;

            case 'q':
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid direction. Please enter l, r, u, d, or q." << endl;
        }

    } while (direction != 'q');

    return 0;
}
