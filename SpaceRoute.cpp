#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Node {
public:
    T& data;
    Node* next;
    Node* prev;

    Node(T& d) : data(d), next(nullptr), prev(nullptr) {}
    void print() { cout << data << " "; }
};

class CelestialNode {
private:
    string name;
    double distance_from_earth;
    string mission_log;

public:
    CelestialNode(const string& n, double d, const string& log);
    const string& getName() const;
    double getDistance() const;
    const string& getMissionLog() const;
    void print() const { cout << name << " (" << distance_from_earth << " AU) - " << mission_log << endl; }
};

template <typename T>
class SpaceRoute {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    SpaceRoute() {
        head = nullptr;
        tail = nullptr;
    }// Constructor
    ~SpaceRoute() {
        Node<T>* temp = head;
        while (temp != nullptr) {
            head = head->next;
            delete temp;
            temp = head;
        }

    } // Destructor

    void addWaypointAtBeginning(T& data) {
        //Create new Node
        Node<T> *newNode = new Node<T>(data);
        //If the head node is null set head and tail to new Node
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            //Otherwise set New Nodes next to the current head, and the current heads prev to New Node then set head to NewNode
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    void addWaypointAtEnd(T& data) {
        //If head is null then addWapointAtEnd is the same as add at begin
        if (head == nullptr) {
            addWaypointAtBeginning(data);
        }
        //Otherwise create a newNode and set its prev pointer to tail and tail next to new node then tail to newNode
        else {
            //Make sure to set prev and next correctly
            Node<T> *newNode = new Node<T>(data);
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }
    void addWaypointAtIndex(int index, T& data) {
        //If index is 0 then add at Begining
        if (index == 0) {
            addWaypointAtBeginning(data);
        }
        else {
            //Create new Node
            Node<T> *newNode = new Node<T>(data);
            //Get the current node at the index
            Node<T> *temp = getWaypoint(index);
            //set new nodes next to temp and newnodes prev to temps prev,
            newNode->next = temp;
            newNode->prev = temp->prev;
            //set temp prev nodes next to newNode
            temp->prev->next = newNode;
            //Lastly set temp prev to newNode
            temp->prev = newNode;


        }
    }
    void removeWaypointAtBeginning() {
        //If head is already null then return
        if (head == nullptr) {
            return;
        }
        //Otherwise create a temp poijnter to head and then set head to head next and set the new head prev to null
        else {
            Node<T> *temp = head;
            head = head->next;
            head->prev = nullptr;
            //delete temp(old head)
            delete temp;
        }
    }
    void removeWaypointAtEnd() {
        //if tail is null return
        if (tail == nullptr) {
            return;
        }
        //same setup as the remove at begin
        else {
            Node<T> *temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;


        }

    }
    void removeWaypointAtIndex(int index) {
        //if the remove index is 0 call remove at begin
        if (index == 0) {
            removeWaypointAtBeginning();
        }
        else {
            //get the needed delete node
            Node<T> *del = getWaypoint(index);
            //get the node previous of delete node
            Node<T> *temp = del->prev;
            //have temp skip  over the delete node
            temp->next = del->next;
            //have the new temp next point to temp
            temp->next->prev = temp;
            delete del;

        }
    }
    void traverseForward() {
        //if empty return
        if (head == nullptr) {
            return;
        }
        else {
            //loop through and print till null
            Node<T> *temp = head;
            while (temp != nullptr) {
                temp->print();
                temp = temp->next;
            }
        }
    }
    void traverseBackward() {
        //if empty return
        if (head == nullptr) {
            return;
        }
        else {
            Node<T> *temp = tail;
            while (temp != nullptr) {
                temp->print();
                temp = temp->prev;
            }
        }
    }
    Node<T>* getWaypoint(int index) {
        //if index is less than 0 return null
        if (index < 0) {
            return nullptr;
        }
        else {
            //start at head and loop through till index
            Node<T> *temp = head;
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }
            return temp;
        }
    }
    void setWaypoint(int index, T& data) {
        //use get Waypoint
        Node<T> *temp = getWaypoint(index);
        //set temp data to given data
        temp->data = data;
    }
    void print(){

            Node<T>* current = head;
            while (current) {
                current->print();
                current = current->next;
            }
            cout << endl;
        }

};

