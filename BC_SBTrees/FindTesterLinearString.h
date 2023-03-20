#pragma once
#include "TreeTester.h"

template<typename TreeType>
class FindTesterLinearString : public TreeAnalyzer<TreeType>
{
public:
    FindTesterLinearString(TreeType* tree, int repNumb, int stepSize, int stepCount, std::string name)
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
            this->tree_->insert(s, i);
        }
        
        return reverseVector(vector_);
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

    std::vector<std::string> reverseVector(const std::vector<std::string>& vec) {
        std::vector<std::string> reversedVec(vec.rbegin(), vec.rend());
        return reversedVec;
    }
};

