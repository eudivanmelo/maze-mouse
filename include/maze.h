#include <string>

#ifndef MAZE_H
#define MAZE_H

class Maze {
    private:
        struct Tile {
            bool isBlocked;
        };

        Tile** tiles;
        int width, height;

    public:
        Maze(std::string filename);
        Maze(int width, int height);

        ~Maze();

        const int getWidth() const;
        const int getHeight() const;

        bool isBlocked(int x, int y) const;
        void setBlocked(int x, int y, bool blocked);

        // Tile* getTile(int x, int y) const;
};;

#endif