#ifndef STATEIDLE_H
#define STATEIDLE_H

#include "State.h"
#include "StateContext.h"

class StateIdle : public State
{
private:
    static StateIdle *singleton;
    int idleCount = 0;

public:
    StateIdle();
    ~StateIdle();
    static StateIdle* getInstance();
    void doEnter();
    void doSelf();
    void doLeave();

    void takeAction(StateContext *stateContext, Events event);
};

#endif // STATEIDLE_H
