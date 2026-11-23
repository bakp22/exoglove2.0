idf_component_register(SRCS "main.c"
                            "states/startup.c"
                            "states/wait.c"
                       INCLUDE_DIRS "." "states" "config"
                       REQUIRES pump valve pressure_sensor comms
                                esp_driver_gpio esp_driver_spi esp_wifi mqtt)
