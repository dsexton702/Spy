#include "pebble.h"
#include "APPMESSAGE.h"




static AppSync sync;
static Window *window;
static Window *windows;
bool record = false;
static AppTimer *timerz;
static Layer *layer;
static AppTimer *timers;
static AppTimer *timer;
Layer *window_layers;
static GBitmap *image;
static GBitmap *images;
static GBitmap *imagez;
static bool play = false;
static int transNum;
DictionaryIterator *outbox;
static uint32_t chunk = 0;
static Tuple *start_tuple;
static Tuple *data_tuple;
static Tuple *stop_tuple;

static uint32_t length = 0;
static uint8_t *data = NULL;
static uint32_t *index = 0;



static char *pee = "Recording...";
static char *peep = "";
static Layer *window_layer;
static AppSync sync;
static ActionBarLayer *action_bar;

static char *text = "Security off";

static uint8_t sync_buffer[1024];
static TextLayer *text_layer;
// This is a menu layer
// You have more control than with a simple menu layer
static MenuLayer *menu_layer;
static BitmapLayer *image_layer;
static MenuLayer *menu_layers;

// Menu items can optionally have an icon drawn with them





static int current_icon = 0;
enum WeatherKey {
  WEATHER_ICON_KEY = 0x1  // TUPLE_CSTRING
};


// You can draw arbitrary things in a menu item such as a background
static GBitmap *menu_background;

// A callback is used to specify the amount of sections of menu items
// With this, you can dynamically add and remove sections
static uint16_t menu_get_num_sections_callback(MenuLayer *menu_layer, void *data) {
  return NUM_MENU_SECTIONS;
}

// Each section has a number of items;  we use a callback to specify this
// You can also dynamically add and remove items using this
static uint16_t menu_get_num_rows_callback(MenuLayer *menu_layer, uint16_t section_index, void *data) {
 
      return NUM_FIRST_MENU_ITEMS;

    
  
  
}

static uint16_t menu_get_num_rows_callbacks(MenuLayer *menu_layer, uint16_t section_index, void *data) {
 
      return 2;

    
  
  
}

void sendMes(Tuplet tup){
app_message_outbox_begin(&iter);

  
  dict_write_tuplet(iter, &tup);
  dict_write_end(iter);

  app_message_outbox_send();

}


  
 static void timer_modss(){
   if(record == false){
  text_layer_set_text(text_layer, pee);
     record = true;

   }else
     if(record == true){
  text_layer_set_text(text_layer, peep);     
     
          record = false;


   }
               timer = app_timer_register(1500 /* milliseconds */, timer_modss, NULL);

 }



static void send_cmd(void) {
 DictionaryIterator *iters;
   uint32_t chunk_size = app_message_inbox_size_maximum() - dict_calc_buffer_size(1);

  Tuplet symbol_tuz = TupletInteger(SPY_KEY_START, 116);

 if(iters == NULL){
   return;
 }
  app_message_outbox_begin(&iters);
    dict_write_tuplet(iters, &symbol_tuz);
   dict_write_end(iters);
  if((app_message_outbox_send() == APP_MSG_OK)) {
    app_message_outbox_send();
  }
}



  
static void timer_mods(){
app_timer_cancel(timerz);
 layer_destroy(text_layer_get_layer(text_layer));

app_timer_cancel(timer);



}


static void my_previous_click_handler(ClickRecognizerRef recognizer, void *context) {
      register int sgiiz = 11;

  
     register Tuplet symbol_tuple = TupletInteger(SPY_KEY_START, sgiiz);
    sendMes(symbol_tuple);
}






static void my_next_click_handler(ClickRecognizerRef recognizer, void *context) {
 
         register int sgiiz = 11;

  
     register Tuplet symbol_tuple = TupletInteger(SPY_KEY_START, sgiiz);
    sendMes(symbol_tuple);
     
  


}


static void my_select_click_handler(ClickRecognizerRef recognizer, void *context) {
 
 register int sgiiz = 12;

  
     register Tuplet symbol_tuple = TupletInteger(SPY_KEY_START, sgiiz);
    sendMes(symbol_tuple);  

   Window *window = (Window *)context;


}



