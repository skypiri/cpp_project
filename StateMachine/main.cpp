#include <iostream>
#include "Event.h"
#include "StateIdle.h"
#include <unistd.h>

using namespace std;

State *mState = StateIdle::getInstance();
StateContext *mStateContext = new StateContext();

void notifyEvent(Events event) {
    cout << __PRETTY_FUNCTION__ << endl;
    mState->takeAction(mStateContext, event);
    mState->doSelf();
}

void StateContext::changeState(State *state) {
    cout << __PRETTY_FUNCTION__ << endl;
    mState->doLeave();
    mState = state;
    mState->doEnter();
}

int main()
{
    cout << "FSM Demo!" << endl;

    notifyEvent(EVT_RETURN_IDLE);

    while(1) {
        sleep(5);
        fprintf(stderr, ".\n");
    }

    return 0;
}




