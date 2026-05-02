// Pin Definiti
const int pwmPin = 3;   // Pin PWM per scrivere il voltaggio (richiede ~)
const int analogPin = A0; // Pin per leggere il voltaggio

void setup() {
  // Impostazione registri per PWM rapido (presumo tu stia usando Arduino Uno/Nano)
  TCCR2A = (TCCR2A & 0b11111000) | 0b00000001;
  TCCR2B = (TCCR2B & 0b11111000) | 0b00000001;
  
  Serial.begin(9600); // Inizializza la porta USB
  Serial.setTimeout(20); // Riduce il tempo di attesa per la lettura da USB
}

void loop() {
  // --- PARTE 1: RICEZIONE DA LABVIEW (Scrittura Voltaggio) ---
  // Manteniamo questa parte fuori dal ciclo di lettura per garantire
  // che Arduino possa ricevere comandi prima di iniziare il campionamento
  if (Serial.available() > 0) {
    float voltageInput = Serial.parseFloat(); 
    
    // Converte da 0-5V a 0-255 (PWM)
    int pwmValue = constrain((voltageInput / 5.0) * 255, 0, 255);
    
    analogWrite(pwmPin, pwmValue);
    
    // Pulisce il buffer seriale
    while(Serial.available() > 0) { Serial.read(); }
  }

  // --- PARTE 2: LETTURA E MEDIA (10 letture in ~100ms) ---
  long sommaValori = 0; // Usiamo long per evitare overflow (anche se con 10 int è difficile)
  
  // Esegue 10 letture
  for (int i = 0; i < 10; i++) {
    sommaValori += analogRead(analogPin); // Somma la lettura corrente
    delay(10); // Aspetta 10ms tra una lettura e l'altra
  }

  // Calcola la media (raw 0-1023)
  float mediaRaw = sommaValori / 10.0;

  // Converte la media in Voltaggio (0-5V)
  float voltageOutput = mediaRaw * (5.0 / 1023.0);
  
  // Invia il valore medio a LabVIEW
  Serial.println(voltageOutput); 

}