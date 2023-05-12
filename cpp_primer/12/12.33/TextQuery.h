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
#include<algorithm>

class QueryResult;

class TextQuery {
    friend QueryResult; 
public:
    using line_no = std::vector<std::string>::size_type;
    TextQuery(std::ifstream &);
    void set_text(std::ifstream &);
    QueryResult query(const std::string &) const;
private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string, std::shared_ptr<std::set<std::size_t>>> wm; 
};

class QueryResult {
    friend std::ostream &print(std::ostream &, const QueryResult &);
public:
    QueryResult(std::string s, std::shared_ptr<std::set<TextQuery::line_no>> p, std::shared_ptr<std::vector<std::string>> f):
        sought(s), lines(p), file(f) {}
    std::set<TextQuery::line_no>::iterator begin() {
        return lines->begin();
    }
    std::set<TextQuery::line_no>::iterator end() {
        return lines->end();
    }
    std::shared_ptr<std::vector<std::string>> get_file() {
        return file;
    }
private:
    std::string sought;
    std::shared_ptr<std::set<TextQuery::line_no>> lines;
    std::shared_ptr<std::vector<std::string>> file;
};
std::ostream &print(std::ostream &os, const QueryResult &qr);

#endif