#include <iostream>
#include <vector>
#include <string>

class Writer;

class Doc_element
{

public:
    virtual void write_geometry(const Writer &w, int lv)const;

    virtual void write_document(const Writer &w, const std::string &type) const;

    virtual void write_to(const Writer &w, int lv) const;

    static Doc_element text(const std::string &t);

    explicit Doc_element(const std::string& n) 
        : name(n) {}

    Doc_element(const std::string& n, const std::vector<Doc_element>& children)
        : name(n), children(children) {}

private:
    std::string name;
    std::vector<Doc_element> children;

};

Doc_element Doc_element::text(const std::string &t)
{
   return Doc_element(t);
}

class Writer
{
public:
    Writer(std::ostream& os) 
        : os(os) {}

    void write(const std::string text) const 
    {
        os << text;
    }
    std::ostream& os;
    
};


void Doc_element::write_geometry(const Writer &w, int lv) const
{
  
    if (children.size()==0){
        
        w.write(name);
    }
    else
    {
        w.write("<"+name);
        for (const auto& child : children) {
            child.write_geometry(w,0);
        }
       w.write("/>\n");
    }
    
}

void Doc_element::write_document(const Writer &w, const std::string &type) const
{   
    if (type == "svg"){
        write_geometry(w,0);
    }
    if (type == "html"){
        write_to(w,0);
    }
    
}

void Doc_element::write_to(const Writer &w, int lv) const
{   
    if (children.size()==0){
        w.write("<"+name+">\n");
    }
    else
    {
        w.write("<"+name+">\n");
        for (const auto& child : children) {
            child.write_to(w,0);
        }
        w.write("</"+name+">\n");
    }
}

int main()
{
    Writer w(std::cout);
    auto t = Doc_element::text("<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>");
    auto e = Doc_element("em", {t});
    e.write_document(w,"svg");
}
