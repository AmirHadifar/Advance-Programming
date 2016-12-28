#ifndef LINKEDARRAY_H_
#define LINKEDARRAY_H_
template <class myType>
class LinkedArray
{
private:

	int m_count;
	struct cell {												//struct is the same as class with default access Public
		myType data;
		cell* next;
		cell(myType newdata) 									//constructor
		{
			data=newdata;
			next=0;
		}
		cell() 													//default constructor
		{
			next=0;
		}
		cell(myType newdata,cell* newnext)						//constructor
		{
			data=newdata;
			next=newnext;
		}
	};
	cell *head;

	void doError(const char *msg = 0, int x1 = -1, int x2 = -1)	const
	{
		if (msg)
			cout << "Fatal Error: " << msg;
		if (x1 != -1)
			cout << " " << x1 << " ";
		if (x2 != -1)
			cout << " " << x2 << " ";
		cout << endl;
		cout.flush();
		int b = 0;
		int a = 10 / b;
		b = a;
	}
public:
	LinkedArray() :
		m_count(0),head(0)
	{

	}

	int append(const myType newData)
	{
		if (count()==0)
			head=new cell(newData);
		else
		{
			cell * t=head;
			while (t->next)
				t=t->next;
			t->next=new cell(newData);
			if (t->next==0)
				doError("could not allocate new cell!");
		}

		return m_count++;
	}
	void remove(const int index)
	{
		if (index >= count())
			doError("index out of bound on remove");

		if (index==0)
		{
			cell *t=head;
			head=head->next;
			delete t;
			m_count--;
			return;
		}
		cell *t=head;
		for (int i=0;i<index-1;++i)
			t=t->next;

		cell *temp=t->next;
		t->next=t->next->next;
		delete temp;
		m_count--;
	}
	void insert(const myType newData, const int index)
	{
		if (index == 0 && count() == 0)
		{
			append(newData);
			return;
		}
		if (index==0)
		{
			head=new cell(newData,head);
			m_count++;
			return;
		}
		if (index >= count())
			doError("index out of bound on insert", index, count());

		cell *t=head;
		for (int i=0;i<index-1;++i)
			t=t->next;
		t->next=new cell(newData,t->next);
		if (t->next==0)
			doError("could not allocate new cell!");
		m_count++;
	}
	const int count() const
	{
		return m_count;
	}
	myType& item(const int index) const
	{
		if (index >= count())
			doError("index out of bound on item()", index, count());

		cell* t=head;
		for (int i=0;i<index;++i)
			t=t->next;

		return t->data;
	}
	void clear()
	{
	m_count=0;
	cell* temp=head;
	while(temp)
	{
		temp->data=0;
		temp=0;
		temp=temp->next;
	}
	
	~LinkedArray()
	{
		cell* temp;
		while(head) // delete all reacords
		{
			temp=head;
			head=head->next;
			delete temp;
		}
		head=NULL;
	}

LinkedArray(const LinkedArray<myType>& la) //copy constructor
{
	m_count=la.m_count;
    cell* apnode = new cell;

    if(la.head)
        head=apnode;
    else
        head=NULL;
    
	cell *ap = la.head;
    while (ap != NULL) {
        apnode->data=ap->data;
        if(ap->next == NULL)
            apnode->next=NULL;
        else {
            apnode->next=new cell;
            apnode=apnode->next;
        }
        ap=ap->next;
     }
}

#endif /* LINKEDARRAY_H_ */
