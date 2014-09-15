#ifndef APPMESSAGE_H
#define APPMESSAGE_H
#define IMAGE_WIDTH  144
#define IMAGE_HEIGHT  144
#define IMAGE_COLS ((IMAGE_WIDTH - 1) / (8 * sizeof(uint32_t)) + 1)
#define IMAGE_ROWS (IMAGE_HEIGHT)
#define NUM_FIRST_MENU_ITEMS 10
#define NUM_MENU_SECTIONS 1

enum {
  SPY_KEY_START,
  SPY_KEY_STOP,
  IMG_START,
  IMG_DATA,
  IMG_STOP,
  IMG_MSG,
};

typedef struct{
  GBitmap*  bm;
  uint8_t*  imgdata;
}Image;






  






static BitmapLayer *image_layer;
static TextLayer *text_layer;
DictionaryIterator *iter;
static int count = 0;
char text_buffer[1024];

static int se = 0;
static Tuple *start_tuple;
static Tuple *data_tuple;
static Tuple *stop_tuple;




void createImg(uint8_t* i);


void timer_callback(void *data);


void out_sent_handler(DictionaryIterator *sent, void *context);


void out_failed_handler(DictionaryIterator *failed, AppMessageResult reason, void *context);


void in_received_handler(DictionaryIterator *received, void *context);


void in_dropped_handler(AppMessageResult reason, void *context);



#endif
