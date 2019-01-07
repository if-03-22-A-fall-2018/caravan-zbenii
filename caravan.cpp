/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <2AHIF>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			caravan.c
 * Author(s):		Benjamin Besic
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include "caravan.h"
#include <stdlib.h>

struct PackAnimalImplementation {
	AnimalType type;
	const char *name;
	int max_speed;
	int load;
	Caravan caravan;
};

typedef struct _node{
  PackAnimal pack_animal;
  struct _node* next;
}Node;

struct CaravanImplementation{
  Node* head;
};

Caravan new_caravan()
{
  Caravan caravan = (Caravan)malloc(sizeof(struct CaravanImplementation));
  caravan->head = 0;
  return caravan;
}

int get_length(Caravan caravan)
{
  int count=0;
  Node* currentNode=caravan->head;
  while(currentNode!=0)
  {
    count++;
    currentNode=currentNode->next;
  }
  return count;
}

void delete_caravan(Caravan caravan)
{
  int length=get_length(caravan);

  for (int i = 0; i < length; i++) {
    Node* head=caravan->head;
    caravan->head=head->next;
    free(head);
  }
  free(caravan);
}

void add_pack_animal(Caravan caravan, PackAnimal animal)
{
  if((animal == 0) || (animal->caravan == caravan)){
    return;
  }

  if(animal->caravan != 0){
    remove_pack_animal(animal->caravan, animal);
  }

  animal->caravan = caravan;
  Node* new_node = (Node*)malloc(sizeof(Node));
  new_node->pack_animal = animal;
  new_node->next = caravan->head;
  caravan->head = new_node;

}

void remove_pack_animal(Caravan caravan, PackAnimal animal)
{
}

int get_caravan_load(Caravan caravan)
{
  int length = get_length(caravan);
  int load_count = 0;
  Node* crnt_node = caravan->head;

  for(int i = 0; i < length; i++){
    load_count += crnt_node->pack_animal->load;
    crnt_node = crnt_node->next;
  }

  return load_count;
}

void unload(Caravan caravan)
{
  int length = get_length(caravan);

  Node* crnt_node = caravan->head;

  for(int i = 0; i < length; i++){
    crnt_node->pack_animal->load = 0;
    crnt_node = crnt_node->next;
  }

}

int get_caravan_speed(Caravan caravan)
{
}
