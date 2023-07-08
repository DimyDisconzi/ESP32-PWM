int pwmChannel = 0;    // Selects channel 0
int frequence = 15000;  // PWM frequency of 15 KHz
int resolution = 12;   // 8(12-16)-bit resolution, 256(4095-65536) possible values obs.: máx freq do pwm diminui com aumento da resolução
int Delta_us = 30000;
int pwmPin = 2;
int pwmlevel = 0;
int Arrayline =0;
float MyArray [36][2]= {
{0, 0.00},
{10,	0.17},
{20,	0.34},
{30,	0.50},
{40,	0.64},
{50,	0.77},
{60,	0.87},
{70,	0.94},
{80,	0.98},
{90,	1.00},
{100,	0.98},
{110,	0.94},
{120,	0.87},
{130,	0.77},
{140,	0.64},
{150,	0.50},
{160,	0.34},
{170,	0.17},
};


hw_timer_t *My_timer = NULL;
void IRAM_ATTR onTimer(){
timerAlarmWrite(My_timer, Delta_us, true);
if (Arrayline++ > 17) Arrayline = 0;
pwmlevel = 4095 * MyArray[Arrayline][1];
ledcWrite(pwmChannel, pwmlevel);
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
  timerAlarmWrite(My_timer, Delta_us, true);
  timerAlarmEnable(My_timer); //Just Enable
}

void loop() {
}