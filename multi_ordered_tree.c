//
// AED, January 2022
//
// Solution of the second practical assignement (multi-ordered tree)
//
// Place your student numbers and names here
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AED_2021_A02.h"
#include "elapsed_time.c"


//
// the custom tree node structure
//
// we want to maintain three ordered trees (using the same nodes!), so we need three left and three right pointers
// so, when inserting a new node we need to do it three times (one for each index), so we will end upo with 3 three roots
//

typedef struct tree_node_s
{
  char name[MAX_NAME_SIZE + 1];                         // index 0 data item
  char zip_code[MAX_ZIP_CODE_SIZE + 1];                 // index 1 data item
  char telephone_number[MAX_TELEPHONE_NUMBER_SIZE + 1]; // index 2 data item
  char social_number[MAX_SOCIAL_NUMBER_SIZE+1];       //index 3 data item
  struct tree_node_s *left[4];                          // left pointers (one for each index) ---- left means smaller
  struct tree_node_s *right[4];                         // right pointers (one for each index) --- right means larger
}
tree_node_t;


//
// the node comparison function (do not change this)
/* 
str1>str2 (>0)
str1<str2 (<0)
str1==str2 (0)
*/

int compare_tree_nodes(tree_node_t *node1,tree_node_t *node2,int main_idx)
{
  int i,c;

  for(i = 0;i < 3;i++)
  {
    if(main_idx == 0)
      c = strcmp(node1->name,node2->name);
    else if(main_idx == 1)
      c = strcmp(node1->zip_code,node2->zip_code);
    else if(main_idx == 2)
      c = strcmp(node1->telephone_number,node2->telephone_number);
    else
      c = strcmp(node1->social_number,node2->social_number);
    if(c != 0)
      return c; // different on this index, so return
    main_idx = (main_idx == 3) ? 0 : main_idx + 1; // advance to the next index
  }
  return 0;
}


//
// tree insertion routine (place your code here)
//

//index- tipo de dados pelo qual vou ordenar
//roots- a arvore ja existente
//node - novo nó
void tree_insert( tree_node_t *node, int index, tree_node_t **roots )
{
   //ver se a raiz nao é nula, 
   //no caso de ser null colocamos o nó na raiz
    if (roots[index] == NULL){
      roots[index]=node;
      return;
    }
    
    if ( compare_tree_nodes (node,roots[index],index)<0)
        tree_insert(node,index, roots[index]->left);
    else if (compare_tree_nodes (node,roots[index],index)>0)
        tree_insert(node,index, roots[index]->right);
 
    return;
}


//
// tree search routine (place your code here)
//

/*
roots - arvore completa 
index- pelo que é organizado
node - nó para descobrir
*/
tree_node_t *find( tree_node_t *root, int index, tree_node_t node)
{
  if (root==NULL){return NULL;}  

  if ( compare_tree_nodes (&node,root,index)==0 ){
     return root;
  } else if(compare_tree_nodes (&node,root,index)<0){
    return find(root->left[index], index, node);
  }else {
     return find(root->right[index], index, node);
  }
}


//
/* tree depdth - profundidade da arvore
root - arvore completa
index - tipo de dados
*/

int tree_depth( tree_node_t *root, int index )

{
  if (root==NULL){return 0;}

  int direito = tree_depth(root->right[index] , index);
  int esquerdo =tree_depth(root->left[index] , index);

  return (direito >esquerdo ? direito : esquerdo) + 1; // soma-se 1 pois a raiz é nivel zero
}


//
// list, i,e, traverse the tree (place your code here)
//imprimir a arvore
// root - arvore completa
// index - tipo de dados
//

void print_dados(tree_node_t *root){
  static int counter=1;
  printf("Person #%d\n", counter++);
  printf("  name -------------------%s\n",root->name);
  printf("  zip code ---------------%s\n", root-> zip_code);
  printf("  telephone number -------%s\n",root->telephone_number);
  printf("  social security number--%s\n",root->social_number);

}
void list(tree_node_t *root, int index)
{
  if (root != NULL)
    {
        list(root->left[index], index);
        print_dados(root);
        list(root->right[index], index);
    }
}

/*
retornar a pesssoa
preciso dos zip code completos 
preciso do nome que vou achar 

*/

int compare(char *dados,tree_node_t *node2,int main_idx)
{
    int c;
  
    if(main_idx == 0)
      c = strcmp(dados,node2->name);
    else if(main_idx == 1)
      c = strcmp(dados,node2->zip_code);
    else if(main_idx == 2)
      c = strcmp(dados,node2->telephone_number);
    else
      c = strcmp(dados,node2->social_number);

  return c;
}

