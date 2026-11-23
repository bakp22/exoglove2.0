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
// MQTT settings: topics/port in config/app_config.h,
// broker/client id/WiFi in config/secrets.h (copy secrets.h.example).
#include "startup.h"
#include "app_config.h"
#include "secrets.h"

const char* BROKER = MQTT_BROKER;
const int PORT = MQTT_PORT;
const char* CMD_TOPIC = MQTT_CMD_TOPIC;
const char* TEST_TOPIC = MQTT_TEST_TOPIC;
const char* CLIENT_ID = MQTT_CLIENT_ID;


// TAKE A LOOK AT STARTUP STATE DIAGRAM AND ISSUE FOR INSTRUCTIONS(read thoroughly)

// TODO: setup function
    


// TODO: loop funciton
