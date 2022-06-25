#pragma once


#include <algorithm>

template<typename T>
class Binary_Tree
{
public:
    explicit Binary_Tree(T data = T{}) : data_{std::move(data)}
    {}
    Binary_Tree(T data, Binary_Tree<T> * left, Binary_Tree<T> * right) :
                                                            data_{data},
                                                            left_{left},
                                                            right_{right}
    {}
    ~Binary_Tree()
    {
        if(left_)
            delete left_;
        if(right_)
            delete right_;
    }

    Binary_Tree<T> * left_{};
    Binary_Tree<T> * right_{};
    T data_{};
};
template<typename T>
int height(Binary_Tree<T> * root)
{
    if(root == nullptr)
        return 0;
    int left_height = height(root->left_);
    int right_height = height(root->right_);
    return 1 + std::max(left_height, right_height);
}
template<typename T>
T find(T elem, Binary_Tree<T> * root)
{
    while(root) {
        if (root->data_ == elem)
            return root->data_;
        if (root->data > elem)
            root = root->left_;
        if (root->data_ < elem)
            root = root->right_;
    }
}