static void my_previous_click_handlers(ClickRecognizerRef recognizer, void *context) {
      register int sgiiz = 5;

  
     register Tuplet symbol_tuple = TupletInteger(SPY_KEY_START, sgiiz);
    sendMes(symbol_tuple);
}






static void my_next_click_handlers(ClickRecognizerRef recognizer, void *context) {
 
         register int sgiiz = 5;

  
     register Tuplet symbol_tuple = TupletInteger(SPY_KEY_START, sgiiz);
    sendMes(symbol_tuple);
     
  


}


static void my_select_click_handlers(ClickRecognizerRef recognizer, void *context) {
 
      
 register int sgiiz = 12;

  
     register Tuplet symbol_tuple = TupletInteger(SPY_KEY_START, sgiiz);
    sendMes(symbol_tuple);  
 Window *window = (Window *)context;

}





void click_config_provider(void *context) {
  window_single_click_subscribe(BUTTON_ID_DOWN, (ClickHandler) my_next_click_handler);
    //  window_single_click_subscribe(BUTTON_ID_SELECT, (ClickHandler) my_select_click_handler);

  window_single_click_subscribe(BUTTON_ID_UP, (ClickHandler) my_previous_click_handler);
}


void click_config_providers(void *context) {
  window_single_click_subscribe(BUTTON_ID_DOWN, (ClickHandler) my_next_click_handlers);
  
   // window_single_click_subscribe(BUTTON_ID_SELECT, (ClickHandler) my_select_click_handlers);

  window_single_click_subscribe(BUTTON_ID_UP, (ClickHandler) my_previous_click_handlers);
}

static void timer_mod(){
  

text_layer_set_text(text_layer, "Picture Taken");



timer = app_timer_register(600 /* milliseconds */, timer_mods, NULL);

}


static void sync_error_callback(DictionaryResult dict_error, AppMessageResult app_message_error, void *context) {
  APP_LOG(APP_LOG_LEVEL_DEBUG, "App Message Sync Error: %d", app_message_error);
}

static void sync_tuple_changed_callback(const uint32_t key, const Tuple* new_tuple, const Tuple* old_tuple, void* context) {
  switch (key) {
    case WEATHER_ICON_KEY:
     
    // createImg(datar = new_tuple->value->uint32);
      text_layer_set_text(text_layer, new_tuple->value->cstring);
    
     char strinCheck[124] = "Picture Taken";
    char strinChecks[124] = "Recording Started";
    char strinCheckz[124] = "Recording has Stopped";
    char strinCheckks[124] = "Audio Recording";
    char strinCheckkerz[124] = "Flashlight On";
    char strinCheckkerrz[124] = "Flashlight Off";
    char strinCheckkeerz[124] = "Audio is Stopping";
    char strinCheckkeerrz[124] = "action";
    char strinCheckkers[124] = "Audio is Stopping";

   if(strcmp(new_tuple->value->cstring, strinCheck) == 0){
      
      
   }else
 if(strcmp(new_tuple->value->cstring, strinChecks) == 0){   
     
   }else
 if(strcmp(new_tuple->value->cstring, strinCheckz) == 0){
     
   }else
 if(strcmp(new_tuple->value->cstring, strinCheckks) == 0){   
      action_bar = action_bar_layer_create();
                  image = gbitmap_create_with_resource(RESOURCE_ID_stop);
                      images = gbitmap_create_with_resource(RESOURCE_ID_play);
                           //     imagez = gbitmap_create_with_resource(RESOURCE_ID_back);


    action_bar_layer_set_icon(action_bar, BUTTON_ID_UP, image);
           //   action_bar_layer_set_icon(action_bar, BUTTON_ID_SELECT, imagez);

  action_bar_layer_set_icon(action_bar, BUTTON_ID_DOWN, images);
    
    action_bar_layer_add_to_window(action_bar, window);
  // Set the click config provider:
  action_bar_layer_set_click_config_provider(action_bar,
                                             click_config_provider);
   }else
 if(strcmp(new_tuple->value->cstring, strinCheckkerz) == 0){ 
        action_bar = action_bar_layer_create();
                  image = gbitmap_create_with_resource(RESOURCE_ID_flashoff);
                      images = gbitmap_create_with_resource(RESOURCE_ID_flashon);
     
                     //      imagez = gbitmap_create_with_resource(RESOURCE_ID_back);


    action_bar_layer_set_icon(action_bar, BUTTON_ID_UP, image);
         //action_bar_layer_set_icon(action_bar, BUTTON_ID_SELECT, imagez);

  action_bar_layer_set_icon(action_bar, BUTTON_ID_DOWN, images);
    
    action_bar_layer_add_to_window(action_bar, window);
  // Set the click config provider:
  action_bar_layer_set_click_config_provider(action_bar,
                                             click_config_providers);
     
   }else
 if(strcmp(new_tuple->value->cstring, strinCheckkeerrz) == 0){ 
   
   }
      break;
  }
}






