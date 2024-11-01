#ifndef MEMENTO_H
#define MEMENTO_H

#include "Map.h"
class City;      // Forward declaration
class Caretaker; // Forward declaration

class Memento {
    friend class City;  // Grant `City` access to private members

private:
    double populationPool;
    double employmentPool;
    double population;
    double employable;
    double satisfaction;
    double earnings;
    double funds;
    int day;
    Map map;

public:
    Memento(double populationPool, double employmentPool, double population, double employable,
            double satisfaction, double earnings, double funds, int day, const Map& map);

    static void storeInCaretaker(City& city, Caretaker* caretaker);  // Static function to create and store Memento
};

#endif // MEMENTO_H
