#include <Arduino.h>
#include <TenzoRS485.h>

#define PRINT_CELL  0

HardwareSerial newSerial(PA9, PA10);

TenzoRS485 leftHipCell                          (newSerial, 2);
TenzoRS485 leftKneeCell                         (newSerial, 4);

TenzoRS485 leftHeelLeftCell                     (newSerial, 7); 
// TenzoRS485 leftHeelRightCell                    (newSerial, 21);

TenzoRS485 leftMetatarsalLeftCell               (newSerial, 8); 
// TenzoRS485 leftMetatarsalRightCell              (newSerial, 21);

TenzoRS485 rightHipCell                         (newSerial, 3);
TenzoRS485 rightKneeCell                        (newSerial, 1);

TenzoRS485 rightHeelLeftCell                    (newSerial, 6); 
TenzoRS485 rightHeelRightCell                   (newSerial, 5);

// TenzoRS485 rightMetatarsalLeftCell              (newSerial, 21); 
// TenzoRS485 rightMetatarsalRightCell             (newSerial, 21);

inline bool getPermissionToStart() {
  if(Serial.available() > 0) {
    String _input = Serial.readStringUntil('\n');
    delay(10);
    _input.trim();
    Serial.println(_input);
    if(_input.equals("Tenzo")) {
      Serial.println("Tenzo");
      return false;
    }
    else return true;
  }
  return true;
}

void setup() {
  Serial.begin(115200);

  leftHipCell.begin(115200);                          
  leftKneeCell.begin(115200);
  leftHeelLeftCell.begin(115200);
  // leftHeelRightCell.begin(115200);
  leftMetatarsalLeftCell.begin(115200);
  // leftMetatarsalRightCell.begin(115200);

  rightHipCell.begin(115200);
  rightKneeCell.begin(115200);
  rightHeelLeftCell.begin(115200);
  rightHeelRightCell.begin(115200);
  // rightMetatarsalLeftCell.begin(115200);
  // rightMetatarsalRightCell.begin(115200);
}

void loop() {

  if(PRINT_CELL == 1) { 
    Serial.print("Л. бедро.: ");              Serial.print(leftHipCell.getCell());
    Serial.print(" Л. колено.: ");             Serial.print(leftKneeCell.getCell());
    Serial.print(" Л. пятка(л): ");            Serial.print(leftHeelLeftCell.getCell());
    // Serial.print("Л. пятка(п): ");            Serial.print(leftHeelRightCell.getCell());
    Serial.print(" Л. носок(л): ");            Serial.print(leftMetatarsalLeftCell.getCell());
    // Serial.print("Л. носок(п): ");            Serial.print(leftMetatarsalRightCell.getCell());


    Serial.print(" П. бедро.: ");              Serial.print(rightHipCell.getCell());
    Serial.print(" П. колено.: ");             Serial.print(rightKneeCell.getCell());
    Serial.print(" П. пятка(л): ");            Serial.print(rightHeelLeftCell.getCell());
    Serial.print(" П. пятка(п): ");            Serial.println(rightHeelRightCell.getCell());
    // Serial.print("П. носок(л): ");            Serial.print(rightMetatarsalLeftCell.getCell());
    // Serial.print("П. носок(п): ");            Serial.println(rightMetatarsalRightCell.getCell());
  }
}