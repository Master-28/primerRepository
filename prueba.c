#include <stdio.h>

//Pasos a seguir:
//  1. Implementeu la funció int quantsXurros(int X);
//  2. Compileu mitjançant:
//      gcc codi_exemple_P1_facil.c -o problema1
//  3. Descarregueu el vostre fitxer d'entrada de la web i poseu-lo a la mateixa carpeta que l'executable
//  4. Executeu:
//      problema1 fitxer_entrada_1f.txt
//  5. Pengeu el fitxer_sortida.txt i aquest codi a la web.


//Feu la funció quantsXurros, que donats el nombre de xurros reservat X, retorna el nombre total de xurros mínim que s'ha de demanar per
//tal que es puguin repartir bé entre 2 i entre 5.
int quantsXurros(int X){
	int Y = 0;
	int fin = 0;
	
	while(fin == 0){
		
		if((X%2 == 0) && (X%43 == 0)){
			fin = 1;
			Y = X;
		}
		X++;
	}
	printf("%d\n",Y);
	return Y;
}

int main(int argc, char *argv[]){
	char kk;
	int T; //Tests a resoldre
	int i, X, Y;
	FILE *fin, *fout;

	if(argc != 2){
		printf("Error! Per executar has de passar per paràmetre el fitxer d'entrada que s'ha de llegir! Exemple:\n problema1 fitxer_entrada_1f.txt\n");
		return 0;
	}

	fin=fopen(argv[1], "r");
	fout=fopen("fitxer_sortida.txt", "w");
	if (fin==NULL || fout == NULL)
	{
		printf("Error! No s'ha trobat el fitxer %s.\n", argv[1]);
	}
	else
	{
		fscanf(fin, "%d", &T);
		fscanf(fin, "%c", &kk);
		for (i = 0; i<T; i++)
		{
			fscanf(fin, "%d", &X);
			Y = quantsXurros(X);
			fprintf(fout, "Test #%d: %d\n", i+1, Y);
		}
		fclose(fin);
		fclose(fout);
	}
	printf("Solució guardada al fitxer fitxer_sortida.txt!\n" );
	return 0;
}
