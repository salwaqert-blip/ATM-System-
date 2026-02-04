#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <istream>
#include <limits>
#include <windows.h>

using namespace std;

// to change the color of consle
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

//class is private for the information of user
class User{
   private:
       double balance ;
       string name , phoneNumber , address;

    public:
       User(string name  , string address , string phoneNumber , double balance ): name(name) , balance(balance) , address(address),  phoneNumber( phoneNumber){}

        User(): name(" ")  , address(" ") , phoneNumber(" ") , balance(0.0){}

     virtual void displayPersonalinfo() = 0 ;
     virtual ~User(){
     cout<<"User object destroyed"<<endl;
     }
        // to return the name
    string getName(){
       return name;
     }

   // to return the address
    string getAddress(){
     return address;
    }

  // to return the phone
  string getPhoneNumber(){
    return phoneNumber;
  }

  // to return the balance
  double getBalance(){
    return balance;
  }

  void Enter_name(){
    do{
        cout<<"Enter your name!"<<endl;
         getline(cin,name);}
         while(name.empty());
  }

   void  Enter_address(){
    do{
       cout<<"Enter your address!"<<endl;
        getline(cin,address);}
  while(address.empty());
  }

    void  Enter_phoneNumber(){
        do{
       cout<<"Enter your phone Number!"<<endl;
        cin>>phoneNumber;}
        while(phoneNumber.empty());
        }

    void  Enter_Balance(){
        do{
        cout<<"Enter your balance!"<<endl;
        cin>>balance;
          } while(balance==0.0);
    }

 };

//class is private for PIN
  class SecurityPin{
        protected :
         string pin ;
        public:
         SecurityPin():pin(" "){}
         SecurityPin(string pin):pin(pin){}

        void  Enter_Pin(string filename){
        do{
        cout<<"Enter your pin number!"<<endl;
         cin>>pin;}
         while(!(ispinstrong (pin)&&!checkpin(pin,filename)));
        }

 //to return the PIN
    string getPin(){
        return pin;
  }

    // unique pin
  bool checkpin(string pin_to_search ,  string filename){
    ifstream infile(filename);
    if(!infile.is_open()){
         return false ;
       }
    else{
   string line ;
   bool pinfound = false;
   while(getline(infile,line)){
    if(line.find(pin_to_search) != -1){
        pinfound = true;
   }}
   infile.close();
    if(pinfound){
        cout<<"the pin is found please enter unique pin!\n";
        return true ;}
      else{
            return false;
    cout<<"the pin is not find\n";

      }
     }
  }

  //The length of password and it form
   bool ispinstrong (string Pin ){
        int minlength = 4 ;

        if(Pin.length()< minlength  ){
            cout<<"password must be with number do not few about the : "<<minlength<<endl;
            return false ;
        }
        bool hasupper = false ,  haslower = false ,  hasdigit = false ,  hasspecial = false ;
        for(int i = 0 ; i < Pin.length() ; i++ ){
            char ch = Pin[i];
            if(isupper(ch)){
                hasupper = true ;
            }
             if(islower(ch)){
                haslower = true ;
            }
             if(isdigit(ch)){
                hasdigit = true ;
            }
             if(ispunct(ch)){
                hasspecial = true ;
            }
        }
        if( hasspecial && hasdigit && haslower && hasupper ){
            return true ;
        }
        else {
            if(!hasspecial){
                cout<<"password must contain at least one special character"<<endl;
            }
             if(!haslower){
                cout<<"password must contain at least one lower character"<<endl;
            }
              if(!hasupper){
                cout<<"password must contain at least one upper character"<<endl;
            }
              if(!hasdigit){
                cout<<"password must contain numbers "<<endl;
            }

            return false ;
        }
      }
      virtual ~SecurityPin()= default ;


  };

//class is private for account number
class SecurityAccount {
     protected :
        string accountNumber ;
     public :
        SecurityAccount(): accountNumber("  "){}
        SecurityAccount(string accountNumber){
                this->accountNumber = accountNumber ;
        }

 // unique account number
   bool account_unique(string account_to_search ,  string filename){
    ifstream infile(filename);
      if(!infile.is_open()){
        return false ;
        }
  else{
   string line ;
   bool accNumfound = false;
   while(getline(infile,line)){
    if(line.find(account_to_search) != -1){
     accNumfound = true;
   }}
   infile.close();
    if(accNumfound){
        cout<<"the account number is found please enter unique account number!\n";
        return true ;}
      else{
            return false;
    cout<<"the account number is not find\n";
       }
     }
 }

