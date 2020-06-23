#include<iostream>
#include<conio.h>
#include<cstdlib>
using namespace std;
struct node
{
    int id;
    float gpa;
    char gender;
    node *next;
};
class Linked_list
{
private:
    struct node *head ;
    int counter;
    struct node wrongNode ;
public:
    Linked_list()
    {
        head = NULL;
        counter = 0;
        wrongNode.id = -1;
        wrongNode.gpa = -1;
        wrongNode.gender = '#';
        wrongNode.next = NULL;
    }
    void insert_first(node d)
    {
        node *ptr;
        ptr = new node;
        *ptr = d;
        ptr->next = head;
        head = ptr;
    }
    void insert_last(node d)
    {
        if (head == NULL)
        {
            insert_first(d);
            return;
        }
        node *ptr;
        for (ptr = head; ptr->next != NULL; ptr = ptr->next)
            continue;
        ptr->next = new node;
        ptr = ptr->next;
        *ptr = d;
        ptr->next = NULL;
    }
    void insert_id_order(node d)
    {
        if ((head == NULL) || (d.id < head->id))
            insert_first(d);
        else if(head->next == NULL)
            insert_last(d);
        else
        {
            node *ptr;
            for (ptr = head; ptr->next != NULL; ptr = ptr->next)
                if(ptr->next->id < d.id)
                    continue;
                else
                    break;
            node *temp = new node;
            *temp = d;
            temp->next = ptr->next ;
            ptr->next = temp;
        }
    }
    void insert_index(node d, int n)
    {
        if((n == 0) || (head == NULL))
        {
            insert_first(d);
            return;
        }
        node *ptr;
        ptr = head;
        for(int k = 1 ; k < n-1 ; k++)
        {
            if(ptr->next == NULL)
            {
                insert_last(d);
                return;
            }
            else
                ptr=ptr->next;
        }
        node *temp = new node;
        *temp = d ;
        temp->next = ptr->next;
        ptr->next = temp;
    }
    bool is_empty(void)
    {
        if(head == NULL)
            return true;
        else
            return false;
    }
    node read_first(void)
    {
        if(head == NULL)
            return wrongNode;
        else
            return *head;
    }
    int number_of_nodes(void)
    {
        if(head == NULL)
            return 0;
        int counter = 0;
        node *ptr;
        for(ptr = head ; ptr != NULL ; ptr = ptr->next)
            counter++;
        return counter;
    }
    node read_last(void)
    {
        node *ptr;
        if(head == NULL)
            return wrongNode;
        if(head->next == NULL)
            return *head;
        for(ptr = head ; ptr->next->next != NULL ; ptr = ptr->next)
            continue;
        return *(ptr->next) ;
    }
    void delete_first(void)
    {
        if(head == NULL)
            return;
        node *ptr;
        ptr = head;
        head = head->next;
        delete ptr;
    }
    void delete_last(void)
    {
        if(head == NULL)
            return;
        if(head->next == NULL)
            delete_first();

        node *ptr ;
        for(ptr = head ; ptr->next->next !=NULL ; ptr = ptr ->next)
        {
            continue;
        }
        delete ptr ->next;
        ptr->next = NULL;
    }
    void delete_index(int n)
    {
        if (head ==NULL)
            return;
        if(n==0)
        {
            delete_first();
            return;
        }
        node *p, *temp;
        p= head;
        for (int i =1 ; i<n; i++)
        {
            p = p-> next;
        }
        temp = p-> next;
        p -> next = temp ->next;

        delete (temp);
    }
    void delete_id(int ID)
    {
        if (head ==NULL)
            return;

        if (ID == head->id)
        {
            delete_first();
            return;
        }

        int flag=0;
        node *p,*temp;
        for(p=head ; p->next !=NULL; p= p->next)
        {
            if (p->next->id !=ID)
            {
                flag=0;
                continue;
            }
            else
            {
                flag=1;//found the node
                break;
            }
        }
        if (flag==1)
        {
            temp = p->next;
            p->next = temp->next;
            free (temp);
        }
    }
    void delete_all(void)
    {
        if (head==NULL)
            return;
        if (head->next ==NULL)
        {
            delete_first();
            return;
        }

        node *Next, *current ;
        current =head;
        while(current != NULL)
        {
            Next = current -> next;
            delete current;
            current =Next;
        }
        head =NULL;
    }
    void sort_id(void)
    {
        if (head==NULL || head->next==NULL)
            return;

        int  last_index =number_of_nodes()-1;

        node *p, *temp;
        int t;
        float t3;
        char t2;
        while(last_index>0)
        {
            p=head;
            for(int i=0 ; i<last_index ; i++)
            {
                if(p->id > p->next->id)
                {
                    t   =  p->id;
                    p-> id  =  p->next->id;
                    p->next->id  =  t;

                    t3   =  p->gpa;
                    p->gpa  =  p->next->gpa;
                    p->next->gpa  =  t3;

                    t2   =  p->gender;
                    p->gender  =  p->next->gender;
                    p->next->gender  =  t2;
                }
                p = p->next;
            }
            last_index--;
        }
    }
    int get_index_data(int index)
    {
        int k;
        node *ptr;
        if(head == NULL)
            return wrongNode.id;
        if(index == 0)
            return read_first().id;
        ptr = head;
        for(k = 0 ; k < index ; k++)
        {
            ptr = ptr->next;
            if(ptr == NULL)
                return wrongNode.id;
        }
        return ptr->id;
    }
    node get_id_data(int ID)
    {
        node *ptr;
        if(head == NULL)
            return wrongNode;
        for(ptr = head ; ptr != NULL ; ptr = ptr->next)
        {
            if(ptr->id == ID)
                return *ptr;
        }
        return wrongNode;
    }
    void print_list(void)
    {
        int index = 0;
        struct node *temp;
        cout<< "\n========================================\n";
        cout << "Index\t"<< "id\t" << "GPA\t" << "Gender\n";
        cout<< "----------------------------------------\n";
        for (temp = head; temp != NULL; temp = temp->next)
        {
            cout << index << "\t" << temp->id << "\t" << temp->gpa << "\t" << temp->gender << "\n";
            index++;
        }
        cout<< "========================================\n\n";
    }


};

