#ifndef FIELD_H
#define FIELD_H

#include <array>
#include <vector>
#include <ctime>

#include "ship.h"

enum class ShipPosition : bool {
    VERTICAL,
    HORIZONTAL
};

enum class Cell{
   CL_CLEAR,
   CL_SHIP,
   CL_DOT,
   CL_HALF,
   CL_FULL
};

enum class ShootResult {
    NO_HITS,
    WOUND,
    KILL,
    REPETITION
};

struct ShipContainer {
    Ship ship;
    std::vector<std::pair<int, int>> coordinates; //координаты палуб корабля (x, y)
};


class Field {
private:
    int numOfShips;
    std::array<Cell, 100> field;
    std::vector<ShipContainer> ships;

    void killFrameCells(const ShipContainer & s);

public:
    Field();
    bool checkPlacing();
    int getNumOfShips();
    bool setShip(int x, int y, const Ship & ship, ShipPosition pos);
    void autoPlaceShips();
    ShootResult shoot(int x, int y);//0 - без попаданий, 1 - ранил, 2 - убил, 3 - уже был ход на эту клетку
    void clear();//очистка поля от всех кораблей
    void fill(const std::array<Cell, 100> & fld); //гарантируется, что корабли расставлены правильно
    const std::array<Cell, 100> & getFieldInstance() const;
    const std::array<Cell, 100> getFieldInstanceForEnemy() const;
};

#endif // FIELD_H