     //The length of account number
  bool ischeck_account_number (string accNum ){
        int minlength = 7 ;
        int maxlength = 9 ;
        bool alldigit;
        if(accNum.length()< minlength  ){
            cout<<"account number must be contained at least 7 numbers! "<<endl;
            return false ;
        }
        if(accNum.length()> maxlength  ){
            cout<<"The length of account number must not be  more than 9 numbers! "<<endl;
            return false ;
        }
         for(int i = 0 ; i < accNum.length() ; i++ ){
            char ch = accNum[i];
           if(isdigit(ch)){
                alldigit = true ;
            }}
            if(alldigit){
                return true;
            }
            else {
                return false;}
  }

   string getAccountNumber(){
    return accountNumber;
  }

   void  Enter_accountNumber(string filename){
       do{
        cout<<"Enter your account Number!"<<endl;
        cin>>accountNumber;}
        while(!(ischeck_account_number (accountNumber)&&!account_unique(accountNumber,filename)));

        }
    //destructor
    virtual ~SecurityAccount()= default ;


};

//class is private for email and form it
class SecurityEmail{
   protected :
       string email;
   public :
     SecurityEmail(string email): email(email){}
     SecurityEmail(): email("  "){}

     //to check coordinates email
      bool isvalidemail(string Email){
         size_t pos_add = Email.find("@");
           size_t dotpos = Email.find("." ,pos_add );
       if(pos_add == -1 ||pos_add == 0 || dotpos == -1 ||
           dotpos ==  pos_add+1 ||  dotpos == Email.length()-1 ){
                   return false ;
       }
       return true ;
    }

   //to form the email
      bool has_domain(string Email){

       string domain = "@gmail.com";
         if( email.find(domain)!= string::npos ){
            return true ;
         }
         return false ;
       }

  //to input email from user
        void  Enter_Email(){
        do{
         cout<<"Enter your email!"<<endl;
        cin>>email;}
        while(!(isvalidemail(email) && has_domain(email)));
        }
        string getEmail(){
        return email ;
        }

    virtual ~SecurityEmail()= default ;

};

//class is private for the linked list
class Node : public User , public SecurityAccount ,  public SecurityPin  , public SecurityEmail{
   public :
       Node* next ;

       //parameterized constructor
       Node(string username , string phone   , string account , string email , string address , string pin , double balance){
         name = username ;
         phoneNumber = phone ;
         next = nullptr ;
         accountNumber = account ;
         this->address = address;
         this->email = email;
         this->pin = pin;
         this->balance = balance ;

       }
      void displayPersonalinfo()override{
        cout<<"This class is private only for any thing about the linked list and the information of the user is exist in the Registration class"<<endl;
       }

             virtual ~Node()= default ;

};

//class is private for login and delete account
class Registeration : public User  ,  public SecurityPin , public SecurityAccount , public SecurityEmail{
    protected :
      static  Node*head;
    public :
        Registeration():  SecurityPin() , User() , SecurityAccount() , SecurityEmail() {}
        Registeration(string accountNumber , string pin , string name , string email , string address , string phoneNumber , double balance):
            User(name  , address , phoneNumber , balance),SecurityPin(pin) , SecurityAccount(accountNumber), SecurityEmail(email) {}

        //to save the data into the file
    void savedToFile(string filename){
       ofstream outfile(filename, ios::app);
       if(outfile.is_open()){
        outfile<<"Name: "<<name<<"   "<<"AccountNumber: "<<accountNumber<<"   "<<"Pin: "<<pin<<"   "<<"Address: "<<address<<"   "<<"Email: "<<email<<"   "
         <<"PhoneNumber: "<<phoneNumber<<"    "<<"Balance: "<<balance<<"   "<<endl;
         outfile.close();
         cout<<"Account saved to file "<<filename<<endl;
       }
       else{
        cout<<"Failed to open file for writing."<<endl;
       }
   }

   //to create new account with the linked list
    void createAccount(){
        cin.ignore();
         Enter_name();
         Enter_address();
         Enter_phoneNumber();
         Enter_accountNumber("salwa.txt");
         Enter_Email();
         Enter_Balance();
         Enter_Pin("salwa.txt");
         Node* newUser = new Node( name , phoneNumber , accountNumber , email , address   , pin, balance );
        if(head == nullptr){
            head = newUser;
            }
        else {
            Node* temp = head;
            while(temp->next != nullptr){
                temp = temp->next ;
            }
            temp->next = newUser ;
        }
        savedToFile("salwa.txt");
    }


