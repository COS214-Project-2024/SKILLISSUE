#include "Memento.h"
#include "City.h"
#include "Caretaker.h"
#include <iostream>

Memento::Memento(double populationPool, double employmentPool, double population, double employable,
                 double satisfaction, double earnings, double funds, int day, const Map& map)
    : populationPool(populationPool), employmentPool(employmentPool),
      population(population), employable(employable), satisfaction(satisfaction),
      earnings(earnings), funds(funds), day(day), map(map) {}

void Memento::storeInCaretaker(City& city, Caretaker* caretaker) {
    // Use getter methods for accessing private members
    Memento* memento = new Memento(city.getHomeless(), city.getUnemployed(), city.population, 
                                   city.employable, city.satisfaction, city.earnings, city.funds, 
                                   city.day, *city.map);
    caretaker->storeMemento(memento);
    std::cout << "Saved Memento for Day " << city.day << "\n";
    std::cout << "  Population Pool: " << city.getHomeless() << "\n";
    std::cout << "  Employment Pool: " << city.getUnemployed() << "\n";
    std::cout << "  Population: " << city.population << "\n";
    std::cout << "  Employable: " << city.employable << "\n";
    std::cout << "  Satisfaction: " << city.satisfaction << "\n";
    std::cout << "  Earnings: " << city.earnings << "\n";
    std::cout << "  Funds: " << city.funds << "\n";
}
