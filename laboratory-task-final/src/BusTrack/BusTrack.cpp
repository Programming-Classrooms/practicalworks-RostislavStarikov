#include "BusTrack.hpp"

/*================================================================================*/
/*================================= Конструкторы =================================*/
/*================================================================================*/

BusTrack::BusTrack() : NumberBus(1), Driver("Name"), NumberTrack(1), BrandBus("MAZ")
{}                       

BusTrack::BusTrack  (uint16_t inNumberBus, 
                    std::string& inDriver, 
                    uint16_t inNumberTrack, 
                    std::string& inBrandBus) :
    NumberBus(inNumberBus), Driver(inDriver), NumberTrack(inNumberTrack), BrandBus(inBrandBus)
{}

BusTrack::BusTrack(const BusTrack& rhs) : NumberBus(rhs.NumberBus), Driver(rhs.Driver), NumberTrack(rhs.NumberTrack), BrandBus(rhs.BrandBus)
{}


/*================================================================================*/
/*==================================== Геттеры ===================================*/
/*================================================================================*/

uint16_t BusTrack::getNumberTrack() const
{
    return NumberTrack;
}
uint16_t BusTrack::getNumberBus() const
{
    return NumberBus;
}
std::string BusTrack::getDriver() const
{
    return Driver;
}
std::string BusTrack::getBrandBus() const
{
    return BrandBus;
}

/*================================================================================*/
/*==================================== Сеттеры ===================================*/
/*================================================================================*/
void BusTrack::setNumberTrack(uint16_t _NumberTrack)
{
    NumberTrack =_NumberTrack;
}

void BusTrack::setNumberBus(uint16_t _NumberBus)
{
    NumberBus = _NumberBus;
}        
void BusTrack::setDriver(std::string& _Driver)
{
    Driver = _Driver;
}
void BusTrack::setBrandBus(std::string& _BrandBus)
{
    BrandBus = _BrandBus;
}


/*================================================================================*/
/*======================= Перегрузка оператора ввода/вывода ======================*/
/*================================================================================*/

std::ostream& operator<<(std::ostream& out, const BusTrack& obj)
{
    out << "\n===================================";
    out << "\nНомер маршрута:\t" << obj.getNumberTrack();
    out << "\nВодитель:\t" << obj.getDriver();
    out << "\nНомер автобуса:\t" << obj.getNumberBus();
    out << "\nМарка автобуса:\t" << obj.getBrandBus();
    out << "\n===================================";
    return out;
}

std::istream& operator>>(std::istream& in, BusTrack& obj)
{
    int32_t tempNumber;
    std::string tempString;

    in >> tempNumber;
    obj.setNumberTrack(checkNumber(tempNumber));

    in >> tempString;
    obj.setDriver(tempString);
    
    in >> tempNumber;
    obj.setNumberBus(checkNumber(tempNumber));

    in >> tempString;
    obj.setBrandBus(tempString);

    return in;
}


uint16_t checkNumber(int32_t check)
{
    if (!static_cast<uint16_t>(check)) throw std::invalid_argument("Error of number track/bus");

    return check;
}

/*================================================================================*/
/*=========================== Функции проверки значений ==========================*/
/*================================================================================*/

void checkFile(std::ifstream& fin)
{
    if (!fin.good())    throw std::runtime_error("Файл не найден!");
    if (!fin)           throw std::runtime_error("Ошибка открытия файла!");
}