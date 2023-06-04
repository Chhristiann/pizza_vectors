/*
    Christian Chacon | 5/23/23

    CIS 230 - 01
*/

#include <iostream>
#include <limits>
#include <vector>
#include <iomanip>

class Pizza{
private:
    std::string type;
    std::string size;
    short int toppings;

public:
    //non-default constructors
    Pizza(std::string type, std::string size, short int toppings){
        this->type = type;
        this->size = size;
        this->toppings = toppings;
    }

    //mutators
    void setType(std::string type){this->type = type;}
    void setSize(std::string size){this->size = size;}
    void setToppings(short int toppings){this->toppings = toppings;}
    
    //accessors
    std::string getSize(){return size;}
    std::string getType(){return type;}
    short int getToppings(){return toppings;}

    //utility functions
    double calcPrice() const {
        double price = 0;

        if(size == "Small"){price = 10.00;}
        else if(size == "Medium"){price = 14.00;}
        else if(size == "Large"){price = 17.00;}

        price += (toppings * 2.00);

        return price;
    }

    //accessor(s)
    std::string printPizza() const {
        return(type + " " + size + " pizza with " + std::to_string(toppings) + " toppings.\n");
    }
};// - - - - End Pizza Class - - - - 

class OrderInformation{
private:
    std::vector <Pizza> customerOrder;
    std::string name;
    std::string phone;
    double totalPrice;

public:
    //non-default constructor
    OrderInformation(std::string name, std::string phone){
        this->name = name;
        this->phone = phone;
        totalPrice = 0.00;
    }

    //mutators
    void addPizza(const Pizza &pizza){
        customerOrder.push_back(pizza);
        totalPrice += pizza.calcPrice();
    }

    //accessor(s)
    std::string printCustInfo(){
        return ("\n  " + name + " : " + phone);
    }
    std::string printOrder(){
        std::string details;
        for (const Pizza& pizza : customerOrder) {
            details += ("  " + pizza.printPizza());
        }
        return details;
    }
    double printTotalPrice(){return totalPrice;}
};// - - - - End Order Information Class - - - - 

Pizza orderPizza();
OrderInformation getCustInfo();

int main(){
    std::cout<<std::setprecision(2)<<std::fixed;
    std::string name, phone;
    short int numPizzas;
    char addMore;

    std::cout<<"How many pizzas would you like? ";
        std::cin>>numPizzas;

        while(std::cin.fail() || (numPizzas < 1 || numPizzas > 20)){
            std::cout<<"\n  Invalid. \nStore policy requires payment upfront for more than 20 pizzas!";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout<<"\nHow many pizzas would you like? ";
                std::cin>>numPizzas;    
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
    OrderInformation order(getCustInfo());//declare class

    for(int x = 0; x < numPizzas; x++){
        Pizza pizza(orderPizza());
        order.addPizza(pizza);
    }

    while(addMore != 'N'){
        std::cout<<"Would you like to add another? (Y/N): ";
            std::cin>>addMore;
                addMore = toupper(addMore);

            while(std::cin.fail() || (addMore != 'Y' && addMore != 'N')){
                std::cout<<"\n  Invalid."<<std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout<<"Would you like to add another? (Y/N): ";
                std::cin>>addMore;
                    addMore = toupper(addMore);
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if(addMore == 'N'){break;}

        Pizza pizza(orderPizza());
        order.addPizza(pizza);
    }

    std::cout<<std::endl;
    std::cout<<"Customer Information: "<<order.printCustInfo()<<std::endl;
    std::cout<<"Order Details: \n"<<order.printOrder()<<std::endl;
    std::cout<<"Total Due: $"<<order.printTotalPrice();

    return 0;
}

Pizza orderPizza(){
    std::string type, size;
    char typeInput, sizeInput;
    short int toppings;

    std::cout<<"\nWhat type of pizza would you like?"<<std::endl;
    std::cout<<"  D - Deep Dish\n  H - Hand Tossed\n  P - Pan Cooked\n->";
        std::cin>>typeInput;
            typeInput = toupper(typeInput);
        
        while(std::cin.fail() || (typeInput != 'D' && typeInput != 'H' && typeInput != 'P')){
            std::cout<<"\n  Invalid";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout<<"\nWhat type of pizza would you like?"<<std::endl;
            std::cout<<"  D - Deep Dish\n  H - Hand Tossed\n  P - Pan Cooked\n->";
                std::cin>>typeInput;
                    typeInput = toupper(typeInput);
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if(typeInput == 'D'){type = "Deep Dish";}
        else if(typeInput == 'H'){type = "Hand Tossed";}
        else if(typeInput == 'P'){type = "Pan Cooked";}
    
    std::cout<<"\nWhat size of pizza would you like? "<<std::endl;
    std::cout<<"  S - Small\n  M - Medium\n  L - Large\n ->";
        std::cin>>sizeInput;
            sizeInput = toupper(sizeInput);
        
        while(std::cin.fail() || (sizeInput != 'S' && sizeInput != 'M' && sizeInput != 'L')){
            std::cout<<"\n  Invalid";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout<<"\nWhat size of pizza would you like? "<<std::endl;
            std::cout<<"  S - Small\n  M - Medium\n  L - Large\n ->";
                std::cin>>sizeInput;
                    sizeInput = toupper(sizeInput);
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if(sizeInput == 'S'){size = "Small";}
        else if(sizeInput == 'M'){size = "Medium";}
        else if(sizeInput == 'L'){size = "Large";}

    std::cout<<"\nHow many toppings? (No Halfs): ";
        std::cin>>toppings;
        
        while(std::cin.fail() || (toppings < 0 || toppings > 8)){
            std::cout<<"\n  Invalid. No more than 8.";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout<<"\nHow many toppings? (No Halfs): ";
            std::cin>>toppings;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
    Pizza onePizza(type, size, toppings);

    return onePizza;
}

OrderInformation getCustInfo(){
    std::string name;
    std::string phone;

    std::cout<<"For your order, what is the name? ";
        getline(std::cin, name);//cannot validate line

    std::cout<<"What is the phone number? ";
        getline(std::cin, phone);//cannot validate line

    OrderInformation pizzaInfo(name, phone);

    return pizzaInfo;
}
