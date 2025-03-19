#include "servicedata.hh"
#include <iostream>

using namespace std;
// Constructor
ServiceData::ServiceData(){}

// Destructor
ServiceData::~ServiceData(){}

// Inserts the given data in the services_map, if the car has been driven
// after the previous service, but if a service can be found from the
// services_ map with the same kilometres, prints the error message
// "Error: already serviced with the same kilometres".
bool ServiceData::makeService(const Service& service, int kilometres){
    if (services_.count(kilometres)){
        cout<< "Error: already serviced with the same kilometres" << endl;
        return false;
    }
    services_[kilometres] = service;
    return true;
}

// Prints all services made. Each service is printed in the format:
// * Kilometres driven <kilometres> until <date>
//   --- service 1
//   --- service 2
//   --- etc.
void ServiceData::print() const {
    for (const auto& entry : services_) {
        cout << "* Kilometres driven " << entry.first << " until " << entry.second.date_ << std::endl;
        for (const auto& operation : entry.second.operations_) {
            cout << "  --- " << operation << endl;
        }

    }
    cout << endl;
}

const std::map<int, Service>& ServiceData::getServices() const {
    return services_;
}

