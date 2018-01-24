#include <LCD1x9.h>

LCD1X9 LCD;

char Text[9];
unsigned char Hours=23, Minutes=59, Seconds=55;
long Time, PrevTime=0;

void setup()
{
  LCD.Initialize();
  Serial.begin(9600);
  Serial.println("HELLO");
  pinMode(PB0, INPUT);
  pinMode(D14, INPUT);
}

void UpdateTime ()
{
  Time = millis();

  if (Time - PrevTime >= 1000)
  {
    PrevTime = Time;
    Seconds++;
    if (Seconds == 60)
    {
      Seconds = 0;
      Minutes++;
      if (Minutes == 60)
      {
        Minutes = 0;
        Hours++;
        if (Hours == 24)
          Hours = 0;
      }
    }
  }
}

void UpdateBuffer ()
{
  Text[0] = (Hours/10) + '0';
  Text[1] = (Hours%10) + '0';
  Text[2] = '.';
  Text[3] = (Minutes/10) + '0';
  Text[4] = (Minutes%10) + '0';
  Text[5] = '.';
  Text[6] = (Seconds/10) + '0';
  Text[7] = (Seconds%10) + '0';
}

void loop()
{
  UpdateTime ();
  UpdateBuffer ();
  LCD.Write (Text);
  Serial.println("HELLO");
  Serial.print("PB0 : ");
  Serial.println(PB0);
  Serial.print("D14 : ");
  Serial.println(D14);
}
