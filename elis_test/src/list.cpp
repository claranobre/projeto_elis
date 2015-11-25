#include "list.h"

#include <iostream>

template <class Object>
Elis::List<Object>::List()
{
    init();
}

template <class Object>
Elis::List<Object>::List(const List & list)
    : nodes(list.size()), head(list.head), tail(list.tail) {}

template <class Object>
Elis::List<Object>::~List()
{
    delete head;
    delete tail;
}

template <class Object>
const Elis::List<Object> &
Elis::List<Object>::operator=(const List & list)
{
    nodes = list.nodes;
    head = list.head;
    tail = list.tail;

    return *this;
}

template <class Object>
typename Elis::List<Object>::iterator Elis::List<Object>::begin()
{
    return Elis::List<Object>::iterator(head->next);
}

template <class Object>
typename Elis::List<Object>::const_iterator
Elis::List<Object>::begin() const
{
    return Elis::List<Object>::const_iterator(head->next);
}

template <class Object>
typename Elis::List<Object>::iterator
Elis::List<Object>::end()
{
    return Elis::List<Object>::iterator(tail);
}

template <class Object>
typename Elis::List<Object>::const_iterator
Elis::List<Object>::end() const
{
    return Elis::List<Object>::const_iterator(tail);
}

template <class Object>
int Elis::List<Object>::size() const
{
    return nodes;
}

template <class Object>
bool Elis::List<Object>::empty() const
{
    return nodes == 0;
}

template <class Object>
void Elis::List<Object>::clear()
{
    Elis::List<Object>::iterator itr;

    for (itr = begin(); itr != end(); ++itr)
        delete *itr;

    nodes = 0;
}

template <class Object>
typename Elis::List<Object>::iterator
Elis::List<Object>::insert(Elis::List<Object>::iterator itr, const Object & x)
{
    auto next_node = itr.current;
    auto prev_node = next_node->prev;
    auto new_node = new Node(x, prev_node, next_node);

    prev_node->next = new_node;
    next_node->prev = new_node;

    nodes++;

    return Elis::List<Object>::iterator(new_node);
}

template <class Object>
typename Elis::List<Object>::iterator
Elis::List<Object>::erase(Elis::List<Object>::iterator itr)
{
    return nullptr;
}

template <class Object>
typename Elis::List<Object>::iterator
Elis::List<Object>::erase(Elis::List<Object>::iterator start, Elis::List<Object>::iterator end)
{
    return nullptr;
}

template <class Object>
typename Elis::List<Object>::const_iterator
Elis::List<Object>::find(const Object & x) const
{
    Elis::List<Object>::const_iterator const_itr;

    for (auto itr = begin(); itr != end(); ++itr)
        if (*itr == x) const_itr = itr;

    return const_itr;
}

template <class Object>
typename Elis::List<Object>::iterator
Elis::List<Object>::find(const Object & x)
{
    return nullptr;
}

template <class Object>
void
Elis::List<Object>::pop_front()
{
    auto poped_node = head->next;
    auto next_node = poped_node->next;

    head->next = poped_node->next;
    next_node->prev = head;

    --nodes;
}

template <class Object>
void
Elis::List<Object>::pop_back()
{
    auto poped_node = tail->prev;
    auto prev_node = poped_node->prev;

    prev_node->next = tail;
    tail->prev = prev_node;

    --nodes;
}

template <class Object>
void
Elis::List<Object>::init()
{
    nodes = 0;

    head = new Node();
    tail = new Node();

    head->next = tail;
    tail->prev = head;
}

// const_iterator
// ----------------------------------------------------------------------------

template <class Object>
Elis::List<Object>::const_iterator::const_iterator()
    : current(nullptr) {}


template <class Object>
const Object &
Elis::List<Object>::const_iterator::operator*() const
{
    return this->current->data;
}

template <class Object>
typename Elis::List<Object>::const_iterator &
Elis::List<Object>::const_iterator::operator++()
{
    this->current = this->current->next;

    return *this;
}

template <class Object>
typename Elis::List<Object>::const_iterator &
Elis::List<Object>::const_iterator::operator++(int)
{
    auto itr = *this;

    this->current = this->current->next;

    return itr;
}

template <class Object>
typename Elis::List<Object>::const_iterator
Elis::List<Object>::const_iterator::operator--()
{
    return Elis::List<Object>::const_iterator(this->current->prev);
}

template <class Object>
typename Elis::List<Object>::const_iterator
Elis::List<Object>::const_iterator::operator--(int)
{
    return Elis::List<Object>::const_iterator(this->current->prev);
}

template <class Object>
Elis::List<Object>::const_iterator::const_iterator(Elis::List<Object>::Node* p)
    : current(p) {}


// iterator
// ----------------------------------------------------------------------------

template <class Object>
const Object &
Elis::List<Object>::iterator::operator*() const
{
    return this->current->data;
}

template <class Object>
Object &
Elis::List<Object>::iterator::operator*()
{
    return this->current->data;
}

template <class Object>
typename Elis::List<Object>::iterator &
Elis::List<Object>::iterator::operator++()
{
    this->current = this->current->next;

    return *this;
}

template <class Object>
typename Elis::List<Object>::iterator
Elis::List<Object>::iterator::operator++(int)
{
    auto itr = *this;

    this->current = this->current->next;

    return itr;
}

template <class Object>
typename Elis::List<Object>::iterator &
Elis::List<Object>::iterator::operator--()
{
    this->current = this->current->prev;

    return *this;
}

template <class Object>
typename Elis::List<Object>::iterator
Elis::List<Object>::iterator::operator--(int)
{
    auto itr = *this;

    this->current = this->current->prev;

    return itr;
}

template <class Object>
Elis::List<Object>::iterator::iterator(Elis::List<Object>::Node* p)
{
    this->current = p;
}
