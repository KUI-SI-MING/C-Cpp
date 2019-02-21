#include "vector.h"

void TestVector1()
{
	kui::Vector<int> first; 
	kui::Vector<int> second(4, 100); 
	kui::Vector<int> third(second.Begin(), second.End()); 
	kui::Vector<int> fourth(third); 

	int myints[] = { 16, 2, 77, 29 };
	kui::Vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));

	std::cout << "The contents of fifth are:";
	for (kui::Vector<int>::iterator it = fifth.Begin(); it != fifth.End(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	kui::Vector<string> strV;
	strV.Push_Back("1111");
	strV.Push_Back("2222");
	strV.Push_Back("3333");
	strV.Push_Back("4444");
	for (size_t i = 0; i < strV.Size(); ++i)
	{
		cout << strV[i] << " ";
	}
	cout << endl;
}

//vector iterator的使用
void PrintVector(const kui::Vector<int>& v)
{
	 //使用const迭代器进行遍历打印
	kui::Vector<int>::constiterator it = v.CBegin();
	while (it != v.CEnd())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void TestVector2()
{
	// 使用push_back插入4个数据
	kui::Vector<int> v;
	v.Push_Back(1);
	v.Push_Back(2);
	v.Push_Back(3);
	v.Push_Back(4);
	// 使用迭代器进行遍历打印
	kui::Vector<int>::iterator it = v.Begin();
	while (it != v.End())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	// 使用迭代器进行修改

	it = v.Begin();
	while (it != v.End())
	{
		*it *= 2;
		++it;
	}
	PrintVector(v);
}

//capacity/vector::reserve/resize
void TestVector3()
{
	size_t sz;
	kui::Vector<int> foo;
	sz = foo.Capacity();

	std::cout << "making foo grow:\n";
	for (int i = 0; i < 100; ++i) {
		foo.Push_Back(i);
		if (sz != foo.Capacity()) {
			sz = foo.Capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}
	cout << endl;

	// resverse
	kui::Vector<int> bar;
	sz = bar.Capacity();
	bar.Reserve(100); 

	std::cout << "making bar grow:\n";
	for (int i = 0; i < 100; ++i) {
		bar.Push_Back(i);
		if (sz != bar.Capacity()) {
			sz = bar.Capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}
	cout << endl;

	// resize
	kui::Vector<int> myvector;
	for (int i = 1; i < 10; i++)
		myvector.Push_Back(i);

	myvector.Resize(5);
	myvector.Resize(8, 100);
	myvector.Resize(12);

	std::cout << "myvector contains:";
	for (size_t i = 0; i < myvector.Size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
}

// find / insert / erase
void TestVector4()
{
	int a[] = { 1, 2, 3, 4 };
	kui::Vector<int> v(a, a + sizeof(a) / sizeof(int));

	// 使用find查找3所在位置的iterator
	kui::Vector<int>::iterator pos = find(v.Begin(), v.End(), 3);

	// 在pos位置之前插入30
	v.Insert(pos, 30);

	kui::Vector<int>::iterator it = v.Begin();
	while (it != v.End()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;

	pos = find(v.Begin(), v.End(), 3);
	// 删除pos位置的数据
	v.Erase(pos);
	it = v.Begin();
	while (it != v.End()) {
		cout << *it << " ";
		++it;
	}	
	cout << endl;
}

// operator[]
void TestVector5()
{
	int a[] = { 1, 2, 3, 4 };
	kui::Vector<int> v(a, a + sizeof(a) / sizeof(int));

	// 通过[]读写第0个位置。
	v[0] = 10;
	cout << v[0] << endl;

	// 通过[i]的方式遍历vector
	for (size_t i = 0; i < v.Size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	kui::Vector<int> swapv(v.Size(), 0);
	swapv.Swap(v);
	cout << "v data:";

	for (size_t i = 0; i < v.Size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	cout << "swapv data:";
	for (size_t i = 0; i < swapv.Size(); ++i)
	{
		cout << swapv[i] << " ";
	}
	cout << endl;
}

// iterator失效问题
void TestVector6()
{
	int a[] = { 1, 2, 3, 4 };
	kui::Vector<int> v(a, a + sizeof(a) / sizeof(int));

	// 使用find查找3所在位置的iterator
	kui::Vector<int>::iterator pos = find(v.Begin(), v.End(), 3);

	// 删除pos位置的数据，导致pos迭代器失效。
	v.Erase(pos);
	cout << *pos << endl; // 此处会导致非法访问

	// 在pos位置插入数据，导致pos迭代器失效。
	// insert会导致迭代器失效，是因为insert可
	// 能会导致增容，增容后pos还指向原来的空间，而原来的空间已经释放了。
	pos = find(v.Begin(), v.End(), 3);
	v.Insert(pos, 30);
	cout << *pos << endl; // 此处会导致非法访问

	// 实现删除v中的所有偶数
	// 下面的程序会崩溃掉，如果是偶数，erase导致it失效
	// 对失效的迭代器进行++it，会导致程序崩溃
	kui::Vector<int>::iterator it = v.Begin();
	while (it != v.End())
	{
		if (*it % 2 == 0)
			v.Erase(it);
		++it;
	}
	// 以上程序要改成下面这样，erase会返回删除位置的下一个位置
	it = v.Begin();
	while (it != v.End())
	{
		if (*it % 2 == 0)
			it = v.Erase(it);
		else
			++it;
	}
}

int main()
{
	TestVector1();
	TestVector2();
	TestVector3();
	TestVector4();
	TestVector5();
	TestVector6();
	

	system("pause");
	return 0;
}