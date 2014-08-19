#ifndef APPMESSAGE_H
#define APPMESSAGE_H

enum {
  SPY_KEY_START,
  SPY_KEY_STOP,
  TODO_KEY_MOVE,
  TODO_KEY_TOGGLE_STATE,
  TODO_KEY_FETCH,
};
static BitmapLayer *image_layer;
static uint8_t datar;
static TextLayer *text_layer;
DictionaryIterator *iter;

char text_buffer[1024];
static int se = 0;
Tuple *start_tuple;
  Tuple *stop_tuple;



void createImg(const uint8_t data);

 void timer_callback(void *data);

 void out_sent_handler(DictionaryIterator *sent, void *context);


 void out_failed_handler(DictionaryIterator *failed, AppMessageResult reason, void *context);


 void in_received_handler(DictionaryIterator *received, void *context);


 void in_dropped_handler(AppMessageResult reason, void *context);



#endif
