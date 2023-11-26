#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <string.h>
#include<cstring>

using namespace std;

class RandomNames
{
public:
    int a,b,i;
    string aux;
    string extra = "extra";
    ~RandomNames();


    void names(string fname1, string fname2, string fname3)
    {
//Citire prenume din fisier(firstnames.csv)

        vector<vector<string>> content1;
        vector<string> row;
        string line, word;

        fstream file1 (fname1, ios::in);
        if(file1.is_open())
        {
            while(getline(file1, line))
            {
                row.clear();

                stringstream str(line);

                while(getline(str, word, ','))
                    row.push_back(word);
                content1.push_back(row);
            }
        }
        else
            cout<<"Could not open the file/ Nu s-a putut deschide fisierul. \n";

//Citire nume din fisier(lastnames.csv)

        vector<vector<string>> content2;
        fstream file2 (fname2, ios::in);
        if(file2.is_open())
        {
            while(getline(file2, line))
            {
                row.clear();

                stringstream str(line);

                while(getline(str, word, ','))
                    row.push_back(word);
                content2.push_back(row);
            }
        }
        else
        {
            cout<<"Could not open the file/ Nu s-a putut deschide fisierul.\n";
        }
//Se genereaza numere aleatorii cu ajutorul carora se fac numele random, care apoi sunt scrise in fisier

        std::ofstream file3;
        file3.open("wednesdayCast.csv", std::ios::app);

        if(file3.is_open())
        {
            for(i=0; i<int(content1.size()); i++)
            {
                a = rand() % 132;
                b = rand() % 132;
                aux = content1[a][0] + " " + content2[b][0];

                file3 << aux << "," << extra << '\n';

            }
            cout << "The random names have been added to the cast list/ Numele aleatorii au fost adaugate in lista" << endl;
        }
        else
        {
            cout<<"Could not open the file/ Nu s-a putut deschide fisierul.\n";
        }
    }
};

//Destructor:
RandomNames::~RandomNames(void)
{
    cout << "RandomNames class is being deleted/ Clasa RandomNames a fost distrusa."<< endl;
}

class Busses
{
public:

    int a, full, rest;
    ~Busses();

    int calculate(string fname1, string language)
    {
//Se calculeaza numarul necesar de autobuze - se extrag persoanele din csv, se afla numarul lor, apoi se calculeaza autobuzele
        vector<vector<string>> content1;
        vector<string> row;
        string line, word;

        fstream file1 (fname1, ios::in);
        if(file1.is_open())
        {
            while(getline(file1, line))
            {
                row.clear();

                stringstream str(line);

                while(getline(str, word, ','))
                    row.push_back(word);
                content1.push_back(row);
            }
        }
        else
        {
            cout<<"Could not open the file/ Nu s-a putut deschide fisierul.\n";
        }

        a = int(content1.size());

        full = a/50;
        rest = a%50;
        if(rest < 50) rest = 1;

        a = full + rest;

        if(language == "english") cout << "There are " << a << " busses needed." <<int(content1.size())<< endl;
        else if(language == "romana") cout << "Este nevoie de " << a << " autobuze." << endl;
        return a;

    }
};

//Destructor:
Busses::~Busses(void)
{
    cout << "Busses class is being deleted/ Clasa Busses a fost distrusa."<< endl;
}

//Mosteniri:
class Human
{
public:
    int type = 0;
    ~Human();

    int calculate()
    {
        type++;
        return type;
    }
};

class Vampire : public Human{
};

class Warewolf : public Human{
};

class Psychic : public Human{
};

class Siren : public Human{
};

//Destructor:
Human::~Human(void)
{
    cout << "Human class is being deleted/ Clasa Human a fost distrusa." << endl;
}

//Mosteniri:
class Normal
{
public:
    int type=0;
    int a=0;
    string language;
    ~Normal();

    void getLanguage(string l)
    {
       language = l;
    }

