#include "Memento.h"
#include "City.h"
#include "Caretaker.h"
#include <iostream>

Memento::Memento(double populationPool, double employmentPool, double population, double employable,
                 double satisfaction, double earnings, double funds, int day, Map* map )
    : populationPool(populationPool), employmentPool(employmentPool),
      population(population), employable(employable), satisfaction(satisfaction),
      earnings(earnings), funds(funds), day(day), map(map) {}


