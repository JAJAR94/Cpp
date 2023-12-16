#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::string;

class Text_base
{
protected:
    string stringtext;
    string a;

public:
    Text_base()
    {
        stringtext = "";
    }

    Text_base(string _stringtext, string a = "")
    {
        stringtext = _stringtext;
        
    }

    virtual string text() const{
        return stringtext;
    };
   
};

class Quoted_text : public Text_base
{
private:
    string open;
    string end;

public:
    Quoted_text(string _stringtext, string _open, string _end = "")
    {
        stringtext = _stringtext;
        open = _open;
        if (_end == "")
        {
            end = _open;
        }
        else
        {
            end = _end;
        }
    }

    string text() const override
    {
        return open + stringtext + end;
    }
};

class Crypted_text : public Text_base
{
public:
    Crypted_text()
    {
        stringtext = "";
    }

    Crypted_text(string _stringtext)
    {
        stringtext = _stringtext;
    }

    string text() const override
    {
        string output = "";
        for (char c : stringtext)
        {
            if (c >= 65 && c <= 90)
            {
                output += char(155 - c);
            }
            else if (c >= 97 && c <= 122)
            {
                output += char(219 - c);
            }
            else
            {
                output += c;
            }
        }
        return output;
        ;
    }
};

class Text{
    private:
    string word;
    public:
    Text(Text_base basetext) : word(basetext.text()) {}
    Text(Quoted_text quotedtext) : word(quotedtext.text()) {}
    Text(Crypted_text cryptedtext) : word(cryptedtext.text()) {}
    string text() const { return word; }
    
};

int main(int, char **)
{

    vector<Text> words{Quoted_text("C++", "<i>", "</i>"),
                        Crypted_text("Zidane"), 
                        Quoted_text("Rust", "*"), 
                        Quoted_text("Python", "[[", "]]"), 
                        Text_base("Vivi")};

    for (const auto& w: words) {
        std::cout << w.text() << std::endl;
    }


    Text_base q0("Python", "*");
    auto text =  q0.text(); // "Python"
    std::cout<<text<<'\n';

    Quoted_text q("Python", "*");
    const Text_base& rq = q;
    text = q.text();  // "*Python*"
    text = rq.text(); // "*Python*"
    std::cout<<text;

    q = Quoted_text("Python", "<em>", "</em>");
    text = q.text();  // "<em>Python</em>"
    text = rq.text(); // "<em>Python</em>"
    std::cout<<text<<'\n';

    Crypted_text ct("Abc101");
    const Text_base& rct = ct;
    text = ct.text();  // "Zyx101"
    text = rct.text(); // "Zyx101"
    std::cout<<text<<'\n';

    ct = Crypted_text{"PYthoN101"};
    text = ct.text();  // "KBgslM101"
    text = rct.text(); // "KBgslM101"
    std::cout<<text<<'\n';

   
}
