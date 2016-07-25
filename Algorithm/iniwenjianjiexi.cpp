/*/   //test file data.ini

  [mydatabase]

       connect = jdbc:odbc:mysrc
user = administrator
		pwd = 123456

[mytable]

tablename = student

  tablefields = studno, studname, age, birthday

*/



#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

class Section {
    string section;
    map<string, string> m;

public:
    Section(string s):section(s) {}
    void add(string key, string value) {
        pair<string, string> p(key, value);
        m.insert(p);
    }
    void show(ostream& os) {
        os << section << endl;
        map<string, string>::iterator it = m.begin();
        for (; it != m.end(); it++)
            os << "\t" << it->first << " = " << it->second << endl;
    }
};


class Collect {
    map<string, Section> ms;

public:
    void add(string str) {
        pair<string, Section> p(str, Section(str));
        ms.insert(p);
    }
    Section* get(string section) {
        map<string, Section>::iterator it = ms.find(section);
        return &(it->second);
    }
    void show(ostream& os) {
        map<string, Section>::iterator it = ms.begin();
        for (; it!=ms.end(); it++)
            (it->second).show(os);
    }
};

class ReadIni {
    string path;
    Collect& collect;

private:
    void trim(string& str) {
        str.erase(0, str.find_first_not_of(" "));
        str.erase(0, str.find_first_not_of("\t"));
        str.erase(str.find_last_not_of(" ")+1, str.length());
        str.erase(str.find_last_not_of("\t")+1, str.length());
    }
    string getSection(string str) {
        str.erase(0, str.find_first_not_of("["));
        str.erase(str.find_last_not_of("]")+1, str.length()-1);
        return str;
    }
    void getPair(string str, string& key, string& value) {
        int pos = str.find("=");
        key = str.substr(0, pos);
        value = str.substr(pos+1, str.length()-pos-1);
        trim(key);
        trim(value);
    }

public:
    ReadIni(string p, Collect& c):path(p), collect(c) {}
    void process() {
        string line;
        string section;
        string key;
        string value;

        Section* pSection = NULL;

        ifstream in(path.c_str());
        if (!in) {
            cerr << path << " not exist! please check again" << endl;
            exit(1);
        }
        while (!in.eof()) {
            getline(in, line);
            trim(line);
            if (line == "")
                continue;
            if (line.at(0) == '[') {
                section = getSection(line);
                collect.add(section);
                pSection = collect.get(section);
            } else if (line.at(0) != '[') {
                getPair(line, key, value);
                pSection->add(key, value);
            }
        }
        in.close();
    }
};


int main() {
    string path = "data.ini";
    Collect collect;
    ReadIni ri(path, collect);

    ri.process();
    collect.show(cout);

    return 0;
}
