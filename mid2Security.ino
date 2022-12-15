#include <Crypto.h>
#include <AES.h>

const byte key[] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
                     0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F };

AES aes(key); // Create an instance of the AES object

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Get user input for the message to encrypt
  String input = "";
  Serial.println("Enter the message to encrypt: ");
  while (input.length() == 0) {
    while (Serial.available() > 0) {
      char c = Serial.read();
      if (c == '\n') continue;
      input += c;
    }
  }

  // Encrypt the input message
  size_t inputLen = input.length() + 1;
  char inputChars[inputLen];
  input.toCharArray(inputChars, inputLen);

  int outputLen;
  byte *output = aes.EncryptECB(inputChars, inputLen, &outputLen);

  // Print the encrypted message
  Serial.println("Encrypted message: ");
  for (int i = 0; i < outputLen; i++) {
    Serial.print(output[i]);
  }
  Serial.println();

  // Get user input for the encrypted message to decrypt
  String encryptedInput = "";
  Serial.println("Enter the encrypted message to decrypt: ");
  while (encryptedInput.length() == 0) {
    while (Serial.available() > 0) {
      char c = Serial.read();
      if (c == '\n') continue;
      encryptedInput += c;
    }
  }

  // Convert the encrypted input message to a byte array
  size_t encryptedInputLen = encryptedInput.length() / 2;
  byte encryptedInputBytes[encryptedInputLen];
  for (int i = 0; i < encryptedInputLen; i++) {
    encryptedInputBytes[i] = encryptedInput.substring(i * 2, i * 2 + 2).toInt();
  }

  // Decrypt the encrypted message
  int decryptedLen;
  byte *decrypted = aes.DecryptECB(encryptedInputBytes, encryptedInputLen, &decryptedLen);

  // Print the decrypted message
  Serial.println("Decrypted message: ");
  for (int i = 0; i < decryptedLen; i++) {
    Serial.print(decrypted[i]);
  }
  Serial.println();
}
