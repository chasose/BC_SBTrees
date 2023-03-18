#pragma once
#include "TreeTester.h"

template<typename TreeType>
class InsertTesterRNG_INT :
    public TreeAnalyzer<TreeType>
{

public:
    InsertTesterRNG_INT(TreeType* tree, int repNumb, int stepSize, int stepCount, std::string name)
        : TreeAnalyzer<TreeType>(tree, repNumb, stepSize, stepCount, name) {};

    using TreeTester<TreeType>::currentStep_;
    using TreeTester<TreeType>::stepSize_;
    using TreeTester<TreeType>::tree_;

    // Inherited via TreeAnalyzer
    virtual std::vector<typename TreeType::key_type> prepare() override
    {
        std::vector<typename TreeType::key_type> vector_;

        for (int i = 0; i < stepSize_ * currentStep_; i = i + 1)
        {
            vector_.push_back(i);
        }

        std::random_device rd;
        std::mt19937 gen(rd());
        std::shuffle(vector_.begin(), vector_.end(), gen);

        return vector_;
    }

    virtual void execute(std::vector<typename TreeType::key_type>* vector) override
    {
        int i = 0;
        for (auto& key : *vector)
        {
            this->tree_->insert(key, i);
            i++;
        }


    }

    virtual void clear() override
    {
        this->tree_->clear();
    }



};