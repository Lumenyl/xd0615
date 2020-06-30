/*
  Analog input, analog output, serial output

  Reads an analog input pin, maps the result to a
  range from 0 to 255  and uses the result to set
  the pulsewidth modulation (PWM) of an output
  pin.  Also prints the results to the serial
  monitor.

  The circuit:
  * potentiometer connected to analog pin 0.
    Center pin of the potentiometer goes to the
    analog pin. side pins of the potentiometer go
    to +5V and ground
  * LED connected from digital pin 9 to ground

  created 29 Dec. 2008
  modified 9 Apr 2012
  by Tom Igoe

  This example code is in the public domain.
*/

int sensorValue = 0;

int outputValue = 0;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);

}

void loop()
{
  // ��ȡA0���ŵĵ���ֵ������������sensorValue:
  sensorValue = analogRead(A0);
  // ��sensorValue��ֵӳ�䵽��һ��������С:
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  // ����С��SVֵд��9����:
  analogWrite(9, outputValue);
  // �ڴ��м����������SV��OV��ֵ:
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);
  // 2����֮�������һ��ѭ��:
  delay(2); // ����2������ʱ
}