//
//  main.c
//  CbcVigenere
//
//  Created by Steven Vargas on 4/05/15.
//  Copyright (c) 2015 Steven Vargas. All rights reserved.
//

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>

enum flag{encrypted = 1, decrypted = 0};

void encrytion ( char* to_encrypt,char*key);

void decyption (char*to_encrypt,char*key);

void vigenere(char* to_encrypt, char* key, enum flag f ){
    
    int i, k, s;
    k = strlen(key);
    s = strlen(to_encrypt);
    char* q;
    
    q=strdup(to_encrypt);
    
    for (i = 0; i < s; i++)
    {
        if (!isupper(q[i])) continue;
        q[i]= 'A' + ( f
                     ? q[i] - 'A' + key[i % k] - 'A'
                     : q[i] - key[i % k] + 26) % 26;
    }
    
    if(f==1)
    {printf(" The Document was encrypted %s\n", q); }
    else
    {  printf(" Decrypted %s\n", q); }
    
};

void decyption (char*to_encrypt,char*key){
    
    vigenere(to_encrypt,key,decrypted);
    
};

void encrytion ( char* to_encrypt,char*key){
    
    vigenere(to_encrypt,key,encrypted);
    
    
};

void Padded ( char* to_encryted, int i, int k ){
    char rand[20];
    int j=0;
    int rnum;
    char rchar;
    srand(time(NULL));
    
    while(i%k != 0)
    {
        rnum = (random() % 26);
        rchar = (char) rnum+0x41;
        
        rand[j]=rchar;
        j++;
        i++;
    }
    rand[j]='\0';
    
    strcat( to_encryted, rand );
    
    
    printf(" The Documnet was padded. \n");
    
    
};

int main(){
    
    int c, m, k;
    char *n, *e;
    
    
    char to_encryted[20] =  "SIX" ;
    char key[20] = "DR" ;
    char temp[20];
    
    k = strlen(to_encryted);
    c = strlen(key);
    m = k % c;
    
    if (m !=0)
    {
        Padded(to_encryted,k,c);
        
        printf(" padded output: %s\n", to_encryted);
        
    }
    
    encrytion(to_encryted,key);
    
    
    return 0;
    
};