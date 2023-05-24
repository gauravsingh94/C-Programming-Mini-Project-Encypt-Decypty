#include <stdio.h>

void encryptFile(const char* inputFile, const char* outputFile, int key) {
    FILE* input = fopen(inputFile, "rb");
    FILE* output = fopen(outputFile, "wb");
    
    if (input == NULL || output == NULL) {
        printf("Error opening files.\n");
        return;
    }
    
    int ch;
    while ((ch = fgetc(input)) != EOF) {
        ch = ch ^ key;  // XOR operation with the encryption key
        fputc(ch, output);
    }
    
    printf("File encrypted successfully.\n");
    
    fclose(input);
    fclose(output);
}

void decryptFile(const char* inputFile, const char* outputFile, int key) {
    FILE* input = fopen(inputFile, "rb");
    FILE* output = fopen(outputFile, "wb");
    
    if (input == NULL || output == NULL) {
        printf("Error opening files.\n");
        return;
    }
    
    int ch;
    while ((ch = fgetc(input)) != EOF) {
        ch = ch ^ key;  // XOR operation with the encryption key
        fputc(ch, output);
    }
    
    printf("File decrypted successfully.\n");
    
    fclose(input);
    fclose(output);
}

int main() {
    char inputFile[100];
    char outputFile[100];
    int key;
    int choice;
    
    printf("Enter the input file name: ");
    scanf("%s", inputFile);
    
    printf("Enter the output file name: ");
    scanf("%s", outputFile);
    
    printf("Enter the encryption/decryption key: ");
    scanf("%d", &key);
    
    printf("Choose an option:\n");
    printf("1. Encrypt file\n");
    printf("2. Decrypt file\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            encryptFile(inputFile, outputFile, key);
            break;
        case 2:
            decryptFile(inputFile, outputFile, key);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
    
    return 0;
}