    //load the date from file to the linked list
   static  void loadFromFile(string filename){
    ifstream infile(filename);
    if(!infile.is_open()){
     cout<<"Error opening file"<<endl;
    return;}
    string line , field ;
   while(getline(infile,line)){
    if(line.empty())
     continue ;
     istringstream iss (line); // to divide the line
     string name , phone , accNum , email , pin , address ;
       double balance = 0.0 ;
   if(getline(iss , field , ':')){
     getline(iss,name,'\t');
   }
   if(getline(iss , field , ':')){
     getline(iss,accNum,'\t');
   }
   if(getline(iss , field , ':')){
     getline(iss,pin,'\t');
   }
    if(getline(iss , field , ':')){
     getline(iss,address,'\t');
   }
   if(getline(iss , field , ':')){
     getline(iss,email,'\t');
   }
   if(getline(iss , field , ':')){
     getline(iss,phone,'\t');
   }
   if(getline(iss , field , ':')){
     iss>>balance ;
   }
   Node*newUser = new Node(name , phone ,  accNum , email , address  , pin , balance );
           newUser->next = head ;
            head = newUser;
        }
           infile.close();
    }

    //to clear the linked list
    static void clearLinkedList(){
        Node* current = head ;
        while(current!=nullptr){
            Node* nextNode = current->next ;
            delete current ;
            current = nextNode ;
        }
        head = nullptr ;

    }

     //to delete an exist account
  static void deleteAccount(string accountTosearch , string filename){
    ofstream ofs("temp.txt");
    ifstream infile(filename);
       if(!ofs.is_open()|| !infile.is_open()){
         cout<<"Error opening file\n";
         return;}
     string line ;
     bool accountfound = false;
     while(getline(infile,line)){
       if(line.find(accountTosearch) != string::npos){
         accountfound = true;
          continue;
     }
    ofs<<line<<endl;}
     ofs.close();
     infile.close();

    if(accountfound){
            remove(filename.c_str());
        rename("temp.txt" , filename.c_str());
        cout<<"the user delete is accomplished\n";
       Registeration::clearLinkedList();
       Registeration::loadFromFile("salwa.txt");
            }
      else{
          remove("temp.txt" );
          cout<<"the account is not find\n";
      }
    }



   //display specific user depending on the account number
    void displayPersonalinfo()override {
       string accNum ;
          cout<<"Please Enter your account number to show your information "<<endl;
         cin>>accNum;
       ifstream infile("salwa.txt");
       if(!infile.is_open()){
          cout<<"Error opening file\n";
          return ; }
        string line ;
        bool userfound = false ;
        while(getline(infile , line )){
            if(line.find(accNum) != string::npos){
              userfound = true ;
              cout<<"Account Info:  "<<line<<endl;
            }
        }
        infile.close();
        if(userfound){
        cout<<"Your information is displayed "<<endl;
   }
     else {
        cout<<"Your account is not find "<<endl;
     }
   }

    virtual ~Registeration()= default ;


};
//the head is static member of class Registration
Node* Registeration::head = nullptr;

//class is private for the processes of the ATM
class Account : public Registeration {
    public :
        Account(string accountNumber , string pin , string name , string email , string address , string phoneNumber , double balance):
            Registeration(accountNumber , pin , name , email , address , phoneNumber , balance){}
        Account():  Registeration(){}

    virtual ~Account(){
       cout<<"Account object destroyed"<<endl;
     }

