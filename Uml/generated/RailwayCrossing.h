#ifndef RAILWAYCROSSING_H
#define RAILWAYCROSSING_H

class RailwayCrossing : TranportationRouting {

public:
	Railway* wrappee;

	RailwayCrossing(Railway* railway);
};

#endif