    void createMenu(string language)
    {

       std::ofstream file;
        file.open("menu.csv", std::ios::app);
//Se genereaza fisierul csv cu meniul(atat in engleza, cat si in romana) pe 3 zile
        if(file.is_open())
        {
            file << "Menu - english: " << '\n' << endl;
            file << "Normal : " << '\n' << endl;
            file << "Chicken soup" << "," << "Grilled salmon with vegetables" << "," << "Chocolate cake" << '\n' << endl;
            file << "Noodle soup" << "," << "Caesar salad" << "," << "Pancakes" << '\n' << endl;
            file << "Beef soup" << "," << "Cheeseburger" << "," << "Tiramisu" << '\n' << endl;

            file << "Vegetarian : " << '\n' << endl;
            file << "Tomato soup" << "," << "Vegetable dish with soy sauce" << "," << "Chia pudding with peaches" << '\n' << endl;
            file << "Spiced carrot & lentil soup" << "," << "Spinach & ricotta gnocchi" << "," << "Lemon cheesecake" << '\n' << endl;
            file << "Pumpkin soup" << "," << "Roasted cauliflower pasta with toasted walnuts, parsley, garlic & lemon zest" << "," << "Vegan ice-cream" << '\n' << endl;

            file << "Flexitarian : " << '\n' << endl;
            file << "Lentil soup with olives and grilled game slices" << "," << "Grilled salmon with baked sweet potatoes and sautéed green beans" << "," << "Oat flakes with flax seeds + apple slices and cinnamon" << '\n' << endl;
            file << "Spiced carrot & lentil soup" << "," << "Roasted vegetable & black bean tacos" << "," << "Vegan ice-cream" << '\n' << endl;
            file << "Pumpkin soup" << "," << "Greek salad with Edamame" << "," << "Coconut lemon cake" << '\n' << endl;

            file << "Menou - romana: " << '\n' << endl;
            file << "Normal : " << '\n' << endl;
            file << "Supa de pui" << "," << "Somon cu legume la gratar" << "," << "Tort cu ciocolata" << '\n' << endl;
            file << "Supa cu taitei" << "," << "Salata Caesar" << "," << "Clatite" << '\n' << endl;
            file << "Ciorba de vita" << "," << "Cheeseburger" << "," << "Tiramisu" << '\n' << endl;

            file << "Vegetarian : " << '\n' << endl;
            file << "Supa de rosii" << "," << "Mancare de legume cu sos de soia" << "," << "Budinca de chia cu piersici" << '\n' << endl;
            file << "Supa picanta de morcovi si linte" << "," << "Gnocchi cu spanac si ricotta" << "," << "Cheesecake de lamaie" << '\n' << endl;
            file << "Supa de doveac" << "," << "Paste de conopida cu nuci prajite, patrunjel si usturoi" << "," << "Inghetata vegana" << '\n' << endl;

            file << "Flexitarian : " << '\n' << endl;
            file << "Supa de linte cu masline si felii de vanata la gratar" << "," << "Somon la gratar cu cartofi dulci copti si fasole verde sotata" << "," << "Fulgi de ovaz cu seminte de in + felii de mar si scortisoara" << '\n' << endl;
            file << "Supa picanta de morcovi si linte" << "," << "Tacos cu legume prăjite și fasole neagră" << "," << "Inghetata vegana" << '\n' << endl;
            file << "Supa de doveac" << "," << "Salată grecească cu Edamame" << "," << "Tort cu nucă de cocos și lămâie" << '\n' << endl;
            if(language== "english")cout << "The menu has been created" << endl;
            else if(language == "romana") cout << "Meniul a fost creat" << endl;
        }
        else
        {
            cout<<"Could not open the file/ Nu s-a putut deschide fisierul.\n";
        }
    }



    int calculate()
    {
        type++;

        return type;
    }

};

class Vegetarian : public Normal{
};

class Flexitarian : public Vegetarian{
};

//Destructors:
Normal::~Normal()
{
    cout << "Menu classes are being deleted/ Clasele Meniu au fost distruse." << endl;

}

//Polimorfism - Overriding(sau daca nu macar tentativa) pentru calcularea camerelor de hotel
class Full{
public:

