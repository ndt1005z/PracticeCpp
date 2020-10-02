#include<iostream>

using namespace std;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)
class Box
{
public:
    Box()
    {
        length = breadth = height = 0;
    }
    Box(int l, int b, int h)
    {
        this->length = l;
        this->breadth = b;
        this->height = h;
    }
    Box(Box& B)
    {
        this->length = B.length;
        this->breadth = B.breadth;
        this->height = B.height;
    }
    int getLength()
    {
        return this->length;
    }
    int getBreadth()
    {
        return this->breadth;
    }
    int getHeight()
    {
        return this->height;
    }
    long long CalculateVolume()
    {
        long long retVal;
        retVal = static_cast<long long> (length) * breadth * height;
        return retVal;
    }
    bool operator<(const Box& b);
    friend ostream& operator<<(ostream& out, const Box& B);
private:
    int length;
    int breadth;
    int height;
};

bool operator<(Box& A, Box& B)
{
    if (A.getLength() < B.getLength())
        return true;
    else if ((A.getLength() == B.getLength()) && (A.getBreadth() < B.getBreadth()))
        return true;
    else if (((A.getLength() == B.getLength()) && (A.getBreadth() == B.getBreadth())) &&
        (A.getHeight() < B.getHeight()))
        return true;
    else
        return false;
}
ostream& operator<<(ostream& out, const Box& B)
{
    out << B.length << " " << B.breadth << " " << B.height;
    return out;
}


void check2()
{
    int n;
    cin >> n;
    Box temp;
    for (int i = 0; i < n; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            cout << temp << endl;
        }
        if (type == 2)
        {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            temp = NewBox;
            cout << temp << endl;
        }
        if (type == 3)
        {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            if (NewBox < temp)
            {
                cout << "Lesser\n";
            }
            else
            {
                cout << "Greater\n";
            }
        }
        if (type == 4)
        {
            cout << temp.CalculateVolume() << endl;
        }
        if (type == 5)
        {
            Box NewBox(temp);
            cout << NewBox << endl;
        }

    }
}

int main()
{
    check2();
}