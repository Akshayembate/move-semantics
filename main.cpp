#include <iostream>
#include <cstring>

class String
{
public:
    // deleting the default constructor
    String() = delete;

    String(const char* string)
    {
        printf("created \n");
        m_Size = strlen(string);
        m_Data = new char[m_Size + 1]; // allocating the memory in the heap for the string 
        memcpy(m_Data, string, m_Size + 1); // copy the string data 
    }

    // copy constructor takes the valriable other as string and then prontong the necessory info 
    // m_size is a variable for the size of the charector in the charector array
    // m_data is the variable for the char string array for allocating  
    // cpoying the string to the new string using the memcpy
    String(const String& other)
    {
        printf("copyed \n");
        m_Size = other.m_Size;
        m_Data = new char [m_Size];
        memcpy(m_Data,other.m_Data,m_Size);
    }

    // making an move constructor for instead of copying the data to strings q
    // we can move for the same string because copying takes a heap memory allocation
    // for moving the data we need a r value reference function
    // the data which is passing to the move constructor should be a temperary
    String(String&& other) noexcept
    {
        printf("moved \n");
        m_Size = other.m_Size;
        m_Data = other.m_Data;

        other.m_Data = nullptr;
        other.m_Size = 0;        
    }

    // distructor 
    ~String()
    {
        printf("destroyed \n");
        delete[] m_Data; // freeing the memory which is allocated
    }
    // funtion for iterating to the string and ma
    void Print()
    {
        for (uint32_t i = 0; i < m_Size ; i++)
        {
            printf("%c", m_Data[i]);
        }
        printf("\n"); 
    }

private:
    char* m_Data;
    uint32_t m_Size;
};

// a new class for calling the string 
// making the class type for allocating the string 
// the constructor of the class is taiklimg the string 
// and storing the data toi its private variables 
class Entity
{
private:
    String m_Name;
    
public:
    Entity(const String& name)
        :m_Name(name)
    {}

    // same copy contructor needs to add here 
    Entity(String&& name)
        :m_Name(std::move(name))
    {}

    void printName()
    {
        m_Name.Print();
    }
};

int main()
{
    //std::cout << "hello world \n";
    Entity entity("a new allocation");
    entity.printName();
    std::cin.get();
}