    ~Full();

    int aux1;

    int calculate(int actors){

    aux1 = actors / 2;

    return aux1;
    }
};

class Rest : public Full{
public:

    int calculate(int actors){

    aux1 = actors%2;
    if(aux1 < 2 && aux1!= 0) aux1=1;

    return aux1;
    }
};

class Full1{
public:

    ~Full1();

    int aux1;

    int calculate(int actors){

    aux1 = actors / 3;

    return aux1;
    }
};

class Rest1 : public Full1{
public:

    int calculate(int actors){

    aux1 = actors%3;
    if(aux1 < 3 && aux1!= 0) aux1=1;

    return aux1;
    }
};

//Destructori:
Full::~Full()
{
    cout << "Accomodation classes are being deleted/ Clasele Accomodation au fost distruse. " << endl;

}

Full1::~Full1()
{
    cout << "Accomodation classes are being deleted/ Clasele Accomodation au fost distruse. " << endl;

}

//Incapsulare:
class Drinks{
private:
    float drinks;
public:
    ~Drinks();
    //setter:
    //Se calculeaza cati litri de un anumit tip de lichid se beau pe zi pe set de toata echipa
    void setDrinks(string drink,int actors){
    if(drink == "water") this->drinks = 1 * actors;
    else if(drink == "coffee") this->drinks = 0.5 * actors;
    else if(drink == "juice") this->drinks = 0.8 *actors;
    }

    //getter:
    float getDrinks(){
    return this->drinks;
    }

    };

//Destructor:
Drinks::~Drinks()
{
    cout << "Drinks class is being deleted/ Clasa Drinks a fost distrusa." << endl;

}

//Incercare de Template:
template <typename X>
X exCastle(X x, X y)
{
    return(x/y > 0)? 2*(x/y): 2;
}

//Abstractizare:
//Afisare cost total
class Cost1{
public:

    virtual void hello() = 0;

    virtual void print(int days,float aux1,float aux2,float aux3,float aux4, float aux5, float aux6, string language){

    int total;
    //cazarea se ia: nr de zile-1 (se numara noptile)
    total = aux1 + aux2*days + aux3*days + aux4*(days-1) + aux5*days + aux6;

    if(language == "english ")cout << days << " days : " << " the total is around : " << total << " dollars. / " << endl ;
    else if(language == "romana") cout << days << " zile : " << " totalul este de aproximativ : "<< total << " dolari."<< endl;
    }
};

class Cost2 : public Cost1{
public:

    void print(){
    cout << "Hi!/Buna!";
    }

    void hello(){
    cout << "Not abstract anymore/Nu mai e abstract";
    }
};


