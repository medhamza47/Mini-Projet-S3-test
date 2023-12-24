#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct {
	char nom[50],cin[50],natio[50];
	int age;
}auteur;
typedef struct {
	char titre[50],categorie[50];
	int cote,annee;
	auteur aut;
}livre;
void ajouter (livre *a,int N) {
	int c,l;
	for(int i=0; i<N; i++) {
		printf("Entrez le titre du livre %d\n",i+1);
		scanf("%s",(a+i)->titre);
    /*  poo:printf("Entrez la categorie du livre %d\n",i+1);
		scanf("%s",(a+i)->categorie);
	for(int j=0;j<strlen(((a+i)->categorie));j++){
		l=isalpha((a+i)->categorie[j]);
		}
			if(l==0){
			printf("La categorie ne doit contenir que des lettres!\n");
			goto poo;
		}
	ici : printf("Entrez le cote et l'annee du livre %d\n",i+1);
		scanf("%d %d",&(a+i)->cote,&(a+i)->annee);
		if((a+i)->annee>2023 || (a+i)->annee <0) {
			printf("L'annee est incorrecte !\n");
			goto ici;
		}
	foo:printf("Entrez le nom et le prenom de l'auteur du livre %d\n",i+1);
		scanf("%s",(a+i)->aut.nom);
	for(int j=0;j<strlen(((a+i)->aut.nom));j++){
		c=isalpha((a+i)->aut.nom[j]);
		}
			if(c==0){
			printf("Le nom et le prenom de l'auteur ne doivent contenir que des lettres!\n");
			goto foo;
		}
		printf("Entrez le CIN de l'auteur du livre %d\n",i+1);
		scanf("%s",(a+i)->aut.cin);
		here : printf("Entrez l'age de l'auteur du livre %d\n",i+1);
		scanf("%d",&(a+i)->aut.age);
		if ((a+i)->aut.age>120 ||(a+i)->aut.age <1 ) {
			printf("L'age est incorrecte \n");
			goto here;
		}*/
	}
}
void afficher (livre *a, int N) {
	int k;
	printf("Voici les livres de la bibliotheque :\n");
	for (int i=0; i<N; i++) {
		printf("Livre %d : %s\n",i+1,(a+i)->titre);
	}
} 	
void cat(livre *a,int N) {
	int r=0,c,*u,max,k=0;
	char *t;
	t=(char*)malloc(50*sizeof(char));
	u=(int*)malloc(N*sizeof(int));
    for(int i=0; i<N; i++) {
		for(int j=0;j<N;j++){
			c=strcmp((a+i)->categorie,(a+j)->categorie);
			if(c==0){
				r++;
			}
		} *(u+i)=r; // a b b b a
		r=0;
	}
	int p=0,o=0;
	max=*u;
	for(int i=1; i<N; i++) {
	 	o++;
			if(*(u+i)>max){
				max=*(u+i);
				p=o;
				}
	}
	t=(a+p)->categorie;
	printf("La categorie dominante est :%s\n",t);
	printf("Les livres de cette categorie sont :\n");
	for (int i=0; i<N; i++) {
		c=strcmp((a+i)->categorie,t);
		if(c==0) {
			printf("%d-%s\n",k+1,(a+i)->titre);
	    	k++;
		}
	}
}
void affich_aut(livre *a,int N) {
	char *c,k=0;
	int d;
	c=(char*)malloc(50*sizeof(char));
	hona :printf("Entrez le nom de l'auteur\n");
	scanf("%s",c);
	for (int i=0; i<N; i++) {
		d=strcmp((a+i)->aut.nom,c);
		if(d==0) {
			printf("%d-%s\n",k+1,(a+i)->titre);
	    	k++;
		}
	}
	if (k==0) {
		printf("L'auteur n'existe pas!\n");
		goto hona;
	}
}
void affich_cote(livre *a,int N) {
	int k=0,z;
	hona1 :printf("Entrez le cote\n");
	scanf("%d",&z);
	for (int i=0; i<N; i++) {
		if((a+i)->cote==z) {
			printf("%d-%s\n",k+1,(a+i)->titre);
	    	k++;
		}
	}
	if (k==0) {
		printf("Le cote n'existe pas!\n");
		goto hona1;
	}
}
void affich_cat(livre *a,int N) {
	char *q;
	int d,k=0;
	q=(char*)malloc(50*sizeof(char));
	hona :printf("Entrez la categorie\n");
	scanf("%s",q);
	for (int i=0; i<N; i++) {
		d=strcmp((a+i)->aut.nom,q);
		if(d==0) {
			printf("%d-%s\n",k+1,(a+i)->titre);
	    	k++;
		}
	}
	if (k==0) {
		printf("La categorie n'existe pas!\n");
		goto hona;
	}
}
void ajout_debut_liv(livre *a,int N){
	a=(livre*)realloc(a,(N+1)*sizeof(livre));
	for(int i=N;i>0;i--){
		*(a+i)=*(a+i-1);	
	}
		printf("Entrez le titre du livre \n");
		scanf("%s",(a+0)->titre);
		printf("Entrez la categorie du livre \n");
		scanf("%s",(a+0)->categorie);
		ici : printf("Entrez le cote et l'annee du livre \n");
		scanf("%d %d",&(a+0)->cote,&(a+0)->annee);
		if((a+0)->annee>2023 || (a+0)->annee <0) {
			printf("L'annee est incorrecte !\n");
			goto ici;
		}
		printf("Entrez le nom et le prenom de l'auteur du livre \n");
		scanf("%s",(a+0)->aut.nom);
		printf("Entrez le CIN de l'auteur du livre \n");
		scanf("%s",(a+0)->aut.cin);
		here : printf("Entrez l'age de l'auteur du livre \n");
		scanf("%d",&(a+0)->aut.age);
		if ((a+0)->aut.age>120 ||(a+0)->aut.age <1 ) {
			printf("L'age est incorrecte \n");
			goto here;
		}
	}	
