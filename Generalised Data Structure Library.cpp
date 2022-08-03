//Data Structure
#include<iostream>
using namespace std;

//Singly linear LL structure
template<class T>
struct slnode
{
    T data;
    struct slnode *next;
};

//Singly circular LL structure
template<class T>
struct scnode
{
    T data;
    struct scnode *next;
};

//Doubly linear LL structure
template<class T>
struct dlnode
{
    T Data;
    struct dlnode* Next;
    struct dlnode* Prev;
};

//Doubly circular LL structure
template<class T>
struct dcnode
{
    T data;
    struct dcnode *next;
    struct dcnode* prev;
};

//Queue structure
template<class T>
struct qnode
{
    T data;
    struct qnode *next;
};

// Stack Structure
template<class T>
struct stnode
{
    T data;
    struct stnode *next;
};

//Binary search tree structure
template<class T>
struct bstnode
{
    T data;
    struct bstnode *lchild;
    struct bstnode *rchild;
};



//Singly LL using Generic Programming
template<class T>
class SinglyLL
{
    private:
        struct slnode<T> *Head;       //*
        int Count;

    public:
    SinglyLL();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPosition(int,T);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPosition(int);
    void Display();
    int CountNode();

};

template<class T>
SinglyLL<T>::SinglyLL()
{
    Head = NULL;
    Count = 0;
}

template<class T>
void SinglyLL<T>::InsertFirst(T no)
{
    struct slnode <T>*newn = NULL;            //*
    newn = new slnode<T>;                     //*

    newn -> data = no;
    newn -> next = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        newn -> next = Head;
        Head = newn;
    }
    Count++;
}

template<class T>
void SinglyLL<T>::InsertLast(T no)
{
    struct slnode <T>*newn = NULL;            //*
    newn = new slnode<T>;                     //*

    newn -> data = no;
    newn -> next = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
      struct slnode<T> *temp  = Head;
      while(temp -> next !=NULL)
      {
            temp = temp -> next;
      }
      temp -> next = newn;
    }
    Count++;
}

template<class T>
void SinglyLL<T>::Display()
{
        cout<<endl;
        cout<<"List of Nodes in Singly Linear LinkedLst are: ";
   struct slnode<T> *temp  = Head;

    while(temp !=NULL)
      {
           cout<<"|"<<temp->data<<"|->";
            temp = temp -> next;
      }
       cout<< "NULL\n";
    }


template<class T>
int SinglyLL<T>::CountNode()
{
    return Count;
}

template<class T>
void SinglyLL<T> :: InsertAtPosition(int pos, T no)
{
    if((Head == NULL) || (pos > CountNode()+1) ||(pos <= 0))
    {
        return ;
    }
    if(pos == 1)
    {
        return (InsertFirst(no));
    }
    else if(pos == (CountNode())+1)
    {
        return InsertLast(no);
    }
    else
    {
        struct slnode<T> *newn = NULL;
        struct slnode <T>* Temp = Head;
        newn = new slnode<T>;
        if(newn == NULL)
        {
            return;
        }
        newn -> data = no;
        newn -> next = NULL;

        for(int i = 1; i < (pos-1); i++)
        {
            Temp = Temp -> next;
        }
        newn -> next = Temp -> next;
        Temp -> next = newn;
    }
        Count++;
}

template<class T>
void SinglyLL<T> :: DeleteFirst()
{
    struct slnode<T> *Temp = Head;

    if(Head == NULL)
    {
        return ;
    }
    else
    {
        Head = Head -> next;
        delete(Temp);
    }
    Count--;
}

template<class T>
void SinglyLL<T>:: DeleteLast()
{
    if(Head == NULL)
    {
        return;
    }
    if(Head -> next == NULL)
    {
        delete Head;
        Head == NULL;
    }
    else
    {
        struct slnode<T> *Temp1 = Head;
         struct slnode<T> *Temp2 = NULL;

        while(Temp1 -> next -> next != NULL)
        {
            Temp1 = (Temp1 -> next);
        }
        Temp2 = Temp1 -> next;
        Temp1 -> next = NULL;
        delete Temp2;
    }
    Count--;
}

