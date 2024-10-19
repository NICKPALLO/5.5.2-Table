#include<iostream>

template<class T>
class table
{
public:
	table(int r, int c) :rows(r), columns(c)
	{
		arr = new T*[rows];
		for (int i = 0; i < rows; ++i)
		{
			arr[i] = new T[columns];
		}
	}

	~table()
	{
		for (int i = 0; i < rows; ++i)
		{
			delete[] arr[i];
		}
		delete[] arr;
	}

	T* operator[] (int i)
	{
		return arr[i];
	}

	T* operator[] (int i) const
	{
		return arr[i];
	}

	int Size() const
	{
		return rows * columns;
	}

private:
	T** arr;
	int rows; //строка
	int columns; //столбец
};



int main()
{
	auto test = table<int>(2, 3);
	test[0][0] = 4;
	std::cout << test[0][0]<<std::endl; // выводит 4
	std::cout << test.Size();
}