 //return the balance that is stored into the file
     double Return_balance(string accNum ){
       ifstream infile("salwa.txt");
       if(!infile.is_open()){
          cout<<"Error opening file\n";
          return -1 ;
          }
        string line ;
        while(getline(infile,line)){
                size_t accpos = line.find("AccountNumber: "+accNum);
                if(accpos!= string::npos ){
                        size_t balpos = line.find("Balance: ");
                if(balpos != string::npos){
                    string balancestr = line.substr(balpos+9);
                    infile.close();
                   return stod(balancestr);}}

                   }

                    infile.close();
                    return -1 ;
                     }
//update the balance after any process
    void update_balance(double new_balance ,  string accNum){
        ofstream outfile("temp.txt");
       ifstream infile("salwa.txt");
       if(!infile.is_open()|| !outfile.is_open()){
          cout<<"Error opening file\n";
          return ;}
          bool accountfound = false ;
        string line ;
        while(getline(infile,line)){
                size_t accpos = line.find("AccountNumber: "+accNum);
                if(accpos!= string::npos ){
                    accountfound = true ;
                    size_t balpos = line.find("Balance: ");
                    if(balpos!= string::npos ){
                        string updateline = line.substr(0,balpos+9)+to_string(new_balance);
                        outfile<<updateline<<endl;
                        }
                          else{ outfile<<line<<endl;}}
                        else{ outfile<<line<<endl;}}
                        infile.close();
                        outfile.close();
            if(!accountfound){
                cout<<"Account not found "<<endl;
            }
            else{
                remove("salwa.txt");
                rename("temp.txt" ,"salwa.txt" );
            }
    }

//withdraw the money from the balance
       void Withdraw(){
           string accNum;
           do{
           cout<<"Enter your account: "<<endl;
          cin>>accNum;}
          while(!(ischeck_account_number (accNum)));
        double balance =  Return_balance(accNum);
        if(balance == -1){
            cout<<"The account is not find"<<endl;
            return;
        }
        double amount ;
        cout<<"Enter your amount that you want withdraw it "<<endl;
        cin>>amount ;
        cout<<"the old balance: "<< balance<<endl;
       if( balance >= amount ){
       balance -= amount;
        cout<<"The amount  " <<amount<<"  is Withdrawed successfully!"<<endl;
        cout<<"the new balance: "<<balance<<endl;
        update_balance(balance , accNum);
        Registeration::clearLinkedList();
       Registeration::loadFromFile("salwa.txt");
       }
       else {cout<<"Sorry! your balance is less than the amount that you wanted withdraw."<<endl;
             cout<<"Your current balance is:  "<<balance<<endl;
             }
    }
//add the money for the balance
    void Deposit(){
        string accNum ;
         do{
           cout<<"Enter your account: "<<endl;
          cin>>accNum;}
          while(!(ischeck_account_number (accNum)));
         double balance = Return_balance(accNum);
         double amount ;
        if(balance == -1){
            cout<<"The account is not found "<<endl;
            return;
        }
        cout<<"Enter your amount that you added for your balance: "<<endl;
        cin>>amount ;
        balance += amount;
        cout<<"The amount  " <<amount<<"  is added for balance successfully!"<<endl;
        cout<<"Your current balance is :  "<<balance<<endl;
        update_balance(balance, accNum);
       Registeration::clearLinkedList();
       Registeration::loadFromFile("salwa.txt");
    }

 //display the balance that is exist into the file
    void displayBalance(){
         string accNum ;
        cout<<"Enter your account: "<<endl;
          cin>>accNum;
        double balance = Return_balance(accNum);
        cout<<"The current balance is :  "<<balance<<endl;
    }

    //transfer function using template
    template<typename T ,typename St >
   void Transfer(T amount , St SenderAccNum , St ReceiverAccNum){
      double ReceiverBalance = Return_balance(ReceiverAccNum);
      double SenderBalance = Return_balance(SenderAccNum);
      if(SenderBalance >= amount){
        SenderBalance -= amount;
        ReceiverBalance += amount;
         cout<<"Transferred:  "<<amount<<"  "<<"to account:  "<<ReceiverAccNum<<endl;
          update_balance(SenderBalance, SenderAccNum);
          update_balance(ReceiverBalance, ReceiverAccNum);
          Registeration::clearLinkedList();
          Registeration::loadFromFile("salwa.txt");
      }
      else{
       cout<<"Insufficient funds for transfer."<<endl;
      }

    }

   //update the information of the user
  string UpdatePersonalInfo(){
     string new_name , new_address , new_phone , new_pin  , new_accountNumber;
     double new_balance = getBalance();
         Enter_phoneNumber();
          do{
        cout<<"Enter the new account number!"<<endl;
         cin>>new_accountNumber;}
        while(!(ischeck_account_number (new_accountNumber)&&!new_accountNumber.empty()));
         Enter_Email();
         cin.ignore();
          Enter_name();
         Enter_Balance();
         Enter_address();
         Enter_Pin("salwa.txt");

  return "Name: "+getName()+"  "+"AccountNumber: "+ new_accountNumber+"  "+"Pin: "+getPin()+"  "+"Address: "+getAddress()+"  "+"Email: "+getEmail()+"  "+"PhoneNumber: "+new_phone+"   "+"Balance: "+to_string(balance)+"\n" ;

   }

      //update the information of the user depending on the account number
     void editAccount(string accNum , string filename){
         ofstream ofs("temp.txt");
         ifstream infile(filename);
         if(!ofs.is_open()|| !infile.is_open()){
            cout<<"Error opening file\n";
            return;}
               string line    ;
   bool accountfound = false;
   while(getline(infile,line)){
    if(line.find(accNum) !=  string::npos){
        accountfound = true;
        cout<<"Current data: "<<line<<endl;
      string newData = UpdatePersonalInfo()  ;
   ofs<<newData<<endl;
    }
        else{
            ofs<<line<<endl;
        }}
     ofs.close();
     infile.close();
    if(accountfound){
        remove(filename.c_str());
        rename("temp.txt" , filename.c_str());
        cout<<"Account updated successfully!\n";}
      else{
          remove("temp.txt" );
          cout<<"the account is not find\n";
    }}

