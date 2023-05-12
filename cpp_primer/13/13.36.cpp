#include<bits/stdc++.h>
using namespace std;
class Message;

class Folder {
    friend void swap(Folder &, Folder &);
public:
    Folder() = default;
    Folder(const Folder &);
    Folder &operator=(const Folder &);
    ~Folder();
    void addMsg(Message *m) {
        messages.insert(m);
    }
    void remMsg(Message *m) {
        messages.erase(m);
    }
private:
    set<Message *> messages;
    void add_to_message(const Folder &);
    void remove_from_message();
};

class Message {
    friend void swap(Message &, Message &);
public:
    explicit Message(const string &s = ""): contents(s) {}
    Message(const Message &rhs);
    Message &operator=(const Message &rhs);
    ~Message();
    void save(Folder &);
    void remove(Folder &);
    void addFld(Folder *f) {
        folders.insert(f);
    }
    void remFld(Folder *f) {
        folders.erase(f);
    }
private:
    string contents;
    set<Folder *> folders;
    void add_to_Folders(const Message &);
    void remove_from_Floders();
};

void Message::save(Folder &f) {
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f) {
    folders.erase(&f);
    f.remMsg(this);
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
    if(this != &rhs) {
        remove_from_Floders();
        contents = rhs.contents;
        folders = rhs.folders;
        add_to_Folders(rhs);
    }
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

void Folder::add_to_message(const Folder &rhs) {
    for(auto m : rhs.messages) {
        m->addFld(this);
    }
}

void Folder::remove_from_message() {
    for(auto m : messages) {
        m->remFld(this);
    }
}

Folder::Folder(const Folder &rhs): messages(rhs.messages) {
    add_to_message(rhs);
}

Folder::~Folder() {
    remove_from_message();
}

Folder &Folder::operator=(const Folder &rhs) {
    if(this != &rhs) {
        remove_from_message();
        messages = rhs.messages;
        add_to_message(rhs);
    }
    return *this;
}

void swap(Folder &lhs, Folder &rhs) {
    lhs.remove_from_message();
    rhs.remove_from_message();
    swap(lhs.messages, rhs.messages);
    lhs.add_to_message(lhs);
    rhs.add_to_message(rhs);
}
