#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct {
	char code[50],nom[50],adresse[50],nationalite[50];
}fournisseur;

typedef struct {
	char marque[50],type[50];
	int code,annee,prix;
	fournisseur frs;
}bijou;

void ajouter_bijou (bijou *b,int T) {
	for(int i=0; i<T; i++) {
		printf("Entrez la marque du bijou %d\n",i+1);
		scanf("%s",(b+i)->marque);
		/*	printf("Entrez le code du bijou %d\n",i+1);
		scanf("%d",&(b+i)->code);
	printf("Entrez l'annee de fabrication du bijou %d\n",i+1);
		scanf("%d",&(b+i)->annee);
		printf("Entrez le type du bijou %d\n",i+1);
		scanf("%s",(b+i)->type);
		printf("Entrez le prix du bijou %d\n",i+1);
		scanf("%d",&(b+i)->prix);
		printf("Entrez le code du fournisseur du bijou %d\n",i+1);
		scanf("%s",(b+i)->frs.code); 
		printf("Entrez le nom du fournisseur du bijou %d\n",i+1);
		scanf("%s",(b+i)->frs.nom);
		printf("Entrez l'adresse du fournisseur du bijou %d\n",i+1);
		scanf("%s",(b+i)->frs.adresse);*/
		printf("Entrez la nationalite du fournisseur du bijou %d\n",i+1);
		scanf("%s",(b+i)->frs.nationalite);
	}
}
void afficher_bijou (bijou *b, int N) {
	printf("Voici les bijoux de la bijouterie :\n");
	for (int i=0; i<N; i++) {
		printf("Bijou %d :\n",i+1);
		printf("- Marque : %s\n",(b+i)->marque);
		//printf("- Code : %d\n",(b+i)->code);
		//printf("- Annee de fabrication : %d\n",(b+i)->annee);
		//printf("- Type : %s\n",(b+i)->type);
		//printf("- Prix : %d\n",(b+i)->prix);
		//printf("- Fournisseur :\n");
		printf("- Code : %s\n",(b+i)->frs.code);
		//printf("- Nom : %s\n",(b+i)->frs.nom);
		//printf("- Adresse : %s\n",(b+i)->frs.adresse);
		//printf("- Nationalite : %s\n",(b+i)->frs.nationalite);
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
void ajouter_bijou_selon(bijou *b, int T) {
	char c;
	printf("Entrez a,b,c ou d\n");
	scanf(" %c",&c);
	if (c=='a'){
		b=(bijou*)realloc(b,(T+1)*sizeof(bijou));
		T++;
	for(int i=T;i>0;i--){
		*(b+i)=*(b+i-1);	
	}
	ajouter_bijou(b,1);
	printf("Ajout reussi, voici la nouvelle liste\n");
	for (int i=0;i<T;i++) {
		printf("Bijou %d:%s\n",i+1,(b+i)->marque);
	}
	}
	if (c=='b'){
		b=(bijou*)realloc(b,(T+1)*sizeof(bijou));
			printf("Entrez la marque du bijou\n");
		scanf("%s",(b+T)->marque);
		/*	printf("Entrez le code du bijou\n");
		scanf("%d",&(b+T)->code);
	printf("Entrez l'annee de fabrication du bijou\n");
		scanf("%d",&(b+T)->annee);
		printf("Entrez le type du bijou\n");
		scanf("%s",(b+T)->type);
		printf("Entrez le prix du bijou\n");
		scanf("%d",&(b+T)->prix);
		printf("Entrez le code du fournisseur du bijou\n");
		scanf("%s",(b+T)->frs.code); 
		printf("Entrez le nom du fournisseur du bijou\n");
		scanf("%s",(b+T)->frs.nom);
		printf("Entrez l'adresse du fournisseur du bijou\n");
		scanf("%s",(b+T)->frs.adresse);*/
		printf("Entrez la nationalite du fournisseur du bijou\n");
		scanf("%s",(b+T)->frs.nationalite);
		printf("Ajout reussi, voici la nouvelle liste\n");
	for (int i=0;i<T+1;i++) {
		printf("Bijou %d:%s\n",i+1,(b+i)->marque);
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
		case 4:ajouter_bijou_selon(b,T);break;
	}
	}
	return 0;
}

