


 # include <iostream >
 using namespace std ;
 const int Max =100;
 // D claration Pile : R e p r sentation Tableau !
 typedef struct Pile
 {
 int element [ Max ]; // C o n s i d rer le max des nts =100
 int sommet ;
 };

 // D claration Pile : R e p r sentation Liste C h a i n e !
 typedef struct PileL
 {
 int info ;
 PileL * suivant ;
 };
 /* *************=================== Primitives Pile r e p r sentation
chaine l i n aire ** */
 /** Initialiser le sommet de la Pile NULL **/
 void initPileL ( PileL * & debut )
 {
 debut =0;
 }
 /** Fonction empiler une valeur x dans une Pile r e p r sent avec
liste c h a i n e , est similaire insertDebut !* */
 void empilerL ( PileL *& debut , int x)
 {
 PileL * nouveau = new PileL ;
 nouveau -> info = x;
 nouveau -> suivant = debut ;
 debut = nouveau ;
 }
 /** Fonction depiler un nt partir d’une pile r e p r sent par
une Liste c h a i n e , est similaire suppDebut
36 sauf il faut ajouter comme p a r a m tre de la fonction x pour
r cupr la valeur de l’ nt s u p p r i m !** */
 void depilerL ( PileL *& debut , int &x) //x: r fnce de la variable

 {
 PileL * sup ;
 if( debut !=0)
 {
 sup = debut ;
 x= debut -> info ;
 debut = debut -> suivant ;
 delete sup ;
 }

 }
 /** Fonction c r ation de la Pile - Liste C h a i n e de n nts **/
 void creationPileL ( PileL *& debut , int n )
 {
 int x;
 for ( int i =0; i <n; i ++)
 {
 cout <<" Donner un entier : ";
 cin >>x ;
 empilerL ( debut ,x);
 }
 }
 /** Fonction afficher Pile ( Liste )**/
 void afficherPileL ( PileL * courant )
 {
 if( courant ==0) cout <<" Pile vide ";
 else
 while ( courant != 0)
 {

 cout  << courant -> info ;
 courant = courant -> suivant ;
 }
 }
 /** Fonction l i b ration de la m moire r serv la Pile ( liste )**/
 void Liberer ( PileL *& debut )
 {
 PileL * sup ;
 while ( debut !=0)
 {
 sup = debut ;
 debut = debut -> suivant ;
 delete sup ;
 }
 }
 /* *************=================== Primitives Pile r e p r sentation
avec Tableau ** */
 /** Initialiser le sommet de la Pile NULL **/
 void initPileT ( Pile &p)
 {
 p. sommet =0;
 }

 /** Fonction empiler une valeur x dans une Pile r e p r sent avec
Tableau !* */
 void empilerT ( Pile &p , int x)
 {
 if(p. sommet == Max ) cout <<" Pile pleine ";
 else
 {
 p. element [p. sommet ]= x;// I n s rer x
 p. sommet ++; // I n c r menter l’indice sommet pour p r parer la

 }
 }
 /** Fonction depiler un nt partir d’une pile r e p r sent par
Tableau !* */ void depilerT ( Pile &p , int &x )
 {
 if(p. sommet ==0) cout <<" Pile vide ";
 else
 {
 p. sommet--;
 x=p . element [ p. sommet ];
 }
 }

 /** Fonction Afficher le contenu de la pile r e p r sent par Tableau *
*/
 void afficherPileT ( Pile p)
 {
 int val ;
 if(p. sommet ==0) cout <<" Pile vide ";
 else
 {
 for ( int i =p. sommet-1; i >=0; i--)
 {

 depilerT (p , val );
 cout <<"[" <<val <<"]\t";
 }
 }
 }
 /** Fonction conversion Pile ( Liste )=> Pile ( Tableau )*/
 void conversionLT ( PileL *& debut , Pile &p)
 {
 int val ;
 Pile temp ;
 initPileT ( temp ) ; /* on d pile et on empile dans un tableau temporaire */
 while ( debut !=0)
 {
 depilerL ( debut , val );
 empilerT ( temp , val );
 }
 /* on d pile du tableau et on empile vers une pile pour inverser l’
ordre des ements */
 for ( int i = temp . sommet -1; i >=0; i -- )
 {
 depilerT ( temp , val );
 empilerT (p , val );
 }


 }
 /** Fonction conversion Pile ( Tableau )=> Pile ( Liste ), attention ici , l
’odre est i n v e r s , je vous demande de le reinverser */
 void conversionTL ( PileL *& debut , Pile &p) {
 int val ;
 if(p. sommet ==0) initPileL ( debut );
 else
 {
 do
 {
 depilerT (p , val );
 empilerL ( debut , val );
 } while ( p. sommet !=0) ;
 }

 }
 /** Fonction Principale main ()**/
 int main ()
 {
 /* D claration d’une liste avec r e p r sentation liste c h a i n e et
l’ i n i t i a l i s e NULL */
 PileL * debut ;
 initPileL ( debut );
 /* Construire la pile de type chaine de c a r a c t re */
 int n;
 cout <<" Donner le nombre d elements a empiler : ";
 cin >>n ;
 creationPileL ( debut ,n);
 /* Afficher la pile construite de type Liste */
 cout <<"\ nPile Saisie = ";

 afficherPileL ( debut );
 /* Convertir la pile ( liste ) en pile ( Tableau )*/
 Pile p;
 conversionLT ( debut ,p) ;
 /* Afficher la pile originale ( liste ) et la nouvelle pile (
tableau )*/
 cout <<"\n\n ==== Conversion Pile ( Liste )=> Pile ( Tableau )";
 cout <<"\ nPile originale ( Liste ): ";
 afficherPileL ( debut );
 cout <<"\ nPile nouvelle ( Tableau ): ";
 afficherPileT (p );
 /* Convertir la pile ( Tableau ) en pile ( Liste )*/;
 conversionTL ( debut ,p) ;
 /* Afficher les deux listes a p r s conversion */
 cout <<"\n\n ==== Conversion Pile ( Tableau )=> Pile ( Liste )";
 cout <<"\ nPile ( Liste ): ";
 afficherPileL ( debut );
 cout <<"\ nPile ( Tableau ): ";
 afficherPileT (p );
 /** L i b rer la m moire a l l o u e pour liste */
 Liberer ( debut );
 return 0;}
