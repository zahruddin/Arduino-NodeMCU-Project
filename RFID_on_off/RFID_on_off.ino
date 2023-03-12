// Project Pengaman On Off Alat/Mesin Menggunakan RFID dan Arduino
// Dibuat oleh : M. Nofgi Y.P.U.
// www.nofgipiston.wordpress.com
// Tokopedia/Bukalapak = Nofgi Piston Shop


// menambah library program
#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>

// inialisasi pin RFID, buzzer, dan relay
constexpr uint8_t RST_PIN = D3;     // Configurable, see typical pin layout above
constexpr uint8_t SS_PIN = D4;     // Configurable, see typical pin layout above
MFRC522 mfrc522(SS_PIN, RST_PIN);
int pinBuzzer = D8;
int pinRelay = D2;
//int led      = D0;


// inialisasi variabel kondisi
int kondisi;


// ===================== PROGRAM PENGATURAN AWAL ======================= //

void setup()
{
  // inialisasi baud rate serial monitor
  Serial.begin(115200); // Initiate a serial communication
  SPI.begin(); // Initiate SPI bus
  mfrc522.PCD_Init(); // Initiate MFRC522

  // inialisasi status I/O pin
  pinMode(pinBuzzer, OUTPUT);
  pinMode(pinRelay, OUTPUT);
//  pinMode (led, OUTPUT);
  
  // mematkan buzzer dan relay di awal program
  digitalWrite(pinBuzzer, HIGH);
  digitalWrite(pinRelay, HIGH);
//  digitalWrite(led, LOW);
  // kondisi awal = 0
  kondisi = 0;
}

// ============================== PROGRAM UTAMA ============================== //

void loop()
{

  // cek kartu RFID baru
  if ( ! mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }

  // memilih kartu RFID
  if ( ! mfrc522.PICC_ReadCardSerial())
  {
    return;
  }

  // menampilkan ID kartu RFID pada Serial Monitor
  Serial.print("UID:");
  String content = " ";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);

    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }

  content.toUpperCase();

  // *** PROGRAM JIKA KARTU RFID SESUAI DENGAN YANG TERDAFTAR *** //
  // ****** ubah ID katu RFID yang ingin didaftarkan di sini ****** //
  if (content.substring(1) == "6A 0B 32 B4", "BC E2 20 30")
  {


    // PROGRAM "ON" alat

    // jika kondisi = 0
    if (kondisi == 0)
    {
      // relay dinyalakan
      // alat dalam kondisi "ON"
      // buzzer menyala
      digitalWrite(pinRelay, LOW);
      digitalWrite(pinBuzzer, HIGH);
      delay(500);
      // buzzer dimatikan
      digitalWrite(pinBuzzer, LOW);
      // kondisi menjadi = 1
      kondisi = 1;
    }

    // PROGRAM "OFF" alat

    // jika kondisi = 1
    else if (kondisi == 1)
    {
      // relay dimatikan
      // alat dalam kondisi "ON"
      // buzzer menyala
      digitalWrite(pinRelay, HIGH);
      digitalWrite(pinBuzzer, HIGH);
      delay(300);
      digitalWrite(pinBuzzer, LOW);
      delay(300);
      digitalWrite(pinBuzzer, HIGH);
      delay(300);
      digitalWrite(pinBuzzer, LOW);
      delay(300);
      // kondisi menjadi = 0
      kondisi = 0;
    }
  }

  // PROGRAM JIKA KARTU RFID YANG DIGUNAKAN SALAH ATAU TIDAK TERDAFTAR

  else {
    // buzzer berbunyi pendek 3 kali
    digitalWrite(pinBuzzer, LOW);
    delay(300);
    digitalWrite(pinBuzzer, HIGH);
    delay(300);
    digitalWrite(pinBuzzer, LOW);
    delay(300);
    digitalWrite(pinBuzzer, HIGH);
    delay(300);
    digitalWrite(pinBuzzer, LOW);
    delay(300);
  }
}
