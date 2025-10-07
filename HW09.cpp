#include <vector>
#include <algorithm>
#include <iostream>
#include <random>

void printVector(const std::vector<char>& charV);
void printVector(const std::vector<char *>& charPtrV);

int main()
{
    // Create a vector of characters with "abcde" in it
    std::vector<char> charVector { 'a', 'b', 'c', 'd', 'e' };

    // Add 'f' -> 'z' to vector
    for(char c = 'f'; c <= 'z'; ++c)
    {
        charVector.push_back(c);
    }

    printVector(charVector);

    std::random_device rd;
    // seed random generator
    std::mt19937_64 gen(rd());
    
    // Shuffle Vector
    std::shuffle(charVector.begin(), charVector.end(), gen);

    printVector(charVector);

    // Find 'z' and erase it
    charVector.erase(std::find(charVector.begin(), charVector.end(), 'z'));

    printVector(charVector);

    // Randomly remove 5 letters
    for(int i = 0; i < 5; ++i)
    {
        std::uniform_int_distribution<int> dist(0, charVector.size() - 1);
        int randIndex = dist(gen);
        charVector.erase(charVector.begin() + randIndex);
    }

    printVector(charVector);
    
    // sort a-z remaining letters
    std::sort(charVector.begin(), charVector.end());
    printVector(charVector);

    // New vector of character pointers
    std::vector<char *> charPtrVector;
    charPtrVector.reserve(5);

    // dynamically copy first 5 chars of regular vector to pointer vector
    std::transform(charVector.begin(), charVector.begin() + 5,
                   std::back_inserter(charPtrVector),
                   [] (char c) { return new char(c); });

    printVector(charPtrVector);

    std::shuffle(charPtrVector.begin(), charPtrVector.end(), gen);

    printVector(charPtrVector);

    // re-sort pointer vector
    std::sort(charPtrVector.begin(), charPtrVector.end(),
              [] (char* a, char* b) { return (*a < *b); } );

    printVector(charPtrVector);

    // delete all pointers in pointer vector
    for(char *c : charPtrVector)
    {
        delete c;
    }
    
    charPtrVector.clear();
    
    printVector(charPtrVector);

    std::cout << "Correct grammar is: I have done it!" << std::endl;
    return 0;
}

void printVector(const std::vector<char>& charV)
{
    if(charV.size() != 0)
    {
        for(const auto& elem : charV)
        {
            std::cout << elem;
        }
        std::cout << std::endl;
    }

}

void printVector(const std::vector<char *>& charPtrV)
{
    if(charPtrV.size() != 0)
    {
        for(const auto& elem : charPtrV)
        {
            std::cout << elem;
        }
        std::cout << std::endl;
    }

}

