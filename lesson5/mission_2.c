/*
��Ŀ2
���ܣ�һ�������ĸ����֣���������������ʾ���ĸ��߶��������ʾ���ϡ�
��д�ڣ�2020.6.22
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
  pinMode(IN1, OUTPUT);//����1
  pinMode(IN2, OUTPUT);//����2
  pinMode(IN3, OUTPUT);//����3
  pinMode(IN4, OUTPUT);//����4
  pinMode(S1, OUTPUT);//Ƭѡ1
  pinMode(S2, OUTPUT);//Ƭѡ2
  pinMode(S3, OUTPUT);//Ƭѡ3
  pinMode(S4, OUTPUT);//Ƭѡ4
  pinMode(LT,OUTPUT);//����
  pinMode(BT,OUTPUT);//����
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
byte a=0,b=0,c=0,d=0;
void loop()
{
  if (Serial.available()>0)
  {
  	a=Serial.read();
    a=a-'0';
    digitalWrite(11,LOW);
    digitalWrite(IN1,a&0x1);
    digitalWrite(IN2,(a>>1)&0x1);
    digitalWrite(IN3,(a>>2)&0x1);
    digitalWrite(IN4,(a>>3)&0x1); 
    digitalWrite(11,HIGH);
    delay(1);
  	b=Serial.read();
    b=b-'0';
    digitalWrite(10,LOW);
    digitalWrite(IN1,b&0x1);
    digitalWrite(IN2,(b>>1)&0x1);
    digitalWrite(IN3,(b>>2)&0x1);
    digitalWrite(IN4,(b>>3)&0x1); 
    digitalWrite(10,HIGH);
    delay(1);
  	c=Serial.read();
    c=c-'0';
    digitalWrite(9,LOW);
    digitalWrite(IN1,c&0x1);
    digitalWrite(IN2,(c>>1)&0x1);
    digitalWrite(IN3,(c>>2)&0x1);
    digitalWrite(IN4,(c>>3)&0x1); 
    digitalWrite(9,HIGH);
    delay(1);
  	d=Serial.read();
    d=d-'0';
    digitalWrite(8,LOW);
    digitalWrite(IN1,d&0x1);
    digitalWrite(IN2,(d>>1)&0x1);
    digitalWrite(IN3,(d>>2)&0x1);
    digitalWrite(IN4,(d>>3)&0x1); 
    digitalWrite(8,HIGH);
    delay(1);
  }
}