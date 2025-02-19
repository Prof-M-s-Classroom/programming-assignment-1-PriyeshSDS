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
    SpaceRoute();  // Constructor
    ~SpaceRoute(); // Destructor

    void addWaypointAtBeginning(T& data) {
        Node<T> *newNode = new Node<T>(data);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    void addWaypointAtEnd(T& data) {
        if (head == nullptr) {
            addWaypointAtBeginning(data);
        }
        else {
            //Make sure to set prev and next correctly
            Node<T> *newNode = new Node<T>(data);
            newNode->prev = tail;
            tail->next = newNode;
        }
    }
    void addWaypointAtIndex(int index, T& data) {
        if (index == 0) {
            addWaypointAtBeginning(data);
        }
        else {
            Node<T> *newNode = new Node<T>(data);
            Node<T> *temp = getWaypoint(index - 1);
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next = newNode;
        }
    }
    void removeWaypointAtBeginning() {
        if (head == nullptr) {
            return;
        }
        else {
            Node<T> *temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
    }
    void removeWaypointAtEnd() {
        if (head == nullptr) {
            return;
        }
        else {
            Node<T> *temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;


        }

    }
    void removeWaypointAtIndex(int index) {
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
        if (head == nullptr) {
            return;
        }
        else {
            Node<T> *temp = head;
            while (temp->next != nullptr) {
                temp->print();
                temp = temp->next;
            }
        }
    }
    void traverseBackward() {
        if (head == nullptr) {
            return;
        }
        else {
            Node<T> *temp = tail;
            while (temp->prev != nullptr) {
                temp->print();
                temp = temp->prev;
            }
        }
    }
    Node<T>* getWaypoint(int index) {
        if (index == 0) {
            return head;
        }
        else {
            Node<T> *temp = head;
            for (int i = 1; i < index; i++) {
                temp = temp->next;
            }
            return temp;
        }
    }
    void setWaypoint(int index, T& data);
    void print(){

            Node<T>* current = head;
            while (current) {
                current->print();
                current = current->next;
            }
            cout << endl;
        }

};

