#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
//berrada 7ayawan
typedef struct {
	char code[50],nom[50],adresse[50],nationalite[50];
}fournisseur;

typedef struct {
	char marque[50],type[50];
	int code,annee,prix;
	fournisseur frs;
}bijou;

void ajouter_bijou (bijou *a,int N) {
	for(int i=0; i<N; i++) {
		printf("Entrez la marque du bijou %d\n",i+1);
		scanf("%s",(a+i)->marque);
		/*	printf("Entrez le code du bijou %d\n",i+1);
		scanf("%d",&(a+i)->code);
	printf("Entrez l'annee de fabrication du bijou %d\n",i+1);
		scanf("%d",&(a+i)->annee);
		printf("Entrez le type du bijou %d\n",i+1);
		scanf("%s",(a+i)->type);
		printf("Entrez le prix du bijou %d\n",i+1);
		scanf("%d",&(a+i)->prix);
		printf("Entrez le code du fournisseur du bijou %d\n",i+1);
		scanf("%s",(a+i)->frs.code); 
		printf("Entrez le nom du fournisseur du bijou %d\n",i+1);
		scanf("%s",(a+i)->frs.nom);
		printf("Entrez l'adresse du fournisseur du bijou %d\n",i+1);
		scanf("%s",(a+i)->frs.adresse);*/
		printf("Entrez la nationalite du fournisseur du bijou %d\n",i+1);
		scanf("%s",(a+i)->frs.nationalite);
	}
}
void afficher_bijou (bijou *a, int N) {
	printf("Voici les bijoux de la bijouterie :\n");
	for (int i=0; i<N; i++) {
		printf("Bijou %d :\n",i+1);
		printf("- Marque : %s\n",(a+i)->marque);
		//printf("- Code : %d\n",(a+i)->code);
		//printf("- Annee de fabrication : %d\n",(a+i)->annee);
		//printf("- Type : %s\n",(a+i)->type);
		//printf("- Prix : %d\n",(a+i)->prix);
		//printf("- Fournisseur :\n");
		printf("- Code : %s\n",(a+i)->frs.code);
		//printf("- Nom : %s\n",(a+i)->frs.nom);
		//printf("- Adresse : %s\n",(a+i)->frs.adresse);
		//printf("- Nationalite : %s\n",(a+i)->frs.nationalite);
	}
}
void afficher_bijoux_ayant(bijou *b, int T) {
	char c;int j=0,k=0,y=0,d;
	printf("Entrer a,b ou c\n");
	scanf(" %c",&c);
    char *code,*natio;
    if (c=='a'){
	code=(char*)malloc(100*sizeof(char));
	printf("Entrez le code du fournisseur\n");
	scanf("%s",code);
	
	for (int i=0; i<T; i++) {
	     if(strcmp((b+i)->frs.code,code)==0) {
			printf("Le bijou%d : %s\n",j+1,(b+i)->marque);
	    	j++;
		}
	}
	if (j==0) {
		printf("Code introuvable");
	}
	}
	if(c=='b') {
	printf("Entrez code\n");
	scanf("%d",&d);
	for (int i=0; i<T; i++) {
		if((b+i)->code==d) {
			printf("Le bijou%d : %s\n",k+1,(b+i)->marque);
	    	k++;
		}
	}
	if (k==0) {
		printf("Code introuvable\n");
	}
}
	if (c=='c') {
		natio=(char*)malloc(100*sizeof(char));
	printf("Entrez la nationalite du fournisseur\n");
	scanf("%s",natio);
	
	for (int i=0; i<T; i++) {
	     if(strcmp((b+i)->frs.nationalite,natio)==0) {
			printf("Le bijou%d : %s\n",y+1,(b+i)->marque);
	    	y++;
		}
	}
	if (y==0) {
		printf("Natio introuvable");
	}
	}

}

int main () {
	int T,choix;
	bijou *b;
	do {
	printf("Entrer le nombre des bijoux (maximum 100)\t");
	scanf("%d",&T);
	}while(T>100 || T<0);
	b=(bijou*)malloc(T*sizeof(bijou));
	ajouter_bijou(b,T);
	if(b) {
	printf("1/Afficher le stock\n2/Afficher le bijou du fournisseur ayant le plus des bijoux\n3-Afficher les bijoux (a-un fournisseur donnee\nb-ayant un code\nc-ayant une nationnalite donnee\n)\n");
	scanf("%d",&choix);
	switch (choix) {
		case 1:afficher_bijou(b,T);break;
		case 3:afficher_bijoux_ayant(b,T);break;
	}
	}
	return 0;
}

