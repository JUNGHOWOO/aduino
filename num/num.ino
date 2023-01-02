int ledPin = 12;
int senser = A0;
int piezoPin = 11;

unsigned int frqArray[7] = 
{
  262,
  294,
  330,
  349,
  392,
  440,
  494
};

int signatures[20]  = {2,4,4,2,2,2,4,4,2,2,4,4,2,4,4,2,2,2,2};

int scale[20] = {0,0,0,0,0,2,4,4,2,0,4,4,2,4,4,2,0,0,0};

  void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(piezoPin, OUTPUT);
  }

  void loop() {
    int val = analogRead(A0);
    Serial.println(val);
    delay(100);
    
       if(val>50)
      {
       
        for(int i=0; i<19;i++)
    {
      unsigned long duration
      = 1000 / signatures[i];

      tone(11, frqArray[scale[i]], duration);
        digitalWrite(12,HIGH);
     
      delay(duration*1.5);
      noTone(12);
    }
      }
    else
    {
      digitalWrite(12, LOW);
      noTone(12);
    }
    }
 
