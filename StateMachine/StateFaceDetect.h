#ifndef STATEFACEDETECT_H
#define STATEFACEDETECT_H

#include "State.h"
#include "StateContext.h"

class StateFaceDetect : public State
{
private :
    StateFaceDetect();
    static StateFaceDetect *singleton;

public:
    ~StateFaceDetect();
    static StateFaceDetect *getInstance();

    void doEnter();
    void doSelf();
    void doLeave();

    void takeAction(StateContext *stateContext, Events event);
};

#endif // STATEFACEDETECT_H
