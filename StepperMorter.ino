#include <RTClib.h>
#include <LCD_I2C.h>

LCD_I2C lcd(0x27, 16, 2);
RTC_DS1307 rtc;

char daysOfWeek[7][12] = {
  "Sun",
  "Mon",
  "Tus",
  "Wed",
  "Thr",
  "Fri",
  "Sat"
};

void setup() {
  Serial.begin(9600);
  if (!rtc.begin()) {
    Serial.println("RTC module is NOT found");
    Serial.flush();
    while (1)
      ;
  }
  // automatically sets the RTC to the date & time on PC this sketch was compiled
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  // manually sets the RTC with an explicit date & time, for example to set
  // January 21, 2021 at 3am you would call:
  // rtc.adjust(DateTime(2021, 1, 21, 3, 0, 0));
  lcd.begin();
  lcd.backlight();
}

void loop() {
  DateTime now = rtc.now();

  Serial.print("ESP32 RTC Date Time: ");
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(" (");
  Serial.print(daysOfWeek[now.dayOfTheWeek()]);
  Serial.print(") ");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.println(now.second(), DEC);

  lcd.setCursor(0, 0);
  lcd.print(now.year(), DEC);
  lcd.print('/');
  lcd.print(now.month(), DEC);
  lcd.print('/');
  lcd.print(now.day(), DEC);
  lcd.print(" (");
  lcd.print(daysOfWeek[now.dayOfTheWeek()]);
  lcd.print(") ");
  lcd.setCursor(0, 1);
  lcd.print(now.hour(), DEC);
  lcd.print(':');
  lcd.print(now.minute(), DEC);
  lcd.print(':');
  lcd.print(now.second(), DEC);
  // lcd.setCursur(5,0);
  // lcd.print(daysOftheWeek[now.dayOfTheWeek()]);
  // lcd.setCursur(5,1);
  // lcd.print(now.hour() +":"+now.minute()+":"+now.second());
  delay(1000);  // delay 1 seconds
}