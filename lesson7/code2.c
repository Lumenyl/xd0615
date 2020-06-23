#include <MsTimer2.h>
#define IN1 3
#define IN2 4
#define IN3 5
#define IN4 6
#define LT 7
#define BT 8
byte tick=0;
void setup()
{
  pinMode(IN1, OUTPUT);//����1
  pinMode(IN2, OUTPUT);//����2
  pinMode(IN3, OUTPUT);//����3
  pinMode(IN4, OUTPUT);//����4
  pinMode(9, OUTPUT);//Ƭѡ1
  pinMode(LT,OUTPUT);//����
  pinMode(BT,OUTPUT);//����
  digitalWrite(LT,HIGH);
  digitalWrite(BT,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  MsTimer2::set(1000, onTimer); //�����жϣ�ÿ1000ms����һ���жϷ������ onTimer()
  MsTimer2::start(); //��ʼ��ʱ
}
void onTimer()
{
  digitalWrite(IN1,tick&0x1);
  digitalWrite(IN2,(tick>>1)&0x1);
  digitalWrite(IN3,(tick>>2)&0x1);
  digitalWrite(IN4,(tick>>3)&0x1);
  if (tick<9)
  {
  	tick++;
  }
  else
  {
  	tick=0;
  }
}
void loop()
{
  if (digitalRead(2)==LOW)
  {
  	tick=0;
  }
}