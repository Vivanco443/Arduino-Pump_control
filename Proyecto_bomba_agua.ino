
// Cuando SAT1 y 0 estan e HIGH es que estan llenos
 // Cuando SBT1 y 0 estan e HIGH es que estan vacios

//  Actuadores
#define EB 3    //  enable bomba
#define EV1 4 //  enable valvula 1
#define EV0 5   //  enable valvula 0

  //  Sensores
#define energia1 7    // Señal para los sensores
#define SAT0 8    //  Sensor alto Tinaco 0 o tinaco de abajo
#define SBT0 9    //  Sensor bajo Tinaco 0 o tinaco de abajo
#define SAT1 10   //  Sensor alto Tinaco 1 o tinaco de arriba
#define SBT1 11   //  Sensor bajo Tinaco 1 o tinaco de arriba
#define energia0 12   // Señal para los sensores

//banderas
bool Bajotinaco000 = false;
bool Altotinaco000 = false;
bool Bajotinaco111 = false;
bool Altotinaco111 = false;


void setup() {
  pinMode(EB, OUTPUT);
  pinMode(EV0, OUTPUT);
  pinMode(EV1, OUTPUT);
  digitalWrite(EB, LOW);
  digitalWrite(EV0, LOW);
  digitalWrite(EV1, LOW);

  pinMode(energia0, OUTPUT);
  pinMode(energia1, OUTPUT);
  digitalWrite(energia0, HIGH);
  digitalWrite(energia1, HIGH);
  
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  

}

void loop() {

  Bajotinaco111 = digitalRead(SBT1);
  if (Bajotinaco111 == true){   // Esta abierto cuando hay agua   ; cuando falta el agua arriba
    //  Osea que falta agua arriba
    
    do{   // Mientras se llena arriba
        Bajotinaco000 = digitalRead(SBT0);
        
        if(Bajotinaco000 == false){    // Si hay agua en el tinaco de abajo
            Elevacion_de_agua();
        }
        Llenado_tinaco_0();
      
        Altotinaco111 = digitalRead(SAT1);
    
    
    } while(Altotinaco111 == false);
    
  }
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(2000);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(2000); 
}

void Llenado_tinaco_0(){
  digitalWrite(EV0, HIGH);    //Abrimos la valvula de llenado
  do{
          digitalWrite(LED_BUILTIN, HIGH);      // Mientras esta abierta dejamos parpadeando el led
          delay(2000);                       
          digitalWrite(LED_BUILTIN, LOW);    
          delay(500);
          digitalWrite(LED_BUILTIN, HIGH);   
          delay(500);                       
          digitalWrite(LED_BUILTIN, LOW);    
          delay(500);
          digitalWrite(LED_BUILTIN, HIGH);   
          delay(500); 
          digitalWrite(LED_BUILTIN, LOW);    
          delay(500); 
          
          Altotinaco000 = digitalRead(SAT0);
  }while(Altotinaco000 == false);
      
  digitalWrite(EV0, LOW);   // Cerramos valvula de llenado
}

void Elevacion_de_agua(){
  //Abrimos valvula 1
  digitalWrite(EV1, HIGH);
  delay(2000);
  //Enciende la bomba
  digitalWrite(EB, HIGH);
          
  do {  // Esperamos que pase cualquiera de ambas
    digitalWrite(LED_BUILTIN, HIGH);   
    delay(500);                             //  Mientras trabaja la bomba dejamos trabajando el led
    digitalWrite(LED_BUILTIN, LOW);    
    delay(500); 
            
    // leemos sensores
    Bajotinaco000 = digitalRead(SBT0);
    Altotinaco111 = digitalRead(SAT1); 
          
  }while(Bajotinaco000 == false && Altotinaco111 == false);
        
  //Apaga la bomba
  digitalWrite(EB, LOW);
  delay(2000);
  digitalWrite(EV1, LOW);
}
