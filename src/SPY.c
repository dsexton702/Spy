#include "pebble.h"
#include "APPMESSAGE.h"





static AppSync sync;
bool record = false;
static AppTimer *timerz;
static Layer *layer;
static AppTimer *timers;
static AppTimer *timer;
Layer *window_layers;
static GBitmap *image;
static GBitmap *images;
static GBitmap *imagez;
static GBitmap bmpimage;
MenuLayerCallbacks man;
static bool play = false;
static int transNum;
DictionaryIterator *outbox;
static uint32_t chunk = 0;
static Tuple *start_tuple;
static Tuple *data_tuple;
static Tuple *stop_tuple;
static const char* p;
char aud[124] = "Audio Recording";
char audS[124] = "Audio Stopped";
char pic[124] = "Picture Taken";
char cam[124] = "Loading Camera";
char vid[124] = "Starting Recording";
char vidS[124] = "Recording Stopped";
char rec[124] = "Recording...";
char flashh[124] = "Flashlight on";
char flashO[124] = "Flashlight off";  
char listen[124] = "Listening...";  
char phoneS[124] = "Phone Silenced";  
char phone[124] = "Volume Normal";  
char motion[124] = "Motion Detected";
static int eat = 0;
uint8_t* imgData;
static bool detect = false;
int z = 0;
bool isCam = false;
bool gobackCam = false;
bool isVid = false;
bool isSet = false;
bool yesno = false;
bool vibrate = true;



static uint32_t length = 0;
static uint8_t* data;
static uint32_t index = 0;



static char *pee = "Recording...";
static char *peep = "";
static AppSync sync;
static ActionBarLayer *action_bar;

static char *text = "Security off";

static uint8_t sync_buffer[1024];
static TextLayer *text_layer;
// This is a menu layer
// You have more control than with a simple menu layer
static BitmapLayer *image_layer;
static char* replace;

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
  if(isCam == true || isVid == true || isSet == true || yesno == true){
    return 1;
  }else
  return NUM_MENU_SECTIONS;
}

// Each section has a number of items;  we use a callback to specify this
// You can also dynamically add and remove items using this
static uint16_t menu_get_num_rows_callback(MenuLayer *menu_layer, uint16_t section_index, void *data) {
 
  if(isCam == true){
    return 3;
  }
  
   if(isVid == true){
    return 2;
  }
  
   if(isSet == true){
    return 5;
  }
  
   if(yesno == true){
    return 2;
  }
      return NUM_FIRST_MENU_ITEMS;

    
  
  
}




void sendMes(Tuplet tup){
app_message_outbox_begin(&iter);

  
  dict_write_tuplet(iter, &tup);
  dict_write_end(iter);

  app_message_outbox_send();

}


static void actionTimer(){
}


static void timer_mods(){

  text_layer_destroy(text_layer);

   window_stack_pop(true);


  layer_mark_dirty((Layer*)menu_layer);


  
menu_layer_set_click_config_onto_window(menu_layer, window);

app_timer_cancel(timer);

  isCam = false;


}


static void my_previous_click_handler(ClickRecognizerRef recognizer, void *context) {
      register int sgiiz = 4;

  
     register Tuplet symbol_tuple = TupletInteger(SPY_KEY_START, sgiiz);
    sendMes(symbol_tuple);
}






static void my_next_click_handler(ClickRecognizerRef recognizer, void *context) {
 
         register int sgiiz = 4;

  
     register Tuplet symbol_tuple = TupletInteger(SPY_KEY_START, sgiiz);
    sendMes(symbol_tuple);
     
  


}