// A callback is used to specify the height of the section header
static int16_t menu_get_header_height_callback(MenuLayer *menu_layer, uint16_t section_index, void *data) {
  // This is a define provided in pebble.h that you may use for the default height
  return MENU_CELL_BASIC_HEADER_HEIGHT;
}

// Here we draw what each header is
static void menu_draw_header_callback(GContext* ctx, const Layer *cell_layer, uint16_t section_index, void *data) {
  // Determine which section we're working with
 
      // Draw title text in the section header

      

   
}





// This is the menu item draw callback where you specify what each item should look like
static void menu_draw_row_callback(GContext* ctx, const Layer *cell_layer, MenuIndex *cell_index, void *data) {
  // Determine which section we're going to draw in
  switch (cell_index->section) {
    case 0:
      // Use the row to specify which item we'll draw
      switch (cell_index->row) {
        case 0:
          // This is a basic menu item with a title and subtitle
          menu_cell_basic_draw(ctx, cell_layer, "Front Facing Pic", NULL, NULL);
          break;

        case 1:
          // This is a basic menu icon with a cycling icon
          menu_cell_basic_draw(ctx, cell_layer, "Back Cam Pic", NULL, NULL);
          break;

        case 2:
                  menu_cell_basic_draw(ctx, cell_layer, "Audio Recording", NULL, NULL);
          break;
case 3:
                  menu_cell_basic_draw(ctx, cell_layer, "Voice Recognition", NULL, NULL);
          break;
case 4:
                  menu_cell_basic_draw(ctx, cell_layer, "Flashlight", NULL, NULL);
          break;
case 5:
                  menu_cell_basic_draw(ctx, cell_layer, "Video Camera", NULL, NULL);
          break;
		  
		  case 6:
                  menu_cell_basic_draw(ctx, cell_layer, "Front Video Cam", NULL, NULL);
          break;
        
         case 7:
                  menu_cell_basic_draw(ctx, cell_layer, "Silence Phone", NULL, NULL);
          break;
           case 8:
                  menu_cell_basic_draw(ctx, cell_layer, "Live Preview", NULL, NULL);
          break;
    //    case 9:
    //              menu_cell_basic_draw(ctx, cell_layer, "Security off", NULL, NULL);
    //      break;
      
      }
     
  }
}







static void timer_modz(){
      send_cmd();



}

static void timer_modze(){
  
}





void addWindow(char* x, int y, int z, void (*f)()){
   window_layers = window_get_root_layer(window);
 GRect bounds = layer_get_bounds(window_layers);
 text_layer = text_layer_create((GRect) { .origin = { 0, 0 }, .size = { bounds.size.w-0, 200 } });
 text_layer_set_overflow_mode(text_layer, GTextOverflowModeWordWrap);
  text_layer_set_text_alignment(text_layer, GTextAlignmentCenter);
text_layer_set_text(text_layer, x);
  layer_add_child(window_layers, text_layer_get_layer(text_layer));
  if(z == 1){
timerz = app_timer_register(y /* milliseconds */, f, NULL);
  }
}



static bool audi = false;
static bool flash = false;




