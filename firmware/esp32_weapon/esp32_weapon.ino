#include <ps4.h>
#include <PS4Controller.h>
#include <ps4_int.h>
#define MOTOR_PIN 13  // Broche de commande du moteur

BleGamepad bleGamepad;  // Objet pour la manette Bluetooth

bool motorState = false;  // État du moteur (marche ou non)

void setup() {
  pinMode(MOTOR_PIN, OUTPUT);  // Définir la broche du moteur comme sortie
  Serial.begin(115200);  // Initialiser la communication série

  // Initialiser le Bluetooth de la manette
  bleGamepad.begin();
}

void loop() {
  bleGamepad.poll();  // Vérifier les entrées de la manette

  // Si le bouton "A" (ou un autre bouton selon la configuration) est pressé
  if (bleGamepad.isPressed(BUTTON_1)) {  // Par exemple, BUTTON_1 est le bouton "A" sur PS4
    motorState = !motorState;  // Inverser l'état du moteur
    delay(500);  // Délai pour éviter les rebonds du bouton
  }

  // Activer/désactiver le moteur en fonction de l'état
  if (motorState) {
    digitalWrite(MOTOR_PIN, HIGH);  // Allumer le moteur
  } else {
    digitalWrite(MOTOR_PIN, LOW);  // Éteindre le moteur
  }

  // Afficher l'état pour débogage
  Serial.print("Motor State: ");
  Serial.println(motorState ? "ON" : "OFF");

  delay(100);  // Délai pour éviter une lecture trop rapide
}
