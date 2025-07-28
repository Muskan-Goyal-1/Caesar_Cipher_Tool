
#include <iostream>
#include <string>
#include <ctime>
#include <cctype>
#include <limits> 

using namespace std;

class CaesarCipher {
private:
    int randomKey;  // Random key (101-999)
    int shiftKey;   // Actual shift key (sum of first and last digits of randomKey)

    // Generate a random key between 101 and 999
    int generateRandomKey() {
        srand(time(0));
        return rand() % 899 + 101; // Ensures key is between 101 and 999
    }

    // Calculate the shift key (sum of first and last digits of random key)
    int calculateShiftKey(int randomKey) {
        int firstDigit = randomKey / 100;
        int lastDigit = randomKey % 10;
        return firstDigit + lastDigit;
    }

public:
    CaesarCipher() {
        randomKey = generateRandomKey();
        shiftKey = calculateShiftKey(randomKey);
    }

    // Encrypt the message
    string encryptMessage(const string& text) {
        string encryptedText;

        for (char c : text) {
            if (isupper(c)) { // Encrypt uppercase letters
                encryptedText += ((c - 'A' + shiftKey) % 26) + 'A';
            } else if (islower(c)) { // Encrypt lowercase letters
                encryptedText += ((c - 'a' + shiftKey) % 26) + 'a';
            } else if (isdigit(c)) { // Encrypt numbers cyclically
                encryptedText += to_string((c - '0' + shiftKey) % 10);
            } else { // Keep symbols and spaces unchanged
                encryptedText += c;
            }
        }

        return encryptedText;
    }

    // Decrypt the message
    string decryptMessage(const string& text, int userShiftKey) {
        string decryptedText;

        for (char c : text) {
            if (isupper(c)) { // Decrypt uppercase letters
                decryptedText += ((c - 'A' - userShiftKey + 26) % 26) + 'A';
            } else if (islower(c)) { // Decrypt lowercase letters
                decryptedText += ((c - 'a' - userShiftKey + 26) % 26) + 'a';
            } else if (isdigit(c)) { // Decrypt numbers cyclically
                decryptedText += to_string((c - '0' - (userShiftKey % 10) + 10) % 10);
            } else { // Keep symbols and spaces unchanged
                decryptedText += c;
            }
        }

        return decryptedText;
    }

    // Getters
    int getRandomKey() const {
        return randomKey;
    }

    int getShiftKey() const {
        return shiftKey;
    }
};

void handleInputError() {
    cerr << "Invalid input. Please restart the program and try again." << endl;
}

int main() {
    CaesarCipher cipher; // Create an instance of CaesarCipher
    int choice;
    while (true)
    {
        cout << "\n========================================" << endl;
        cout << "   Caesar Cipher Machine 🛡️" << endl;
        cout << "========================================" << endl;
        cout << "\nChoose an option:" << endl;
        cout << "1. Encrypt a message" << endl;
        cout << "2. Decrypt a message" << endl;
        cout << "3. Exit\n" << endl;
        cout << "Your choice: ";

        cin >> choice;
        if (cin.fail() || choice < 1 || choice > 3) {
            handleInputError();
            return 1;
        }

        switch (choice) {
            case 1: { // Encryption
                string text;

                cout << "\nEnter the text to encrypt: ";
                cin.ignore(); 
                getline(cin, text);

                string encryptedText = cipher.encryptMessage(text);
                cout << "\nEncrypted Text: " << encryptedText << endl;
                cout << "Your 3-digit key (keep it safe!): " << cipher.getRandomKey() << endl;
                break;
            }

            case 2: { // Decryption
                string text;
                int userShiftKey;

                cout << "Enter the ciphered text: ";
                cin.ignore(); 
                getline(cin, text);

                cout << "Enter the key: ";
                cin >> userShiftKey;

                string decryptedText = cipher.decryptMessage(text, userShiftKey);
                cout << "Decrypted Text: " << decryptedText << endl;
                break;
            }

            case 3: { // Exit
                cout << "\nExiting the program. Goodbye! 👋\n" << endl;
                return 0;

            }
        }

        
        cout << "\nPress Enter to return to the main menu...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }
    return 0; 
}