template<class T>
void SinglyLL<T> :: DeleteAtPosition(int pos)
{
    if((Head == NULL) || (pos > CountNode()) ||(pos <= 0))
    {
        return ;
    }
    if(pos == 1)
    {
        return (DeleteFirst());
    }
    else if(pos == (CountNode()))
    {
        return DeleteLast();
    }
    else
    {
        struct slnode <T>* Temp1 = Head;
        struct slnode <T>* Temp2 = NULL;

        for(int i = 1; i < (pos-1); i++)
        {
            Temp1 = Temp1 -> next;
        }
         Temp2 = Temp1 -> next;
         Temp1 -> next = Temp2 ->next;;
         delete Temp2;
    }
        Count--;
}

// Singly circular linkedlist (C++) Generic Programming

template<class T>
class SinglyCLL
{
    private:        // characteristics
        struct scnode<T> *Head;
        struct scnode<T> * Tail;
        int Count;

    public:         // Behaviours
    SinglyCLL();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPosition(T,int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPosition(int);
    void Display();
    int CountNode();
};

    template<class T>
    SinglyCLL<T> :: SinglyCLL()
     {
         Head = NULL;
         Tail = NULL;
         Count = 0;
     }

   template<class T>
   void SinglyCLL<T> :: InsertFirst(T no)
    {
       struct scnode <T>*newn = NULL;
        newn  = new scnode<T>;

        newn -> data = no;
        newn -> next = NULL;

        if((Head == NULL) && (Tail == NULL))
        {
            Head = newn;
            Tail = newn;
        }
        else
        {
            newn -> next = Head;
            Head = newn;
        }
        Tail -> next = Head;
        Count++;
    }

   template<class T>
   void SinglyCLL<T> :: InsertLast(T no)
    {
       struct scnode <T>* newn = NULL;
        newn  = new scnode<T>;

        newn -> data = no;
        newn -> next = NULL;

        if((Head == NULL) && (Tail == NULL))
        {
            Head = newn;
            Tail = newn;
        }
        else
        {
            Tail-> next = newn;
            Tail = newn;

        }
        Tail -> next = Head;
        Count++;
    }

   template<class T>
   void SinglyCLL<T> :: InsertAtPosition(T no, int ipos)
    {
        int iSize = CountNode();
        if((ipos < 1) || (ipos > iSize+1))
        {
            return;
        }
        if(ipos == 1)
        {
            InsertFirst(no);
        }
        else if(ipos == iSize +1)
        {
            InsertLast(no);
        }
        else
        {
          struct scnode <T>* newn = NULL;
          newn  = new scnode<T>;

          newn -> data = no;
          newn -> next = NULL;

        struct scnode <T>* temp = Head;
        int iCnt = 0;

        for(iCnt = 1; iCnt < ipos -1; iCnt++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp -> next = newn;
        }
        Count++;
    }

    template<class T>
    void SinglyCLL<T> :: DeleteFirst()
    {
        if(Head == NULL && Tail == NULL)
        {
            return;
        }
        else if(Head == Tail)
        {
            delete Head;  // delete Tail;
            Head = NULL;
            Tail = NULL;
        }
        else
        {
            Head = Head -> next;
            delete Tail-> next;
        }
        Tail -> next = Head;
        Count--;
    }

    template<class T>
    void SinglyCLL<T> :: DeleteLast()
    {
        if(Head == NULL && Tail == NULL)
        {
            return;
        }
        else if(Head == Tail)
        {
            delete Head;  // delete Tail;
            Head = NULL;
            Tail = NULL;
        }
        else
        {
            struct scnode<T> *temp = Head;

            while(temp-> next != Tail)
             {
                temp = temp -> next;
             }
             delete temp -> next; // delete Tail;
             Tail = temp;
        }
         Tail -> next = Head;
         Count--;
    }

    template<class T>
    void SinglyCLL<T> :: DeleteAtPosition(int ipos)
    {
         int iSize = CountNode();
        if((ipos < 1) || (ipos > iSize))
        {
            cout<<"Invalid Position";
            return;
        }
        if(ipos == 1)
        {
            DeleteFirst();
        }
        else if(ipos == iSize)
        {
            DeleteLast();
        }
        else
        {
          struct scnode <T> *temp1 = Head;
          int iCnt = 0;

          for(iCnt = 1; iCnt < ipos -1; iCnt++)
          {
              temp1 = temp1 -> next;
          }
            struct scnode <T> *temp2 = temp1 -> next;
            temp1 -> next = temp2 -> next;
            delete temp2;
        }

    }

    template<class T>
    void SinglyCLL<T> :: Display()
    {
        struct scnode<T> * temp = Head;

        if(Head == NULL && Tail ==NULL)
        {
            return;
        }
         cout<<endl;
        cout<<"List of Nodes in Singly Circular LinkedLst are: ";
       do
        {
            cout<<" |"<<temp-> data<<"|->";
            temp = temp -> next;
        } while(temp != Tail->next);   //(temp != Head);

        cout<<endl;
    }

    template<class T>
    int SinglyCLL<T> :: CountNode()
    {
        return Count;
    }

// Doubly Linear LinkedList in C++.

template<class T>
class Doubly_linkedList
{
    private:
        struct dlnode<T> *Head;
        int Count;

    public:
        Doubly_linkedList();
        ~Doubly_linkedList();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPosition(T,int);
        inline void Display();
        inline int CountNode();
        void DeleteFirst();
        void DeleteAtPosition(int);
        void DeleteLast();
};

template<class T>
Doubly_linkedList<T> :: Doubly_linkedList()
{
    Head = NULL;
    Count = 0;
}

template<class T>
Doubly_linkedList<T> :: ~Doubly_linkedList()
{
    struct dlnode <T>*Temp = Head;

    if(Head != NULL)
    {
        while(Head != NULL)
        {
            Head = Head -> Next;
            delete Temp;
            Temp = Head;
        }
    }
}

 template<class T>
 void Doubly_linkedList<T> :: InsertFirst(T no)
{
    struct dlnode <T>* newn = NULL;

    newn = new dlnode<T>;

    if(newn == NULL)
    {
        return;
    }

    newn -> Data = no;
    newn -> Next = NULL;
    newn -> Prev = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        newn -> Next = Head;
        Head -> Prev = newn;
        Head = newn;
    }
    Count++;
}

