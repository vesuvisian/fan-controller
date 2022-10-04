#define len 200
int old = 0;
int val = 0;
int counter = 0;
int breaker = 0;
bool startb = false;
unsigned long sigs[len];
unsigned long now = micros();
unsigned long last = micros();

void setup() {
  Serial.begin(115200);
  pinMode(2, INPUT);
}

void loop() {
  now = micros();
  val = digitalRead(2);
//  if (Serial.available() > 0){
//    while(true){}
//  }
  if (val != old) {
    sigs[counter] = now - last;
    if (now - last > 240000){
      startb = true;
    }
    if (startb){
      breaker++;
    }
    counter = (counter + 1) % len;
    last = now;
    old = val;
  }
  if (breaker > len-1){
    for(int i=0; i<len; i++){
      Serial.println(sigs[(counter+i)%len]);
      //Serial.print(", ");
    }
    //Serial.println();
    while (1){}
  }
}
