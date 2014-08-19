#include <pebble.h>
#include "APPMESSAGE.h"

 void out_sent_handler(DictionaryIterator *sent, void *context) {
 APP_LOG(APP_LOG_LEVEL_DEBUG, "App Message worked!");
 }


 void out_failed_handler(DictionaryIterator *failed, AppMessageResult reason, void *context) {
 APP_LOG(APP_LOG_LEVEL_DEBUG, "App Message Failed to Send!");
 }


 void in_received_handler(DictionaryIterator *received, void *context) {
  Tuple *start_tuple = dict_find(iter, SPY_KEY_START);
   


  if (start_tuple) {
    text_layer_set_text(text_layer, append_tuple->value->cstring);

  }

	

         
      





 void in_dropped_handler(AppMessageResult reason, void *context) {
  APP_LOG(APP_LOG_LEVEL_DEBUG, "App Message Dropped!");
 }
