#pragma once
#include "TreeTester.h"

template<typename TreeType>
class InsertTester :
    public TreeAnalyzer<TreeType>
{
public:
	InsertTester(TreeType* tree, int repNumb, int stepSize, int stepCount, std::string name)
		: TreeAnalyzer<TreeType>(tree, repNumb, stepSize, stepCount, name) {};

	using TreeTester<TreeType>::currentStep_;
	using TreeTester<TreeType>::stepSize_;
	using TreeTester<TreeType>::tree_;
	
	// Inherited via TreeAnalyzer
	virtual void prepare() override
	{
		
	}
	virtual void execute() override 
	{
		for (int i = 0; i < stepSize_ * currentStep_; i = i + 1)
		{
			tree_->insert(i, i + 1);
		}
		
	}
	virtual void clear() override
	{
		tree_->clear();
	}
};