 template<class T>
 void Doubly_linkedList<T> :: InsertLast(T no)
 {
    struct dlnode <T>* newn = NULL;
     struct dlnode <T>*Temp = Head;

    newn = new dlnode<T>;

    if(newn == NULL)
    {
        return;
    }

    newn -> Data = no;
    newn -> Next = NULL;
    newn -> Prev = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
        while(Temp -> Next != NULL)
        {
            Temp = Temp -> Next;
        }
        Temp -> Next = newn;
        newn -> Prev = Temp;
    }
    Count++;
 }

template<class T>
void Doubly_linkedList<T> :: InsertAtPosition(T no, int pos)
{
    if((Head == NULL) || (pos > CountNode()+1) || (pos <= 0))
    {
        return;
    }
    if(pos ==1 )
    {
        return(InsertFirst(no));
    }
    else if(pos == CountNode()+1)
    {
        return(InsertLast(no));
    }
    else
    {
         struct dlnode<T> *newn = NULL;
         struct dlnode<T> *Temp = Head;

        newn = new dlnode<T>;

        if(newn == NULL)
        {
            return;
        }

        newn -> Data = no;
        newn -> Next = NULL;
        newn -> Prev = NULL;

        for(int i = 1; i < (pos-1); i++)
        {
            Temp = Temp -> Next;
        }
        newn -> Next = Temp -> Next;
        Temp -> Next -> Prev = newn;
        newn -> Prev = Temp;
        Temp -> Next = newn;
    }
    Count++;
}

template<class T>
void Doubly_linkedList<T> :: DeleteFirst()
{
    struct dlnode<T> *Temp = Head;

    if(Head == NULL)
    {
        return;
    }
    else
    {
        Head = Head -> Next;
        Head -> Prev = NULL;

        delete Temp;
    }
    Count--;
}

template<class T>
void Doubly_linkedList<T> :: DeleteLast()
{
    struct dlnode<T> *Temp = Head;

    if(Head == NULL)
    {
        return;
    }
   if(Head -> Next == NULL)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        while((Temp -> Next) != NULL)  // while(Temp1 -> Next -> Next != NULL)
        {
            Temp = Temp -> Next;
        }
                                        //Temp2 = Temp1 -> Next;
        Temp -> Prev -> Next = NULL;   // Temp1 -> Next = NULL;
        delete Temp;                   // delete Temp2;
    }
    Count--;
}

