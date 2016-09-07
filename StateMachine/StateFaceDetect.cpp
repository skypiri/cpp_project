#include "StateFaceDetect.h"
#include "StateIdle.h"
#include "StateKeyword.h"
#include <iostream>
#include <unistd.h>

using namespace std;
StateFaceDetect* StateFaceDetect::singleton = nullptr;

StateFaceDetect::StateFaceDetect()
{
    cout << __PRETTY_FUNCTION__ << endl;
}

StateFaceDetect::~StateFaceDetect() {
    cout << __PRETTY_FUNCTION__ << endl;
}

StateFaceDetect* StateFaceDetect::getInstance() {
    cout << __PRETTY_FUNCTION__ << endl;
    if(singleton == nullptr) {
        singleton = new StateFaceDetect();
    }

    return singleton;
}

void StateFaceDetect::doEnter() {
    cout << __PRETTY_FUNCTION__ << endl;

}

void StateFaceDetect::doSelf() {
    cout << __PRETTY_FUNCTION__ << endl;
    sleep(1);
    notifyEvent(EVT_RETURN_IDLE);
}

void StateFaceDetect::doLeave(){
    cout << __PRETTY_FUNCTION__ << endl;
}

void StateFaceDetect::takeAction(StateContext *stateContext, Events event) {
    cout << __PRETTY_FUNCTION__ << endl;
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
