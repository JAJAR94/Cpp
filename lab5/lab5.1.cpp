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

    bool find(vector<Book> bookshlef){
        for (int i =0;i<=bookshlef.size();i++){
          if (isbn == bookshlef[i].isbn){
            return true;
          }
        }
        
    }
};

Book read(std::istream &is)
{
    string _isbn1, title1, author1, genreinput;
    int copyright1;
    Genre genre;
    is >> _isbn1 >> title1 >> author1 >> copyright1 >> genreinput;

    if (genreinput == "Fiction")
    {
        genre = Genre::Fiction;
    }
    if (genreinput == "NonFiction")
    {
        genre = Genre::NonFiction;
    }
    if (genreinput == "Periodical")
    {
        genre = Genre::Periodical;
    }
    if (genreinput == "Biography")
    {
        genre = Genre::Biography;
    }
    if (genreinput == "Children")
    {
        genre = Genre::Children;
    }
    Book book(_isbn1, title1, author1, copyright1, genre);
    return book;

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