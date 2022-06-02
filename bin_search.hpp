#include <vector>

template<typename ForwardeIter, typename T>
bool binary_search(ForwardeIter first, ForwardeIter last, T elem)
{
	auto first_ = first;
	auto last_ = last;

	while(first_ <= last_)
	{
		auto mid = first_ + (last_ - first_) / 2;
		if (*mid == elem)
			return true;
		if (*mid > elem)
			last_ = --mid;
		if (*mid < elem)
			first_ = ++mid;
	}
	return false;
}


void test_bin_search()
{
	std::vector<int> v{ 0,1,2,3,4,5,6,7,8,9,10,12,15,19 };
	if (!::binary_search(v.begin(), v.end(), 2))
		throw logic_error{"false"};
	if (!::binary_search(v.begin(), v.end(), 0))
		throw logic_error{ "false" };
	if (!::binary_search(v.begin(), v.end(), 6))
		throw logic_error{ "false" };
	if (!::binary_search(v.begin(), v.end(), 19))
		throw logic_error{ "false" };
}