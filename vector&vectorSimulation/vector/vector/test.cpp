#include <iostream>
#include <vector>
#include <algorithm>    // std::for_each

using namespace std;

void TestInit()
{
	//迭代器初始化                                                                                                                                                                           
	int myints[] = { 12, 4, 67, 4 };
	std::vector<int> myint(myints, myints + sizeof(myints) / sizeof(int));
	cout << "The contents of myint are";
	for (std::vector<int>::iterator it = myint.begin(); it != myint.end(); ++it)
	{
		std::cout << ' ' << *it;
	}
	cout << endl;
}

void PrintVector(const vector<int>& v)
{
	// 使用const迭代器进行遍历打印
	vector<int>::const_iterator it = v.cbegin();
	while (it != v.cend())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void Print(const int& v)
{
	cout << v << " ";
}
void TestIterator(vector<int>& v)
{
	// 使用迭代器进行遍历打印
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// 使用迭代器进行修改
	it = v.begin();
	while (it != v.end())
	{
		*it *= 3;
		++it;
	}

	// 使用反向迭代器进行遍历再打印
	vector<int>::reverse_iterator rit = v.rbegin();
	while (rit != v.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

		for (auto& iter : v)
		{
			cout << iter << " ";
		}
		cout << endl;

		for_each(v.begin(), v.end(), Print);
		cout << endl;

	PrintVector(v);
}

int main()
{
	////迭代器初始化
	//TestInit();


	//// 使用push_back插入4个数据
	//vector<int> v;
	//v.push_back(1);
	//v.push_back(2);
	//v.push_back(3);
	//v.push_back(4);
	//TestIterator(v);

	////空间开辟
	//size_t sz;
	//std::vector<int> foo;
	//sz = foo.capacity();
	//std::cout << "making foo grow:\n";
	//for (int i = 0; i<100; ++i) {
	//	foo.push_back(i);
	//	if (sz != foo.capacity()) {
	//		sz = foo.capacity();
	//		std::cout << "capacity changed: " << sz << '\n';
	//	}
	//}

	////vector::reserve
	//std::vector<int> bar;
	//int sz = bar.capacity();
	//bar.reserve(100); 
	//std::cout << "making bar grow:\n";
	//for (int i = 0; i<100; ++i) {
	//	bar.push_back(i);
	//	if (sz != bar.capacity()) {
	//		sz = bar.capacity();
	//		std::cout << "capacity changed: " << sz << '\n';
	//	}
	//}

	////vector::resize
	//std::vector<int> myvector;
	//// set some initial content:
	//for (int i = 1; i<10; i++)
	//	myvector.push_back(i);
	//myvector.resize(5);
	//myvector.resize(8, 100);
	//myvector.resize(12);
	//std::cout << "myvector contains:";
	//for (int i = 0; i<myvector.size(); i++)
	//	std::cout << ' ' << myvector[i];
	//std::cout << '\n';

	////增删查改
	//int a[] = { 1, 2, 3, 4 };
	//vector<int> v(a, a + sizeof(a) / sizeof(int));

	//// 使用find查找3所在位置的iterator
	//vector<int>::iterator pos = find(v.begin(), v.end(), 3);//InputIterator find (InputIterator first, InputIterator 
	////last, const T& val);

	//// 在pos位置之前插入30
	//v.insert(pos, 30);//iterator insert (iterator position, const value_type& val);

	//vector<int>::iterator it = v.begin();
	//while (it != v.end()) {
	//	cout << *it << " ";
	//	++it;
	//}
	//cout << endl;

	//pos = find(v.begin(), v.end(), 3);
	//// 删除pos位置的数据
	//v.erase(pos);//iterator erase (iterator position);	

	//v.pop_back();//void pop_back();
	//v.push_back(10);//void push_back (const value_type& val)


	//it = v.begin();
	//while (it != v.end()) {
	//	cout << *it << " ";
	//	++it;
	//}
	//cout << endl;

	// insert/erase导致的迭代器失效
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));

	// 使用find查找3所在位置的iterator
	vector<int>::iterator pos = find(v.begin(), v.end(), 3);

	// 删除pos位置的数据，导致pos迭代器失效。
	v.erase(pos);
	cout << *pos << endl; // 此处会导致非法访问

	//在pos位置插入数据，导致pos迭代器失效。
	// insert会导致迭代器失效，是因为insert可
	// 能会导致增容，增容后pos还指向原来的空间，而原来的空间已经释放了。

	pos = find(v.begin(), v.end(), 3);
	v.insert(pos, 30);
	cout << *pos << endl; // 此处会导致非法访问

	//场景
	// 实现删除v中的所有偶数
	// 下面的程序会崩溃掉，如果是偶数，erase导致it失效
	// 对失效的迭代器进行++it，会导致程序崩溃
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
			v.erase(it);
		++it;
	}
	// 以上程序要改成下面这样，erase会返回删除位置的下一个位置
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
			it = v.erase(it);
		else
			++it;
	}

	system("pause");
	return 0;
}