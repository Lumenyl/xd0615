void setup()
{
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
}

void loop()
{
  int a,i;
  for (a=1;a<=20;a++)
    {
    	if (a<=10) {i=a;}
   		else {i=21-a;};
  		digitalWrite(i, HIGH);
  		delay(50); // Wait for 50 millisecond(s)
  		digitalWrite(i, LOW);
  		delay(50); // Wait for 50 millisecond(s)
    } 
}