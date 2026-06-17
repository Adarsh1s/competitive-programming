class MyLinkedList {
    struct Node{
        int val;
        Node* next;
        Node(int v) : val(v),next(nullptr){}
    };
    Node* sentinel;
    int size;
public:
    MyLinkedList() {
        sentinel = new Node(0);
        size = 0;
    }
    
    int get(int index) {
        if(index<0 || index>=size) return -1;
        Node* current = sentinel->next;
        for(int i = 0;i<index;i++){
            current = current->next;
        }
        return current->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0,val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size,val);
    }
    
    void addAtIndex(int index, int val) {
        if(index<0 || index>size) return;
        Node* temp = sentinel;
        for(int i = 0;i<index;i++){
            temp = temp->next;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next=newNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index<0 || index>=size) return;
        Node* temp = sentinel;
        for(int i = 0;i<index;i++){
            temp = temp->next;
        }
        Node* todel = temp->next;
        temp->next = todel->next;
        delete todel;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */