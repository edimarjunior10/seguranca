#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//#include <vector>

//using namespace std;


int main(){

		
	srand(time(NULL));	
	
	/*FILE *input;
	input=fopen("in.txt", "r"); 
	if (input==NULL){
		printf("Arquivo nao encontrado!\n");
		exit(0);
    }
	fseek(input, 0, SEEK_END);
    
    //int tamArquivo=0, 
    int tam=0, x=0;
    tam = ftell(input);
    printf("tamArquivo: %d\n", tam);	*/	
	
	int opcao=0, key=5, tamstring, tam=100;
	char txt[tam];	
	
	printf("Digite texto a criptografar: ");
	scanf("%s", txt);
	
	/*fseek(input, 0, 0);
		
	//LER DO ARQUIVO
	while (!feof(input)){
		fread(&txt[x], sizeof(char), 1, input);
		x++;			
	}*/
	
	tamstring = strlen(txt);
		
	//printf("tamStringTXT: %d\n", tamstring);
	
	printf("\nTexto Original: %s", txt); 
	
	printf("\n\nEscolha a opção:\n1 - Cesar\n2 - Transposição\n3 - Venegere\n4 - Substituição\n");
	scanf("%d", &opcao);
	printf("Opcao selecionada: %d\n", opcao);
	
	if(opcao == 1){
		//cifra de cesar
		int i;
			
		for(i=0; i<=tamstring; i++){
			txt[i] = (txt[i] + key + 256) % 256;	
		}
		printf("\nTexto Cripto: %s", txt);
		for(i=0; i<=tamstring; i++){
				txt[i] = (txt[i] - key + 256) % 256;	
		}
		printf("\nTexto Descripto: %s", txt);
		
	}else if(opcao == 2){
		//cifra transposição
		
		int l, c, n, o, cnt=0;
		
		int linhas = (tamstring/key);
		if ((tamstring%key) != 0)
			linhas = linhas+1;
		//printf("linhas %d\n\n", linhas);
		char txttrans[linhas][key];
		
		n=0, o=0;
		//for(l=0; l<linhas; l++){
		for(c=0; c<key; c++){
				//printf("o: %d\n", o);
				o++;
				n=0;
				
			for(l=0; l<linhas; l++){
			//for(c=0; c<key; c++){
				if (txt[cnt] == '0' || txt[cnt] == '\0')
					txt[cnt] = ' ';
				
				txttrans[l][c] = txt[cnt];
				//printf("%d\n", cnt);	
				cnt++;
				//printf(" n: %d\n", n);
				n++;
			}
		}
		printf("\nMatriz Cripto:");
		for(l=0; l<linhas; l++){
			printf("\n");
			for(c=0; c<key; c++){
				printf("%c", txttrans[l][c]);
			}
		}
		printf("\nTexto Cripto:");
		for(l=0; l<linhas; l++){
			for(c=0; c<key; c++){
				printf("%c", txttrans[l][c]);
			}
		}
		
		printf("\nTexto Descripto:");
		for(c=0; c<key; c++){
			//printf("\n");
			for(l=0; l<linhas; l++){
				printf("%c", txttrans[l][c]);
			}
		}
	
	
	}else if(opcao == 3){
		//cifra vegenere
		
		char keys[] = "BOLO";
		int w, z, tamk=0, x;

		printf("\nChave: %s", keys);
			
		tamstring = strlen(txt);
		tamk = strlen(keys);
		char txtaux[tamstring], txtveg[tamstring];
		
		z=0;
		for(w=0; w<tamstring; w++){
				txtaux[w] = keys[z];
				z++;
				if(z==tamk)
					z=0;
		}
		printf("\nTexto Chave: %s", txtaux);
		
		for(x=0; x<tamstring; x++){			
				txtveg[x] = (txt[x] + txtaux[x] + 256) % 256;					
		}
		printf("\nTexto Cripto: %s", txtveg);
		
		for(x=0; x<tamstring; x++){			
				txtveg[x] = (txtveg[x] - txtaux[x] + 256) % 256;					
		}
		printf("\nTexto Descripto: %s", txtveg);
		
		//printf("\n\nChave: %c", keys[0]);
	
		
	}else if(opcao == 4){
		//cifra substituicao
		int k, v, u, h, g, nrrand, tamalfa=128; 
		int vaux[tamalfa], vsub[tamalfa][2];
		int nada=0, eq1, eq2;
		
		/*int t=127;
		for(k=0; k<tamalfa; k++){
			vaux[k] = k;
			vsub[k][0] = k;
			vsub[k][1] = t;
			t--;
			//printf("k: %d ", k);
			//printf("vsub1[%d]: %d ", k, vsub[k][0]);
			//printf("vsub2[%d]: %d\n", k, vsub[k][1]);
		}*/
				
		
		
		for(k=0; k<tamalfa; k++){
			vaux[k] = k;
			vsub[k][0] = k;
		} 
		for(h=0; h<tamalfa; h++){
			g=0;
			while(g==0){
				nrrand = (rand()+128) % 128;
				if (vaux[nrrand] != 500){
				//if (vaux[nrrand] != NULL){
				//if (vaux[nrrand] != '\0'){
					vsub[h][1] = vaux[nrrand];
					vaux[nrrand] = 500;
					//vaux[nrrand] = NULL;
					//vaux[nrrand] = '\0';
					g++;
				}
			}
		}	
		
		
		
		for(nada=0; nada<tamalfa; nada++){
			printf("cont: %d ", nada);
			printf("vsub1[%d]: %d ", nada, vsub[nada][0]);
			printf("vsub2[%d]: %d\n", nada, vsub[nada][1]);
		}
		
		int count=0;
		for(eq1=0; eq1<tamalfa; eq1++){
			for(eq2=0; eq2<tamalfa; eq2++){
				if(vsub[eq1][1] == vsub[eq2][1]){
					count++;
					if (count>1){
						printf("\nREPETIDO: %d %d", vsub[eq1][1], vsub[eq2][1]);
					}
				}	
			}
			count=0;
		}
		
		printf("\nTexto Criptografado:\n");
		
		for(v=0; v<tamstring; v++){			
			for(u=0; u<tamalfa; u++){
				if(txt[v] == vsub[u][0]){
					txt[v] = (vsub[u][1] + 128) % 128;	
					printf("%c", txt[v]);
				}
			}
		}
		printf("\n%s", txt);
		
		printf("\n\n");
		
		printf("Texto Descriptografado:\n");
		for(v=0; v<tamstring; v++){			
			for(u=0; u<tamalfa; u++){
				if(txt[v] == vsub[u][1]){
					txt[v] = (vsub[u][0] + 128) % 128;
					printf("%c", txt[v]);	
				}
			}
		}
		printf("\n%s", txt);	
	}
				
	return 0;
}
