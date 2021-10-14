#include "head.h"
void LinkList::create() {
    head = new Node();
    head->next = NULL;
    head->value = 0;
}
void LinkList::insertHead(Node* p) {
    p->next = head->next;
    head->next = p;
    head->value++;
}
void LinkList::insertTail(Node* p) {
    Node* tail = findByIndex(head->value);
    if (tail == NULL)
        insertHead(p);
    else {
        p->next = tail->next;
        tail->next = p;
    }
    head->value++;
}
Node* LinkList::findByIndex(int index){
    Node* p = head;
    int i = 0;
    if (index<0||index >getLength()) {
        cout << "索引非法！" << endl;
        return NULL;
    }
    while (p) {
        if (i == index) 
            return p;
        else {
            p = p->next;
            i++;
        }
    }
    return NULL;
}
Node* LinkList::findByValue(int value) {
    Node* p = head->next;
    for (;p;p=p->next){
        if (p->value == value)
            return p;
    }
    return NULL;
}
int LinkList::getLength() {
    return head->value;
}
void LinkList::deleteByIndex(int index) {
    if (index == 0) {
        cout << "不能删除头节点！" << endl;
        return;
    }
    Node* p = findByIndex(index);
    if (!p) {
        cout << "删除失败！" << endl;
        return;
    }
    else {
        Node* q = findByIndex(index - 1);
        q->next = p->next;
        head->value--;
        delete p;
    }
}
void LinkList::deleteByValueOnce(int value) {
    Node* p = head->next;
    Node* q = head;
    bool flag = false;
    for (;p;p = p->next,q=q->next) {
        if (p->value == value) {
            q->next = p->next;
            delete p;
            flag = true;
            head->value--;
            break;
        }
    }
    if (!flag) {
        cout << "链表中不存在值为：" << value << "的节点" << endl;
    }
}
void LinkList::deleteByValueAll(int value) {
    Node* p = head->next;
    Node* q = head;
    bool flag = false;
    while(p){
        if (p->value == value) {
            q->next = p->next;
            Node* temp = p;
            p = p->next; //此处q不动，留给你们思考，不会再留言，嘻嘻
            delete temp;
            head->value--;
            flag = true;
        }
        else {
            p = p->next;
            q = q->next;
        }
    }
    if (!flag) {
        cout << "链表中不存在值为：" << value << "的节点" << endl;
    }
}
void LinkList::editByIndex(int index,int value) {
    if (index == 0) {
        cout << "不能修改头节点！" << endl;
        return;
    }
    Node* p = findByIndex(index);
    if (!p) {
        cout << "修改失败！" << endl;
        return;
    }
    else {
        p->value = value;
    }
}
void LinkList::print() {
    for (Node* p = head->next;p;p = p->next) {
        cout << p->value << " ";
    }
    cout << endl;
}