#pragma once
#include "TreeTester.h"

template<typename TreeType>
class InsertTesterRNG_STRING :
    public TreeAnalyzer<TreeType>
{

public:
    InsertTesterRNG_STRING(TreeType* tree, int repNumb, int stepSize, int stepCount, std::string name)
        : TreeAnalyzer<TreeType>(tree, repNumb, stepSize, stepCount, name) {};

    using TreeTester<TreeType>::currentStep_;
    using TreeTester<TreeType>::stepSize_;
    using TreeTester<TreeType>::tree_;

    // Inherited via TreeAnalyzer
    virtual std::vector<typename TreeType::key_type> prepare() override
    {
        std::string s = "a"; // initial string
        int iterations = stepSize_ * currentStep_; // number of iterations
        std::vector<typename TreeType::key_type> vector_;
        for (int i = 0; i < iterations; ++i)
        {
            // increment the string
            int carry = 1;
            for (int j = s.size() - 1; j >= 0 && carry > 0; --j)
            {
                if (s[j] == 'z')
                {
                    s[j] = 'a';
                }
                else
                {
                    ++s[j];
                    carry = 0;
                }
            }
            if (carry > 0)
            {
                s = "a" + s;
            }

            vector_.push_back(s);
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