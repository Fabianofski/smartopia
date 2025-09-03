
import paho.mqtt.client as mqtt
import time
import json

BROKER = "home-server"  
PORT = 1883
DEVICE_NAME = "mein_test_device"
UNIQUE_ID = "test_switch_1"

client = mqtt.Client()
client.username_pw_set("user", "pass")

def on_connect(client, userdata, flags, rc):
    config_topic = f"homeassistant/switch/{DEVICE_NAME}/config"
    state_topic = f"{DEVICE_NAME}/state"
    command_topic = f"{DEVICE_NAME}/set"

    payload = {
        "name": "Test Schalter",
        "uniq_id": UNIQUE_ID,
        "stat_t": state_topic,
        "cmd_t": command_topic,
    }

    client.publish(config_topic, json.dumps(payload), retain=True)
    client.publish(state_topic, "OFF", retain=True)

def on_message(client, userdata, msg):
    topic = msg.topic
    payload = msg.payload.decode() 
    print(f"Nachricht empfangen: Topic='{topic}', Payload='{payload}'")

    if msg.payload.decode() == "ON":
        client.publish(f"{DEVICE_NAME}/state", "ON", retain=True)
    else:
        client.publish(f"{DEVICE_NAME}/state", "OFF", retain=True)

client.on_connect = on_connect
client.on_message = on_message

client.connect(BROKER, PORT, 60)
client.subscribe(f"{DEVICE_NAME}/set")

client.loop_start()

while True:
    time.sleep(1)
