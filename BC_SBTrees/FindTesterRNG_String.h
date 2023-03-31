#pragma once
#include "TreeTester.h"

template<typename TreeType>
class FindTesterRNG_String : public TreeAnalyzer<TreeType>
{
public:
    FindTesterRNG_String(TreeType* tree, int repNumb, int stepSize, int stepCount, std::string name)
        : TreeAnalyzer<TreeType>(tree, repNumb, stepSize, stepCount, name) {};

    using TreeTester<TreeType>::currentStep_;
    using TreeTester<TreeType>::stepSize_;
    using TreeTester<TreeType>::tree_;

    // Inherited via TreeAnalyzer
    virtual void prepare(std::vector<typename TreeType::key_type>* vector_) override
    {
        std::string s = "a";
        int iterations = stepSize_ * currentStep_;
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

            vector_->push_back(s);
            this->tree_->insert(s, i);
        }

        std::random_device rd;
        std::mt19937 gen(rd());
        std::shuffle(vector_->begin(), vector_->end(), gen);

    }

    virtual int execute(std::vector<typename TreeType::key_type>* vector) override
    {
        for (auto& key : *vector)
        {
            this->tree_->find(key);
        }
        return 0;
    }

    virtual void clear() override
    {
        this->tree_->clear();
    }

};

