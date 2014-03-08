#include "pebble.h"
#include "APPMESSAGE.h"



#define NUM_FIRST_MENU_ITEMS 6
#define NUM_MENU_SECTIONS 1

static Window *window;
static AppTimer *timerz;
static AppTimer *timers;
static AppTimer *timer;
Layer *window_layers;
Layer *window_layer;
static TextLayer *text_layer;
// This is a menu layer
// You have more control than with a simple menu layer
static MenuLayer *menu_layer;

// Menu items can optionally have an icon drawn with them


static int current_icon = 0;

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
                  menu_cell_basic_draw(ctx, cell_layer, "Audi Recording", NULL, NULL);
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
      
      }
     
  }
}




void sendMes(Tuplet tup){
app_message_outbox_begin(&iter);


  dict_write_tuplet(iter, &tup);
  dict_write_end(iter);

  app_message_outbox_send();

}




static void timer_mods(){
app_timer_cancel(timerz);
	Layer *law = text_layer_get_layer(text_layer);
 layer_destroy(law);

app_timer_cancel(timer);



}

static void timer_mod(){

text_layer_set_text(text_layer, "Picture Taken");



timer = app_timer_register(600 /* milliseconds */, timer_mods, NULL);

}

void window_sets(Window *window, MenuLayerCallbacks men) {
Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);

    

  // Create the menu layer
  menu_layer = menu_layer_create(bounds);

 
  // Set all the callbacks for the menu layer
  menu_layer_set_callbacks(menu_layer, NULL, men);

  // Bind the menu layer's click config provider to the window for interactivity
  menu_layer_set_click_config_onto_window(menu_layer, window);

  // Add it to the window for display
  layer_add_child(window_layer, menu_layer_get_layer(menu_layer));

}

void changeWindow(Window *window, MenuLayerCallbacks man){
window = window_create();


window_sets(window, man);





  window_stack_push(window, true /* Animated */);

}


int symbol = 1;
int symbols = 2;
int symbolz = 3;
int sign = 4;
int signs = 5;
int signz = 6;
int sigs = 7;
// Here we capture when a user selects a menu item
void menu_select_callback(MenuLayer *menu_layer, MenuIndex *cell_index, void *data) {

     register Tuplet symbol_tuple = TupletInteger(SPY_KEY_START, symbol);
     register Tuplet symbol_tuples = TupletInteger(SPY_KEY_START, symbols);
     register Tuplet symbol_tuplez = TupletInteger(SPY_KEY_START, symbolz);
     register Tuplet symbol_tups = TupletInteger(SPY_KEY_START, sign);
     register Tuplet symbol_tupz = TupletInteger(SPY_KEY_START, signs);
     register Tuplet symbol_tupez = TupletInteger(SPY_KEY_START, signz);
	  register Tuplet symbol_tup = TupletInteger(SPY_KEY_START, sigs;
  switch (cell_index->row) {

case 0:


sendMes(symbol_tupez);
 window_layers = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layers);
 text_layer = text_layer_create((GRect) { .origin = { 0, 0 }, .size = { bounds.size.w-0, 200 } });
  text_layer_set_overflow_mode(text_layer, GTextOverflowModeWordWrap);
  text_layer_set_text_alignment(text_layer, GTextAlignmentCenter);
text_layer_set_text(text_layer, "Loading Camera");
  layer_add_child(window_layers, text_layer_get_layer(text_layer));
timerz = app_timer_register(3300 /* milliseconds */, timer_mod, NULL);
break;
case 1:


sendMes(symbol_tuplez);
window_layers = window_get_root_layer(window);
  GRect bound = layer_get_bounds(window_layers);
 text_layer = text_layer_create((GRect) { .origin = { 0, 0 }, .size = { bound.size.w-0, 200 } });
  text_layer_set_overflow_mode(text_layer, GTextOverflowModeWordWrap);
  text_layer_set_text_alignment(text_layer, GTextAlignmentCenter);
text_layer_set_text(text_layer, "Loading Camera");
  layer_add_child(window_layers, text_layer_get_layer(text_layer));
timerz = app_timer_register(3300 /* milliseconds */, timer_mod, NULL);
    // This is the menu item with the cycling icon
break;
    case 2:


sendMes(symbol_tups);

      break;
case 3:
sendMes(symbol_tuples);
window_layers = window_get_root_layer(window);
  GRect bounde = layer_get_bounds(window_layers);
 text_layer = text_layer_create((GRect) { .origin = { 0, 0 }, .size = { bounde.size.w-0, 200 } });
  text_layer_set_overflow_mode(text_layer, GTextOverflowModeWordWrap);
  text_layer_set_text_alignment(text_layer, GTextAlignmentCenter);
text_layer_set_text(text_layer, "Loading Voice Rec");
  layer_add_child(window_layers, text_layer_get_layer(text_layer));
timer = app_timer_register(1000 /* milliseconds */, timer_mods, NULL);


      break;
case 4:
  sendMes(symbol_tupz);
      break;
case 5:


  sendMes(symbol_tuple);
      break;
	  
	  case 6:


  sendMes(symbol_tup);
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

void window_unload(Window *window) {
  // Destroy the menu layer
  menu_layer_destroy(menu_layer);
app_timer_cancel(timerz);
  // Cleanup the menu icons
  
}

int main(void) {
  window = window_create();

  // Setup the window handlers
  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });

  window_stack_push(window, true /* Animated */);
app_comm_set_sniff_interval(SNIFF_INTERVAL_REDUCED);
  // Init buffers
   app_message_open(app_message_inbox_size_maximum(), app_message_outbox_size_maximum());
  // Register message handlers
  app_message_register_inbox_received(in_received_handler);
   app_message_register_inbox_dropped(in_dropped_handler);
   app_message_register_outbox_sent(out_sent_handler);
   app_message_register_outbox_failed(out_failed_handler);


  app_event_loop();

  window_destroy(window);
}
