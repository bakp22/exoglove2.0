idf_component_register(SRCS "startup.c" "wait.c"
                       INCLUDE_DIRS "."
                       REQUIRES esp_driver_gpio esp_driver_spi esp_wifi mqtt)
