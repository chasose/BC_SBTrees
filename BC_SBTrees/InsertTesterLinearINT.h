#pragma once
#include "TreeTester.h"

template<typename TreeType>
class InsertTesterLinearINT :
    public TreeAnalyzer<TreeType>
{

public:
    InsertTesterLinearINT(TreeType* tree, int repNumb, int stepSize, int stepCount, std::string name)
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
        }
        
    }

    virtual int execute(std::vector<typename TreeType::key_type>* vector) override
    {
        int i = 0;
        for (auto& key : *vector)
        {
            this->tree_->insert(key, i);
            i++;
        }
        return 0;
    }

    virtual void clear() override
    {
        this->tree_->clear();
    }
};

