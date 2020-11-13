#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

//Riccardo Fei cod.330463
//Declaration and initialization of variables
int size = 128;
char message[128] = "";
char key[128] = "";
char cryptedMessage[128] = "";
char decryptedMessage[128] = "";
void encryptinput(char message[128], char key[128]);
void encryptRandom(char message[128], char key[128]);
void decrypt(char criptedMessage[128], char key[128]);
static const char alphanum[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

int main(){
	printf("|| Encoding with XOR operator || \n");
	printf("--> Insert the message that you want to encrypt : \n");
	fgets(message,128,stdin);
	//Input of the command
	printf("--> Write \"1\" to insert the key or \"2\" to generate it :\n");
	int command = 0;
	scanf("%d",&command);
	//Switch Case
	switch(command){
		case 1:
		encryptinput(message,key);
		decrypt(cryptedMessage,key);
		break;
		case 2:
		encryptRandom(message,key);
		decrypt(cryptedMessage,key);
		break;
	}
	
}

//Enrypt function
void encryptinput(char message[], char key[]){
	while (getchar()!='\n'); // To empty the buffer stdin
	printf("--> Enter the key with which you want to encrypt the message: \n");
    fgets(key,128,stdin);
	//Encrypting
	for(int i = 0;i<128;i++){
		cryptedMessage[i] = message[i] ^ key[i];
	}
	printf("--> Crypted string : \n");
	for(int i = 0;i<128;i++){
		printf("%c", cryptedMessage[i]);
	}
}
void encryptRandom(char message[], char key[]){
	srand(time(NULL));
	//length of message
	int len = 0;
	while (message[len] != '\0'){
	len++;
	}
	for(int i = 0; i < len ; i++){
		key[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
	}
	printf("--> The random key is:");
	for(int i = 0; i < len ; i++){
		printf("%c", key[i]);
	}
	printf("\n");
	//Encrypting
	for(int i = 0;i<128;i++){
		cryptedMessage[i] = message[i] ^ key[i];
	}
	printf("--> Crypted string : \n");
	for(int i = 0;i<128;i++){
		printf("%c", cryptedMessage[i]);
	}
}

//Decript function
void decrypt(char criptedMessage[], char key[]){
	for(int i = 0;i<128;i++){
		decryptedMessage[i] = cryptedMessage[i] ^ key[i];
	}
	printf("\n--> Decrypted string : \n");
	for(int i = 0;i<128;i++){
		printf("%c", decryptedMessage[i]);
	}
	
}
