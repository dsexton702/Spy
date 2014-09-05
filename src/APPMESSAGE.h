#ifndef APPMESSAGE_H
#define APPMESSAGE_H
#define IMAGE_WIDTH  144
#define IMAGE_HEIGHT  144
#define IMAGE_COLS ((IMAGE_WIDTH - 1) / (8 * sizeof(uint32_t)) + 1)
#define IMAGE_ROWS (IMAGE_HEIGHT)
#define NUM_FIRST_MENU_ITEMS 9
#define NUM_MENU_SECTIONS 1

enum {
  SPY_KEY_START,
  SPY_KEY_STOP,
  IMG_KEY,
  IMG_ROW,
  TODO_KEY_FETCH,
};
static BitmapLayer *image_layer;
static uint8_t datar;
static TextLayer *text_layer;
DictionaryIterator *iter;
static int count = 0;
char text_buffer[1024];
    static BitmapLayer *img_layer;
    static GBitmap img;
static int se = 0;
Tuple *start_tuple;
static uint8_t img_data[20*144];


  Tuple *stop_tuple;



void createImg();


 void timer_callback(void *data);

 void out_sent_handler(DictionaryIterator *sent, void *context);


 void out_failed_handler(DictionaryIterator *failed, AppMessageResult reason, void *context);


 void in_received_handler(DictionaryIterator *received, void *context);


 void in_dropped_handler(AppMessageResult reason, void *context);



#endif
