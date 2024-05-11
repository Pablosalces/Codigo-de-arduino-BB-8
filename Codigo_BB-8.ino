int bob_1=8;
int bob_2=9;
int bob_3=10;
int bob_4=11;
int trigger=7;
int echo=6;
long distancia;
long tiempo;
int paso_avance [4] [4]= //1paso enciende las 4 bobinas 1 vez
  {
  {1,0,0,0},
  {0,1,0,0},
  {0,0,1,0},
  {0,0,0,1}
  };
 int paso_retroceso [4] [4]=
  {
  {0,0,0,1},
  {0,0,1,0},
  {0,1,0,0},  
  {1,0,0,0}
  };


  
void setup() {
  Serial.begin(9600);
  pinMode(bob_1,OUTPUT);
  pinMode(bob_2,OUTPUT);
  pinMode(bob_3,OUTPUT);
  pinMode(bob_4,OUTPUT);
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);
}



void loop() {
  for (int i=0; i < 512/2; i++) 
  {    
    for (int i=0; i < 4; i++) {
      digitalWrite(bob_1,paso_avance[i][0]);
      digitalWrite(bob_2,paso_avance[i][1]);
      digitalWrite(bob_3,paso_avance[i][2]);
      digitalWrite(bob_4,paso_avance[i][3]);
       delay(10);      
       distancia=calculo_distancia();
       Serial.print(distancia);
       Serial.println(" cm");
        
    }
  }
  for (int i=0; i < 512; i++) 
  {    
    for (int i=0; i < 4; i++) {
      
      digitalWrite(bob_1,paso_retroceso[i][0]);
      digitalWrite(bob_2,paso_retroceso[i][1]);
      digitalWrite(bob_3,paso_retroceso[i][2]);
      digitalWrite(bob_4,paso_retroceso[i][3]);
       delay(10);
       distancia=calculo_distancia();
       Serial.print(distancia);
       Serial.println(" cm");      
    }
  }
}
int calculo_distancia () { 
         digitalWrite(trigger, LOW); 
         delay(2);
         digitalWrite(trigger, HIGH);
         delay(10);
         digitalWrite(trigger, LOW);
         tiempo = pulseIn(echo, HIGH);  
         distancia = tiempo*10 / 292/ 2;
  return distancia;
}
