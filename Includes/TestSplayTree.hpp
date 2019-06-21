#ifndef TEST_AVL_TREE_HPP
#define TEST_AVL_TREE_HPP

/*******************************************************************
*						Here be Dragons
********************************************************************/

#include "TestingBase.hpp"
#include <cstdint>
#include <iostream>

#if __has_include("SplayTree.h")
#include "SplayTree.h"
#include <initializer_list>
#include <vector>
#include <algorithm>
#include <random>
#include <iomanip>
#include <chrono>
#include <limits>
namespace UnitTests::SPLAYTREE
{


GENERATE_SAME_NAME_HAS_MEMBER_FUNCTION(insert)
GENERATE_SAME_NAME_HAS_MEMBER_FUNCTION(remove)
GENERATE_SAME_NAME_HAS_MEMBER_FUNCTION(find)
GENERATE_SAME_NAME_HAS_MEMBER_FUNCTION(size)
GENERATE_SAME_NAME_HAS_CONST_MEMBER_FUNCTION(size)
GENERATE_SAME_NAME_HAS_MEMBER_FUNCTION(getMin)
GENERATE_SAME_NAME_HAS_MEMBER_FUNCTION(getMax)
GENERATE_SAME_NAME_HAS_MEMBER_FUNCTION(getRoot)
GENERATE_SAME_NAME_HAS_CONST_MEMBER_FUNCTION(getRoot)
GENERATE_SAME_NAME_HAS_MEMBER_FUNCTION(preOrderWalk)
GENERATE_SAME_NAME_HAS_CONST_MEMBER_FUNCTION(preOrderWalk)
GENERATE_SAME_NAME_HAS_MEMBER_FUNCTION(inOrderWalk)
GENERATE_SAME_NAME_HAS_CONST_MEMBER_FUNCTION(inOrderWalk)
GENERATE_SAME_NAME_HAS_MEMBER_FUNCTION(postOrderWalk)
GENERATE_SAME_NAME_HAS_CONST_MEMBER_FUNCTION(postOrderWalk)

static constexpr bool SplayTree_IsDefaultConstructible =    std::is_default_constructible<SplayTree<int>>::value &&
                                                            std::is_default_constructible<SplayTree<std::string>>::value;

static constexpr bool SplayTree_has_insert = 
                                            (has_insert<SplayTree<int>, void, int>::value ||
                                                has_insert<SplayTree<int>, void, int&>::value ||
                                                has_insert<SplayTree<int>, void, const int>::value ||
                                                has_insert<SplayTree<int>, void, const int&>::value)
                                            &&
                                            (has_insert<SplayTree<std::string>, void, std::string>::value ||
                                                has_insert<SplayTree<std::string>, void, std::string&>::value ||
                                                has_insert<SplayTree<std::string>, void, const std::string>::value ||
                                                has_insert<SplayTree<std::string>, void, const std::string&>::value);

static constexpr bool SplayTree_has_remove = 
                                            (has_remove<SplayTree<int>, void, int>::value ||
                                                has_remove<SplayTree<int>, void, int&>::value ||
                                                has_remove<SplayTree<int>, void, const int>::value ||
                                                has_remove<SplayTree<int>, void, const int&>::value)
                                            &&
                                            (has_remove<SplayTree<std::string>, void, std::string>::value ||
                                                has_remove<SplayTree<std::string>, void, std::string&>::value ||
                                                has_remove<SplayTree<std::string>, void, const std::string>::value ||
                                                has_remove<SplayTree<std::string>, void, const std::string&>::value);

static constexpr bool SplayTree_has_find = 
                                            (has_find<SplayTree<int>, bool, int>::value ||
                                                has_find<SplayTree<int>, bool, int&>::value ||
                                                has_find<SplayTree<int>, bool, const int>::value ||
                                                has_find<SplayTree<int>, bool, const int&>::value)
                                            &&
                                            (has_find<SplayTree<std::string>, bool, std::string>::value ||
                                                has_find<SplayTree<std::string>, bool, std::string&>::value ||
                                                has_find<SplayTree<std::string>, bool, const std::string>::value ||
                                                has_find<SplayTree<std::string>, bool, const std::string&>::value);

static constexpr bool SplayTree_has_size = 
                                            (has_size<SplayTree<int>, std::size_t>::value ||
                                                has_const_size<SplayTree<int>, std::size_t>::value)
                                            &&
                                            (has_size<SplayTree<std::string>, std::size_t>::value ||
                                                has_const_size<SplayTree<std::string>, std::size_t>::value);


static constexpr bool SplayTree_has_getMin = 
                                            (has_getMin<SplayTree<int>, int>::value ||
                                                has_getMin<SplayTree<int>, int&>::value ||
                                                has_getMin<SplayTree<int>, const int>::value ||
                                                has_getMin<SplayTree<int>, const int&>::value)
                                            &&
                                            (has_getMin<SplayTree<std::string>, std::string>::value ||
                                                has_getMin<SplayTree<std::string>, std::string&>::value ||
                                                has_getMin<SplayTree<std::string>, const std::string>::value ||
                                                has_getMin<SplayTree<std::string>, const std::string&>::value);

static constexpr bool SplayTree_has_getMax = 
                                            (has_getMax<SplayTree<int>, int>::value ||
                                                has_getMax<SplayTree<int>, int&>::value ||
                                                has_getMax<SplayTree<int>, const int>::value ||
                                                has_getMax<SplayTree<int>, const int&>::value)
                                            &&
                                            (has_getMax<SplayTree<std::string>, std::string>::value ||
                                                has_getMax<SplayTree<std::string>, std::string&>::value ||
                                                has_getMax<SplayTree<std::string>, const std::string>::value ||
                                                has_getMax<SplayTree<std::string>, const std::string&>::value);


static constexpr bool SplayTree_has_getRoot = 
                                            (has_getRoot<SplayTree<int>, int>::value ||
                                                has_getRoot<SplayTree<int>, int&>::value ||
                                                has_getRoot<SplayTree<int>, const int>::value ||
                                                has_getRoot<SplayTree<int>, const int&>::value ||
                                                has_const_getRoot<SplayTree<int>, int>::value ||
                                                has_const_getRoot<SplayTree<int>, int&>::value ||
                                                has_const_getRoot<SplayTree<int>, const int>::value ||
                                                has_const_getRoot<SplayTree<int>, const int&>::value)
                                            &&
                                            (has_getRoot<SplayTree<std::string>, std::string>::value ||
                                                has_getRoot<SplayTree<std::string>, std::string&>::value ||
                                                has_getRoot<SplayTree<std::string>, const std::string>::value ||
                                                has_getRoot<SplayTree<std::string>, const std::string&>::value ||
                                                has_const_getRoot<SplayTree<std::string>, std::string>::value ||
                                                has_const_getRoot<SplayTree<std::string>, std::string&>::value ||
                                                has_const_getRoot<SplayTree<std::string>, const std::string>::value ||
                                                has_const_getRoot<SplayTree<std::string>, const std::string&>::value);


static constexpr bool SplayTree_has_preOrderWalk = 
                                            (has_preOrderWalk<SplayTree<int>, std::vector<int>>::value ||
                                                has_const_preOrderWalk<SplayTree<int>, std::vector<int>>::value)
                                            &&
                                            (has_preOrderWalk<SplayTree<std::string>, std::vector<std::string>>::value ||
                                                has_const_preOrderWalk<SplayTree<std::string>,std::vector<std::string>>::value);

static constexpr bool SplayTree_has_inOrderWalk = 
                                            (has_inOrderWalk<SplayTree<int>, std::vector<int>>::value ||
                                                has_const_inOrderWalk<SplayTree<int>, std::vector<int>>::value)
                                            &&
                                            (has_inOrderWalk<SplayTree<std::string>, std::vector<std::string>>::value ||
                                                has_const_inOrderWalk<SplayTree<std::string>,std::vector<std::string>>::value);

static constexpr bool SplayTree_has_postOrderWalk = 
                                            (has_postOrderWalk<SplayTree<int>, std::vector<int>>::value ||
                                                has_const_postOrderWalk<SplayTree<int>, std::vector<int>>::value)
                                            &&
                                            (has_postOrderWalk<SplayTree<std::string>, std::vector<std::string>>::value ||
                                                has_const_postOrderWalk<SplayTree<std::string>,std::vector<std::string>>::value);

/**
 * 
 * Unit Tests starts
 * 
 * 
*/


std::string VectorToString(const std::vector<int> &toTransform)
{
    std::string content = "{";
    for(auto &&nodeElement : toTransform)
    {
        content += std::to_string(nodeElement) + ", ";
    }

    if(toTransform.size())
    {
        content.pop_back();
        content.pop_back();
    }
    content += "}";
    return content;
}

template <typename T = SplayTree<int>>
bool PreOrderWalkCheck(const std::vector<int> &expectedOrder, T &tree, size_t textIndentionLevel)
{
    bool passed = false;
    if constexpr(SplayTree_has_preOrderWalk)
    {
        passed = true;
        ++textIndentionLevel;
        std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::preOrderWalk will be used to control the structure." << std::endl;

        std::vector<int> treeOrder = tree.preOrderWalk();
        ++textIndentionLevel;
        std::cout << std::string(textIndentionLevel, '\t') + "Expected the ordered set " + VectorToString(expectedOrder) + "\n";
        
        std::cout << std::string(textIndentionLevel, '\t') + "Returned the ordered set " + VectorToString(treeOrder) + "\n";
        --textIndentionLevel;
        if(treeOrder != expectedOrder)
        {
            passed = false;
            std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::preOrderWalk did not return the expected ordered set.\n";
        }
        --textIndentionLevel;
    }
    return passed;
}

template <typename T = SplayTree<int>>
bool InOrderWalkCheck(const std::vector<int> &expectedOrder, T &tree, size_t textIndentionLevel)
{
    bool passed = false;
    if constexpr(SplayTree_has_inOrderWalk)
    {
        passed = true;
        ++textIndentionLevel;
        std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::inOrderWalk will be used to control the structure." << std::endl;

        std::vector<int> treeOrder = tree.inOrderWalk();
        ++textIndentionLevel;
        std::cout << std::string(textIndentionLevel, '\t') + "Expected the ordered set " + VectorToString(expectedOrder) + "\n";
        
        std::cout << std::string(textIndentionLevel, '\t') + "Returned the ordered set " + VectorToString(treeOrder) + "\n";
        --textIndentionLevel;
        if(treeOrder != expectedOrder)
        {
            passed = false;
            std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::inOrderWalk did not return the expected ordered set.\n";
        }
        --textIndentionLevel;
    }
    return passed;
}

template <typename T = SplayTree<int>>
bool PostOrderWalkCheck(const std::vector<int> &expectedOrder, T &tree, size_t textIndentionLevel)
{
    bool passed = false;
    if constexpr(SplayTree_has_postOrderWalk)
    {
        passed = true;
        ++textIndentionLevel;
        std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::postOrderWalk will be used to control the structure." << std::endl;

        std::vector<int> treeOrder = tree.postOrderWalk();
        ++textIndentionLevel;
        std::cout << std::string(textIndentionLevel, '\t') + "Expected the ordered set " + VectorToString(expectedOrder) + "\n";
        
        std::cout << std::string(textIndentionLevel, '\t') + "Returned the ordered set " + VectorToString(treeOrder) + "\n";
        --textIndentionLevel;
        if(treeOrder != expectedOrder)
        {
            passed = false;
            std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::postOrderWalk did not return the expected ordered set.\n";
        }
        --textIndentionLevel;
    }
    return passed;
}

template <typename T = SplayTree<int>>
bool ControllWithAllWalks(T &tree, const std::vector<int> &expectedPreOrderResult, const std::vector<int> &expectedInOrderResult, 
                            const std::vector <int> &expectedPostOrderResult, size_t textIndentionLevel)
{
    bool passed = false;
    if constexpr(SplayTree_has_preOrderWalk || SplayTree_has_inOrderWalk ||SplayTree_has_postOrderWalk)
    {
        passed = true;
        ++textIndentionLevel;
        std::cout << std::string(textIndentionLevel, '\t') + "One or more \"OrderWalk\" functions implemented. Controls will be conducted to make sure that the datastructure looks as expected.\n";

        if constexpr(SplayTree_has_preOrderWalk)
        {
            passed &= PreOrderWalkCheck(expectedPreOrderResult, tree, textIndentionLevel);
        }
        else
        {
            passed = false;
            ++textIndentionLevel;
            std::cout << std::string(textIndentionLevel, '\t') + "This test cannot succeed before all \"OrderWalk\" functions are implemented." << std::endl;
            std::cout << std::string(textIndentionLevel, '\t') + "This test expect the Pre-order: " << VectorToString(expectedPreOrderResult) << '\n';
            --textIndentionLevel;
        }
        if constexpr(SplayTree_has_inOrderWalk)
        {
            passed &= InOrderWalkCheck(expectedInOrderResult, tree, textIndentionLevel);
        }
        else
        {
            if(!passed)
            {
                passed = false;
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "This test cannot succeed before all \"OrderWalk\" functions are implemented." << std::endl;
                std::cout << std::string(textIndentionLevel, '\t') + "This test expect the In-order: " << VectorToString(expectedInOrderResult) << '\n';
                --textIndentionLevel;
            }
        }
        if constexpr(SplayTree_has_postOrderWalk)
        {
            passed &= PostOrderWalkCheck(expectedPostOrderResult, tree, textIndentionLevel);
        }
        else
        {
            if(!passed)
            {
                passed = false;
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "This test cannot succeed before all \"OrderWalk\" functions are implemented." << std::endl;
                std::cout << std::string(textIndentionLevel, '\t') + "This test expect the Post-order: " << VectorToString(expectedPostOrderResult) << '\n';
                --textIndentionLevel;
            }
        }
        
        if(passed)
            std::cout << std::string(textIndentionLevel, '\t') + "All \"OrderWalk\" functions indicates expected SplayTree." << std::endl;
        else
            std::cout << std::string(textIndentionLevel, '\t') + "One or more \"OrderWalk\" functions indicates an incorrect SplayTree." << std::endl;

        --textIndentionLevel;
    }
    else
    {
        passed = false;
        ++textIndentionLevel;
        std::cout << std::string(textIndentionLevel, '\t') + "This test cannot succeed before all \"OrderWalk\" functions are implemented." << std::endl;
        std::cout << std::string(textIndentionLevel, '\t') + "This test expect the Pre-order: " << VectorToString(expectedPreOrderResult) << '\n';
        std::cout << std::string(textIndentionLevel, '\t') + "This test expect the In-order: " << VectorToString(expectedInOrderResult) << '\n';
        std::cout << std::string(textIndentionLevel, '\t') + "This test expect the Post-order: " << VectorToString(expectedPostOrderResult) << '\n';

        --textIndentionLevel;
    }
    return passed;
}

template <typename T = SplayTree<int>>
bool GetRootHelpFunction(T &tree, int expectedValue, size_t textIndentionLevel)
{
    bool passed = false;
    if constexpr (SplayTree_has_getRoot)
    {
        passed = true;
        int current = tree.getRoot();
        if(current != expectedValue)
        {
            passed = false;
            ++textIndentionLevel;
            std::cout << std::string(textIndentionLevel, '\t') + "Control with SplayTree::getRoot indicates failure.\n";
            ++textIndentionLevel;
            std::cout << std::string(textIndentionLevel, '\t') + "Expected root: " << expectedValue <<'\n';
            std::cout << std::string(textIndentionLevel, '\t') + "Returned root: " << current << '\n';
            --textIndentionLevel;
            --textIndentionLevel;
        }
    }
    return passed;
}

template <typename T = SplayTree<int>>
bool SizeHelpFunction(T &tree, size_t expectedSize, size_t textIndentionLevel)
{
    bool passed = false;   
    if constexpr (SplayTree_has_size)
    {
        passed = true;
        size_t currentSize = tree.size();
        if(expectedSize != currentSize)
        {
            passed = false;
            ++textIndentionLevel;
            std::cout << std::string(textIndentionLevel, '\t') + "Control with SplayTree::size indicates error.\n";
            ++textIndentionLevel;
            std::cout << std::string(textIndentionLevel, '\t') + "Expected size: " << expectedSize << '\n';
            std::cout << std::string(textIndentionLevel, '\t') + "Returned size: " << currentSize << '\n';
            --textIndentionLevel;
            --textIndentionLevel;
        }
    }
    return passed;
}

template <typename T = SplayTree<int>>
bool InsertionHelpFunction(const std::vector<int> &insertionOrder, T &tree, size_t textIndentionLevel)
{
    bool passed = true;
    size_t counter = 0;

    for(auto element : insertionOrder)
    {
        ++counter;
        std::cout << std::string(textIndentionLevel, '\t') + "Inserting element: " << element <<'\n';
        
        tree.insert(element);

        passed &= GetRootHelpFunction(tree, element, textIndentionLevel);
        passed &= SizeHelpFunction(tree, counter, textIndentionLevel);
        
    }
    return passed;
}

template <typename T = SplayTree<int>>
bool TestInsert()
{
	std::size_t textIndentionLevel = 1;
	std::cout << '\n';
	std::cout << std::string(textIndentionLevel, '\t') + "Start: SplayTree::insert tests\n";
	++textIndentionLevel;
    if constexpr(SplayTree_has_insert)
    {
        bool passed = true;
        /**
		 * 
		 * Exception tests
		 * 
		*/
		{
			std::cout << std::string(textIndentionLevel, '\t') + "Starting basic exception test.\n";
			++textIndentionLevel;
			auto callable = [](){
				T tree;
                int toInsert = 5;
				tree.insert(toInsert);
			};
			bool passOnCatch = false;
			std::string currentTest = "SplayTree::insert on empty structure";
			std::string onFailMessage = "This function should not throw an exception on an empty structure, due to this being a recoverable situation (insert the element).";
			if(!TryCatchHelper(callable, passOnCatch, textIndentionLevel, currentTest, onFailMessage))
			{
				textIndentionLevel = 3;
				std::cout << std::string(textIndentionLevel, '\t') + "Ending basic exception test\n";
				--textIndentionLevel;
				std::cout << std::string(textIndentionLevel, '\t') + "Further testing cannot be conducted.\n";
				--textIndentionLevel;
				std::cout << std::string(textIndentionLevel, '\t') + "End: SplayTree::insert tests" << std::endl;
				return false;
			}
			--textIndentionLevel;

			++textIndentionLevel;
			auto callable2 = [](){
				T tree;
                int toInsert = 5;
				tree.insert(toInsert);
				tree.insert(toInsert);
			};
			passOnCatch = false;
			currentTest = "SplayTree::insert duplicate";
			onFailMessage = "This function should not throw an exception on insertion of a duplicate, due to this being a recoverable situation (ignore the duplicate).";
			if(!TryCatchHelper(callable2, passOnCatch, textIndentionLevel, currentTest, onFailMessage))
			{
				textIndentionLevel = 3;
				std::cout << std::string(textIndentionLevel, '\t') + "Ending basic exception test\n";
				--textIndentionLevel;
				std::cout << std::string(textIndentionLevel, '\t') + "Further testing cannot be conducted.\n";
				--textIndentionLevel;
				std::cout << std::string(textIndentionLevel, '\t') + "End: SplayTree::insert tests" << std::endl;
				return false;
			}
			--textIndentionLevel;
            

			std::cout << std::string(textIndentionLevel, '\t') + "Ending basic exception test.\n";
		}

        /**
         * The basic test will insert 10 elements in the splay tree.
         *  -If getRoot is implemented, it will be used to check so that the last inserted element is now root
         *  -If any of the walks are implemented, this will be used to control the ordering
         *      -If multiple walks are implemented, they will all be used
         *  -If size is implemented, this will be used to control so that the size is correct
        */ 
        {
            std::cout << '\n';
            std::cout << std::string(textIndentionLevel, '\t') + "Starting basic insert test.\n";
            ++textIndentionLevel;
            std::cout << std::string(textIndentionLevel, '\t') + "Extra control(s) for this test: " << std::endl;

            if constexpr(!(SplayTree_has_size))
            {
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "Cannot control if calls to SplayTree::insert causes the size to change correctly.\n";
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "Further controls will be conducted when SplayTree::size is implemented." << std::endl;
                --textIndentionLevel;
                --textIndentionLevel;					
            }
            else
            {
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::size is implemented.\n";
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "Controls will be conducted to make sure that SplayTree::insert reports correct size once done.\n";
                --textIndentionLevel;
                --textIndentionLevel;
            }
            if constexpr(!(SplayTree_has_getRoot))
            {
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "Cannot control if calls to SplayTree::insert caused the expected element to become root.\n";
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "Further controls will be conducted when SplayTree::getRoot is implemented." << std::endl;
                --textIndentionLevel;
                --textIndentionLevel;
            }
            else
            {
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::getRoot is implemented.\n";
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "Controls will be conducted to make sure that SplayTree::insert caused the expected element to become root.\n";
                --textIndentionLevel;
                --textIndentionLevel;
            }
            if constexpr(!(SplayTree_has_preOrderWalk || SplayTree_has_inOrderWalk || SplayTree_has_postOrderWalk))
            {
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "Cannot control if calls to SplayTree::insert caused the expected ordering of elements.\n";
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "Further controls will be conducted when any of the \"orderWalk\" functions are implemented." << std::endl;
                --textIndentionLevel;
                --textIndentionLevel;
            }
            else
            {
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "One or more of the \"orderWalk\" functions implented.\n";
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "Controls will be conducted to make sure that SplayTree::insert caused the expected ordering of elements.\n";
                --textIndentionLevel;
                --textIndentionLevel;
            }
            {
                std::cout << std::string(textIndentionLevel, '\t') + "This test will insert the set {9, 8, 7, 6, 5, 4, 3, 2, 1, 0} into the structure using SplayTree::insert.\n";

                T tree;
                std::vector<int> insertionSet = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
                ++textIndentionLevel;
                for(auto &&element : insertionSet)
                {
                    std::cout << std::string(textIndentionLevel, '\t') + "Inserting element: " << element << '\n';
                    tree.insert(element);
                    if constexpr(SplayTree_has_getRoot)
                    {
                        ++textIndentionLevel;
                        int currentRoot = tree.getRoot();
                        if(currentRoot != element)
                        {
                            std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::getRoot indicates error after insertion of element: " << element << '\n';
                            ++textIndentionLevel;
                            std::cout << std::string(textIndentionLevel, '\t') + "Expected root: " << element << '\n';
                            std::cout << std::string(textIndentionLevel, '\t') + "Returned root: " << currentRoot << '\n';
                            --textIndentionLevel;
                            passed = false;
                        }
                        --textIndentionLevel;
                    }
                    if constexpr(SplayTree_has_preOrderWalk)
                    {
                        std::vector<int> walkVector = tree.preOrderWalk();
                        if(!(std::is_sorted(walkVector.begin(), walkVector.end())) || !(walkVector.size()))
                        {
                            std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::preOrderWalk indicates error after insertion of element: " << element << '\n';
                            ++textIndentionLevel;
                            std::string content = "";
                            content.clear();

                            auto insertedEnd = std::find(insertionSet.begin(), insertionSet.end(), element);

                            for(auto itr = insertionSet.begin(); itr != insertedEnd; ++itr)
                            {
                                content += std::to_string(*itr) + ", ";
                            }
                            content += std::to_string(*insertedEnd);

                            std::cout << std::string(textIndentionLevel, '\t') + "Expected order: {" << content << "}\n";

                            content.clear();
                            content = "";
                            for(auto inserted : walkVector)
                            {
                                content += std::to_string(inserted) + ", ";
                            }
                            
                            if(walkVector.size())
                            {
                                content.pop_back();
                                content.pop_back();
                            }

                            std::cout << std::string(textIndentionLevel, '\t') + "Returned order: {" << content << "}\n";
                            --textIndentionLevel;
                            passed = false;
                        }
                    }
                    if constexpr(SplayTree_has_inOrderWalk)
                    {
                        std::vector<int> walkVector = tree.inOrderWalk();
                        if(!(std::is_sorted(walkVector.begin(), walkVector.end())) || !(walkVector.size()))
                        {
                            std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::inOrderWalk indicates error after insertion of element: " << element << '\n';
                            ++textIndentionLevel;
                            std::string content = "";
                            content.clear();
                            auto insertedEnd = std::find(insertionSet.begin(), insertionSet.end(), element);
                            
                            for(auto itr = insertedEnd; itr != insertionSet.begin(); --itr)
                            {
                                content += std::to_string(*itr) + ", ";
                            }
                            content += std::to_string(*insertionSet.begin());

                            std::cout << std::string(textIndentionLevel, '\t') + "Expected order: {" << content << "}\n";
                            content.clear();
                            content = "";
                            for(auto inserted : walkVector)
                            {
                                content += std::to_string(inserted) + ", ";
                            }
                            
                            if(walkVector.size())
                            {
                                content.pop_back();
                                content.pop_back();
                            }

                            std::cout << std::string(textIndentionLevel, '\t') + "Returned order: {" << content << "}\n";
                            --textIndentionLevel;
                            passed = false;
                        }
                    }
                    if constexpr(SplayTree_has_postOrderWalk)
                    {
                        std::vector<int> walkVector = tree.postOrderWalk();
                        if(!(std::is_sorted(walkVector.rbegin(), walkVector.rend())) || !(walkVector.size()))
                        {
                            std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::postOrderWalk indicates error after insertion of element: " << element << '\n';
                            ++textIndentionLevel;
                            std::string content = "";
                            content.clear();
                            auto insertedEnd = std::find(insertionSet.begin(), insertionSet.end(), element);

                            for(auto itr = insertedEnd; itr != insertionSet.begin(); --itr)
                            {
                                content += std::to_string(*itr) + ", ";
                            }
                            content += std::to_string(*insertionSet.begin());

                            std::cout << std::string(textIndentionLevel, '\t') + "Expected order: {" << content << "}\n";

                            content = "";
                            content.clear();
                            for(auto inserted : walkVector)
                            {
                                content += std::to_string(inserted) + ", ";
                            }
                            
                            if(walkVector.size())
                            {
                                content.pop_back();
                                content.pop_back();
                            }

                            std::cout << std::string(textIndentionLevel, '\t') + "Returned order: {" << content << "}\n";
                            --textIndentionLevel;
                            passed = false;
                        }
                    }
                }
                --textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "Insert with set {9, 8, 7, 6, 5, 4, 3, 2, 1, 0} finished.\n";
            }
            {
                std::cout << std::string(textIndentionLevel, '\t') + "This test will insert the set {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} into the structure using SplayTree::insert.\n";

                T tree;
                std::vector<int> insertionSet = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
                ++textIndentionLevel;
                for(auto &&element : insertionSet)
                {
                    std::cout << std::string(textIndentionLevel, '\t') + "Inserting element: " << element << '\n';
                    tree.insert(element);
                    if constexpr(SplayTree_has_getRoot)
                    {
                        ++textIndentionLevel;
                        int currentRoot = tree.getRoot();
                        if(currentRoot != element)
                        {
                            std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::getRoot indicates error after insertion of element: " << element << '\n';
                            ++textIndentionLevel;
                            std::cout << std::string(textIndentionLevel, '\t') + "Expected root: " << element << '\n';
                            std::cout << std::string(textIndentionLevel, '\t') + "Returned root: " << currentRoot << '\n';
                            --textIndentionLevel;
                            passed = false;
                        }
                        --textIndentionLevel;
                    }
                    if constexpr(SplayTree_has_preOrderWalk)
                    {
                        std::vector<int> walkVector = tree.preOrderWalk();
                        if(!(std::is_sorted(walkVector.rbegin(), walkVector.rend())) || !(walkVector.size()))
                        {
                            std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::preOrderWalk indicates error after insertion of element: " << element << '\n';
                            ++textIndentionLevel;
                            std::string content = "";
                            content.clear();

                            auto insertedEnd = std::find(insertionSet.begin(), insertionSet.end(), element);

                            for(auto itr = insertedEnd; itr != insertionSet.begin(); --itr)
                            {
                                content += std::to_string(*itr) + ", ";
                            }
                            content += std::to_string(*insertionSet.begin());

                            std::cout << std::string(textIndentionLevel, '\t') + "Expected order: {" << content << "}\n";

                            content.clear();
                            content = "";
                            for(auto inserted : walkVector)
                            {
                                content += std::to_string(inserted) + ", ";
                            }
                            
                            if(walkVector.size())
                            {
                                content.pop_back();
                                content.pop_back();
                            }

                            std::cout << std::string(textIndentionLevel, '\t') + "Returned order: {" << content << "}\n";
                            --textIndentionLevel;
                            passed = false;
                        }                        
                    }
                    if constexpr(SplayTree_has_inOrderWalk)
                    {
                        std::vector<int> walkVector = tree.inOrderWalk();
                        if(!(std::is_sorted(walkVector.begin(), walkVector.end())) || !(walkVector.size()))
                        {
                            std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::inOrderWalk indicates error after insertion of element: " << element << '\n';
                            ++textIndentionLevel;
                            std::string content = "";
                            content.clear();
                            auto insertedEnd = std::find(insertionSet.begin(), insertionSet.end(), element);
                            
                            for(auto itr = insertedEnd; itr != insertionSet.begin(); --itr)
                            {
                                content += std::to_string(*itr) + ", ";
                            }
                            content += std::to_string(*insertionSet.begin());

                            std::cout << std::string(textIndentionLevel, '\t') + "Expected order: {" << content << "}\n";
                            content.clear();
                            content = "";
                            for(auto inserted : walkVector)
                            {
                                content += std::to_string(inserted) + ", ";
                            }
                            
                            if(walkVector.size())
                            {
                                content.pop_back();
                                content.pop_back();
                            }

                            std::cout << std::string(textIndentionLevel, '\t') + "Returned order: {" << content << "}\n";
                            --textIndentionLevel;
                            passed = false;
                        }
                    }
                    if constexpr(SplayTree_has_postOrderWalk)
                    {
                        std::vector<int> walkVector = tree.postOrderWalk();
                        if(!(std::is_sorted(walkVector.begin(), walkVector.end())) || !(walkVector.size()))
                        {
                            std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::postOrderWalk indicates error after insertion of element: " << element << '\n';
                            ++textIndentionLevel;
                            std::string content = "";
                            content.clear();
                            auto insertedEnd = std::find(insertionSet.begin(), insertionSet.end(), element);

                            for(auto itr = insertionSet.begin(); itr != insertedEnd; ++itr)
                            {
                                content += std::to_string(*itr) + ", ";
                            }
                            content += std::to_string(*insertedEnd);

                            std::cout << std::string(textIndentionLevel, '\t') + "Expected order: {" << content << "}\n";

                            content = "";
                            content.clear();
                            for(auto inserted : walkVector)
                            {
                                content += std::to_string(inserted) + ", ";
                            }
                            
                            if(walkVector.size())
                            {
                                content.pop_back();
                                content.pop_back();
                            }

                            std::cout << std::string(textIndentionLevel, '\t') + "Returned order: {" << content << "}\n";
                            --textIndentionLevel;
                            passed = false;
                        }
                    }
                }
                --textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "Insert with set {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} finished.\n";
            }
            
            --textIndentionLevel;
            std::cout << std::string(textIndentionLevel, '\t') + "Ending basic insertion test." << std::endl;
        }
        /**
         * Intermediate insert test
         * 
         * 
        */ 
        {
            std::cout << '\n';
            std::cout << std::string(textIndentionLevel, '\t') + "Starting intermediate insert test.\n";
            ++textIndentionLevel;
            std::cout << std::string(textIndentionLevel, '\t') + "Extra control(s) for this test: " << std::endl;

            if constexpr(!(SplayTree_has_size))
            {
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "Cannot control if calls to SplayTree::insert causes the size to change correctly.\n";
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "Further controls will be conducted when SplayTree::size is implemented." << std::endl;
                --textIndentionLevel;
                --textIndentionLevel;					
            }
            else
            {
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::size is implemented.\n";
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "Controls will be conducted to make sure that SplayTree::insert reports correct size once done.\n";
                --textIndentionLevel;
                --textIndentionLevel;
            }
            if constexpr(!(SplayTree_has_getRoot))
            {
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "Cannot control if calls to SplayTree::insert caused the expected element to become root.\n";
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "Further controls will be conducted when SplayTree::getRoot is implemented." << std::endl;
                --textIndentionLevel;
                --textIndentionLevel;
            }
            else
            {
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::getRoot is implemented.\n";
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "Controls will be conducted to make sure that SplayTree::insert caused the expected element to become root.\n";
                --textIndentionLevel;
                --textIndentionLevel;
            }
            if constexpr(!(SplayTree_has_preOrderWalk || SplayTree_has_inOrderWalk || SplayTree_has_postOrderWalk))
            {
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "Cannot control if calls to SplayTree::insert caused the expected ordering of elements.\n";
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "Further controls will be conducted when any of the \"orderWalk\" functions are implemented." << std::endl;
                --textIndentionLevel;
                --textIndentionLevel;
            }
            else
            {
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "One or more of the \"orderWalk\" functions implented.\n";
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "Controls will be conducted to make sure that SplayTree::insert caused the expected ordering of elements.\n";
                --textIndentionLevel;
                --textIndentionLevel;
            }

            std::cout << std::string(textIndentionLevel, '\t') + "This test will start with inserting the set {8, 6, 7, 5, 9} into the datastructure.\n";
            ++textIndentionLevel;
            T tree;
            std::vector<int> insertionOrder = {8, 6, 7, 5, 9};
            size_t counter = 0;
            for(auto &&element : insertionOrder)
            {

                std::cout << std::string(textIndentionLevel, '\t') + "Inserting element: " << element <<'\n';
                
                if(element == 5)
                {
                    ++textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "This insertion will cause a zig-zig to be conducted." << std::endl;
                    --textIndentionLevel;
                }
                else if(element == 7)
                {
                    ++textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "This insertion will cause a zig-zag to be conducted." << std::endl;
                    --textIndentionLevel;
                }
                else if(element == 9)
                {
                    ++textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "This insertion will cause a zig-zig followed by a zig-zig to be conducted." << std::endl;
                    --textIndentionLevel;
                }
                tree.insert(element);

                if constexpr (SplayTree_has_getRoot)
                {
                    int current = tree.getRoot();
                    if(current != element)
                    {
                        passed = false;
                        ++textIndentionLevel;
                        std::cout << std::string(textIndentionLevel, '\t') + "Control with SplayTree::getRoot indicates failure.\n";
                        ++textIndentionLevel;
                        std::cout << std::string(textIndentionLevel, '\t') + "Expected root: " << element <<'\n';
                        std::cout << std::string(textIndentionLevel, '\t') + "Returned root: " << current << '\n';
                        --textIndentionLevel;
                        --textIndentionLevel;
                    }
                }
                if constexpr (SplayTree_has_size)
                {
                    ++counter;
                    size_t currentSize = tree.size();
                    if(counter != currentSize)
                    {
                        passed = false;
                        ++textIndentionLevel;
                        std::cout << std::string(textIndentionLevel, '\t') + "Control with SplayTree::size indicates error.\n";
                        ++textIndentionLevel;
                        std::cout << std::string(textIndentionLevel, '\t') + "Expected size: " << counter << '\n';
                        std::cout << std::string(textIndentionLevel, '\t') + "Returned size: " << currentSize << '\n';
                        --textIndentionLevel;
                        --textIndentionLevel;
                    }
                }
            }
            --textIndentionLevel;
            std::cout << std::string(textIndentionLevel, '\t') + "Set inserted." << std::endl;
            
            ControllWithAllWalks(tree, {9, 6, 5, 8, 7}, {5, 6, 7, 8, 9}, {5, 7, 8, 6, 9}, textIndentionLevel);

            --textIndentionLevel;
            std::cout << std::string(textIndentionLevel, '\t') + "Ending intermediate insert test" << std::endl;
        }

        /**
         * 
         *  Advanced insert test 
         * 
         * 
        */
        {
            std::cout << '\n';
            std::cout << std::string(textIndentionLevel, '\t') + "Starting advanced insert test.\n";
            ++textIndentionLevel;
            std::cout << std::string(textIndentionLevel, '\t') + "Extra control(s) for this test: " << std::endl;

            if constexpr(!(SplayTree_has_getRoot))
            {
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "Cannot control if calls to SplayTree::insert caused the expected element to become root.\n";
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "Further controls will be conducted when SplayTree::getRoot is implemented." << std::endl;
                --textIndentionLevel;
                --textIndentionLevel;
            }
            else
            {
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::getRoot is implemented.\n";
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "Controls will be conducted to make sure that SplayTree::insert caused the expected element to become root.\n";
                --textIndentionLevel;
                --textIndentionLevel;
            }
            if constexpr(!(SplayTree_has_size))
            {
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "Cannot control if calls to SplayTree::insert causes the size to change correctly.\n";
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "Further controls will be conducted when SplayTree::size is implemented." << std::endl;
                --textIndentionLevel;
                --textIndentionLevel;					
            }
            else
            {
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::size is implemented.\n";
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "Controls will be conducted to make sure that SplayTree::insert reports correct size once done.\n";
                --textIndentionLevel;
                --textIndentionLevel;
            }
            if constexpr(!(SplayTree_has_preOrderWalk || SplayTree_has_inOrderWalk || SplayTree_has_postOrderWalk))
            {
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "Cannot control if calls to SplayTree::insert caused the expected ordering of elements.\n";
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "Further controls will be conducted when any of the \"orderWalk\" functions are implemented." << std::endl;
                --textIndentionLevel;
                --textIndentionLevel;
            }
            else
            {
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "One or more of the \"orderWalk\" functions implented.\n";
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "Controls will be conducted to make sure that SplayTree::insert caused the expected ordering of elements.\n";
                --textIndentionLevel;
                --textIndentionLevel;
            }

            std::cout << std::string(textIndentionLevel, '\t') + "This test will start with inserting the set {8, 6, 7, 5, 9, 25, 15, 13, 24, 10, 4, 20, 16, 14, 3, 19, 17, 2, 18, 1, 11, 23, 12, 22, 21} into the datastructure.\n";
            ++textIndentionLevel;
            T tree;
            passed &= InsertionHelpFunction({8, 6, 7, 5, 9, 25, 15, 13, 24, 10, 4, 20, 16, 14, 3, 19, 17, 2, 18, 1, 11, 23, 12, 22, 21},
                                            tree, textIndentionLevel);
            --textIndentionLevel;
            std::cout << std::string(textIndentionLevel, '\t') + "Set inserted." << std::endl;
            passed &= ControllWithAllWalks(tree,
                                    {21, 20, 12, 11, 1, 2, 3, 9, 4, 5, 6, 8, 7, 10, 19, 16, 13, 14, 15, 18, 17, 22, 23, 24, 25},
                                    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25},
                                    {7, 8, 6, 5, 4, 10, 9, 3, 2, 1, 11, 15, 14, 13, 17, 18, 16, 19, 12, 20, 25, 24, 23, 22, 21},
                                    textIndentionLevel);

            --textIndentionLevel;
            std::cout << std::string(textIndentionLevel, '\t') + "Ending advanced insert test" << std::endl;
        }
		--textIndentionLevel;
		std::cout << std::string(textIndentionLevel, '\t') + "End: SplayTree::insert tests" << std::endl;
		return passed;		
    }
    else
    {

		std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::insert not implemented. Tests cannot be conducted.\n";
		--textIndentionLevel;
		std::cout << std::string(textIndentionLevel, '\t') + "End: SplayTree::insert tests" << std::endl;
		return false;
    }
}


