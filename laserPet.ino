#include <PubSubClient.h>
#include <ESP8266WiFi.h>

#include <Servo.h>
#define POS_INICIAL 90
#define X_MINIMO    30 // Angulo de X (30 a 150)
#define Y_MINIMO    50 // Angulo de y (50 a 90)
#define X_INTERVALO 12 // (X maximo - X minimo)/10 = 12 
#define Y_INTERVALO  4 // (Y maximo - Y minimo)/10 = 4
#define LASER_TEMPO 60
#define LASER       5
#define PIR         4

Servo servoX;
Servo servoY;

// SETUP WIFI E MQTT

const char* ssid = "";                         // SSID DA SUA REDE
const char* password = "";                // SENHA DA SUA REDE WIFI
const char* mqtt_server = "mqtt.eclipseprojects.io";  // BROKER MQTT ADRESS
const int mqtt_port = 1883;                           // BROKER MQTT PORT
const char* mqtt_user = "usuario";
const char* mqtt_password= "senha";

WiFiClient espClient;
PubSubClient client(espClient);



void setup() {
  Serial.begin(115200);
  servoX.attach(0);
  servoY.attach(2);
  servoX.write(POS_INICIAL);
  servoY.write(POS_INICIAL);

  pinMode(LASER, OUTPUT);
  digitalWrite(LASER, LOW);

  pinMode(PIR, INPUT);

  setup_wifi();
  client.setServer(mqtt_server, 1883); //BROKER ADRESS, MQTT PORT
  
}

void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("ESP8266Client", mqtt_user, mqtt_password)) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 2 seconds");
      delay(2000);
    }
  }
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  
  int trigger = digitalRead(PIR);
  client.publish("outTopic", String(trigger).c_str());
  
  if (trigger == HIGH){
    Serial.println("Detectado");
    ligaLaser();
  } else {
    desligaLaser();
    Serial.println("Não detectado");
  }

}

void posiciona_servos(){
  int posicaoX = (random(0,(X_INTERVALO))* 10 + (X_MINIMO));
  int posicaoY = (random(0,(Y_INTERVALO))* 10 + (Y_MINIMO));
  servoX.write(posicaoX);
  servoY.write(posicaoY); 
}

void ligaLaser(){ 
  for(int i=0; i<= LASER_TEMPO/2; i++){
digitalWrite(LASER, HIGH);
posiciona_servos();
delay(2000);
}
}

void desligaLaser(){
digitalWrite(LASER, LOW);
}
  
