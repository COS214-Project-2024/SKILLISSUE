#ifndef SASTISFACTIONCALCULATOR_H
#define SASTISFACTIONCALCULATOR_H


class SatisfactionCalculator {
private:
    SCReceiver receiver;

    Map* map;
    std::vector<int>& shuffledTiles;
    std::string taxtype;

public:
    SatisfactionCalculator(Map* map, std::vector<int>& shuffledTiles,std::string taxtype);

    void execute();
};

#endif // SASTISFACTIONCALCULATOR_H
