#include <sstream>
#include <iostream>


using namespace std;

struct Node {
   int data;
   struct Node *next;
};

struct Node* head = NULL;

void insert(int new_data) {
   struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
   new_node->data = new_data;
   new_node->next = head;
   head = new_node;
}

int listLength(Node* head){
  if(head->next == NULL){
    return 1;
  }
  else{
    Node* new_head = head->next;
    return 1 + listLength(new_head);
  }
}

int main (int argc, char* argv[]) {
  istringstream length_stream(argv[1]);
  int list_length;
  if(length_stream >> list_length){
    for(int i = 0; i < list_length; i++){
      insert(1);
    }
  }
  cout << "List Length: " << listLength(head);

}