template <typename T = SplayTree<int>>
bool TestRemove()
{
	std::size_t textIndentionLevel = 1;
	std::cout << '\n';
	std::cout << std::string(textIndentionLevel, '\t') + "Start: SplayTree::remove tests\n";
	++textIndentionLevel;
    if constexpr(SplayTree_has_remove)
    {
        bool passed = true;
        /**
		 * 
		 * Exception tests
		 * 
		*/
		{
			std::cout << std::string(textIndentionLevel, '\t') + "Starting basic exception test.\n";
			++textIndentionLevel;
			auto callable = [](){
				T tree;
                int toRemove = 5;
				tree.remove(toRemove);
			};
			bool passOnCatch = false;
			std::string currentTest = "SplayTree::remove on empty structure";
			std::string onFailMessage = "This function should not throw an exception on an empty structure, due to this being a recoverable situation (ignore the call).";
			if(!TryCatchHelper(callable, passOnCatch, textIndentionLevel, currentTest, onFailMessage))
			{
				textIndentionLevel = 3;
				std::cout << std::string(textIndentionLevel, '\t') + "Ending basic exception test\n";
				--textIndentionLevel;
				std::cout << std::string(textIndentionLevel, '\t') + "Further testing cannot be conducted.\n";
				--textIndentionLevel;
				std::cout << std::string(textIndentionLevel, '\t') + "End: SplayTree::remove tests" << std::endl;
				return false;
			}
			--textIndentionLevel;
            if constexpr (SplayTree_has_insert)
            {
                ++textIndentionLevel;
                auto callable2 = [](){
                    T tree;
                    int toInsert = 5;
                    tree.insert(toInsert);
                    int toRemove = 15;
                    tree.remove(toRemove);
                };
                passOnCatch = false;
                currentTest = "SplayTree::remove on non-empty structure with non-existing element as argument";
                onFailMessage = "This function should not throw an exception on insertion of a duplicate, due to this being a recoverable situation (ignore the call).";
                if(!TryCatchHelper(callable2, passOnCatch, textIndentionLevel, currentTest, onFailMessage))
                {
                    textIndentionLevel = 3;
                    std::cout << std::string(textIndentionLevel, '\t') + "Ending basic exception test\n";
                    --textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "Further testing cannot be conducted.\n";
                    --textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "End: SplayTree::remove tests" << std::endl;
                    return false;
                }
                --textIndentionLevel;
            }
            else
            {
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "SplayTree:insert not implemented. Secondary exception test cannot be conducted.\n";
                std::cout << std::string(textIndentionLevel, '\t') + "Further testing will be conducted when SplayTree::insert is implemented\n";
                passed = false;
                --textIndentionLevel;
            }
			std::cout << std::string(textIndentionLevel, '\t') + "Ending basic exception test.\n";
		}

        if constexpr (SplayTree_has_insert)
        {
            /**
             * Basic remove test
             * 
             * 
            */
            {
                
            }

            /**
             * 
             *  Advanced remove test 
             * 
             * 
            */
            {
                std::cout << '\n';
                std::cout << std::string(textIndentionLevel, '\t') + "Starting advanced remove test.\n";
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "Extra control(s) for this test: " << std::endl;

                if constexpr(!(SplayTree_has_size))
                {
                    ++textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "Cannot control if calls to SplayTree::remove causes the size to change correctly.\n";
                    ++textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "Further controls will be conducted when SplayTree::size is implemented." << std::endl;
                    --textIndentionLevel;
                    --textIndentionLevel;					
                }
                else
                {
                    ++textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::size is implemented.\n";
                    ++textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "Controls will be conducted to make sure that SplayTree::remove reports correct size once done.\n";
                    --textIndentionLevel;
                    --textIndentionLevel;
                }
                if constexpr(!(SplayTree_has_getRoot))
                {
                    ++textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "Cannot control if calls to SplayTree::remove caused the expected element to become root.\n";
                    ++textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "Further controls will be conducted when SplayTree::getRoot is implemented." << std::endl;
                    --textIndentionLevel;
                    --textIndentionLevel;
                }
                else
                {
                    ++textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::getRoot is implemented.\n";
                    ++textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "Controls will be conducted to make sure that SplayTree::remove caused the expected element to become root.\n";
                    --textIndentionLevel;
                    --textIndentionLevel;
                }
                if constexpr(!(SplayTree_has_preOrderWalk || SplayTree_has_inOrderWalk || SplayTree_has_postOrderWalk))
                {
                    ++textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "Cannot control if calls to SplayTree::remove caused the expected ordering of elements.\n";
                    ++textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "Further controls will be conducted when any of the \"orderWalk\" functions are implemented." << std::endl;
                    --textIndentionLevel;
                    --textIndentionLevel;
                }
                else
                {
                    ++textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "One or more of the \"orderWalk\" functions implented.\n";
                    ++textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "Controls will be conducted to make sure that SplayTree::remove caused the expected ordering of elements.\n";
                    --textIndentionLevel;
                    --textIndentionLevel;
                }

                std::cout << std::string(textIndentionLevel, '\t') + "This test will start with inserting the set {8, 6, 7, 5, 9, 25, 15, 13, 24, 10, 4, 20, 16, 14, 3, 19, 17, 2, 18, 1, 11, 23, 12, 22, 21} into the datastructure.\n";
                ++textIndentionLevel;
                T tree;
                passed &= InsertionHelpFunction({8, 6, 7, 5, 9, 25, 15, 13, 24, 10, 4, 20, 16, 14, 3, 19, 17, 2, 18, 1, 11, 23, 12, 22, 21},
                                                tree, textIndentionLevel);
                --textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "Set inserted." << std::endl;
                passed &= ControllWithAllWalks(tree,
                                        {21, 20, 12, 11, 1, 2, 3, 9, 4, 5, 6, 8, 7, 10, 19, 16, 13, 14, 15, 18, 17, 22, 23, 24, 25},
                                        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25},
                                        {7, 8, 6, 5, 4, 10, 9, 3, 2, 1, 11, 15, 14, 13, 17, 18, 16, 19, 12, 20, 25, 24, 23, 22, 21},
                                        textIndentionLevel);
                                        
                if(passed)
                    std::cout << std::string(textIndentionLevel, '\t') + "All control functions indicates that the correct SplayTree has been created after insertion." << std::endl;
                else
                {
                    std::cout << std::string(textIndentionLevel, '\t') + "One or more control functions indicates that incorrect SplayTree has been created after insertion." << std::endl;
                    ++textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "A correct tree must be created by SplayTree::insert before this test can be conducted." << std::endl;
                    --textIndentionLevel;
                    --textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "Ending advanced remove test" << std::endl;
                    --textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "End: SplayTree::remove tests" << std::endl;
                    return false;
                }

                std::cout << std::string(textIndentionLevel, '\t') + "Calling SplayTree::remove with argument 19\n";

                int toRemove = 19;
                tree.remove(toRemove);
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "Conducting control on the tree." << std::endl;
                passed &= GetRootHelpFunction(tree, 18, textIndentionLevel);
                passed &= ControllWithAllWalks(tree,
                                    {18, 16, 12, 11, 1, 2, 3, 9, 4, 5, 6, 8, 7, 10, 13, 14, 15, 17, 21, 20, 22, 23, 24, 25},
                                    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 20, 21, 22, 23, 24, 25},
                                    {7, 8, 6, 5, 4, 10, 9, 3, 2, 1, 11, 15, 14, 13, 12, 17, 16, 20, 25, 24, 23, 22, 21, 18},
                                    textIndentionLevel);
                passed &= SizeHelpFunction(tree, 24, textIndentionLevel);

                if(passed)
                    std::cout << std::string(textIndentionLevel, '\t') + "All control functions indicates that the correct SplayTree has been created after remove." << std::endl;
                else
                {
                    std::cout << std::string(textIndentionLevel, '\t') + "One or more control functions indicates that incorrect SplayTree has been created after remove." << std::endl;
                    --textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "Ending advanced remove test" << std::endl;
                    --textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "End: SplayTree::remove tests" << std::endl;
                    return false;
                }
                --textIndentionLevel;
                
                std::cout << std::string(textIndentionLevel, '\t') + "Calling SplayTree::remove with argument 1\n";

                toRemove = 1;
                tree.remove(toRemove);
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "Conducting control on the tree." << std::endl;
                passed &= GetRootHelpFunction(tree, 16, textIndentionLevel);
                passed &= ControllWithAllWalks(tree,
                                    {16, 11, 2, 3, 9, 4, 5, 6, 8, 7, 10, 12, 13, 14, 15, 18, 17, 21, 20, 22, 23, 24, 25},
                                    {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 20, 21, 22, 23, 24, 25},
                                    {7, 8, 6, 5, 4, 10, 9, 3, 2, 15, 14, 13, 12, 11, 17, 20, 25, 24, 23, 22, 21, 18, 16},
                                    textIndentionLevel);
                passed &= SizeHelpFunction(tree, 23, textIndentionLevel);

                if(passed)
                    std::cout << std::string(textIndentionLevel, '\t') + "All control functions indicates that the correct SplayTree has been created after remove." << std::endl;
                else
                {
                    std::cout << std::string(textIndentionLevel, '\t') + "One or more control functions indicates that incorrect SplayTree has been created after remove." << std::endl;
                    --textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "Ending advanced remove test" << std::endl;
                    --textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "End: SplayTree::remove tests" << std::endl;
                    return false;
                }
                --textIndentionLevel;

                std::cout << std::string(textIndentionLevel, '\t') + "Calling SplayTree::remove with argument 25\n";

                toRemove = 25;
                tree.remove(toRemove);
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "Conducting control on the tree." << std::endl;
                passed &= GetRootHelpFunction(tree, 18, textIndentionLevel);
                passed &= ControllWithAllWalks(tree,
                                    {18, 16, 11, 2, 3, 9, 4, 5, 6, 8, 7, 10, 12, 13, 14, 15, 17, 22, 21, 20, 24, 23},
                                    {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 20, 21, 22, 23, 24},
                                    {7, 8, 6, 5, 4, 10, 9, 3, 2, 15, 14, 13, 12, 11, 17, 16, 20, 21, 23, 24, 22, 18},
                                    textIndentionLevel);
                passed &= SizeHelpFunction(tree, 22, textIndentionLevel);

                if(passed)
                    std::cout << std::string(textIndentionLevel, '\t') + "All control functions indicates that the correct SplayTree has been created after remove." << std::endl;
                else
                {
                    std::cout << std::string(textIndentionLevel, '\t') + "One or more control functions indicates that incorrect SplayTree has been created after remove." << std::endl;
                    --textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "Ending advanced remove test" << std::endl;
                    --textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "End: SplayTree::remove tests" << std::endl;
                    return false;
                }
                --textIndentionLevel;
                
                std::cout << std::string(textIndentionLevel, '\t') + "Calling SplayTree::remove with argument 26\n";

                toRemove = 26;
                tree.remove(toRemove);
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "Conducting control on the tree." << std::endl;
                passed &= GetRootHelpFunction(tree, 18, textIndentionLevel);
                passed &= ControllWithAllWalks(tree,
                                    {18, 16, 11, 2, 3, 9, 4, 5, 6, 8, 7, 10, 12, 13, 14, 15, 17, 22, 21, 20, 24, 23},
                                    {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 20, 21, 22, 23, 24},
                                    {7, 8, 6, 5, 4, 10, 9, 3, 2, 15, 14, 13, 12, 11, 17, 16, 20, 21, 23, 24, 22, 18},
                                    textIndentionLevel);
                passed &= SizeHelpFunction(tree, 22, textIndentionLevel);

                if(passed)
                    std::cout << std::string(textIndentionLevel, '\t') + "All control functions indicates that the correct SplayTree has been created after remove." << std::endl;
                else
                {
                    std::cout << std::string(textIndentionLevel, '\t') + "One or more control functions indicates that incorrect SplayTree has been created after remove." << std::endl;
                    --textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "Ending advanced remove test" << std::endl;
                    --textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "End: SplayTree::remove tests" << std::endl;
                    return false;
                }
                --textIndentionLevel;

                if constexpr (SplayTree_has_size && SplayTree_has_getMax && SplayTree_has_getRoot && SplayTree_has_getMin)
                {

                    std::cout << std::string(textIndentionLevel, '\t') + "Calling SplayTree::remove on the structure until it is empty.\n";
                    std::cout << std::string(textIndentionLevel, '\t') + "These calls will alternate between removing the element returned by SplayTree::getMax, SplayTree::getMin, and SplayTree::getRoot.\n";
                    std::cout << std::string(textIndentionLevel, '\t') + "No control will be conducted on this part.\n";
                    ++textIndentionLevel;
                    size_t counter = 0;
                    while(tree.size())
                    {
                        int element = ( counter == 0 ?  tree.getMax() :
                                        counter == 1 ?  tree.getMin() :
                                                        tree.getRoot());
                        
                        std::cout << std::string(textIndentionLevel, '\t') + "Removing element: " << element << '\n';
                        
                        ++counter;
                        if(counter == 3)
                            counter = 0;

                        tree.remove(element);
                    }
                    --textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "All elements removed from the structure." << '\n';
                    --textIndentionLevel;

                }
                else
                {
                    std::cout << std::string(textIndentionLevel, '\t') + "Test to empty the structure cannot be conducted before the following functions are implemented: \n";
                    ++textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::size\n";
                    std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::getMax\n";
                    std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::getRoot\n";
                    std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::getMin\n";
                    --textIndentionLevel;
                }

                std::cout << std::string(textIndentionLevel, '\t') + "Ending advanced remove test" << std::endl;
            }
        }
		--textIndentionLevel;
		std::cout << std::string(textIndentionLevel, '\t') + "End: SplayTree::remove tests" << std::endl;
		return passed;		
    }
    else
    {

		std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::remove not implemented. Tests cannot be conducted.\n";
		--textIndentionLevel;
		std::cout << std::string(textIndentionLevel, '\t') + "End: SplayTree::remove tests" << std::endl;
		return false;
    }
}

