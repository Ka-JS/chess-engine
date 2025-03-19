#include "car.hh"
#include <iostream>

using namespace std;

// Default constructor.
// Sets empty strings for the string attributes,
// sets the kilometresDriven_ as 0, and makes a unique service data.
Car::Car() : brand_(""), model_(""), color_(""), registerNum_(""),
             kilometresDriven_(0), service_data_(make_unique<ServiceData>()) {}

// Constructor.
// Sets the given values for the corresponding attributes,
// sets the kilometresDriven_ as 0, and makes a unique service data.
Car::Car(const string& brand, const string& model,
         const string& color, const string& regNum)
    : brand_(brand), model_(model), color_(color), registerNum_(regNum),
      kilometresDriven_(0), service_data_(std::make_unique<ServiceData>()) {}

// Copy constructor.
// Sets the attributes as the values copied from the other car,
// but sets the register number as an empty string and the
// kilometresDriven_ as 0, and makes a unique service data.
Car::Car(const Car& other)
    : brand_(other.brand_), model_(other.model_), color_(other.color_),
      registerNum_(""), kilometresDriven_(0), service_data_(std::make_unique<ServiceData>()) {}

// Destructor
Car::~Car(){}

// Assignment operator
Car& Car::operator=(const Car& other){
    if (this != &other){
        brand_ = other.brand_;
        model_ = other.model_;
        color_ = other.color_;
        registerNum_ = other.registerNum_;
        kilometresDriven_ = other.kilometresDriven_;
        service_data_ = make_unique<ServiceData>(*other.service_data_);
    }
    return *this;
}



// Obvious setter functions
void Car::setRegisterNum(const std::string& regNum){
    registerNum_ = regNum;
}
void Car::setColor(const std::string& color){
    color_ = color;
}

// Getter functions for the attributes, return the corresponding attribute
string Car::brand() const{return brand_;}
string Car::model() const{return model_;}
string Car::color() const{return color_;}
string Car::registerNum() const{return registerNum_;}
int Car::kilometresDriven() const{return kilometresDriven_;}
const ServiceData& Car::serviceData() const{return *service_data_;}

// Drives the car, i.e. increases kilometres with the given number
void Car::drive(int kilometres){
    if (kilometres >0){
        kilometresDriven_+=kilometres;
    }
}

// Tries to insert the given service in the service data.
// Returns the result of the service data's makeService function.
bool Car::service(const Service& service){
    return service_data_->makeService(service, kilometresDriven_);
}

// Creates a service with the given data and inserts the created service
// in the service data. Returns the result of the service data's makeService function.
bool Car::service(const std::string& date, const std::vector<std::string>& operations) {
    Service new_service{date, operations};
    return service_data_->makeService(new_service, kilometresDriven_);
}

// Prints the car data in the format:
// <register number> : <brand> : <model> : <color>
// and asks the service data to print itself.
void Car::print() const {
    if (!registerNum_.empty()) { // Ensure we don't print an empty register number
        cout << registerNum_ << " : " << brand_ << " : " << model_ << " : " << color_ << endl;
    } else {
        cout << brand_ << " : " << model_ << " : " << color_ << endl;
    }
    service_data_->print();
}