template<class T>
void Doubly_linkedList<T> :: DeleteAtPosition(int pos)
{
    if((Head == NULL) || (pos > CountNode()) || (pos <= 0))
    {
        return;
    }
    if(pos ==1 )
    {
        return(DeleteFirst());
    }
    else if(pos == CountNode()+1)
    {
        return(DeleteLast());
    }
    else
    {
        struct dlnode<T> * Temp = Head;

        for(int i = 1; i <= (pos-2); i++)
        {
            Temp = Temp -> Next;
        }
        Temp -> Next = Temp -> Next -> Next;
        delete (Temp -> Next -> Prev);
        Temp -> Next -> Prev = Temp;
    }
    Count--;
}

template<class T>
void Doubly_linkedList<T> :: Display()
{
    struct dlnode<T> * Temp = Head;
    cout<<"\nList of Nodes in Doubly Linear LinkedList are: ";
    while(Temp != NULL)
    {
        cout<<"|"<<Temp-> Data<<"|->";
        Temp = Temp -> Next;
    }
    cout<< "NULL\n";
}

template<class T>
int Doubly_linkedList<T> :: CountNode()
{
    return Count;
}

// Doubly circular linkedlist (C++) Generic Programming

template<class T>
class DoublyCLL
{
    private:        // characteristics
        struct dcnode<T> *Head;
        struct dcnode<T> *Tail;
        int Count;

    public:         // Behaviours
    DoublyCLL();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPosition(int, T);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPosition(int);
    void Display();
    int CountNode();
};
    template<class T>
    DoublyCLL<T> :: DoublyCLL()
     {
         Head = NULL;
         Tail = NULL;
         Count = 0;
     }

   template<class T>
   void DoublyCLL<T> :: InsertFirst(T no)
    {
        struct dcnode <T>* newn = NULL;
        newn  = new dcnode<T>;

        newn -> data = no;
        newn -> next = NULL;
        newn -> prev = NULL;

        if((Head == NULL) && (Tail == NULL))
        {
            Head = newn;
            Tail = newn;
        }
        else
        {
            Head -> prev = newn;
            newn -> next = Head;
            Head = newn;
            Head -> prev = Tail;
        }
        Tail -> next = Head;
        Count++;
    }

   template<class T>
   void DoublyCLL<T> :: InsertLast(T no)
    {
        struct dcnode<T> *newn = NULL;
        newn  = new dcnode<T>;

        newn -> data = no;
        newn -> next = NULL;
       newn -> prev = NULL;

        if((Head == NULL) && (Tail == NULL))
        {
            Head = newn;
            Tail = newn;
        }
        else
        {
            Tail -> next = newn;
            newn -> prev = Tail;
            Tail = newn;
            Head -> prev = Tail;
        }
        Tail -> next = Head;
        Count++;
    }

   template<class T>
   void DoublyCLL<T> :: InsertAtPosition(int ipos, T no)
    {
        int iSize = CountNode();
        if((ipos < 1) || (ipos > iSize+1))
        {
            return;
        }
        if(ipos == 1)
        {
            InsertFirst(no);
        }
        else if(ipos == iSize +1)
        {
            InsertLast(no);
        }
        else
        {
          struct dcnode <T>* newn = NULL;
          newn  = new dcnode<T>;

          newn -> data = no;
          newn -> next = NULL;
          newn -> prev = NULL;

        struct dcnode <T> *temp = Head;
        int iCnt = 0;

        for(iCnt = 1; iCnt < ipos -1; iCnt++)
        {
            temp = temp -> next;
        }
        newn -> prev = temp;
        newn -> next = temp -> next;
        temp -> next -> prev = newn;
        temp -> next = newn;
        }
        Count++;
    }

    template<class T>
    void DoublyCLL<T> :: DeleteFirst()
    {
        if(Head == NULL && Tail == NULL)
        {
            return;
        }
        else if(Head == Tail)
        {
            delete Head;  // delete Tail;
            Head = NULL;
            Tail = NULL;
        }
        else
        {
            Head = Head -> next;
            Head -> prev = Tail;
            delete Tail-> next;
        }
        Tail -> next = Head;
        Count--;
    }

     template<class T>
    void DoublyCLL<T> :: DeleteLast()
    {
        if(Head == NULL && Tail == NULL)
        {
            return;
        }
        else if(Head == Tail)
        {
            delete Head;  // delete Tail;
            Head = NULL;
            Tail = NULL;
        }
        else
        {
            struct dcnode <T> *temp = Head;

            while(temp-> next != Tail)
             {
                temp = temp -> next;
             }
             delete temp -> next; // delete Tail;
             Tail = temp;
             Head -> prev = Tail;
        }
        Tail -> next = Head;
        Count--;
    }

    template<class T>
    void DoublyCLL<T> :: DeleteAtPosition(int ipos)
    {
         int iSize = CountNode();
        if((ipos < 1) || (ipos > iSize))
        {
            cout<<"Invalid Position";
            return;
        }
        if(ipos == 1)
        {
            DeleteFirst();
        }
        else if(ipos == iSize)
        {
            DeleteLast();
        }
        else
        {
          struct dcnode <T> *temp1 = Head;
          int iCnt = 0;

          for(iCnt = 1; iCnt < ipos -1; iCnt++)
          {
              temp1 = temp1 -> next;
          }
            struct dcnode <T> *temp2 = temp1 -> next;
            temp1 -> next = temp2 -> next;
            delete temp2;
            temp1 -> next -> prev = temp1;
        }
        Count--;
    }
    template<class T>
    void DoublyCLL<T> :: Display()
    {
        struct dcnode <T> *temp = Head;
        cout<<"\nList of Nodes in Doubly Circular LinkedList are: ";
        if(Head == NULL && Tail ==NULL)
        {
            return;
        }

       do
        {
            cout<<" |"<<temp-> data<<"|->";
            temp = temp -> next;
        } while(temp != Tail->next);   //(temp != Head);

        cout<<endl;
    }

    template<class T>
    int DoublyCLL<T> :: CountNode()
    {
        return Count;
    }

