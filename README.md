

# Caesar Cipher Utility

A straightforward, command-line application for text encryption and decryption using a classic Caesar cipher. This implementation incorporates a two-layer key system to determine the character shift, adding a unique step to the standard algorithm.

The tool is self-contained and requires no external libraries for operation.

## Core Features

  * *Text Encryption*: Transforms plaintext into a ciphered message.
  * *Text Decryption*: Reverts a ciphered message back to its original form.
  * *Character Handling*:
      * Encrypts uppercase and lowercase alphabetic characters.
      * Encrypts numerical digits with a cyclical shift.
      * Preserves all other characters, including symbols and spaces.
  * *Unique Key System*: Employs a 3-digit public key from which the actual encryption shift is derived.

## Understanding the Key System

The cipher's security relies on a two-part key mechanism. It's important to understand how they work together.

1.  *Public Key*: When you encrypt a message, you are given a 3-digit number (e.g., 489). This is your *Public Key*. You must save this key to decrypt the message later.

2.  *Shift Key*: The actual value used to shift the characters is the sum of the **first* and *last* digits of your Public Key. This is the *Shift Key*.

For example, if your given Public Key is 489:

  * The first digit is 4.
  * The last digit is 9.
  * The Shift Key for decryption would be 4 + 9 = 13.

When decrypting a message, the program will ask you to enter this calculated *Shift Key*.

## How to Use

### Prerequisites

You will need a C++ compiler, such as g++, installed on your system.

### 1\. Compilation

Navigate to the directory containing the caesar.cpp file and compile it using the following command:

sh
g++ caesar.cpp -o caesar


### 2\. Execution

Run the compiled program from your terminal:

sh
./caesar


### 3\. On-Screen Instructions

The program will present a menu with the following options:

  * *Encrypt a message*: Prompts you to enter text. It will then display the encrypted result and your 3-digit Public Key.
  * *Decrypt a message*: Prompts you to enter the encrypted text and the calculated Shift Key.
  * *Exit*: Terminates the program.

#### Example Workflow

1.  Run the program and select option 1 to encrypt.
2.  *Enter text to encrypt*: Hello World 123!
3.  The program outputs the encrypted text and your key. Let's assume the key is 852.
      * *Encrypted Text*: Jgnnq Yqtnf 345!
      * *Your 3-digit key (keep it safe\!)*: 852
4.  To decrypt, select option 2.
5.  Calculate your Shift Key from the Public Key 852: 8 + 2 = 10.
6.  *Enter the ciphered text*: Jgnnq Yqtnf 345!
7.  *Enter the key*: 10
8.  The program will output the original message:
      * *Decrypted Text*: Hello World 123!
