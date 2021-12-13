#include <iostream>
#include <iomanip>
#include <ctime>

#define Vec

using namespace std;

#ifdef Vec
class Vector {

	int* arr;
	int size;

	const int defaultValue = 0, max_rand = 100;

public:

	Vector() : Vector(0) {};

	Vector(int size) : size(size) {
		arr = new int[size];

		for (int i = 0; i < size; i++) {
			arr[i] = defaultValue;
		}
	}

	Vector(const Vector& other) {

		this->size = other.size;
		this->arr = new int[other.size];

		for (int i = 0; i < size; i++) {
			this->arr[i] = other.arr[i];
		}
	}

	~Vector() {
		delete[] arr;
	}
	// ============================== \\
			 	  Гетеры               


	int GetSize() {
		return size;
	}

	int GetSumm() {
		int summ = 0;

		for (int i = 0; i < size; i++) {
			summ += arr[i];
		}

		return summ;
	}

	int GetAverage() {
		return GetSumm() / size;
	}

	int GetMax() {
		int max = INT_MIN;
		for (int i = 0; i < size; i++) {
			if (arr[i] > max) {
				max = arr[i];
			}
		}
		return max;
	}

	int GetMin() {
		int min = INT_MAX;
		for (int i = 0; i < size; i++) {
			if (arr[i] < min) {
				min = arr[i];
			}
		}
		return min;
	}

	// ============================== \\
				Заполнение

	void FillRandom() const {
		srand(time(NULL));

		for (int i = 0; i < size; i++) {
			arr[i] = rand() % max_rand;
		}
	}

	void FillDefault() {
		for (int i = 0; i < size; i++) {
			arr[i] = defaultValue;
		}
	}

	// ============================== \\
				 Push`ы

	void push_back(int value) {
		int* temp = new int[size + 1];

		for (int i = 0; i < size; i++) {
			temp[i] = this->arr[i];
		}
		temp[size] = value;

		if (arr != nullptr) { delete[] arr; }

		arr = temp;

		size++;
	}

	// ============================== \\
				  Принт

	void Print() const {
		cout << "Vector" << " | Size: " << setw(3) << size << " | Adress: " << this << endl; // 37
		cout << "=====================================" << endl;
		for (int i = 0; i < size; i++) {
			cout << setw(16) << i << ". |" << setw(16) << arr[i] << endl;
		}
		cout << "=====================================" << endl;
	}

	// ============================== \\
		     Поиск и сортировка

	int LineSearch(int value) {

		for (int i = 0; i < size; i++) {
			if (value == arr[i]) {
				return i;
			}
		}

		cout << "Vector " << this << " | Element not found!" << endl;
		return 0;
	}

	void BubbleSort() {
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if (arr[j] > arr[j + 1]) {
					swap(arr[j], arr[j + 1]);
				}
			}
		}
	}

	// ============================== \\
				 Операторы

	int& operator[] (int index) { // Реализация обращения к вектору как к масиву
		if (index > size) {
			throw runtime_error("Array out of range");
		}
		else { return arr[index]; }
	}

	bool operator ==(const Vector& other) {
		if (this->size != other.size) {
			return false;
		}
		else {
			for (int i = 0; i < size; i++) {
				if (arr[i] != other.arr[i]) {
					return false;
				}
			}
		}
	}

	bool operator !=(const Vector& other) {
		if (this->size != other.size) {
			return true;
		}
		else {
			for (int i = 0; i < size; i++) {
				if (arr[i] != other.arr[i]) {
					return true;
				}
			}
		}
	}

	Vector& operator =(const Vector& other) {

		this->size = other.size;

		if (arr != nullptr) { delete[] arr; }
		this->arr = new int[other.size];

		for (int i = 0; i < size; i++) {
			this->arr[i] = other.arr[i];
		}

		return *this;
	}

	Vector operator +(const Vector& other) {
		Vector tmp(this->size + other.size);

		for (int i = 0; i < size; i++) {
			tmp[i] = this->arr[i];
		}

		for (int i = 0; i < tmp.size; i++) {
			tmp[i] = other.arr[i - size];
		}

		return tmp;
	}

	Vector& operator +=(const Vector& other) {

		for (int i = 0; i < other.size; i++) {
			push_back(other.arr[i]);
		}
		return *this;
	}
};

void main() {
	Vector vec(3);
	vec.FillRandom();
	vec.Print();
	Vector vec1(4);
	vec1.FillRandom();
	vec1.Print();

	vec = vec1;
	vec.Print();
}
#endif // Vec


