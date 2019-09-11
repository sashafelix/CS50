#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>


int main(int argc, string argv[])
{
    // Save key input to variable.
    string msg = argv[1];
    //Make sure there is 1 input after application command.
    if (argc != 2)
    {
        //If there is not an input, print usage error.
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
    // Loop through key letters.
    for (int i = 0, n = strlen(msg) ; i < n; i++)
    {
        // Make sure input is only alphabetic.
        if (isalpha(msg[i]) == 0)
        {
            //Print usage error if its not.
            printf("Usage: ./vigenere keyword\n");
            return 1;
        }
    }

    // Store key as string and get length
    string key = argv[1];
    int keyLength = strlen(key);
    
    // Get text to encode
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    // Loop through text
    for (int i = 0, j = 0, n = strlen(plaintext); i < n; i++)
    {            
        // Get key for this letter
        int letterKey = tolower(key[j % keyLength]) - 'a';
        
        // Check if uppercase
        if (isupper(plaintext[i]))
        {
            // Get modulo number and add to appropriate case
            printf("%c", 'A' + (plaintext[i] - 'A' + letterKey) % 26);
            
            // Increment j if uppercase.
            j++;
        }
        // Check if lowercase
        else if (islower(plaintext[i]))
        {
            printf("%c", 'a' + (plaintext[i] - 'a' + letterKey) % 26);
            // Increment j if lowercase.
            j++;
        }
        else
        {
            // Return unchanged, if space or other character.
            printf("%c", plaintext[i]);
        }
    }
    
    printf("\n");
    
    return 0;
}


