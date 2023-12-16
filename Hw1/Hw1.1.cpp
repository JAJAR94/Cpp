#include <iostream>
#include <string>
using std::cin;         
using std::endl;
using std::cout;        
using std::string;

int main(){

    cout << "Pls enter Warrior name: ";
    string warriorname;
    cin >> warriorname;

    cout << "Pls enter Mage name: ";
    string magename;
    cin >> magename;

    cout << "Pls enter Ninja name: ";
    string ninjaname;
    cin >> ninjaname;
    
    cout << "Pls enter Fighter name: ";
    string fightername;
    cin >> fightername;

    const string warrior = "Warrior: " + warriorname;
    const string mage = "Mage: " + magename;
    const string ninja = "Ninja: " + ninjaname;
    const string fighter = "Fighter: " + fightername;
    
    int size;
    if (warrior.size()+mage.size()>ninja.size()+fighter.size()){
        size = warrior.size()+mage.size();
    }
    else{
        size = ninja.size()+fighter.size();
    }

    size*=2;
    int column;
    
    for (int row =1; row<=9; row++){

        for(column = 1; column<=size ; column++){

            if (row==1 || row==9 || row==5){
                cout << "*";
                //column++;
            }

            if (row==2 || row==4 || row==6 || row==8){
                
                if (column==1 || column==size || column==size/2){
                    cout << "*";
                    //column++;
                }

                else{
                    cout << ' ';
                    //column++;
                }
            }

              else {
                 if (row==3){

                     if (column==1){
                         cout << "*";
                         
                         cout << warrior;
                         column+= warrior.size();

                    }

                    if (column==size/2){
                        cout << "*";
                        
                        cout << mage;
                        column+= mage.size();
                    }

                    else{
                    cout << ' ';
                    
                }
                }
            }
            
        }
        cout << "\n";
        //column =1;
        
    }
    return 0;
}