
#define encoder0Pin               3
volatile int count, countold;
int DCMotor = 2;
int button1 = 4;
boolean start = false;
int n = HIGH;
int nprev = LOW;
void setup()
{
  count = 0;
  countold = 0;
  // External Pullup Needed so as not to short the ground (NO INPUT_PULLUP)
  pinMode(encoder0Pin, INPUT); 
 // attachInterrupt(0, sensor1, FALLING);

  digitalWrite(DCMotor,LOW);
  pinMode(button1, INPUT);

  Serial.begin(9600); // initialize serial communication:

}

void loop()
{
  n = digitalRead(encoder0Pin);
  if ( n == HIGH && nprev == LOW)
  {
    count++;
    }
    nprev = n;
    
  if (digitalRead(button1) == HIGH){
    start = true;
    count = 0;
    }
  if (start == true){
    digitalWrite(DCMotor,HIGH);
    }
  else {
    digitalWrite(DCMotor,LOW);
    }
  if (countold != count)
  {
    Serial.println(count);
       countold = count;
  }
   if (count > 24){
      start = false;
    }
}

/*void sensor1()
{
  count++;
}
*/