static void my_select_click_handler(ClickRecognizerRef recognizer, void *context) {
 
   action_bar_layer_remove_from_window(action_bar);
   gbitmap_destroy(image);
  gbitmap_destroy(images);
layer_mark_dirty((Layer*)text_layer);
  text_layer_destroy(text_layer);


//  layer_mark_dirty((Layer*)window_layer);
   // layer_mark_dirty((Layer*)window_layers);

  
      layer_mark_dirty((Layer*)menu_layer);
  
 // layer_remove_from_parent((Layer*)action_bar);
  
 // layer_mark_dirty((Layer*)action_bar);

  
menu_layer_set_click_config_onto_window(menu_layer, window);
  
  



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
 
   action_bar_layer_remove_from_window(action_bar);
   gbitmap_destroy(image);
  gbitmap_destroy(images);
layer_mark_dirty((Layer*)text_layer);
  text_layer_destroy(text_layer);


//  layer_mark_dirty((Layer*)window_layer);
   // layer_mark_dirty((Layer*)window_layers);

  
      layer_mark_dirty((Layer*)menu_layer);
  
 // layer_remove_from_parent((Layer*)action_bar);
  
 // layer_mark_dirty((Layer*)action_bar);

  
menu_layer_set_click_config_onto_window(menu_layer, window);
  


}





void click_config_provider(void *context) {
  window_single_click_subscribe(BUTTON_ID_DOWN, (ClickHandler) my_next_click_handler);
      window_single_click_subscribe(BUTTON_ID_SELECT, (ClickHandler) my_select_click_handler);

  window_single_click_subscribe(BUTTON_ID_UP, (ClickHandler) my_previous_click_handler);
}


void click_config_providers(void *context) {
  window_single_click_subscribe(BUTTON_ID_DOWN, (ClickHandler) my_next_click_handlers);
  
    window_single_click_subscribe(BUTTON_ID_SELECT, (ClickHandler) my_select_click_handlers);

  window_single_click_subscribe(BUTTON_ID_UP, (ClickHandler) my_previous_click_handlers);
}


static const VibePattern custom_pattern = {
  .durations = (uint32_t []) {300},
  .num_segments = 1
};


static void displayText(char* p){
   
   
 
   text_layer_set_text(text_layer, p);


}


