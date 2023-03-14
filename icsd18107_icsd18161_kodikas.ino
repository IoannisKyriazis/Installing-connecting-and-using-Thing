//  Papadopoulos  Panagiotis  3212018161
//  Kyriazis      Ioannis     3212018107


/*    ΦΤΙΑΞΑΜΕ ΚΑΙΝΟΥΡΙΟ APPLICATION ΜΕ APPEUI= "***" ΚΑΙ DEVEUI= "***" ΚΑΙ Η ΣΥΝΔΕΣΗ ΜΕ ΤΟ ΤΤΝ
      ΕΠΕΤΕΥΧΘΕΙ. ΣΤΗΝ ΣΥΝΕΧΕΙΑ ΕΛΕΓΞΑΜΕ ΜΕ ΕΠΙΤΥΧΙΑ ΤΑ ΜΗΝΥΜΑΤΑ ΠΟΥ ΕΜΦΑΝΙΖΟΝΤΑΙ ΣΤΟ ΤΤΝ ΣΕ ΔΙΑΚΕΞΑΔΙΚΗ ΜΟΡΦΗ. ΤΟ ΜΟΝΟ
      ΠΡΟΒΛΗΜΑ ΠΟΥ ΑΝΤΙΜΕΤΩΠΙΖΕΙ Ο ΠΑΡΑΚΑΤΩ ΚΩΔΙΚΑΣ, ΕΙΝΑΙ ΟΤΙ ΤΟ WATCHDOG ΔΕΝ ΔΟΥΛΕΨΕ ΠΟΤΕ ΚΑΙ ΓΙ' ΑΥΤΟ ΤΟΝ ΒΑΛΑΜΕ ΣΕ ΣΧΟΛΙΑ
      ΜΑΖΙ ΜΕ ΟΛΟ ΤΟ ΚΟΜΜΑΤΙ ΚΩΔΙΚΑ ΠΟΥ ΤΟΝ ΣΥΝΟΔΕΥΕΙ. ΕΠΙΣΗΣ ΑΝΤΙΜΕΤΩΠΙΣΑΜΕ ΠΡΟΒΛΗΜΑ ΜΕ ΤΗΝ ΕΓΚΑΤΑΣΤΑΣΗ ΤΟΥ MOSQUITTO ΚΑΙ ΕΤΣΙ
      ΔΕΝ ΔΙΑΘΕΤΟΥΜΕ ΠΛΗΡΟΦΟΡΙΕΣ ΑΠΟ ΑΥΤΟ.
*/

#include <MKRWAN.h>
#include <Adafruit_SleepyDog.h>

int green_led_pin = LED_BUILTIN;
int red_led_pin = LED_BUILTIN;
LoRaModem modem;

// Uncomment if using the Murata chip as a module
// LoRaModem modem(Serial1);

String appEui = "***";
String appKey = "***";
int countdownMS;
String msg;
unsigned long xronos = millis();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  while (!Serial);
  //countdownMS = Watchdog.enable(100000);
  // change this to your regional band (eg. US915, AS923, ...)
  if (!modem.begin(EU868)) {
    Serial.println("Failed to start module");
    while (1) {}
  };
  Serial.print("Your module version is: ");
  Serial.println(modem.version());
  Serial.print("Your device EUI is: ");
  Serial.println(modem.deviceEUI());

  int connected = modem.joinOTAA(appEui, appKey);
  if (!connected) {
    Serial.println("Something went wrong; are you indoor? Move near a window and retry");
    while (1) {}
  }

  // Set poll interval to 60 secs.
  modem.minPollInterval(60);
  // NOTE: independent of this setting, the modem will
  // not allow sending more than one message every 2 minutes,
  // this is enforced by firmware and can not be changed.

  pinMode(green_led_pin, OUTPUT);
  pinMode(red_led_pin, OUTPUT);
}

void loop() {

/*  if (xronos == countdownMS) {
    String msg3 = "KANEI RESET!!";
    Serial.print("Sending: " + msg3 + " - ");
    for (unsigned int i = 0; i < msg3.length(); i++) {
      Serial.print(msg3[i] >> 4, HEX);
      Serial.print(msg3[i] & 0xF, HEX);
      Serial.print(" ");
    }
    Serial.println();

    int err;
    modem.beginPacket();
    modem.print(msg3);
    err = modem.endPacket(true);
    if (err > 0) {
      Serial.println("Message sent correctly!");
    } else {
      Serial.println("Error sending message :(");
      Serial.println("(you may send a limited amount of messages per minute, depending on the signal strength");
      Serial.println("it may vary from 1 message every couple of seconds to 1 message every minute)");
    }
    countdownMS = 0;
    Watchdog.reset();

    Serial.println();
  }
  else {*/
    int counter = 0;
    int tyxaios = 0;
    do {
      tyxaios = random(0, 10);
      counter = counter + tyxaios;
      if (counter > 161) {
        while (!Serial.available());
        RG_color(255, 0);
        digitalWrite(green_led_pin, HIGH);
        delay(1000);
        digitalWrite(green_led_pin, LOW);
        while (!Serial.available());
        String msg1 = "Green Light";
        Serial.print("Sending: " + msg1 + " - ");
        for (unsigned int i = 0; i < msg1.length(); i++) {
          Serial.print(msg1[i] >> 4, HEX);
          Serial.print(msg1[i] & 0xF, HEX);
          Serial.print(" ");
        }
        Serial.println();

        int err;
        modem.beginPacket();
        modem.print(msg1);
        err = modem.endPacket(true);
        if (err > 0) {
          Serial.println("Message sent correctly!");
        } else {
          Serial.println("Error sending message :(");
          Serial.println("(you may send a limited amount of messages per minute, depending on the signal strength");
          Serial.println("it may vary from 1 message every couple of seconds to 1 message every minute)");
        }


        Serial.println();
        break;
      }
      delay(1000);
    } while (1);




    delay(1000);


    counter = 0;
    int tyxaios1 = 0;
    do {
      tyxaios1 = random(0, 10);
      counter = counter + tyxaios1;
      if (counter > 161) {
        counter = 0;
        RG_color(0, 255);
        digitalWrite(red_led_pin, HIGH);
        delay(1000);
        digitalWrite(red_led_pin, LOW);
        while (!Serial.available());
        String msg2 = "Red Light";
        Serial.print("Sending: " + msg2 + " - ");
        for (unsigned int i = 0; i < msg2.length(); i++) {
          Serial.print(msg2[i] >> 4, HEX);
          Serial.print(msg2[i] & 0xF, HEX);
          Serial.print(" ");
        }
        Serial.println();

        int err;
        modem.beginPacket();
        modem.print(msg2);
        err = modem.endPacket(true);
        if (err > 0) {
          Serial.println("Message sent correctly!");
        } else {
          Serial.println("Error sending message :(");
          Serial.println("(you may send a limited amount of messages per minute, depending on the signal strength");
          Serial.println("it may vary from 1 message every couple of seconds to 1 message every minute)");
        }

        Serial.println();
        break;
      }

      delay(1000);
    } while (1);

 // }
  delay(1000);
}





void RG_color(int green_led_value, int red_led_value)
{
  analogWrite(green_led_pin, green_led_value);
  analogWrite(red_led_pin, red_led_value);
}
