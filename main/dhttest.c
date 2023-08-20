#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include <esp_err.h>
#include <esp_log.h>
static const char *TAG = "[DHT11_Project]";

#include <dht_espidf.h>

#define DHT_IO 16 //27

//void app_main();

struct dht_reading dht_data;

int app_main() {

    //struct dht_reading dht_data{};
while(1){
    dht_result_t res = read_dht_sensor_data((gpio_num_t)DHT_IO, DHT2X, &dht_data);

    if (res != DHT_OK) {
        ESP_LOGW(TAG, "DHT sensor reading failed");
    } else {
        double fahrenheit = (dht_data.temperature * 1.8f) + 32.0f;
        double humidity = dht_data.humidity;
        ESP_LOGI(TAG, "DHT sensor reading: %f° / %f", fahrenheit, humidity);
    }
    
    vTaskDelay(CONFIG_BLINK_PERIOD / portTICK_PERIOD_MS);
}
    return 0;
}
