#include "pebble.h"
#include "APPMESSAGE.h"



void camera(Tuplet tup){
  
 

  
  regSync();

sendMes(tup);
    
    replace = "Loading Camera";
   
   addWindow("Loading Camera", y);
  
   

  
}

void vidCam(Tuplet tup){
  app_message_deregister_callbacks();

    regSync();

  sendMes(tup);
    
           replace = "Loading Recorder";

  addWindow("Loading Recorder", y);
}

void audRec(Tuplet tup){
  
   app_message_deregister_callbacks();

    regSync();

sendMes(tup);
   
replace = "Loading Audio";
     
addWindow("Loading Audio", window);
  
}

void voice(Tuplet tup){
  listener = true;
   app_message_deregister_callbacks();

        regSync();

sendMes(tup);
        replace = "Loading Voice Rec";

addWindow("Loading Voice Rec", window);
}

void motionD(Tuplet tup){
  
  
  
  
  
  
    app_message_deregister_callbacks();

        regSync();

    replace = "Detecting Motion";
   
    addWindow("Detecting Motion", window);
     
      sendMes(tup);

    

}

void flashF(Tuplet tup){
   app_message_deregister_callbacks();

        regSync();

  sendMes(tup);
  replace = "Starting Flashlight";
  addWindow(replace, window);

}

void silence(Tuplet tup){
    app_message_deregister_callbacks();

        regSync();

     sendMes(tup);
   addWindow(NULL, window);
      
  
}




void window_sets(Window *x, MenuLayerCallbacks men) {
window_layers = window_get_root_layer(x);
  GRect bounds = layer_get_frame(window_layers);

    

  // Create the menu layer
  menu_layers = menu_layer_create(bounds);

 
  // Set all the callbacks for the menu layer
  menu_layer_set_callbacks(menu_layers, NULL, men);

  // Bind the menu layer's click config provider to the window for interactivity
  menu_layer_set_click_config_onto_window(menu_layers, x);

  // Add it to the window for display
  layer_add_child(window_layers, menu_layer_get_layer(menu_layers));

}

void changeWindow(Window *z, MenuLayerCallbacks man){
z = window_create();


window_sets(z, man);


y = z;


  window_stack_push(z, true /* Animated */);

}




