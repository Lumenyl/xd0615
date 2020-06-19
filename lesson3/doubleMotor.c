char a=' ';
void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  Serial.println("\nEnter command:\nf:Go forward\nb:Draw back\nr:Turn right\nl:Turn left\ns:Stop\n");
}

void loop()
{
 if(Serial.available()>0)
  {
  	a=Serial.read();
    switch(a)
    {
    case 'f':
      digitalWrite(10,HIGH);
      digitalWrite(11,LOW);
      digitalWrite(12,HIGH);
      digitalWrite(13,LOW);
      Serial.print("Go forward\n");
      break;
    case 'b':
      digitalWrite(11,HIGH);
      digitalWrite(10,LOW);
      digitalWrite(12,HIGH);
      digitalWrite(13,LOW);
      Serial.print("Draw back\n");
      break;
    case 'r':
      digitalWrite(11,HIGH);
      digitalWrite(10,LOW);
      digitalWrite(12,HIGH);
      digitalWrite(13,LOW);
      Serial.print("Turn right\n");
      break;
    case 'l':
      digitalWrite(10,HIGH);
      digitalWrite(11,LOW);
      digitalWrite(13,HIGH);
      digitalWrite(122,LOW);
      Serial.print("Turn left\n");
      break;
    case 's':
      digitalWrite(10,LOW);
      digitalWrite(11,LOW);
      digitalWrite(12,LOW);
      digitalWrite(13,LOW);
      Serial.print("STOP\n");
      break;
    default:
      Serial.print("Invalid command\n");
      break;
    }
  }
}