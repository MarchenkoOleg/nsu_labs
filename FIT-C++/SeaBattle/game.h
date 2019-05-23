#ifndef GAME_H
#define GAME_H

#include "computerplayer.h"
#include "field.h"

enum class GameStatus {
    StartNewGame,       // Начать новую игру
    MeAttack,      // Ходит первый игрок
    EnemyAttack,      // Ходит второй игрок
    EndOfGame           // Конец игры
};

class Game {

public:
    GameStatus status;
    Game();
    bool checkPlacing(const std::array<Cell, 100> & fld, Field & f) const;
};

#endif // GAME_H
