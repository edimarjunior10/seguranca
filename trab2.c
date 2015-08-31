#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){
	
	srand(time(NULL));	
	
	FILE *input, *output;
	
	//input=fopen("/home/edimarjunior/Documentos/Gits/Seguranca/Trabalho2/arquivos/inputs/pg11.txt", "r"); 
	//output=fopen("/home/edimarjunior/Documentos/Gits/Seguranca/Trabalho2/arquivos/outputs/pg11.txt.enc", "r"); 
	
	//input=fopen("/home/edimarjunior/Documentos/Gits/Seguranca/Trabalho2/arquivos/inputs/pg74.txt", "r"); 
	//output=fopen("/home/edimarjunior/Documentos/Gits/Seguranca/Trabalho2/arquivos/outputs/pg74.txt.enc", "r"); 
	
	//input=fopen("/home/edimarjunior/Documentos/Gits/Seguranca/Trabalho2/arquivos/inputs/pg76.txt", "r");
	//output=fopen("/home/edimarjunior/Documentos/Gits/Seguranca/Trabalho2/arquivos/outputs/pg76.txt.enc", "r"); 
	 
	//input=fopen("/home/edimarjunior/Documentos/Gits/Seguranca/Trabalho2/arquivos/inputs/pg174.txt", "r"); 
	//output=fopen("/home/edimarjunior/Documentos/Gits/Seguranca/Trabalho2/arquivos/outputs/pg174.txt.enc", "r"); 
	
	//input=fopen("/home/edimarjunior/Documentos/Gits/Seguranca/Trabalho2/arquivos/inputs/pg1232.txt", "r");
	//output=fopen("/home/edimarjunior/Documentos/Gits/Seguranca/Trabalho2/arquivos/outputs/pg1232.txt.enc", "r");
	 
	//input=fopen("/home/edimarjunior/Documentos/Gits/Seguranca/Trabalho2/arquivos/inputs/pg1342.txt", "r"); 
	//output=fopen("/home/edimarjunior/Documentos/Gits/Seguranca/Trabalho2/arquivos/outputs/pg1342.txt.enc", "r");
	
	input=fopen("/home/edimarjunior/Documentos/Gits/Seguranca/Trabalho2/arquivos/inputs/pg1661.txt", "r"); 
	output=fopen("/home/edimarjunior/Documentos/Gits/Seguranca/Trabalho2/arquivos/outputs/pg1661.txt.enc", "r"); 
	
	//input=fopen("/home/edimarjunior/Documentos/Gits/Seguranca/Trabalho2/arquivos/inputs/pg27827.txt", "r"); 
	//output=fopen("/home/edimarjunior/Documentos/Gits/Seguranca/Trabalho2/arquivos/outputs/pg27827.txt.enc", "r"); 
	
	if (input==NULL){
		printf("Arquivo Input nao encontrado!\n");
		exit(0);
    }
	if (output==NULL){
		printf("Arquivo Output nao encontrado!\n");
		exit(0);
    }
    
	fseek(input, 0, SEEK_END);
	fseek(output, 0, SEEK_END);
	
	int tamIn=0, tamOut=0;
    tamIn = ftell(input);
    tamOut = ftell(output);
    
    fseek(input, 0, 0);
    fseek(output, 0, 0);
    
    //VARIAVEIS-----------------------------------------------------
    char txtIn[tamIn], txtOut[tamOut], txtAux[tamOut], keyV[tamOut]; //keyV[] = "abcd";
    int tamTxtIn=0, tamTxtOut=0, op=0, ff=256, keyC=0, keyT=0;
    int i=0, x=0, y=0, a, b, c, d, e, criaV, w, z, t, l, j, p, q, k, cnt=0, auxx=0, resulT, comp1, comp2=0;
    char vsub[ff][2];
     
    while (!feof(input)){
		fread(&txtIn[x], sizeof(char), 1, input);
		x++;			
	}
	while (!feof(output)){
		fread(&txtOut[y], sizeof(char), 1, output);
		y++;			
	}
	
	tamTxtIn = strlen(txtIn);
    tamTxtOut = strlen(txtOut);
    
   // printf("%s", txtOut);
    
    //while(op!=0){
	printf(" 1 - Cesar | 2 - Transposicao | 3 - Venegere | 4 - Substituicao\n");
	scanf("%d", &op);
		
	if(op==1){
		//--------------------------------------------CESAR
		keyC = (txtOut[i] - txtIn[i] + 256) % 256;	
		printf("keyC: %d\n", keyC);
		
		strcpy(txtAux, txtOut);
				
		for(i=0; i<tamTxtOut; i++){
			txtAux[i] = (txtOut[i] - keyC + 256) % 256;	
			//printf("keyC: %d\n", keyC);
		}
		
		printf("\n\nTxtAux:\n %s", txtAux);
		printf("\n\n\tCHAVE: %d\n", keyC);
	}
	if(op==2){
		//--------------------------------------------TRANSPOSICAO
		/*keyT = 7;
		t=0;
		for(z=0; z<keyT; z++){
			//printf("vishe");
			if(txtOut[t] != ' '){
				txtAux[t] = txtOut[t];
				t++;
			}
			w=z;
			while(w<tamTxtOut){
				w = w + keyT;
				if(w>tamTxtOut)
					continue;
				if(txtOut[w] != ' '){	
					txtAux[t] = txtOut[w];
					t++;
				}
			}
		}*/
		/*int abb;
		printf("TXT CLARO: \n\n");
		for(abb=0; abb<300; abb++)
			printf("%c", txtIn[abb]);
		printf("\n\n\n");
		
		int abc;
		printf("TXT CRIPTO: \n\n");
		for(abc=0; abc<300; abc++)
			printf("%c", txtOut[abc]);
		printf("\n\n\n");*/
		
		for(k=1; k<100; k++){
			keyT = k; 
			//printf("KeyT: %d\n", keyT);
			
			int colunas = (tamTxtOut/keyT)+1;		
			if ((tamTxtOut%keyT) != 0)
				colunas = colunas+1;	
			char txttrans[keyT][colunas];
			
			cnt=0;
			for(l=0; l<colunas; l++){	
				for(j=0; j<keyT; j++){
					if (txtIn[cnt] == '0' || txtIn[cnt] == '\0')
						txtIn[cnt] = ' ';
					txttrans[j][l] = txtIn[cnt];	
					cnt++;
				}
			}

			auxx=0;
			for(j=0; j<keyT; j++){
				for(l=0; l<colunas; l++){
					txtAux[auxx] = txttrans[j][l];
					//printf("txttrans[%d][%d]: %c\n", l, j, txttrans[l][j]);
					auxx++;
				}
			}
			for(comp1=0;comp1<1000;comp1++){
			if(txtOut[comp1]==txtAux[comp1])
				comp2++;
			}
			if(comp2==1000)
				printf("CHAVE: %d", keyT);
			else
				comp2=0;
		//printf("\n\n ------------------COMP2:   %d", comp2);
		
		}
		
		/*int aba;
		printf("MATRIZ CRIPTO: \n\n");
		for(aba=0; aba<300; aba++)
			printf("%c", txtAux[aba]);
		printf("\n");
		
		printf("%s", txtAux);*/


		//resulT = strcmp(txtAux, txtOut);
		//printf("\n\n\nRESUL: %d", resulT);
	

		/*for(l=0; l<colunas; l++){
			//printf("\n");
			for(j=0; j<keyT; j++){
				printf("%c", txttrans[j][l]);
			}
		}*/
		//printf("TxtOut: %s", txtOut);

	}
	if(op==3){
		//--------------------------------------------VEGENERE

		/*int set=0;
		for(set=0;set<ff;set++){
			keyV[set] = '\0';
		}
		tamKv = strlen(keyV);
		//printf("tamKv: %d", tamKv);
		
		z=0;
		for(w=0; w<tamTxtOut; w++){
				txtAux[w] = keyV[z];
				z++;
				if(z==tamKv)
					z=0;
		}*/	
		
		for(criaV=0; criaV<tamTxtOut; criaV++){
			keyV[criaV] = txtOut[criaV] - txtIn[criaV];
		}
		printf("\n\nTxtAuxV:\n %s", keyV);
		
		for(i=0; i<tamTxtOut; i++){
			txtAux[i] = (txtOut[i] - keyV[i] + 256) % 256;	
			//printf("keyC: %d\n", keyC);
		}
		//printf("\n\nTxtAuxV:\n %s", txtAux);
		
		
	}
	if(op==4){
		//--------------------------------------------SUBSTITUICAO

		for(e=0; e<tamTxtOut; e++){
			txtAux[e] = txtOut[e];
		}
		//printf("\n\nTxtAux:\n %s", txtAux);

		for(a=0; a<ff; a++){
			vsub[a][0]=a;
			for(b=0; b<tamTxtOut; b++){
				if(vsub[a][0] == txtIn[b]){
					vsub[a][1] = (txtOut[b] + 256) % 256;
				}
			}
			//printf("0: %d %c  1: %d %c \n", vsub[a][0], vsub[a][0], vsub[a][1], vsub[a][1]);
		}
		
		//printf("\n\nTxtDescrip:\n");
		for(c=0; c<tamTxtOut; c++){			
				for(d=0; d<ff; d++){
					if(txtOut[c] == vsub[d][1]){
						txtAux[c] = (vsub[d][0] + 256) % 256;
						printf("%c", txtAux[c]);	
					}
				}
			}
		printf("\n%s", txtAux);
		
		
	}
	//}
	
	return 0;
}


/*
	Arquivo 1 - pg11 - CESAR - Chave:5
	Arquivo 2 - pg74 - SUBSTITUIÇÃO
	Arquivo 3 - pg76 - SUBSTITUIÇÃO
	Arquivo 4 - pg174 - VEGENERE - Chave:abcd
	Arquivo 5 - pg1232 - CESAR - Chave:22
	Arquivo 6 - pg1342 - TRANSPOSIÇÃO - Chave:7
	Arquivo 7 - pg1661 - TRANSPOSIÇÃO - Chave:55
	Arquivo 8 - pg27827 - VEGENERE - Chave:123456
*/
