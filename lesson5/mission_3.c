/*
题目3
功能：一次输入一串数字，从左至右滚动显示在四个七段数码管显示器上。
编写于：2020.6.22
*/
#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5
#define S1 8
#define S2 9
#define S3 10
#define S4 11
#define LT 6
#define BT 7
void setup()
{
  pinMode(IN1, OUTPUT);//输入1
  pinMode(IN2, OUTPUT);//输入2
  pinMode(IN3, OUTPUT);//输入3
  pinMode(IN4, OUTPUT);//输入4
  pinMode(S1, OUTPUT);//片选1
  pinMode(S2, OUTPUT);//片选2
  pinMode(S3, OUTPUT);//片选3
  pinMode(S4, OUTPUT);//片选4
  pinMode(LT,OUTPUT);//测试
  pinMode(BT,OUTPUT);//消隐
  digitalWrite(LT,HIGH);
  digitalWrite(BT,HIGH);
  digitalWrite(S1,HIGH);
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  digitalWrite(S4,HIGH);
  digitalWrite(S1,LOW);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  digitalWrite(S1,HIGH);
  digitalWrite(S2,LOW);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  digitalWrite(S2,HIGH);
  digitalWrite(S3,LOW);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  digitalWrite(S3,HIGH);
  digitalWrite(S4,LOW);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
  digitalWrite(S4,HIGH);
  Serial.begin(9600);
}
byte a=0,b=0,c=0,d=0,t=0;
void loop()
{
  if (Serial.available()>0)
  {
    for (int i=0;;i++)
    {
      Serial.print("t=");
      Serial.println(t);//输出测试信息
	  d=c;
      c=b;
      b=a;
      if (t!=207)
      {a=t;}
      Serial.print("d,c,b,a=");
      Serial.print(d);
      Serial.print(",");
      Serial.print(c);
      Serial.print(",");
      Serial.print(b);
      Serial.print(",");
      Serial.println(a);//输出测试信息
      t=Serial.read();
      t=t-'0';
      digitalWrite(8,LOW);
      digitalWrite(IN1,a&0x1);
      digitalWrite(IN2,(a>>1)&0x1);
      digitalWrite(IN3,(a>>2)&0x1);
      digitalWrite(IN4,(a>>3)&0x1); 
      digitalWrite(8,HIGH);
      digitalWrite(9,LOW);
      digitalWrite(IN1,b&0x1);
      digitalWrite(IN2,(b>>1)&0x1);
      digitalWrite(IN3,(b>>2)&0x1);
      digitalWrite(IN4,(b>>3)&0x1);
      digitalWrite(9,HIGH);
      digitalWrite(10,LOW);
      digitalWrite(IN1,c&0x1);
      digitalWrite(IN2,(c>>1)&0x1);
      digitalWrite(IN3,(c>>2)&0x1);
      digitalWrite(IN4,(c>>3)&0x1);
      digitalWrite(10,HIGH);
      digitalWrite(11,LOW);
      digitalWrite(IN1,d&0x1);
      digitalWrite(IN2,(d>>1)&0x1);
      digitalWrite(IN3,(d>>2)&0x1);
      digitalWrite(IN4,(d>>3)&0x1);
      digitalWrite(11,HIGH);
      if (t==207)
      {break;}//串口无输入后跳出循环
      delay(500);//调整滚动延时
    }
    Serial.println("end");
    a=0,b=0,c=0,d=0,t=0;//初始化，准备下次运行
  }
}