    //paying the bill with operator overloading
  void operator()( double billAmount){
       string accNum ;
           cout<<"Enter your account: "<<endl;
           cin>>accNum;
           double balance = Return_balance(accNum);
           if(balance < billAmount){
            cout<<"Your balance is not enough for paying the bill"<<endl;
            return ;
           }
         balance -= billAmount ;
         update_balance(balance, accNum);
         Registeration::clearLinkedList();
         Registeration::loadFromFile("salwa.txt");
         cout<<"The Bill is payed successfully!"<<endl;
         cout<<"Your balance is becoming : "<<balance<<endl;
         return ; }


};

//class is private for the front-end Bank Management system
class BankSystem{
public:
    // دالة لعرض القائمة للمستخدم
   static void displayMenu() {
        cout << "\n------------------ ATM System ------------------\n";
        cout << "1. Display Account Information\n";
        cout << "2. Withdraw\n";
        cout << "3. Deposit\n";
        cout << "4. Transfer\n";
        cout << "5. Display Specific Balance\n";
        cout << "6. Update Personal Information\n";
        cout << "7. Pay Bill\n";
        cout << "8. Create New Account\n";
        cout << "9. Delete Account\n";
        cout << "10. Exit\n";
        cout << "-------------------------------------------------\n";
        cout << "Enter your choice: ";
    }

   static void start() {
        int choice;
        Account account;
        User *U;
        //Registeration R ; // يجب أن تكون قد أنشأت كائنات من كلاس Account
        U = & account;
        while (true) {
           BankSystem::displayMenu();
            cin >> choice;

            // تحقق من الإدخال إذا كان غير صحيح
            if (cin.fail()) {
                cin.clear();  // مسح خطأ الإدخال
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // تجاهل باقي السطر
                cout << "Invalid input. Please try again." << endl;
                continue;
            }

            switch (choice) {
                case 1:
                    U->displayPersonalinfo();  // عرض معلومات الحساب
                    break;

                case 2:
                    account.Withdraw();  // سحب المال
                    break;

                case 3:
                    account.Deposit();  // إيداع المال
                    break;

                case 4:{
                    double amount ;
                    string SenderAccount , ReceiverAccount ;
                    cout<<"Please Enter your account to check it if you already have account: "<<endl;
                    cin>>SenderAccount;
                    cout<<"Please Enter the account that you transfer it the Amount : "<<endl;
                    cin>>ReceiverAccount;
                    cout<<"Please Enter the amount that you added it to the Receiver account: "<<endl;
                    cin>>amount;
                   account.Transfer(amount , SenderAccount , ReceiverAccount );
                   break;}

                case 5:
                    account.displayBalance();  // تنفيذ عملية تحويل
                    break;

                case 6:{
                    string accNum , filename = "salwa.txt" ;
                    cout<<"Enter your Account: "<<endl;
                    cin>>accNum;
                    account.editAccount(accNum,filename);  // تحديث معلومات الحساب
                    break;}

                case 7:{
                    double billAmount;
                    cout << "Enter the bill amount: ";
                    cin >> billAmount;
                    int option ;
                    cout<<"---------------BILL TYPE--------------"<<endl;
                    cout<<"  1. The Water Bill."<<endl;
                    cout<<"  2. The Electricity Bill."<<endl;
                    cout<<"  3. The Gas Bill."<<endl;
                    cout<<"---------------GOOD-------------------"<<endl;
                    cout<<"Enter the type of Bill: "<<endl;
                    cin >> option;
                      switch(option){
                        case 1:
                        case 2:
                        case 3:
                            account.operator()(billAmount);// دفع الفاتورة باستخدام الـ operator()
                            break;
                            default:cout << "Invalid Option. Please select a valid option." << endl;
                            }
                    break;}

                case 8:
                    account.createAccount();  // إنشاء حساب جديد
                    break;

                case 9:{
                    string accNum , filename = "salwa.txt" ;
                    cout<<"Enter The Account that you want to delete it: "<<endl;
                    cin>>accNum;
                    Registeration::deleteAccount(accNum , filename );  // حذف حساب
                    break;}

                case 10:
                    cout << "Exiting ATM System. Thank you!" << endl;
                    return;  // إنهاء البرنامج

                default:
                    cout << "Invalid choice. Please select a valid option." << endl;
         }   }
    }
};

int main()
{

    setColor(14);
   BankSystem::start();
    return 0;
}