template <typename T = SplayTree<int>>
bool TestFind()
{
	std::size_t textIndentionLevel = 1;
	std::cout << '\n';
	std::cout << std::string(textIndentionLevel, '\t') + "Start: SplayTree::find tests\n";
	++textIndentionLevel;
    if constexpr(SplayTree_has_find)
    {
        bool passed = true;
        /**
		 * 
		 * Exception tests
		 * 
		*/
		{
			std::cout << std::string(textIndentionLevel, '\t') + "Starting basic exception test.\n";
			++textIndentionLevel;
			auto callable = [](){
				T tree;
                int toFind = 5;
				tree.find(toFind);
			};
			bool passOnCatch = false;
			std::string currentTest = "SplayTree::find on empty structure";
			std::string onFailMessage = "This function should not throw an exception on an empty structure, due to this being a recoverable situation (return false, no element exist in the empty set).";
			if(!TryCatchHelper(callable, passOnCatch, textIndentionLevel, currentTest, onFailMessage))
			{
				textIndentionLevel = 3;
				std::cout << std::string(textIndentionLevel, '\t') + "Ending basic exception test\n";
				--textIndentionLevel;
				std::cout << std::string(textIndentionLevel, '\t') + "Further testing cannot be conducted.\n";
				--textIndentionLevel;
				std::cout << std::string(textIndentionLevel, '\t') + "End: SplayTree::find tests" << std::endl;
				return false;
			}
			--textIndentionLevel;
            if constexpr (SplayTree_has_insert)
            {
                ++textIndentionLevel;
                auto callable2 = [](){
                    T tree;
                    int toInsert = 5;
                    tree.insert(toInsert);
                    int toFind = 15;
                    tree.find(toFind);
                };
                passOnCatch = false;
                currentTest = "SplayTree::find on non-empty structure with non-existing element as argument";
                onFailMessage = "This function should not throw an exception on insertion of a duplicate, due to this being a recoverable situation (return false).";
                if(!TryCatchHelper(callable2, passOnCatch, textIndentionLevel, currentTest, onFailMessage))
                {
                    textIndentionLevel = 3;
                    std::cout << std::string(textIndentionLevel, '\t') + "Ending basic exception test\n";
                    --textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "Further testing cannot be conducted.\n";
                    --textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "End: SplayTree::find tests" << std::endl;
                    return false;
                }
                --textIndentionLevel;
            }
            else
            {
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "SplayTree:insert not implemented. Secondary exception test cannot be conducted.\n";
                std::cout << std::string(textIndentionLevel, '\t') + "Further testing will be conducted when SplayTree::insert is implemented\n";
                passed = false;
                --textIndentionLevel;
            }
			std::cout << std::string(textIndentionLevel, '\t') + "Ending basic exception test.\n";
		}


        if constexpr (SplayTree_has_insert && SplayTree_has_preOrderWalk && SplayTree_has_inOrderWalk && SplayTree_has_postOrderWalk)
        {
            /**
             * 
             *  Advanced find test 
             * 
             * 
            */
            {
                std::cout << '\n';
                std::cout << std::string(textIndentionLevel, '\t') + "Starting advanced find test.\n";
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "Extra control(s) for this test: " << std::endl;

                if constexpr(!(SplayTree_has_getRoot))
                {
                    ++textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "Cannot control if calls to SplayTree::find caused the expected element to become root.\n";
                    ++textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "Further controls will be conducted when SplayTree::getRoot is implemented." << std::endl;
                    --textIndentionLevel;
                    --textIndentionLevel;
                }
                else
                {
                    ++textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::getRoot is implemented.\n";
                    ++textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "Controls will be conducted to make sure that SplayTree::find caused the expected element to become root.\n";
                    --textIndentionLevel;
                    --textIndentionLevel;
                }

                std::cout << std::string(textIndentionLevel, '\t') + "This test will start with inserting the set {8, 6, 7, 5, 9, 25, 15, 13, 24, 10, 4, 20, 16, 14, 3, 19, 17, 2, 18, 1, 11, 23, 12, 22, 21} into the datastructure.\n";
                ++textIndentionLevel;
                T tree;
                passed &= InsertionHelpFunction({8, 6, 7, 5, 9, 25, 15, 13, 24, 10, 4, 20, 16, 14, 3, 19, 17, 2, 18, 1, 11, 23, 12, 22, 21},
                                                tree, textIndentionLevel);
                --textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "Set inserted." << std::endl;
                passed &= ControllWithAllWalks(tree,
                                        {21, 20, 12, 11, 1, 2, 3, 9, 4, 5, 6, 8, 7, 10, 19, 16, 13, 14, 15, 18, 17, 22, 23, 24, 25},
                                        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25},
                                        {7, 8, 6, 5, 4, 10, 9, 3, 2, 1, 11, 15, 14, 13, 17, 18, 16, 19, 12, 20, 25, 24, 23, 22, 21},
                                        textIndentionLevel);

                if(passed)
                    std::cout << std::string(textIndentionLevel, '\t') + "All control functions indicates that the correct SplayTree has been created after insertion." << std::endl;
                else
                {
                    std::cout << std::string(textIndentionLevel, '\t') + "One or more control functions indicates that incorrect SplayTree has been created after insertion." << std::endl;
                    ++textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "A correct tree must be created by SplayTree::insert before this test can be conducted." << std::endl;
                    --textIndentionLevel;
                    --textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "Ending advanced find test" << std::endl;
                    --textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "End: SplayTree::find tests" << std::endl;
                    return false;
                }

                std::cout << std::string(textIndentionLevel, '\t') + "Calling SplayTree::find with argument 1\n";
                int toFind = 1;
                tree.find(toFind);
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "Conducting control on the tree." << std::endl;
                passed &= GetRootHelpFunction(tree, 1, textIndentionLevel);
                passed &= ControllWithAllWalks(tree,
                                    {1, 20, 11, 2, 3, 9, 4, 5, 6, 8, 7, 10, 12, 19, 16, 13, 14, 15, 18, 17, 21, 22, 23, 24, 25},
                                    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25},
                                    {7, 8, 6, 5, 4, 10, 9, 3, 2, 15, 14, 13, 17, 18, 16, 19, 12, 11, 25, 24, 23, 22, 21, 20, 1},
                                    textIndentionLevel);

                if(passed)
                    std::cout << std::string(textIndentionLevel, '\t') + "All control functions indicates that the correct SplayTree has been created after find." << std::endl;
                else
                {
                    std::cout << std::string(textIndentionLevel, '\t') + "One or more control functions indicates that incorrect SplayTree has been created after find." << std::endl;
                    --textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "Ending advanced find test" << std::endl;
                    --textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "End: SplayTree::find tests" << std::endl;
                    return false;
                }
                --textIndentionLevel;

                std::cout << std::string(textIndentionLevel, '\t') + "Calling SplayTree::find with argument 16\n";
                toFind = 16;
                tree.find(toFind);
                ++textIndentionLevel;
                passed &= GetRootHelpFunction(tree, 16, textIndentionLevel);
                passed &= ControllWithAllWalks(tree,
                                    {16, 1, 11, 2, 3, 9, 4, 5, 6, 8, 7, 10, 12, 13, 14, 15, 20, 19, 18, 17, 21, 22, 23, 24, 25},
                                    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25},
                                    {7, 8, 6, 5, 4, 10, 9, 3, 2, 15, 14, 13, 12, 11, 1, 17, 18, 19, 25, 24, 23, 22, 21, 20, 16},
                                    textIndentionLevel);

                if(passed)
                    std::cout << std::string(textIndentionLevel, '\t') + "All control functions indicates that the correct SplayTree has been created after find." << std::endl;
                else
                {
                    std::cout << std::string(textIndentionLevel, '\t') + "One or more control functions indicates that incorrect SplayTree has been created after find." << std::endl;
                    --textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "Ending advanced find test" << std::endl;
                    --textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "End: SplayTree::find tests" << std::endl;
                    return false;
                }
                --textIndentionLevel;

                std::cout << std::string(textIndentionLevel, '\t') + "Calling SplayTree::find with argument 6\n";

                toFind = 6;
                tree.find(toFind);
                ++textIndentionLevel;
                passed &= GetRootHelpFunction(tree, 6, textIndentionLevel);
                passed &= ControllWithAllWalks(tree,
                                    {6, 1, 2, 3, 5, 4, 16, 11, 9, 8, 7, 10, 12, 13, 14, 15, 20, 19, 18, 17, 21, 22, 23, 24, 25},
                                    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25},
                                    {4, 5, 3, 2, 1, 7, 8, 10, 9, 15, 14, 13, 12, 11, 17, 18, 19, 25, 24, 23, 22, 21, 20, 16, 6},
                                    textIndentionLevel);

                if(passed)
                    std::cout << std::string(textIndentionLevel, '\t') + "All control functions indicates that the correct SplayTree has been created after find." << std::endl;
                else
                {
                    std::cout << std::string(textIndentionLevel, '\t') + "One or more control functions indicates that incorrect SplayTree has been created after find." << std::endl;
                    --textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "Ending advanced find test" << std::endl;
                    --textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "End: SplayTree::find tests" << std::endl;
                    return false;
                }
                --textIndentionLevel;

                
                std::cout << std::string(textIndentionLevel, '\t') + "Calling SplayTree::find with argument 26\n";

                toFind = 26;
                tree.find(toFind);
                ++textIndentionLevel;
                passed &= GetRootHelpFunction(tree, 6, textIndentionLevel);
                passed &= ControllWithAllWalks(tree,
                                    {6, 1, 2, 3, 5, 4, 16, 11, 9, 8, 7, 10, 12, 13, 14, 15, 20, 19, 18, 17, 21, 22, 23, 24, 25},
                                    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25},
                                    {4, 5, 3, 2, 1, 7, 8, 10, 9, 15, 14, 13, 12, 11, 17, 18, 19, 25, 24, 23, 22, 21, 20, 16, 6},
                                    textIndentionLevel);
                if(passed)
                    std::cout << std::string(textIndentionLevel, '\t') + "All control functions indicates that the correct SplayTree has been created after find." << std::endl;
                else
                {
                    std::cout << std::string(textIndentionLevel, '\t') + "One or more control functions indicates that incorrect SplayTree has been created after find." << std::endl;
                    ++textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::find should only cause a change in the tree if the sought for element is found." << std::endl;
                    --textIndentionLevel;
                    --textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "Ending advanced find test" << std::endl;
                    --textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "End: SplayTree::find tests" << std::endl;
                    return false;
                }
                --textIndentionLevel;

                --textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "Ending advanced find test" << std::endl;
            }
        }
        else
        {
            std::cout << std::string(textIndentionLevel, '\t') + "Further testing of SplayTree::find cannot be conducted before the following functions are implemented:\n";
            ++textIndentionLevel;
            std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::insert\n";
            std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::preOrderWalk\n";
            std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::inOrderWalk\n";
            std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::postOrderWalk\n";
            --textIndentionLevel;
        }
		--textIndentionLevel;
		std::cout << std::string(textIndentionLevel, '\t') + "End: SplayTree::find tests" << std::endl;
		return passed;		
    }
    else
    {

		std::cout << std::string(textIndentionLevel, '\t') + " SplayTree::find not implemented. Tests cannot be conducted.\n";
		--textIndentionLevel;
		std::cout << std::string(textIndentionLevel, '\t') + "End: SplayTree::find tests" << std::endl;
		return false;
    }
}

