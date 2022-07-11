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
#include "StrVec.h"

class QueryResult;

class TextQuery {
public:
    TextQuery(std::ifstream &);
    QueryResult query(const std::string &) const;
private:
    std::shared_ptr<StrVec> file;
    std::map<std::string, std::shared_ptr<std::set<std::size_t>>> wm; 
};

class QueryResult {
    friend std::ostream &print(std::ostream &, const QueryResult &);
public:
    QueryResult(std::string s, std::shared_ptr<std::set<size_t>> p, std::shared_ptr<StrVec> f):
        sought(s), lines(p), file(f) {}
private:
    std::string sought;
    std::shared_ptr<std::set<size_t>> lines;
    std::shared_ptr<StrVec> file;
};
std::ostream &print(std::ostream &os, const QueryResult &qr);
#endif