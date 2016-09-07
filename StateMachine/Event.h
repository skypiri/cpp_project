#ifndef EVENT_H
#define EVENT_H

typedef enum {
    EVT_DETECT_FACE = 0,
    EVT_DETECT_KEYWORD,
    EVT_RETURN_IDLE
} Events;

void notifyEvent(Events event);

#endif // EVENT_H