void ajout_fin_liv(livre *a,int N){
	a=(livre*)realloc(a,(N+1)*sizeof(livre));
		printf("Entrez le titre du livre \n");
		scanf("%s",(a+N)->titre);
		printf("Entrez la categorie du livre \n");
		scanf("%s",(a+N)->categorie);
		ici : printf("Entrez le cote et l'annee du livre \n");
		scanf("%d %d",&(a+N)->cote,&(a+N)->annee);
		if((a+N)->annee>2023 || (a+N)->annee <0) {
			printf("L'annee est incorrecte !\n");
			goto ici;
		}
		printf("Entrez le nom et le prenom de l'auteur du livre \n");
		scanf("%s",(a+N)->aut.nom);
		printf("Entrez le CIN de l'auteur du livre \n");
		scanf("%s",(a+N)->aut.cin);
		here : printf("Entrez l'age de l'auteur du livre \n");
		scanf("%d",&(a+N)->aut.age);
		if ((a+N)->aut.age>120 ||(a+N)->aut.age <1 ) {
			printf("L'age est incorrecte \n");
			goto here;
		}
	}
void ajout_pos_liv(livre *a,int N){
	a=(livre*)realloc(a,(N+1)*sizeof(livre));
		int e;
		printf("Entrer la position .");
		scanf("%d",&e);
		for(int i=N;i>e;i--){
		*(a+i)=*(a+i-1);	
	}
	    printf("Entrez le titre du livre \n");
		scanf("%s",(a+e)->titre);
		printf("Entrez la categorie du livre \n");
		scanf("%s",(a+e)->categorie);
		ici : printf("Entrez le cote et l'annee du livre \n");
		scanf("%d %d",&(a+e)->cote,&(a+e)->annee);
		if((a+e)->annee>2023 || (a+e)->annee <0) {
			printf("L'annee est incorrecte !\n");
			goto ici;
		}
		printf("Entrez le nom et le prenom de l'auteur du livre \n");
		scanf("%s",(a+e)->aut.nom);
		printf("Entrez le CIN de l'auteur du livre \n");
		scanf("%s",(a+e)->aut.cin);
		here : printf("Entrez l'age de l'auteur du livre \n");
		scanf("%d",&(a+e)->aut.age);
		if ((a+e)->aut.age>120 ||(a+e)->aut.age <1 ) {
			printf("L'age est incorrecte \n");
			goto here;
		}
	
}
void ajout_cote_liv(livre *a,int N){
	a=(livre*)realloc(a,(N+1)*sizeof(livre));
		int j,t,e;
		printf("Entrer le cote");
		scanf("%d",&e);
		for(j=0;j<N;j++){
			if(e==(a+j)->cote){
				break;
			}
		}
		for(int i=N;i>=j;i--){
		*(a+i)=*(a+i-1);	
	}
	    	printf("Entrez le titre du livre \n");
		scanf("%s",(a+j)->titre);
		printf("Entrez la categorie du livre \n");
		scanf("%s",(a+j)->categorie);
		ici : printf("Entrez le cote et l'annee du livre \n");
		scanf("%d %d",&(a+j)->cote,&(a+j)->annee);
		if((a+j)->annee>2023 || (a+j)->annee <0) {
			printf("L'annee est incorrecte !\n");
			goto ici;
		}
		printf("Entrez le nom et le prenom de l'auteur du livre \n");
		scanf("%s",(a+j)->aut.nom);
		printf("Entrez le CIN de l'auteur du livre \n");
		scanf("%s",(a+j)->aut.cin);
		here : printf("Entrez l'age de l'auteur du livre \n");
		scanf("%d",&(a+j)->aut.age);
		if ((a+j)->aut.age>120 ||(a+j)->aut.age <1 ) {
			printf("L'age est incorrecte \n");
			goto here;
		}
	
}
void supp_debut_liv(livre *a , int N){
	int i;
	for( i=0;i<N-1;i++){ 
		*(a+i)=*(a+i+1);
	}
	a=(livre*)realloc(a,(N-1)*sizeof(livre));
}
void supp_fin_liv(livre *a , int N){
	a=(livre*)realloc(a,(N-1)*sizeof(livre));
}
void supp_pos_liv(livre *a , int N){
	int i,u,k=0;
la:	printf("Entrer la position :\n");
	scanf("%d",&u);
	for( i=0;i<N-1;i++){
		 if(i==u){	 
		    *(a+i)=*(a+i+1);
		    k++;
	}
	}
		if (k==0){
		printf("La position n'existe pas!\n");
		goto la;
 	    }	
	a=(livre*)realloc(a,(N-1)*sizeof(livre));	
}
void supp_titre_liv(livre *a , int N){
int i,j,d,k=0;
    char *u;
    u=(char*)malloc(59*sizeof(char));
    tf:printf("Entrer le titre\n");
    scanf("%s",u);
    if(u){
    for(j=0;j<N;j++){
  d=strcmp((a+j)->titre,u);
        if(d=0){
        k++;
        }
    }
        if (k==0) {
        printf("Le titre n'existe pas!\n");
        goto tf;
    }
    hier :for(i=0;i<N;i++){
         if(*((a+i)->titre)==*u){
         for(int t=i;t<N;t++){
            *(a+t)=*(a+t+1);
            }
            goto hier;
       }
    }   
    a=(livre*)realloc(a,(N-k)*sizeof(livre));
	 afficher(a,N-k);
  }
}
void supp_CIN_liv(livre *a , int N){
int i,j,d,k=0;
    char *u;
    u=(char*)malloc(59*sizeof(char));
    tf:printf("Entrer le CIN de l'auteur\n");
    scanf("%s",u);
    if(u){
    for(j=0;j<N;j++){
    d=strcmp((a+j)->aut.cin,u);
        if(d==0){
        k++;
        }
    }
        if (k==0) {
        printf("Le CIN de l'auteur n'existe pas!\n");
        goto tf;
    }
    hier :for(i=0;i<N;i++){
         if(*((a+i)->aut.cin)==*u){
         for(int t=i;t<N;t++){
            *(a+t)=*(a+t+1);
            }
            goto hier;
       }
    }   a=(livre*)realloc(a,(N-k)*sizeof(livre));
	 afficher(a,N-k);
  }
}
void supp_lettre_liv(livre *a, int N) {
char l;
    int o=0,p=0;;
    ooo:printf("Entrez la lettre :\n");
    scanf(" %c",&l);
    for (int i=0; i<N; i++) {
        for (int j=0;(a+i)->titre[j]!='\0';j++) {
            if((a+i)->titre[j]==l) {
                o++;
                break;
            }
          }
		}
       if(o==0) {
		printf("La lettre n'existe pas!\n");
		goto ooo;
		} 
hier :for(int i=0;i<N;i++){
	for (int j=0;(a+i)->titre[j]!='\0';j++) {
         if((a+i)->titre[j]==l){
         	p++;
         for(int t=i;t<N;t++){
            *(a+t)=*(a+t+1);
            }
			goto hier;
        }
	 }
}
   afficher(a,N-p);
}
int main () {
	int n,y,p,w,s,k;
	livre *ktab;
	la : printf("Entrez le nombre de livres a ajouter\n");
	scanf("%d",&n);
	if(n>50 || n<1) {
		printf("Le nombre est incorrect !\n");
		goto la;
	}
	ktab=(livre*)malloc(n*sizeof(livre));
	if(ktab) {
	printf("Ajoutez les livres :\n");
	ajouter(ktab,n);
	hier2:printf("**************MENU GESTION DES LIVRES**************\n");
	printf("1-Afficher la bibliotheque.\n");
	printf("2-Afficher les livres de la categorie ayant le plus de livres.\n");
	printf("3-Afficher les livres selon les options suivantes : (Par l'auteur, par la cote, par la categorie).\n");
	printf("4-Ajouter un livre selon les options suivantes : (Au debut, a la fin du tableau, en une position donnee, avant un livre identifie par sa cote).\n");
	printf("5-Supprimer un livre selon les options suivantes : (Au debut, a la fin du tableau, en une position donnee, par titre, par auteur (CIN), dont le nom de l'auteur commence par une lettre donnée).\n");
	printf("6-Quitter le programme.\n");
	printf("Entrez votre choix :\n");
	scanf("%d",&p);
	switch (p) {
		case 1: afficher(ktab,n); 
		hier3:printf("\n1-Retour\n2-Quitter le programme\n");
	scanf("%d",&k);
	switch(k) {
		case 1:goto hier2;break;
		case 2:exit(0);break;
		default : printf("Choix erronnee!\n");goto hier3;
	};break;
		case 2: cat(ktab,n);
		hier4:printf("\n1-Retour\n2-Quitter le programme\n");
	scanf("%d",&k);
	switch(k) {
		case 1:goto hier2;break;
		case 2:exit(0);break;
		default : printf("Choix erronnee!\n");goto hier4;
	}break;
		ici7:case 3: printf("1-Par l'auteur\n2-Par la cote\n3-Par la categorie\n4-Retour\n");
		scanf("%d",&s);
		switch(s) {
			case 1:affich_aut(ktab,n);hier5:printf("\n1-Retour\n2-Quitter le programme\n");
	scanf("%d",&k);
	switch(k) {
		case 1:goto ici7;break;
		case 2:exit(0);break;
		default : printf("Choix erronnee!\n");goto hier5;}break;
			case 2:affich_cote(ktab,n);hier6:printf("\n1-Retour\n2-Quitter le programme\n");
	scanf("%d",&k);
	switch(k) {
		case 1:goto ici7;break;
		case 2:exit(0);break;
		default : printf("Choix erronnee!\n");goto hier6;}break;
			case 3:affich_cat(ktab,n);hier7:printf("\n1-Retour\n2-Quitter le programme\n");
	scanf("%d",&k);
	switch(k) {
		case 1:goto ici7;break;
		case 2:exit(0);break;
		default : printf("Choix erronnee!\n");goto hier7;}break;
			case 4:goto hier2;break;
			default:printf("Choix erronnee!\n");goto ici7;
		}; break;
		ici6:case 4: printf("1-Au debut du tableau.\n2-A la fin du tableu.\n3-En une position donnee.\n4-Avant un livre identifie par sa cote\n5-Retour\n");
				scanf("%d",&y);
				switch(y){
					case 1: ajout_debut_liv(ktab,n);afficher(ktab,n+1);hier8:printf("\n1-Retour\n2-Quitter le programme\n");
	scanf("%d",&k);
	switch(k) {
		case 1:goto ici6;break;
		case 2:exit(0);break;
		default : printf("Choix erronnee!\n");goto hier8;}break;
					case 2:ajout_fin_liv(ktab,n);afficher(ktab,n+1);hier9:printf("\n1-Retour\n2-Quitter le programme\n");
	scanf("%d",&k);
	switch(k) {
		case 1:goto ici6;break;
		case 2:exit(0);break;
		default : printf("Choix erronnee!\n");goto hier9;}break;
					case 3:ajout_pos_liv(ktab,n);afficher(ktab,n+1);hier10:printf("\n1-Retour\n2-Quitter le programme\n");
	scanf("%d",&k);
	switch(k) {
		case 1:goto ici6;break;
		case 2:exit(0);break;
		default : printf("Choix erronnee!\n");goto hier10;}break;
					case 4:ajout_cote_liv(ktab,n);afficher(ktab,n+1);hier11:printf("\n1-Retour\n2-Quitter le programme\n");
	scanf("%d",&k);
	switch(k) {
		case 1:goto ici6;break;
		case 2:exit(0);break;
		default : printf("Choix erronnee!\n");goto hier11;}break;
					case 5:goto hier2;break;
					default:printf("Choix erronnee!\n");goto ici6;
				}
				break;
		ici5:case 5:	printf("1-Au debut du tableau.\n2-A fin du tableu.\n3-En une position donnee.\n4-Par titre.\n5-Par CIN de l'auteur\n6-Dont le nom de l'auteur commence par une lettre donnee\n7-Retour\n");
				scanf("%d",&w);	
				switch(w){
					case 1:supp_debut_liv(ktab,n);afficher(ktab,n-1);hier12:printf("\n1-Retour\n2-Quitter le programme\n");
	scanf("%d",&k);
	switch(k) {
		case 1:goto ici5;break;
		case 2:exit(0);break;
		default : printf("Choix erronnee!\n");goto hier12;}break;
					case 2:supp_fin_liv(ktab,n);afficher(ktab,n-1);hier13:printf("\n1-Retour\n2-Quitter le programme\n");
	scanf("%d",&k);
	switch(k) {
		case 1:goto ici5;break;
		case 2:exit(0);break;
		default : printf("Choix erronnee!\n");goto hier13;}break;
					case 3:supp_pos_liv(ktab,n);afficher(ktab,n-1);hier14:printf("\n1-Retour\n2-Quitter le programme\n");
	scanf("%d",&k);
	switch(k) {
		case 1:goto ici5;break;
		case 2:exit(0);break;
		default : printf("Choix erronnee!\n");goto hier14;}break;
					case 4:supp_titre_liv(ktab,n);hier15:printf("\n1-Retour\n2-Quitter le programme\n");
	scanf("%d",&k);
	switch(k) {
		case 1:goto ici5;break;
		case 2:exit(0);break;
		default : printf("Choix erronnee!\n");goto hier15;}break;
					case 5:supp_CIN_liv(ktab,n);hier16:printf("\n1-Retour\n2-Quitter le programme\n");
	scanf("%d",&k);
	switch(k) {
		case 1:goto ici5;break;
		case 2:exit(0);break;
		default : printf("Choix erronnee!\n");goto hier16;}break;
					case 6:supp_lettre_liv(ktab,n);hier17:printf("\n1-Retour\n2-Quitter le programme\n");
	scanf("%d",&k);
	switch(k) {
		case 1:goto ici5;break;
		case 2:exit(0);break;
		default : printf("Choix erronnee!\n");goto hier17;}break;
					case 7:goto hier2;break;
					default:printf("Choix erronnee!\n");goto ici5;
                 }
				 break;
		case 6: exit(0);break;
		default:printf("Choix erronnee!\n");goto hier2;
	 }
	}
	else printf("Memoire saturee !\n");
		return 0;
}
