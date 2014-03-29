#include <pebble.h>
#include "APPMESSAGE.h"

 void out_sent_handler(DictionaryIterator *sent, void *context) {
 APP_LOG(APP_LOG_LEVEL_DEBUG, "App Message worked!");
 }


 void out_failed_handler(DictionaryIterator *failed, AppMessageResult reason, void *context) {
 APP_LOG(APP_LOG_LEVEL_DEBUG, "App Message Failed to Send!");
 }


 void in_received_handler(DictionaryIterator *received, void *context) {
 
 Tuple *text_tuple = dict_find(received, SPY_KEY_STOP);
   Tuple *get_tuple = dict_find(received, SPY_KEY_START);

        
    if(text_tuple){
      
      datar = text_tuple->value->uint8;
      
  //     snprintf(text_buffer, 1024, "%s", text_tuple->value->cstring);
  

           //APP_LOG(APP_LOG_LEVEL_DEBUG, "Text: %s", text_buffer);
}

   if(get_tuple){
       snprintf(text_buffer, 1024, "%s", get_tuple->value->cstring);
  text_layer_set_text(text_layer, text_buffer);

           APP_LOG(APP_LOG_LEVEL_DEBUG, "Text: %s", text_buffer);
}
      

    
  

	
 }
         
      





 void in_dropped_handler(AppMessageResult reason, void *context) {
  APP_LOG(APP_LOG_LEVEL_DEBUG, "App Message Dropped!");
 }
