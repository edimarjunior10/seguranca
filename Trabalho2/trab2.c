#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	
	int opcao=0, key=5, tam=100, tamstring;
	char txt[tam];
			
	printf("Digite texto a criptografar: ");
	scanf("%s", txt);
		
	printf("\nTexto Original: %s", txt); 

	tamstring = strlen(txt);		
			
	
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
		int k, v, u, tamalfa=128, t=127;
		int vaux[tamalfa], vsub[tamalfa][2];
		
		//t=127;
		for(k=0; k<tamalfa; k++){
			vaux[k] = k;
			vsub[k][1] = k;
			vsub[k][2] = t;
			t--;
			//printf("k: %d ", k);
			//printf("v[k]: %d ", vsub[k][1]);
			//printf("t[k]: %d\n", vsub[k][2]);
		}
				
		/*printf("Original\n");
		for(v=0; v<tamstring; v++){
			printf("%d ", txt[v]);
		}
		printf("\n\n");
		for(v=0; v<tamstring; v++){			
			for(u=0; u<tamalfa; u++){
				if(txt[v] == vsub[u][1]){
					printf("v: %d ", v);
					printf("u: %d\n", u);
					printf("txt: %c ", txt[v]);
					printf("vsub: %c\n", vsub[u][1]);
					printf("vsub: %c\n\n\n", vsub[u][2]);
					txt[v] = (vsub[u][2] + 128) % 128;	
				}
			}
		}*/
		
		for(v=0; v<tamstring; v++){			
			for(u=0; u<tamalfa; u++){
				if(txt[v] == vsub[u][1]){
					txt[v] = (vsub[u][2] + 128) % 128;	
				}
			}
		}
		
		printf("Texto Criptografado:\n");
		for(v=0; v<tamstring; v++){
			printf("%c", txt[v]);
		}
		printf("\n\n");
		
		for(v=0; v<tamstring; v++){			
			for(u=0; u<tamalfa; u++){
				if(txt[v] == vsub[u][2]){
					txt[v] = (vsub[u][1] + 128) % 128;	
				}
			}
		}
		
		printf("Texto Descriptografado:\n");
		for(v=0; v<tamstring; v++){
			printf("%c", txt[v]);
		}
		printf("\n\n");
			
	}
				
	return 0;
}
