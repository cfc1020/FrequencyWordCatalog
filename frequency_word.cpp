//
//  frequency_word.cpp
//  FrequencyWordInCatalog
//

#include "frequency_word.h"

frequency_word::frequency_word(const std::string &path)
    : _path(path)
{
    
}

void frequency_word::run(void) noexcept
{
    std::string file_name;
    
    try
    {
        for(bfs::recursive_directory_iterator rdib(_path), rdie; rdib != rdie; ++rdib)
        {
            if (!bfs::is_directory(rdib->status()))
            {
                scan(rdib->path().string());
            }
        }
    }
    catch (boost::filesystem::filesystem_error e)
    {
        std::cerr << "Error open catalog: " << e.what() << std::endl;
    }
    
    //  for (int i = 0; i < 10 && i < arr_word.size(); ++i)
    //std::cout << arr_word[i].first << " - " << arr_word[i].second << std::endl;
}

void frequency_word::clear_frequency()
{
    frequency.clear();
}
