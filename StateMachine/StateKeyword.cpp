#include "StateKeyword.h"
#include "StateIdle.h"
#include "StateFaceDetect.h"
#include <iostream>

using namespace std;

StateKeyword* StateKeyword::singleton = nullptr;

StateKeyword::StateKeyword()
{
    cout << __PRETTY_FUNCTION__ << endl;
}

StateKeyword::~StateKeyword() {
    cout << __PRETTY_FUNCTION__ << endl;
}

StateKeyword* StateKeyword::getInstance() {
    if(singleton == nullptr) {
        singleton = new StateKeyword();
    }

    return singleton;
}

void StateKeyword::doEnter() {
    cout << __PRETTY_FUNCTION__ << endl;
}

void StateKeyword::doSelf() {
    cout << __PRETTY_FUNCTION__ << endl;
}

void StateKeyword::doLeave(){
    cout << __PRETTY_FUNCTION__ << endl;
}

void StateKeyword::takeAction(StateContext *stateContext, Events event) {
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



