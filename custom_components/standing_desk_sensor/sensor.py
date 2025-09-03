import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import uart, sensor
DEPENDENCIES = ["uart"]

empty_uart_sensor_ns = cg.esphome_ns.namespace("standing_desk_sensor")
StandingDeskSensor = empty_uart_sensor_ns.class_(
    "StandingDeskSensor", cg.PollingComponent, uart.UARTDevice
)

CONFIG_SCHEMA = (
    sensor.sensor_schema(
        StandingDeskSensor,
        accuracy_decimals=1,
    )
    .extend(cv.polling_component_schema("5s"))
    .extend(uart.UART_DEVICE_SCHEMA)
)


async def to_code(config):
    var = await sensor.new_sensor(config)
    await cg.register_component(var, config)
    await uart.register_uart_device(var, config)
