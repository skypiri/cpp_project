#ifndef STATEKEYWORD_H
#define STATEKEYWORD_H

#include "State.h"
#include "StateContext.h"

class StateKeyword : public State
{
private:
    StateKeyword();
    static StateKeyword* singleton;

public:
    ~StateKeyword();
    static StateKeyword* getInstance();

    void doEnter();
    void doSelf();
    void doLeave();

    void takeAction(StateContext *stateContext, Events event);
};

#endif // STATEKEYWORD_H
