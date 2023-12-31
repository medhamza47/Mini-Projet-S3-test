#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct {
	char code1[50],nom[50],natio[50],adresse[50];
} fournisseur;
typedef struct {
	char marque[50],type[50];
	int code,annee;
	float prix;
	fournisseur fr;
} bijou;
void ajouter (bijou *a,int N) {
	int c,l;
	for(int i=0; i<N; i++) {
		printf("Entrez la marque du bijou %d\n",i+1);
		scanf("%s",(a+i)->marque);
/*poo:
		printf("Entrez le type du bijou %d\n",i+1);
		scanf("%s",(a+i)->type);
		for(int j=0; j<strlen(((a+i)->type)); j++) {
			l=isalpha((a+i)->type[j]);
		}
		if(l==0) {
			printf("Le type ne doit contenir que des lettres!\n");
			goto poo;
		}
		printf("Entrez le code du bijou %d\n",i+1);
		scanf("%d",&(a+i)->code);
ici :
		printf("Entrez l'annee de fabrication du bijou %d\n",i+1);
		scanf("%d",&(a+i)->annee);
		if((a+i)->annee>2023 || (a+i)->annee <0) {
			printf("L'annee est incorrecte !\n");
			goto ici;
		}
		printf("Entrez le prix du bijou %d\n",i+1);
		scanf("%f",&(a+i)->prix);
foo:
		printf("Entrez le nom du fournisseur du bijou %d\n",i+1);
		scanf("%s",(a+i)->fr.nom);
		for(int j=0; j<strlen(((a+i)->fr.nom)); j++) {
			c=isalpha((a+i)->fr.nom[j]);
		}
		if(c==0) {
			printf("Le nom du fournisseur ne doit contenir que des lettres!\n");
			goto foo;
		}
		printf("Entrez le code du fournisseur du bijou %d\n",i+1);
		scanf("%s",(a+i)->fr.code1);
here :
		printf("Entrez l'adresse du fournisseur de bijou %d\n",i+1);
		scanf("%s",(a+i)->fr.adresse);
		printf("Entrez la nationnalite du fournisseur du bijou %d\n",i+1);
		scanf("%s",(a+i)->fr.natio);*/
	}
}
void afficher (bijou *a, int N) {
	int k;
	printf("Voici les bijoux de la boutique :\n");
	for (int i=0; i<N; i++) {
		printf("------------>Le bijou%d<------------  \n",i+1);
		printf("\tMarque du bijou                : %s\n",(a+i)->marque);
		printf("\tCode du bijou                  : %d\n",(a+i)->code);
		printf("\tAnnee de fabrication du bijou  : %d\n",(a+i)->annee);
		printf("\tType du bijou                  : %s\n",(a+i)->type);
		printf("\tPrix du bijou                  : %f\n",(a+i)->prix);
		printf("\tNom de fournisseur             : %s\n",(a+i)->fr.nom);
		printf("\tCode de fournisseur            : %s\n",(a+i)->fr.code1);
		printf("\tAdresse de fournisseur         : %s\n",(a+i)->fr.adresse);
		printf("\tNationalite de fournisseur     : %s\n",(a+i)->fr.natio);

	}
}
void afficher_plus_bijoux(bijou *a,int N) {
	int r=0,c,*b,max;
	b=(int*)malloc(N*sizeof(int));
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			c=strcmp((a+i)->type,(a+j)->type);
			if(*((a+i)->type)==*((a+j)->type)) {
				r++;
			}
		}
		*(b+i)=r;
		r=0;
	}
	max=*b;
	for(int i=1; i<N; i++) {
		if(*(b+i)>max) {
			max=*(b+i);
		}
	}
	int e=0;
	for(int i=0; i<N; i++) {
		if(*(b+i)==max && max!=1) {
			printf("------------>Le bijou%d<------------  \n",i+1);
			printf("\tMarque du bijou                : %s\n",(a+i)->marque);
			printf("\tCode du bijou                  : %d\n",(a+i)->code);
			printf("\tAnnee de fabrication du bijou  : %d\n",(a+i)->annee);
			printf("\tType du bijou                  : %s\n",(a+i)->type);  //wach ran ndiro (a+i) ola (a+e)
			printf("\tPrix du bijou                  : %f\n",(a+i)->prix);
			printf("\tNom de fournisseur             : %s\n",(a+i)->fr.nom);
			printf("\tCode de fournisseur            : %s\n",(a+i)->fr.code1);
			printf("\tAdresse de fournisseur         : %s\n",(a+i)->fr.adresse);
			printf("\tNationalite de fournisseur     : %s\n",(a+i)->fr.natio);
			e++;
		}
	}
	if(e==0) {
		printf("Il y a la meme quantite!\n");
	}
}
void affich_fr(bijou *a,int N) {
	char *c,k=0;
	int d;
	c=(char*)malloc(50*sizeof(char));
hona :
	printf("Entrez le code du fournisseur\n");
	scanf("%s",c);
	for (int i=0; i<N; i++) {
		if(*((a+i)->fr.code1)==*c) {
			printf("------------>Le bijou%d<------------  \n",i+1);
			printf("\tMarque du bijou                : %s\n",(a+i)->marque);
			printf("\tCode du bijou                  : %d\n",(a+i)->code);
			printf("\tAnnee de fabrication du bijou  : %d\n",(a+i)->annee);
			printf("\tType du bijou                  : %s\n",(a+i)->type);
			printf("\tPrix du bijou                  : %f\n",(a+i)->prix);
			printf("\tNom de fournisseur             : %s\n",(a+i)->fr.nom);
			printf("\tCode de fournisseur            : %s\n",(a+i)->fr.code1);
			printf("\tAdresse de fournisseur         : %s\n",(a+i)->fr.adresse);
			printf("\tNationalite de fournisseur     : %s\n",(a+i)->fr.natio);
			k++;
		}
	}
	if (k==0) {
		printf("Le code n'existe pas!\n");
		goto hona;
	}
}
void affich_code(bijou *a,int N) {
	int k=0,z;
hona1 :
	printf("Entrez le code du bijou\n");
	scanf("%d",&z);
	for (int i=0; i<N; i++) {
		if((a+i)->code==z) {
			printf("------------>Le bijou%d<------------  \n",i+1);
			printf("\tMarque du bijou                : %s\n",(a+i)->marque);
			printf("\tCode du bijou                  : %d\n",(a+i)->code);
			printf("\tAnnee de fabrication du bijou  : %d\n",(a+i)->annee);
			printf("\tType du bijou                  : %s\n",(a+i)->type);
			printf("\tPrix du bijou                  : %f\n",(a+i)->prix);
			printf("\tNom de fournisseur             : %s\n",(a+i)->fr.nom);
			printf("\tCode de fournisseur            : %s\n",(a+i)->fr.code1);
			printf("\tAdresse de fournisseur         : %s\n",(a+i)->fr.adresse);
			printf("\tNationalite de fournisseur     : %s\n",(a+i)->fr.natio);
			k++;
		}
	}
	if (k==0) {
		printf("Le code n'existe pas!\n");
		goto hona1;
	}
}
void affich_natio(bijou *a,int N) {
	char *q;
	int d,k=0;
	q=(char*)malloc(50*sizeof(char));
hona :
	printf("Entrez la nationnalite du fournisseur\n");
	scanf("%s",q);
	for (int i=0; i<N; i++) {
		if(*((a+i)->fr.natio)==*q) {
			printf("------------>Le bijou%d<------------  \n",i+1);
			printf("\tMarque du bijou                : %s\n",(a+i)->marque);
			printf("\tCode du bijou                  : %d\n",(a+i)->code);
			printf("\tAnnee de fabrication du bijou  : %d\n",(a+i)->annee);
			printf("\tType du bijou                  : %s\n",(a+i)->type);
			printf("\tPrix du bijou                  : %f\n",(a+i)->prix);
			printf("\tNom de fournisseur             : %s\n",(a+i)->fr.nom);
			printf("\tCode de fournisseur            : %s\n",(a+i)->fr.code1);
			printf("\tAdresse de fournisseur         : %s\n",(a+i)->fr.adresse);
			printf("\tNationalite de fournisseur     : %s\n",(a+i)->fr.natio);
			k++;
		}
	}
	if (k==0) {
		printf("La nationnalite n'existe pas!\n");
		goto hona;
	}
}
void ajout_debut_bij(bijou *a,int N) {
	int c,l;
	a=(bijou*)realloc(a,(N+1)*sizeof(bijou));
	for(int i=N; i>0; i--) {
		*(a+i)=*(a+i-1);
	}
	printf("Entrez la marque du bijou \n");
	scanf("%s",(a)->marque);
poo:
	printf("Entrez le type du bijou\n");
	scanf("%s",(a+0)->type);
	for(int j=0; j<strlen(((a+0)->type)); j++) {
		l=isalpha((a+0)->type[j]);
	}
	if(l==0) {
		printf("Le type ne doit contenir que des lettres!\n");
		goto poo;
	}
	printf("Entrez le code du bijou \n");
	scanf("%d",&(a+0)->code);
ici :
	printf("Entrez l'annee de fabrication du bijou \n");
	scanf("%d",&(a+0)->annee);
	if((a+0)->annee>2023 || (a+0)->annee <0) {
		printf("L'annee est incorrecte !\n");
		goto ici;
	}
	printf("Entrez le prix du bijou \n");
	scanf("%f",&(a+0)->prix);
foo:
	printf("Entrez le nom du fournisseur du bijou \n");
	scanf("%s",(a+0)->fr.nom);
	for(int j=0; j<strlen(((a+0)->fr.nom)); j++) {
		c=isalpha((a+0)->fr.nom[j]);
	}
	if(c==0) {
		printf("Le nom du fournisseur ne doit contenir que des lettres!\n");
		goto foo;
	}
	printf("Entrez le code du fournisseur du bijou\n");
	scanf("%s",(a+0)->fr.code1);
here :
	printf("Entrez l'adresse du fournisseur de bijou\n");
	scanf("%s",(a+0)->fr.adresse);
	printf("Entrez la nationnalite du fournisseur du bijou\n");
	scanf("%s",(a+0)->fr.natio);
}
void ajout_fin_bij(bijou *a,int N) {
	int c,l;
	a=(bijou*)realloc(a,(N+1)*sizeof(bijou));
	printf("Entrez la marque du bijou \n");
	scanf("%s",(a+N)->marque);
poo:
	printf("Entrez le type du bijou\n");
	scanf("%s",(a+N)->type);
	for(int j=0; j<strlen(((a+N)->type)); j++) {
		l=isalpha((a+N)->type[j]);
	}
	if(l==0) {
		printf("Le type ne doit contenir que des lettres!\n");
		goto poo;
	}
	printf("Entrez le code du bijou \n");
	scanf("%d",&(a+N)->code);
ici :
	printf("Entrez l'annee de fabrication du bijou \n");
	scanf("%d",&(a+N)->annee);
	if((a+N)->annee>2023 || (a+N)->annee <0) {
		printf("L'annee est incorrecte !\n");
		goto ici;
	}
	printf("Entrez le prix du bijou \n");
	scanf("%f",&(a+N)->prix);
foo:
	printf("Entrez le nom du fournisseur du bijou \n");
	scanf("%s",(a+N)->fr.nom);
	for(int j=0; j<strlen(((a+N)->fr.nom)); j++) {
		c=isalpha((a+N)->fr.nom[j]);
	}
	if(c==0) {
		printf("Le nom du fournisseur ne doit contenir que des lettres!\n");
		goto foo;
	}
	printf("Entrez le code du fournisseur du bijou\n");
	scanf("%s",(a+N)->fr.code1);
here :
	printf("Entrez l'adresse du fournisseur de bijou\n");
	scanf("%s",(a+N)->fr.adresse);
	printf("Entrez la nationnalite du fournisseur du bijou\n");
	scanf("%s",(a+N)->fr.natio);

}
void ajout_pos_bij(bijou *a,int N) {
	a=(bijou*)realloc(a,(N+1)*sizeof(bijou));
	int e,c,l;
toto:
	printf("Entrer la position :");
	scanf("%d",&e);
	if(e<0||e>=N) {
		printf("La position n'existe pas\n");
		goto toto;
	}
	for(int i=N; i>e; i--) {
		*(a+i)=*(a+i-1);
	}
	printf("Entrez la marque du bijou \n");
	scanf("%s",(a+e)->marque);
poo:
	printf("Entrez le type du bijou\n");
	scanf("%s",(a+e)->type);
	for(int j=0; j<strlen(((a+e)->type)); j++) {
		l=isalpha((a+e)->type[j]);
	}
	if(l==0) {
		printf("Le type ne doit contenir que des lettres!\n");
		goto poo;
	}
	printf("Entrez le code du bijou \n");
	scanf("%d",&(a+e)->code);
ici :
	printf("Entrez l'annee de fabrication du bijou \n");
	scanf("%d",&(a+e)->annee);
	if((a+e)->annee>2023 || (a+e)->annee <0) {
		printf("L'annee est incorrecte !\n");
		goto ici;
	}
	printf("Entrez le prix du bijou \n");
	scanf("%f",&(a+e)->prix);
foo:
	printf("Entrez le nom du fournisseur du bijou \n");
	scanf("%s",(a+e)->fr.nom);
	for(int j=0; j<strlen(((a+e)->fr.nom)); j++) {
		c=isalpha((a+e)->fr.nom[j]);
	}
	if(c==0) {
		printf("Le nom du fournisseur ne doit contenir que des lettres!\n");
		goto foo;
	}
	printf("Entrez le code du fournisseur du bijou\n");
	scanf("%s",(a+e)->fr.code1);
here :
	printf("Entrez l'adresse du fournisseur de bijou\n");
	scanf("%s",(a+e)->fr.adresse);
	printf("Entrez la nationnalite du fournisseur du bijou\n");
	scanf("%s",(a+e)->fr.natio);
}
void ajout_meme_bij(bijou *a,int N) {
	char *v,c,l;
	int j=0;
	a=(bijou*)realloc(a,(N+1)*sizeof(bijou));
	v=(char*)malloc(15*sizeof(char));
	printf("Entrez une marque\n");
	scanf("%s",v);
	for(int i=0; i<N; i++) {
		if(*((a+i)->marque)==*v) {
			j++;
			if(j==3) {
				for(int y=N; y>i; y--) {
					*(a+y)=*(a+y-1);
				}
				printf("Entrez la marque du bijou \n");
				scanf("%s",(a+i+1)->marque);
poo:
				printf("Entrez le type du bijou %d\n",i+1);
				scanf("%s",(a+i+1)->type);
				for(int j=0; j<strlen(((a+i)->type)); j++) {
					l=isalpha((a+i+1)->type[j]);
				}
				if(l==0) {
					printf("Le type ne doit contenir que des lettres!\n");
					goto poo;
				}
				printf("Entrez le code du bijou %d\n",i+1);
				scanf("%d",&(a+i+1)->code);
ici :
				printf("Entrez l'annee de fabrication du bijou %d\n",i+1);
				scanf("%d",&(a+i+1)->annee);
				if((a+i+1)->annee>2023 || (a+i+1)->annee <0) {
					printf("L'annee est incorrecte !\n");
					goto ici;
				}
				printf("Entrez le prix du bijou %d\n",i+1);
				scanf("%f",&(a+i+1)->prix);
foo:
				printf("Entrez le nom du fournisseur du bijou %d\n",i+1);
				scanf("%s",(a+i+1)->fr.nom);
				for(int j=0; j<strlen(((a+i+1)->fr.nom)); j++) {
					c=isalpha((a+i+1)->fr.nom[j]);
				}
				if(c==0) {
					printf("Le nom du fournisseur ne doit contenir que des lettres!\n");
					goto foo;
				}
				printf("Entrez le code du fournisseur du bijou %d\n",i+1);
				scanf("%s",(a+i+1)->fr.code1);
here :
				printf("Entrez l'adresse du fournisseur de bijou %d\n",i+1);
				scanf("%s",(a+i+1)->fr.adresse);
				printf("Entrez la nationnalite du fournisseur du bijou %d\n",i+1);
				scanf("%s",(a+i+1)->fr.natio);
				break;
			}
		}
	}
	printf("%d***************************************\n",j);
	if(j==0) {
	printf("Cette marque n'exicte pas \n");
	} 
	if(j==1) {
		printf("Cette marque exicte seulment une seul fois\n");
	} 
    if(j==2) {
		printf("Cette marque exicte seulment une deux fois\n");
	}
	if(j==3) {
	afficher(a,N+1);
	}

}
void supp_debut_bij(bijou *a, int N) {
	int i;
	for( i=0; i<N-1; i++) {
		*(a+i)=*(a+i+1);
	}
	a=(bijou*)realloc(a,(N-1)*sizeof(bijou));
}
void supp_fin_bij(bijou *a, int N) {
	a=(bijou*)realloc(a,(N-1)*sizeof(bijou));
}
void supp_pos_bij(bijou *a, int N) {
	int i,u,k=0;
la:
	printf("Entrer la position :\n");
	scanf("%d",&u);
	for( i=0; i<N-1; i++) {
		if(i==u) {
			*(a+i)=*(a+i+1);
			k++;
		}
	}
	if (k==0) {
		printf("La position n'existe pas!\n");
		goto la;
	}
	a=(bijou*)realloc(a,(N-1)*sizeof(bijou));
}
void supp_marque_bij(bijou *a, int N) {
	int i,j,d,k=0;
	char *u;
	u=(char*)malloc(59*sizeof(char));
tf:
	printf("Entrer la marque\n");
	scanf("%s",u);
	if(u) {
		for(j=0; j<N; j++) {
			if(*((a+j)->marque)==*u) {
				k++;
			}
		}
		if (k==0) {
			printf("La marque n'existe pas!\n");
			goto tf;
		}
hier :
		for(i=0; i<N; i++) {
			if(*((a+i)->marque)==*u) {
				for(int t=i; t<N; t++) {
					*(a+t)=*(a+t+1);
				}
				goto hier;
			}
		}
		a=(bijou*)realloc(a,(N-k)*sizeof(bijou));
		afficher(a,N-k);
	}
}
void supp_prix_bij(bijou *a, int N) {
	int i,j,d,k=0;
	float u;
tf:
	printf("Entrer le prix du bijou\n");
	scanf("%f",&u);
	for(j=0; j<N; j++) {
		if(u==((a+j)->prix)) {
			k++;
		}
	}
	if (k==0) {
		printf("Ce prix n'existe pas!\n");
		goto tf;
	}
hier :
	for(i=0; i<N; i++) {
		if(((a+i)->prix)==u) {
			for(int t=i; t<N; t++) {
				*(a+t)=*(a+t+1);
			}
			goto hier;
		}
	}
	a=(bijou*)realloc(a,(N-k)*sizeof(bijou));
	afficher(a,N-k);

}
void supp_lettre_bij(bijou *a, int N) {
	char l;
	int b=0,c=0,p=0,M=0;
haha:
	printf("Entrez la lettre :\n");
	scanf(" %c",&l);
	for (int i=0; i<N; i++) {
		for (int j=0; (a+i)->fr.nom[j]!='\0'; j++) {
			if((a+i)->fr.nom[j]==l) {
				b++;
				if(b>=2) {
					M++;
					break;
				}
			}
		}
		b=0;
	}
	if (M==0) {
		printf("La lettre n'existe pas deux fois !\n");
		goto haha;
	}
	for(int i=0; i<N; i++) {
		for (int j=0; (a+i)->fr.nom[j]!='\0'; j++) {
			if((a+i)->fr.nom[j]==l) {
				p++;
				if(p>=2) {
					for(int k=i; k<N; k++) {
						*(a+k)=*(a+k+1);
					}
				}
			}
		}
		p=0;
	}
	a=(bijou*)realloc(a,(N-M)*sizeof(bijou));
	afficher(a,N-M);
}
int main () {
	int n,y,p,w,s,k;
	bijou *khatm;
la :
	printf("Entrez le nombre des bijoux a ajouter\n");
	scanf("%d",&n);
	if(n>50 || n<1) {
		printf("Le nombre est incorrect !\n");
		goto la;
	}
	khatm=(bijou*)malloc(n*sizeof(bijou));
	if(khatm) {
		printf("Ajoutez les bijoux :\n");
		ajouter(khatm,n);
hier2:
		printf("**************MENU GESTION DES LIVRES**************\n");
		printf("1-Afficher la boutique.\n");
		printf("2-Afficher les bijoux du fournisseur ayant le plus de bijoux dans la boutique.\n");
		printf("3-Afficher les bijoux selon les options suivantes : (Par code de fournisseur, par le code du bijou, par la nationnalite du fournisseur).\n");
		printf("4-Ajouter un bijou selon les options suivantes : (Au debut, a la fin du tableau, en une position donnee, apres le 3eme bijou de sa meme marque).\n");
		printf("5-Supprimer un livre selon les options suivantes : (Au debut, a la fin en une position donnee, par marque, par prix, dont le nom de fournisseur contient 2 fois une lettre donnée).\n");
		printf("6-Quitter le programme.\n");
		printf("Entrez votre choix :\n");
		scanf("%d",&p);
		switch (p) {
			case 1:
				afficher(khatm,n);
hier3:
				printf("\n1-Retour\n2-Quitter le programme\n");
				scanf("%d",&k);
				switch(k) {
					case 1:
						goto hier2;
						break;
					case 2:
						exit(0);
						break;
					default :
						printf("Choix erronnee!\n");
						goto hier3;
				};
				break;
			case 2:
				afficher_plus_bijoux(khatm,n);
hier4:
				printf("\n1-Retour\n2-Quitter le programme\n");
				scanf("%d",&k);
				switch(k) {
					case 1:
						goto hier2;
						break;
					case 2:
						exit(0);
						break;
					default :
						printf("Choix erronnee!\n");
						goto hier4;
				}
				break;
ici7:
			case 3:
				printf("1-Par le code du fournisseur\n2-Par le code du bijou\n3-Par la nationnalite du fournisseur\n4-Retour\n");
				scanf("%d",&s);
				switch(s) {
					case 1:
						affich_fr(khatm,n);
hier5:
						printf("\n1-Retour\n2-Quitter le programme\n");
						scanf("%d",&k);
						switch(k) {
							case 1:
								goto ici7;
								break;
							case 2:
								exit(0);
								break;
							default :
								printf("Choix erronnee!\n");
								goto hier5;
						}
						break;
					case 2:
						affich_code(khatm,n);
hier6:
						printf("\n1-Retour\n2-Quitter le programme\n");
						scanf("%d",&k);
						switch(k) {
							case 1:
								goto ici7;
								break;
							case 2:
								exit(0);
								break;
							default :
								printf("Choix erronnee!\n");
								goto hier6;
						}
						break;
					case 3:
						affich_natio(khatm,n);
hier7:
						printf("\n1-Retour\n2-Quitter le programme\n");
						scanf("%d",&k);
						switch(k) {
							case 1:
								goto ici7;
								break;
							case 2:
								exit(0);
								break;
							default :
								printf("Choix erronnee!\n");
								goto hier7;
						}
						break;
					case 4:
						goto hier2;
						break;
					default:
						printf("Choix erronnee!\n");
						goto ici7;
				};
				break;
ici6:
			case 4:
				printf("1-Au debut.\n2-A la fin du tableau.\n3-En une position donnee.\n4-Apres le 3eme bijou de sa meme marque\n5-Retour\n");
				scanf("%d",&y);
				switch(y) {
					case 1:
						ajout_debut_bij(khatm,n);
						afficher(khatm,n+1);
hier8:
						printf("\n1-Retour\n2-Quitter le programme\n");
						scanf("%d",&k);
						switch(k) {
							case 1:
								goto ici6;
								break;
							case 2:
								exit(0);
								break;
							default :
								printf("Choix erronnee!\n");
								goto hier8;
						}
						break;
					case 2:
						ajout_fin_bij(khatm,n);
						afficher(khatm,n+1);
hier9:
						printf("\n1-Retour\n2-Quitter le programme\n");
						scanf("%d",&k);
						switch(k) {
							case 1:
								goto ici6;
								break;
							case 2:
								exit(0);
								break;
							default :
								printf("Choix erronnee!\n");
								goto hier9;
						}
						break;
					case 3:
						ajout_pos_bij(khatm,n);
						afficher(khatm,n+1);
hier10:
						printf("\n1-Retour\n2-Quitter le programme\n");
						scanf("%d",&k);
						switch(k) {
							case 1:
								goto ici6;
								break;
							case 2:
								exit(0);
								break;
							default :
								printf("Choix erronnee!\n");
								goto hier10;
						}
						break;
					case 4:
						ajout_meme_bij(khatm,n);
hier11:
						printf("\n1-Retour\n2-Quitter le programme\n");
						scanf("%d",&k);
						switch(k) {
							case 1:
								goto ici6;
								break;
							case 2:
								exit(0);
								break;
							default :
								printf("Choix erronnee!\n");
								goto hier11;/////////////////????????///////////////////////
						}
						break;
					case 5:
						goto hier2;
						break;
					default:
						printf("Choix erronnee!\n");
						goto ici6;
				}
				break;
ici5:
			case 5:
				printf("1-Au debut.\n2-A la fin.\n3-En une position donnee.\n4-Par marque.\n5-Par prix\n6-Dont le nom de fournisseur contient 2 fois une lettre donnée\n7-Retour\n");
				scanf("%d",&w);
				switch(w) {
					case 1:
						supp_debut_bij(khatm,n);
						afficher(khatm,n-1);
hier12:
						printf("\n1-Retour\n2-Quitter le programme\n");
						scanf("%d",&k);
						switch(k) {
							case 1:
								goto ici5;
								break;
							case 2:
								exit(0);
								break;
							default :
								printf("Choix erronnee!\n");
								goto hier12;
						}
						break;
					case 2:
						supp_fin_bij(khatm,n);
						afficher(khatm,n-1);
hier13:
						printf("\n1-Retour\n2-Quitter le programme\n");
						scanf("%d",&k);
						switch(k) {
							case 1:
								goto ici5;
								break;
							case 2:
								exit(0);
								break;
							default :
								printf("Choix erronnee!\n");
								goto hier13;
						}
						break;
					case 3:
						supp_pos_bij(khatm,n);
						afficher(khatm,n-1);
hier14:
						printf("\n1-Retour\n2-Quitter le programme\n");
						scanf("%d",&k);
						switch(k) {
							case 1:
								goto ici5;
								break;
							case 2:
								exit(0);
								break;
							default :
								printf("Choix erronnee!\n");
								goto hier14;
						}
						break;
					case 4:
						supp_marque_bij(khatm,n);
hier15:
						printf("\n1-Retour\n2-Quitter le programme\n");
						scanf("%d",&k);
						switch(k) {
							case 1:
								goto ici5;
								break;
							case 2:
								exit(0);
								break;
							default :
								printf("Choix erronnee!\n");
								goto hier15;
						}
						break;
					case 5:
						supp_prix_bij(khatm,n);
hier16:
						printf("\n1-Retour\n2-Quitter le programme\n");
						scanf("%d",&k);
						switch(k) {
							case 1:
								goto ici5;
								break;
							case 2:
								exit(0);
								break;
							default :
								printf("Choix erronnee!\n");
								goto hier16;
						}
						break;
					case 6:
						supp_lettre_bij(khatm,n);
hier17:
						printf("\n1-Retour\n2-Quitter le programme\n");
						scanf("%d",&k);
						switch(k) {
							case 1:
								goto ici5;
								break;
							case 2:
								exit(0);
								break;
							default :
								printf("Choix erronnee!\n");
								goto hier17;
						}
						break;
					case 7:
						goto hier2;
						break;
					default:
						printf("Choix erronnee!\n");
						goto ici5;
				}
				break;
			case 6:
				exit(0);
				break;
			default:
				printf("Choix erronnee!\n");
				goto hier2;
		}
	} else printf("Memoire saturee !\n");
	return 0;
}
