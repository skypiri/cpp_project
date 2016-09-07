#ifndef STATE_H
#define STATE_H

#include "Event.h"

class StateContext;

class State {
private:
public:
    State(){};
    virtual ~State(){};

    virtual void doEnter() = 0;
    virtual void doSelf() = 0;
    virtual void doLeave() = 0;

    virtual void takeAction(StateContext *stateContext, Events event) = 0;
};

#endif // STATE_H