template <typename T = SplayTree<int>>
bool TestPreOrderWalk()
{
	std::size_t textIndentionLevel = 1;
	std::cout << '\n';
	std::cout << std::string(textIndentionLevel, '\t') + "Start: SplayTree::preOrderWalk tests\n";
	++textIndentionLevel;
    if constexpr(SplayTree_has_preOrderWalk)
    {
        bool passed = true;
        /**
		 * 
		 * Exception tests
		 * 
		*/
		{
			std::cout << std::string(textIndentionLevel, '\t') + "Starting basic exception test.\n";
			++textIndentionLevel;
			auto callable = [](){
				T tree;
				tree.preOrderWalk();
			};
			bool passOnCatch = false;
			std::string currentTest = "SplayTree::preOrderWalk on empty structure";
			std::string onFailMessage = "This function should not throw an exception on an empty structure, due to this being a recoverable situation (return empty vector).";
			if(!TryCatchHelper(callable, passOnCatch, textIndentionLevel, currentTest, onFailMessage))
			{
				textIndentionLevel = 3;
				std::cout << std::string(textIndentionLevel, '\t') + "Ending basic exception test\n";
				--textIndentionLevel;
				std::cout << std::string(textIndentionLevel, '\t') + "Further testing cannot be conducted.\n";
				--textIndentionLevel;
				std::cout << std::string(textIndentionLevel, '\t') + "End: SplayTree::preOrderWalk tests" << std::endl;
				return false;
			}
			--textIndentionLevel;
            
			std::cout << std::string(textIndentionLevel, '\t') + "Ending basic exception test.\n";
		}

        std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::preOrderWalk is exstensivly used in other tests, and thus is not tested separately.\n";

		--textIndentionLevel;
		std::cout << std::string(textIndentionLevel, '\t') + "End: SplayTree::preOrderWalk tests" << std::endl;
		return passed;		
    }
    else
    {

		std::cout << std::string(textIndentionLevel, '\t') + " SplayTree::preOrderWalk not implemented. Tests cannot be conducted.\n";
		--textIndentionLevel;
		std::cout << std::string(textIndentionLevel, '\t') + "End: SplayTree::preOrderWalk tests" << std::endl;
		return false;
    }
}