// Queue Data Structure programs using Generic programming.

template<class T>
class Queue
{
    private:
        struct qnode<T> *Head;       //*
        int Count;

    public:
    Queue();
    void Enqueue(T);       //InsertLast()
    void Dequeue();           // DeleteFirst()
    void Display();
    int CountNode();
};

template<class T>
Queue<T>::Queue()
{
    Head = NULL;
    Count = 0;
}

template<class T>
void Queue<T>::Enqueue(T no)
{
    struct qnode <T>*newn = NULL;            //*
    newn = new qnode<T>;                     //*

    newn -> data = no;
    newn -> next = NULL;

    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
      struct qnode<T> *temp  = Head;
      while(temp -> next !=NULL)
      {
            temp = temp -> next;
      }
      temp -> next = newn;
    }
    Count++;
}

template<class T>
void Queue<T> :: Dequeue()   //DeleteFirst
{
    T no;

    if(Count == 0)         //(Head == NULL)
    {
        cout<<"Queue is Empty"<<endl;
        return;
    }

        no = Head -> data;
        struct qnode<T> *temp = Head;
        Head = Head -> next;
        delete temp;

        Count--;
        cout<<"Removed element is: "<<no<<endl;
}


template<class T>
void Queue<T>::Display()
{
        cout<<"List of Nodes in Queue are: ";
   struct qnode<T> *temp  = Head;

    while(temp !=NULL)
      {
           cout<<"|"<< temp->data<< "|->" <<" ";
            temp = temp -> next;
      }
       cout<<"NULL";
       cout<<endl;
    }


template<class T>
int Queue<T>::CountNode()
{
    return Count;
}

// Stack Data Structure programs using Generic programming.

template<class T>
class Stack
{
    private:
        struct stnode<T> *Head;       //*
        int Count;

    public:
    Stack();
    void Push(T);       //InsertFirst()
    void Pop();           // DeleteFirst()
    void Display();
    int CountNode();
};

template<class T>
Stack<T>::Stack()
{
    Head = NULL;
    Count = 0;
}

template<class T>
void Stack<T>::Push(T no)
{
    struct stnode <T>*newn = NULL;            //*
    newn = new stnode<T>;                     //*

    newn -> data = no;
    newn -> next = NULL;

   newn -> next = Head;  // used to handle empty and full stack also.
   Head = newn;
    Count++;
}

template<class T>
void Stack<T> :: Pop()   //DeleteFirst
{
    T no;

    if(Count == 0)         //(Head == NULL)
    {
        cout<<"Stack is Empty"<<endl;
        return;
    }

        no = Head -> data;
        struct stnode<T> *temp = Head;
        Head = Head -> next;
        delete temp;

        Count--;
        cout<<"Removed element is: "<<no<<endl;
}


template<class T>
void Stack<T>::Display()
{
        cout<<"List of Nodes in Stack are: ";
   struct stnode<T> *temp  = Head;

    while(temp !=NULL)
      {
           cout<<"|"<< temp->data<<"|->";
            temp = temp -> next;
      }
       cout<<"NULL";
       cout<<endl;
    }


