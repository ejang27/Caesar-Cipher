

//File name: caesarcipher.c
//Written by: Eunsoo Jang
//Purpose: replaces each letter in a message with another letter that is a
//        fixed number of positions later in the alphabet.
//Date: March 7th, 2018

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_CH 80

void encrypt1(char message[], char codedMsg[], int n, int shift);
void encrypt2(char *message, char *codedMsg, int shift);

int main (void){
  char message1[MAX_CH+1];
  char message2[MAX_CH+1];
  char codedMsg1[MAX_CH+1];
  char codedMsg2[MAX_CH+1];
  char ch;
  int shift;
  int n =0;     //keeps track of length of message[]

  //testing out encrypt1
  printf("Enter message to be encrypted: ");
  int i = 0;
  while((ch=getchar())!='\n'){
    message1[i]=ch;
    i++;
    n++;
  }
  printf("Enter shift amount (1-25): ");
  scanf("%d", &shift);
  encrypt1(message1,codedMsg1, n, shift);
  printf("Ecrypted(encrypt1) message: %s \n", codedMsg1);

  //testing out encrypt2
  printf("Enter message to be encrypted: ");
  scanf("%c", &ch);
  int j = 0;
  while((ch=getchar())!='\n'){
    message2[j]=ch;
    j++;
  }
  printf("Enter shift amount (1-25): ");
  scanf("%d", &shift);
  encrypt2(message2,codedMsg2, shift);
  printf("Ecrypted(encrypt1) message: %s \n", codedMsg2);
  return 0;
}

void encrypt1(char message[], char codedMsg[], int n, int shift){
  for(int i =0; i<n;i++){
    if(isalpha(message[i])){
      if(islower(message[i])){
        codedMsg[i]=((message[i]-'a')+shift)%26+'a';
      }
      else if(isupper(message[i])){
        codedMsg[i]=((message[i]-'A')+shift)%26+'A';
      }
    }
    else{
      codedMsg[i]=message[i];
    }
  }
  codedMsg[n]='\0';
}


void encrypt2(char *message, char *codedMsg, int shift){
  int i=0;
  while(message[i]!='\0'){
    if(isalpha(message[i])){
      if(islower(message[i])){
        codedMsg[i]=((message[i]-'a')+shift)%26+'a';
      }
      else if(isupper(message[i])){
        codedMsg[i]=((message[i]-'A')+shift)%26+'A';
      }
    }

    else{
      codedMsg[i]=message[i];
    }
    i++;
  }
  codedMsg[i]='\0';
}
