#include <iostream>
#include <cstring>

// class for manage the strings and the heap allocation
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

    // copy constructor
    String(const String& other)
    {
        printf("copyed \n");
        m_Size = other.m_Size;
        m_Data = new char [m_Size];
        memcpy(m_Data,other.m_Data,m_Size);
    }

    String& operator=(String&& other) noexcept 
    {
        //printf("moved using assaignment operator");

        if (this != &other)
        {
            delete[] m_Data;

            m_Size = other.m_Size;
            m_Data = other.m_Data;

            other.m_Size = 0;
            other.m_Data = nullptr;
        }

        return *this;
    }

    // move constructor
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

class Entity
{
private:
    String m_Name;
    
public:
    Entity(const String& name)
        :m_Name(name)
    {}

    // constructor for the r value refernce
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
    //Entity entity("a new allocation");
    //entity.printName();

    String string = "hellow";
    String dest = "" ;

    std::cout << "string :";
    string.Print();

    std::cout << "destinatrion :";
    dest.Print();

    printf("--------------------- \n");

    dest = std::move(string);
    std::cout << "string :";
    string.Print();

    std::cout << "destination :";
    dest.Print();

    std::cin.get();
} 