template<class T>
int Stack<T>::CountNode()
{
    return Count;
}

// Binary Search tree Data Structure programs using Generic programming.


template<class T>
class BST
{
     private:
        int Count;

     public:
       BST();
       void Insert(struct bstnode<T> **,T);
       void Inorder(struct bstnode<T> *);
       void Preorder(struct bstnode<T> *);
       void Postorder(struct bstnode<T> *);
       void Search(struct bstnode<T> *,T);
       int CountNode();
       int CountLeafNode(struct bstnode<T> *);
       void DisplayLeafNode(struct bstnode<T> *);
};

template<class T>
BST<T>  :: BST()
{
    Count = 0;
}

template<class T>
void BST<T>  :: Insert(struct bstnode<T> **Head, T iNo)
{
    struct bstnode<T> *temp = *Head;
    struct bstnode<T> *newn = new bstnode<T>;
    newn->data = iNo;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(*Head == NULL)   // BST empty
    {
        *Head = newn;
    }
    else
    {
            while(1)
            {
                    if(iNo > temp->data)        // R
                    {
                            if(temp->rchild == NULL)
                            {
                                temp->rchild = newn;
                                break;
                            }
                            temp = temp->rchild;
                    }
                    else if(iNo < temp->data)   // L
                    {
                             if(temp->lchild == NULL)
                            {
                                temp->lchild = newn;
                                break;
                            }
                            temp = temp->lchild;
                    }
                    else if(iNo == temp->data)  // Duplicate
                    {
                        delete newn;
                        cout<<"Data is already there in BST";
                        break;
                    }
            }
    }
    Count++;
}

template<class T>
void BST<T>  :: Inorder(struct bstnode<T> *Head)
{
    if(Head != NULL)
    {
        Inorder(Head->lchild);
        cout<<"|"<<Head->data<<"|->";
        Inorder(Head->rchild);
    }
}

template<class T>
void BST<T>  :: Preorder(struct bstnode<T> *Head)
{
    if(Head != NULL)
    {
         cout<<"|"<<Head->data<<"|->";
        Preorder(Head->lchild);
        Preorder(Head->rchild);
    }
}

template<class T>
void BST<T>  :: Postorder(struct bstnode<T> *Head)
{
    if(Head != NULL)
    {
        Postorder(Head->lchild);
        Postorder(Head->rchild);
        cout<<"|"<<Head->data<<"|->";
    }
}

template<class T>
void BST<T>  :: Search(struct bstnode<T> *Head, T iNo)
{
   struct bstnode<T> *temp = Head;

    while(temp != NULL)
    {
        if(temp -> data == iNo)
        {
            break;
        }
        else if(iNo > temp-> data)
        {
            temp = temp-> rchild;
        }
        else if(iNo < temp-> data)
        {
            temp = temp-> lchild;
        }
    }
    if(temp == NULL)
    {
        cout<<"\nThe Element "<<iNo<<" is not present in tree.\n";
    }
    else
    {
        cout<<"\nThe Element "<<iNo<<" is present in tree.\n";
    }
}

template<class T>
int BST<T>  :: CountNode()
{
   return Count;
}

template<class T>
int BST<T>  :: CountLeafNode(struct bstnode<T> *Head)
{
    static int iCnt = 0;
    struct bstnode<T> *temp = Head;

    if(temp != NULL)
    {
        if((temp->lchild == NULL) && (temp->rchild == NULL))
        {
            iCnt++;
        }
        CountLeafNode(temp->lchild);
        CountLeafNode(temp->rchild);
    }
   return iCnt;
}

template<class T>
void BST<T>  :: DisplayLeafNode(struct bstnode<T> *Head)
{
    if(Head != NULL)
    {
        if((Head->lchild == NULL) && (Head->rchild == NULL))
        {
             cout<<" |"<<Head-> data<<"| ";
        }
        DisplayLeafNode(Head->lchild);
        DisplayLeafNode(Head->rchild);
    }
}