template <typename T = SplayTree<int>>
bool TestInOrderWalk()
{
	std::size_t textIndentionLevel = 1;
	std::cout << '\n';
	std::cout << std::string(textIndentionLevel, '\t') + "Start: SplayTree::inOrderWalk tests\n";
	++textIndentionLevel;
    if constexpr(SplayTree_has_inOrderWalk)
    {
        bool passed = true;
        /**
		 * 
		 * Exception tests
		 * 
		*/
		{
			std::cout << std::string(textIndentionLevel, '\t') + "Starting basic exception test.\n";
			++textIndentionLevel;
			auto callable = [](){
				T tree;
				tree.inOrderWalk();
			};
			bool passOnCatch = false;
			std::string currentTest = "SplayTree::inOrderWalk on empty structure";
			std::string onFailMessage = "This function should not throw an exception on an empty structure, due to this being a recoverable situation (return empty vector).";
			if(!TryCatchHelper(callable, passOnCatch, textIndentionLevel, currentTest, onFailMessage))
			{
				textIndentionLevel = 3;
				std::cout << std::string(textIndentionLevel, '\t') + "Ending basic exception test\n";
				--textIndentionLevel;
				std::cout << std::string(textIndentionLevel, '\t') + "Further testing cannot be conducted.\n";
				--textIndentionLevel;
				std::cout << std::string(textIndentionLevel, '\t') + "End: SplayTree::inOrderWalk tests" << std::endl;
				return false;
			}
			--textIndentionLevel;
            
			std::cout << std::string(textIndentionLevel, '\t') + "Ending basic exception test.\n";
		}
        std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::inOrderWalk is exstensivly used in other tests, and thus is not tested separately.\n";

		--textIndentionLevel;
		std::cout << std::string(textIndentionLevel, '\t') + "End: SplayTree::inOrderWalk tests" << std::endl;
		return passed;		
    }
    else
    {

		std::cout << std::string(textIndentionLevel, '\t') + " SplayTree::inOrderWalk not implemented. Tests cannot be conducted.\n";
		--textIndentionLevel;
		std::cout << std::string(textIndentionLevel, '\t') + "End: SplayTree::inOrderWalk tests" << std::endl;
		return false;
    }
}

