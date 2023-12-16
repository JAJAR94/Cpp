#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using std::string;
using std::vector;

enum class Genre
{
    None,
    Fiction,
    NonFiction,
    Periodical,
    Biography,
    Children
};

class Book
{
private:
    int copyright;
    string isbn, title, author;
    string status = "Single";
    Genre genre;

public:
    Book(string _isbn, string _title, string _author, int _copyright, Genre _genre)
    {
        isbn = _isbn;
        title = _title;
        author = _author;
        copyright = _copyright;
        genre = _genre;
    }

    

    string getisbn()
    {
        return isbn;
    }

    string gettitle()
    {
        return title;
    }

    string getauthor()
    {
        return author;
    }

    string getstatus()
    {
        return status;
    }

    int getcopyright()
    {
        return copyright;
    }

    Genre getgenre()
    {
        return genre;
    }

    string print_genre()
    {
        switch (genre)
        {
        case Genre::Fiction:
            return "Fiction";

        case Genre::NonFiction:
            return "Nonfinction";

        case Genre::Periodical:
            return "Periodical";

        case Genre::Biography:
            return "Biography";

        case Genre::Children:
            return "Children";
        default:
            return "KUY";
        }
    }

    void check_in_out()
    {
        if (status == "Single")
        {
            status = "Taken";
        }
        else
        {
            status = "Single";
        }
    }

    void print_status()
    {
        std::cout << status;
    }

    bool compare(const Book &otherbook)
    {
        return isbn == otherbook.isbn;
    }

    
    
};


string findbytitle(string booktitle,vector<Book> bookshelf){
    for (int i =0 ;i<=bookshelf.size();i++){
        if(bookshelf[i].gettitle() == booktitle){
            return "Yes";
        }
        else{
            return "Nope";
        }
    }
}

string findbyisbn(string bookisbn,vector<Book> bookshelf){
    for (int i =0 ;i<=bookshelf.size();i++){
        if(bookshelf[i].getisbn() == bookisbn){
            return "Yes";
        }
        else{
            return "Nope";
        }
    }
}

Genre getenumtype(string type){
    if (type == "Fiction")
    {
        return Genre::Fiction;
    }
    if (type == "NonFiction")
    {
        return Genre::NonFiction;
    }
    if (type == "Periodical")
    {
        return Genre::Periodical;
    }
    if (type == "Biography")
    {
        return Genre::Biography;
    }
    if (type == "Children")
    {
        return Genre::Children;
    }
}

void getlist(string findgenre, vector<Book> bookshelf){
    Genre bookgenre = getenumtype(findgenre);
    for (int i =0 ;i<=bookshelf.size();i++){
        if(bookshelf[i].getgenre() == bookgenre){
            std::cout<<bookshelf[i].gettitle()<<"\n";
        }
    }
}

Book read(std::istream &is)
{
    string _isbn1, title1, author1, genreinput;
    int copyright1;
    is >> _isbn1 >> title1 >> author1 >> copyright1 >> genreinput;
    Book book(_isbn1, title1, author1, copyright1, getenumtype(genreinput));
    return book;

}

void sortbyalphabet(vector<Book> &bookshelf){
    bool sorted = false;
    while (!sorted)
    {
        sorted = true;
        for (int i = 0; i < bookshelf.size() - 1; i++)
        {
            if (bookshelf[i].gettitle() > bookshelf[i + 1].gettitle())
            {
                sorted = false;
                Book temp = bookshelf[i];
                bookshelf[i] = bookshelf[i + 1];
                bookshelf[i + 1] = temp;
            }
        }
    }
}

void sortbyisbn(vector<Book> &bookshelf){
    bool sorted = false;
    while (!sorted)
    {
        sorted = true;
        for (int i = 0; i < bookshelf.size() - 1; i++)
        {
            if (bookshelf[i].getisbn() > bookshelf[i + 1].getisbn())
            {
                sorted = false;
                Book temp = bookshelf[i];
                bookshelf[i] = bookshelf[i + 1];
                bookshelf[i + 1] = temp;
            }
        }
    }
}

std::ostream &print(std::ostream &os, Book &book)
{
    os << book.getisbn() << book.getauthor() << book.gettitle() << book.getcopyright()
       << book.getstatus() << book.print_genre();
    return os;
}

int main(){

    Book book = read(std::cin);
    
    
    
    
    print(std::cout,book);
    return 0;
}