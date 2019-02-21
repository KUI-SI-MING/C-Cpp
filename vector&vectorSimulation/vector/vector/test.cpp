#include <iostream>
#include <vector>
#include <algorithm>    // std::for_each

using namespace std;

void TestInit()
{
	//��������ʼ��                                                                                                                                                                           
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
	// ʹ��const���������б�����ӡ
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
	// ʹ�õ��������б�����ӡ
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// ʹ�õ����������޸�
	it = v.begin();
	while (it != v.end())
	{
		*it *= 3;
		++it;
	}

	// ʹ�÷�����������б����ٴ�ӡ
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
	////��������ʼ��
	//TestInit();


	//// ʹ��push_back����4������
	//vector<int> v;
	//v.push_back(1);
	//v.push_back(2);
	//v.push_back(3);
	//v.push_back(4);
	//TestIterator(v);

	////�ռ俪��
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

	////��ɾ���
	//int a[] = { 1, 2, 3, 4 };
	//vector<int> v(a, a + sizeof(a) / sizeof(int));

	//// ʹ��find����3����λ�õ�iterator
	//vector<int>::iterator pos = find(v.begin(), v.end(), 3);//InputIterator find (InputIterator first, InputIterator 
	////last, const T& val);

	//// ��posλ��֮ǰ����30
	//v.insert(pos, 30);//iterator insert (iterator position, const value_type& val);

	//vector<int>::iterator it = v.begin();
	//while (it != v.end()) {
	//	cout << *it << " ";
	//	++it;
	//}
	//cout << endl;

	//pos = find(v.begin(), v.end(), 3);
	//// ɾ��posλ�õ�����
	//v.erase(pos);//iterator erase (iterator position);	

	//v.pop_back();//void pop_back();
	//v.push_back(10);//void push_back (const value_type& val)


	//it = v.begin();
	//while (it != v.end()) {
	//	cout << *it << " ";
	//	++it;
	//}
	//cout << endl;

	// insert/erase���µĵ�����ʧЧ
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));

	// ʹ��find����3����λ�õ�iterator
	vector<int>::iterator pos = find(v.begin(), v.end(), 3);

	// ɾ��posλ�õ����ݣ�����pos������ʧЧ��
	v.erase(pos);
	cout << *pos << endl; // �˴��ᵼ�·Ƿ�����

	//��posλ�ò������ݣ�����pos������ʧЧ��
	// insert�ᵼ�µ�����ʧЧ������Ϊinsert��
	// �ܻᵼ�����ݣ����ݺ�pos��ָ��ԭ���Ŀռ䣬��ԭ���Ŀռ��Ѿ��ͷ��ˡ�

	pos = find(v.begin(), v.end(), 3);
	v.insert(pos, 30);
	cout << *pos << endl; // �˴��ᵼ�·Ƿ�����

	//����
	// ʵ��ɾ��v�е�����ż��
	// ����ĳ����������������ż����erase����itʧЧ
	// ��ʧЧ�ĵ���������++it���ᵼ�³������
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
			v.erase(it);
		++it;
	}
	// ���ϳ���Ҫ�ĳ�����������erase�᷵��ɾ��λ�õ���һ��λ��
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