static void motionTimer(){
  
  if(readB() == true){
    vibes_enqueue_custom_pattern(custom_pattern);
  }
  if(detector == false){
              timer = app_timer_register(1500 /* milliseconds */, timer_mods, NULL);
  }


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

static void send(uint32_t x) {
 DictionaryIterator *iters;
   uint32_t chunk_size = app_message_inbox_size_maximum() - dict_calc_buffer_size(1);

  Tuplet symbol_tuz = TupletInteger(SPY_KEY_START, x);

 if(iters == NULL){
   return;
 }
  app_message_outbox_begin(&iters);
    dict_write_tuplet(iters, &symbol_tuz);
   dict_write_end(iters);
  if((app_message_outbox_send() == APP_MSG_OK)) {
    app_message_outbox_send();
  }else
    if((app_message_outbox_send() == APP_MSG_BUSY)){

    
  }else
    app_message_outbox_send();
  
}



static void timer_modz(){

send(index); 

}



static void send_cmd(uint32_t x) {
 DictionaryIterator *iters;
   uint32_t chunk_size = app_message_inbox_size_maximum() - dict_calc_buffer_size(1);

  Tuplet symbol_tuz = TupletInteger(SPY_KEY_START, x);

 if(iters == NULL){
   return;
 }
  app_message_outbox_begin(&iters);
    dict_write_tuplet(iters, &symbol_tuz);
   dict_write_end(iters);
  if((app_message_outbox_send() == APP_MSG_OK)) {
       timer = app_timer_register(5000 /* milliseconds */, timer_modz, NULL);


   // app_message_outbox_send();
  }else
    if((app_message_outbox_send() == APP_MSG_BUSY)){
   timer = app_timer_register(5000 /* milliseconds */, timer_modz, NULL);

    
  }else
       timer = app_timer_register(5000 /* milliseconds */, timer_modz, NULL);

  
}



  static void grabSettings(){
    int i = 0;
    for(i=0;i<10;i++){
    menus[i] = malloc(24);
    if(menus[i] == NULL){
      
    }
    }
    app_sync_deinit(&sync); 

     app_message_register_inbox_received(in_received_handler);
   app_message_register_inbox_dropped(in_dropped_handler);
   app_message_register_outbox_sent(out_sent_handler);
  app_message_register_outbox_failed(out_failed_handler);
    register int set = 13;



register Tuplet tuple = TupletInteger(SPY_KEY_START, set);
    
      sendMes(tuple);

    
  }




static void timer_mod(){
  

text_layer_set_text(text_layer, "Picture Taken");



timer = app_timer_register(600 /* milliseconds */, timer_mods, NULL);

}


static int testString(char p, char z){
  if(strcmp(&p, &z) == 0){
      return 1;
    }else
    return 0;
  
}

static void sync_error_callback(DictionaryResult dict_error, AppMessageResult app_message_error, void *context) {
  APP_LOG(APP_LOG_LEVEL_DEBUG, "App Message Sync Error: %d", app_message_error);
}

static void sync_tuple_changed_callback(const uint32_t key, const Tuple* new_tuple, const Tuple* old_tuple, void* context) {
    
  if(listener == false){
  text_layer_set_text(text_layer, replace);
  }else
    if(listener == true){
      text_layer_set_text(text_layer, new_tuple->value->cstring);

  }
  
  if(strcmp(new_tuple->value->cstring, motion) == 0){
    detector = true;
      text_layer_set_text(text_layer, new_tuple->value->cstring);

                   timer = app_timer_register(0 /* milliseconds */, motionTimer, NULL);

  }
    
    if(strcmp(new_tuple->value->cstring, phone) == 0 || strcmp(new_tuple->value->cstring, phoneS) == 0 || strcmp(new_tuple->value->cstring, vidS) == 0 || strcmp(new_tuple->value->cstring, vid) == 0 || strcmp(new_tuple->value->cstring, pic) == 0 || strcmp(new_tuple->value->cstring, cam) == 0){
      text_layer_set_text(text_layer, new_tuple->value->cstring);
      motionTimer();

   } else
      
  
   
 if(strcmp(new_tuple->value->cstring, aud) == 0){   
      action_bar = action_bar_layer_create();
                  image = gbitmap_create_with_resource(RESOURCE_ID_stop);
                      images = gbitmap_create_with_resource(RESOURCE_ID_play);
                           //     imagez = gbitmap_create_with_resource(RESOURCE_ID_back);


    action_bar_layer_set_icon(action_bar, BUTTON_ID_UP, image);

           //   action_bar_layer_set_icon(action_bar, BUTTON_ID_SELECT, imagez);

  action_bar_layer_set_icon(action_bar, BUTTON_ID_DOWN, images);
    
    action_bar_layer_add_to_window(action_bar, window);
         text_layer_set_text(text_layer, new_tuple->value->cstring);

  // Set the click config provider:
  action_bar_layer_set_click_config_provider(action_bar,
                                             click_config_provider);
   }else
 if(strcmp(new_tuple->value->cstring, flashh) == 0){ 
        action_bar = action_bar_layer_create();
                  image = gbitmap_create_with_resource(RESOURCE_ID_flashoff);
                      images = gbitmap_create_with_resource(RESOURCE_ID_flashon);
     
                     //      imagez = gbitmap_create_with_resource(RESOURCE_ID_back);


    action_bar_layer_set_icon(action_bar, BUTTON_ID_UP, image);
         //action_bar_layer_set_icon(action_bar, BUTTON_ID_SELECT, imagez);

  action_bar_layer_set_icon(action_bar, BUTTON_ID_DOWN, images);
    
    action_bar_layer_add_to_window(action_bar, window);
         text_layer_set_text(text_layer, new_tuple->value->cstring);

  // Set the click config provider:
  action_bar_layer_set_click_config_provider(action_bar,
                                             click_config_providers);
  
 }else
      if(strcmp(new_tuple->value->cstring, audS) == 0){
                      text_layer_set_text(text_layer, new_tuple->value->cstring);

    }else
      if(strcmp(new_tuple->value->cstring, flashO) == 0){
                     text_layer_set_text(text_layer, new_tuple->value->cstring);
 
    }else
      if(strcmp(new_tuple->value->cstring, rec) == 0){
                      text_layer_set_text(text_layer, new_tuple->value->cstring);

    }else
      if(strcmp(new_tuple->value->cstring, listen) == 0){
            text_layer_set_text(text_layer, new_tuple->value->cstring);
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
 
    menu_cell_basic_header_draw(ctx, cell_layer, "Welcome to Spy");
  
      

   
}


static void rowInit(){
 menus[0] = "Camera";
   menus[1] = "Video Camera";
     menus[2] = "Audio Recording";

     menus[3] = "Voice Recognition";

     menus[4] = "Flashlight";

     menus[5] = "Silence Phone";

     menus[6] = "Motion Detector";

     menus[7] = "Take pic and view";

}



// This is the menu item draw callback where you specify what each item should look like
static void menu_draw_row_callback(GContext* ctx, const Layer *cell_layer, MenuIndex *cell_index, void *data) {
  // Determine which section we're going to draw in
  switch (cell_index->section) {
    case 0:
      // Use the row to specify which item we'll draw
    
     if(isCam == true){
       switch (cell_index->row){
          case 0:
                    menu_cell_basic_draw(ctx, cell_layer, "Take Front Pic", NULL, NULL);
          break;
          case 1:
                    menu_cell_basic_draw(ctx, cell_layer, "Take Back Pic", NULL, NULL);
          break;
          case 2:
                    menu_cell_basic_draw(ctx, cell_layer, "Take pic w/Flash", NULL, NULL);
          break;
       }

        }
    
    if(isVid == true){
       switch (cell_index->row){
          case 0:
                    menu_cell_basic_draw(ctx, cell_layer, "Take Front Vid", NULL, NULL);
          break;
          case 1:
                    menu_cell_basic_draw(ctx, cell_layer, "Take Back Vid", NULL, NULL);
          break;
       }

        }
    
    
    
     if(yesno == true){
       switch (cell_index->row){
          case 0:
                    menu_cell_basic_draw(ctx, cell_layer, "Yes", NULL, NULL);
          break;
          case 1:
                    menu_cell_basic_draw(ctx, cell_layer, "No", NULL, NULL);
          break;
       }

        }
    
    
    if(isSet == true){
       switch (cell_index->row){
          case 0:
                    menu_cell_basic_draw(ctx, cell_layer, "Vibe on Success", NULL, NULL);
          break;
          case 1:
                    menu_cell_basic_draw(ctx, cell_layer, "Video Quality", NULL, NULL);
          break;
         case 2:
                             menu_cell_basic_draw(ctx, cell_layer, "Pic on Detection", NULL, NULL);

         break;
          case 3:
                             menu_cell_basic_draw(ctx, cell_layer, "Vid on Detection", NULL, NULL);

         break;
         case 4:
                             menu_cell_basic_draw(ctx, cell_layer, "Detect while off", NULL, NULL);

         break;
       }

        }
    
    
    
    
    if(isCam == false && isVid == false && isSet == false && yesno == false){
      switch (cell_index->row) {
        
       
       
        case 0:
          // This is a basic menu item with a title and subtitle
          menu_cell_basic_draw(ctx, cell_layer, menus[0], NULL, NULL);
          break;

        case 1:
          // This is a basic menu icon with a cycling icon
          menu_cell_basic_draw(ctx, cell_layer, menus[1], NULL, NULL);
        
          break;

        case 2:
                  menu_cell_basic_draw(ctx, cell_layer, menus[2], NULL, NULL);
          break;
case 3:
                  menu_cell_basic_draw(ctx, cell_layer, menus[3], NULL, NULL);
          break;
case 4:
                  menu_cell_basic_draw(ctx, cell_layer, menus[4], NULL, NULL);
          break;
case 5:
                  menu_cell_basic_draw(ctx, cell_layer, menus[5], NULL, NULL);
          break;
		  
		  case 6:
                  menu_cell_basic_draw(ctx, cell_layer, menus[6], NULL, NULL);
          break;
        
         case 7:
                  menu_cell_basic_draw(ctx, cell_layer, menus[7], NULL, NULL);
          break;
           case 8:
                  menu_cell_basic_draw(ctx, cell_layer, "Settings", NULL, NULL);
          break;
 /*  case 9:
                menu_cell_basic_draw(ctx, cell_layer, "Take pic and View", NULL, NULL);
        break;
        */
      
      }
    }
  }
}







static void timer_modze(){
  
}





  



void addWindow(char* x, Window* w){
  if(isCam == true || isVid == true || isSet == true || yesno == true){
window_layers = window_get_root_layer(w);
    GRect bounds = layer_get_frame(window_layers);
 text_layer = text_layer_create(bounds);
 text_layer_set_overflow_mode(text_layer, GTextOverflowModeWordWrap);
  text_layer_set_text_alignment(text_layer, GTextAlignmentCenter);
text_layer_set_text(text_layer, x);
  layer_add_child(window_layers, text_layer_get_layer(text_layer));
  }else
    if(isCam != true && isVid != true && isSet != true && yesno != true){
window_layers = window_get_root_layer(w);
    GRect bounds = layer_get_frame(window_layers);
 text_layer = text_layer_create(bounds);
 text_layer_set_overflow_mode(text_layer, GTextOverflowModeWordWrap);
  text_layer_set_text_alignment(text_layer, GTextAlignmentCenter);
text_layer_set_text(text_layer, x);
  layer_add_child(window_layers, (Layer*)text_layer);
  }
 
  
  
  
  
  

  
}

void regSync(){
   Tuplet initial_values[] = {
    TupletInteger(WEATHER_ICON_KEY, (uint8_t) 1)};
  app_sync_init(&sync, sync_buffer, sizeof(sync_buffer), initial_values, ARRAY_LENGTH(initial_values),
      sync_tuple_changed_callback, sync_error_callback, NULL);
}

static bool audi = false;
static bool flash = false;


bool readB(){
 return persist_read_bool(0x1234);
}

void saveB(bool x){
persist_write_bool(0x1234, x);
 
}


// Here we capture when a user selects a menu item
void menu_select_callback(MenuLayer *menu_layer, MenuIndex *cell_index, void *data) {

 
      
      
  
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
register int sgiiiz = 11;
  register int sgiiiiz = 12;
    register int wtf = 15;




register Tuplet symbol_tuple = TupletInteger(SPY_KEY_START, symbol);
register Tuplet symbol_tuples = TupletInteger(SPY_KEY_START, symbols);
register Tuplet symbol_tuplez = TupletInteger(SPY_KEY_START, symbolz);
register Tuplet symbol_tups = TupletInteger(SPY_KEY_START, sign);
register Tuplet symbol_tupz = TupletInteger(SPY_KEY_START, signs);
register Tuplet symbol_tupez = TupletInteger(SPY_KEY_START, signz);
register Tuplet symbol_tup = TupletInteger(SPY_KEY_START, sigs);
register Tuplet symbol_tuppz = TupletInteger(SPY_KEY_START, sgis);
register Tuplet symbol_tuzz = TupletInteger(SPY_KEY_START, sgiz);
register Tuplet symbol_tuz = TupletInteger(SPY_KEY_START, sgiiz);
  register Tuplet symbol_tuzze = TupletInteger(SPY_KEY_START, sgiiiz);
    register Tuplet sy = TupletInteger(SPY_KEY_START, sgiiiiz);
      register Tuplet ci = TupletInteger(SPY_KEY_START, wtf);





 if(isCam == true){
   switch (cell_index->row){
      case 0:
      camera(symbol_tupez);
    break;
      case 1:
      camera(symbol_tuplez);
     break;
     case 2:
     camera(ci);
       break;
   }
    }
  
   if(yesno == true){
   switch (cell_index->row){
      case 0:
    saveB(true);
     isSet = true;
        window_stack_pop(true);

     break;
      case 1:
    saveB(false);
     isSet = true;
        window_stack_pop(true);

     break;
    
   }
    }
  
  if(isVid == true){
   switch (cell_index->row){
      case 0:
      vidCam(symbol_tup);
    break;
      case 1:
    vidCam(symbol_tuple);
   }
    }
   if(isSet == true){
   switch (cell_index->row){
      case 0:
     isSet = false;
     yesno = true;
             gobackCam = true;

      man = (MenuLayerCallbacks){
    .get_num_sections = menu_get_num_sections_callback,
    .get_num_rows = menu_get_num_rows_callback,
    .get_header_height = menu_get_header_height_callback,
    .draw_header = menu_draw_header_callback,
    .draw_row = menu_draw_row_callback,
    .select_click = menu_select_callback,
  };
    changeWindow(windows, man);
    break;
     
   }
    }



  if(isCam == false && isVid == false && isSet == false && yesno == false){
  switch (cell_index->row) {
    
   

case 0:
    
    isCam = true;
    
    gobackCam = true;
    
    man = (MenuLayerCallbacks){
    .get_num_sections = menu_get_num_sections_callback,
    .get_num_rows = menu_get_num_rows_callback,
    .get_header_height = menu_get_header_height_callback,
    .draw_header = menu_draw_header_callback,
    .draw_row = menu_draw_row_callback,
    .select_click = menu_select_callback,
  };
    changeWindow(windows, man);

    //Front Camera, going to make this another menu soon//
 //  camera(symbol_tupez);
    


break;
case 1:
  isVid = true;
        gobackCam = true;

    
        man = (MenuLayerCallbacks){
    .get_num_sections = menu_get_num_sections_callback,
    .get_num_rows = menu_get_num_rows_callback,
    .get_header_height = menu_get_header_height_callback,
    .draw_header = menu_draw_header_callback,
    .draw_row = menu_draw_row_callback,
    .select_click = menu_select_callback,
  };
    changeWindow(windows, man);
    
    //BackCamera//
   // camera(symbol_tuplez);
    
break;
    case 2:
 audRec(symbol_tups);
  
    
    
    
      break;
case 3:
     voice(symbol_tuples);



      break;
case 4:
    flashF(symbol_tupz);

  
      break;
case 5:
 
    silence(symbol_tuppz);
    
    
    
    
    
       break;
	  
	  case 6:
  
  if(detect == false){
      motionD(symbol_tuz);
     
      detect = true;
    }else
      if(detect == true){
      motionD(symbol_tuzze);
     
    

text_layer_destroy(text_layer);

   window_stack_pop(true);
      detect = false;

    }
     
    
      break;
    
    case 7:

     app_sync_deinit(&sync); 

     app_message_register_inbox_received(in_received_handler);
   app_message_register_inbox_dropped(in_dropped_handler);
   app_message_register_outbox_sent(out_sent_handler);
  app_message_register_outbox_failed(out_failed_handler);
    
    sendMes(sy);

  


addWindow("Loading Image", window);

    break;

    case 8:
    
    isSet = true;

    
gobackCam = true;

 man = (MenuLayerCallbacks){
    .get_num_sections = menu_get_num_sections_callback,
    .get_num_rows = menu_get_num_rows_callback,
    .get_header_height = menu_get_header_height_callback,
    .draw_header = menu_draw_header_callback,
    .draw_row = menu_draw_row_callback,
    .select_click = menu_select_callback,
  };
    changeWindow(windows, man);

 
  


    break;
    
    case 9:


    
    
  


    break;
    
  }
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
   window_layer = window_get_root_layer(window);
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
  

  
 bmpimage = (GBitmap) {
         .addr = i,
         .bounds = GRect(0,0,144,168),
         .row_size_bytes = 20,
     };

  
  bitmap_layer_set_bitmap(image_layer, &bmpimage);
  layer_mark_dirty((Layer*)image_layer);

  
  
                                APP_LOG(APP_LOG_LEVEL_DEBUG, "end of function");

  
}

static void goBack(int x){
  
         timer = app_timer_register(x /* milliseconds */, timer_mods, NULL);

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
   Tuple *msg = dict_find(received, IMG_MSG);
      Tuple *menu = dict_find(received, GET_MENU);

   
   
   if(menu){
       char *text = menu->value->cstring;
     menus[z] = text;
     z++;
     layer_mark_dirty((Layer*)menu_layer);
   }
   
   if(msg){
     displayText(msg->value->cstring);
   }
   
    if (start_tuple) {
              // timerz = app_timer_register(2500 /* milliseconds */, timer_modz, NULL);

      APP_LOG(APP_LOG_LEVEL_DEBUG, "Start transmission. Size=%lu", start_tuple->value->uint32);
        if(data != NULL){
        free(data);
        }
    
      length = start_tuple->value->uint32;   
      index = 0;
      send_cmd(116);
      Layer *window_layers = window_get_root_layer(window);
GRect bounds = layer_get_bounds(window_layers);
  image_layer = bitmap_layer_create(bounds);
  bitmap_layer_set_bitmap(image_layer, &bmpimage);
  layer_add_child(window_layers, bitmap_layer_get_layer(image_layer));
      }

/*          DictionaryIterator *iters;

  app_message_outbox_begin(&iters);

 uint32_t chunk_size = app_message_inbox_size_maximum() - dict_calc_buffer_size(1);
  dict_write_int(iters, SPY_KEY_START, &chunk_size, sizeof(uint32_t), false);
  // Send the URL
 dict_write_end(iters);
  app_message_outbox_send();
  */
    
        
    if(data_tuple){
            APP_LOG(APP_LOG_LEVEL_DEBUG, "data sent. index=%lu, length=%d", index, data_tuple->length);

       if (index + data_tuple->length <= length) {
        memcpy(data + index, &data_tuple->value->data + 1, data_tuple->length - 1);        
        index += data_tuple->length;
                   createImg(data);

   timer = app_timer_register(5000 /* milliseconds */, timer_modz, NULL);

      }
    }

   
      
     if(stop_tuple){
                   APP_LOG(APP_LOG_LEVEL_DEBUG, "final data sent. index=%lu, length=%d", index, stop_tuple->length);

        if (data && length > 0 && index > 0) {
        Image *image = malloc(sizeof(Image));
        GBitmap *bitmap = gbitmap_create_with_data(data);
        if (image && bitmap) {
          printf("Gbitmap=%p Gbitmap->addr=%p ctx->data=%p", bitmap, bitmap->addr, data);
          image->bm = bitmap;
          imgData = data;
        //  ctx->callback(image);
          
          
          
          // We have transfered ownership of this memory to the app. Make sure we dont free it.
          // (see netimage_destroy for cleanup)
                          APP_LOG(APP_LOG_LEVEL_DEBUG, "trying to post image");
          
          
                app_message_deregister_callbacks();



          
                                        APP_LOG(APP_LOG_LEVEL_DEBUG, "before data goes NULL");

          data = NULL;
          index = length = 0;
        } else {
          APP_LOG(APP_LOG_LEVEL_DEBUG, "Unable to create GBitmap. Is this a valid PBI?");
          // free memory
          free(data);
          data = NULL;
          index = length = 0;
          if (image) {
            free(image);
          }
     }
     
    }

 

     }

       
     
 

 }


static void rowDeinit(){
   for(int i = 0;i<10;i++){
  if(menus[i] != NULL){
    menus[i] = NULL;
  free(menus[i]);
}
}

}



void window_appear(Window* w){
   if(gobackCam == true){
    isVid = false;
    isCam = false;
    isSet = false;
    yesno = false;
     
    menu_layer_destroy(menu_layers);
    layer_destroy(window_layers);
      layer_mark_dirty(menu_layer_get_layer(menu_layer));



  
menu_layer_set_click_config_onto_window(menu_layer, w);
    gobackCam = false;
  }
}


void window_unload(Window *window) {
  
 
  
  if(isCam == false || isVid == false || isSet == false || yesno == false){
    menu_layer_reload_data(menu_layer);
      layer_mark_dirty((Layer*)menu_layer);


  
menu_layer_set_click_config_onto_window(menu_layer, window);
  
}
  
  rowDeinit();
     register Tuplet sym = TupletInteger(SPY_KEY_START, 11);

  // Destroy the menu layer
  if(data != NULL){
  free(data);
  }
  if(detect == true){
    detect = false;
    sendMes(sym);
  }
  action_bar_layer_remove_from_window(action_bar);

    action_bar_layer_destroy(action_bar);

  app_message_deregister_callbacks();
  app_sync_deinit(&sync); 
    app_message_set_context(NULL);
  menu_layer_destroy(menu_layer);
app_timer_cancel(timer);
  listener = false;
  // Cleanup the menu icons
  
}

int main(void) {

 app_comm_set_sniff_interval(SNIFF_INTERVAL_REDUCED);
  
  
       app_message_open(256, 256);
  grabSettings();
    rowInit();


  
  window = window_create();
 

    data = malloc(sizeof(uint8_t) * (5 * 4) * 168 + 12);


  // Setup the window handlers
  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .appear = window_appear,

    .unload = window_unload,
  });

  window_stack_push(window, true /* Animated */);


  app_event_loop();

  window_destroy(window);
}