int main(void)
{
    int k, r,ExitFlag=0, input,n;
    struct node temp;
    Linked_list list1;

    while (ExitFlag == 0)

    {
        cout<<"To exit press 0\n";
        cout<<"To print the linked list enter 1\n";
        cout<<"To get number of nodes enter 2\n";
        cout<<"To insert first node enter 3\n";
        cout<<"To insert last node enter 4\n";
        cout<<"To insert in id order node enter 5\n";
        cout<<"To insert node using index enter 6\n";
        cout<<"To delete first node enter 7\n";
        cout<<"To delete last node enter 8\n";
        cout<<"To delete node from index enter 9\n";
        cout<<"To delete node from id enter 10\n";
        cout<<"To delete all nodes enter 11\n";
        cout<<"To sort all nodes with id enter 12\n";
        cout<<"To get data from node index enter 13\n";
        cout<<"To get data from node id enter 14\n";
        cout<<"Your Choice: ";
        cin>>input;

        switch (input)
        {
        case 0 :
            cout<<"\nThank You\nGood Bye\n";
            ExitFlag = 1;
            break;

        case 1 :
            cout << "Data in Linked List L1: \n";
            list1.print_list();
            break;

        case 2 :
            n= list1.number_of_nodes();
            cout << "Number of node:\t"<< n<<endl;
            break;

        case 3 :
            cout<< "enter id ,gpa and gender \n";
            cin >>temp.id>>temp.gpa>>temp.gender;
            temp.next = NULL;
            list1.insert_first(temp);
            break;

        case 4 :
            cout<< "enter id ,gpa and gender \n";
            cin >>temp.id>>temp.gpa>>temp.gender;
            temp.next = NULL;
            list1.insert_last(temp);
            break;

        case 5 :
            cout<< "enter id ,gpa and gender \n";
            cin >>temp.id>>temp.gpa>>temp.gender;
            temp.next = NULL;
            list1.insert_id_order(temp);
            break;

        case 6 :
            cout<< "enter id ,gpa , gender and index \n";
            cin >>temp.id>>temp.gpa>>temp.gender>>n;
            temp.next = NULL;
            list1.insert_index(temp,n);
            break;

        case 7 :
            list1.delete_first();
            break;

        case 8 :
            list1.delete_last();
            break;

        case 9 :
            cout<< "Enter index:\n";
            cin >>n ;
            list1.delete_index(n);
            break;

        case 10 :
            cout<< "Enter ID:\n";
            cin >>n ;
            list1.delete_id(n);
            break;

        case 11 :
            list1.delete_all();
            break;

        case 12 :
            list1.sort_id();
            break;

        case 13 :
            cout<< "Enter n:\n";
            cin >>n ;
            cout<<list1.get_index_data(n)<<endl;
            break;

        case 14 :
            cout<< "Enter ID:\n";
            cin >>n ;
            struct node tempNode ;
            tempNode = list1.get_id_data(n);
            cout <<"id\t" << "GPA\t" << "Gender\n";
            cout<< "----------------------------------------\n";
            cout <<tempNode.id << "\t" << tempNode.gpa << "\t" << tempNode.gender << "\n";
            break;

        default:

            cout<<"\nInvalid Choice please try again\n";
            break;
        }
        cout << "__________________________________\n";
    }
    getch();
}
