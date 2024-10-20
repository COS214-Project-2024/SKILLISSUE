#ifndef TRANPORTATIONROUTING_H
#define TRANPORTATIONROUTING_H

class TranportationRouting {

private:
	TransportationRouting* linkedListRoute;
	TransportationRouting* up_down_left_right;
	int cost;
	routeIterator iterator;

public:
	TransportationRouting* findRoute(int pointA, int pointB);
};

#endif
