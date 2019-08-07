#ifndef LIST_H
#define LIST_H

#include<iostream>

template<class T>
class List {
private:
    class Nodo {
        public:
            T info;
            Nodo *prev,*next;
            Nodo(const T& t, Nodo* p=0, Nodo* n=0);
            ~Nodo();
    };
    Nodo *first, *last;
    unsigned int size;
     Nodo* copy(Nodo* fst, Nodo* pre, Nodo*& lst);
public:
    List();
    List(int, const T&);
    List(const List&);
    List& operator=(const List&);
    ~List();
    void pushFront(const T&);
    void pushBack(const T&);
    T& popFront();
    T& popBack();
    bool empty() const;
    unsigned int _size() const;
    void _clear();
    class iterator {
        friend class List<T>;
    private:
        Nodo* pt;
        bool pte; // true if past-the-end
    public:
        iterator(Nodo* p=nullptr, bool b=false);
        iterator& operator++();
        iterator operator++(int);
        iterator& operator+(unsigned int);
        iterator& operator+=(unsigned int);
        iterator& operator--();
        iterator operator--(int);
        iterator& operator-(unsigned int);
        iterator& operator-=(unsigned int);
        T& operator*() const;
        T* operator->() const;
        bool operator==(const iterator& x) const;
        bool operator!=(const iterator& x)const;
    };

    class constiterator {
        friend class List<T>;
    private:
        const Nodo* pt;
        bool pte; // true if past-the-end
    public:
        constiterator(Nodo* p=nullptr, bool b=false);
        constiterator& operator++();
        constiterator operator++(int);
        constiterator& operator+(unsigned int);
        constiterator& operator+=(unsigned int);
        constiterator& operator--();
        constiterator operator--(int);
        constiterator& operator-(unsigned int);
        constiterator& operator-=(unsigned int);
        const T& operator*() const;
        const T* operator->() const;
        bool operator==(const constiterator& x) const;
        bool operator!=(const constiterator& x) const;
    };
        iterator begin() const;
        iterator end() const;
        iterator ptend() const;
        constiterator cbegin() const;
        constiterator cend() const;
        constiterator cptend() const;
        void erase(iterator);
        void erase(const T&,iterator,iterator);
};

/****** Nodo ******/
template<class T>
List<T>::Nodo::Nodo(const T& t, Nodo* p, Nodo* n): info(t), prev(p), next(n) {}
template<class T>
List<T>::Nodo::~Nodo() {
    if(next){    
        delete next;
    }
}

/****** List ******/
template<class T>
typename List<T>::Nodo* List<T>::copy(Nodo* fst, Nodo* pre, Nodo*& lst){
    if(fst == nullptr) {
    lst = nullptr;
    return nullptr;
    }
    Nodo* temp = new Nodo(fst->info,pre,nullptr);
    temp->next = copy(fst->next,temp,lst);
    if(fst->next == nullptr) lst=temp;
    return temp;
}

template<class T>
List<T>::List(): first(nullptr), last(nullptr),size(0){}

template<class T>
List<T>::List(int k, const T& t): first(nullptr), last(nullptr),size(0) {
    for(int i=0; i<k; ++i) pushBack(t);
}

template<class T>
List<T>::List(const List& dl) {
    first = copy(dl.first,dl.first->prev,last);
    size=dl.size;
}

template<class T>
List<T>& List<T>::operator=(const List& dl) {
    if(this != &dl) {
    if(first) delete first;
    first=copy(dl.first,dl.first->prev,last);
    }
    return *this;
}

template<class T>
List<T>::~List() {
    if(first) delete first;
}

template<class T>
void List<T>::pushFront(const T& t) {
    first = new Nodo(t,nullptr,first);
    if(last == nullptr) {last = first;}
    else {(first->next)->prev = first;}
    size++;
}

template<class T>
void List<T>::pushBack(const T& t) {
    last = new Nodo(t,last,nullptr);
    if(first == nullptr) {first = last;}
    else {(last->prev)->next = last;}
    size++;
}

