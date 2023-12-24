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
		/*printf("Entrez le prix du bijou %d\n",i+1);
		scanf("%d",&(b+i)->prix);
		printf("Entrez le code du fournisseur du bijou %d\n",i+1);
		scanf("%s",(b+i)->frs.code); */
		printf("Entrez le nom du fournisseur du bijou %d\n",i+1);
		scanf("%s",(b+i)->frs.nom);
	/*  printf("Entrez l'adresse du fournisseur du bijou %d\n",i+1);
		scanf("%s",(b+i)->frs.adresse);
		printf("Entrez la nationalite du fournisseur du bijou %d\n",i+1);
		scanf("%s",(b+i)->frs.nationalite);*/
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
		//printf("- Code : %s\n",(b+i)->frs.code);
		//printf("- Nom : %s\n",(b+i)->frs.nom);
		//printf("- Adresse : %s\n",(b+i)->frs.adresse);
		//printf("- Nationalite : %s\n",(b+i)->frs.nationalite);
	}
}
void afficher_bijou_fournisseur(bijou *b,int T){
int r=0,c,*a,max;
	a=(int*)malloc(T*sizeof(int));	
	for(int i=0; i<T; i++) {
		for(int j=0;j<T;j++){
		c=strcmp((b+i)->type,(b+j)->type);
		if(c==0){
			r++;
		}	
		}*(a+i)=r;
		r=0;
		}
max=*a;
for(int i=1; i<T; i++){
		if(*(a+i)>max){
		  max=*(a+i);
				}
	}	
	int p=0;	
for(int i=0; i<T; i++){
	if(*(a+i)==max && max!=1){
		printf("- Marque : %s\n",(b+i)->marque);
		//printf("- Code : %d\n",(b+i)->code);
		//printf("- Annee de fabrication : %d\n",(b+i)->annee);
		//printf("- Type : %s\n",(b+i)->type);
		//printf("- Prix : %d\n",(b+i)->prix);
		//printf("- Fournisseur :\n");
		//printf("- Code : %s\n",(b+i)->frs.code);
		//printf("- Nom : %s\n",(b+i)->frs.nom);
		//printf("- Adresse : %s\n",(b+i)->frs.adresse);
		//printf("- Nationalite : %s\n",(b+i)->frs.nationalite);
		p++;
	}
	}
	 if(p==0){
	 printf("Il y a la meme quantite!");
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
	printf("Entrez a,b,c,d ou x\n");
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
	if (c=='c'){
	        int p;
			b=(bijou*)realloc(b,(T+1)*sizeof(bijou));
			do{
		printf("Entrez une position ou vous voulez ajouter");
		scanf("%d",&p);
		}while(p<0||p>T);
		for(int i=T;i>p;i--){
		*(b+i)=*(b+i-1);	
	}
		printf("Entrez la marque du bijou\n");
		scanf("%s",(b+p)->marque);
		/*	printf("Entrez le code du bijou\n");
		scanf("%d",&(b+p)->code);
	printf("Entrez l'annee de fabrication du bijou\n");
		scanf("%d",&(b+p)->annee);
		printf("Entrez le type du bijou\n");
		scanf("%s",(b+p)->type);
		printf("Entrez le prix du bijou\n");
		scanf("%d",&(b+p)->prix);
		printf("Entrez le code du fournisseur du bijou\n");
		scanf("%s",(b+p)->frs.code); 
		printf("Entrez le nom du fournisseur du bijou\n");
		scanf("%s",(b+p)->frs.nom);
		printf("Entrez l'adresse du fournisseur du bijou\n");
		scanf("%s",(b+p)->frs.adresse);*/
		printf("Entrez la nationalite du fournisseur du bijou\n");
		scanf("%s",(b+p)->frs.nationalite);
		printf("Ajout reussi, voici la nouvelle liste\n");
	for (int i=0;i<T+1;i++) {
		printf("Bijou %d:%s\n",i+1,(b+i)->marque);
	}
	}
	if (c=='d'){
		char *l;
		b=(bijou*)realloc(b,(T+1)*sizeof(bijou));
		l=(char*)malloc(15*sizeof(char));
		printf("Entrez une marque\n");
		scanf("%s",l);
		int j=0;
		for (int i=0; i<T; i++){
			if(*l==*(b+i)->marque){
				j++;
			}
			if(j==3){
				for (int k=T;k>i;k--){
					*(b+k)=*(b+k-1);
				}
				
		/*	printf("Entrez le code du bijou\n");
		scanf("%d",&(b+i)->code);
	printf("Entrez l'annee de fabrication du bijou\n");
		scanf("%d",&(b+i)->annee);
		printf("Entrez le type du bijou\n");
		scanf("%s",(b+i)->type);
		printf("Entrez le prix du bijou\n");
		scanf("%d",&(b+i)->prix);
		printf("Entrez le code du fournisseur du bijou\n");
		scanf("%s",(b+i)->frs.code); 
		printf("Entrez le nom du fournisseur du bijou\n");
		scanf("%s",(b+i)->frs.nom);
		printf("Entrez l'adresse du fournisseur du bijou\n");
		scanf("%s",(b+i)->frs.adresse);*/
		printf("Entrez la nationalite du fournisseur du bijou\n");
		scanf("%s",(b+i)->frs.nationalite);
				break;
			}
		}
		printf("Ajout reussi!");
	}
	if(c=='x'){
		exit(0);
	}
	
}
void supprimer_bijou_selon(bijou *b ,int T){
		char p;		
	printf("Entrez a,b,c,d,e,fou x\n");
	scanf(" %c",&p);
	if(p=='a'){
	for(int i=0;i<T-1;i++){
	*(b+i)=*(b+i+1);	
	}
	b=(bijou*)realloc(b,(T-1)*sizeof(bijou));
	afficher_bijou(b,T-1);
}
        if(p=='b'){
		b=(bijou*)realloc(b,(T-1)*sizeof(bijou));
		afficher_bijou(b,T-1);
}
        if(p=='c'){
	int r;
	do{
	printf("Entrez la position :");
	scanf("%d",&r);
	}while(r>T||r<0);
			for(int j=r;j<T;j++){	
		*(b+j)=*(b+j+1);
		}			
	b=(bijou*)realloc(b,(T-1)*sizeof(bijou));
	afficher_bijou(b,T-1);
}
 	 	if(p=='d'){
 	 		char *l;
 	 		int k=0,e=-1;
        l=(char*)malloc(T*sizeof(char));
		do{
		printf("Entrez une marque :");
	    scanf("%s",l);
	   for(int j=0;j<T;j++){
	   if(*l==*((b+j)->marque)){
	   	k++;
	   }
	   } 
	   }while(k==0);
	for(int j=0;j<T;j++){
		while(*l==*((b+j)->marque)){
            for(int i=j;i<T;i++){
				*(b+i)=*(b+i+1);
		}
		}
	}
	b=(bijou*)realloc(b,(T-k)*sizeof(bijou));
	afficher_bijou(b,T-k);
		  }
        if(p=='e'){
	int e,r=0;
	do {
	printf("Entrez un prix :");
	scanf("%d",&e);
		for(int j=0;j<T;j++){
if(e==(b+j)->prix){
	r++;
}
}
}while(r==0);
	for(int j=0;j<T;j++){
		while(e==(b+j)->prix){
            for(int i=j;i<T;i++){
				*(b+i)=*(b+i+1);
		}
		}
	}
	b=(bijou*)realloc(b,(T-r)*sizeof(bijou));
	afficher_bijou(b,T-r);
}
        if(p=='f'){
         char l;
    int o=0,c=0,p=0,g=0;
    do {
	printf("Entrez la lettre :\n");
    scanf(" %c",&l);
    for (int i=0; i<T; i++) {
        for (int j=0;(b+i)->frs.nom[j]!='\0';j++) {
            if((b+i)->frs.nom[j]==l) {
                o++;
                if(o>=2){
                	g++;
                	break;
				}
            }
          }o=0;
		}
		}while(g==0);
for(int i=0;i<T;i++){
	for (int j=0;(b+i)->frs.nom[j]!='\0';j++) {
         while((b+i)->frs.nom[j]==l){
         	p++;
         	if(p>=2){
         for(int t=i;t<T;t++){
            *(b+t)=*(b+t+1);
            }
			}
        }
	 }p=0;
}
  afficher_bijou(b,T-g);      	 	
}
    		     if(p=='x'){
    		     	exit(0);
}
}
int main () {
	int T,choix;
	bijou *b;
	do {
	printf("Entrer le nombre des bijoux (maximum 100)  ");
	scanf("%d",&T);
	}while(T>100 || T<0);
	b=(bijou*)malloc(T*sizeof(bijou));
	ajouter_bijou(b,T);
	if(b) {
	printf("1/Afficher le stock\n2/Afficher le bijou du fournisseur ayant le plus des bijoux\n3-Afficher les bijoux :\n\ta-D'un fournisseur donnee\n\tb-Ayant un code donnee\n\tc-Des fournisseurs ayant une nationalite donnee\n4-Ajouter les bijoux :\n\ta-Au debut du tableau\n\tb-A la fin du tableau\n\tc-En une position donnee\n\td-Apres le 3eme bijou de sa meme marque\n\tx-Quitter\n\n5-Supprimer les bijoux :\n\ta-Au debut\n\tb-A la fin du tableau\n\tc-En une position donnee\n\td-Par marque\n\te-Par prix\n\tf-dont le nom de fournisseur contient 2 fois une lettre donnee\n\tx-Quitter\n6-Quitter le programme\n");
	scanf("%d",&choix);
	switch (choix) {
		case 1:afficher_bijou(b,T);break;
		case 2:afficher_bijou_fournisseur(b,T);break;
		case 3:afficher_bijoux_ayant(b,T);break;
		case 4:ajouter_bijou_selon(b,T);break;
		case 5:supprimer_bijou_selon(b,T);break;
		case 6:exit(0);break;
	}
	}
	return 0;
}

