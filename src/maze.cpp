#include "../include/maze.h"

#include <fstream>

/**
 * @brief Construtor da classe Maze que inicializa o labirinto a partir de um arquivo.
 * 
 * @param filename O nome do arquivo que contém a representação do labirinto.
 * 
 * @throws std::runtime_error Se o arquivo não puder ser aberto.
 * 
 * O construtor lê o arquivo linha por linha para determinar a largura e altura do labirinto.
 * Cada linha do arquivo representa uma linha do labirinto, onde '1' indica uma parede (isBlocked = true)
 * e qualquer outro caractere indica um espaço livre (isBlocked = false).
 * 
 * @note Possíveis erros:
 * - O código assume que todas as linhas do arquivo têm o mesmo comprimento, o que pode não ser o caso.
 */
Maze::Maze(std::string filename) {
    std::ifstream file(filename);

    // Verifica se o arquivo foi aberto corretamente
    if (!file.is_open()){
        throw std::runtime_error("Não foi possível abrir o arquivo " + filename);
        return;
    }

    std::string line;
    width = 0, height = 0;

    // Lê o arquivo linha por linha
    while (getline(file, line)){
        // Define a largura do labirinto com base na primeira linha
        if (width == 0){
            width = line.size();
            tiles = new Tile*[1];
        }

        // Cria um novo array de ponteiros para Tile com uma linha a mais
        Tile** newTiles = new Tile*[height + 1];
        for(int i = 0; i < height; i++){
            newTiles[i] = tiles[i];
        }

        // Adiciona uma nova linha de Tiles
        newTiles[height] = new Tile[width];

        // Libera a memória do array antigo e atualiza o ponteiro
        delete[] tiles;
        tiles = newTiles;

        // Define se cada Tile na nova linha é bloqueado ou não
        for(int i = 0; i < width; i++){
            setBlocked(i, height, (line[i] == '1'));
        }

        height++;
    }
}

Maze::~Maze(){
    for(int i = 0; i < getHeight(); i++){
        delete[] tiles[i];
    }
    delete[] tiles;
}

const int Maze::getHeight() const {
    return height;
}

const int Maze::getWidth() const {
    return width;
}

bool Maze::isBlocked(int x, int y) const {
    return tiles[y][x].isBlocked;
}

void Maze::setBlocked(int x, int y, bool blocked){
    tiles[y][x].isBlocked = blocked;
}