template<class T>
T& List<T>::popFront(){
    Nodo* tmp=first;
    Nodo* dlt=tmp;
    dlt->next=nullptr;
    delete dlt;
    if(size==1){
      first=nullptr;
   }
   else{
       first=first->next;
        first->prev=tmp->prev;
   }    
    size--;
    return tmp->info;
}

template<class T>
T& List<T>::popBack(){
     Nodo* tmp=last;
    Nodo* dlt=tmp;
    dlt->next=nullptr;
    delete dlt;
    if(size==1){
        first=nullptr;
    }
    else{
        last=last->prev;
        last->next=tmp->next;
   }    
    size--;
    return tmp->info;
}

template<class T>
bool List<T>::empty() const{
    return first==nullptr;
}

template<class T>
unsigned int List<T>::_size() const{
    return size;
}

template<class T>
void List<T>::erase(iterator it){//elimina it
    if(size>1){
        Nodo* pt=it.pt;//per amicizia
        Nodo* tmp;
        if(pt==first){
             first=first->next;
             first->prev=pt->prev;
             pt->next=0;
             pt->prev=0;
        }
        else if(pt==last){
             last=last->prev;
             last->next=pt->next;
             pt->next=0;
             pt->prev=0;
        }
        else{
            tmp=pt;
            tmp=tmp->prev;
            tmp->next=pt->next;
            tmp->next->prev=tmp;
            pt->next=0;
            pt->prev=0;
        }
        delete pt;
    }
    else{
        delete first;
        first=nullptr;
        last=nullptr;
    }
    size--;


}

template<class T>
void List<T>::erase(const T& val,iterator ifirst,iterator ilast){//elimina tutte le occorenze con info==val
   while (ifirst!=ilast) {
        if (*ifirst==val){
            erase(ifirst);
        }
    ++ifirst;
    }
    if (*ifirst==val){
        erase(ifirst);
    }
}

template<class T>
void List<T>::_clear() {
    if(first!=nullptr){
         delete first;
         first=nullptr;
    }
}
/****** Iterator ******/

template<class T>
List<T>::iterator::iterator(Nodo* p, bool b): pt(p), pte(b) {}

template<class T>
typename List<T>::iterator& List<T>::iterator::operator++(){
    if(!pte && pt) {
        if(pt->next == nullptr) {pt = pt+1; pte=true;}
        else pt = pt->next;
    }
    return *this;
}

template<class T>
typename List<T>::iterator List<T>::iterator::operator++(int){
    iterator aux=*this;
    if(!pte && pt) {
        if(pt->next == nullptr) {pt = pt+1; pte=true;}
        else pt = pt->next;
    }
    return aux;
}

template<class T>
typename List<T>::iterator& List<T>::iterator::operator+(unsigned int k){
    while(!pte && pt && k>0) {
        if(pt->next == nullptr) {pt = pt+1; pte=true;}
        else pt = pt->next;
        k--;
    }
    return *this;
}

template<class T>
typename List<T>::iterator& List<T>::iterator::operator+=(unsigned int k){
    while(!pte && pt && k>0) {
        if(pt->next == nullptr) {pt = pt+1; pte=true;}
        else pt = pt->next;
        k--;
    }
    return *this;
}

template<class T>
typename List<T>::iterator& List<T>::iterator::operator--() {
    if(pte) {pt = pt-1; pte=false;} 
    else if(pt) {pt = pt->prev;}
    return *this;
}

template<class T>
typename List<T>::iterator List<T>::iterator::operator--(int){
    iterator aux=*this;
    if(pte) {pt = pt-1; pte=false;} 
    else if(pt) {pt = pt->prev;}
    return aux;
}

template<class T>
typename List<T>::iterator& List<T>::iterator::operator-(unsigned int k) {
    while(k>0){
        if(pte) {pt = pt-1; pte=false;} 
        else if(pt) {pt = pt->prev;}
        k--;
    }   
    return *this;
}

template<class T>
typename List<T>::iterator& List<T>::iterator::operator-=(unsigned int k) {
    while(k>0){
        if(pte) {pt = pt-1; pte=false;} 
        else if(pt) {pt = pt->prev;}
        k--;
    }   
    return *this;
}

