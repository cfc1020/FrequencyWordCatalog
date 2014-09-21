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
        
        int distinct_word_count = 0;
        int total_word_count = 0;
        
        std::vector<Trie *> most_counted = { words.trie, words.trie, words.trie, words.trie, words.trie};
        
        words.get_top_counts(most_counted, distinct_word_count, total_word_count);
        std::reverse(std::begin(most_counted), std::end(most_counted));
        
        for (auto trie: most_counted)
        {
            std::cout << trie->to_string() << " : " << trie->m_word_count << std::endl;
        }
        
        //std::vector<frequency_word::Pair_t> arr_word = words.get_frequency_and_sort_by_pred(std::greater<size_t>());
        
        //for (size_t i = 0; i < 10 && i < arr_word.size(); ++i)
        //{
        //    std::cout << arr_word[i].first << " - " << arr_word[i].second << std::endl;
        //}
    }
    
    return 0;
}

