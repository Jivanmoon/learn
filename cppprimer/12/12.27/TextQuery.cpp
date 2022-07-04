#include "TextQuery.h"

TextQuery::TextQuery() {
    std::make_shared<std::vector<std::string>>();
    std::make_shared<std::map<std::string, std::set<std::size_t>>>();
}

TextQuery::TextQuery(std::ifstream &fin) {
    std::make_shared<std::vector<std::string>>();
    std::make_shared<std::map<std::string, std::set<std::size_t>>>();
    set_text(fin);
}

void TextQuery::set_text(std::ifstream &fin) {
    std::size_t line_num = 1;
    std::string line;
    while(std::getline(fin, line)) {
        text_lines->push_back(line);
        std::istringstream sin(line);
        std::string word;
        while(sin >> word) {
            (*word_linenum)[word].insert(line_num);
        }
        ++line_num;
    }
}

QueryResult TextQuery::query(const std::string &word) const {
    return QueryResult(*this, word);
}

void print(std::ostream &cout, const QueryResult &query_res) {
    std::size_t occur_times = (*query_res.wl_ptr)[query_res.query_word].size();
    cout << query_res.query_word << " occurs " << occur_times << " times" << std::endl;
    for(const auto &num : (*query_res.wl_ptr)[query_res.query_word]) {
        cout << "\tline( " << num <<" ) " << query_res.tl_ptr->at(num - 1) << std::endl;
    }
}