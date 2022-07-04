#ifndef TEXT_QUERY_H
#define TEXT_QUERY_H

#include<vector>
#include<string>
#include<map>
#include<set>
#include<iostream>
#include<sstream>
#include<fstream>
#include<memory>

class QueryResult;

class TextQuery {
    friend QueryResult; 
public:
    TextQuery();
    TextQuery(std::ifstream &);
    void set_text(std::ifstream &);
    QueryResult query(const std::string &word) const;
private:
    std::shared_ptr<std::vector<std::string>> text_lines;
    std::shared_ptr<std::map<std::string, std::set<std::size_t>>> word_linenum; 
};

class QueryResult {
    friend void print(std::ostream &, const QueryResult &);
public:
    QueryResult() = default;
    QueryResult(const TextQuery &tq, const std::string &word): tl_ptr(tq.text_lines), wl_ptr(tq.word_linenum), query_word(word) {}
private:
    std::shared_ptr<std::vector<std::string>> tl_ptr;
    std::shared_ptr<std::map<std::string, std::set<std::size_t>>> wl_ptr;
    std::string query_word;
};
void print(std::ostream &, const QueryResult &);

#endif