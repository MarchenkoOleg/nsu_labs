#ifndef SHIP_H
#define SHIP_H

#include <array>
#include <vector>

enum ShipState {
    ALIVE,
    DESTROYED
};

class Ship
{
public:
    Ship(int rk = 1);
    void shoot(int num);
    int getRank() const;
    const std::array<ShipState, 5> & getStates() const;
    bool isAlive() const;

private:
    std::vector<std::pair<int, int>> coordinates;
    int rank;
    std::array<ShipState, 5> state;
    bool alive;
};

#endif // SHIP_H
