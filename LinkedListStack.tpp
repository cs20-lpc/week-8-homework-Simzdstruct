template <typename T>
LinkedListStack<T>::LinkedListStack()
{ }

template <typename T>
LinkedListStack<T>::LinkedListStack(const LinkedListStack<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedListStack<T>& LinkedListStack<T>::operator=(const LinkedListStack<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedListStack<T>::~LinkedListStack() {
    clear();
}

template <typename T>
void LinkedListStack<T>::clear() {
    // TO DO: Delete all the elements in the stack
    while (!isEmpty()) {
        pop();
    }

}

template <typename T>
void LinkedListStack<T>::copy(const LinkedListStack<T>& copyObj) {
    // TO DO: Implement copy 
    if (copyObj.isEmpty()) {
        top = nullptr;
        length = 0;
    }
    else {
        // Copy the first node
        top = new Node<T>(copyObj.top->data);
        Node<T>* currentCopyNode = copyObj.top->next;
        Node<T>* currentNewNode = top;

        // Copy the rest of the nodes
        while (currentCopyNode != nullptr) {
            currentNewNode->next = new Node<T>(currentCopyNode->data);
            currentNewNode = currentNewNode->next;
            currentCopyNode = currentCopyNode->next;
        }
        length = copyObj.length;
    }
    
}

template <typename T>
int LinkedListStack<T>::getLength() const {
    return this->length;
}


template <typename T>
bool LinkedListStack<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
T LinkedListStack<T>::peek() const {
    // TO DO: implement peek
    if (isEmpty()) {
        throw std::runtime_error("Stack is empty. Cannot peek.");
    }
    return top->data;

}

template <typename T>
void LinkedListStack<T>::pop() {
    // TO DO: Implement pop
    if (!isEmpty()) {
        Node<T>* temp = top;
        top = top->next;
        delete temp;
        length--;
    }
}

template <typename T>
void LinkedListStack<T>::push(const T& elem) {
    // TO DO: Implement push
    Node<T>* newNode = new Node<T>(elem);
    newNode->next = top;
    top = newNode;
    length++;
}

template <typename T>
void LinkedListStack<T>::rotate(typename Stack<T>::Direction dir) {
    // TO DO: Implement rotate
    if (isEmpty() || length == 1) {
        return; 
    }

    if  (dir == Stack<T>::RIGHT) {
        if (top == nullptr || top->next == nullptr) {
            return; 
        }
        Node<T>* oldTop = top;
        
        top = top->next;
        Node<T>* current = top;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = oldTop;
        oldTop->next = nullptr;
        
    }
    else {
        if (top == nullptr || top->next == nullptr) {
            return; 
        }
        Node<T>* current = top;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        Node<T>* oldBottom = current->next;
        current->next = nullptr;
        oldBottom->next = top;
        top = oldBottom;
    }
}

template <typename T>
void LinkedListStack<T>::print() {
    cout << "LinkedListStack contents: ";
    if (isEmpty()) {
        cout << "Stack is empty, no elements to display.\n";
    }
    else {
        Node<T> *curr = top;
        while (curr != nullptr){
            cout <<  curr->data  << "\t";
            curr = curr->next;
        }
    }

    cout << endl;
}
