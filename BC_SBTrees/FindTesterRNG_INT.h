#pragma once
#include "TreeTester.h"

template<typename TreeType>
class FindTesterRNG_INT : public TreeAnalyzer<TreeType>
{
public:
    FindTesterRNG_INT(TreeType* tree, int repNumb, int stepSize, int stepCount, std::string name)
        : TreeAnalyzer<TreeType>(tree, repNumb, stepSize, stepCount, name) {};

    using TreeTester<TreeType>::currentStep_;
    using TreeTester<TreeType>::stepSize_;
    using TreeTester<TreeType>::tree_;

    // Inherited via TreeAnalyzer
    virtual void prepare(std::vector<typename TreeType::key_type>* vector_) override
    {

        for (int i = stepSize_ * currentStep_; i > 0; i--)
        {
            vector_->push_back(i);
            this->tree_->insert(i, i);
        }

        std::random_device rd;
        std::mt19937 gen(rd());
        std::shuffle(vector_->begin(), vector_->end(), gen);

    }

    virtual int execute(std::vector<typename TreeType::key_type>* vector) override
    {
        auto sum = 0;
        for (int key : *vector)
        {    
            auto data = *this->tree_->find(key);
            sum += data.value;
        }
        return sum;
    }

    virtual void clear() override
    {
        this->tree_->clear();
    }

};

