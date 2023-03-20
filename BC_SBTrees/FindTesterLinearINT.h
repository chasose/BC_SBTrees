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
    virtual std::vector<typename TreeType::key_type> prepare() override
    {
        std::vector<typename TreeType::key_type> vector_;

        for (int i = stepSize_ * currentStep_; i > 0; i--)
        {
            vector_.push_back(i);
            this->tree_->insert(i, i);
        }
        return vector_;
    }

    virtual void execute(std::vector<typename TreeType::key_type>* vector) override
    {
        for (auto& key : *vector)
        {
            this->tree_->find(key);
        }


    }

    virtual void clear() override
    {
        this->tree_->clear();
    }
};