int main()
{
    string language;
    cout << "Choose language/ Alegeti limba: english/ romana" << endl;
    cin >> language;

    // 1 DOLAR = 4.62 LEI

    //Generare nume random si scrierea lor in fisier
    /*RandomNames hello;
    string file1 = "firstnames.csv";
    string file2 = "lastnames.csv";
    hello.names(file1,file2,file3);*/
    string file3 = "wednesdayCast.csv";

    //Calculare autobuze(dus-intors):
    int busses;
    float bus_cost = 5680;
    Busses bus;
    busses = bus.calculate(file3, language);

    //Cost drum dus-intors aeroport:
    bus_cost = bus_cost * 2 * busses;
    bus_cost = bus_cost / 4.62;

    if(language == "english") cout << "The cost of the trips to the airport : " << bus_cost << endl;
    else if(language == "romana") cout << "Costul drumului dus-intors aeroport : " << bus_cost << endl;

    //Calculare monstrii:
    //Cast original:

    int aux, i, v, w, p, s, h;

    Human human;
    Vampire vampire;
    Warewolf warewolf;
    Psychic psychic;
    Siren siren;

    int initial_cast = 735;
    int actors = 54;
    int extras = 132;

    //Cost/zi:

    float makeup_cost;

    //Se aleg random "rolurile" extra-urilor care apoi se adauga la cast-ul initial

    for(i=0; i<(extras+actors); i++)
    {
        aux = rand() % 5;
        if(aux == 0) v = vampire.calculate();
        else if(aux == 1) w = warewolf.calculate();
        else if(aux == 2) p = psychic.calculate();
        else if(aux == 3) s = siren.calculate();
        else if(aux == 4) h = human.calculate();
    }


    //Afisare tipul si numarul creaturilor:

    if(language == "english")
        {
    cout << '\n' << "Final number of monsters : "<<'\n';
    cout << "Vampires : " << v <<  endl;
    cout << "Warewolves : " << w << endl;
    cout << "Psychics : " << p << endl;
    cout << "Sirens : " << s << endl;
    cout << "Humans : " << h << endl;
        }

    else if(language == "romana")
        {
    cout << '\n' << "Numarul final de monstrii : "<<'\n';
    cout << "Vampiri : " << v <<  endl;
    cout << "Varcolaci : " << w << endl;
    cout << "Clarvazatori : " << p << endl;
    cout << "Sirene : " << s << endl;
    cout << "Oameni : " << h << endl;
    }

    makeup_cost = v * 230 + w * 555+ s * 345 + p* 157 + h * 55;
    makeup_cost = makeup_cost / 4.62;

    //Afisare cost machiaj/zi total:

    if(language == "english")cout << "The makeup cost/ day for actors and extras : " << makeup_cost << endl;
    else if(language == "romana") cout << "Costul machiajului/ zi pentru actori si figuranti : " << makeup_cost << endl;

    //Meniuri(doar actori si figuranti):

    int normal,vegetarian,flexitarian;
    float food_cost;
    Normal menu1;
    Vegetarian menu2;
    Flexitarian menu3;
    menu1.getLanguage(language);
    //Apelarea metodei de scriere in fisier a meniurilor
    //menu1.createMenu(language);

    //Meniurile sunt calculate doar pentru actorii principali + extra
    //Calculare meniuri random:

    for(i=0; i<(actors+extras); i++)
    {
        aux = rand() % 3;

        if(aux == 0) normal = menu1.calculate();
        else if(aux == 1) vegetarian = menu2.calculate();
        else if(aux == 2) flexitarian = menu3.calculate();
    }

    cout << "Menus/Meniuri:" << endl;
    cout << "Normal : " << normal << endl;
    cout << "Vegetarian : " << vegetarian << endl;
    cout << "Flexitarian : " << flexitarian << endl;

    //Cost/zi meniuri pentru intreaga echipa(54+132 pers):

    food_cost = normal * 40 + vegetarian * 33 + flexitarian * 46;
    food_cost = food_cost / 4.62;

    if(language == "english")cout << "The food cost/ day for actors and extras : " << food_cost << endl;
    else if(language == "romana") cout << "Costul mancarii/ zi pentru actori si extra : " << food_cost << endl;

    //Cazare(toate persoanele - 735+132 ):

    int rooms_for_two, rooms_for_three,aux1,aux2, cost2, cost3;
    float staying_cost;

    Full full;
    Rest rest;
    Full1 full1;
    Rest1 rest1;

    //Calculare cazari:

    aux1=full.calculate(initial_cast);
    aux2=rest.calculate(initial_cast);
    rooms_for_two=aux1+aux2;

    aux1=full1.calculate(extras);
    aux2=rest1.calculate(extras);
    rooms_for_three=aux1+aux2;

    if(language == "english"){
        cout << "Rooms for two : " << rooms_for_two << endl;
        cout << "Rooms for three : " << rooms_for_three << endl;
    }
    else if(language == "romana"){
        cout << "Camere pentru doi : " << rooms_for_two << endl;
        cout << "Camere pentru trei : " << rooms_for_three << endl;
    }

    //Cost/noapte cazare pentru intreaga echipa:

    cost2 = rooms_for_two * 350;
    cost3 = rooms_for_three * 420;

    staying_cost = cost2 + cost3;
    staying_cost = staying_cost / 4.62;

    if(language == "english")cout << "The accomodation cost for the entire team/night : " << staying_cost << endl;
    else if(language == "romana") cout << "Costul cazarii pentru intreaga echipa/noapte : " << staying_cost << endl;

    //Drinks(toate persoanele):

    Drinks drinks;
    int everyone = initial_cast + extras;
    int water;
    float coffee, juice;

    //Se calculeaza cati litri de un anumit lichid se consuma/zi de catre intreaga echipa:

    drinks.setDrinks("water",everyone);
    water = drinks.getDrinks();
    drinks.setDrinks("coffee",everyone);
    coffee = drinks.getDrinks();
    drinks.setDrinks("juice",everyone);
    juice = drinks.getDrinks();

    float water_cost, coffee_cost, juice_cost, drinks_cost;

    //Se calculeaza costul bauturilor:

    water_cost = water * 3;
    coffee_cost = coffee * 30;
    juice_cost = juice * 4;
    drinks_cost = water_cost + coffee_cost + juice_cost;
    drinks_cost = drinks_cost / 4.62;

    //Cost/zi bauturi:

    if(language == "english")cout << "The drinks cost/ day for everyone : " << drinks_cost << endl;
    else if(language == "romana") cout << "Costul bauturii/zi pentru toata echipa: " << drinks_cost << endl;

    //Costuri finale + costuri inchiriere castel:

    vector<int> vector = {30,45,60,100};
    for(const int &i : vector)
    {
    //Se calculeaza reducerea intreaga:
    float sale = exCastle(i,10);

    //Se calculeaza pretul castelului in functie de perioada(cu tot cu reducere)
    float castle_cost = 10000 * i;
    castle_cost = castle_cost - ((sale/100) * castle_cost);
    castle_cost = castle_cost / 4.62;

    //Se afiseaza costul castelului/perioada
    if(language == "english")cout << "Castle cost for "<< i << "days : " << castle_cost << endl;
    else if(language == "romana") cout << "Costul castelului pentru " << i << " zile : " << castle_cost << endl;

    Cost2 all;
    Cost1 *all2 = &all;

    //Afisari

    all2->print(i,bus_cost,makeup_cost,food_cost,staying_cost,drinks_cost,castle_cost, language);

    long long everything = bus_cost + makeup_cost*i + food_cost*i + staying_cost*(i-1) + drinks_cost*i + castle_cost;

        std::ofstream file3;
        file3.open("all.csv", std::ios::app);

        if(file3.is_open())
        {
                //Adaugare in fisier + afisare
                // file3 << i << "," << bus_cost << "," << (unsigned long long)makeup_cost*i << "," << (unsigned long long)(food_cost*i + drinks_cost*i) << "," << (unsigned long long)staying_cost*(i-1) << "," << (unsigned long long)castle_cost << "," << (unsigned long long)everything << '\n';
                if(language == "english")cout << "Busses : " << bus_cost << "\t Makeup : " << (unsigned long long)makeup_cost*i << "\t Food & Drinks : " << (unsigned long long)(food_cost*i + drinks_cost*i) << "\t Accomodation : " << (unsigned long long)staying_cost*(i-1) << "\t Castle : " << (unsigned long long)castle_cost << "\t TOTAL : " << (unsigned long long)everything << '\n';
                else if(language == "romana")cout << "Autobuze : " << bus_cost << "\t Makeup : " << (unsigned long long)makeup_cost*i << "\t Mancare & Bauturi : " << (unsigned long long)(food_cost*i + drinks_cost*i) << "\t Cazare : " << (unsigned long long)staying_cost*(i-1) << "\t Castel : " << (unsigned long long)castle_cost << "\t TOTAL : " << (unsigned long long)everything << '\n';

            if(language == "english")cout << "The details have been added to the list.\n" << endl;
            else if(language == "romana") cout << "Detaliile au fost adaugate in lista.\n" << endl;
        }
        else
        {
            cout<<"Could not open the file/ Nu s-a putut deschide fisierul.\n";
        }
    }

    return 0;
}
