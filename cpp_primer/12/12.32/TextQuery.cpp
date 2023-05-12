#include "TextQuery.h"

TextQuery::TextQuery(std::ifstream &is): file(new StrBlob) {
    std::string text;
    while(std::getline(is, text)) {
        file->push_back(text);
        int n = file->size() - 1;
        std::istringstream line(text);
        std::string tmp;
        while(line >> tmp) {
            std::string word;
            std::remove_copy_if(tmp.begin(), tmp.end(), std::back_inserter(word), ispunct);
            auto &lines = wm[word];
            if(!lines) {
                lines.reset(new std::set<line_no>);
            }
            lines->insert(n);
        }
    }
}

QueryResult
TextQuery::query(const std::string &sought) const {
    static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
    auto loc = wm.find(sought);
    if(loc == wm.end()) {
        return QueryResult(sought, nodata, file);
    }
    else {
        return QueryResult(sought, loc->second, file);
    }
}

std::ostream &print(std::ostream &os, const QueryResult &qr) {
    os << qr.sought << " occurs " << qr.lines->size() << " "
        << "time" << (qr.lines->size() > 1 ? "s" : "") << std::endl;
    for (auto num : *qr.lines) {
        StrBlobPtr ptr(*(qr.file), num);
        os << "\t(line " << num + 1 << ") " << ptr.deref() << std::endl;
    }
		
    return os;
}