template <typename T = SplayTree<int>>
bool TestPostOrderWalk()
{
	std::size_t textIndentionLevel = 1;
	std::cout << '\n';
	std::cout << std::string(textIndentionLevel, '\t') + "Start: SplayTree::postOrderWalk tests\n";
	++textIndentionLevel;
    if constexpr(SplayTree_has_postOrderWalk)
    {
        bool passed = true;
        /**
		 * 
		 * Exception tests
		 * 
		*/
		{
			std::cout << std::string(textIndentionLevel, '\t') + "Starting basic exception test.\n";
			++textIndentionLevel;
			auto callable = [](){
				T tree;
				tree.postOrderWalk();
			};
			bool passOnCatch = false;
			std::string currentTest = "SplayTree::postOrderWalk on empty structure";
			std::string onFailMessage = "This function should not throw an exception on an empty structure, due to this being a recoverable situation (return empty vector).";
			if(!TryCatchHelper(callable, passOnCatch, textIndentionLevel, currentTest, onFailMessage))
			{
				textIndentionLevel = 3;
				std::cout << std::string(textIndentionLevel, '\t') + "Ending basic exception test\n";
				--textIndentionLevel;
				std::cout << std::string(textIndentionLevel, '\t') + "Further testing cannot be conducted.\n";
				--textIndentionLevel;
				std::cout << std::string(textIndentionLevel, '\t') + "End: SplayTree::postOrderWalk tests" << std::endl;
				return false;
			}
			--textIndentionLevel;
            
			std::cout << std::string(textIndentionLevel, '\t') + "Ending basic exception test.\n";
		}
        std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::postOrderWalk is exstensivly used in other tests, and thus is not tested separately.\n";

		--textIndentionLevel;
		std::cout << std::string(textIndentionLevel, '\t') + "End: SplayTree::postOrderWalk tests" << std::endl;
		return passed;		
    }
    else
    {

		std::cout << std::string(textIndentionLevel, '\t') + " SplayTree::postOrderWalk not implemented. Tests cannot be conducted.\n";
		--textIndentionLevel;
		std::cout << std::string(textIndentionLevel, '\t') + "End: SplayTree::postOrderWalk tests" << std::endl;
		return false;
    }
}

template <typename T = SplayTree<int>>
bool TestGetMin()
{
	std::size_t textIndentionLevel = 1;
	std::cout << '\n';
	std::cout << std::string(textIndentionLevel, '\t') + "Start: SplayTree::getMin tests\n";
	++textIndentionLevel;
    if constexpr(SplayTree_has_getMin)
    {
        bool passed = true;
        /**
		 * 
		 * Exception tests
		 * 
		*/
		{
			std::cout << std::string(textIndentionLevel, '\t') + "Starting basic exception test.\n";
			++textIndentionLevel;
			auto callable = [](){
				T tree;
				tree.getMin();
			};
			bool passOnCatch = true;
			std::string currentTest = "SplayTree::getMin on empty structure";
			std::string onFailMessage = "This function must throw an exception on an empty structure, due to this being a non-recoverable situation (no element can be returned from an empty structure).";
			if(!TryCatchHelper(callable, passOnCatch, textIndentionLevel, currentTest, onFailMessage))
			{
				textIndentionLevel = 3;
				std::cout << std::string(textIndentionLevel, '\t') + "Ending basic exception test\n";
				--textIndentionLevel;
				std::cout << std::string(textIndentionLevel, '\t') + "Further testing cannot be conducted.\n";
				--textIndentionLevel;
				std::cout << std::string(textIndentionLevel, '\t') + "End: SplayTree::getMin tests" << std::endl;
				return false;
			}
			--textIndentionLevel;
            
			std::cout << std::string(textIndentionLevel, '\t') + "Ending basic exception test.\n";
		}

        if constexpr (SplayTree_has_insert && SplayTree_has_preOrderWalk && SplayTree_has_inOrderWalk && SplayTree_has_postOrderWalk)
        {
            /**
             * 
             *  Advanced getMin test 
             * 
             * 
            */
            {
                std::cout << '\n';
                std::cout << std::string(textIndentionLevel, '\t') + "Starting advanced getMin test.\n";
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "Extra control(s) for this test: " << std::endl;

                if constexpr(!(SplayTree_has_getRoot))
                {
                    ++textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "Cannot control if calls to SplayTree::getMin caused the expected element to become root.\n";
                    ++textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "Further controls will be conducted when SplayTree::getRoot is implemented." << std::endl;
                    --textIndentionLevel;
                    --textIndentionLevel;
                }
                else
                {
                    ++textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::getRoot is implemented.\n";
                    ++textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "Controls will be conducted to make sure that SplayTree::getMin caused the expected element to become root.\n";
                    --textIndentionLevel;
                    --textIndentionLevel;
                }

                std::cout << std::string(textIndentionLevel, '\t') + "This test will start with inserting the set {8, 6, 7, 5, 9, 25, 15, 13, 24, 10, 4, 20, 16, 14, 3, 19, 17, 2, 18, 1, 11, 23, 12, 22, 21} into the datastructure.\n";
                ++textIndentionLevel;
                T tree;
                passed &= InsertionHelpFunction({8, 6, 7, 5, 9, 25, 15, 13, 24, 10, 4, 20, 16, 14, 3, 19, 17, 2, 18, 1, 11, 23, 12, 22, 21},
                                                tree, textIndentionLevel);
                --textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "Set inserted." << std::endl;
                passed &= ControllWithAllWalks(tree,
                                        {21, 20, 12, 11, 1, 2, 3, 9, 4, 5, 6, 8, 7, 10, 19, 16, 13, 14, 15, 18, 17, 22, 23, 24, 25},
                                        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25},
                                        {7, 8, 6, 5, 4, 10, 9, 3, 2, 1, 11, 15, 14, 13, 17, 18, 16, 19, 12, 20, 25, 24, 23, 22, 21},
                                        textIndentionLevel);
                --textIndentionLevel;            
                
                if(passed)
                    std::cout << std::string(textIndentionLevel, '\t') + "All control functions indicates that the correct SplayTree has been created after insertion." << std::endl;
                else
                {
                    std::cout << std::string(textIndentionLevel, '\t') + "One or more control functions indicates that incorrect SplayTree has been created after insertion." << std::endl;
                    ++textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "A correct tree must be created by SplayTree::insert before this test can be conducted." << std::endl;
                    --textIndentionLevel;
                    --textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "Ending advanced getMin test" << std::endl;
                    --textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "End: SplayTree::getMin tests" << std::endl;
                    return false;
                }

                std::cout << std::string(textIndentionLevel, '\t') + "Calling SplayTree::getMin\n";
                int returnValue = tree.getMin();
                if(returnValue != 1)
                {
                    ++textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::getMin returned the wrong element.\n";
                    ++textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "Expected min: 1\n";
                    std::cout << std::string(textIndentionLevel, '\t') + "Returned min: " << returnValue << '\n';
                    --textIndentionLevel;
                    --textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "Ending advanced getMin test" << std::endl;
                    --textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "End: SplayTree::getMin tests" << std::endl;
                    return false;
                }

                passed &= GetRootHelpFunction(tree, 1, textIndentionLevel);
                passed &= ControllWithAllWalks(tree,
                                                {1, 20, 11, 2, 3, 9, 4, 5, 6, 8, 7, 10, 12, 19, 16, 13, 14, 15, 18, 17, 21, 22, 23, 24, 25},
                                                {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25},
                                                {7, 8, 6, 5, 4, 10, 9, 3, 2, 15, 14, 13, 17, 18, 16, 19, 12, 11, 25, 24, 23, 22, 21, 20, 1},
                                                textIndentionLevel);

                std::cout << std::string(textIndentionLevel, '\t') + "Ending advanced getMin test" << std::endl;
            }
        }
        else
        {
            std::cout << std::string(textIndentionLevel, '\t') + "Further testing of SplayTree::getMin cannot be conducted before the following functions are implemented:\n";
            ++textIndentionLevel;
            std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::insert\n";
            std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::preOrderWalk\n";
            std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::inOrderWalk\n";
            std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::postOrderWalk\n";
            --textIndentionLevel;
        }

		--textIndentionLevel;
		std::cout << std::string(textIndentionLevel, '\t') + "End: SplayTree::getMin tests" << std::endl;
		return passed;		
    }
    else
    {

		std::cout << std::string(textIndentionLevel, '\t') + " SplayTree::getMin not implemented. Tests cannot be conducted.\n";
		--textIndentionLevel;
		std::cout << std::string(textIndentionLevel, '\t') + "End: SplayTree::getMin tests" << std::endl;
		return false;
    }
}

