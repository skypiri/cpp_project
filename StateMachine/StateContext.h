#ifndef CONTEXT_H
#define CONTEXT_H

#include "Event.h"
#include "State.h"

class StateContext
{
private:

public:
    StateContext();
    virtual ~StateContext();
    void changeState(State *state);
};



#endif // CONTEXT_H