int main()
{
 // Singly Linear LinkedList Function Call
    SinglyLL<int>obj1;

    obj1.InsertFirst(21);
    obj1.InsertFirst(11);
    obj1.InsertFirst(10);
    obj1.InsertLast(51);
    obj1.InsertLast(101);
    obj1.InsertLast(111);
    obj1.InsertAtPosition(3,31);
    obj1.DeleteFirst();
    obj1.DeleteLast();
    obj1.DeleteAtPosition(2);
    obj1.Display();
    cout<<"Number of Nodes in Singly Linear LinkedList are: "<<obj1.CountNode()<<endl;

    SinglyLL<float>obj2;

    obj2.InsertFirst(21.12);
    obj2.InsertFirst(11.36);
    obj2.InsertFirst(10.65);
    obj2.InsertLast(51.4);
    obj2.InsertLast(101.96);
    obj2.InsertLast(111.87);
    obj2.InsertAtPosition(3,31.35);
    obj2.DeleteFirst();
    obj2.DeleteLast();
    obj2.DeleteAtPosition(2);
    obj2.Display();
    cout<<"Number of Nodes in Singly Linear LinkedList are: "<<obj2.CountNode()<<endl;

      SinglyLL<char>obj3;

     obj3.InsertFirst('B');
     obj3.InsertFirst('A');
     obj3.InsertLast('C');
     obj3.InsertLast('D');
     obj3.InsertLast('E');
     obj3.InsertLast('F');
     obj3.InsertAtPosition(3,'Z');
     obj3.DeleteFirst();
     obj3.DeleteLast();
     obj3.DeleteAtPosition(2);
     obj3.Display();
     cout<<"Number of Nodes in Singly Linear LinkedList are: "<<obj3.CountNode()<<endl;

// Singly circular LinkedList Function Call
     SinglyCLL <int>obj11;

    obj11.InsertFirst(101);
    obj11.InsertFirst(111);
    obj11.InsertFirst(112);
    obj11.InsertLast(113);
    obj11.InsertLast(114);
    obj11.InsertLast(115);
    obj11.InsertAtPosition(3,121);
    obj11.DeleteFirst();
    obj11.DeleteLast();
    obj11.DeleteAtPosition(2);
    obj11.Display();
    cout<<"Number of Nodes in Singly Circular LinkedList are: "<<obj11.CountNode()<<endl;

     SinglyCLL<char>obj33;

     obj33.InsertFirst('z');
     obj33.InsertFirst('x');
     obj33.InsertLast('C');
     obj33.InsertLast('v');
     obj33.InsertLast('b');
     obj33.InsertLast('n');
     obj33.InsertAtPosition(3,'m');
     obj33.DeleteFirst();
     obj33.DeleteLast();
     obj33.DeleteAtPosition(2);
     obj33.Display();
     cout<<"Number of Nodes in Singly circular LinkedList are: "<<obj33.CountNode()<<endl;

 // Doubly Linear LinkedList Function Call
     Doubly_linkedList<int>obj21;

    obj21.InsertFirst(101);
    obj21.InsertFirst(111);
    obj21.InsertFirst(112);
    obj21.InsertLast(113);
    obj21.InsertLast(114);
    obj21.InsertLast(115);
    obj21.InsertAtPosition(3,121);
    obj21.DeleteFirst();
    obj21.DeleteLast();
    obj21.DeleteAtPosition(2);
    obj21.Display();
    cout<<"Number of Nodes in Doubly Linear LinkedList are: "<<obj21.CountNode()<<endl;

     Doubly_linkedList<char>obj31;

     obj31.InsertFirst('z');
     obj31.InsertFirst('x');
     obj31.InsertLast('C');
     obj31.InsertLast('v');
     obj31.InsertLast('b');
     obj31.InsertLast('n');
     obj31.InsertAtPosition(3,'m');
     obj31.DeleteFirst();
     obj31.DeleteLast();
     obj31.DeleteAtPosition(2);
     obj31.Display();
     cout<<"Number of Nodes in Doubly Linear LinkedList are: "<<obj31.CountNode()<<endl;

 // Doubly Circular LinkedList Function Call
        DoublyCLL<int> obj41;

        obj41.InsertFirst(51);
        obj41.InsertFirst(21);
        obj41.InsertFirst(11);
        obj41.InsertFirst(1);
        obj41.InsertLast(101);
        obj41.InsertLast(111);
        obj41.InsertLast(121);
        obj41.InsertAtPosition(3,365);
        obj41.Display();
        cout<<"Number of nodes in Doubly Circular LinkedList are:"<<obj41.CountNode()<<endl;

        DoublyCLL<char>obj5;;

       obj5.InsertFirst('H');
       obj5.InsertFirst('J');
       obj5.InsertLast('K');
       obj5.InsertLast('L');
       obj5.InsertLast('T');
       obj5.InsertLast('R');
       obj5.InsertAtPosition(3,'O');
       obj5.DeleteFirst();
       obj5.DeleteLast();
       obj5.DeleteAtPosition(2);
       obj5.Display();
       cout<<"Number of nodes in Doubly Circular LinkedList are: "<<obj5.CountNode()<<endl<<endl;

 // Queue Function Call

      Queue<int>obj10;

     obj10.Enqueue(11);
     obj10.Enqueue(21);
     obj10.Enqueue(51);
     obj10.Enqueue(101);
     obj10.Display();
     obj10.Dequeue();
     obj10.Dequeue();
     obj10.Display();
     cout<<"Number of element in Queue:"<<obj10.CountNode()<<endl<<endl;

     Queue<char>obj20;

     obj20.Enqueue('S');
     obj20.Enqueue('F');
     obj20.Enqueue('W');
     obj20.Enqueue('T');
     obj20.Display();
     obj20.Dequeue();
     obj20.Dequeue();
     obj20.Display();
     cout<<"Number of element in Queue:"<<obj20.CountNode()<<endl<<endl;

 // Stack Function Call

     Stack<char>obj77;

     obj77.Push('D');
     obj77.Push('C');
     obj77.Push('B');
     obj77.Push('A');
     obj77.Display();
     obj77.Pop();
     obj77.Pop();
     obj77.Display();
     cout<<"Number of element in Stack:"<<obj77.CountNode()<<endl;


 // BST Function Call

 struct bstnode<int> *First = NULL;

     BST<int> obj8;

     obj8.Insert(&First,11);
     obj8.Insert(&First,5);
     obj8.Insert(&First,7);
     obj8.Insert(&First,16);
     obj8.Insert(&First,1);
     obj8.Insert(&First,58);

     cout<<"\nInorder Data:\n";
     obj8.Inorder(First);

     cout<<"\nPostorder data\n";
     obj8.Postorder(First);

     cout<<"\nPreorder data\n";
     obj8.Preorder(First);

     cout<<"\n\nNumber of nodes in Tree are: "<<obj8.CountNode();
     cout<<"\nNumber of Leaf nodes in Tree are: "<< obj8.CountLeafNode(First);

     obj8.Search(First,1);

      cout<<"\nLeaf Nodes in tree:\n";
     obj8.DisplayLeafNode(First);
     cout<<endl;

 struct bstnode<char> *Sec = NULL;

     BST<char> obj18;

     obj18.Insert(&Sec,'J');
     obj18.Insert(&Sec,'Y');
     obj18.Insert(&Sec,'R');
     obj18.Insert(&Sec,'U');
     obj18.Insert(&Sec,'P');
     obj18.Insert(&Sec,'I');

     cout<<"\nInorder Data:\n";
     obj18.Inorder(Sec);

     cout<<"\nPostorder data\n";
     obj18.Postorder(Sec);

     cout<<"\nPreorder data\n";
     obj18.Preorder(Sec);

     cout<<"\n\nNumber of nodes in Tree are: "<<obj18.CountNode();
     cout<<"\nNumber of Leaf nodes in Tree are: "<< obj18.CountLeafNode(Sec);

     obj18.Search(Sec,'Q');

      cout<<"\nLeaf Nodes in tree:\n";
     obj18.DisplayLeafNode(Sec);
     cout<<endl;

     struct bstnode<float> *Third = NULL;

     BST<float> obj12;

     obj12.Insert(&Third,11.6);
     obj12.Insert(&Third,5.54);
     obj12.Insert(&Third,7.98);
     obj12.Insert(&Third,16.48);
     obj12.Insert(&Third,1.25);
     obj12.Insert(&Third,58.91);

     cout<<"\nInorder Data:\n";
     obj12.Inorder(Third);

     cout<<"\nPostorder data\n";
     obj12.Postorder(Third);

     cout<<"\nPreorder data\n";
     obj12.Preorder(Third);

     cout<<"\n\nNumber of nodes in Tree are: "<<obj12.CountNode();
     cout<<"\nNumber of Leaf nodes in Tree are: "<< obj12.CountLeafNode(Third);

     obj12.Search(Third,1.25);

      cout<<"\nLeaf Nodes in tree:\n";
     obj12.DisplayLeafNode(Third);
     cout<<endl;



    return 0;
}