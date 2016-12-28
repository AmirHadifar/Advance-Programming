#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_
template<class T>
class DynamicArray
{
private:
	void resize(const int newSize)
	{
		int *temp = new int[newSize];
		if (temp == 0)
			doError(" can not allocate memory to resize!");
		for (int i = 0; i < m_count; ++i)
			temp[i] = data[i];
		delete[] data;
		data = temp;
		m_capacity = newSize;
	}

	int m_count;
	int m_capacity;
	T *data;
	void doError(const char *msg = 0, int x1 = -1, int x2 = -1) const
	{
		if (msg)
			cout << "Fatal Error: " << msg;
		if (x1 != -1)
			cout << " " << x1 << " ";
		if (x2 != -1)
			cout << " " << x2 << " ";
		cout << endl;
		int b = 0;
		int a = 10 / b;
		b = a;
	}
public:
	DynamicArray() :
		data(0)
	{
		clear();
	}

	int append(const T newData)
	{
		if (m_count == m_capacity) //if all cells full
			resize(m_capacity * 2);
		m_count++;
		item(m_count - 1) = newData;
		return m_count - 1;
	}
	void remove(const int index)
	{
		if (index >= count())
			doError("index out of bound on remove");

		for (int i = index; i < count() - 1; ++i)
			item(i) = item(i + 1);
		m_count--; //last item not valid anymore, removed

		if (m_count < m_capacity / 2) //more than half cells empty, release extra memory
			resize(m_capacity / 2);
	}
	void insert(const T newData,const int index)
	{
		if (index == 0 && count() == 0)
		{
			append(newData);
			return;
		}
		if (index >= count())
			doError("index out of bound on insert", index, count());

		if (m_count == m_capacity) //if all cells full
			resize(m_capacity * 2);

		m_count++;
		for (int i = count() - 1; i > index; --i)
			item(i) = item(i - 1);
		item(index) = newData;

	}
	const int count() const
	{
		return m_count;
	}
	inline T& item(const int index) const
	{
		if (index >= count())
			doError("index out of bound on item()", index, count());
		return data[index];
	}
	void clear()
	{
		int i=0;
		int dec=m_count;
		T* temp=data;
		
		while(dec--)
			temp[i++]=0;
	}
	DynamicArray(const DynamicArray<T> & da) //copy constructor 
	{
		m_count=da.m_count;
		m_capacity=da.m_capacity;
		data=new int[m_capacity];
		for(int i=0;i<m_count;i++)
			data[i]=da.data[i];
	}
	~DynamicArray() // destructor
	{
		m_count=0;
		m_capacity=0;
		delete []data;
	}
};

#endif /* DYNAMICARRAY_H_ */
