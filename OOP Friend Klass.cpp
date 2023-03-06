#include <iostream>
#include <cmath>
#include <string>

class Device
{
    friend void write_Device(Device, std::string);
    friend class Computer;
    friend class Decorator_Device;
    friend class Decorator_Computer;
private:
    std::string serial_number  = "12345678";
    void turn_on() {
        std::cout << "Device is on";
    }
    std::string operator+ (std::string s)
    {
        std::string sum = serial_number + "."+  s;
        return (sum);
    }
};

class Computer : private Device {
    friend class Decorator_Computer;
public:
    void say_hello() {
        std::cout << std::endl << "Welcome to Windows 95!" << std::endl;
    }
};

class Decorator_Device : public Device {
protected:
    Device device_;

public:
    Decorator_Device(Device device) : device_(device) {
    }
    void turn_onn()
    {
        std::cout << '[';
        this->device_.turn_on();
        std::cout << ']';
    }
};

class Decorator_Computer : public Computer {
protected:
    Computer device_;

public:
    Decorator_Computer(Computer device) : device_(device) {
    }
    void turn_onn()
    {
        std::cout << '[';
        this->device_.turn_on();
        std::cout << ']';
    }
};

void write_Device(Device Device_instance, std::string s)
{
    Decorator_Device dec = Device(Device_instance);
    std::cout << "\t Device" << std::endl;
    std::cout << "Serial number is: " << Device_instance + s << std::endl;
    dec.turn_onn();
}

void write_Computer(Computer Device_instance)
{
    Decorator_Computer dec = Computer(Device_instance);
    std::cout << std::endl << "\t Computer" << std::endl;
    dec.turn_onn();
}

int main() 
{
    std::string s;
    std::cin >> s;
    Device Device_instance;
    Computer  Computer_instance;
    //cout << "\t Device" << endl;
    //cout << "Serial number is: " << Device_instance.serial_number+"199" << endl;
    //Device_instance.turn_on();
    write_Device(Device_instance, s);
    write_Computer(Computer_instance);
    
    Computer_instance.say_hello();
    return 0;
}