tree_node_t* search( char *dados, tree_node_t **roots, int index){
  if (roots[index]==NULL){ 
    return NULL;
  }

  tree_node_t* node_left=search(dados, roots[index]->left, index);
  tree_node_t* node_right=search(dados, roots[index]->right, index);

 //a condiçao so a feita por necessidade dos filho
  if (compare(dados,roots[index],index)==0)
  {
    tree_node_t* node = malloc(sizeof(tree_node_t));
    memcpy(node,roots[index],sizeof(tree_node_t));
    for(int i=0; i<4;i++){
      node->left[i]=NULL;
    }
     for(int i=0; i<4;i++){
      node->right[i]=NULL;
    }

    if(node_left!=NULL){ 
      tree_insert(node_left,0,&node);
    } 
    if(node_right!=NULL){ 
      tree_insert(node_right,0,&node);
    } 
    return node;
  }
  if (node_left==NULL && node_right==NULL){ 
    return NULL;
  } else if (node_left == NULL){
    return node_right;
  } else if(node_right == NULL){
    return node_left;
  }else{
    tree_insert(node_right,0,&node_left);
    return node_left;
  }
}
//
// main program
//

int main(int argc,char **argv)
{
  double dt; //tempo

  // process the command line arguments
  if(argc < 3)
  {
    fprintf(stderr,"Usage: %s student_number number_of_persons [options ...]\n",argv[0]);
    fprintf(stderr,"Recognized options:\n");
    fprintf(stderr,"  -list[N]              # list the tree contents, sorted by key index N (the default is index 0)\n");
    fprintf(stderr,"  -search[N]    ----    # list the tree contents, sorted by key index N (the default is index 0)\n");

    // place a description of your own options here
    return 1;
  }
  int student_number = atoi(argv[1]);
  if(student_number < 1 || student_number >= 1000000)
  {
    fprintf(stderr,"Bad student number (%d) --- must be an integer belonging to [1,1000000{\n",student_number);
    return 1;
  }
  int n_persons = atoi(argv[2]);
  if(n_persons < 3 || n_persons > 10000000)
  {
    fprintf(stderr,"Bad number of persons (%d) --- must be an integer belonging to [3,10000000]\n",n_persons);
    return 1;
  }
  // generate all data
  tree_node_t *persons = (tree_node_t *)calloc((size_t)n_persons,sizeof(tree_node_t));
  if(persons == NULL)
  {
    fprintf(stderr,"Output memory!\n");
    return 1;
  }
  aed_srandom(student_number);
  for(int i = 0;i < n_persons;i++)
  {
    random_name(&(persons[i].name[0]));
    random_zip_code(&(persons[i].zip_code[0]));
    random_telephone_number(&(persons[i].telephone_number[0]));
    random_social_number(&(persons[i].social_number[0]));
    for(int j = 0;j < 4;j++)
      persons[i].left[j] = persons[i].right[j] = NULL; // make sure the pointers are initially NULL
  }
  // create the ordered binary trees
  dt = cpu_time();
  tree_node_t *roots[4]; // three indices, three roots

  //main_index-- corresponde ao tipo de dado
  for(int main_index = 0;main_index < 4;main_index++)
    roots[main_index] = NULL;
  for(int i = 0;i < n_persons;i++)
    for(int main_index = 0;main_index < 4;main_index++)
       tree_insert(&persons[i], main_index, roots); // place your code here to insert &(persons[i]) in the tree with number main_index
  dt = cpu_time() - dt;
  printf("Tree creation time (%d persons): %.3es\n",n_persons,dt);
  //search the tree
  for(int main_index = 0;main_index < 4;main_index++)
  {
    dt = cpu_time();
    for(int i = 0;i < n_persons;i++)
    {
      tree_node_t n = persons[i]; // make a copy of the node data
      if(find(roots[main_index],main_index,n) != &(persons[i])) // place your code here to find a given person, searching for it using the tree with number main_index
      {
        fprintf(stderr,"person %d not found using index %d\n",i,main_index);
        return 1;
      }
    }
    dt = cpu_time() - dt;
    printf("Tree search time (%d persons, index %d): %.3es\n",n_persons,main_index,dt);
  }
  // compute the largest tree depdth
  for(int main_index = 0;main_index < 4;main_index++)
  {
    dt = cpu_time();
    int depth = tree_depth(roots[main_index], main_index ); // place your code here to compute the depth of the tree with number main_index
    dt = cpu_time() - dt;
    printf("Tree depth for index %d: %d (done in %.3es)\n",main_index,depth,dt);
  }
  // process the command line optional arguments
  for(int i = 3;i < argc;i++)
  {
    if(strncmp(argv[i],"-list",5) == 0)
    { // list all (optional)
      int main_index = atoi(&(argv[i][5]));
      if(main_index < 0)
        main_index = 0;
      if(main_index > 3)
        main_index = 3;
      printf("List of persons:\n");
      list(roots[main_index], main_index); // place your code here to traverse, in order, the tree with number main_index
      
    }else if(strncmp(argv[i],"-search",7) == 0){
       // search all (optional)
        int main_index = atoi(&(argv[i][7]));
        if(main_index < 0)
          main_index = 0;
        if(main_index > 3)
          main_index = 3;

      char *dados = argv[i+1];
      printf("List of persons:\n");
      dt = cpu_time();
      list(search(dados,roots,main_index),0);
      dt=cpu_time()-dt;
       printf("Tree search time (index %d): %.3es\n",main_index,dt);
    }
    // place your own options here
  }
  // clean up --- don't forget to test your program with valgrind, we don't want any memory leaks
  free(persons);
  return 0;
}