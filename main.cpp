#include <iostream>
#include <vector>
using namespace std;

struct Position {
    int x;
    int y;
    int z;
};

enum Direction { N, S, E, W, Up, Down};
Direction rovdir=N;

void moveForward(Position &pos, Direction dir) {
    switch (dir) {
        case N:
            pos.y++;
            break;
        case S:
            pos.y--;
            break;
        case E:
            pos.x++;
            break;
        case W:
            pos.x--;
            break;
        case Up:
            pos.z++;
            break;
        case Down:
            pos.z--;
            break;
    }
}

void moveBackward(Position &pos, Direction dir) {
    switch (dir) {
        case N:
            pos.y--;
            break;
        case S:
            pos.y++;
            break;
        case E:
            pos.x--;
            break;
        case W:
            pos.x++;
            break;
        case Up:
            pos.z--;
            break;
        case Down:
            pos.z++;
            break;
    }
}

void turnLeft(Direction &dir) {
    switch (dir) {
        case N:
            dir = W;
            rovdir = W;
            break;
        case S:
            dir = E;
            rovdir = E;
            break;
        case E:
            dir = N;
            rovdir = N;
            break;
        case W:
            dir = S;
            rovdir = S;
            break;
        case Up:
            dir = rovdir;
            turnLeft(dir);
            break;
        case Down:
            dir = rovdir;
            turnLeft(dir);
            break;
    }
}

void turnRight(Direction &dir) {
    switch (dir) {
        case N:
            dir = E;
            rovdir = E;
            break;
        case S:
            dir = W;
            rovdir = W;
            break;
        case E:
            dir = S;
            rovdir = S;
            break;
        case W:
            dir = N;
            rovdir = N;
            break;
        case Up:
            dir = rovdir;
            turnRight(dir);
            break;
        case Down:
            dir = rovdir;
            turnRight(dir);
            break;
    }
}

void turnUp(Direction &dir) {
    dir = Up;
}

void turnDown(Direction &dir) {
    dir = Down;
}

int main() {
    Position pos = {0, 0, 0};
    Direction dir = N;

    vector<char> commands = {'f', 'r', 'u', 'b', 'l'};

    for (char command : commands) {
        switch (command) {
            case 'f':
                moveForward(pos, dir);
                break;
            case 'b':
                moveBackward(pos, dir);
                break;
            case 'l':
                turnLeft(dir);
                break;
            case 'r':
                turnRight(dir);
                break;
            case 'u':
                turnUp(dir);
                break;
            case 'd':
                turnDown(dir);
                break;
        }
    }

    cout << "Final Position: (" << pos.x << ", " << pos.y << ", " << pos.z << ")" << endl;
    cout << "Final Direction: ";
    switch (dir) {
        case N:
            cout << "N";
            break;
        case S:
            cout << "S";
            break;
        case E:
            cout << "E";
            break;
        case W:
            cout << "W";
            break;
        case Up:
            cout << "Up";
            break;
        case Down:
            cout << "Down";
            break;
    }
    cout << endl;

    return 0;
}
