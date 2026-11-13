/*
 * Code for STARTUP state 
 *
 * State should run after the glove is put on and before our WAIT state. 
 * Tasks that STARTUP state should do are the following:
 *    1. connects to the pump and network
 *    2. verifies the state configuration 
 *    3. initiliazes configuration data
 *    4. checks the system is safe before handing off to WAIT
 *    5. if any step fails STARTUP aborts (stop the process and alert the user)
 *
 * */

/*
    Files to include place here:
*/

/*
    Defined Constants from Dependency Injection files
*/

#include <stdio.h>
#include "esp_wifi.h"
#include "mqtt_client.h"


/* ---------- Configuration Block ------------ */

// MQTT Configuration //
const char* BROKER = "rasticvm.internal";
const int PORT = 1883;
const char* CMD_TOPIC = "racuum/racuum-ACE9/setpoint";
const char* TEST_TOPIC = "racuum/racuum-ACE9/test";
const char* CLIENT_ID = "berenakpinar";
















// TAKE A LOOK AT STARTUP STATE DIAGRAM AND ISSUE FOR INSTRUCTIONS(read thoroughly)

// TODO: setup function
    


// TODO: loop funciton
