// C++ code to implement Vigenere Cipher
#include <iostream>

using namespace std;

// This function generates the key in
// a cyclic manner until it's length isi'nt
// equal to the length of original text
string generateKey(string text, string key)
{
    int x = text.size();

	int i = 0;
    while (true)
    {
        if (x == i)
            i = 0;
        if (key.size() == text.size())
            break;
        key.push_back(key[i]);
		i++;
    }
    return key;
}

// This function returns the encrypted text
// generated with the help of the key
string encryption(string plain_text, string key)
{
    string cipher_text;

    for (int i = 0; i < plain_text.size(); i++)
    {
        // converting in range 0-25
        char x = (plain_text[i] + key[i] + 26) %26;
        // convert into alphabets(ASCII)
        x += 'a';
        cipher_text.push_back(x);
    }
    return cipher_text;
}

// This function decrypts the encrypted text
// and returns the original text
string decryption(string cipher_text, string key)
{
    string plain_text;

    for (int i = 0 ; i < cipher_text.size(); i++)
    {
        // converting in range 0-25
        char x = (cipher_text[i] - key[i] + 26) %26;
        // convert into alphabets(ASCII)
        x += 'a';
        plain_text.push_back(x);
    }
    return plain_text;
}