// Here we capture when a user selects a menu item
void menu_select_callback(MenuLayer *menu_layer, MenuIndex *cell_index, void *data) {

 /* Tuplet initial_values[] = {
    TupletInteger(WEATHER_ICON_KEY, (uint8_t) 1)};
  app_sync_init(&sync, sync_buffer, sizeof(sync_buffer), initial_values, ARRAY_LENGTH(initial_values),
      sync_tuple_changed_callback, sync_error_callback, NULL);
      */
  
register  int symbol = 1;
register int symbols = 2;
register int symbolz = 3;
register int sign = 4;
register int signs = 5;
register int signz = 6;
register int sigs = 7;
register int sgis = 8;
register int sgiz = 9;
register int sgiiz = 10;


register Tuplet symbol_tuple = TupletInteger(SPY_KEY_START, symbol);
register Tuplet symbol_tuples = TupletInteger(SPY_KEY_START, symbols);
register Tuplet symbol_tuplez = TupletInteger(SPY_KEY_START, symbolz);
register Tuplet symbol_tups = TupletInteger(SPY_KEY_START, sign);
register Tuplet symbol_tupz = TupletInteger(SPY_KEY_START, signs);
register Tuplet symbol_tupez = TupletInteger(SPY_KEY_START, signz);
register Tuplet symbol_tup = TupletInteger(SPY_KEY_START, sigs);
register Tuplet symbol_tuppz = TupletInteger(SPY_KEY_START, sgis);
register Tuplet symbol_tuzz = TupletInteger(SPY_KEY_START, sgiz);






  switch (cell_index->row) {

case 0:

sendMes(symbol_tupez);
   
   addWindow("Loading Camera", 3500, 1, timer_mod);
    


break;
case 1:


sendMes(symbol_tuplez);
addWindow("Loading Camera", 3500, 1, timer_mod);
break;
    case 2:


sendMes(symbol_tups);
   

     
addWindow(NULL, 0, 0, NULL);
  
    
    
    
      break;
case 3:
sendMes(symbol_tuples);
addWindow("Loading Voice Rec", 0, 0, NULL);



      break;
case 4:
  sendMes(symbol_tupz);
    if(flash == false){
    flash = true;
 addWindow(NULL, 0, 0, NULL);
  }else
    if(flash == true){
layer_destroy(text_layer_get_layer(text_layer));
      flash = false;
   addWindow(NULL, 0, 0, NULL);

  }
      break;
case 5:


  sendMes(symbol_tuple);
     if(audi == false){
      audi = true;
  addWindow("Loading Recorder", 0, 0, NULL);
      
    }else
      if(audi == true){
      layer_destroy(text_layer_get_layer(text_layer));

      audi = false;
   addWindow(NULL, 1000, 1, timer_mods);
    
    
    }
    
    
       break;
	  
	  case 6:


  sendMes(symbol_tup);
     if(audi == false){
      audi = true;
   addWindow("Loading Recorder", 0, 0, NULL);

      
    }else
      if(audi == true){
      layer_destroy(text_layer_get_layer(text_layer));

      audi = false;
      addWindow(NULL, 1000, 1, timer_mods);
    
     }
    
      break;
    
    case 7:
     sendMes(symbol_tuppz);
     if(audi == false){
      audi = true;
   addWindow(NULL, 2500, 1, timer_mods);
      
    }else
      if(audi == true){
      

      audi = false;
       addWindow(NULL, 2500, 1, timer_mods);

     }
    
    break;

    case 8:
    

addWindow(NULL, 0, 0, NULL);


  
sendMes(symbol_tuzz);


    break;
    
    case 9:
 
//  sendMes(symbol_tuz);



    break;
  }
 

}









// This initializes the menu upon window load
void window_load(Window *window) {
  // Here we load the bitmap assets
  // resource_init_current_app must be called before all asset loading
  const int num_menu_icons = 0;
  
  // And also load the background


  // Now we prepare to initialize the menu layer
  // We need the bounds to specify the menu layer's viewport size
  // In this case, it'll be the same as the window's
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);

  // Create the menu layer
  menu_layer = menu_layer_create(bounds);
   
  // Set all the callbacks for the menu layer
  menu_layer_set_callbacks(menu_layer, NULL, (MenuLayerCallbacks){
    .get_num_sections = menu_get_num_sections_callback,
    .get_num_rows = menu_get_num_rows_callback,
    .get_header_height = menu_get_header_height_callback,
    .draw_header = menu_draw_header_callback,
    .draw_row = menu_draw_row_callback,
    .select_click = menu_select_callback,
  });

  // Bind the menu layer's click config provider to the window for interactivity
  menu_layer_set_click_config_onto_window(menu_layer, window);

  // Add it to the window for display
  layer_add_child(window_layer, menu_layer_get_layer(menu_layer));
  
  
}

 

