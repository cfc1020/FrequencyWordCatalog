//
//  main.cpp
//  FrequencyWordInCatalog
//

#include <iostream>
#include <boost/array.hpp>
#include <boost/filesystem.hpp>
#include <functional>

#include "frequency_word.h"

int main(int argc, const char * argv[])
{
    if (argc < 2)
    {
        std::cerr << "Error input to command line params" << std::endl;
        return -1;
    }
    else
    {
        frequency_word words(argv[1]);
        std::cout << "Executing! Please, wait..." << std::endl;
        words.run();
        //std::vector< std::pair<std::string, size_t> > arr_word = words.get_frequency_and_sort_by_pred([](const size_t& v1, const size_t& v2)
        //{
        //    return v1 < v2;
        //});
        
        std::cout << "Result: " << std::endl;
        
        std::vector<frequency_word::Pair_t> arr_word = words.get_frequency_and_sort_by_pred(std::greater<size_t>());
        
        for (size_t i = 0; i < 10 && i < arr_word.size(); ++i)
        {
            std::cout << arr_word[i].first << " - " << arr_word[i].second << std::endl;
        }
    }
    
    return 0;
}

