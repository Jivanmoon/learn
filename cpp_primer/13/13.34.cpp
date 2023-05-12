#include<bits/stdc++.h>
using namespace std;
class Folder;
class Message {
    friend void swap(Message &, Message &);
public:
    explicit Message(const string &s = ""): contents(s) {}
    Message(const Message &rhs);
    Message &operator=(const Message &rhs);
    ~Message();
    void save(Folder &);
    void remove(Folder &);

private:
    string contents;
    set<Folder *> folders;
    void add_to_Folders(const Message &);
    void remove_from_Floders();
};

void Message::save(Folder &f) {
    f.addMsg(this);
    folders.insert(&f);
}

void Message::remove(Folder &f) {
    f.remMsg(this);
    folders.erase(&f);
}

void Message::add_to_Folders(const Message &msg) {
    for(auto f : msg.folders) {
        f->addMsg(this);
    }
}

void Message::remove_from_Floders() {
    for(auto f : folders) {
        f->remMsg(this);
    }
}

Message::Message(const Message &rhs): contents(rhs.contents), folders(rhs.folders) {
    add_to_Folders(rhs);
}

Message &Message::operator=(const Message &rhs) {
    remove_from_Floders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

Message::~Message() {
    remove_from_Floders();
}

void swap(Message &lhs, Message &rhs) {
    lhs.remove_from_Floders();
    rhs.remove_from_Floders();
    swap(lhs.contents, rhs.contents);
    swap(lhs.folders, rhs.folders);
    lhs.add_to_Folders(lhs);
    rhs.add_to_Folders(rhs);
}

void 