# nam
    for (int i = 0; i < level.size(); i++) {
        for (int j = 0; j < level[i].size(); j++) {
            if (level[i][j] == Player) {
                playerX = i;
                playerY = j;
                return;
            }
        }
    }
}

void DrawLevel() {
    for (int i = 0; i < level.size(); i++) {
        for (int j = 0; j < level[i].size(); j++) {
            cout << level[i][j];
        }
        cout << endl;
    }
}

void ProcessInput(char input) {
    int newX = playerX;
    int newY = playerY;

    switch (input) {
        case 'w':
            newX--;
            break;
        case 's':
            newX++;
            break;
        case 'a':
            newY--;
            break;
        case 'd':
            newY++;
            break;
        default:
            return;
    }

    if (level[newX][newY] == EmptyCell) {
        level[playerX][playerY] = EmptyCell;
        level[newX][newY] = Player;
        playerX = newX;
        playerY = newY;
    } else if (level[newX][newY] == Box) {
        int boxNewX = newX + (newX - playerX);
        int boxNewY = newY + (newY - playerY);

        if (level[boxNewX][boxNewY] == EmptyCell) {
            level[playerX][playerY] = EmptyCell;
            level[newX][newY] = Player;
            level[boxNewX][boxNewY] = Box;
            playerX = newX;
            playerY = newY;
        }
    }
}
