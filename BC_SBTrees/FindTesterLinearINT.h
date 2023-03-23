#pragma once
#include "TreeTester.h"

template<typename TreeType>
class FindTesterLinearINT :public TreeAnalyzer<TreeType>
{
public:
    FindTesterLinearINT(TreeType* tree, int repNumb, int stepSize, int stepCount, std::string name)
        : TreeAnalyzer<TreeType>(tree, repNumb, stepSize, stepCount, name) {};

    using TreeTester<TreeType>::currentStep_;
    using TreeTester<TreeType>::stepSize_;
    using TreeTester<TreeType>::tree_;

    // Inherited via TreeAnalyzer
    virtual void prepare(std::vector<typename TreeType::key_type>* vector_) override
    {
        for (int i = 0; i < stepSize_ * currentStep_; i = i + 1)
        {
            vector_->push_back(i);
            this->tree_->insert(i, i + 1);
        }
    }

    virtual int execute(std::vector<typename TreeType::key_type>* vector) override
    {
        auto sum = 0;
        for (int key : *vector)
        {    
            my_node_sg<int,int> data = *this->tree_->find(key);
            sum += data.value;
        }
        return sum;
    }

    virtual void clear() override
    {
        this->tree_->clear();
    }
};


