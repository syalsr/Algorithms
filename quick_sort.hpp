#include <random>

size_t random(std::size_t size)
{
    std::random_device myRandomDevice;
    unsigned seed = myRandomDevice();
    std::default_random_engine myRandomEngine(seed);
    std::uniform_int_distribution<int> myUnifIntDist(0, size-1);
    return myUnifIntDist(myRandomEngine);
}

template<typename T>
std::vector<T> quick_sort(std::vector<T>& v)
{
    if(v.size() < 2)
        return v;

    //const T* pivot = v.data() + (v.size() / 2) -1 ;
    auto* pivot = &v[random(v.size())];
    std::vector<T> less;
    std::vector<T> greater;

    for(T* elem = v.data(); elem <= &v.back(); ++elem)
    {
        if(elem == pivot)
            continue;
        else if(*elem <= *pivot)
            less.push_back(*elem);
        else
            greater.push_back(*elem);
    }
    auto less_vec = quick_sort(less);
    auto greater_vec = quick_sort(greater);

    less_vec.push_back(*pivot);
    std::move(greater_vec.begin(), greater_vec.end(), back_inserter(less_vec));

    return less_vec;
}