template<class T>
T& List<T>::iterator::operator*() const {
    return pt->info;
}

template<class T>
T* List<T>::iterator::operator->() const {
    return &(pt->info);
}

template<class T>
bool List<T>::iterator::operator==(const iterator& x) const {
    return pt == x.pt;
}

template<class T>
bool List<T>::iterator::operator!=(const iterator& x) const {
    return pt != x.pt;
}

/****** ConstIterator ******/

template<class T>
List<T>::constiterator::constiterator(Nodo* p, bool b): pt(p), pte(b) {}

template<class T>
typename List<T>::constiterator& List<T>::constiterator::operator++() {
    if(!pte && pt) {
    if(pt->next == nullptr) {pt = pt+1; pte=true;}
    else pt = pt->next;
    }
    return *this;
}

template<class T>
typename List<T>::constiterator List<T>::constiterator::operator++(int){
    constiterator aux=*this;
    if(!pte && pt) {
    if(pt->next == nullptr) {pt = pt+1; pte=true;}
    else pt = pt->next;
    }
    return aux;
}

template<class T>
typename List<T>::constiterator& List<T>::constiterator::operator+(unsigned int k){
    while(!pte && pt && k>0) {
        if(pt->next == nullptr) {pt = pt+1; pte=true;}
        else pt = pt->next;
        k--;
    }
    return *this;
}

template<class T>
typename List<T>::constiterator& List<T>::constiterator::operator+=(unsigned int k){
    while(!pte && pt && k>0) {
        if(pt->next == nullptr) {pt = pt+1; pte=true;}
        else pt = pt->next;
        k--;
    }
    return *this;
}

template<class T>
typename List<T>::constiterator& List<T>::constiterator::operator--() {
    if(pte) {pt = pt-1; pte=false;} 
    else if(pt) {pt = pt->prev;}
    return *this;
}

template<class T>
typename List<T>::constiterator List<T>::constiterator::operator--(int){
    constiterator aux=*this;
    if(pte) {pt = pt-1; pte=false;} 
    else if(pt) {pt = pt->prev;}
    return aux;
}

template<class T>
typename List<T>::constiterator& List<T>::constiterator::operator-(unsigned int k) {
    while(k>0){
        if(pte) {pt = pt-1; pte=false;} 
        else if(pt) {pt = pt->prev;}
        k--;
    }   
    return *this;
}

template<class T>
typename List<T>::constiterator& List<T>::constiterator::operator-=(unsigned int k) {
    while(k>0){
        if(pte) {pt = pt-1; pte=false;} 
        else if(pt) {pt = pt->prev;}
        k--;
    }   
    return *this;
}
template<class T>
const T& List<T>::constiterator::operator*() const {
    return pt->info;
}
template<class T>
const T* List<T>::constiterator::operator->() const {
    return &(pt->info);
}
template<class T>
bool List<T>::constiterator::operator==(const constiterator& x) const {
    return pt == x.pt;
}
template<class T>
bool List<T>::constiterator::operator!=(const constiterator& x) const {
    return pt != x.pt;
}

/****** Iterator/constiterator begin/end ******/


template<class T>
typename List<T>::iterator List<T>::begin() const {
    return iterator(first);
}

template<class T>
typename List<T>::iterator List<T>::end() const {//ritorna ultimo elemento prima del pte
    if(first==nullptr) return iterator(nullptr);
    return iterator(last);
}

template<class T>
typename List<T>::iterator List<T>::ptend() const {//ritorna past the end
    if(first==nullptr) return iterator(nullptr);
    return iterator(last+1,true);
}

template<class T>
typename List<T>::constiterator List<T>::cbegin() const {
    return constiterator(first);
}

template<class T>
typename List<T>::constiterator List<T>::cend() const {//ritorna ultimo elemento prima del pte
    if(first==nullptr) return constiterator(nullptr);
    return constiterator(last);
}

template<class T>
typename List<T>::constiterator List<T>::cptend() const {//ritorna past the end
    if(first==nullptr) return constiterator(nullptr);
    return constiterator(last+1,true);
}

#endif /* LIST_H */