template <typename T = SplayTree<int>>
bool TestGetMax()
{
	std::size_t textIndentionLevel = 1;
	std::cout << '\n';
	std::cout << std::string(textIndentionLevel, '\t') + "Start: SplayTree::getMax tests\n";
	++textIndentionLevel;
    if constexpr(SplayTree_has_getMax)
    {
        bool passed = true;
        /**
		 * 
		 * Exception tests
		 * 
		*/
		{
			std::cout << std::string(textIndentionLevel, '\t') + "Starting basic exception test.\n";
			++textIndentionLevel;
			auto callable = [](){
				T tree;
				tree.getMax();
			};
			bool passOnCatch = true;
			std::string currentTest = "SplayTree::getMax on empty structure";
			std::string onFailMessage = "This function must throw an exception on an empty structure, due to this being a non-recoverable situation (no element can be returned from an empty structure).";
			if(!TryCatchHelper(callable, passOnCatch, textIndentionLevel, currentTest, onFailMessage))
			{
				textIndentionLevel = 3;
				std::cout << std::string(textIndentionLevel, '\t') + "Ending basic exception test\n";
				--textIndentionLevel;
				std::cout << std::string(textIndentionLevel, '\t') + "Further testing cannot be conducted.\n";
				--textIndentionLevel;
				std::cout << std::string(textIndentionLevel, '\t') + "End: SplayTree::getMax tests" << std::endl;
				return false;
			}
			--textIndentionLevel;
            
			std::cout << std::string(textIndentionLevel, '\t') + "Ending basic exception test.\n";
		}
        if constexpr (SplayTree_has_insert && SplayTree_has_preOrderWalk && SplayTree_has_inOrderWalk && SplayTree_has_postOrderWalk)
        {
            /**
             * 
             *  Advanced getMax test 
             * 
             * 
            */
            {
                std::cout << '\n';
                std::cout << std::string(textIndentionLevel, '\t') + "Starting advanced getMax test.\n";
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "Extra control(s) for this test: " << std::endl;

                if constexpr(!(SplayTree_has_getRoot))
                {
                    ++textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "Cannot control if calls to SplayTree::getMax caused the expected element to become root.\n";
                    ++textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "Further controls will be conducted when SplayTree::getRoot is implemented." << std::endl;
                    --textIndentionLevel;
                    --textIndentionLevel;
                }
                else
                {
                    ++textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::getRoot is implemented.\n";
                    ++textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "Controls will be conducted to make sure that SplayTree::getMax caused the expected element to become root.\n";
                    --textIndentionLevel;
                    --textIndentionLevel;
                }

                std::cout << std::string(textIndentionLevel, '\t') + "This test will start with inserting the set {8, 6, 7, 5, 9, 25, 15, 13, 24, 10, 4, 20, 16, 14, 3, 19, 17, 2, 18, 1, 11, 23, 12, 22, 21} into the datastructure.\n";
                ++textIndentionLevel;
                T tree;
                passed &= InsertionHelpFunction({8, 6, 7, 5, 9, 25, 15, 13, 24, 10, 4, 20, 16, 14, 3, 19, 17, 2, 18, 1, 11, 23, 12, 22, 21},
                                                tree, textIndentionLevel);
                --textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "Set inserted." << std::endl;
                passed &= ControllWithAllWalks(tree,
                                        {21, 20, 12, 11, 1, 2, 3, 9, 4, 5, 6, 8, 7, 10, 19, 16, 13, 14, 15, 18, 17, 22, 23, 24, 25},
                                        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25},
                                        {7, 8, 6, 5, 4, 10, 9, 3, 2, 1, 11, 15, 14, 13, 17, 18, 16, 19, 12, 20, 25, 24, 23, 22, 21},
                                        textIndentionLevel);
                --textIndentionLevel;            
                
                if(passed)
                    std::cout << std::string(textIndentionLevel, '\t') + "All control functions indicates that the correct SplayTree has been created after insertion." << std::endl;
                else
                {
                    std::cout << std::string(textIndentionLevel, '\t') + "One or more control functions indicates that incorrect SplayTree has been created after insertion." << std::endl;
                    ++textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "A correct tree must be created by SplayTree::insert before this test can be conducted." << std::endl;
                    --textIndentionLevel;
                    --textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "Ending advanced getMax test" << std::endl;
                    --textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "End: SplayTree::getMax tests" << std::endl;
                    return false;
                }

                std::cout << std::string(textIndentionLevel, '\t') + "Calling SplayTree::getMax\n";
                int returnValue = tree.getMax();
                if(returnValue != 25)
                {
                    ++textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::getMax returned the wrong element.\n";
                    ++textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "Expected max: 25\n";
                    std::cout << std::string(textIndentionLevel, '\t') + "Returned max: " << returnValue << '\n';
                    --textIndentionLevel;
                    --textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "Ending advanced getMax test" << std::endl;
                    --textIndentionLevel;
                    std::cout << std::string(textIndentionLevel, '\t') + "End: SplayTree::getMax tests" << std::endl;
                    return false;
                }


                passed &= GetRootHelpFunction(tree, 25, textIndentionLevel);
                passed &= ControllWithAllWalks(tree,
                                                {25, 22, 21, 20, 12, 11, 1, 2, 3, 9, 4, 5, 6, 8, 7, 10, 19, 16, 13, 14, 15, 18, 17, 24, 23},
                                                {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25},
                                                {7, 8, 6, 5, 4, 10, 9, 3, 2, 1, 11, 15, 14, 13, 17, 18, 16, 19, 12, 20, 21, 23, 24, 22, 25},
                                                textIndentionLevel);
                
                --textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "Ending advanced getMax test" << std::endl;
            }
        }
        else
        {
            std::cout << std::string(textIndentionLevel, '\t') + "Further testing of SplayTree::getMax cannot be conducted before the following functions are implemented:\n";
            ++textIndentionLevel;
            std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::insert\n";
            std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::preOrderWalk\n";
            std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::inOrderWalk\n";
            std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::postOrderWalk\n";
            --textIndentionLevel;
        }
		--textIndentionLevel;
		std::cout << std::string(textIndentionLevel, '\t') + "End: SplayTree::getMax tests" << std::endl;
		return passed;		
    }
    else
    {

		std::cout << std::string(textIndentionLevel, '\t') + " SplayTree::getMax not implemented. Tests cannot be conducted.\n";
		--textIndentionLevel;
		std::cout << std::string(textIndentionLevel, '\t') + "End: SplayTree::getMax tests" << std::endl;
		return false;
    }
}

template <typename T = SplayTree<int>>
bool TestGetRoot()
{
	std::size_t textIndentionLevel = 1;
	std::cout << '\n';
	std::cout << std::string(textIndentionLevel, '\t') + "Start: SplayTree::getRoot tests\n";
	++textIndentionLevel;
    if constexpr(SplayTree_has_getRoot)
    {
        bool passed = true;
        /**
		 * 
		 * Exception tests
		 * 
		*/
		{
			std::cout << std::string(textIndentionLevel, '\t') + "Starting basic exception test.\n";
			++textIndentionLevel;
			auto callable = [](){
				T tree;
				tree.getRoot();
			};
			bool passOnCatch = true;
			std::string currentTest = "SplayTree::getRoot on empty structure";
			std::string onFailMessage = "This function must throw an exception on an empty structure, due to this being a non-recoverable situation (no element can be returned from an empty structure).";
			if(!TryCatchHelper(callable, passOnCatch, textIndentionLevel, currentTest, onFailMessage))
			{
				textIndentionLevel = 3;
				std::cout << std::string(textIndentionLevel, '\t') + "Ending basic exception test\n";
				--textIndentionLevel;
				std::cout << std::string(textIndentionLevel, '\t') + "Further testing cannot be conducted.\n";
				--textIndentionLevel;
				std::cout << std::string(textIndentionLevel, '\t') + "End: SplayTree::getRoot tests" << std::endl;
				return false;
			}
			--textIndentionLevel;
            
			std::cout << std::string(textIndentionLevel, '\t') + "Ending basic exception test.\n";
		}
        std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::getRoot is exstensivly used in other tests, and thus is not tested separately.\n";
		--textIndentionLevel;
		std::cout << std::string(textIndentionLevel, '\t') + "End: SplayTree::getRoot tests" << std::endl;
		return passed;		
    }
    else
    {

		std::cout << std::string(textIndentionLevel, '\t') + " SplayTree::getRoot not implemented. Tests cannot be conducted.\n";
		--textIndentionLevel;
		std::cout << std::string(textIndentionLevel, '\t') + "End: SplayTree::getRoot tests" << std::endl;
		return false;
    }
}

template <typename T = SplayTree<int>>
bool TestSize()
{
	std::size_t textIndentionLevel = 1;
	std::cout << '\n';
	std::cout << std::string(textIndentionLevel, '\t') + "Start: SplayTree::size tests\n";
	++textIndentionLevel;
    if constexpr(SplayTree_has_size)
    {
        bool passed = true;
        /**
		 * 
		 * Exception tests
		 * 
		*/
		{
			std::cout << std::string(textIndentionLevel, '\t') + "Starting basic exception test.\n";
			++textIndentionLevel;
			auto callable = [](){
				T tree;
				tree.size();
			};
			bool passOnCatch = false;
			std::string currentTest = "SplayTree::size on empty structure";
			std::string onFailMessage = "This function should not throw an exception on an empty structure, due to this being a recoverable situation (the empty set has a size of 0).";
			if(!TryCatchHelper(callable, passOnCatch, textIndentionLevel, currentTest, onFailMessage))
			{
				textIndentionLevel = 3;
				std::cout << std::string(textIndentionLevel, '\t') + "Ending basic exception test\n";
				--textIndentionLevel;
				std::cout << std::string(textIndentionLevel, '\t') + "Further testing cannot be conducted.\n";
				--textIndentionLevel;
				std::cout << std::string(textIndentionLevel, '\t') + "End: SplayTree::size tests" << std::endl;
				return false;
			}
			--textIndentionLevel;
            
			std::cout << std::string(textIndentionLevel, '\t') + "Ending basic exception test.\n";
		}
        std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::size is exstensivly used in other tests, and thus is not tested separately.\n";
		--textIndentionLevel;
		std::cout << std::string(textIndentionLevel, '\t') + "End: SplayTree::size tests" << std::endl;
		return passed;		
    }
    else
    {

		std::cout << std::string(textIndentionLevel, '\t') + " SplayTree::size not implemented. Tests cannot be conducted.\n";
		--textIndentionLevel;
		std::cout << std::string(textIndentionLevel, '\t') + "End: SplayTree::size tests" << std::endl;
		return false;
    }
}

