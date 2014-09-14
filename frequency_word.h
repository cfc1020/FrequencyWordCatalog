//
//  frequency_word.h
//  FrequencyWordInCatalog
//

#ifndef __FrequencyWordInCatalog__frequency_word__
#define __FrequencyWordInCatalog__frequency_word__

#include <iostream>
#include <map>
#include <string>
#include <boost/filesystem.hpp>
#include <fstream>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/constants.hpp>
#include <iterator>
#include <algorithm>
#include <boost/algorithm/string.hpp>

namespace bfs = boost::filesystem;

class frequency_word
{
public:
    frequency_word(const std::string &);
    
    typedef std::pair<std::string, size_t> Pair_t;
    
    void run(void);
    
    template<typename Pred>
    std::vector<Pair_t> get_frequency_and_sort_by_pred(Pred pred)
    {
        std::vector<Pair_t> arr_word;
        convert_map_to_vector(arr_word, frequency);
        std::sort(std::begin(arr_word), std::end(arr_word), [&] (const Pair_t &p1, const Pair_t &p2) -> bool
        {
            return pred(p1.second, p2.second);
        });
        return arr_word;
    }
    
    const std::string& path() const;
    void path(const std::string&);
    
private:
    std::map<std::string, size_t> frequency;
    std::string _path;
    const char* token = "\n\t ";
    inline void scan(const std::string &path)
    {
        std::string line;
        std::ifstream input_file(path);
        input_file.exceptions(std::ifstream::failbit);
        if (input_file.is_open())
        {
            try
            {
                while(std::getline(input_file, line))
                {
                    //std::cout << line << std::endl;
                    execute(line);
                }
                input_file.close();
            }
            catch(std::ifstream::failure e)
            {
                std::cerr << "Error read:" << e.what() << std::endl;
            }
        }
        else
        {
            std::cerr << "Can't open file" << std::endl;
        }
    }
    template<typename Key, typename Value>
    static void convert_map_to_vector(std::vector<std::pair< Key, Value> > & vec, const std::map<Key, Value> & map)
    {
        std::copy(std::begin(map), std::end(map), std::back_inserter(vec));
    }
    
    static void trim_and_split(std::vector<std::string> &vec, std::string &str, const std::string &token)
    {
        boost::trim(str);
        boost::algorithm::split(vec, str, boost::is_any_of(token), boost::token_compress_on);
    }
    
    inline void execute(std::string& s)
    {
        std::vector<std::string> arr_word;
        //std::copy(arr_word.begin(), arr_word.end(), std::ostream_iterator<char>(std::cout, " "));
        trim_and_split(arr_word, s, token);
        for (auto &word: arr_word)
        {
            ++frequency[word];
        }
    }
};

#endif /* defined(__FrequencyWordInCatalog__frequency_word__) */