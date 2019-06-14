/* Motor Paso a Paso ajustado a grados
  by: www.elprofegarcia.com

  Gira los grados que se le indiquen por el monitor serial o bluetooth

  Arduino    Driver ULN200
  8          IN1
  9          IN2
  10         IN3
  11         IN4

  Tienda en Linea: http://dinastiatecnologica.com/
*/


int retardo = 5;        // Tiempo de retardo en milisegundos (Velocidad del Motor)
int dato_rx;            // valor recibido en grados
int numero_pasos = 0;   // Valor en grados donde se encuentra el motor
char mover="";
String leeCadena;       // Almacena la cadena de datos recibida

void setup() {
  Serial.begin(9600);     // inicializamos el puerto serie a 9600 baudios
  pinMode(11, OUTPUT);    // Pin 11 conectar a IN4
  pinMode(10, OUTPUT);    // Pin 10 conectar a IN3
  pinMode(9, OUTPUT);     // Pin 9 conectar a IN2
  pinMode(8, OUTPUT);     // Pin 8 conectar a IN1*/
/**motor2****/

  pinMode(7, OUTPUT);    // Pin 7 conectar a IN4
  pinMode(6, OUTPUT);    // Pin 6 conectar a IN3
  pinMode(5, OUTPUT);    // Pin 5 conectar a IN2
  pinMode(4, OUTPUT);    // Pin 4 conectar a IN1
  
}

void loop() {

   int j=0;
  mover=" ";
  while (Serial.available()) {    // Leer el valor enviado por el Puerto serial

    if(j==0){
         
    }else{
      delay(retardo);
      char c  = Serial.read();     // Lee los caracteres
      Serial.print(" QUE ES? ");
      if(mover!=' ' && (c=='L' || c=='R' || c=='U' || c=='D') ){ 
        Serial.print(" ALGO ");
        mover=c;
      }else{
        if(c!='-'){
          leeCadena += c;              // Convierte Caracteres a cadena de caracteres
        }
      }
    }   
    j++;
  }
  if (leeCadena.length() > 0) {
    dato_rx = leeCadena.toInt();   // Convierte Cadena de caracteres a Enteros
    Serial.print(dato_rx);         // Envia valor en Grados
    Serial.println(" Grados");
    delay(retardo);
    dato_rx = (dato_rx * 1.4222222222); // Ajuste de 512 vueltas a los 360 grados
  }
  dato_rx =15;
  numero_pasos =0;
  while (mover=='L' && dato_rx > numero_pasos) { // Girohacia la izquierda en grados
    Serial.print("izquierda\n");
    motor1_IZQ();
   // motor2_ABA();
    numero_pasos = numero_pasos + 1;
  }

  while (mover=='D' && dato_rx > numero_pasos) { // Girohacia la izquierda en grados
    Serial.print("DOWN\n");
    //motor1_IZQ();
    motor2_ABA();
    numero_pasos = numero_pasos + 1;
  }

  while (mover=='R' && dato_rx > numero_pasos) { // Giro hacia la derecha en grados
    Serial.print("derecha\n");
    motor1_DER();
   // motor2_ARR();
    numero_pasos = numero_pasos + 1;
  }

  while (mover=='U' && dato_rx > numero_pasos) { // Giro hacia la derecha en grados
    Serial.print("UP\n");
    //motor1_DER();
    motor2_ARR();
    numero_pasos = numero_pasos + 1;
  }
  
  leeCadena = "";   // Inicializamos la cadena de caracteres recibidos
  apagado();         // Apagado del Motor para que no se caliente
}  ///////////////////// Fin del Loop ///////////////////////////

// Pasos a la derecha

void motor1_DER(){ 
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(8, HIGH);
  delay(retardo);
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);
  delay(retardo);
  digitalWrite(11, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  delay(retardo);
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);
  delay(retardo);
 
}


void motor1_IZQ() {        // Pasos a la izquierda
  digitalWrite(11, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  delay(retardo);
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);
  delay(retardo);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(8, HIGH);
  delay(retardo);
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);
  delay(retardo);
}

void motor2_ARR() {        
  
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(4, HIGH);
  delay(retardo);
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(4, HIGH);
  delay(retardo);
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(4, HIGH);
  delay(retardo);
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(4, HIGH);
  delay(retardo);
  
}

void motor2_ABA() {        // Pasos a la izquierda
  digitalWrite(7, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(4, LOW);
  delay(retardo);
  digitalWrite(7, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(4, LOW);
  delay(retardo);
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(4, HIGH);
  delay(retardo);
  digitalWrite(7, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);
  digitalWrite(4, HIGH);
  delay(retardo);
}

void apagado() {         // Apagado del Motor
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);
  digitalWrite(4, LOW);
}

//https://www.youtube.com/watch?v=d_laD0zb_Ew
//Geeky Theory
