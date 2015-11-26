#ifndef _LIST_H_
#define _LIST_H_

namespace Elis { template <class Object> class List; }

template <class Object>
class Elis::List {
    private:
        struct Node {
            Object data;
            Node* prev;
            Node* next;

            Node(const Object &d = Object(), Node* p = nullptr, Node* n = nullptr)
                : data(d), prev(p), next(n) { /* Empty */ }
        };

    public:
        class const_iterator {
            public:
                const_iterator();

                const Object & operator*() const;
                const_iterator & operator++();
                const_iterator & operator++(int);
                const_iterator operator--();
                const_iterator operator--(int);
                bool operator==(const const_iterator & rhs) const { return this->current == rhs.current; }
                bool operator!=(const const_iterator & rhs) const { return !(*this == rhs); }

            protected:
                Node* current;
                const_iterator(Node* p);
                friend class List<Object>;
        };

        class iterator : public const_iterator {
            public:
                iterator() {};

                const Object & operator*() const;
                Object & operator*();

                iterator & operator++();
                iterator operator++(int);
                iterator & operator--();
                iterator operator--(int);

            protected:
                iterator(Node* p);

                friend class List<Object>;
        };

        List();
        ~List();
        List(const List & list);
        const List & operator=(const List & list);

        iterator begin();
        const_iterator begin() const;
        iterator end();
        const_iterator end() const;
        int size() const;
        bool empty() const;
        void clear();
        Object & front() { return *begin(); }
        const Object & front() const;
        Object & back() { return *(--end()); }
        const Object & back() const;
        void push_front(const Object & x) { insert(begin(), x); };
        void push_back(const Object & x) { insert(end(), x); };
        void pop_front();
        void pop_back();
        iterator insert(iterator itr, const Object & x);
        iterator erase(iterator itr);
        iterator erase(iterator start, iterator end);
        const_iterator find(const Object & x) const;
        iterator find(const Object & x);

    private:
        int nodes;
        Node* head;
        Node* tail;

        void init();
};

#endif
