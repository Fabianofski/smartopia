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
  while (this->available() >= 9) {
    uint8_t header1, header2;
    this->read_byte(&header1);
    this->read_byte(&header2);
    if (header1 == 0xF2 && header2 == 0xF2) {
      uint8_t payload[7];
      for (int i = 0; i < 7; i++) this->read_byte(&payload[i]);
      float height = (payload[2] << 8) | payload[3]; 
      publish_state(height / 10); 
    }
  }
}

void StandingDeskSensor::dump_config(){
    ESP_LOGCONFIG(TAG, "Standing Desk Sensor");
}

}  // namespace standing_desk_sensor
}  // namespace esphome