template <typename T = SplayTree<int>>
bool StressTest()
{
    bool passed = false;
	std::size_t textIndentionLevel = 1;
	std::cout << '\n';
	std::cout << std::string(textIndentionLevel, '\t') + "Start: Stress tests\n";
	++textIndentionLevel;

    if constexpr (  SplayTree_has_find &&
                    SplayTree_has_getMax &&
                    SplayTree_has_getMin &&
                    SplayTree_has_getRoot &&
                    SplayTree_has_inOrderWalk &&
                    SplayTree_has_insert &&
                    SplayTree_has_postOrderWalk &&
                    SplayTree_has_preOrderWalk &&
                    SplayTree_has_remove &&
                    SplayTree_has_size)
    {
        passed = true;
        std::cout << std::string(textIndentionLevel, '\t') + "This test will start by inserting 2500 random (unique) elements into the datastructure.\n";
        std::cout << std::string(textIndentionLevel, '\t') + "Once inserted, 2000 of these elements will be removed at random.\n";
        std::cout << std::string(textIndentionLevel, '\t') + "This will continue until 10'000 elements are present in the structure.\n";
        ++textIndentionLevel;

        std::vector<int> insertionVec;
        std::mt19937 engine;
        std::uniform_int_distribution<int> dist;
        T tree;
        do
        {
            std::cout << std::string(textIndentionLevel, '\t') + "Iteration \t" << ((insertionVec.size()/500)+1) << " of \t" << (10'000 / 500) << '\n';
            ++textIndentionLevel;
            size_t counter = 0;
            do
            {
                int generatedNumber = dist(engine);
                if(std::find(insertionVec.begin(), insertionVec.end(), generatedNumber) != insertionVec.end())
                    continue;
                ++counter;
                insertionVec.push_back(generatedNumber);
            } while (counter != 2500);
            std::cout << std::string(textIndentionLevel, '\t') + "2500 elements generated. Inserting...\n";
            for(auto &&element : insertionVec)
                tree.insert(element);
            std::cout << std::string(textIndentionLevel, '\t') + "All elements inserted. Controlling...\n";
            if(tree.size() != insertionVec.size())
            {
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::size does not report correct size.\n";
                std::cout << std::string(textIndentionLevel, '\t') + "Expected: " << insertionVec.size() << '\n';
                std::cout << std::string(textIndentionLevel, '\t') + "Returned: " << tree.size() << '\n';
                passed = false;
                --textIndentionLevel;
            }
            if(tree.getRoot() != insertionVec.back())
            {
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::getRoot does not report expected root.\n";
                std::cout << std::string(textIndentionLevel, '\t') + "Expected: " << insertionVec.back() << '\n';
                std::cout << std::string(textIndentionLevel, '\t') + "Returned: " << tree.getRoot() << '\n';
                passed = false;
                --textIndentionLevel;
            }
            std::sort(insertionVec.begin(), insertionVec.end());
            if(insertionVec != tree.inOrderWalk())
            {
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::inOrderWalk does not report correct ordering of elements.\n";
                passed = false;
                --textIndentionLevel;
            }
            
            if(!passed)
            {
                std::cout << std::string(textIndentionLevel, '\t') + "Control failed on one or more tests.\n";
                --textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "Stress test failed.\n";
                --textIndentionLevel;
                --textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "End: Stress tests\n";
                return false;
            }

            std::cout << std::string(textIndentionLevel, '\t') + "Control successful. Removing...\n";

            std::shuffle(insertionVec.begin(), insertionVec.end(), engine);

            counter = 0;
            do
            {
                ++counter;
                tree.remove(insertionVec.back());
                insertionVec.pop_back();
            }while(counter != 2000);
            
            std::cout << std::string(textIndentionLevel, '\t') + "2000 elements removed. Controlling...\n";
            if(tree.size() != insertionVec.size())
            {
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::size does not report correct size.\n";
                std::cout << std::string(textIndentionLevel, '\t') + "Expected: " << insertionVec.size() << '\n';
                std::cout << std::string(textIndentionLevel, '\t') + "Returned: " << tree.size() << '\n';
                passed = false;
                --textIndentionLevel;
            }
            std::sort(insertionVec.begin(), insertionVec.end());
            if(insertionVec != tree.inOrderWalk())
            {
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::inOrderWalk does not report correct ordering of elements.\n";
                passed = false;
                --textIndentionLevel;
            }
            if(!passed)
            {
                std::cout << std::string(textIndentionLevel, '\t') + "Control failed on one or more tests.\n";
                --textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "Stress test failed.\n";
                --textIndentionLevel;
                --textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "End: Stress tests\n";
                return false;
            }

            --textIndentionLevel;
            if(insertionVec.size() != 10'000)
                std::cout << std::string(textIndentionLevel, '\t') + "Iteration successful. New iteration...\n\n";
            else
                std::cout << std::string(textIndentionLevel, '\t') + "Iteration successful.\n\n";

        }while(insertionVec.size() != 10'000 && passed);

        --textIndentionLevel;
        std::cout << std::string(textIndentionLevel, '\t') + "All elements inserted.\n";
        std::cout << std::string(textIndentionLevel, '\t') + "Phase 2 will add 2000 elements and remove 2500 elements each iteration.\n";
        std::cout << std::string(textIndentionLevel, '\t') + "This will be done until 0 elements remain.\n";
        ++textIndentionLevel;
        size_t iterationCounter = 0;
        do
        {
            ++iterationCounter;
            std::cout << std::string(textIndentionLevel, '\t') + "Iteration \t" << iterationCounter << " of \t" << (10'000 / 500) << '\n';
            ++textIndentionLevel;
            size_t counter = 0;
            do
            {
                int generatedNumber = dist(engine);
                if(std::find(insertionVec.begin(), insertionVec.end(), generatedNumber) != insertionVec.end())
                    continue;
                ++counter;
                insertionVec.push_back(generatedNumber);
            } while (counter != 2000);
            std::cout << std::string(textIndentionLevel, '\t') + "2000 elements generated. Inserting...\n";
            for(auto &&element : insertionVec)
                tree.insert(element);
            std::cout << std::string(textIndentionLevel, '\t') + "All elements inserted. Controlling...\n";
            if(tree.size() != insertionVec.size())
            {
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::size does not report correct size.\n";
                std::cout << std::string(textIndentionLevel, '\t') + "Expected: " << insertionVec.size() << '\n';
                std::cout << std::string(textIndentionLevel, '\t') + "Returned: " << tree.size() << '\n';
                passed = false;
                --textIndentionLevel;
            }
            if(tree.getRoot() != insertionVec.back())
            {
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::getRoot does not report expected root.\n";
                std::cout << std::string(textIndentionLevel, '\t') + "Expected: " << insertionVec.back() << '\n';
                std::cout << std::string(textIndentionLevel, '\t') + "Returned: " << tree.getRoot() << '\n';
                passed = false;
                --textIndentionLevel;
            }
            std::sort(insertionVec.begin(), insertionVec.end());
            if(insertionVec != tree.inOrderWalk())
            {
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::inOrderWalk does not report correct ordering of elements.\n";
                passed = false;
                --textIndentionLevel;
            }
            
            if(!passed)
            {
                std::cout << std::string(textIndentionLevel, '\t') + "Control failed on one or more tests.\n";
                --textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "Stress test failed.\n";
                --textIndentionLevel;
                --textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "End: Stress tests\n";
                return false;
            }

            std::cout << std::string(textIndentionLevel, '\t') + "Control successful. Removing...\n";

            std::shuffle(insertionVec.begin(), insertionVec.end(), engine);

            counter = 0;
            do
            {
                ++counter;
                tree.remove(insertionVec.back());
                insertionVec.pop_back();
            }while(counter != 2500);
            
            std::cout << std::string(textIndentionLevel, '\t') + "2500 elements removed. Controlling...\n";
            if(tree.size() != insertionVec.size())
            {
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::size does not report correct size.\n";
                std::cout << std::string(textIndentionLevel, '\t') + "Expected: " << insertionVec.size() << '\n';
                std::cout << std::string(textIndentionLevel, '\t') + "Returned: " << tree.size() << '\n';
                passed = false;
                --textIndentionLevel;
            }
            std::sort(insertionVec.begin(), insertionVec.end());
            if(insertionVec != tree.inOrderWalk())
            {
                ++textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "SplayTree::inOrderWalk does not report correct ordering of elements.\n";
                passed = false;
                --textIndentionLevel;
            }
            if(!passed)
            {
                std::cout << std::string(textIndentionLevel, '\t') + "Control failed on one or more tests.\n";
                --textIndentionLevel;
                --textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "Stress test failed.\n";
                --textIndentionLevel;
                std::cout << std::string(textIndentionLevel, '\t') + "End: Stress tests\n";
                return false;
            }

            --textIndentionLevel;
            if(insertionVec.size() != 0)
                std::cout << std::string(textIndentionLevel, '\t') + "Iteration successful. New iteration...\n\n";
            else
                std::cout << std::string(textIndentionLevel, '\t') + "Iteration successful.\n";

        }while(insertionVec.size() != 0);
        --textIndentionLevel;
        std::cout << std::string(textIndentionLevel, '\t') + "Stress test successful." << std::endl;
    }
    else
    {
        std::cout << "Stress test cannot be conducted before all functions are implemented.\n";
    }

    --textIndentionLevel;        
    std::cout << std::string(textIndentionLevel, '\t') + "End: Stress tests\n";

    return passed;
}

template <typename T = SplayTree<int>>
bool SplayTreeUnitTests()
{
    if (SplayTree_IsDefaultConstructible)
    {
        try
        {
            T* tree = new T();
            delete tree;
        }
		catch(const std::exception& e)
		{
			std::cout << "\tDefault construction or destruction of SplayTree failed. Testing cannot be conducted. Error message: " << e.what() << std::endl;
			return false;
		}
		catch(...)
		{
			std::cout << "\tDefault construction or destruction of SplayTree failed. Testing cannot be conducted." << std::endl;
			return false;
		}
        
        bool pass = true;

        if(!TestInsert())
        {
			std::cout << "Tests failed on SplayTree::insert." << std::endl;
			pass = false;
        }
        else
			std::cout << "Tests succeeded on SplayTree::insert." << std::endl;

		std::cout << "Press enter to continue." << std::endl;
		std::cin.get();

        if(!TestRemove())
        {
			std::cout << "Tests failed on SplayTree::remove." << std::endl;
			pass = false;
        }
        else
			std::cout << "Tests succeeded on SplayTree::remove." << std::endl;
		std::cout << "Press enter to continue." << std::endl;
		std::cin.get();

        if(!TestFind())
        {
			std::cout << "Tests failed on SplayTree::find." << std::endl;
			pass = false;
        }
        else
			std::cout << "Tests succeeded on SplayTree::find." << std::endl;
		std::cout << "Press enter to continue." << std::endl;
		std::cin.get();

        if(!TestPreOrderWalk())
        {
			std::cout << "Tests failed on SplayTree::preOrderWalk." << std::endl;
			pass = false;
        }
        else
			std::cout << "Tests succeeded on SplayTree::preOrderWalk." << std::endl;
		std::cout << "Press enter to continue." << std::endl;
		std::cin.get();

        if(!TestInOrderWalk())
        {
			std::cout << "Tests failed on SplayTree::inOrderWalk." << std::endl;
			pass = false;
        }
        else
			std::cout << "Tests succeeded on SplayTree::inOrderWalk." << std::endl;
		std::cout << "Press enter to continue." << std::endl;
		std::cin.get();

        if(!TestPostOrderWalk())
        {
			std::cout << "Tests failed on SplayTree::postOrderWalk." << std::endl;
			pass = false;
        }
        else
			std::cout << "Tests succeeded on SplayTree::postOrderWalk." << std::endl;
		std::cout << "Press enter to continue." << std::endl;
		std::cin.get();

        if(!TestGetMin())
        {
			std::cout << "Tests failed on SplayTree::getMin." << std::endl;
			pass = false;
        }
        else
			std::cout << "Tests succeeded on SplayTree::getMin." << std::endl;
		std::cout << "Press enter to continue." << std::endl;
		std::cin.get();
        
        if(!TestGetMax())
        {
			std::cout << "Tests failed on SplayTree::getMax." << std::endl;
			pass = false;
        }
        else
			std::cout << "Tests succeeded on SplayTree::getMax." << std::endl;
		std::cout << "Press enter to continue." << std::endl;
		std::cin.get();
        
        if(!TestGetRoot())
        {
			std::cout << "Tests failed on SplayTree::getRoot." << std::endl;
			pass = false;
        }
        else
			std::cout << "Tests succeeded on SplayTree::getRoot." << std::endl;
		std::cout << "Press enter to continue." << std::endl;
		std::cin.get();
        
        if(!TestSize())
        {
			std::cout << "Tests failed on SplayTree::size." << std::endl;
			pass = false;
        }
        else
			std::cout << "Tests succeeded on SplayTree::size." << std::endl;
		std::cout << "Press enter to continue." << std::endl;
		std::cin.get();

        if(!pass)
        {
            std::cout << "Stress test will not be conducted before all tests are passed." << std::endl;
        }
        else
        {
            
            if(!StressTest())
            {
                std::cout << "Stress tests failed." << std::endl;
                pass = false;
            }
            else
                std::cout << "Stress test succeeded." << std::endl;
        }

		std::cout << "Press enter to exit." << std::endl;
		std::cin.get();
        return pass;
    }
    else
    {
        std::cout << "SplayTree Unit Tests cannot be conducted, no defaul constructor available." << std::endl;
        return false;
    }
}
} // namespace UnitTests::AVLTREE

#else
namespace UnitTests::SPLAYTREE
{
bool SplayTreeUnitTests()
{
    std::cout << "File SplayTree.h non-existent." << std::endl;
    return false;
}
} // namespace UnitTests::AVLTREE
#endif

#endif