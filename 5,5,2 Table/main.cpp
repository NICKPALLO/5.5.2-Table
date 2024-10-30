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
	table(const table& other)
	{
		this->rows = other.rows;
		this->columns = other.columns;

		this->arr = new T * [rows];
		for (int i = 0; i < rows; ++i)
		{
			this->arr[i] = new T[columns];
		}

		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < columns; ++j)
			{
				this->arr[i][j] = other[i][j];
			}
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

	table& operator= (const table& other)
	{
		for (int i = 0; i < this->rows; ++i)
		{
			delete[] this->arr[i];
		}
		delete[] this->arr;
		
		this->rows = other.rows;
		this->columns = other.columns;

		this->arr = new T* [rows];
		for (int i = 0; i < rows; ++i)
		{
			this->arr[i] = new T[columns];
		}

		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < columns; ++j)
			{
				this->arr[i][j] = other[i][j];
			}
		}
		return *this;
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

	std::cout << test[0][0]<<std::endl;
	std::cout << test.Size();
	return 0;
}