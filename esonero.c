#include <stdio.h>
#include <string.h>
#include <time.h>

//Declaration and initialization of variables
int size = 128;
char message[128] = "";
char key[128] = "";
char cryptedMessage[128] = "";
char decryptedMessage[128] = "";
void encrypt(char message[128], char key[128]);
void decrypt(char criptedMessage[128], char key[128]);
time_t time;

int main(){
	srand((unsigned) time (&time));
	printf("|| Encrypt with XOR operator || \n");
	printf("--> Insert the message that you want to encript : \n");
	fgets(message,128,stdin);
	//Input of the command
	printf("--> Write \"1\" to insert the key or \"2\" to generate it \n");
	int command = 0;
	scanf("%d",&command);
	//Switch Case
	switch(command){
		case 1:
		encryptinput(message,key);
		decrypt(cryptedMessage,key);
		break;
		case 2:
		
		break;
	}
	
}

//Enrypt function
void encryptinput(char message[], char key[]){
	while (getchar()!='\n'); // To empty the buffer stdin
	printf("--> Enter the key with which you want to encrypt the message \n");
    fgets(key,128,stdin);
	//Encrypting
	for(int i = 0;i<128;i++){
		cryptedMessage[i] = message[i] ^ key[i];
	}
	for(int i = 0;i<128;i++){
		printf("%c", cryptedMessage[i]);
	}
}
void encryptRandom(char message[], char key[]){
	
	
	//Encrypting
	for(int i = 0;i<128;i++){
		cryptedMessage[i] = message[i] ^ key[i];
	}
	for(int i = 0;i<128;i++){
		printf("%c", cryptedMessage[i]);
	}
}

//Decript function
void decrypt(char criptedMessage[], char key[]){
	for(int i = 0;i<128;i++){
		decryptedMessage[i] = cryptedMessage[i] ^ key[i];
	}
	for(int i = 0;i<128;i++){
		printf("%c", decryptedMessage[i]);
	}
}