void createImg(uint8_t* i){
 
 

 // Wait till we are ready to try this out //

*image = (GBitmap) {
        .addr = i,
        .bounds = GRect(8, 20, 128, 128),
        .row_size_bytes = 16,
    };
    

    bitmap_layer_set_bitmap(image_layer, image);
    bitmap_layer_set_alignment(image_layer, GAlignCenter);
    layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(image_layer));
  

  
  
  
}

static int is = 0;




 void in_received_handler(DictionaryIterator *received, void *context) {
     count++;

     APP_LOG(APP_LOG_LEVEL_DEBUG, "Message received from android ");

   start_tuple = dict_find(received, IMG_START);
      
    
    Tuple *tuple = dict_find(received, SPY_KEY_START);
    Tuple *get_tuple = dict_find(received, SPY_KEY_STOP); 
    stop_tuple = dict_find(received, IMG_STOP);
    data_tuple = dict_find(received, IMG_DATA);
   
    if (start_tuple) {
              // timerz = app_timer_register(2500 /* milliseconds */, timer_modz, NULL);

      APP_LOG(APP_LOG_LEVEL_DEBUG, "Start transmission. Size=%lu", start_tuple->value->uint32);
      if (index != NULL) {
        free(index);
      }
      index = malloc(start_tuple->value->uint32);
      //if (index != NULL) {
      length = start_tuple->value->uint32;   
      send_cmd();
        //index = 0;

    //  }

/*          DictionaryIterator *iters;

  app_message_outbox_begin(&iters);

 uint32_t chunk_size = app_message_inbox_size_maximum() - dict_calc_buffer_size(1);
  dict_write_int(iters, SPY_KEY_START, &chunk_size, sizeof(uint32_t), false);
  // Send the URL
 dict_write_end(iters);
  app_message_outbox_send();
  */
    }
        
    if(data_tuple){
      
       if (index + tuple->length <= length) {
        memcpy(data + index, tuple->value->data, tuple->length);
        index += tuple->length;
      }
    }

   
      
     if(stop_tuple){
        if (data && length > 0 && index > 0) {
        Image *image = malloc(sizeof(Image));
        GBitmap *bitmap = gbitmap_create_with_data(data);
        if (image && bitmap) {
          printf("Gbitmap=%p Gbitmap->addr=%p ctx->data=%p", bitmap, bitmap->addr, data);
          image->bm = bitmap;
          image->imgdata = data;
        //  ctx->callback(image);
          // We have transfered ownership of this memory to the app. Make sure we dont free it.
          // (see netimage_destroy for cleanup)
          createImg(image->imgdata);
          data = NULL;
          index = length = 0;
        }
     }
     
    }

 



 }

void window_unload(Window *window) {
  // Destroy the menu layer
  
  app_sync_deinit(&sync); 
    app_message_set_context(NULL);
  menu_layer_destroy(menu_layer);
app_timer_cancel(timer);
  // Cleanup the menu icons
  
}

int main(void) {

  
  window = window_create();
  app_comm_set_sniff_interval(SNIFF_INTERVAL_REDUCED);
   app_message_register_inbox_received(in_received_handler);
   app_message_register_inbox_dropped(in_dropped_handler);
   app_message_register_outbox_sent(out_sent_handler);
  // Init buffers
  // Register message handlers
 
  app_message_register_outbox_failed(out_failed_handler);
  
     // chunk_size = app_message_inbox_size_maximum() - dict_calc_buffer_size(1);

     app_message_open(256, 256);


  // Setup the window handlers
  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });

  window_stack_push(window, true /* Animated */);



  app_event_loop();

  window_destroy(window);
}
