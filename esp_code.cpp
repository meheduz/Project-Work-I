#include <WiFi.h>
#include "esp_http_server.h"

// Wi-Fi credentials
const char* ssid = "OPPO A92";
const char* password = "12345678";

// Motor pins (L298N)
#define MOTOR_1_PIN_1    14
#define MOTOR_1_PIN_2    15
#define MOTOR_2_PIN_1    13
#define MOTOR_2_PIN_2    12

httpd_handle_t server = NULL;

// HTML Page
static const char PROGMEM INDEX_HTML[] = R"rawliteral(
<html>
<head>
<title>ESP32 CAR</title>
<meta name="viewport" content="width=device-width, initial-scale=1">
<style>
body { font-family: Arial; text-align: center; margin-top: 30px;}
.button { background-color: #2f4468; color: white; padding: 15px; font-size: 18px; margin: 5px; cursor: pointer; }
</style>
</head>
<body>
<h1>ESP32 CAR CONTROL</h1>
<button class="button" onmousedown="sendCmd('forward')" onmouseup="sendCmd('stop')">FORWARD</button><br>
<button class="button" onmousedown="sendCmd('left')" onmouseup="sendCmd('stop')">LEFT</button>
<button class="button" onmousedown="sendCmd('right')" onmouseup="sendCmd('stop')">RIGHT</button><br>
<button class="button" onmousedown="sendCmd('backward')" onmouseup="sendCmd('stop')">BACKWARD</button><br>
<button class="button" onmousedown="sendCmd('stop')">STOP</button>

<script>
function sendCmd(cmd){
  var xhr = new XMLHttpRequest();
  xhr.open("GET", "/cmd?go=" + cmd, true);
  xhr.send();
}
</script>
</body>
</html>
)rawliteral";

// Handle Motor Commands
static esp_err_t cmd_handler(httpd_req_t *req){
  char variable[32] = {0};
  size_t buf_len = httpd_req_get_url_query_len(req) + 1;

  if(buf_len > 1){
    char* buf = (char*) malloc(buf_len);
    if(httpd_req_get_url_query_str(req, buf, buf_len) == ESP_OK){
      httpd_query_key_value(buf, "go", variable, sizeof(variable));
    }
    free(buf);
  }

  if(strcmp(variable, "left") == 0){
    digitalWrite(MOTOR_1_PIN_1, HIGH);
    digitalWrite(MOTOR_1_PIN_2, LOW);
    digitalWrite(MOTOR_2_PIN_1, HIGH);
    digitalWrite(MOTOR_2_PIN_2, LOW);
    Serial.println("left");
  }
  else if(strcmp(variable, "right") == 0){
    digitalWrite(MOTOR_1_PIN_1, LOW);
    digitalWrite(MOTOR_1_PIN_2, HIGH);
    digitalWrite(MOTOR_2_PIN_1, LOW);
    digitalWrite(MOTOR_2_PIN_2, HIGH);
    Serial.println("right");
  }
  else if(strcmp(variable, "backward") == 0){
    digitalWrite(MOTOR_1_PIN_1, LOW);
    digitalWrite(MOTOR_1_PIN_2, HIGH);
    digitalWrite(MOTOR_2_PIN_1, HIGH);
    digitalWrite(MOTOR_2_PIN_2, LOW);
    Serial.println("Backward");
  }
  else if(strcmp(variable, "forward") == 0){
    digitalWrite(MOTOR_1_PIN_1, HIGH);
    digitalWrite(MOTOR_1_PIN_2, LOW);
    digitalWrite(MOTOR_2_PIN_1, LOW);
    digitalWrite(MOTOR_2_PIN_2, HIGH);
    Serial.println("Forward");
  }
  else if(strcmp(variable, "stop") == 0){
    digitalWrite(MOTOR_1_PIN_1, LOW);
    digitalWrite(MOTOR_1_PIN_2, LOW);
    digitalWrite(MOTOR_2_PIN_1, LOW);
    digitalWrite(MOTOR_2_PIN_2, LOW);
    Serial.println("Stop");
  }

  httpd_resp_send(req, NULL, 0);
  return ESP_OK;
}

// Start Web Server
void startServer(){
  httpd_config_t config = HTTPD_DEFAULT_CONFIG();
  config.server_port = 80;
  httpd_uri_t index_uri = { "/",
    HTTP_GET,
    [](httpd_req_t *req){ return httpd_resp_send(req, INDEX_HTML, strlen(INDEX_HTML)); },
    NULL };

  httpd_uri_t cmd_uri = { "/cmd", HTTP_GET, cmd_handler, NULL };

  if(httpd_start(&server, &config) == ESP_OK){
    httpd_register_uri_handler(server, &index_uri);
    httpd_register_uri_handler(server, &cmd_uri);
  }
}

void setup(){
  Serial.begin(115200);

  // Motor pins
  pinMode(MOTOR_1_PIN_1, OUTPUT);
  pinMode(MOTOR_1_PIN_2, OUTPUT);
  pinMode(MOTOR_2_PIN_1, OUTPUT);
  pinMode(MOTOR_2_PIN_2, OUTPUT);

  // Connect Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting");
  while(WiFi.status() != WL_CONNECTED){
    delay(500); Serial.print(".");
  }
  Serial.println("\nWiFi Connected!");
  Serial.print("Open: http://"); Serial.println(WiFi.localIP());

  startServer();
}

void loop(){}
