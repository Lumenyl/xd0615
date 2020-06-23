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
  pinMode(IN1, OUTPUT);//输入1
  pinMode(IN2, OUTPUT);//输入2
  pinMode(IN3, OUTPUT);//输入3
  pinMode(IN4, OUTPUT);//输入4
  pinMode(9, OUTPUT);//片选1
  pinMode(LT,OUTPUT);//测试
  pinMode(BT,OUTPUT);//消隐
  digitalWrite(LT,HIGH);
  digitalWrite(BT,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  MsTimer2::set(1000, onTimer); //设置中断，每1000ms进入一次中断服务程序 onTimer()
  MsTimer2::start(); //开始计时
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