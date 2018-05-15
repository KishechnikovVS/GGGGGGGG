#include <iostream>
#include <cassert>
using namespace std;
char nibble_to_hex (uint8_t i)
{
assert(0x0 <= i && i <= 0xf);
 char digits[] = "0123456789abcdef";
 return digits[i];
}
void print_in_hex(uint8_t byte)
{
    cout <<  nibble_to_hex(byte >>4);
    cout <<  nibble_to_hex(byte & 0b00001111);
}
 const uint8_t*
 as_bytes(const void* data)
 {
     return reinterpret_cast<const uint8_t*>(data);
 }
void print_in_hex(const void*data,size_t size)
{
    const uint8_t*  bytes = as_bytes(data);
    for (size_t i = 0; i < size; i++) {
        print_in_hex(bytes[i]);
        if ((i + 1) % 16 == 0) {
            cout << '\n';
        }
        else {
            cout << ' ';
        }
    }

}
char
bit_digit(uint8_t byte, uint8_t bit) {
    if (byte & (0x1 << bit)) {
        return '1';
    }
    return '0';
}
void
print_in_binary(uint8_t byte) {
    for (uint8_t bit = 7; bit > 0; bit--) {
        cout << bit_digit(byte,bit);
    }
  cout << bit_digit(byte,0);
}
void
print_in_binary(const void* data, size_t size) {
    const uint8_t* bytes = as_bytes(data);
    for (size_t i = 0; i < size; i++) {
        print_in_binary(bytes[i]);
        if ((i + 1) % 4 == 0) {
            cout << '\n';
        }
        else {
            cout << ' ';
        }
    }
}
struct student
{
  char name [17];
    uint16_t year;
    float sred_ball;
    uint8_t sex:1;
    int classes;
    student * starosta;
};
int main()
{
    student students[3]=
    {
        {
            "Alkash",2017,4.1,0,7,
            nullptr//Starosta
        },
            {
                 "Rus",2017,5.1,0,7,&students[0]
            },
                {
                 "Skala",2017,6.1,0,7,&students[0]
                }
    };

    //assert(nibble_to_hex(0x0) == '0');
    //assert(nibble_to_hex(0x1) == '1');
    //assert(nibble_to_hex(0x2) == '2');
    //assert(nibble_to_hex(0x3) == '3');
    //assert(nibble_to_hex(0x4) == '4');
    //assert(nibble_to_hex(0x5) == '5');
    //assert(nibble_to_hex(0x6) == '6');
    //assert(nibble_to_hex(0x7) == '7');
    //assert(nibble_to_hex(0x8) == '8');
    //assert(nibble_to_hex(0xa) == 'a');
    //assert(nibble_to_hex(0xb) == 'b');
    //assert(nibble_to_hex(0xc) == 'c');
    //assert(nibble_to_hex(0xd) == 'd');
    //assert(nibble_to_hex(0xe) == 'e');
    //assert(nibble_to_hex(0xf) == 'f');
    uint8_t u8 = 3;
    cout << "u8 bytes: ";
    print_in_hex(&u8, sizeof(u8));
    cout << '\n';


    uint16_t u16 = 0x42;
    cout << "u16 bytes: ";
    print_in_hex(&u16, sizeof(u16));
    cout << '\n';
    uint32_t u32 = 0x42;
    cout << "u32 bytes: ";
    print_in_hex(&u32, sizeof(u32));
    cout << '\n';
    print_in_binary(&u8, sizeof(u8));
    char per2;
    uint16_t per1,per3,rez;
    cout << "Vvedite per1,per2,per3 \n";
    cin >> per1 >> per2 >> per3;
    cout << per1 << per2 << per3;


    switch(per2)
    {
    case '&':
         rez=per1 & per3;
        print_in_hex(&per1,sizeof(per1));
        cout<<per2<<" ";
        print_in_hex(&per3,sizeof(per3));
        cout <<" = ";
        print_in_hex(&rez,sizeof(rez));
        cout << "\n";
        print_in_binary(&per1, sizeof(per1));
        cout<<per2<<" ";
        print_in_binary(&per3, sizeof(per3));
        cout<<" = ";
        print_in_binary(&rez, sizeof(rez));
        break;

case '|':
 rez=per1 | per3;
print_in_hex(&per1,sizeof(per1));
cout<<per2<<" ";
print_in_hex(&per3,sizeof(per3));
cout <<" = ";
print_in_hex(&rez,sizeof(rez));
cout << "\n";
print_in_binary(&per1, sizeof(per1));
cout<<per2<<" ";
print_in_binary(&per3, sizeof(per3));
cout<<" = ";
print_in_binary(&rez, sizeof(rez));
break;

case '^':
rez=per1 ^ per3;
print_in_hex(&per1,sizeof(per1));
cout<<per2<<" ";
print_in_hex(&per3,sizeof(per3));
cout <<" = ";
print_in_hex(&rez,sizeof(rez));
cout << "\n";
print_in_binary(&per1, sizeof(per1));
cout<<per2<<" ";
print_in_binary(&per3, sizeof(per3));
cout<<" = ";
print_in_binary(&rez, sizeof(rez));
break;
}
    cout << "Adress of array : " << &students << "\n";
    cout << "Size of array : " << sizeof(students) << "\n";
    cout << "\t Adress of element : " <<"Size of element : \n";
    for (int i=0;i<3;i++)
    {
        cout << i << "\t" << &students[i] << "\t" << sizeof(students[i]);
        cout << "\n";
    }
    cout << "FOR FIRST elem of array : \n";
    cout << "\t Adress of field : " <<"\t Size of field : " << "\t offset :\n";
    cout << "NAME : \t" << &students[0].name;
    cout << "\t" << sizeof(students[0].name)  << "\t" << offsetof(struct student,name);
    cout << "\n";
    cout << "YEAR : \t" << &students[0].year;
    cout << "\t" << sizeof(students[0].year)  << "\t" << offsetof(struct student,year);
    cout << "\n";
    cout << "Av.point : \t" << &students[0].sred_ball;
    cout << "\t" << sizeof(students[0].sred_ball)  << "\t" << offsetof(struct student,
            sred_ball);
    cout << "\n";
    cout << "Yos : \t" << &students[0].classes;
    cout << "\t" << sizeof(students[0].classes)  << "\t" << offsetof(struct student,
            classes);
    cout << "\n";
    cout << "NAME :\n";
    cout << "Binary :\n";
    print_in_binary(&students[0].name,sizeof(students[0].name));
    cout << "\n Hex \n";
    print_in_hex(&students[0].name,sizeof(students[0].name));
    cout << "NAME :\n";
    cout << "Binary :\n";
    print_in_binary(&students[0].year,sizeof(students[0].year));
    cout << "\n Hex \n";
    print_in_hex(&students[0].year,sizeof(students[0].year));
    cout << "NAME :\n";
    cout << "Binary :\n";
    print_in_binary(&students[0].sred_ball,sizeof(students[0].sred_ball));
    cout << "\n Hex \n";
    print_in_hex(&students[0].sred_ball,sizeof(students[0].sred_ball));
    cout << "NAME :\n";
    cout << "Binary :\n";
    print_in_binary(&students[0].classes,sizeof(students[0].classes));
    cout << "\n Hex \n";
    print_in_hex(&students[0].classes,sizeof(students[0].classes));

    return(0);
}
