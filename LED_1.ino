#define LED_PIN 18

void setup() {
  pinMode(LED_PIN, OUTPUT); // กำหนดให้ขา 18 เป็นขา OUTPUT
}

void loop() {
  digitalWrite(LED_PIN, HIGH); // เปิด LED
  delay(1000);                 // รอ 1 วินาที
  digitalWrite(LED_PIN, LOW);  // ปิด LED
  delay(1000);                 // รอ 1 วินาที
}
