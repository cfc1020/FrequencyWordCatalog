//
//  Trie.h
//  FrequencyWordInCatalog
//
//  Created by Andrey on 19.09.14.
//  Copyright (c) 2014 Andrey. All rights reserved.
//

#ifndef __FrequencyWordInCatalog__Trie__
#define __FrequencyWordInCatalog__Trie__

#include <iostream>
#include <map>
#include <cctype>
#include <vector>
#include <algorithm>

class Trie
{
public:
    typedef std::map<char, std::shared_ptr<Trie> > Map;
    
    char m_char;
    int m_word_count;
    std::shared_ptr<Trie> m_parent;
    std::shared_ptr<Map> m_children;
    Trie(const Trie&);
    

    
    Trie(Trie* parent, char c)
        : m_char(c), m_word_count(0), m_parent(parent), m_children(new Map)
    {
        
    }
    
    void add_word(const std::string& word, size_t index = 0)
    {
        if (index < word.length())
        {
            char key = word[index];
            if (isalpha(key))
            {
                // letter
                if (!m_children->count(key))
                {
                    (*m_children)[key] = std::shared_ptr<Trie>(new Trie(this, key));
                }
                (*m_children)[key]->add_word(word, index + 1);
            }
            else
            {
                // not a letter
                add_word(word, index + 1);
            }
        }
        else
        {
            if (m_parent != NULL) // empty words should never be counted
            {
                ++m_word_count;
            }
        }
    }
    
    void get_top_counts(std::vector<Trie*>& most_counted, int& distinct_word_count, int& total_word_count)
    {
        if (m_word_count > 0)
        {
            ++distinct_word_count;
            total_word_count += m_word_count;
        }
        if (m_word_count > most_counted[0]->m_word_count)
        {
            most_counted[0] = this;
            //most_counted.sort();
            std::sort(std::begin(most_counted), std::end(most_counted), [] (const Trie* v1, const Trie* v2) -> bool
            {
                return v1->m_word_count < v2->m_word_count;
            });
        }
        for (auto& pair: *m_children)
        {//
            (*m_children)[pair.first]->get_top_counts(most_counted, distinct_word_count, total_word_count);
        }
    }
    
    std::string to_string() const
    {
        if (!m_parent)
            return "";
        else
            return m_parent->to_string() + (m_char);
    }

};

#endif /* defined(__FrequencyWordInCatalog__Trie__) */
