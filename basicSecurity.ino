// Define a key for encrypting and decrypting the message
const int key = 12345;

// Define a function for encrypting a message
String encrypt(String message) {
  // Create an empty string to store the encrypted message
  String encrypted = "";

  // Loop through each character in the message
  for (int i = 0; i < message.length(); i++) {
    // Get the current character in the message
    char character = message[i];

    // Encrypt the character by adding the key to its ASCII value
    char encryptedCharacter = character + key;

    // Append the encrypted character to the encrypted message
    encrypted += encryptedCharacter;
  }

  // Return the encrypted message
  return encrypted;
}

// Define a function for decrypting a message
String decrypt(String encrypted) {
  // Create an empty string to store the decrypted message
  String decrypted = "";

  // Loop through each character in the encrypted message
  for (int i = 0; i < encrypted.length(); i++) {
    // Get the current character in the encrypted message
    char character = encrypted[i];

    // Decrypt the character by subtracting the key from its ASCII value
    char decryptedCharacter = character - key;

    // Append the decrypted character to the decrypted message
    decrypted += decryptedCharacter;
  }

  // Return the decrypted message
  return decrypted;
}

void setup() {
  // Initialize the serial port for communication
  Serial.begin(9600);

  // Define a message to encrypt
  String message = "Hello, world!";

  // Encrypt the message
  String encrypted = encrypt(message);

  // Print the encrypted message
  Serial.println(encrypted);

  // Decrypt the message
  String decrypted = decrypt(encrypted);

  // Print the decrypted message
  Serial.println(decrypted);
}

void loop() {
  // Empty loop
}
