#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <chrono>


template<typename TreeType>
class TreeTester
{
public:
	TreeTester(TreeType* tree,int repNumb, int stepSize, int stepCount, std::string name) {
		setNumberOfReplications(repNumb);
		setStepSize(stepSize);
		setStepCount(stepCount);
		setTree(tree);
		setCSVName(name);
	};
	~TreeTester() = default;
	void setNumberOfReplications(int number);
	void setStepSize(int number);
	void setStepCount(int number);
	void setCSVName(std::string name);
	void setTree(TreeType* tree);
	std::string getName() {
		return name_;
	};
	virtual void analyze() = 0;

protected:
	int numberOfReplications_;
	int stepCount_;
	int stepSize_;
	int currentStep_ = 1;
	std::string name_;
	TreeType* tree_;
};

template<typename TreeType>
void TreeTester<TreeType>::setNumberOfReplications(int number)
{
	numberOfReplications_ = number;
}

template<typename TreeType>
class TreeAnalyzer : public TreeTester<TreeType>
{
public:
	TreeAnalyzer(TreeType* tree, int repNumb, int stepSize, int stepCount, std::string name) 
		: TreeTester<TreeType>(tree, repNumb, stepSize, stepCount, name) {
	};
	// Inherited via TreeTester
	using TreeTester<TreeType>::name_;
	using TreeTester<TreeType>::numberOfReplications_;
	using TreeTester<TreeType>::currentStep_;
	using TreeTester<TreeType>::stepSize_;
	using TreeTester<TreeType>::stepCount_;
	
	virtual void prepare() = 0;
	virtual void execute() = 0;
	virtual void clear() = 0;
	virtual void analyze() override
	{
		std::string filename = TreeTester<TreeType>::getName();
		std::ofstream outputFile(filename);
		
		int deliverNumber = TreeTester<TreeType>::numberOfReplications_;
		if (outputFile.is_open()) {
			for (int i = 0; i < stepCount_; i++)
			{
				int repNum = TreeTester<TreeType>::numberOfReplications_;
				auto replicationsDuration = std::chrono::microseconds(0);
				while (repNum > 0)
				{
					this->prepare();
					auto startTime = std::chrono::high_resolution_clock::now();
					this->execute();
					auto endTime = std::chrono::high_resolution_clock::now();
					
					this->clear();
					auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
					replicationsDuration += duration;
				
					repNum --;

				}
				std::cout << i << std::endl;
				outputFile << TreeTester<TreeType>::currentStep_ * TreeTester<TreeType>::stepSize_ << ";" << replicationsDuration.count()/deliverNumber << std::endl;
				currentStep_++;
			}
		}
		else {
			std::cout << "Error opening file: " << filename << std::endl;
		}
	}
};



template<typename TreeType>
void TreeTester<TreeType>::setStepSize(int number)
{
	stepSize_ = number;
}

template<typename TreeType>
void TreeTester<TreeType>::setStepCount(int number)
{
	stepCount_ = number;
}

template<typename TreeType>
void TreeTester<TreeType>::setCSVName(std::string name)
{
	name_ = name;
}

template<typename TreeType>
void TreeTester<TreeType>::setTree(TreeType* tree)
{
	tree_ = tree;
}
