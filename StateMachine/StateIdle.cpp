#include "StateIdle.h"
#include "StateFaceDetect.h"
#include "StateKeyword.h"
#include "StateFaceDetect.h"
#include <iostream>
#include <unistd.h>

using namespace std;

StateIdle* StateIdle::singleton = nullptr;

StateIdle::StateIdle() {
    cout << __PRETTY_FUNCTION__ << endl;
}

StateIdle::~StateIdle() {
    cout << __PRETTY_FUNCTION__ << endl;
}

StateIdle* StateIdle::getInstance() {
    cout << __PRETTY_FUNCTION__ << endl;
    if(singleton == nullptr) {
        singleton = new StateIdle();
    }
    return singleton;
}

void StateIdle::doEnter() {
    cout << __PRETTY_FUNCTION__ << endl;
    idleCount = 0;
}

void StateIdle::doSelf() {
    cout << __PRETTY_FUNCTION__ << endl;
    cout << "Idle Count : " << idleCount++ << endl;

    sleep(1);
    if(idleCount < 5) {
        this->doSelf();
    } else {
        notifyEvent(EVT_DETECT_FACE);
    }
}

void StateIdle::doLeave() {
    cout << __PRETTY_FUNCTION__ << endl;
}

void StateIdle::takeAction(StateContext *stateContext, Events event) {
    cout << __PRETTY_FUNCTION__ << ": Event => " << event << endl;
    switch(event) {
    case EVT_DETECT_FACE :
        stateContext->changeState(StateFaceDetect::getInstance());
        break;
    case EVT_DETECT_KEYWORD :
        stateContext->changeState(StateKeyword::getInstance());
        break;
    case EVT_RETURN_IDLE :
        stateContext->changeState(StateIdle::getInstance());
        break;
    default : break;
    }

}
