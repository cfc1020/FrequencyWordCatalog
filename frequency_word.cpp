//
//  frequency_word.cpp
//  FrequencyWordInCatalog
//

#include "frequency_word.h"

frequency_word::frequency_word(const std::string &path)
    : _path(path)
{
    
}

void frequency_word::run(void)
{
    std::string file_name;
    for(bfs::recursive_directory_iterator rdib(_path), rdie; rdib != rdie; ++rdib)
    {
        if (!bfs::is_directory(rdib->status()))
        {
            file_name = rdib->path().string();
            scan(file_name);
        }
    }
    
    //  for (int i = 0; i < 10 && i < arr_word.size(); ++i)
    //std::cout << arr_word[i].first << " - " << arr_word[i].second << std::endl;
}
