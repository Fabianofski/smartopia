#include "standing_desk_sensor.h"
#include "esphome/core/log.h"

namespace esphome {
namespace standing_desk_sensor {

static const char *TAG = "standing_desk_sensor.sensor";

void StandingDeskSensor::setup() {
}

void StandingDeskSensor::update() {
}

void StandingDeskSensor::loop() {
  if (available()) {
    ESP_LOGI(TAG, "AVAILABLE");
  } else {
    ESP_LOGI(TAG, "UNAVAILABLE");
  }
}

void StandingDeskSensor::dump_config(){
    ESP_LOGCONFIG(TAG, "Standing Desk Sensor");
}

}  // namespace standing_desk_sensor
}  // namespace esphome
