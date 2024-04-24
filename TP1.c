#include "TP1.h"
#include <stdlib.h>

/*=============================================================================
|                                                                             |
|                              PARTIE 1                                       |
|                                                                             |
=============================================================================*/
int pow2(unsigned int n) {
  return 1<<n;
}

VECTEUR vecteur_vide(unsigned int n) {
  VECTEUR v;
  v = (int *)calloc(n, sizeof(VECTEUR));
  return v;
}

void affiche_vecteur(VECTEUR v, unsigned int n){
  if(v){
  printf("(%d", v[0]);
  for (size_t i = 1; i < n; i++) {
    printf(", %d",v[i] );
  }
  printf(")\n");
  } return;
}

void affiche_vecteur_mirroir(VECTEUR v, unsigned int n){
  if(v){
  printf("(");
  for (int i = n-1; i > 0; i--) {
    printf("%d, ",v[i] );
  }
  printf("%d)\n",v[0]);
  } return;
}

VECTEUR vecteur(unsigned int valeur, unsigned int n){
  int max = pow2(n);
  int k = 0;
  if(valeur > max)
    return NULL;
  VECTEUR v = vecteur_vide(n);
  while (valeur) {
    if (valeur & 1) {
      v[k]++;
    }
    k++;
    valeur >>= 1;
  }
  return v;
}

int valeur(VECTEUR v, unsigned int n){
  int val = 0;
  for (size_t i = n-1; i > 0; i--) {
    //printf("%d\n",i );
    if(v[i]){ val |= 1;}
    val <<= 1;
  }
  if (v[0]) val |= 1;
  return val;
}

/*=============================================================================
|                                                                             |
|                              PARTIE 2                                       |
|                                                                             |
=============================================================================*/


VECTEUR* mots(unsigned int k){
  if(k < 1 || k > 32)
    return NULL;
  VECTEUR* out;
  int max = pow2(k);
  out = (VECTEUR*) malloc(max * sizeof(int) * k);
  for (size_t i = 0; i < max; i++) {
    out[i] = vecteur(k, i);
  }
  return out;
}

unsigned int poids(VECTEUR v, int n){
  int p = 0;
  for (size_t i = 0; i < n; i++)
    if(v[i]) p++;
  return p;
}

VECTEUR diff(VECTEUR u, VECTEUR v, int n){
  if(n <= 0)
    return NULL;
  int valu = valeur(u, n);
  int valv = valeur(v, n);
  int ans = valu ^ valv;
  //printf("%d\n",ans );
  return(vecteur(ans, n));
}

unsigned int hamming(VECTEUR u, VECTEUR v, int n){
  int val = valeur(diff(u,v,n), n);
  int k = 0;
  while (val) {
    if(val&1)
      k++;
    val>>=1;
  }
  return k;
}


/*=============================================================================
|                                                                             |
|                              PARTIE 3                                       |
|                                                                             |
=============================================================================*/
/*
MATRICE init_matrice( unsigned int l, unsigned int c){
  MATRICE mat;
  mat = malloc()
}
*/

MATRICE merge_vec(VECTEUR* vec,unsigned int mat_n, unsigned int vec_n){
  //vec_n -> taille vecteur
  // mat_n -> lignes matrice : (nb de vecteurs)
  MATRICE mat;
  mat = malloc(sizeof(int*) * mat_n );
  for (size_t i = 0; i < mat_n; i++){
    affiche_vecteur_mirroir(vec[i], vec_n);
    mat[i] = vec[i];
  }
  printf("hey\n" );
  return mat;
}

void affiche_matrice(MATRICE mat, unsigned int c, unsigned int l) {
  printf("ho\n" );
  for (unsigned int i = 0; i < c; i++) {
    printf("[ ");
    for (int j = l-1; j >= 0; j--) {
      printf("%d ",mat[i][j] );
    }
    printf("]\n");
  }
}

VECTEUR encode (MATRICE g, VECTEUR v, unsigned int k, unsigned int n){
  //TODO: ca marche pas oskouuuur
  VECTEUR result = vecteur_vide(n);
  for (int i = 0; i < n; i++) {
    int temp = v[i] & g[0][i];
    for (size_t j = 1; j < k; j++) {
      temp ^= v[i] & g[j][i];
    }
    result[i] = temp;
  }
  return result;
}

int main(int argc, char const *argv[]) {
  /*======================================================
                    TESTS part 1
  =====================================================*
  int n = 5;
  printf("this is pow2 of %d : %d\n", n, pow2(n));
  VECTEUR v = vecteur_vide(n);
  affiche_vecteur(v, n);
  VECTEUR v2 = vecteur(42, 6);
  VECTEUR v3 = vecteur(21, 6);
  VECTEUR v4 = vecteur(63, 6);
  affiche_vecteur(v4, 6);
  printf("valeur du vecteur au dessus : %d\n",valeur(v4, 6) );
  affiche_vecteur(v2, 6);
  printf("valeur du vecteur au dessus : %d\n",valeur(v2, 6) );
  affiche_vecteur(v3, 6);
  printf("valeur du vecteur au dessus : %d\n",valeur(v2, 6) );
  /*======================================================
                    TESTS part 2
  =====================================================*
  //VECTEUR* m = mots(3);
  //for (size_t i = 0; i < pow2(3); i++) { affiche_vecteur_mirroir(m[i], 3);}
  printf("poids de %d : %d\n",0, poids(NULL, 0) );
  printf("poids de %d : %d\n",42, poids(v2, 6) );
  printf("diff des vecteurs %d et %d : ",valeur(v2, 6), valeur(v3, 6) );
  VECTEUR vect = diff(v2, v3, 6);
  affiche_vecteur_mirroir(vect, 6);
  printf("distance de Hamming entre %d et %d : %d\n",valeur(v2, 6), valeur(v3, 6), hamming(v2, v3, 6) );
  /*======================================================
                    TESTS part 3
  =====================================================*/
  VECTEUR v0 = vecteur(69, 7);
  VECTEUR v1 = vecteur(39, 7);
  VECTEUR v2 = vecteur(22, 7);
  VECTEUR v3 = vecteur(11, 7);
  VECTEUR* v;
  v = malloc(4 * sizeof(VECTEUR));
  v[0] = v0; v[1] = v1; v[2] = v2; v[3] = v3;
  MATRICE G = merge_vec(v, 4, 7);
  affiche_matrice(G,4, 7);
  VECTEUR* V = mots(4);
  for (size_t i = 0; i < 16; i++) { affiche_vecteur(encode(G, V, 4, 7),7);
  }


  return 0;
}
