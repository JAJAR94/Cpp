#include <iostream>
#include <string>
#include <fstream>

using std::string;


string stylize(string word){
    if (word.front() == '*' && word.back() == '*' ){
        return "<strong>"+word.substr(1,word.size()-2)+"</strong>";
    }

    else {
        return word;
    }
    
}
string unstylize(string word){
    
    if (word.front() == '*' && word.back() == '*' ){
        return word.substr(1,word.size()-2);
    }

    else {
        return word;
    }

}

string puttd(string word){
    return "<td>"+word+"</td>";
}

string puttr(string word){
    return "<tr>"+word+"</tr>";
}

string putth(string word){
    return "<th>"+word+"</th>";
}

string puttable(string word){
    return "<table>"+word+"</table>";
}

string putbody(string word){
    return "<body>" +word +"</body>";
}

string puthtml(string word){
    return "<html>"+word+"</html>";
}

int main(){
    //std::ofstream myfile("test.html");
    auto words = {"c","*c++*","Rust*","*Python*","*Java"};
    auto head = {" ","unstylized","stylized"};
    string a,b;
    for (const auto& w: head){
        a+=(putth(w));
    }
    b+=puttr(a);
    b+="\n";
    a.erase()  ;
    
    for (const auto& w: words){
        a +=puttd(w);
        a += puttd(unstylize(w));
        a +=puttd(stylize(w));
        b+=puttr(a);
        b+="\n";
        a.erase()  ;
    }
    std:: cout << puthtml(putbody(puttable(b)));
    
    
    return 0;
}