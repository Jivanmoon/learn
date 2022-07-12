#include<set>
#include<string>
using std::string;
using std::set;
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
    Message(Message &&rhs);
    Message &operator=(const Message &rhs);
    Message &operator=(Message &&rhs);
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
    void move_folders(Message *m);
    void add_to_Folders(const Message &);
    void remove_from_Floders();
};