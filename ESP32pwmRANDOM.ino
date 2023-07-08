int pwmChannel = 0;    // Selects channel 0
int frequence = 1000;  // PWM frequency of 1 KHz
int resolution = 16;   // 8(16)-bit resolution, 256(65536) possible values
int pwmPin = 2;
int pwmlevel = 5000;

hw_timer_t *My_timer = NULL;
void IRAM_ATTR onTimer(){
pwmlevel = random(65536);
ledcWrite(pwmChannel, pwmlevel);
timerAlarmWrite(My_timer, random(500000), true);
//digitalWrite(LED, !digitalRead(LED));
}

void setup() {
  // Configuration of channel 0 with the chosen frequency and resolution
  ledcSetup(pwmChannel, frequence, resolution);

  // Assigns the PWM channel to pin 23
  ledcAttachPin(pwmPin, pwmChannel);

  // Create the selected output voltage
  ledcWrite(pwmChannel, pwmlevel);  // = ?? V

My_timer = timerBegin(0, 80, true);
timerAttachInterrupt(My_timer, &onTimer, true);
timerAlarmWrite(My_timer, 1000000, true);
timerAlarmEnable(My_timer); //Just Enable
}

void loop() {
}