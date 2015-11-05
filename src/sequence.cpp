/*
  "g++ sequence.cpp main.cpp -std=c++11 -o main"
*/

using namespace std;
#include <iostream>

//Node list;

template <typename Data>
Sequence<Data>::Sequence(){
}

template <typename Data>
Sequence<Data>::~Sequence(){
  if(getSize() <= 0){
    return;
  }
  Node *aux = list.next;
  while(aux->next != nullptr){
    aux = aux->next;
    delete (aux->prev);
  }
  delete aux;
}

template <typename Data>
bool Sequence<Data>::isEmpty(){
  if(getSize() == 0){
    return true;
  }
  else{
    return false;
  }
}

template <typename Data>
int Sequence<Data>::getSize(){
  Node *aux = list.next;
  int cont = 0;
  while(aux != nullptr){
    cont++;
    aux = aux->next;
  }
  return cont;
}

template <typename Data>
bool Sequence<Data>::addFirst(const Data &value){
  Node *elemento = new Node;
  elemento->data = value;
  elemento->next = list->next;
  elemento->prev = nullptr;
  list.next = elemento;
  
  if(getFirst() == value){
    return true;
  }
  else if(getFirst() != value){
    return false;
  }
  else{
    cout<<"foo";
    return false;
  }
}

template <typename Data>
bool Sequence<Data>::addLast(const Data &value){
  int check = 1;
  Node *aux = list.prev;
  Node *elemento = new Node;
  elemento->data = value;
  elemento->prev = list->prev;
  elemento->next = nullptr;
  aux->next = elemento;
  list->prev = elemento;
  
  if(getLast() == value){
    return true;
  }
  else if(getLast() != value){
    return false;
  }
  else{
    cout<<"foo";
    return false;
  }
}
template <typename Data>
bool Sequence<Data>::add(const Data &value, int pos) {
  Node *add = new Node;
  add->data = value;
  
  if(pos > getSize()){
    addLast(value);
  }
  else if(pos < 0){
    addFirst(value);
  }
  else{
    Node *aux = list.next;
    for(int i = 0; i < pos; i++){
      aux = aux->next;
    }
    Node *nodulo_anterior = aux->prev;
    Node *nodulo_prox = aux->next;
    
    nodulo_anterior->next = add;
    add->prev = nodulo_anterior;
    
    nodulo_prox->prev = add;
    add->next = nodulo_prox;
    if(get(pos) == value){
      return true;
    } 
    else if(get(pos) != value){
      return false;
    }
    else{
      cout<<"foo";
      return false;
    }
  }
}

template <typename Data>
Data Sequence<Data>::removeFirst(){
  Node *aux = list.next;
  TYPE data = aux->data;
  list.next = aux->next;
  delete aux;
  return data;
}

template <typename Data>
Data Sequence<Data>::removeLast(){
  Node *aux = list->prev;
  TYPE data = aux->data;
  list->prev = aux->prev;
  delete aux;
}

template <typename Data>
Data Sequence<Data>::remove(int pos){
  
  if(pos > (getSize()-1)){
    cout<<"posição maior do que o tamanho - 1 da lista";
    return -1;
  }
  Node *aux = list.next;
  for(int i = 0; i < pos; i++){
    aux = aux.next;
  }
  Node *nodulo_anterior = aux.prev;
  Node *nodulo_prox = aux.next;
  nodulo_anterior->next = nodulo_prox;
  nodulo_prox->prev = nodulo_anterior;
  Data data = aux->data;
  
  delete aux;
  
  return data;
}

template <typename Data>
Data Sequence<Data>::getFirst(){
  Node *aux = list.next;
  if(aux == nullptr){
    cout<<"Lista vazia";
  }
  return aux->data;
  
}

template <typename Data>
Data Sequence<Data>::getLast(){
  Node *aux = list.prev;
  if(aux == nullptr){
    cout<<"Lista vazia";
  }
  return aux->data;
}

template <typename Data>
Data Sequence<Data>::get(int pos){
  if(pos > (getSize()-1)){
    cout<<"posição maior do que o tamanho - 1 da lista";
    return -1;
  }
  Node *aux = list.next;
  for(int i = 0; i < pos; i++){
    aux = aux->next; 
  }
  return aux->data;
}

/*
**Search com While
template <typename TYPE>
int Sequence<TYPE>::search(const TYPE &elm){
  int aux.data = getSize();
    int *aux = list.next;

      while (aux != 0){
        if(aux->data == elm){
          return true;
        }
        else{
        aux = aux->next;
        }
      }
}*/
//search de Maria Clara
template <typename Data>
int Sequence<Data>::search(const Data &elm){
  int i;
  Node *aux = list.next;
  for (i = 1; i <= getSize(); i++){
    if (aux->data == elm)
      return true;
    aux = aux->next;
  }
  return false;
}
//isEqual de Maria Clara
template <typename Data>
bool Sequence<Data>::isEqual(Sequence<Data> &s){
  Node *aux1 = list.next;
  Node *aux2 = s.list.next;
  
  if(getSize()!= s.getSize())
    return false;
  for (int i = 0; i < getSize(); i++){
    if (aux1->data != aux2->data)
      return false;
    aux1 = aux1->next;
    aux2 = aux2->next;
  }

  return true;
}

template <typename Data>
void Sequence<Data>::reverse(){
  Data vetor[getSize()];
  Node *aux = list.next;
  for(int i = 0; i < getSize(); i++)  {
    vetor[i] = aux->data;
    aux = aux->next;
  }
  
  aux = list.next;
  for(int i = (getSize()-1); i >= 0; i--) {
    aux->data = vetor[i];
    aux = aux->next;
  }
}

template <typename Data>
void Sequence<Data>::sort(){
  Data v[getSize()];
  Data aus;
  Node *aux = list.next;
  
  for(int i = 0; i < getSize(); i++)  {
    v[i] = aux->data;
    aux = aux->next;
  }
  
  for (int i = (getSize()-1); i > 0; i--) {
      for (int j = 0; j < i; j++) {
        if (v[j] > v[j+1]){
          aus = v[j];
          v[j] = v[j+1];
          v[j+1] = aux;
      }
    }
  }
  for(int i = 0; i < getSize(); i++)  {
    aux->data = v[i];
    aux = aux->next;
  }
}

template <typename Data>
void Sequence<Data>::print(){
  Node *aux = list.next;
  while(aux != nullptr){
    cout<<aux->data<<endl;
    aux = aux->next;
  }
}